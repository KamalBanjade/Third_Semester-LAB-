#include <graphics.h>

int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw some graphics primitives
    line(100, 100, 300, 100);   // Draw a line
    rectangle(100, 150, 300, 250);  // Draw a rectangle
    circle(200, 350, 50);    // Draw a circle
    ellipse(400, 200, 0, 360, 100, 50);  // Draw an ellipse
    getch();
    // Close the graphics window
    closegraph();


    return 0;
}