#include <genesis.h>
#include <bmp.h>

int main()
{

  //Initialise the bitmap engine
  BMP_init(TRUE, BG_A, PAL0, FALSE);

  //Set the colour of the line. We are using pallete 0 for the bitmap, so we have 0->15. 15 is used for white text, so we set an unused pallet colour, 14 to blue - RGB 0000FF.
  u16 colour_blue = RGB24_TO_VDPCOLOR(0x0000ff);
  VDP_setPaletteColor(14, colour_blue);

  //A line needs a source coordinate x,y and a destination coordinate x,y along with a pallete colour.
  Line l;
  l.pt1.x = 0;
  l.pt1.y = 0;
  l.pt2.x = 255;
  l.pt2.y = 0;
  l.col = 14;
  l.col |= l.col << 4; // if we do not left shift the colour, we get gaps in the line

  while(TRUE)
  {
      //Clear the bitmap
      BMP_clear();

      //Draw the line defined above (in the background, hidden)
      BMP_drawLine(&l);

      //Flip the data to the screen - i.e. actually draw the complete image on screen
      BMP_flip(1);

      //Increment the destination y coordinate
      l.pt2.y = l.pt2.y + 2;

      //Reset the destination y coordinate if it hits 160
      if (l.pt2.y == 160)
      {
        l.pt2.y = 0;
      }
  }
  return 0;
}
