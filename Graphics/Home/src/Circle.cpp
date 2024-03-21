#include <stdio.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int P = 5 - 4*r;

    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Plot the default point
    int newX = x + xc;
    int newY = y + yc;
    putpixel(newX, newY, WHITE);

    while (x < y) {
        x++;

        // Mid-point is inside or on the perimeter of the circle
        if (P < 0) {
            P += 2*x + 1;
        } 
        // Mid-point is outside the perimeter of the circle
        else {
            y--;
            P += 2*x - 2*y + 1;
        }

        // Determine symmetry points and plot them
        newX = x + xc;
        newY = y + yc;
        putpixel(newX, newY, WHITE);
        newX = -x + xc;
        newY = y + yc;
        putpixel(newX, newY, WHITE);
        newX = x + xc;
        newY = -y + yc;
        putpixel(newX, newY, WHITE);
        newX = -x + xc;
        newY = -y + yc;
        putpixel(newX, newY, WHITE);

        if (x != y) {
            // If the generated point is on the line x = y then the perimeter points have already been printed
            newX = y + xc;
            newY = x + yc;
            putpixel(newX, newY, WHITE);
            newX = -y + xc;
            newY = x + yc;
            putpixel(newX, newY, WHITE);
            newX = y + xc;
            newY = -x + yc;

            putpixel(newX, newY, WHITE);
            newX = -y + xc;
            newY = -x + yc;
            putpixel(newX, newY, WHITE);
        }
    }

    // Close graphics
    getch();
    closegraph();
}

int main() {
    int xc = 200, yc = 200, r = 100; // Adjust these values as needed

    // Draw the circle
    drawCircle(xc, yc, r);

    return 0;
}