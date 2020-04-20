/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
//#include "lcddrawx.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLACK);

    drawString5x7(25,20, "SCORE !!", COLOR_BLUE, COLOR_BLACK);

    //    fillRectangle(35, 35, 60, 60, COLOR_BLUE);
  
  u_char j;

  /* dot */
  //for(j = 0; j < 90; j++)
  //drawPixel(10, 10, COLOR_YELLOW);

  /* right diagonal line*/
  for(j = 0; j < 50; j++)
  drawPixel(j, j, COLOR_BLUE);

  /* vertical line */
  for(j = 0; j < 50; j++)
  drawPixel(0, j, COLOR_RED);

  /* horizontal LINE */
  for(j = 0; j < 50; j++)
  drawPixel(j, 50, COLOR_YELLOW);

  /* what's this a dot? */
  //for(j = 0; j < 90; j++)
  //drawPixel(j, -j, COLOR_WHITE);
  
  /* right diagonal line */
  //for(j = 0; j > 90; j++)
  //drawPixel(50, j, COLOR_RED);
}
