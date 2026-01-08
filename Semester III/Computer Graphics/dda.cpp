#include<stdio.h>
#include<iostream>
#include<limits.h>
#include <graphics.h>
#include<math.h>
#define R(x) (int)(x + 0.5) // Round off

// DDA Algorithm

void lineDDA(int x1, int y1, int x2, int y2, int color) {
	// Initialize x and y to the starting coordinates
	float x = x1;
	float y = y1;

	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps;

	// Determine the number of steps (the absolute maximum of dx or dy)
	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else {
		steps = abs(dy);
	}

	// Calculate the increments for x and y
	float x_inc = (float)dx / steps;
	float y_inc = (float)dy / steps;

	// Plot the starting point
	putpixel(R(x), R(y), color);

	// Loop for the calculated number of steps
	for (int i = 0; i < steps; i++) {
		x = x + x_inc;
		y = y + y_inc;

		// Plot the new rounded pixel
		putpixel(R(x), R(y), color);
	}

}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");

	// Draw lines
	lineDDA(0, 0, 639, 479, 2);  // Diagonal: Top-Left to Bottom-Right (Green)
	lineDDA(639, 0, 0, 479, 3);  // Diagonal: Top-Right to Bottom-Left (Cyan)
	lineDDA(320, 0, 320, 479, 4); // Vertical: Center (Red)
	lineDDA(0, 240, 639, 240, 5); // Horizontal: Center (Magenta)

	getch();
	closegraph();

	return 0;

}