#include <stdio.h>
#include <graphics.h>

void drawEllipse(int rr, int rx, int ry, int xc, int yc) {
    int x, y;
    int p1, p2;

    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Region 1
    x = 0;
    y = ry;
    p1 = rx * rx - ry * ry * rx + 2 * rx * rx;

    while (2 * rx * x <= 2 * ry * y) {
        // Plot the points in the current quadrant
        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);

        if (p1 < 0) {
            x++;
            p1 = p1 + 2 * rx * rx * x + rx * rx;
        } else {
            x++;
            y--;
            p1 = p1 + 2 * rx * rx * x - 2 * ry * ry * y + rx * rx;
        }
    }

    // Region 2
    p2 = rx * rx * (x + 0.5) * (x + 0.5) + ry * ry * (y - 1) * (y - 1) - rx * rx * ry * ry;

    while (y >= 0) {
        // Plot the points in the current quadrant
        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);

        if (p2 > 0) {
            y--;
            p2 = p2 - 2 * ry * ry * y + ry * ry;
        } else {
            x++;
            y--;
            p2 = p2 + 2 * rx * rx * x - 2 * ry * ry * y + rx * rx;
        }
    }

    // Close graphics
    getch();
    closegraph();
}

int main() {
    int rr = 1, rx = 80, ry = 60, xc = 300, yc = 300;

    // Draw the ellipse
    drawEllipse(rr, rx, ry, xc, yc);

    return 0;
}