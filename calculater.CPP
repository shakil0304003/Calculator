#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
getmousepos(int *button,int *x,int *y);
restrictmouseptr(int x1,int y1,int x2, int y2);
showmouseptr();
union REGS i,o;
class cal
{protected:
long long int i,x[4][7],y[4][7],x1[4][7],y1[4][7],j,a,b,sin[20],num,hh1,jj,rr1;
long double sa[20],poin,pi,jj1;
char stri[90];
public:
cal()
{ a=20;b=45;num=0;sa[0]=0;sin[0]=' ';poin=0;pi=3.141592654;
  for(j=0;j<4;j++)
 { b=b+45*2;a=20;
  for(i=0;i<7;i++)
  { a=a+60;
    x[j][i]=a;x1[j][i]=a+30;y[j][i]=b;y1[j][i]=b+45;
   }
}
 }
void show()
{ cleardevice();
  setcolor(WHITE);
  rectangle(55,55,500,100);
  setfillstyle(SOLID_FILL,WHITE);
  floodfill(56,76,WHITE);
  setcolor(WHITE);
  rectangle(520,250,600,300);
  outtextxy(525,265," SHAKIL ");
  outtextxy(525,275,"  CUET  ");
  outtextxy(525,285," 0304003");
  setcolor(RED);
  rectangle(50,50,510,455);
  rectangle(49,49,511,456);
  for(j=0;j<4;j++)
  for(i=0;i<7;i++)
  {setcolor(10);
  rectangle(x[j][i],y[j][i],x1[j][i],y1[j][i]);
  setfillstyle(EMPTY_FILL,10);
  floodfill(x[j][i]+1,y[j][i]+1,10);
  switch(j*7+i)
  {case 0:
   outtextxy(x[j][i],y[j][i]+21," +");
   break;
   case 1:
   outtextxy(x[j][i],y[j][i]+21," -");
   break;
   case 2:
   outtextxy(x[j][i],y[j][i]+21," X");
   break;
   case 3:
   outtextxy(x[j][i],y[j][i]+21," /");
   break;
   case 4:
   outtextxy(x[j][i],y[j][i]+21," 1");
   break;
   case 5:
   outtextxy(x[j][i],y[j][i]+21," 2");
   break;
   case 6:
   outtextxy(x[j][i],y[j][i]+21," 3");
   break;
   case 7:
   outtextxy(x[j][i]+3,y[j][i]+21,"sin");
   break;
   case 8:
   outtextxy(x[j][i]+6,y[j][i]+11," -1");
   outtextxy(x[j][i],y[j][i]+18,"sin");
   break;
   case 9:
   outtextxy(x[j][i]+3,y[j][i]+21,"cos");
   break;
   case 10:
   outtextxy(x[j][i]+6,y[j][i]+11," -1");
   outtextxy(x[j][i],y[j][i]+18,"cos");
   break;
   case 11:
   outtextxy(x[j][i],y[j][i]+21," 4");
   break;
   case 12:
   outtextxy(x[j][i],y[j][i]+21," 5");
   break;
   case 13:
   outtextxy(x[j][i],y[j][i]+21," 6");
   break;
   case 14:
   outtextxy(x[j][i]+3,y[j][i]+21,"tan");
   break;
   case 15:
   outtextxy(x[j][i]+6,y[j][i]+11," -1");
   outtextxy(x[j][i],y[j][i]+18,"tan");
   break;
   case 16:
   outtextxy(x[j][i]+3,y[j][i]+21,"log");
   break;
   case 17:
   outtextxy(x[j][i]+6,y[j][i]+11," -1");
   outtextxy(x[j][i],y[j][i]+18,"log");
   break;
   case 18:
   outtextxy(x[j][i],y[j][i]+21," 7");
   break;
   case 19:
   outtextxy(x[j][i],y[j][i]+21," 8");
   break;
   case 20:
   outtextxy(x[j][i],y[j][i]+21," 9");
   break;
   case 21:
   outtextxy(x[j][i],y[j][i]+21,"sqrt");
   break;
   case 22:
   outtextxy(x[j][i]+15,y[j][i]+13,"2");
   outtextxy(x[j][i],y[j][i]+18," X");
   break;
   case 23:
   outtextxy(x[j][i],y[j][i]+14," AC");
   outtextxy(x[j][i],y[j][i]+24,"\\ON");
   break;
   case 24:
   outtextxy(x[j][i],y[j][i]+21," .");
   break;
   case 25:
   outtextxy(x[j][i],y[j][i]+21," 0");
   break;
   case 26:
   outtextxy(x[j][i],y[j][i]+21," =");
   break;
   case 27:
   outtextxy(x[j][i]+4,y[j][i]+21,"OFF");
   break;
  }   }
  rr1=0;
  for(i=0;i<=num;i++)
  { hh1=sa[i]; jj=0;
    if(hh1<0)
    {hh1=-hh1;stri[rr1]='-';rr1++;}
    do{hh1=hh1/10;
       jj=jj+1;
      }while(hh1!=0);
    hh1=sa[i];
    if(hh1<0)
    hh1=-hh1;
    for(j=jj;j>=1;j--)
    {stri[rr1-1+j]=hh1%10+48;
    hh1=hh1/10;}
    rr1=rr1+jj;
    hh1=sa[i];
    if(hh1<0)
    {hh1=-hh1;
     jj1=-sa[i];
    if(jj1>hh1)
    {jj1=jj1-hh1;
     goto mn;} }
    if(sa[i]>hh1)
    {
    jj1=sa[i]-hh1;   mn:
    stri[rr1]='.';rr1++;
    for(j=0;j<6;j++)
    {hh1=jj1*10;jj1=jj1*10;jj1=jj1-hh1;
    stri[rr1]=hh1+48;
    rr1++;
    if(jj1==0)
    break;
    }
    }
    stri[rr1]=sin[i];
    rr1++;

  }
  j=strlen(stri);
  if(j>rr1)
  for(i=rr1;i<j;i++)
  stri[i]=' ';
setcolor(BLACK);
outtextxy(57,74,stri);

}
void calcu(int p,int q)
{for(j=0;j<4;j++)
 for(i=0;i<7;i++)
 {if((x[j][i]<p&&p<x1[j][i])&&(q>y[j][i]&&q<y1[j][i]))
  {a=j*7+i;
  switch(a)
  {case 0:sin[num]='+';
	  num=num+1;sa[num]=0; sin[num]=' ';poin=0;
	  play(1);
	  break;
   case 1:sin[num]='-';
	  num=num+1;sa[num]=0;sin[num]=' ';poin=0;
	  play(1);
	  break;
   case 2:sin[num]='x';
	  num=num+1;sa[num]=0;sin[num]=' ';poin=0;
	  play(1);
	  break;
   case 3:sin[num]='/';
	  num=num+1;sa[num]=0;sin[num]=' ';poin=0;
	  play(1);
	  break;
  case 4:if(poin==0)
	 sa[num]=sa[num]*10+1;
	 else
	 {sa[num]=sa[num]+1/poin;
	 poin=poin*10;}
	 break;
  case 5:if(poin==0)
	 sa[num]=sa[num]*10+2;
	 else
	 {sa[num]=sa[num]+2/poin;
	 poin=poin*10;}
	 break;
  case 6:if(poin==0)
	 sa[num]=sa[num]*10+3;
	 else
	 {sa[num]=sa[num]+3/poin;
	 poin=poin*10;}
	 break;
  case 7:sa[num]=sinl((sa[num]*pi)/180);
	 break;
 case 8:sa[num]=(asinl(sa[num])*180)/pi;
       break;
case 9:sa[num]=cos((sa[num]*pi)/180);
	break;
case 10:sa[num]=(acos(sa[num])*180)/pi;
	break;
case 14:sa[num]=tan((sa[num]*pi)/180);
	break;
case 15:sa[num]=(atan(sa[num])*180)/pi;
	break;
case 16:sa[num]=log(sa[num]);
	break;
case 17:sa[num]=exp(sa[num]);
	break;
case 11:if(poin==0)
	sa[num]=sa[num]*10+4;
	else
	{sa[num]=sa[num]+4/poin;
	poin=poin*10;}
	break;
case 12:if(poin==0)
	sa[num]=sa[num]*10+5;
	else
	{sa[num]=sa[num]+5/poin;
	poin=poin*10;}
	break;
case 13:if(poin==0)
	sa[num]=sa[num]*10+6;
	else
	{sa[num]=sa[num]+6/poin;
	poin=poin*10;}
	break;
case 18:if(poin==0)
       sa[num]=sa[num]*10+7;
       else
       {sa[num]=sa[num]+7/poin;
       poin=poin*10;}
       break;
case 19:if(poin==0)
       sa[num]=sa[num]*10+8;
       else
       {sa[num]=sa[num]+8/poin;
       poin=poin*10;}
       break;
case 20:if(poin==0)
	sa[num]=sa[num]*10+9;
	else
	{sa[num]=sa[num]+9/poin;
	poin=poin*10;}
	break;
case 25:if(poin==0)
	sa[num]=sa[num]*10+0;
	else
	{sa[num]=sa[num]+0/poin;
	poin=poin*10;}
	break;
case 21:sa[num]=sqrt(sa[num]);
       break;
case 22:sa[num]=sa[num]*sa[num];
       break;
case 23:num=0;sa[0]=0;sin[0]=' ';poin=0;
	play(2);
	break;
case 24:poin=10;
	break;
case 26:poin=0;
	for(i=0;i<num;i++)
	{if(sin[i]=='+')
	 sa[0]=sa[i+1]+sa[0];
	 if(sin[i]=='-')
	 sa[0]=sa[0]-sa[i+1];
	 if(sin[i]=='x')
	 sa[0]=sa[0]*sa[i+1];
	 if(sin[i]=='/')
	 sa[0]=sa[0]/sa[i+1];
	}
	num=0;sin[0]=' '; play(3);
	break;
   default:
      break;
  }
  goto kk; }
  }

kk:
}
void play(int sa1)
{float NaturalFreq[7]={130.81,146.83,164.81,174.61,196,220,246.94};
int n1,i1;
switch(sa1)
{case 1:sound(NaturalFreq[6]*6);
	delay(60);
	nosound();
	break;
case 2:for(i1=0;i1<15;i1++)
      {n1=random(7);
       sound(NaturalFreq[n1]*4);
       delay(80); }
       nosound();
       break;
case 3:for(i1=4;i1>=0;i1--)
       {sound(NaturalFreq[i1]*4);
       delay(10);  }
       nosound();
       break;
 }
}
};

void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"e:\\tc\\bgi");
int maxx,maxy,x,y,button=1,prevx,prevy;
cal ca;
ca.show();
restrictmouseptr(50,50,510,455);  //50,50,510,455
showmouseptr();
while(1)
{
 getmousepos(&button,&x,&y);
 if((button & 1)==1)
 {
 if((x>440&&y>405)&&(x<470&&y<450))
  goto xy;
 else
ca.calcu(x,y);

ca.show();
button=0;
delay(100);
  }
}
xy:

closegraph();
}



initmouse()
{i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
}
getmousepos(int *button,int *x,int *y)
{i.x.ax=3;
 int86(0x33,&i,&o);
 *button=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
showmouseptr()
{i.x.ax=1;
 int86(0x33,&i,&o);
}
restrictmouseptr(int x1,int y1,int x2, int y2)
{i.x.ax=7;
 i.x.cx=x1;
 i.x.dx=x2;
 int86(0x33,&i,&o);
 i.x.ax=8;
 i.x.cx=y1;
 i.x.dx=y2;
 int86(0x33,&i,&o);
 }
