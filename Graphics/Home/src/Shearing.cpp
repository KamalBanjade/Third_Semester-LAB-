#include <stdio.h>
#include <graphics.h>

typedef struct Point
{
    float x;
    float y;
} Point;

Point X_Shear(Point P, float shearFactor)
{
    P.x += P.y * shearFactor;
    return P;
}

Point Y_Shear(Point P, float shearFactor)
{
    P.y += P.x * shearFactor;
    return P;
}

void drawTriangle(Point P1, Point P2, Point P3, int xOffset, int yOffset)
{
    line(P1.x + xOffset, P1.y + yOffset, P2.x + xOffset, P2.y + yOffset);
    line(P2.x + xOffset, P2.y + yOffset, P3.x + xOffset, P3.y + yOffset);
    line(P3.x + xOffset, P3.y + yOffset, P1.x + xOffset, P1.y + yOffset);
}

int main()
{
    Point P1 = {10, -10}, P2 = {200, -10}, P3 = {100, -100};

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:/TurboC3/BGI");

    // Calculate center of the window
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    // Calculate offset to center the drawing
    int xOffset = centerX;
    int yOffset = centerY;

    // Draw original triangle
    drawTriangle(P1, P2, P3, xOffset, yOffset);

    // Shear the triangle in X direction
    float shearFactorX = 0.5;
    P1 = X_Shear(P1, shearFactorX);
    P2 = X_Shear(P2, shearFactorX);
    P3 = X_Shear(P3, shearFactorX);
    drawTriangle(P1, P2, P3, xOffset, yOffset);

    // Shear the triangle in Y direction
    float shearFactorY = 0.5;
    P1 = Y_Shear(P1, shearFactorY);
    P2 = Y_Shear(P2, shearFactorY);
    P3 = Y_Shear(P3, shearFactorY);
    drawTriangle(P1, P2, P3, xOffset, yOffset);

    getch();
    closegraph();
    return 0;
}