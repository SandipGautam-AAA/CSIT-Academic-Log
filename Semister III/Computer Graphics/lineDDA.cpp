#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <cmath>
#include <windows.h>

void lineDDA(int x1, int y1, int x2, int y2, int col){
    int dX = x2 - x1;
    int dY = y2 - y1;
    int steps;
    float x = x1, y = y1;
    float Xinc, Yinc;

    steps = (abs(dX) > abs(dY)) ? abs(dX) : abs(dY);

    Xinc = (float)dX / steps;
    Yinc = (float)dY / steps;

    for(int k = 0; k <= steps; k++){
        putpixel(round(x), round(y), col);
        x += Xinc;
        y += Yinc;
    }
}

int main(){
    int gd = DETECT, gm;
    char path[] = "";   // Fix for C++ string warning
    initgraph(&gd, &gm, path);

    lineDDA(200,200,400,200,3);
    lineDDA(300,100,300,300,4);   
    lineDDA(200,100,400,300,2);   
    lineDDA(400,100,200,300,5);

    getch();
    closegraph();
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR args, int show){
    return main();
}