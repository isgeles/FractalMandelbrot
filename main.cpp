//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================

#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Bitmapfileheader.h"
#include "Bitmapinfoheader.h"
#include "Mandelbrot.h"

using namespace std;
using namespace ismg;


int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;



    Bitmap bitm(WIDTH, HEIGHT);

    //double min = 999999;
    //double max = -999999;
    unique_ptr<int[]> gradient(new int[Mandelbrot::MAX_ITERATION]);
    unique_ptr<int[]> iterationPerPixel(new int[WIDTH*HEIGHT]);

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            //bitm.setPixels(x,y , 0, 0, 255);  // setting pixels to color
            
            //offset to center and scaling
            double xFractal = (x - (WIDTH)/2.0) - WIDTH/4.0;    // offset
            xFractal /= ((WIDTH-1)/2.0);                // scaling
            double yFractal = (y - (HEIGHT)/2.0); 
            yFractal /= ((HEIGHT-1)/2.0);

            int iterationNumber = Mandelbrot::getIterations(xFractal, yFractal);

            iterationPerPixel[x*HEIGHT + y] = iterationNumber; // storing iterations per pixel

            //filtering maximum iteration number in gradient
            if(iterationNumber != Mandelbrot::MAX_ITERATION){
                gradient[iterationNumber]++; // how many pixels have a number of iteration
            }



        }
    }

    int totalIterations = 0;
    for(int i = 0; i<Mandelbrot::MAX_ITERATION; i++) {
        totalIterations += gradient[i];
    }
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations  = iterationPerPixel[x*HEIGHT + y];

            //normalizing convergence to 255
            //uint8_t conv = uint8_t(255 * iterations/(Mandelbrot::MAX_ITERATION));

            //if(conv < min) min = conv;
            //if(conv > max) max = conv;

            double colorFactor = 0.0;
            if(iterations != Mandelbrot::MAX_ITERATION) {
                for (int i = 0; i < iterations; i++)
                {
                    colorFactor += (double)gradient[i]/totalIterations;
                }
                //conv = conv*conv*conv;
                green = pow(255,colorFactor);
            }
            bitm.setPixels(x,y, red, green, blue); 


            //check max value on top right corner
            // if(WIDTH-1 == x && y ==HEIGHT-1){
            //     bitm.setPixels(x,y, 255, 255, 255);
            //     cout << xFractal << ": " << yFractal << endl;
            // }

        }
    }

    cout << endl;
    cout << "----" << endl;
    //cout << min << ", " << max << endl;

    bitm.writeFile("test.bmp");

    cout << "Finished" << endl;
  
    return 0;
}






