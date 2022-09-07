#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
int width=20,height=20,gameover;
int flag,score,x,y,fruitx,fruity; 
int tailX[100],tailY[100];
int tailcount=0;
using namespace std;
void setup()
{ 
    gameover=0;
	x=width/2;
	y=height/2;
	
	label1:
		fruitx=rand()%20;
		if(fruitx==0)
		goto label1;
	label7:
		fruity=rand()%20;
		if(fruity==0)
		goto label7;
	score=0;
		
}
void draw()
{
	int i,j,k;
	system("cls");
	for(i=0;i<width;i++)
	{
		for(j=0;j<height;j++)
		{
		 if(i==0||i==height-1||j==0||j==width-1)
				printf("*");
		  else
		   {
		     if(i==x && j==y)
		     printf("O");
		      else if(i==fruitx&&j==fruity)
             printf("F");
			   else
		       {
		     	 int ch=0;
		    	 for(k=0;k<tailcount;k++)  //i,j (pair)
		        	{
		    	    	if(i==tailX[k] && j==tailY[k])
		    		    {
		    		    	printf("o");
		    		    	ch=1;
				     	}
			    	} 
				     if(ch==0)
			        printf(" ");
				
			    }
			   
		   }
		}
		
		printf("\n");
	}
	printf("SCORE :%d",score);	
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
		case 'a':
			flag=1;
			break;
		case 's':
			flag=2;
			break;
		case 'w':
			flag=3;
			break;
	    case 'd':
		    flag=4;
			break;
	    case 'x':
	    	gameover=1;
	    	break;
			}
	    	
	}
}
void makelogic()
{
	int p; //looping variable 
	int prevX=tailX[0];
    int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	
	for(p=1;p<tailcount;p++)
	{
		prev2X=tailX[p];
		prev2Y=tailY[p];
		tailX[p]=prevX;
		tailY[p]=prevY;
		prevX=prev2X;
		prevY=prev2Y;	 
	}
	
	switch(flag)
	{
		case 1:
			y--;
			break;
		case 2:
			x++;
			break;
		case 3:
			x--;
			break;
		case 4:
			y++;
			break;
        default:
			break;
	}
	if(x==0||x==width-1||y==0||y==height-1)
	gameover=1;
	for(p=0;p<tailcount;p++)
	{
		if(x==tailX[p] && y==tailY[p])
		gameover=1;
	}
	if(x==fruitx && y==fruity)
	{
	label3:
		fruitx=rand()%20;
		if(fruitx==0)
		goto label3;
	label4:
		fruity=rand()%20;
		if(fruity==0)
		goto label4;
	   score+=10;
	   tailcount++;
	}
}

int main() 
{
	int poi;
	setup();
	while(!gameover)
	{
	label56:
	draw();
	input();
	makelogic();
   }
   	cout<<"\n\n\t\t Press O to exit the game!";
   	cin>>poi;
   	
   	if(poi==0)
   	{
   		goto label56;
	}
}
