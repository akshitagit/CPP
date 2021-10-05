//C Program to draw a Mid-Point Circle
#include<stdio.h>
#include<graphics.h>

//Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw (int x_centre, int y_centre, int r)
{
  int x = r,y = 0;
  //When radius is zero only a single point will be printed
  //Initialising the value of P
  int P = 1 - r;
  while (x > y)
  {
    y++;
    //Mid-Point is inside or on the perimeter
    if (P <= 0)
      P = P + 2 * y + 1;
    //Mid-Point is outside the perimeter
    else
    {
      x--;
      P = P + 2 * y - 2 * x + 1;
    }
    if (x < y)
      break;
    //Drawing the generated point and its reflection in the other octants after translation
    putpixel(x + x_centre, y + y_centre, 15);
    putpixel(-x + x_centre, y + y_centre, 15);
    putpixel(x + x_centre, -y + y_centre, 15);
    putpixel(-x + x_centre, -y + y_centre, 15);
    //If the generated point is on line x=y then the circle is already printed
    if (x != y)
    {
      putpixel(y + x_centre, x + y_centre, 15);
      putpixel(-y + x_centre, x + y_centre, 15);
      putpixel(y + x_centre, -x + y_centre, 15);
      putpixel(-y + x_centre, -x + y_centre, 15);
    }
  }
}

//Driver Code
int main()
{
  int x,y,r;
  printf("Enter the X and Y coordinate of circle:\n");
  scanf("%d %d",&x,&y);
  printf("Enter the radius of the circle:\n");
  scanf("%d",&r);
  initwindow(640,480,"Mid-Point Circle Drawing Algorithm");
  midPointCircleDraw(x,y,r);
  getch();
  return 0;
}
