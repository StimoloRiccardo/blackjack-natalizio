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
        DrawCircle(960, 0, 1009, colortav, Black);
        DrawCircle(960, 0, 894, colortav, Black);
        DrawCircle(960, 0, 880, coloretav2, Black); 
      
        DrawRectangle(xc - 7, yc - 7, 188+7, 273+7, Yellow, Yellow); 
        DrawRectangle(xc-4, yc-4, 188, 273, coloretav2, Yellow);
        DrawRectangle(IMM2D_WIDTH/2-195/2,40, 188 + 7, 273 + 7, Yellow, Yellow);
        DrawRectangle(IMM2D_WIDTH / 2 - 188/ 2, 40+4, 188 , 273, coloretav2, Yellow);
        DrawRectangle(xc - 4, yc - 4, 188, 273, coloretav2, Yellow);
        DrawRectangle(xc-4, yc-4, 188, 273, coloretav2, Yellow);
        carta(xc, yc);
        //carta(xc + 40, yc);
        
        dorsocarta(IMM2D_WIDTH - 400, 50);
        DrawCircle(IMM2D_WIDTH / 2 - 900 / 2, IMM2D_HEIGHT / 2 - 110+50,50,coloretav2,Yellow);
        DrawCircle(IMM2D_WIDTH / 2 + 900 / 2, IMM2D_HEIGHT / 2 - 110 + 50, 50, coloretav2, Yellow);
        DrawRectangle(IMM2D_WIDTH / 2 - 900 / 2, IMM2D_HEIGHT / 2 - 110, 900, 100, coloretav2, Yellow);
        DrawRectangle(IMM2D_WIDTH / 2 - 902 / 2, IMM2D_HEIGHT / 2 - 109, 902, 98, coloretav2, coloretav2);

        DrawString(IMM2D_WIDTH / 2 ,IMM2D_HEIGHT / 2-110+25,"2 A 1       ASSICURAZIONE       2 A 1 ","times new roman",42,Yellow,true);
        DrawString(IMM2D_WIDTH / 2,IMM2D_HEIGHT/2-173,"IL BANCO PAGA 3 A 2","TIMES NEW ROMAN",40,White,true);

        //tasti fish

        DrawCircle(IMM2D_WIDTH/2,952,65,colorefish,Black);
        DrawCircle(IMM2D_WIDTH / 2-138, 955-13, 55, colorefish, Black);
        DrawCircle(IMM2D_WIDTH / 2 + 138, 955 - 13, 55, colorefish, Black);
        DrawCircle(IMM2D_WIDTH / 2 - 257, 955 - 39, 55, colorefish, Black);
        DrawCircle(IMM2D_WIDTH / 2 + 257, 955 - 39, 55, colorefish, Black);


        DrawRectangle(0, 0, 350, 70, White, Black);
        DrawRectangle(0, 70, 350, 70, White, Black);
        DrawString(10, 90, "Puntata:", "elvetica", 30, Black, false);
        DrawString(10, 20, "Saldo:", "elvetica", 30, Black, false);
        
        string s;
        s = to_string(saldo);
        DrawString(150, 20, s.c_str(), "elvetica", 30, Black, false);
        string p;
        p = to_string(puntata);
        DrawString(190, 90, p.c_str(), "elvetica", 30, Black, false);
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2)-65 && MouseX() <= IMM2D_WIDTH / 2 + 65) {
                if (MouseY() >= 955-65 && MouseY() <= 955 + 65)
                {
                    puntata += 5000;
                    saldo -= 5000;
                     
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2) - 65 && MouseX() <= IMM2D_WIDTH / 2 + 65) {
                if (MouseY() >= 955 - 65 && MouseY() <= 955 + 65)
                {
                    puntata -= 5000;
<<<<<<< HEAD
                    saldo += 5000;
                    
=======
>>>>>>> origin/main
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 138) + 55) {
                if (MouseY() >= (955-11) - 55 && MouseY() <= (955-11) + 55)
                {
                    puntata += 1000;
                    saldo-= 1000; 
                    
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 138) + 55) {
                if (MouseY() >= (955 - 11) - 55 && MouseY() <= (955 - 11) + 55)
                {
                    puntata -= 1000;
<<<<<<< HEAD
                    saldo += 1000;
                    
=======
>>>>>>> origin/main
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 138) + 55) {
                if (MouseY() >= (955 - 11) - 55 && MouseY() <= (955 - 11) + 55)
                {
                    puntata += 500;
                    saldo -= 500;
                   
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 138) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 138) + 55) {
                if (MouseY() >= (955 - 11) - 55 && MouseY() <= (955 - 11) + 55)
                {
                    puntata -= 500;
<<<<<<< HEAD
                    saldo += 500;
                    

=======
>>>>>>> origin/main
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata += 100;
                    saldo -= 100;
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 - 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 - 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata -= 100;
<<<<<<< HEAD
                    saldo += 100;
                    
=======
>>>>>>> origin/main
                }
            }
        }
        if (LeftMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata += 50;
                    saldo -= 50;
                    
                }
            }
        }
        if (RightMousePressed())
        {
            if (MouseX() >= (IMM2D_WIDTH / 2 + 257) - 55 && MouseX() <= (IMM2D_WIDTH / 2 + 257) + 55) {
                if (MouseY() >= (955 - 39) - 55 && MouseY() <= (955 - 39) + 55)
                {
                    puntata -= 50;
<<<<<<< HEAD
                    saldo += 50;
=======
>>>>>>> origin/main
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
