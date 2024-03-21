#include <stdio.h>
#include <math.h>
#include <graphics.h>

// Define a 3x3 matrix type
typedef struct
{
    float data[3][3];
} Matrix;

// Define a Point structure
typedef struct
{
    float x;
    float y;
} Point;

// Function to multiply two matrices
Matrix multiply(Matrix A, Matrix B)
{
    Matrix result;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result.data[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return result;
}

// Function to rotate a point using matrix transformation
Point Rotate_Point_Matrix(Point P, Point pivot, float angle)
{
    float radians = angle * 3.14 / 180.0;
    float cos_theta = cos(radians);
    float sin_theta = sin(radians);

    // Translation matrices
    Matrix translation_to = {{{1, 0, -pivot.x}, {0, 1, -pivot.y}, {0, 0, 1}}};
    Matrix translation_back = {{{1, 0, pivot.x}, {0, 1, pivot.y}, {0, 0, 1}}};

    // Rotation matrix
    Matrix rotation = {{{cos_theta, -sin_theta, 0}, {sin_theta, cos_theta, 0}, {0, 0, 1}}};

    // Combined transformation
    Matrix final = multiply(translation_back, multiply(rotation, translation_to));

    // Multiply transformation with point coordinates
    float new_x = P.x * final.data[0][0] + P.y * final.data[0][1] + final.data[0][2];
    float new_y = P.x * final.data[1][0] + P.y * final.data[1][1] + final.data[1][2];

    return (Point){new_x, new_y};
}

// Function to rotate a triangle using matrix transformation
void Rotate_Triangle_Matrix(Point *A, Point *B, Point *C, Point pivot, float angle)
{
    *A = Rotate_Point_Matrix(*A, pivot, angle);
    *B = Rotate_Point_Matrix(*B, pivot, angle);
    *C = Rotate_Point_Matrix(*C, pivot, angle);
}

// Function to draw a triangle
void drawTriangle(Point A, Point B, Point C, int xOffset, int yOffset)
{
    // Calculate the coordinates of the three vertices of the triangle with offsets
    Point A_offset = {A.x + xOffset, A.y + yOffset};
    Point B_offset = {B.x + xOffset, B.y + yOffset};
    Point C_offset = {C.x + xOffset, C.y + yOffset};

    // Draw the lines connecting the vertices to form the triangle
    line(A_offset.x, A_offset.y, B_offset.x, B_offset.y);
    line(B_offset.x, B_offset.y, C_offset.x, C_offset.y);
    line(C_offset.x, C_offset.y, A_offset.x, A_offset.y);
}

int main()
{
    // Initialize graphics environment
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Calculate center of the window
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    // Define initial triangle points
    Point A = {-150, 150};
    Point B = {-50, 150};
    Point C = {-100, 50};

    // Draw the original triangle
    drawTriangle(A, B, C, centerX, centerY);

    // Define pivot point for rotation
    Point pivot = {-100, 150};
    float rotation_angle = 45;

    // Rotate the triangle
    Rotate_Triangle_Matrix(&A, &B, &C, pivot, rotation_angle);

    // Draw the rotated triangle
    drawTriangle(A, B, C, centerX, centerY);

    // Close graphics environment
    getch();
    closegraph();
    return 0;
}