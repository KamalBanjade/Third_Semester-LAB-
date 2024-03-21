#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define MAX_VERTICES 16

typedef struct vertex {
    int x;
    int y;
} Vertex;

Vertex vertices[MAX_VERTICES] = {
    {155, 90}, {125, 195}, // Line 1
    {155, 90}, {180, 195}, // Line 2
    {155, 360}, {125, 250}, // Line 3
    {155, 360}, {180, 250}, // Line 4
    {20, 225}, {125, 195}, // Line 5
    {20, 225}, {125, 250}, // Line 6
    {290, 225}, {180, 195}, // Line 7
    {290, 225}, {180, 250}  // Line 8
};

Vertex new_vertices[MAX_VERTICES] = {{0}};

int clip(int i, int limit, int edge, int clipValue) {
    int j = 0;
    float slope;

    for (; i < limit; i++) {
        int x1 = vertices[i].x, y1 = vertices[i].y;
        int x2 = vertices[(i + 1) % limit].x, y2 = vertices[(i + 1) % limit].y;

        slope = (float)(y2 - y1) / (x2 - x1);

        // Check if both endpoints are outside the clipping window
        if (((edge == 'l' && x1 < clipValue && x2 < clipValue) ||
             (edge == 't' && y1 < clipValue && y2 < clipValue) ||
             (edge == 'r' && x1 > clipValue && x2 > clipValue) ||
             (edge == 'b' && y1 > clipValue && y2 > clipValue))) {
            continue;
        }

        // Check if both endpoints are inside the clipping window
        if (((edge == 'l' && x1 >= clipValue && x2 >= clipValue) ||
             (edge == 't' && y1 >= clipValue && y2 >= clipValue) ||
             (edge == 'r' && x1 <= clipValue && x2 <= clipValue) ||
             (edge == 'b' && y1 <= clipValue && y2 <= clipValue))) {
            new_vertices[j].x = x2;
            new_vertices[j++].y = y2;
            continue;
        }

        // Handle cases where one endpoint is inside and the other is outside
        if ((edge == 'l' && x1 >= clipValue && x2 < clipValue) ||
            (edge == 't' && y1 >= clipValue && y2 < clipValue) ||
            (edge == 'r' && x1 <= clipValue && x2 > clipValue) ||
            (edge == 'b' && y1 <= clipValue && y2 > clipValue)) {
            new_vertices[j].x = clipValue;
            new_vertices[j++].y = y1 + slope * (clipValue - x1);
            continue;
        }

        if ((edge == 'l' && x1 < clipValue && x2 >= clipValue) ||
            (edge == 't' && y1 < clipValue && y2 >= clipValue) ||
            (edge == 'r' && x1 > clipValue && x2 <= clipValue) ||
            (edge == 'b' && y1 > clipValue && y2 <= clipValue)) {
            new_vertices[j].x = clipValue;
            new_vertices[j++].y = y1 + slope * (clipValue - x1);
            new_vertices[j].x = x2;
            new_vertices[j++].y = y2;
        }

        // No clipping needed for remaining vertices (early termination)
        break;
    }

    // Copy clipped vertices back and set remaining to (0, 0)
    for (int k = 0; k < j; k++) {
        vertices[k].x = new_vertices[k].x;
        vertices[k].y = new_vertices[k].y;
        new_vertices[k].x = new_vertices[k].y = 0;
    }

    // Set the remaining vertices to (0, 0)
    if (j < limit) {
        for (int k = j; k < limit; k++) {
            vertices[k].x = vertices[k].y = 0;
        }
    }

    return j; // Return the number of vertices after clipping
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"C:/TurboC3/BGI");

    // DRAW ORIGINAL POLYGON
    rectangle(60, 130, 250, 320);
    for (int i = 0; i < 16; i++)
        line(vertices[i].x, vertices[i].y, vertices[(i + 1) % MAX_VERTICES].x, vertices[(i + 1) % MAX_VERTICES].y);

    int result;

    result = clip(0, MAX_VERTICES, 'l', 60); // Left clip
    result = clip(0, result, 't', 130);      // Top clip
    result = clip(0, result, 'r', 250);      // Right clip
    result = clip(0, result, 'b', 320);      // Bottom clip

    // Draw the clipping window
    rectangle(60 + getmaxx() / 2, 130, 250 + getmaxx() / 2, 320);

    // Draw the clipped polygon
    for (int i = 0; i < result; i++)
        line(vertices[i].x + getmaxx() / 2, vertices[i].y, vertices[(i + 1) % result].x + getmaxx() / 2, vertices[(i + 1) % result].y);

    getch();
    closegraph();
    return 0;
}
