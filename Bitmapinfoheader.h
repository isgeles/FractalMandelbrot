//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>


using namespace std;


namespace ismg {

#pragma pack()

typedef struct _Infoheader_
{
    uint32_t headerSize = 40;       // info header size (40)
    uint32_t width;                 // pixel width 
    uint32_t height;                // pixel height 
    uint16_t planes = 1;            // color planes, must be 1
    uint16_t bitCount = 24;         // 24 for RGB
    uint32_t compression = 0;       // compression (0)
    uint32_t imageSize = 0;         // bytes in pixel data
    uint32_t xResolution = 2400;    // horizontal resolution 
    uint32_t yResolution = 2400;    // vertical resolution 
    uint32_t colors = 0;            // number of colors, default 0
    uint32_t importantColor = 0;    // important colors, default 0
}__attribute__((packed)) Infoheader;





}
#endif




