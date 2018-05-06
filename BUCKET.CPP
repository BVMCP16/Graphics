#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int score=0,maxscore=0;
char arr[50];
void bucket(int j)
{
  rectangle(1,1,639,400);
  rectangle(1,400,639,479);
  line(295+j,372,345+j,372);
  arc(320+j,372,180,360,25);
}
void egg(int *k,int *x,int *y)
{
	ellipse(*x,(*y)+(*k),0,180,10,10);
}
void move(int *j,int *k,int *x,int *y)
{
	char key;
	key=getch();
	if(key=='d')
	{
	    if(*j<=289)
	    {
	      *j+=10;
	      cleardevice();
	      bucket(*j);
	      egg(k,x,y);
	    }
	}
	if(key=='a')
	{
	    if(*j>=-289)
	    {
	    *j-=10;
	    cleardevice();
	    bucket(*j);
	    egg(k,x,y);
	    }
	}
	  if(key=='e')
	  exit(0);
}
void main()
{
	int gd=0,gm,j=0,x,y,k=0,f=0,g=5;
	char key2;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	bucket(0);
	setbkcolor(1);
	while(1)
	{
		x=rand()%638+1;
		y=1;
		s:
		while(!kbhit())
		{
			k+=10;
			cleardevice();
			circle(x,y+k,10);
			bucket(j);
			sprintf(arr,"= %d",score);
			settextstyle(3,0,2);
			outtextxy(10,426,"SCORE");
			outtextxy(80,426,arr);
			settextstyle(3,0,2);
			outtextxy(240,426,"High Score ");
			sprintf(arr,"= %d",maxscore);
			outtextxy(350,426,arr);
			outtextxy(550,426,"E : Exit");

			if(score>=maxscore)
				maxscore=score;

			if(score>g)
			{
			  delay(100-10*f);
			  f++;
			  g+=5;
			}else{
			  delay(100-10*f);
			}
			if((y+k)>=400)
			{
				settextstyle(1,0,5);
				outtextxy(180,150,"| GAME OVER |");
				settextstyle(1,0,2);
				outtextxy(245,200,"Press R to Replay");
				x:
				key2=getch();
				if(key2=='r')
				{
					score=0;
					goto p;
				}
				else if(key2=='e')
					exit(0);
				else{
				  goto x;
				}
			}
			if((y+k)>=370 && x<(345+j) && x>(295+j))
			{
				score++;
				goto p;
			}
		}
		move(&j,&k,&x,&y);
		goto s;
		p:
			k=0;
	}
	getch();
}