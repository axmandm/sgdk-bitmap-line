An experiment in drawing bitmapped lines on screen.

Draws a blue line from 0,0 to 240,0 and then increments 240,0 to 240,2 240,4 etc.

There are a couple of "gotchas" with working with bitmaps to be aware of.

1. Computing the bitmap to be drawn and _then_ drawing it is much faster than drawing pixel by pixel or line by line. BMP_flip(); should be carefully positioned within the code loops to take this into account.

2. Bitmap mode expects colours to be defined as 8 bits. In essence, when selecting a pallet colour, we need to left shift the pallet number. 

Explained helpfully on the SGDK discord thusly:

```
erik 22/06/2020 at 19:05
Because the bmp functions treat two hardware pixels as a single bitmap pixel
Each pixel is 4 bit color, so two at once means a byte, which is a lot more efficient to manipulate
But you also need to supply two colors

Stef 23/06/2020 at 11:39
as said Eric color are 4 bits on Megadrive, still i let the opportunity of providing a couple of pixel 
color instead of a single pixel color. Thus you can create mesh filling (alternate color pixel), to so 
pseudo transparent or just to simulate more colors.
```
