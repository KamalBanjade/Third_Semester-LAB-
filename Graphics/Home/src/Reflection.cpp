#include <stdio.h>
#include <graphics.h>

typedef struct Point
{
    float x;
    float y;
} Point;

Point X_Reflection(Point P)
{
    Point Temp;
    Temp.x = P.x;
    Temp.y = -P.y;
    return Temp;
}

Point Y_Reflection(Point P)
{
    Point Temp;
    Temp.x = -P.x;
    Temp.y = P.y;
    return Temp;
}

void drawTriangle(Point P1, Point P2, Point P3)
{
    line(P1.x + 320, P1.y + 240, P2.x + 320, P2.y + 240);
    line(P2.x + 320, P2.y + 240, P3.x + 320, P3.y + 240);
    line(P3.x + 320, P3.y + 240, P1.x + 320, P1.y + 240);
}

int main()
{
    Point P1 = {10, -10}, P2 = {200, -10}, P3 = {100, -100};

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:/TurboC3/BGI");

    line(0, 240, 640, 240);
    line(320, 0, 320, 480);
    outtextxy(110 + 320, -120 + 240, "Original Triangle.");
    outtextxy(110 + 320, 120 + 240, "X Reflected Triangle.");
    outtextxy(-270 + 320, -120 + 240, "Y Reflected Triangle.");

    // Draw original triangle
    drawTriangle(P1, P2, P3);

    // Reflect about X axis
    Point P1_x_reflected = X_Reflection(P1);
    Point P2_x_reflected = X_Reflection(P2);
    Point P3_x_reflected = X_Reflection(P3);
    drawTriangle(P1_x_reflected, P2_x_reflected, P3_x_reflected);

    // Reflect about Y axis
    Point P1_y_reflected = Y_Reflection(P1);
    Point P2_y_reflected = Y_Reflection(P2);
    Point P3_y_reflected = Y_Reflection(P3);
    drawTriangle(P1_y_reflected, P2_y_reflected, P3_y_reflected);

    getch();
    closegraph();
    return 0;
}