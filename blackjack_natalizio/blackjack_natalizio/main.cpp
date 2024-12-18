#define IMM2D_WIDTH 1920
#define IMM2D_HEIGHT 1080
#define IMM2D_SCALE 1

#define IMM2D_IMPLEMENTATION
#include "immediate2d.h"
#include <string>
using namespace std;
void carta(int x,int y);
int numero[7]; 
int colore = MakeColor(0, 49, 83);
int colortav = MakeColor(139, 69, 19);
int coloretav2 = MakeColor(0, 100, 0);


void run() {
        Clear(colore);
        UseAntiAliasing();
   
        DrawCircle(960, 0, 1030, colortav, Black);
        DrawCircle(960, 0, 880, coloretav2, Black);
        carta(IMM2D_WIDTH/2-180/2, IMM2D_HEIGHT/2+265/10);
        DrawRectangle(0, 1080-0, 100, 100, Black, White);
        
       

    

}

void carta(int x, int y)
{
    srand(time(NULL));
    int num = RandomInt(2,9);
    string lettera = "AJQK";
    string u;
    if (RandomInt(1,2)==1)
    {
        u = to_string(num);
    }
    else
    {
        u = lettera[RandomInt(0, 3)];
    }
    DrawRectangle(x, y, 180, 265, White, Red);
    DrawString(x,y, u.c_str(),"elvetica",30,Red,false);
    DrawString(x + 147, y + 224,u.c_str(), "elvetica", 30, Red, false);

}
