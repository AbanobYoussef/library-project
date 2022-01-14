#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <string.h>
#include "Book.h"


 FILE * fPtr;
typedef struct {
  Book *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(Book));
  a->used = 0;
  BookId=0;
  a->size = initialSize;
}

void insertArray(Array *a, Book element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(Book));
  }
BookId++;
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


int seachById(Array books , int id){

    for(int i = 0; i<books.used;i++)
          if(books.array[i].ID==id)
              return (i);


    return (-1);
}


int seachByName(Array books , char Name[]){

    for(int i = 0; i<books.used;i++)
          if(strcmp(books.array[i].name, Name)==0)
              return (i);

    return (-1);
}




void delete(Array *_array ,int pos ){
/* Invalid delete position */
    int i;
    if(pos < 0 || pos > _array->used)
    {
        printf("Invalid position! Please enter position between 1 to %d", _array->used);
    }
    else
    {
        /* Copy next element value to current element */

        int used=_array->used;
        for( i=pos; i<used-1; i++)
        {
            _array->array[i] = _array->array[i + 1];
        }

        /* Decrement array size by 1 */
        _array->used=--used;
    }
}

void printBooks(Array _array)
{

    for(int i = 0 ; i<_array.used;i++){
        printBook(_array.array[i]);
    }

}



void loadFromfile(Array *_array){
    fPtr = fopen("file1.dat", "r");

    if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    Book _book;
    while(fread(&_book, sizeof(Book), 1, fPtr))
    {
        insertArray(_array, _book);
    }

    fclose(fPtr);
}

void saveTofile(Array _array){
    fPtr = fopen("file1.dat", "w");

    if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
        return ;
    }

    for(int i = 0 ; i<_array.used;i++){
         fwrite(&_array.array[i], sizeof(Book), 1, fPtr);
    }
    fclose(fPtr);
}
#endif // DYNAMICARRAY_H
