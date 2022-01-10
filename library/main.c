#include <stdio.h>
#include <stdlib.h>
//#include "Book.h"
//#include "ynamicArray.h"
#include <windows.h>
COORD coord= {0,0};
void gotoxy(int x,int y);
void draw_box(void);
int main()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int position =1;
    char ch;

    draw_box();
    ShowConsoleCursor(0);
    position=1;
    do {
            SetConsoleTextAttribute(console,15);
            gotoxy(42,9 );printf("[1] Add Book                       ");
            gotoxy(42,10);printf("[2] Remove Book                    ");
            gotoxy(42,11);printf("[3] Display the data of books      ");
            gotoxy(42,12);printf("[4] Save data                      ");
            gotoxy(42,13);printf("[5] Load data                      ");
            gotoxy(42,14);printf("[6] Add user                       ");
            gotoxy(42,15);printf("[7] Login user                     ");
            gotoxy(42,16);printf("[8] Exit                           ");
            printf("\n\n");


            switch(position)
            {
            case 1:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,9);printf("[1] Add Book                       ");
                break;
            case 2:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,10);printf("[2] Remove Book                    ");
                break;
            case 3:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,11);printf("[3] Display the data of books      ");
                break;
            case 4:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,12);printf("[4] Save data                      ");
                break;
            case 5:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,13);printf("[5] Load data                      ");
                break;
            case 6:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,14);printf("[6] Add user                       ");
                break;
            case 7:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,15);printf("[7] Login user                     ");
                break;
            case 8:
                SetConsoleTextAttribute(console,240);
                gotoxy(42,16);printf("[8] Exit                           ");
                break;

            }
            ch = getch();
            if(ch==-32)ch=getch();
            if(ch==72)
            {
                position--;
                if(position==0)position=8;
            }
            if(ch==80)
            {
                position++;
                if(position==9)position=1;
            }


}while(ch!=13);

gotoxy(40,18);
SetConsoleTextAttribute(console,15);
switch(position)
{
case 1:
    //add fun of add book
    //like ==> add();
    break;
case 2:
    //add fun of remove book
    //like ==> add();
    break;
case 3:
    //add fun of display the data of books
    //like ==> add();
    break;
case 4:
   //add fun of save data
    //like ==> add();
    break;
case 5:
    //add fun of load data
    //like ==> add();
    break;
case 6:
    //add fun of add user
    //like ==> add();
    break;
case 7:
    //add fun of login user
    //like ==> add();
    break;
case 8:
    exit(0);


}

}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void draw_box(void)
{
    int i ,j;
    gotoxy(41,8);printf("%c",201);
    for (i=1;i<36;i++)printf("%c",205);
    printf("%c",187);

    gotoxy(41,9);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);


    gotoxy(41,10);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(41,11);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(41,12);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

     gotoxy(41,13);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(41,14);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(41,15);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(41,16);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(41,17);printf("%c",200);
    for (i=1;i<36;i++)printf("%c",205);
    printf("%c",188);

}
void ShowConsoleCursor(int showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out,&cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out,&cursorInfo);

}

/*
Array a;
int i;

initArray(&a, 5);


 /*
  insertArray(&a, assignBook("a","Me "));
  insertArray(&a, assignBook("f","Me "));
  insertArray(&a, assignBook("w","Me "));
  insertArray(&a, assignBook("v","Me "));
  insertArray(&a, assignBook("b","Me "));
  insertArray(&a, assignBook("r","Me "));*/



   // bubbleSortAWriteToB(&a);


   /* for (i = 0; i < a.used; i++)
        printBook(a.array[i]);*/


// printf("%d",seachById(a,50).ID);
//printf("%d",seachByName(a,"a").ID);

    //delete(&a ,0);
   // loadFromfile(&a);
   // saveTofile(a);



   // printBooks(a);
//freeArray(&a);


 //   return 0;
//}
