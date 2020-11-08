// Hermite or Bezier Curve drawing Algorithm

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void main(){
   clrscr();
   int i, j, x, y, ctrl[4][2];
   double t;

   cout<<" Enter 4 Controle points:\n ";
   for(i=0; i<4; i++)
      for(j=0; j<2; j++){
	 cin>>ctrl[i][j];
      }
   clrscr();

   int gd = DETECT,gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");

   for(i=0; i<4; i++)
	circle(ctrl[i][0], ctrl[i][1], 4);

   for(t=0.0; t<1.0; t = t+0.0005){
	x = ((-pow(t, 3) + 3*pow(t, 2) - 3*t +1)*ctrl[0][0]) +
	    ((3*pow(t,3) - 6*pow(t, 2) + 3*t)*ctrl[1][0]) +
	    ((-3*pow(t, 3) + 3*pow(t, 2))*ctrl[2][0]) +
	    (pow(t, 3)*ctrl[3][0]);
	y = ((-pow(t, 3) + 3*pow(t, 2) - 3*t +1)*ctrl[1][1]) +
	    ((3*pow(t,3) - 6*pow(t, 2) + 3*t)*ctrl[1][1]) +
	    ((-3*pow(t, 3) + 3*pow(t, 2))*ctrl[2][1]) +
	    (pow(t, 3)*ctrl[3][1]);

	putpixel(x, y, RED);
   }

   setcolor(BLUE);
   line(ctrl[0][0], ctrl[0][1], ctrl[1][0], ctrl[1][1]);
   line(ctrl[1][0], ctrl[1][1], ctrl[2][0], ctrl[2][1]);
   line(ctrl[2][0], ctrl[2][1], ctrl[3][0], ctrl[3][1]);

   getch();
}
