#define IMM2D_WIDTH 1920
#define IMM2D_HEIGHT 1080
#define IMM2D_SCALE 1

#define IMM2D_IMPLEMENTATION
#include "immediate2d.h"
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;
void carta(int x,int y);
int colore = MakeColor(0, 49, 83);
int colortav = MakeColor(139, 69, 19);
int coloretav2 = MakeColor(0, 100, 0);


void run() {
        Clear(colore);
        UseAntiAliasing();
   
        DrawCircle(960, 0, 1030, colortav, colortav);
        DrawCircle(960, 0, 880, coloretav2, coloretav2);
        carta(IMM2D_WIDTH/2-180/2, IMM2D_HEIGHT/2+265/10);
        DrawRectangle(0, 1080-150, 100, 100, Black, White);
        
       

    

}

void carta(int x, int y)
{
    srand(time(NULL));
    int num = rand() % 9 + 2;
    string u = to_string(num);
    DrawRectangle(x, y, 180, 265, White, Red);
    DrawString(x,y, u.c_str(),"elvetica",50,Red,false);
    DrawString(x + 123, y + 195,u.c_str(), "elvetica", 50, Red, false);

}
