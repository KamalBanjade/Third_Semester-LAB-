#include <stdio.h>
#include <graphics.h>
#include<math.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p = 2 * dy - dx;

    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
    } else {
        x = x1;
        y = y1;
    }

    putpixel(x, y, WHITE);

    while (x < x2) {
        x++;

        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }

        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
}

int main() {
    int x1 = 50, y1 = 50, x2 = 200, y2 = 150; // Change these coordinates for different points

    drawLineBresenham(x1, y1, x2, y2);

    return 0;
}