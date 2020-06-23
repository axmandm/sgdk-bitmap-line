An experiment in drawing bitmapped lines on screen.

Draws a blue line from 0,0 to 240,0 and then increments 240,0 to 240,2 240,4 etc.

erik 22/06/2020 at 19:05
Because the bmp functions treat two hardware pixels as a single bitmap pixel
Each pixel is 4 bit color, so two at once means a byte, which is a lot more efficient to manipulate
But you also need to supply two colors
