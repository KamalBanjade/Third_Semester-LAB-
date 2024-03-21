#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

float xl = 60, yl = 130, xh = 250, yh = 350;

void plotClipp(float xa, float ya, float xb, float yb)
{
    float dx = xb - xa;
    float dy = yb - ya;
    float tmin = 0, tmax = 1;
    float p[4], q[4], t[4];

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = xa - xl;
    q[1] = xh - xa;
    q[2] = ya - yl;
    q[3] = yh - ya;

    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
            {
                // Line is parallel to the edge and outside the window
                return;
            }
        }
        else
        {
            t[i] = q[i] / p[i];
            if (p[i] < 0)
            {
                if (t[i] > tmin)
                    tmin = t[i];
            }
            else
            {
                if (t[i] < tmax)
                    tmax = t[i];
            }
        }
    }

    if (tmin > tmax)
    {
        // Line is outside the window
        return;
    }

    float x1_clip = xa + tmin * dx;
    float y1_clip = ya + tmin * dy;
    float x2_clip = xa + tmax * dx;
    float y2_clip = ya + tmax * dy;

    rectangle(xl + 320, yl, xh + 320, yh);
    line(x1_clip + 320, y1_clip, x2_clip + 320, y2_clip);
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

    // Clip and draw lines
    plotClipp(P1x, P1y, P2x, P2y);
    plotClipp(P3x, P3y, P4x, P4y);
    plotClipp(P5x, P5y, P6x, P6y);

    getch();
    closegraph();
    return 0;
}
