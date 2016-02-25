#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define double_list_Empty 1
#define double_list_End 3
#define double_list_Begin 4

// ERROR - The const value returned if result is incorrect
// OK    - The const value returned if result is correct and procedure is done
#define ERROR -1
#define OK     1

#define type_t char*



struct node_t                               //nodes of list
{
    struct node_t *next;
    struct node_t *prev;
    type_t data;
};


struct list_t                               //header struct.
{
    struct node_t *first;
    struct node_t *last;
    int size;
};



struct list_t* LIST_constructer ()              //construct header
{
    struct list_t* LIST = ( struct list_t* ) malloc ( sizeof ( struct list_t ) );
    LIST -> first = NULL;
    LIST -> last  = NULL;
    LIST -> size = 0;
    return LIST;
}



int LIST_destructer ( struct list_t* LIST )    //destruct header
{
    if ( LIST -> size != 0 )
        return ERROR;
    LIST -> first = NULL;
    LIST -> last = NULL;
    LIST -> size = 0;
    free ( LIST );
    return OK;
}



void LIST_addBegin ( struct list_t* LIST, type_t element )
{
    struct node_t *NODE = ( struct node_t* ) malloc ( sizeof ( struct node_t ) );

    if( LIST -> size == 0 )
    {
        LIST -> last = NODE;
        LIST -> first = NODE;
        NODE -> next = NULL;
        NODE -> prev = NULL;
    }
    else
    {
        NODE -> next = LIST -> first;
        ( LIST -> first ) -> prev = NODE;
        LIST -> first = NODE;
        NODE -> prev = NULL;
    }
    //initialize memory for data and taking string there
    NODE -> data = ( char* ) calloc ( ( strlen ( element ) + 1 ), sizeof ( char ) );
    memcpy ( NODE -> data, element, ( strlen ( element ) + 1 ) );
    ( LIST -> size )++;                     //increase size of list
}




void LIST_addEnd ( struct list_t* LIST, type_t element )             //Adding element to end of list
{
    struct node_t *NODE = ( struct node_t* ) malloc ( sizeof ( struct node_t ) );

    if( LIST -> size == 0 )                                         //If list is empty
    {
        LIST -> last = NODE;
        LIST -> first = NODE;
        NODE -> next = NULL;
        NODE -> prev = NULL;
    }
    else
    {
        NODE -> prev = LIST -> last;
        ( LIST -> last ) -> next = NODE;
        LIST -> last = NODE;
        NODE -> next = NULL;
    }
    //initialize memory for data and taking string there
    NODE -> data = ( char* ) calloc ( strlen ( element ) + 1, sizeof ( char ) );
    memcpy ( NODE -> data, element, strlen ( element ) + 1 );
    ( LIST -> size )++;                     //increase size of list
}



type_t LIST_deleteBegin ( struct list_t* LIST )
{
    type_t data = ( LIST -> first ) -> data;
    if ( ( LIST -> size ) == 1 )
    {
        free ( LIST -> first );
        LIST_destructer ( LIST );
    }
    else
    {
        LIST -> first = ( LIST -> first )-> next;
        free ( ( LIST -> first ) -> prev );
        ( LIST -> first ) -> prev = NULL;
        ( LIST -> size )--;
    }
    return data;
}



type_t LIST_deleteEnd ( struct list_t* LIST )
{
    type_t data = LIST -> last -> data;

    if ( ( LIST -> size ) == 1 )
    {
        free ( LIST -> last );
        LIST_destructer ( LIST );
    }
    else
    {
        LIST -> last = LIST -> last -> prev;
        free ( ( LIST -> last ) -> next );
        ( LIST -> last ) -> next = NULL;
        ( LIST -> size )--;
    }
    return data;
}



int main ()
{
    int start = 0;
    struct list_t* current_list = LIST_constructer();

    char* text = ( char* ) calloc ( 255, sizeof ( char ) );
    FILE* input = fopen ( "data.txt", "r" );
    if ( input == NULL )
    {
        printf ( "Cannot open file \"data.txt\"\n" );
        system ( "pause" );
        return 0;
    }
    while ( !feof(input) )                      //reading information till end of file
    {
        fscanf( input, "%s", text );
        LIST_addBegin( current_list, text );
    }
    printf ( "Enter first element: " );
    scanf ( "%s", &start );
    while ( start <= current_list -> size )
        printf ( "%s\n", LIST_deleteEnd ( current_list ) );
    LIST_destructer ( current_list );
    return 0;
}
