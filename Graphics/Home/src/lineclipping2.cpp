#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Define the coordinates of the clipping window
float xl = 60, yl = 130, xh = 250, yh = 350;

// Define the region codes for each point
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Function to compute the region code for a point
int computeCode(float x, float y)
{
    int code = INSIDE;

    if (x < xl)
        code = code || LEFT;
    else if (x > xh)
        code = code || RIGHT;

    if (y < yl)
        code = code || BOTTOM;
    else if (y > yh)
        code = code || TOP;

    return code;
}

// Function to clip the line segment
void plotClipp(float x1, float y1, float x2, float y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);    
    int accept = 0;

    while (1)
    {
        if (!(code1 | code2))
        {
            // Both endpoints are inside the clipping window
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            // Both endpoints are outside the same region
            break;
        }
        else
        {
            // Compute intersection point using parametric equations
            float x, y;

            // Select the endpoint to clip
            int code_outside;

            if (code1 != INSIDE)
                code_outside = code1;
            else
                code_outside = code2;

            // Find intersection point
            if (code_outside & TOP)
            {
                x = x1 + (x2 - x1) * (yh - y1) / (y2 - y1);
                y = yh;
            }
            else if (code_outside & BOTTOM)
            {
                x = x1 + (x2 - x1) * (yl - y1) / (y2 - y1);
                y = yl;
            }
            else if (code_outside & RIGHT)
            {
                y = y1 + (y2 - y1) * (xh - x1) / (x2 - x1);
                x = xh;
            }
            else if (code_outside & LEFT)
            {
                y = y1 + (y2 - y1) * (xl - x1) / (x2 - x1);
                x = xl;
            }

            // Replace the endpoint outside the window with intersection point
            if (code_outside == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // If the line segment is accepted, draw it
    // If the line segment is accepted, draw it
    if ((code1 == INSIDE && code2 == INSIDE) || accept)
    {
        rectangle(xl + 320, yl, xh + 320, yh);
        line(x1 + 320, y1, x2 + 320, y2);
    }
}

int main()
{
    float P1x = 230, P1y = 150, P2x = 80, P2y = 300; // completely in
    float P3x = 180, P3y = 100, P4x = 30, P4y = 250; // partially in
    float P5x = 130, P5y = 50, P6x = -20, P6y = 200; // completely out

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    line(320, 0, 320, 480); // Adjusted for the center of the screen
    // Draw left rectangle
    rectangle(xl, yl, xh, yh);
    // Draw lines and text
    line(P1x, P1y, P2x, P2y); // completely in
    outtextxy(155, 225, "Completely In");

    line(P3x, P3y, P4x, P4y); // partially in
    outtextxy(105, 175, "Partially In");

    line(P5x, P5y, P6x, P6y); // completely out
    outtextxy(40, 125, "Completely Out");

    // Clip and draw lines using Cohen-Sutherland algorithm
    plotClipp(P1x, P1y, P2x, P2y);
    plotClipp(P3x, P3y, P4x, P4y);
    plotClipp(P5x, P5y, P6x, P6y);

    getch();
    closegraph();
    return 0;
}
