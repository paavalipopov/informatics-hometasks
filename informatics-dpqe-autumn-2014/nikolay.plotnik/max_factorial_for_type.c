#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "max_factorial_for_type.h"

/*
 * This code expands in enormous amount of if statements for each type checking
 *
 */
int process_type(char* type) {
	CHECK_INT_TYPE("%hhd", signed char)
	CHECK_INT_TYPE("%hd", short)
	CHECK_INT_TYPE("%d", int)
	CHECK_INT_TYPE("%ld", long)
	CHECK_INT_TYPE("%lld", long long)
#undef SHIFT
//for unsigned types
#define SHIFT 1
	CHECK_INT_TYPE("%hhu", unsigned char)
	CHECK_INT_TYPE("%hu", unsigned short)
	CHECK_INT_TYPE("%u", unsigned int)
	CHECK_INT_TYPE("%lu", unsigned long)
	CHECK_INT_TYPE("%llu", unsigned long long)
#undef SHIFT
	CHECK_FLT_TYPE("%f", float, FLT_MAX)
	CHECK_FLT_TYPE("%f", double, DBL_MAX)
	CHECK_FLT_TYPE("%Lf", long double, LDBL_MAX)

	printf("Unsupported type: %s\n", type);
	return -1;
}

/* Read sizeless string
 * Function has only one argument - double pointer to char.
 * The main idea is: When we want modify data in function we pass pointer to this data, here we should modify pointer value, 
 * because we allocate memory in function and assign returned pointer to the argument
 * So we should pass pointer to pointer or double pointer to function.
 * If we pass only pointer to char, its value will be copied on called function(read_input) stack, modified and leave modified on called function stack,
 * BUT leave unmodified for calling function(main, for example)
 */
int read_string(char** result) {
	//Chunk size - after how many character we should reallocate we memory for the next input characters
	static char chunk_size = 5;
	//Result size - how much memory it occupies
	size_t result_size = chunk_size;
	//Result length - real amount of characters in the string(String can occupy memory for 40 characters, but only 36 may be filled)
	size_t result_length = 0;
	//In this variable we read input character
	char character;

	//Initial memory allocation for input buffer, we store value, returned from calloc, in *result - this is the value of pointer which pointed to our string
	//For example, 0x12345(pointer to pointer to char array - string)	---->>>>(points to)		0x54321(pointer to char array)	---->>>>	"abcdef"(our string)
	//This line modifies value of pointer to char array - 0x54321, for example, it becomes 0x98765
	//But this value 0x98765 is stored on read_string function stack and to visible to main function(or any other calling function), HOW CALLING FUNCTION CAN ACCESS IT?
	//It has pointer(0x12345) to this pointer(old value - 0X54321, new value - 0x98765) to char array("abcdef"), which leaves unmodified and visible to calling(main) and called(read_string) function
	//So in main function we can apply * to pointer and get the allocated memory - *(0x12345)==0x98765
	//+1 is for last '\0' character for validity of C-string
	*result = (char*)calloc(result_size + 1, sizeof(char));

	//Read one character with getchar function in 'character' variable until it is not End Of File(EOF) or new line(\n)
	while((character = getchar()) != EOF && character != '\n') {
		//Increase string length by 1 symbol
		result_length++;

		//If current size(for example, 5) is not enough for new length(for example now we read sixth character) we should reallocate memory
		if(result_length > result_size) {
			//Print message about reallocating memory
			printf("Maximum size of %d characters reached, reallocating memory. Current result: %s\n", result_size, *result);
			//Calculate new string size - add chunk size
			result_size += chunk_size;
			//Reallocating memory, don't forget about +1 for reserved end character - '\0', realloc copy old content if successed and not deallocated old memory if fails
			if((*result = (char*)realloc((void*)(*result), result_size + 1)) == NULL) {
				printf("Unable to allocate memory for input\n");
				return -1;
			}
			//Setting new added chunk with '\0' characters.
			//For example, string before allocation - "abcde\0", after reallocation - "abcde\0*****", where ***** is garbage, noone knows which characters were in this memory before
			//We should normalize it to "abcde\0\0\0\0\0\0", because after next iteration first \0 will removed and we have not valid C-string with \0 in the end.
			//memset sets memory pointed to by pointer with specified character for specified length(it has three arguments - pointer, character, length)
			memset(*result + strlen(*result), '\0', chunk_size + 1);
		}

		//Finally we assign input character to result string
		(*result)[result_length - 1] = character;
	}

	//Check for string empty, return fail code -1 if string is empty(user enters nothing), print proper message
	if(strlen(*result) == 0) {
		printf("Input string is empty\n");
		return -1;
	}

	//Finally memory reallocation - for example we have string with 40-character size but only 37 occupied, we want to try to decrease allocated memory to exactly 37 characters + end character \0
	if(result_size > result_length) {
		printf("Final reallocation memory for precise string length.\nBefore reallocation - %d\n", result_size);
		if((*result = (char*)realloc((void*)(*result), result_length + 1)) == NULL) {
			printf("Unable to allocate memory for input\n");
			return -1;
		}
		(*result)[result_length] = '\0';
		//%zu - is format specifier for size_t, this type is returned by strlen, it is like %d for int, this valid only for gcc compiler
		//Microsoft compilers(like in Visual Studio) doesn't support it, for them it should be %Iu
		//http://msdn.microsoft.com/en-us/library/tcxf1dw6.aspx - read here about MS type size
		//This is the case of not-related to C standard implementation, it depends on compiler, C standard says nothing about handling and printing such types like size_t or ssize_t
		printf("After reallocation - %Iu\n", strlen(*result));
	}

	return 0;
}

void test_max_factorial_type() {
	char* type = NULL;
	int quit = 0;

	while (!quit) {
		printf("Enter type or quit for exiting:\n");
		if (read_string(&type) < 0) {
			printf("Invalid input from stdin\n");
			continue;
		}
		if (!strcmp(type, "quit")) {
			quit = 1;
			break;
		}
		if (process_type(type) < 0) {
			printf("Can't process type.\n");
		}
	}

	free(type);
}
