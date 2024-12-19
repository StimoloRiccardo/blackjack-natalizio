#define IMM2D_WIDTH 1920
#define IMM2D_HEIGHT 1080
#define IMM2D_SCALE 1

#define IMM2D_IMPLEMENTATION
#include "immediate2d.h"
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void carta(int x,int y);
void dorsocarta(int x, int y);


int numero[7];
int colorefish = MakeColor(108,60,12); 
int colore = MakeColor(0, 49, 83);
int colortav = MakeColor(139, 69, 19);
int coloretav2 = MakeColor(0, 100, 0);
int xc = IMM2D_WIDTH / 2 - 180 / 2;
int yc = IMM2D_HEIGHT / 2 + 265 / 10;
int wstart = 500;
int hstart = 300;
int start = 0;
int xst = IMM2D_WIDTH / 2 - 300 / 2, yst = IMM2D_HEIGHT / 2 - 125 / 2;
int saldo = 500;
int puntata = 0;
void run() { 
        Clear(colore); 
        UseDoubleBuffering(true);
        
        UseAntiAliasing(); 
        while (start==0) {
           DrawRectangle(0, 0, IMM2D_WIDTH, IMM2D_HEIGHT,colore, Black);

           DrawString(IMM2D_WIDTH/2,IMM2D_HEIGHT/2-400,"Blackjack","segoe script",150,White,true);
           DrawRectangle(xst,yst,300,125,colore,White);
           DrawString(xst+150, yst+10, "START", "segoe script", 50, White, true);
           if (LeftMousePressed())
           {
              if(MouseX()>=xst && MouseX()<=xst+300){
                  if (MouseY() >= yst && MouseY() <= yst + 125)
                  {
                      start = 1;
                  }               
              }
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
        dorsocarta(IMM2D_WIDTH - 390, 80);
        DrawRectangle(IMM2D_WIDTH / 2 - 1000 / 2, IMM2D_HEIGHT / 2 - 170, 1000, 150, coloretav2, Yellow);
        DrawCircle(IMM2D_WIDTH/2,955,65,colorefish,Black);
        DrawCircle(IMM2D_WIDTH / 2-138, 955-11, 55, colorefish, Black);
        DrawCircle(IMM2D_WIDTH / 2 + 138, 955 - 11, 55, colorefish, Black);
        DrawCircle(IMM2D_WIDTH / 2 - 257, 955 - 39, 55, colorefish, Black);
        DrawCircle(IMM2D_WIDTH / 2 + 257, 955 - 39, 55, colorefish, Black);

        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2)-65 && MouseX() <= IMM2D_WIDTH / 2 + 65) {
                if (MouseY() >= 955-65 && MouseY() <= 955 + 65)
                {
                    puntata += 5000;
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2) - 65 && MouseX() <= IMM2D_WIDTH / 2 + 65) {
                if (MouseY() >= 955 - 65 && MouseY() <= 955 + 65)
                {
                    puntata -= 5000;
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 138) + 55) {
                if (MouseY() >= (955-11) - 55 && MouseY() <= (955-11) + 55)
                {
                    puntata += 1000;
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 138) + 55) {
                if (MouseY() >= (955 - 11) - 55 && MouseY() <= (955 - 11) + 55)
                {
                    puntata -= 1000;
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 138) + 55) {
                if (MouseY() >= (955 - 11) - 55 && MouseY() <= (955 - 11) + 55)
                {
                    puntata += 500;
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 138) + 55) {
                if (MouseY() >= (955 - 11) - 55 && MouseY() <= (955 - 11) + 55)
                {
                    puntata -= 500;
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata += 100;
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata -= 100;
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata += 50;
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata -= 50;
                }
            }
        }

        string p = to_string(puntata);
        DrawString(200, 90, p.c_str(), "elvetica", 30, Black, false);
                
        Present(); 
        //start
         


          

       

    

}

void carta(int x, int y)
{
    srand(time(NULL));
    int num = RandomInt(2,9);
    int caso = rand()%2+1;
    string lettera = "AJQK";
    string u;
    if (caso==1)
    {
        u = lettera[RandomInt(0, 3)];
    }
    else if(caso==2)
    {
        u = to_string(num);
    }
    DrawRectangle(x, y, 180, 265, White, Red);
    DrawString(x-2,y-2, u.c_str(),"elvetica",27,Red,false);
    DrawString(x + 147, y + 224,u.c_str(), "elvetica", 27, Red, false);
    DrawRectangle(x+29,y+30,123,210,White,Red);

}
void dorsocarta(int x, int y)
{
    DrawRectangle(x, y, 180, 265, White, Black);
    DrawRectangle(x + 14, y + 15, 150, 237, Red, Red);
}
