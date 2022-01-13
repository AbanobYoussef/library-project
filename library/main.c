#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "dynamicArray.h"
#include <windows.h>
COORD coord= {0,0};
void gotoxy(int x,int y);
void draw_box_log(void);
void set_colur (int x);
void draw_box_library(void);
void add_user (void);
void Login_user (void);
void print_menu (void);
void arrows (void);
////////////////////*Global Variables*////////////////////////////
int act_sz = 0;
int pos = 0;
char menu[2][30] = {"1) Add new user    " , "2) Login           "};
char ch;

struct USER
{
	char name[20];
	char pass[10];
};
struct USER user;
struct USER list[1000];
char bookName[225];
char bookAuther[225];
int Bookid;
int position =1;
char ch;

Array a;
////////////////////****************//////////////////////////////



int main()
{

    start_log_menu();
}

/////////////////library-box//////////////////////////////////////////////////////////
void drawLightBar(){

    initArray(&a, 5);
    loadFromfile(&a);

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
      draw_box_library();
        ShowConsoleCursor(0);
        position=1;
        do {
                SetConsoleTextAttribute(console,15);
                gotoxy(42,9 );printf("[1] Add Book                       ");
                gotoxy(42,10);printf("[2] Remove Book                    ");
                gotoxy(42,11);printf("[3] Display the data of books      ");
                gotoxy(42,12);printf("[4] Save data                      ");
                gotoxy(42,13);printf("[5] Load data                      ");
                gotoxy(42,14);printf("[6] Logout                         ");
                gotoxy(42,15);printf("[8] Exit                           ");
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
                    gotoxy(42,14);printf("[6] Logout                         ");
                    break;
                case 7:
                    SetConsoleTextAttribute(console,240);
                    gotoxy(42,15);printf("[8] Exit                           ");
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
        system("cls");
        printf("\nEnter the book name and the auther\n");
         printf("Book Name : ");
         scanf("%s",bookName);
         printf("Book Auther : ");
         scanf("%s",bookAuther);
        insertArray(&a, assignBook(bookName,bookAuther));
        system("cls");
        drawLightBar(console);
    case 2:
        system("cls");
        printf("\nEnter the book Id\n");
         printf("Book Name : ");
         scanf("%d",&Bookid);
         delete(&a ,seachById(a,Bookid));
        system("cls");
        drawLightBar(console);
    case 3:
        system("cls");
        printBooks(a);
        if(getch()=='\r')
        {
            system("cls");
            drawLightBar();
        }
        break;
    case 4:
       saveTofile(a);
        system("cls");
        drawLightBar(console);
    case 5:
        freeArray(&a);
        initArray(&a, 5);
        loadFromfile(&a);
        system("cls");
        drawLightBar(console);
    case 6:
        system("cls");
        start_log_menu();
        break;
    case 7:
        exit(0);


    }
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void draw_box_library(void)
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


    gotoxy(41,16);printf("%c",200);
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
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////log in //////////////////////////////////////////////////
///////////////////////////////////////////////////
//function to set colur
void set_colur (int colur)
{
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, colur);
}

///////////////////////////////////////////////////
//function to draw box in cmd
void draw_box_log(void)
{
	int i;
	gotoxy(35,8);
	printf("%c",201);

	for (i=0 ; i<=30 ; i++)
		printf("%c",205);

	printf ("%c",187);
	gotoxy(35,9);

	for (i=0;i<5;i++)
	{
		printf("%c",186);
		gotoxy(35,9+i);
	}
	printf("%c",200);

	for (i=0;i<=30;i++)
	{
		printf("%c",205);
		gotoxy(37+i,13);
	}
	printf("%c",188);
	gotoxy(67,9);

	for (i=0;i<5;i++)
	{
		printf("%c",186);
		gotoxy(67,9+i);
	}
}

///////////////////////////////////////////////////
//function to set main menu using light bar
void print_menu (void)
{
    int i;

	//printing colured menu
	for (i=0 ; i<2 ; i++ )
	{
		if(i==pos)
			set_colur(245);
		else
			set_colur(15);
		gotoxy(40 , 10+i);
		printf("%s\n",menu[i] );
		set_colur(15);
	}
}
///////////////////////////////////////////////////
//function to use up and down arrows in light bar menu
void arrows (void)
{
    int i;
   //using up and down arrows
	do
	{
		/*ch = getch();
		if (ch == -32) ch = getch();*/


		switch(ch)
		{
        case (27):
            exit(0);
            break;
		//up arrow
		case (72):
        pos--;
		if (pos == -1) pos=1;
		for (i=0 ; i<2 ; i++ )
		{
			if(i==pos)
				set_colur(245);
			else
				set_colur(15);
			gotoxy(40 , 10+i);
			printf("%s\n",menu[i] );

		}
		set_colur(15);
		break;

		//down arrow
		case(80):
        pos++;
		if (pos == 2) pos=0;
		for (i=0 ; i<2 ; i++ )
		{
			if(i==pos)
				set_colur(245);
			else
				set_colur(15);
			gotoxy(40 , 10+i);
			printf("%s\n",menu[i] );
		}
		set_colur(15);
		break;
		}
		ch = getch();
	}while (ch != 13 );
}


///////////////////////////////////////////////////
//function to add user
void add_user (void)
{
    int i;

    FILE * sfptr;

	system("cls");
	draw_box_log();
	gotoxy(40,10);
	set_colur(245);
	printf("User name:           ");
	gotoxy(40+10,10);
	scanf ("%s",&user.name);
	gotoxy(40,12);
	set_colur(245);
	printf("Password :           ");
	gotoxy(0,20);
	printf("Please Enter password for maximum 10 digits");
	set_colur(245);
	gotoxy(40+10,12);
	for (i=0 ; i < 10 ; i++ )
        {
          ch = getch();
          if(ch == '\r')
            break;
          user.pass[i]  = ch;
          putch ('*');
        }
	list[act_sz] = user;


    sfptr = fopen ("DB.txt" , "ab");
    fwrite(&list[act_sz] , sizeof(user) , 1 , sfptr);
    fclose(sfptr);

	act_sz++;
	set_colur(15);

}

///////////////////////////////////////////////////
//function to Login user

int login_user (void)
{
    struct USER arr_temp[1000];
    int counter = 0;
    int login_status = 0;
    int i;
    struct USER temp;

    FILE * lfptr;
    lfptr = fopen ("DB.txt" , "rb");

    system("cls");
	draw_box_log();
	gotoxy(40,10);
	set_colur(245);
	printf("User name :           ");
	gotoxy(40+10,10);
	scanf ("%s",&temp.name);
	gotoxy(40,12);
	set_colur(245);
	printf("Password :            ");
	gotoxy(40+10,12);
	for (i=0 ; i < 10 ; i++ )
        {
          ch = getch();
          if(ch == '\r')
            break;
          temp.pass[i]  = ch;
          putch ('*');
        }

    while (fread(&list[counter] , sizeof(list[counter]) , 1 , lfptr))
    {
        //arr_temp[counter] = temp;
        if( (strcmp(list[counter].name , temp.name)==0) && (strcmp(list[counter].pass , temp.pass)==0) )
        {
            login_status = 1;
            break;
        }

        else
            login_status = 0;
        counter++;
    }
    gotoxy(25,15);
    fclose(lfptr);
	set_colur(15);
    return (login_status);


}

void start_log_menu(){
do
	{
        system("cls");
	    ///////////////////////////////////////////////////
		draw_box_log();
		print_menu();
		arrows();
		///////////////////////////////////////////////////
		if (ch == 13)
        {
            set_colur(15);
            switch (pos)
            {
            case (0):
                add_user();
                break;

            case (1):
                if(login_user())
                {
                    system("cls");
                    drawLightBar();
                }else
                    printf("Incorrect user name or password !!");
                break;
            }
        }
        set_colur(15);
	}
	while ((ch=getch()) != 27);
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
