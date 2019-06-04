#include<iostream.h>
#include<conio.h>
//#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#define kb_up 72
int count=0,l=0;
int i=20,j=14;
int ju=0,up=0;
int i1=70,j1=14;
int u=60,v=6;
void score(int a=60,int b=6)
{
//	clrscr();
//	int count=0;
//	int a,b;
	u=a;
	v=b;
	for(;a<u+7;a++)
	{
		gotoxy(a,v-1);
		cout<<"_";
		gotoxy(a,v+1);
		cout<<"_";
		gotoxy(a,v+3);
		cout<<"_";
	}
	for(;b<v+4;b++)
	{
		gotoxy(u,b);
		cout<<"|";
		gotoxy(u+6,b);
		cout<<"|";
	}
	gotoxy(u+1,v);
	cout<<"SCORE";
	gotoxy(u+2,v+2);
	cout<<count;
}

void tree(int& x1,int& y1)
{
//	clrscr();
	if(x1<3)  x1=60;
	gotoxy(x1-1,y1-1);
	cout<<"#";
	gotoxy(x1+1,y1-1);
	cout<<"#";
	gotoxy(x1,y1);
	cout<<"#";
	gotoxy(x1,y1-2);
	cout<<"#";
	gotoxy(x1,y1+1);
	cout<<"#";
}
void track()
{
	for(int i=0;i<80;i++)
	{
		gotoxy(i,15);
		cout<<"_";
	}

}
void ball(int &x,int &y)
{
	clrscr();
	track();
	score();
//	tree(x-15,y);
//	if(x>70)	x=1;
	gotoxy(x,y);
	cout<<"*";
	gotoxy(x+1,y);
	cout<<"*";
	gotoxy(x,y+1);
	cout<<"*";
	gotoxy(x-1,y);
	cout<<"*";
	gotoxy(x,y-1);
	cout<<"*";
}

void jump()
{
	if(j>7 && up==1)
		j--;
	else
	{	j++;
		up=0;	}
	if(j==14)
		ju=0;
	ball(i,j);
}

void main()
{
	clrscr();
//	int i=10,j=14;
	char ch;
	int n=1;
	while(1)
	{
		if(kbhit())
		{
			ch=getch();
			switch(ch)
			{
			/*       	case 'w':
				case 'W':
			*/	case kb_up:ju=1;
					 up=1;
					 break;
				/*case 's':
				case 'S':j<14?j++:j;
					 ball(i,j);
					 break;
*/				case 'x':
				case 'X':exit(0);
			}
		}
		delay(100-(n*5));

		if(ju==1)
			jump();
		else
			ball(i,j);
//		i++;
		i1--;
		tree(i1,j1);
		if(n>=10)
		{
			tree(i1-10,j1);
		  //	delay(50);
			n--;
		}

		if(i==i1+1 || i==i1-1)
		{
		       //	n++;
			if((j>=j1)&&(i>=i1))
			{	break;       }
			else
			{  n++;
			   l++;
			}
		}
		else
		{
		 count++;
 //		 n=n+1;
		}
		gotoxy(10,2);
//		l--;
		cout<<"LEVEL "<<l;

	}

	clrscr();
	cout<<"Game Over!";
	score(10);
	getch();
}
