#define IMM2D_WIDTH 1920
#define IMM2D_HEIGHT 1080
#define IMM2D_SCALE 1

#define IMM2D_IMPLEMENTATION
#include "immediate2d.h"
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int carta(int xa, int ya, Image dorso,int& cont);  
bool animazione[51]; 
bool isInside(int x, int y, int xStart, int yStart, int xEnd, int yEnd);
void mischiaCarte(Image carte[], int valori[]);
bool inizio = false;

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
int xa = IMM2D_WIDTH - 450;
int ya = yc - 508;
int xan = xa;
int cont = 0;
int nc = 4;

int nanim = 0;
bool an = false;
int banco = 0;
int giocatore = 0;
void run() { 
    Image carte[52]; 
    Image fish[5];
    Image fish2[5];
    Image dorso = LoadImage("retrop.png");
    Image scarta[2];
    Image x2 = LoadImage("x2.png");
    Image stai = LoadImage("stai.png");
    scarta[0] = LoadImage("carta0.png");
    scarta[1] = LoadImage("carta0_1.png.png"); 

    int valori[52]{11,2,3,4,5,6,7,8,9,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10};
    
    carte[0] = LoadImage("Acuori.png");
    carte[1] = LoadImage("2cuori.png");
    carte[2] = LoadImage("3cuori.png");
    carte[3] = LoadImage("4cuori.png");
    carte[4] = LoadImage("5cuori.png");
    carte[5] = LoadImage("6cuori.png");
    carte[6] = LoadImage("7cuori.png");
    carte[7] = LoadImage("8cuori.png");
    carte[8] = LoadImage("9cuori.png");
    carte[9] = LoadImage("10cuori.png");
    carte[10] = LoadImage("Jcuori.png");
    carte[11] = LoadImage("Qcuori.png");
    carte[12] = LoadImage("Kcuori.png");
    carte[13] = LoadImage("Aquadri.png");
    carte[14] = LoadImage("2quadri.png");
    carte[15] = LoadImage("3quadri.png");
    carte[16] = LoadImage("4quadri.png");
    carte[17] = LoadImage("5quadri.png");
    carte[18] = LoadImage("6quadri.png");
    carte[19] = LoadImage("7quadri.png");
    carte[20] = LoadImage("8quadri.png");
    carte[21] = LoadImage("9quadri.png");
    carte[22] = LoadImage("10quadri.png");
    carte[23] = LoadImage("Jquadri.png");
    carte[24] = LoadImage("Qquadri.png");
    carte[25] = LoadImage("Kquadri.png");
    carte[26] = LoadImage("Afiori.png");
    carte[27] = LoadImage("2fiori.png");
    carte[28] = LoadImage("3fiori.png");
    carte[29] = LoadImage("4fiori.png");
    carte[30] = LoadImage("5fiori.png");
    carte[31] = LoadImage("6fiori.png");
    carte[32] = LoadImage("7fiori.png");
    carte[33] = LoadImage("8fiori.png");
    carte[34] = LoadImage("9fiori.png");
    carte[35] = LoadImage("10fiori.png");
    carte[36] = LoadImage("Jfiori.png");
    carte[37] = LoadImage("Qfiori.png");
    carte[38] = LoadImage("Kfiori.png");
    carte[39] = LoadImage("Apicche.png");
    carte[40] = LoadImage("2picche.png");
    carte[41] = LoadImage("3picche.png");
    carte[42] = LoadImage("4picche.png");
    carte[43] = LoadImage("5picche.png");
    carte[44] = LoadImage("6picche.png");
    carte[45] = LoadImage("7picche.png");
    carte[46] = LoadImage("8picche.png");
    carte[47] = LoadImage("9picche.png");
    carte[48] = LoadImage("10picche.png");
    carte[49] = LoadImage("Jpicche.png");
    carte[50] = LoadImage("Qpicche.png");
    carte[51] = LoadImage("Kpicche.png");


    fish[0] = LoadImage("fish50.png");
    fish[1] = LoadImage("fish100p.png");
    fish[2] = LoadImage("fish_500.png");
    fish[3] = LoadImage("fish_5000.png");
    fish[4] = LoadImage("fish2.png");

    fish2[4] = LoadImage("fish2.1.png");
    fish2[0] = LoadImage("fish50.1.png");
    fish2[1] = LoadImage("fish_100.png");
    fish2[2]= LoadImage("fish_500.1.png");
    fish2[3] = LoadImage("fish_5000.1.png");




    

        Clear(colore); 
        UseDoubleBuffering(true);
        
        UseAntiAliasing(); 
        while (start==1) {
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
           Wait(2);
        }
        Wait(2); 
        mischiaCarte(carte, valori);

        DrawCircle(IMM2D_WIDTH / 2 - 900 / 2, IMM2D_HEIGHT / 2 - 110+50,50,coloretav2,Yellow);
        
        DrawCircle(IMM2D_WIDTH / 2 + 900 / 2, IMM2D_HEIGHT / 2 - 110 + 50, 50, coloretav2, Yellow);
        DrawRectangle(IMM2D_WIDTH / 2 - 900 / 2, IMM2D_HEIGHT / 2 - 110, 900, 100, coloretav2, Yellow);
        DrawRectangle(IMM2D_WIDTH / 2 - 902 / 2, IMM2D_HEIGHT / 2 - 109, 902, 98, coloretav2, coloretav2);

        DrawString(IMM2D_WIDTH / 2 ,IMM2D_HEIGHT / 2-110+25,"2 A 1       ASSICURAZIONE       2 A 1 ","times new roman",37,Yellow,true);
        DrawString(IMM2D_WIDTH / 2,IMM2D_HEIGHT/2-173,"IL BANCO PAGA 3 A 2","TIMES NEW ROMAN",40,White,true);

        //tasti fish
        bool statoDelMouseSinistro = false; //false=rilasciato
        bool statoDelMouseDestro = false; //false=rilasciato

        while (true) {
            UseDoubleBuffering(true);
            DrawCircle(960, 0, 1030, colortav, Black);
            DrawCircle(960, 0, 1009, colortav, Black);
            DrawCircle(960, 0, 894, colortav, Black);
            DrawCircle(960, 0, 880, coloretav2, Black);

            DrawCircle(IMM2D_WIDTH / 2 - 900 / 2, IMM2D_HEIGHT / 2 - 110 + 50, 50, coloretav2, Yellow);

            DrawCircle(IMM2D_WIDTH / 2 + 900 / 2, IMM2D_HEIGHT / 2 - 110 + 50, 50, coloretav2, Yellow);
            DrawRectangle(IMM2D_WIDTH / 2 - 900 / 2, IMM2D_HEIGHT / 2 - 110, 900, 100, coloretav2, Yellow);
            DrawRectangle(IMM2D_WIDTH / 2 - 902 / 2, IMM2D_HEIGHT / 2 - 109, 902, 98, coloretav2, coloretav2);

            DrawString(IMM2D_WIDTH / 2, IMM2D_HEIGHT / 2 - 110 + 25, "2 A 1       ASSICURAZIONE       2 A 1 ", "times new roman", 37, Yellow, true);
            DrawString(IMM2D_WIDTH / 2, IMM2D_HEIGHT / 2 - 173, "IL BANCO PAGA 3 A 2", "TIMES NEW ROMAN", 40, White, true);

            /*spazio giocatore*/
            DrawRectangle(xc - 6, yc - 5, 188 + 5, 273 - 7, Yellow, Yellow);
            DrawRectangle(xc - 4, yc - 3, 184 + 5, 286 - 24, coloretav2, Yellow);
            /* mazziere spazio*/
            DrawRectangle(xc + 2, yc - 513, 188 + 5, 273 - 7, Yellow, Yellow);
            DrawRectangle(xc + 4, yc - 511, 184 + 5, 286 - 24, coloretav2, Yellow);

            DrawRectangle(50, 20, 350, 70, colortav, Black);
            DrawCircle(50, 55, 35, colortav, Black);
            DrawCircle(50, 55, 25, colore, Black);
            DrawCircle(400, 55, 35, colortav, Black);
            DrawCircle(400, 55, 25, colore, Black);
            DrawRectangle(50, 21, 352, 68, colortav, colortav);
            DrawRectangle(50, 30, 352, 50, colortav, Black);
            DrawRectangle(50, 31, 352, 48, colore, colore);


            DrawRectangle(50, 110, 350, 70, colortav, Black);
            DrawCircle(50, 145, 35, colortav, Black);
            DrawCircle(50, 145, 25, colore, Black);
            DrawCircle(400, 145, 35, colortav, Black);
            DrawCircle(400, 145, 25, colore, Black);
            DrawRectangle(50, 111, 352, 68, colortav, colortav);
            DrawRectangle(50, 120, 352, 50, colortav, Black);
            DrawRectangle(50, 121, 352, 48, colore, colore);
            DrawString(50, 123, "Puntata:", "times new roman", 30, White, false);
            DrawString(50, 32, "Saldo:", "times new roman", 30, White, false);

            /*centro*/
           
            
            

            DrawRectangle(50, 20, 350, 70, colortav, Black);
            DrawCircle(50, 55, 35, colortav, Black);
            DrawCircle(50, 55, 25, colore, Black);
            DrawCircle(400, 55, 35, colortav, Black);
            DrawCircle(400, 55, 25, colore, Black);
            DrawRectangle(50, 21, 352, 68, colortav, colortav);
            DrawRectangle(50, 30, 352, 50, colortav, Black);
            DrawRectangle(50, 31, 352, 48, colore, colore);


            DrawRectangle(50, 110, 350, 70, colortav, Black);
            DrawCircle(50, 145, 35, colortav, Black);
            DrawCircle(50, 145, 25, colore, Black);
            DrawCircle(400, 145, 35, colortav, Black);
            DrawCircle(400, 145, 25, colore, Black);
            DrawRectangle(50, 111, 352, 68, colortav, colortav);
            DrawRectangle(50, 120, 352, 50, colortav, Black);
            DrawRectangle(50, 121, 352, 48, colore, colore);
            DrawString(50, 123, "Puntata:", "times new roman", 30, White, false);
            DrawString(50, 32, "Saldo:", "times new roman", 30, White, false);


            //DrawImage(xc + 8, yc - 508, carte[0]);
            //DrawImage(xc, yc, carte[1]);
            //DrawImage(xc + 40, yc, carte[2]);
            //DrawImage(xc + 40, yc - 508, carte[3]);
            /*/carta(xc + 40, yc-518);*/

             /*dorsocarta(IMM2D_WIDTH - 400, 50);*/
            DrawImage(IMM2D_WIDTH - 450, yc - 508, dorso);
            
              
            
            
            string s;
            s = to_string(saldo);
            DrawString(180, 32, s.c_str(), "times new roman", 30, White, false);
            string p;
            p = to_string(puntata);           
            DrawString(220, 123, p.c_str(), "times new roman", 30, White, false);
            


            DrawCircle(IMM2D_WIDTH / 2, 952, 65, colorefish, Black);
            /*if (saldo < 10000)
            {
                DrawImage(IMM2D_WIDTH / 2 - 66, 887, fish2[4]);
            }
            else
            {
                DrawImage(IMM2D_WIDTH / 2 - 66, 887, fish[4]);
            }*/
            /*sx*/
            DrawCircle(IMM2D_WIDTH / 2 - 257, 955 - 39, 55, colorefish, Black);
            /*if (saldo < 50)
            {
                DrawImage(IMM2D_WIDTH / 2 - 311, 955 - 94, fish2[0]);
            }
            else
            {
                DrawImage(IMM2D_WIDTH / 2 - 311, 955 - 94, fish[0]);
            }*/
            /*centrosx*/
            DrawCircle(IMM2D_WIDTH / 2 - 138, 955 - 13, 55, colorefish, Black);
            /*if (saldo < 100)
            {
                DrawImage(IMM2D_WIDTH / 2 - 192, 955 - 68, fish2[1]);
            }
            else
            {
                DrawImage(IMM2D_WIDTH / 2 - 192, 955 - 68, fish[1]);
            }*/
            //centrodx
            DrawCircle(IMM2D_WIDTH / 2 + 138, 955 - 13, 55, colorefish, Black);
            /*if (saldo < 5000)
            {
                DrawImage(IMM2D_WIDTH / 2 + 84, 955 - 68, fish2[3]);
            }
            else
            {
                DrawImage(IMM2D_WIDTH / 2 + 84, 955 - 68, fish[3]);
            }*/

            DrawCircle(IMM2D_WIDTH / 2 + 257, 955 - 39, 55, colorefish, Black);

            //if (saldo < 500)
            //{
            //    DrawImage(IMM2D_WIDTH / 2 + 203, 955 - 94, fish2[2]);
            //}
            //else
            //{
            //    DrawImage(IMM2D_WIDTH / 2 + 203, 955 - 94, fish[2]);
            //}
            if ((puntata > 0) && (inizio == true))
            {
                DrawImage(IMM2D_WIDTH / 2 - 66, 887, fish2[4]);
                DrawImage(IMM2D_WIDTH / 2 - 311, 955 - 94, fish2[0]); 
                DrawImage(IMM2D_WIDTH / 2 - 192, 955 - 68, fish2[1]); 
                DrawImage(IMM2D_WIDTH / 2 + 84, 955 - 68, fish2[3]);
                DrawImage(IMM2D_WIDTH / 2 + 203, 955 - 94, fish2[2]);
                if (animazione[0] == false)
                {
                    ya -= 30;
                    carta(xa, ya, dorso, cont);
                    if (cont == 15)
                    {
                        animazione[0] = true;
                        ya = 160;
                        cont = 0;
                        nanim++;
                        giocatore += valori[0]; 
                    }
                }
                else
                {
                    DrawImage(xc, yc, carte[0]);
                }


                if (animazione[1] == false && animazione[0] == true)
                {
                    ya -= 30;
                    carta(xa, ya, dorso, cont);
                    if (cont == 15)
                    {
                        animazione[1] = true;
                        ya = 160;
                        cont = 0;
                        nanim++;
                        giocatore += valori[1];
                    }
                }
                else if (animazione[1] == true)
                {
                    DrawImage(xc + 30, yc, carte[1]);
                }

                if (animazione[2] == false && animazione[1] == true && animazione[0] == true)
                {
                    ya -= 30;
                    carta(xa, ya, dorso, cont);
                    if (cont == 15)
                    {
                        animazione[2] = true;
                        ya = 160;
                        cont = 0;
                        nanim++;
                        banco += valori[2];
                    }
                }
                else if (animazione[2] == true)
                {
                    DrawImage(xc + 8, yc - 508, carte[2]);
                }

                if (animazione[3] == false && animazione[2] == true && animazione[1] == true && animazione[0] == true)
                {
                    ya -= 30;
                    carta(xa, ya, dorso, cont);
                    if (cont == 15)
                    {
                        animazione[3] = true;
                        nanim++;
                        ya = 160;
                        cont = 0;
                        banco += valori[3];

                    }
                }
                else if (animazione[3] == true)
                {
                    DrawImage(xc + 40, yc - 508, dorso);
                }

               
                    
                if (giocatore < 21)
                {
                    if (LeftMousePressed())
                    {
                        int xm = MouseX();
                        int ym = MouseY();

                        if (isInside(xm, ym, IMM2D_WIDTH - 423, 325, (IMM2D_WIDTH - 423) + 113, 325 + 38)) {
                            if (statoDelMouseSinistro == false)
                            {
                                an = true;

                            }
                        }
                    }

                    if (an == true)
                    {
                        ya -= 30;
                        carta(xa, ya, dorso, cont);
                        if (cont == 15)
                        {
                            animazione[nanim] = true;
                            nanim++;

                            an = false;
                            ya = 160;
                            cont = 0;
                            giocatore += valori[nc];
                            nc++;
                        }
                    }
                    if (saldo>=puntata*2)
                    {
                        DrawImage(IMM2D_WIDTH - 423, 375, x2);
                        if (LeftMousePressed())
                        {
                            int xm = MouseX();
                            int ym = MouseY();

                            if (isInside(xm, ym, IMM2D_WIDTH - 423, 375, (IMM2D_WIDTH - 423) + 113, 375 + 38)) {
                                if (statoDelMouseSinistro == false)
                                {
                                    puntata *= 2;
                                    saldo -= puntata * 2;
                                    an = true;

                                }
                            }
                        }
                       
                    }
                    DrawImage(IMM2D_WIDTH - 423, 325, scarta[0]); 
                    DrawImage(IMM2D_WIDTH - 423, 425, stai);

                } 
               
                    if (animazione[4] == true) DrawImage(xc + 60, yc, carte[5]);
                    if (animazione[5] == true) DrawImage(xc + 90, yc, carte[6]);
                    if (animazione[6] == true) DrawImage(xc + 120, yc, carte[7]);
                    if (animazione[7] == true) DrawImage(xc + 150, yc, carte[8]);
                    if (animazione[8] == true) DrawImage(xc + 180, yc, carte[9]);
                    if (animazione[9] == true) DrawImage(xc + 210, yc, carte[10]);
                    if (animazione[10] == true) DrawImage(xc + 240, yc, carte[11]);
                    if (animazione[11] == true) DrawImage(xc + 270, yc, carte[12]);
                    if (animazione[12] == true) DrawImage(xc + 300, yc, carte[13]);
                    if (animazione[13] == true) DrawImage(xc + 330, yc, carte[14]);
                    if (animazione[14] == true) DrawImage(xc + 360, yc, carte[15]);
                    if (animazione[15] == true) DrawImage(xc + 390, yc, carte[16]);
                    if (animazione[16] == true) DrawImage(xc + 420, yc, carte[17]);
                    if (animazione[17] == true) DrawImage(xc + 450, yc, carte[18]);
                    if (animazione[18] == true) DrawImage(xc + 480, yc, carte[19]);
                    if (animazione[19] == true) DrawImage(xc + 510, yc, carte[20]);
                    if (animazione[20] == true) DrawImage(xc + 540, yc, carte[21]);
                    if (animazione[21] == true) DrawImage(xc + 570, yc, carte[22]);
                    if (animazione[22] == true) DrawImage(xc + 600, yc, carte[23]);
                    if (animazione[23] == true) DrawImage(xc + 630, yc, carte[24]);
                    if (animazione[24] == true) DrawImage(xc + 660, yc, carte[25]);
                    if (animazione[25] == true) DrawImage(xc + 690, yc, carte[26]);
                    if (animazione[26] == true) DrawImage(xc + 720, yc, carte[27]);
                    if (animazione[27] == true) DrawImage(xc + 750, yc, carte[28]);
                    if (animazione[28] == true) DrawImage(xc + 780, yc, carte[29]);
                    if (animazione[29] == true) DrawImage(xc + 810, yc, carte[30]);
                    if (animazione[30] == true) DrawImage(xc + 840, yc, carte[31]);
                    if (animazione[31] == true) DrawImage(xc + 870, yc, carte[32]);
                    if (animazione[32] == true) DrawImage(xc + 900, yc, carte[33]);
                    if (animazione[33] == true) DrawImage(xc + 930, yc, carte[34]);
                    if (animazione[34] == true) DrawImage(xc + 960, yc, carte[35]);
                    if (animazione[35] == true) DrawImage(xc + 990, yc, carte[36]);
                    if (animazione[36] == true) DrawImage(xc + 1020, yc, carte[37]);
                    if (animazione[37] == true) DrawImage(xc + 1050, yc, carte[38]);
                    if (animazione[38] == true) DrawImage(xc + 1080, yc, carte[39]);
                    if (animazione[39] == true) DrawImage(xc + 1110, yc, carte[40]);
                    if (animazione[40] == true) DrawImage(xc + 1140, yc, carte[41]);
                    if (animazione[41] == true) DrawImage(xc + 1170, yc, carte[42]);
                    if (animazione[42] == true) DrawImage(xc + 1200, yc, carte[43]);
                    if (animazione[43] == true) DrawImage(xc + 1230, yc, carte[44]);
                    if (animazione[44] == true) DrawImage(xc + 1260, yc, carte[45]);
                    if (animazione[45] == true) DrawImage(xc + 1290, yc, carte[46]);
                    if (animazione[46] == true) DrawImage(xc + 1320, yc, carte[47]);
                    if (animazione[47] == true) DrawImage(xc + 1350, yc, carte[48]);
                    if (animazione[48] == true) DrawImage(xc + 1380, yc, carte[49]);
                    if (animazione[49] == true) DrawImage(xc + 1410, yc, carte[50]);
                    if (animazione[50] == true) DrawImage(xc + 1440, yc, carte[51]);
                    
                    
                
            }
            else
            {
                if (saldo < 10000)
                {
                    DrawImage(IMM2D_WIDTH / 2 - 66, 887, fish2[4]);
                }
                else
                {
                    DrawImage(IMM2D_WIDTH / 2 - 66, 887, fish[4]);
                }

                if (saldo < 50)
                {
                    DrawImage(IMM2D_WIDTH / 2 - 311, 955 - 94, fish2[0]);
                }
                else
                {
                    DrawImage(IMM2D_WIDTH / 2 - 311, 955 - 94, fish[0]);
                }

                if (saldo < 100)
                {
                    DrawImage(IMM2D_WIDTH / 2 - 192, 955 - 68, fish2[1]);
                }
                else
                {
                    DrawImage(IMM2D_WIDTH / 2 - 192, 955 - 68, fish[1]);
                }

                if (saldo < 5000)
                {
                    DrawImage(IMM2D_WIDTH / 2 + 84, 955 - 68, fish2[3]);
                }
                else
                {
                    DrawImage(IMM2D_WIDTH / 2 + 84, 955 - 68, fish[3]);
                }
                if (saldo < 500)
                {
                    DrawImage(IMM2D_WIDTH / 2 + 203, 955 - 94, fish2[2]);
                }
                else
                {
                    DrawImage(IMM2D_WIDTH / 2 + 203, 955 - 94, fish[2]);
                }
                if (LeftMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2) - 65, 952 - 65, (IMM2D_WIDTH / 2) + 65, 952 + 65)) {
                        if (statoDelMouseSinistro == false)
                        {
                            if (saldo >= 10000)
                            {
                                puntata += 10000;
                                saldo -= 10000;
                            }

                        }
                    }
                }
                if (RightMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2) - 65, 952 - 65, (IMM2D_WIDTH / 2) + 65, 952 + 65)) {
                        if (statoDelMouseDestro == false)
                        {
                            if (puntata >= 10000)
                            {
                                puntata -= 10000;
                                saldo += 10000;
                            }

                        }
                    }
                }
                if (LeftMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 - 138) - 65, 952 - 65, (IMM2D_WIDTH / 2 - 138) + 65, 952 + 65)) {
                        if (statoDelMouseSinistro == false)
                        {
                            if (saldo >= 100)
                            {
                                puntata += 100;
                                saldo -= 100;
                            }
                        }
                    }
                }
                if (RightMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 - 138) - 65, 952 - 65, (IMM2D_WIDTH / 2 - 138) + 65, 952 + 65)) {
                        if (statoDelMouseDestro == false)
                        {
                            if (puntata >= 100)
                            {
                                puntata -= 100;
                                saldo += 100;
                            }
                        }
                    }
                }
                if (LeftMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 + 138) - 65, 952 - 65, (IMM2D_WIDTH / 2 + 138) + 65, 952 + 65)) {
                        if (statoDelMouseSinistro == false)
                        {
                            if (saldo >= 5000)
                            {
                                puntata += 5000;
                                saldo -= 5000;
                            }
                        }
                    }
                }
                if (RightMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 + 138) - 65, 952 - 65, (IMM2D_WIDTH / 2 + 138) + 65, 952 + 65)) {
                        if (statoDelMouseDestro == false)
                        {
                            if (puntata >= 5000)
                            {
                                puntata -= 5000;
                                saldo += 5000;
                            }
                        }
                    }
                }
                if (LeftMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 - 257) - 65, 952 - 65, (IMM2D_WIDTH / 2 - 257) + 65, 952 + 65)) {
                        if (statoDelMouseSinistro == false)
                        {
                            if (saldo >= 50)
                            {
                                puntata += 50;
                                saldo -= 50;
                            }
                        }
                    }
                }
                if (RightMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 - 257) - 65, 952 - 65, (IMM2D_WIDTH / 2 - 257) + 65, 952 + 65)) {
                        if (statoDelMouseDestro == false)
                        {
                            if (puntata >= 50)
                            {
                                puntata -= 50;
                                saldo += 50;
                            }
                        }
                    }
                }
                if (LeftMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 + 257) - 65, 952 - 65, (IMM2D_WIDTH / 2 + 257) + 65, 952 + 65)) {
                        if (statoDelMouseSinistro == false)
                        {
                            if (saldo >= 500)
                            {
                                puntata += 500;
                                saldo -= 500;
                            }
                        }
                    }
                }
                if (RightMousePressed())
                {
                    int xm = MouseX();
                    int ym = MouseY();

                    if (isInside(xm, ym, (IMM2D_WIDTH / 2 + 257) - 65, 952 - 65, (IMM2D_WIDTH / 2 + 257) + 65, 952 + 65)) {
                        if (statoDelMouseDestro == false)
                        {
                            if (puntata >= 500)
                            {
                                puntata -= 500;
                                saldo += 500;
                            }
                        }
                    }
                }
                if (saldo < 0)
                {
                    saldo = 0;
                }
                else if (puntata < 0) {
                    puntata = 0;
                }

                if (LastKey() == Enter)
                {
                    inizio = true;
                }
                statoDelMouseSinistro = LeftMousePressed();
                statoDelMouseDestro = RightMousePressed();
            }

            
            
            
            Present();
            Wait(2);
            //start
        }     
        statoDelMouseSinistro = LeftMousePressed();
        statoDelMouseDestro = RightMousePressed();
}

int carta(int xa, int ya, Image dorso,int& cont)
{
    
        DrawImage(xa, ya, dorso);  
        cont++;
        return cont;
}

bool isInside(int x, int y, int xStart, int yStart, int xEnd, int yEnd)
{
    if (xStart < x && x < xEnd)
    {
        if (yStart < y && y < yEnd)
        {
            return true;
        }
    }

    return false;
}

void mischiaCarte(Image carte[], int valori[])
{
    for (int i = 0; i < 200; i++)
    {
        srand(time(NULL));

        for (int j = 0; j < 52; j++)
        {
            for (int k = i; k < 51; k++) {
                int casuale=rand() % 2;
                if (casuale==1)
                {
                    int temp = carte[j];
                    carte[j] = carte[k + 1];
                    carte[k + 1] = temp;
                    
                    temp = valori[j];
                    valori[j] = valori[k + 1];
                    valori[k + 1] = temp;
                }
            }
        }
    }
}
