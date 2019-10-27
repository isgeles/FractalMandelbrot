//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include <cstdint>
#include <string>

using namespace std;

namespace ismg {


class Mandelbrot
{
public:
    static constexpr int MAX_ITERATION = 1000;


public:
    Mandelbrot();
//    virtual ~Mandelbrot();

    static int getIterations(double x, double y);
    
};




}
#endif




