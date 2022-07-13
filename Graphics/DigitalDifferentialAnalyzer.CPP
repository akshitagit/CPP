//Digital Differential Analyzer

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

struct point
{
    float x;
    float y;
};

void main()
{
    clrscr();

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    point beg, end, Line;
    float slope;
    int j, i;

    cout << "Enter co-ordinates of initial point: ";
    cin >> beg.x >> beg.y;
    cout << "Enter co-ordinates of last point: ";
    cin >> end.x >> end.y;
    Line = beg;

    ////////////////////////////////////////////////

    line(20, 25, 20, 454);   //x-axis
    line(15, 449, 619, 449); //y-axis

    ////////////////////////////////////////////////

    slope = fabs((end.y - beg.y) / (end.x - beg.x));
    if (slope <= 1)
    {
        for (i = 0; i < int(end.x - beg.x); i++)
        {
            putpixel(Line.x, 449 - Line.y, GREEN);
            Line.x += 1;
            Line.y += slope;
        }
    }
    else
    {
        for (i = 0; i < int(end.y - beg.y); i++)
        {
            putpixel(Line.x, 449 - Line.y, GREEN);
            Line.x += 1 / slope;
            Line.y += 1;
        }
    }

    getch();
    closegraph();
}
