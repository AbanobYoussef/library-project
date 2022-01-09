#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "dynamicArray.h"
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
            gotoxy(40,11);printf("[1] Type your name                 ");
            gotoxy(40,12);printf("[2] Type your name                 ");
            gotoxy(40,13);printf("[3] Type your name                 ");
            gotoxy(40,14);printf("[4] exit                           ");
            printf("\n\n");


            switch(position)
            {
            case 1:
                SetConsoleTextAttribute(console,240);
                gotoxy(40,11);printf("[1] Type your name                 ");
                break;
            case 2:
                SetConsoleTextAttribute(console,240);
                gotoxy(40,12);printf("[2] Type your name                 ");
                break;
            case 3:
                SetConsoleTextAttribute(console,240);
                gotoxy(40,13);printf("[3] Type your name                 ");
                break;
            case 4:
                SetConsoleTextAttribute(console,240);
                gotoxy(40,14);printf("[4] exit                           ");
                break;

            }
            ch = getch();
            if(ch==-32)ch=getch();
            if(ch==72)
            {
                position--;
                if(position==0)position=4;
            }
            if(ch==80)
            {
                position++;
                if(position==5)position=1;
            }


}while(ch!=13);

gotoxy(40,18);
SetConsoleTextAttribute(console,15);
printf("your choose is : %d\n",position);

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
    gotoxy(39,10);printf("%c",201);
    for (i=1;i<36;i++)printf("%c",205);
    printf("%c",187);

    gotoxy(39,11);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);


    gotoxy(39,12);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(39,13);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(39,14);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

     gotoxy(39,15);printf("%c",186);
    for (i=1;i<36;i++)printf(" ");
    printf("%c",186);

    gotoxy(39,16);printf("%c",200);
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
