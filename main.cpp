//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================

#include <iostream>
#include "Bitmap.h"
#include "Bitmapfileheader.h"
#include "Bitmapinfoheader.h"

using namespace std;
using namespace ismg;


int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;



    Bitmap bitm(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            bitm.setPixels(i,j , 255, 0, 0);
            
            double xFractal = (i - (WIDTH)/2) / (WIDTH/2.0);
            double yFractal = (j - (HEIGHT)/2) / (HEIGHT/2.0);

            if(xFractal < min) min = xFractal;
            if(xFractal > max) max = xFractal;

        }
    }
    cout << min << ", " << max << endl;

    bitm.writeFile("test.bmp");

    cout << "Finished" << endl;
  
    return 0;
}