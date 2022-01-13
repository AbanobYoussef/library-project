#ifndef BOOK_H
#define BOOK_H


typedef struct book {
     int ID;
    char name[225];
    char auther[225];
}Book;
int BookId=0 ;
 Book assignBook( char Name[] , char Auther[]){
     Book _book;


    _book.ID = BookId++;
    strcpy( _book.name, Name);
    strcpy(  _book.auther , Auther);


    return _book;

}
Book creatBook(){
     Book _book;
    return _book;

}
void printBook( Book _book){
    Book book=assignBook("Hello", "Me");

 printf("the book id => %d \n the book name => %s \n the book auther => %s \n", _book.ID,_book.name,_book.auther);


}

#endif
