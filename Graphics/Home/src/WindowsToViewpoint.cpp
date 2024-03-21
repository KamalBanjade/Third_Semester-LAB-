#include <graphics.h>
#include <math.h>

typedef struct Point
{
    float x;
    float y;
} Point;

void drawRectangle(Point topleft, Point bottomright, char *label)
{
    rectangle(topleft.x, topleft.y, bottomright.x, bottomright.y);
    outtextxy(topleft.x, topleft.y - 10, label);
}

void drawTriangle(Point P1, Point P2, Point P3)
{
    line(P1.x, P1.y, P2.x, P2.y);
    line(P2.x, P2.y, P3.x, P3.y);
    line(P3.x, P3.y, P1.x, P1.y);
}

void transformCoordinates(float xw, float yw, float *xv, float *yv, float Sx, float Sy, float Tx, float Ty)
{
    *xv = Sx * xw + Tx;
    *yv = Sy * yw + Ty;
}

void scaleTriangleToViewport(Point *P1, Point *P2, Point *P3, Point xvmax, Point xvmin, Point xwmax, Point xwmin)
{
    float Sx = (xvmax.x - xvmin.x) / (xwmax.x - xwmin.x);
    float Sy = (xvmax.y - xvmin.y) / (xwmax.y - xwmin.y);
    float Tx = xvmin.x - xwmin.x * Sx;
    float Ty = xvmin.y - xwmin.y * Sy;
    transformCoordinates(P1->x, P1->y, &P1->x, &P1->y, Sx, Sy, Tx, Ty);
    transformCoordinates(P2->x, P2->y, &P2->x, &P2->y, Sx, Sy, Tx, Ty);
    transformCoordinates(P3->x, P3->y, &P3->x, &P3->y, Sx, Sy, Tx, Ty);
}

int main()
{
    Point xwmax = {10, 10};
    Point xwmin = {300, 300};
    Point xvmax = {420, 310};
    Point xvmin = {630, 470};

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawRectangle(xwmax, xwmin, "Window");

    Point triangle_P1 = {150, 50};
    Point triangle_P2 = {250, 250};
    Point triangle_P3 = {50, 250};
    drawTriangle(triangle_P1, triangle_P2, triangle_P3);

    scaleTriangleToViewport(&triangle_P1, &triangle_P2, &triangle_P3, xvmax, xvmin, xwmax, xwmin);

    drawRectangle(xvmax, xvmin, "Viewport");

    drawTriangle(triangle_P1, triangle_P2, triangle_P3);

    getch();
    closegraph();

    return 0;
}