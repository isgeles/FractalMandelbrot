//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================

#include <complex>
#include "Mandelbrot.h"

using namespace std;
using namespace ismg;

namespace ismg {

Mandelbrot::Mandelbrot() {

}


int Mandelbrot::getIterations(double x, double y) {

    complex<double> z = 0;
    complex<double> c(x,y);

    
    int iterations = 0;
    for(;iterations < Mandelbrot::MAX_ITERATION; iterations++) {
        z = z*z + c;

        if(abs(z) > 5) { //length of z smaller than 2
            break;
        }

    }


    return iterations;
}




 


}





