//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================


#include <string>
#include <fstream>

#include "Bitmap.h"
#include "Bitmapfileheader.h"
#include "Bitmapinfoheader.h"

using namespace std;
using namespace ismg;

namespace ismg {


Bitmap::Bitmap(int width, int height): 
m_width(width), m_height(height), m_Pixels(new uint8_t[width*height*3]{}){ //init with zeros by {}

}

void Bitmap::setPixels(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t *pixel = m_Pixels.get();

    pixel += (y*3) * m_width + (x*3); // times 3 for RGB

    // bitmap is little endian format
    pixel[0] = blue; 
    pixel[1] = green; 
    pixel[2] = red; 
}


bool Bitmap::writeFile(string filename) {
    Fileheader bFileheader;
    Infoheader bInfoheader;

    bFileheader.fileSize = sizeof(Fileheader) + sizeof(Infoheader) 
                            + (m_width * m_height * 3);

    bFileheader.offsetBits = sizeof(Fileheader) + sizeof(Infoheader);
    
    bInfoheader.width = m_width;
    bInfoheader.height = m_height;

    ofstream file; // ouput file stream

    file.open(filename, ios::out|ios::binary); // write binary

    if(!file) {
        return false;
    }

    file.write((char*)&bFileheader, sizeof(bFileheader));
    file.write((char*)&bInfoheader, sizeof(bInfoheader));
    file.write((char*)m_Pixels.get(), m_width * m_height * 3);




    file.close();

    if(!file) {
        return false;
    }

    return true;
}




}





