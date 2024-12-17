#define IMM2D_WIDTH 1920
#define IMM2D_HEIGHT 1080
#define IMM2D_SCALE 1

#define IMM2D_IMPLEMENTATION
#include "immediate2d.h"
#include <string>

using namespace std;
int colore = MakeColor(0, 49, 83);
int colortav = MakeColor(139, 69, 19);
int coloretav2 = MakeColor(0, 100, 0);
void run() {
    int colore = MakeColor(0, 49, 83);
    int colortav = MakeColor(139, 69, 19);
    int coloretav2 = MakeColor(0, 100, 0);
    
    
        UseAntiAliasing();
        Clear(colore);
        DrawCircle(960, 0, 900, colortav, colortav);
        DrawCircle(960, 0, 800, coloretav2, coloretav2);

    

}