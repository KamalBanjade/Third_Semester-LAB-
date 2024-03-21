
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Define the maximum number of vertices in the polygon
#define MAX_VERTICES 16

// Define the clipping window coordinates
#define XMIN 60
#define YMIN 130
#define XMAX 250
#define YMAX 320
// Define the structure for storing coordinates of a vertex
typedef struct vertex {
  int x;
  int y;
} Vertex;

// Array to store the vertices of the polygon
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

// Temporary array used to store the new coordinates of the vertices after
// clipping
Vertex new_vertices[MAX_VERTICES] = {{0}};

// Function prototypes
int leftClip(int, int);
int topClip(int, int);
int rightClip(int, int);
int bottomClip(int, int);

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char*)"C:/TurboC3/BGI");
  int result, i;
  int midX = getmaxx() / 2;

  // DRAW ORIGINAL POLYGON
   outtextxy(100, 380, "Before Clipping");
  rectangle(XMIN, YMIN, XMAX, YMAX);
  for (i = 0; i < 16; i++)
    line(vertices[i].x, vertices[i].y, vertices[(i + 1) % MAX_VERTICES].x,
         vertices[(i + 1) % MAX_VERTICES].y);

  // Perform left, top, right, and bottom clipping successively
  result = leftClip(MAX_VERTICES, XMIN);
  result = topClip(result, YMIN);
  result = rightClip(result, XMAX);
  result = bottomClip(result, YMAX);

  // Draw the clipping window
  line(midX, 0, midX, getmaxy());
 outtextxy(420, 380, "After Clipping");
  rectangle(XMIN + midX, YMIN, XMAX + midX, YMAX);
  // Draw the clipped polygon
  for (i = 0; i < result; i++)
    line(vertices[i].x + midX, vertices[i].y,
         vertices[(i + 1) % result].x + midX, vertices[(i + 1) % result].y);

  getch();
  closegraph();
  return 0;
}

// Function to clip against the left edge of the clipping window
int leftClip(int limit, int xmin) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (x1 < xmin && x2 < xmin) continue;
    // Check if both endpoints are inside the clipping window
    if (x1 >= xmin && x2 >= xmin) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (x1 >= xmin && x2 < xmin) {
      new_vertices[j].x = xmin;
      new_vertices[j++].y = y1 + slope * (xmin - x1);
      continue;
    }
    if (x1 < xmin && x2 >= xmin) {
      new_vertices[j].x = xmin;
      new_vertices[j++].y = y1 + slope * (xmin - x1);
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}

// Function to clip against the top edge of the clipping window
int topClip(int limit, int ymin) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (y1 < ymin && y2 < ymin) continue;
    // Check if both endpoints are inside the clipping window
    if (y1 >= ymin && y2 >= ymin) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (y1 >= ymin && y2 < ymin) {
      new_vertices[j].x = x1 + (ymin - y1) / slope;
      new_vertices[j++].y = ymin;
      continue;
    }
    if (y1 < ymin && y2 >= ymin) {
      new_vertices[j].x = x1 + (ymin - y1) / slope;
      new_vertices[j++].y = ymin;
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}

// Function to clip against the right edge of the clipping window
int rightClip(int limit, int xmax) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (x1 > xmax && x2 > xmax) continue;
    // Check if both endpoints are inside the clipping window
    if (x1 <= xmax && x2 <= xmax) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (x1 <= xmax && x2 > xmax) {
      new_vertices[j].x = xmax;
      new_vertices[j++].y = y1 + slope * (xmax - x1);
      continue;
    }
    if (x1 > xmax && x2 <= xmax) {
      new_vertices[j].x = xmax;
      new_vertices[j++].y = y1 + slope * (xmax - x1);
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}

// Function to clip against the bottom edge of the clipping window
int bottomClip(int limit, int ymax) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (y1 > ymax && y2 > ymax) continue;
    // Check if both endpoints are inside the clipping window
    if (y1 <= ymax && y2 <= ymax) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (y1 <= ymax && y2 > ymax) {
      new_vertices[j].x = x1 + (ymax - y1) / slope;
      new_vertices[j++].y = ymax;
      continue;
    }
    if (y1 > ymax && y2 <= ymax) {
      new_vertices[j].x = x1 + (ymax - y1) / slope;
      new_vertices[j++].y = ymax;
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}