#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void constructgraph()
{
 int gd,gm;
 gd=gm=DETECT;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
 outtextxy(100,150,"P1");
 settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
 outtextxy(200,150,"P2");
 settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
 outtextxy(300,150,"P3");
 settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
 outtextxy(400,150,"P4");
 settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
 outtextxy(500,150,"P5");
 line(50,0,50,600);
 line(0,300,800,300);
 setcolor(RED);
 rectangle(50,200,150,300);
 floodfill(100,250,RED);
 setcolor(BLUE);
 rectangle(150,200,250,300);
 floodfill(200,250,BLUE);
 setcolor(YELLOW);
 rectangle(250,200,350,300);
 floodfill(300,250,YELLOW);
 setcolor(GREEN);
 rectangle(350,200,450,300);
 floodfill(400,250,GREEN);
 setcolor(MAGENTA);
 rectangle(450,200,550,300);
 floodfill(500,250,MAGENTA);
}
void systemprocess()
{
 constructgraph();
}
void batchprocess()
{
 constructgraph();
}
void interactiveprocess()
{
 constructgraph();
}
void userprocess()
{
 constructgraph();
}
void main()
{
 int ch;
 clrscr();
 printf("\n1. System Process");
 printf("\n2. Batch Process");
 printf("\n3. ");
 printf("\n4. ");
 printf("\n5. Exit");
 printf("\nEnter your choice of process: ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1 : systemprocess();
    break;
  case 2 : batchprocess();
    break;
  case 3 : interactiveprocess();
    break;
  case 4 : userprocess();
    break;
  case 5 : return;
  default : printf("\nPlease, enter a valid option!");
 }
 getch();
}
