//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================

#ifndef BITMAP_H_
#define BITMAP_H_

#include <cstdint>
#include <string>

using namespace std;

namespace ismg {


class Bitmap
{
private:
    int m_width = 0;
    int m_height = 0;
    unique_ptr<uint8_t[]> m_Pixels = NULL; //free memory not needed with unique pointers

public:
    Bitmap(int width, int height);
    bool writeFile(string filename);
    void setPixels(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    //virtual ~Bitmap();
    
};





}
#endif




