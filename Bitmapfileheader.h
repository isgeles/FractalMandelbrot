//=================================================================
// Name: 
// Author: IG
// Version
// Description: 
//=================================================================

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>


using namespace std;


namespace ismg {

#pragma pack()

typedef struct _Fileheader_
{
  uint8_t header[2] = {'B', 'M'};    
  uint32_t fileSize;
  uint32_t reserved = 0;
  uint32_t offsetBits;      
}__attribute__((packed)) Fileheader;




}
#endif




