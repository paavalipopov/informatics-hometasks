#ifndef MAX_FACTORIAL_FOR_TYPE_H
#define MAX_FACTORIAL_FOR_TYPE_H

/*
* This shift is for calculating max value for integer types
*	So everywhere in code below SHIFT will be replaced with 2
*	For example, int a = SHIFT; would be int a = 2;
*	For example, SHIFT a = SHIFT; would be 2 a = 2; This piece of code doesn't compile,
*	but macro expansion will be done earlier.
*/
#define SHIFT 2

/*
* This macros accepts format of type to print and type to generate
* So all such things like CHECK_INT_TYPE("%lld", long long)
* would be replaced with
* CHECK_FLT_TYPE("%lld", long long, (counter << (sizeof(long long)*8 - 2)) - 1 + (counter << (sizeof(long long)*8 - 2)))
* counter is undefined in this context, but it will be define later in CHECK_FLT_TYPE macros:
* verified_type counter = 1; will be long long counter = 1; This is a simple counter for chosen type.
*
* Calculating of size:
* counter equals to 1, size of long long is for example 8 bytes = 64 bits, max value will be 2^63 - 1(one bit for sign)
* For example, unsigned long long max value will be 2^64 - 1
* We can't directly calculate 2^64 or 2^63 and simply subtract 1,
* because it will cause overflow so we calc it as 2^n - 1 = 2^(n-1) - 1 + 2^(n-1). This won't cause overflow of type
* for signed long long type it will be 2^63 - 1 = 2^(63-1) - 1 + 2^(63-1)
* That is, (counter << (sizeof(verified_type)*8 - SHIFT)) - 1 + (counter << (sizeof(verified_type)*8 - SHIFT)) would be
* (1 << (sizeof(long long)*8 - 2)) - 1 + (1 << (sizeof(long long)*8 - 2))
* for calculating power of 2, we use left shift operator <<. 2^63 = 1 << 63
*
* Here is the meaning of SHIFT declaration : for unsigned types SHIFT will be 1, for signed - 2,
* because of sign bit.
*
*/
#define CHECK_INT_TYPE(format, verified_type) \
		CHECK_FLT_TYPE(format, verified_type, (counter << (sizeof(verified_type)*8 - SHIFT)) - 1 + (counter << (sizeof(verified_type)*8 - SHIFT)))
/*
* #verified_type will be replaced not with signed char, but with string constant "signed char"
* # stringifies macros argument, adds quotes before and after argument
* So, all occurences of macros CHECK_FLT_TYPE("%f", float, FLT_MAX) will be replaced:
* 	if(!strcmp(type, "float")) { \
*		float counter = 1; \
*		float max_value = FLT_MAX; \
*		printf("Maximum value for type %s is ""%f""\n", "float", max_value); \
*		for(; max_value > 1; counter++, max_value = max_value/counter); \
*		printf("Max value for factorial calc for type %s is ""%f""\n", "float", counter - 1); \
*		return 0; \
*	}
*
* When I call CHECK_INT_TYPE("%hhd", signed char), it will be replaced as above, but with another MAX_VALUE:
* (counter << (sizeof(verified_type)*8 - SHIFT)) - 1 + (counter << (sizeof(verified_type)*8 - SHIFT))
*
* 	if(!strcmp(type, "int")) { \
*		int counter = 1; \
*		int max_value = (counter << (sizeof(int)*8 - 2)) - 1 + (counter << (sizeof(int)*8 - 2)); \
*		printf("Maximum value for type %s is ""%d""\n", "int", max_value); \
*		for(; max_value > 1; counter++, max_value = max_value/counter); \
*		printf("Max value for factorial calc for type %s is ""%d""\n", "int", counter - 1); \
*		return 0; \
*	}
*
* This trick is only because bit shift operator << is only defined for integer types, not float.
* So, for float types we should use constants from float.h directly like FLT_MAX or LDBL_MAX.
*/

#define CHECK_FLT_TYPE(format, verified_type, MAX_VALUE) \
	if(!strcmp(type, #verified_type)) { \
		verified_type counter = 1; \
		verified_type max_value = MAX_VALUE; \
		printf("Maximum value for type %s is "format"\n", #verified_type, max_value); \
		for(; max_value > 1; counter++, max_value = max_value/counter); \
		printf("Max value for factorial calc for type %s is "format"\n", #verified_type, counter - 1); \
		return 0; \
		}

//This function reads any size input string reallocating memory by chunks(for example, 5 characters here)
//Its logic is simple, there is no macroses, so you should explain me it
int read_string(char** result);
int process_type(char* type);
void test_max_factorial_type();

#endif
