#include <stdio.h>
#include <graphics.h>
#include<math.h>
#include <Windows.h>


void drawLineDDA(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }

    getch();
    closegraph();
}

int main() {
    int x1 = 50, y1 = 50, x2 = 200, y2 = 150; // Change these coordinates for different points

    drawLineDDA(x1, y1, x2, y2);

    return 0;
}