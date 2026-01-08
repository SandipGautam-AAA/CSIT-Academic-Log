#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#define R(x) (int)(x + 0.5) // Round off

// Bresenham Line Algorithm
void lineBresenham(int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1; // Step for x
    int sy = (y1 < y2) ? 1 : -1; // Step for y

    int err = dx - dy;
    int e2;

    while (true) {
        putpixel(x1, y1, color); // Plot current pixel

        if (x1 == x2 && y1 == y2) break; // End condition

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw lines using Bresenham
    lineBresenham(0, 0, 639, 479, 2);   // Diagonal: Top-Left to Bottom-Right (Green)
    lineBresenham(639, 0, 0, 479, 3);   // Diagonal: Top-Right to Bottom-Left (Cyan)
    lineBresenham(320, 0, 320, 479, 4); // Vertical: Center (Red)
    lineBresenham(0, 240, 639, 240, 5); // Horizontal: Center (Magenta)

    getch();
    closegraph();
    return 0;
}
