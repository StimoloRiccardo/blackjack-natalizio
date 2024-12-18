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
int xc = IMM2D_WIDTH / 2 - 180 / 2;
int yc = IMM2D_HEIGHT / 2 + 265 / 10;
int wstart = 500;
int hstart = 300;
int start = 0;
int xst = IMM2D_WIDTH / 2 - 300 / 2, yst = IMM2D_HEIGHT / 2 - 125 / 2;
int saldo = 500,puntata=5;
void run() { 
        Clear(colore); 
        UseDoubleBuffering(true);
        
        UseAntiAliasing(); 
        while (start==0) {
           DrawRectangle(0, 0, IMM2D_WIDTH, IMM2D_HEIGHT,colore, Black);

           DrawString(IMM2D_WIDTH/2,IMM2D_HEIGHT/2-400,"Blackjack","segoe script",150,White,true);
           DrawRectangle(xst,yst,300,125,colore,White);
           DrawString(xst+150, yst+10, "START", "segoe script", 50, White, true);
           if (LeftMousePressed())/*fare comando per pessione pulsante*/
           {
               start = 1;
           }
           Present();
        }
        DrawCircle(960, 0, 1030, colortav, Black);
        DrawCircle(960, 0, 880, coloretav2, Black);
        carta(xc, yc);
        carta(xc + 40, yc);
        DrawRectangle(0, 0, 350, 70, White, Black);
        DrawRectangle(0, 70, 350, 70, White, Black);
        DrawString(10, 90, "Puntata:", "elvetica", 30, Black, false);
        DrawString(10, 20, "Saldo:", "elvetica", 30, Black, false);
        string s = to_string(saldo); 
        DrawString(150,20,s.c_str(), "elvetica", 30, Black, false);
        Present();
        //start
         


          

       

    

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
    DrawString(x,y, u.c_str(),"elvetica",28,Red,false);
    DrawString(x + 147, y + 224,u.c_str(), "elvetica", 28, Red, false);
    DrawRectangle(x+29,y+30,123,210,White,Red);

}
