/*
  Auto_Moving_Dot.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int xcoord = 3;
int ycoord = 4;
int direction = 0; // Keeps track of direction. Can be 0, 90, 180, or 270.

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  ClearSlate();
  CheckButtonsPress();
  UpdateDirection();
  UpdateDot();
  DrawPx(xcoord,ycoord,White);   // Draws player
  DisplaySlate();   
  delay (200);  
}

void UpdateDirection()
{
  if (Button_Right) // Updates the direction
    direction = 90;
  if (Button_Left) 
    direction = 270;
  if (Button_Up) 
    direction = 0;
  if (Button_Down) 
    direction = 180;
}

void UpdateDot()
{
  if (direction == 0) // Handles out-of-bounds values
    ycoord++;
  
  if (direction == 90) 
    xcoord = 0;
    
  if (direction == 180) // Handles out-of-bounds values
    ycoord = 7;
  
  if (direction == 270)
    ycoord = 0;
    
  if (xcoord < 0) xcoord = 7; // check for out-of-bounds and adjust if neccesary
  if (xcoord > 7) xcoord = 0;
  if (ycoord < 0) ycoord = 7;
  if (ycoord > 7) ycoord = 0;
}
