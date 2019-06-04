#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define kb_up 72
#define kb_down 80
#define kb_right 77
#define kb_escape 27
int i,j,x1=2,y1=10,g=0;
int a=5,b,count=0;
void score(int a=65,int b=6)
{
	for(a=65;a<72;a++)
	{
		gotoxy(a,5);
		cout<<"_";
		gotoxy(a,7);
		cout<<"_";
		gotoxy(a,9);
		cout<<"_";
	}
	for(b=6;b<10;b++)
	{
		gotoxy(65,b);
		cout<<"|";
		gotoxy(71,b);
		cout<<"|";
	}
	gotoxy(66,6);
	cout<<"SCORE";
	gotoxy(68,8);
	cout<<count;
}

void bullet()
{
	if(g==0)
	  b=y1+1;
	gotoxy(a,b);
	cout<<"->";
	if(a==60)
	{
	   g=0;
	   a=5;
	}
}
void line();
void tank();
void target(int &x,int &y)
{
//	line();
	clrscr();
	line();
	tank();
	if(g==1)
	   bullet();
	score();
	if(y==22)	y=0;
	gotoxy(x,y-1);
	cout<<"|";
	gotoxy(x,y);
	cout<<"|";
	gotoxy(x,y+1);
	cout<<"|";
/*	gotoxy(x,y+2);
	cout<<"|";
	gotoxy(x,y-2);
	cout<<"|";
*/
}
void tank()
{
	gotoxy(x1,y1+1);
	cout<<"[";
	gotoxy(x1,y1+2);
	cout<<"[";
	gotoxy(x1,y1);
	cout<<"[";
	gotoxy(x1+2,y1+1);
	cout<<"]";
	gotoxy(x1+2,y1+2);
	cout<<"]";
	gotoxy(x1+2,y1);
	cout<<"]";
	gotoxy(x1+1,y1-1);
	cout<<"_";
	gotoxy(x1+1,y1+2);
	cout<<"_";
	gotoxy(x1+3,y1+1);
	cout<<"-";
}
void line()
{
	for(int i=0;i<23;i++)
	{
		gotoxy(1,i);
		cout<<"|";
	}

}

void main()
{
	clrscr();
	char opt;
	i=60;  j=0;

	while(1)
	{
		if(kbhit())
		{
			opt=getch();
			switch(opt)
			{
			 case kb_up:y1--;
				    break;
			 case kb_down:y1++;
					break;
			 case kb_right:bullet();
					g=1;
					break;
			 case kb_escape: exit(1);
					 break;
			}
		}

/*		tank();
		delay(100);
		if(g==1)
		bullet();
		delay(50);        */
		target(i,j);
		delay(400);
		j++;
		if(g==1)
		  a+=5;
		if(((i==x1-5)||(i==x1+1)||(i==x1-6))&&(j==y1))
		   break;
//		clrscr();

	}
	getch();
}