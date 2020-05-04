/** \file lcddraw.c
 *  \brief Adapted from RobG's EduKit
 */
#include "lcdutils.h"
#include "lcddraw.h"


/** Draw single pixel at x,row 
 *
 *  \param col Column to draw to
 *  \param row Row to draw to
 *  \param colorBGR Color of pixel in BGR
 */
void drawPixel(u_char col, u_char row, u_int colorBGR) 
{
  lcd_setArea(col, row, col, row);
  lcd_writeColor(colorBGR);
}

/** Fill rectangle
 *
 *  \param colMin Column start
 *  \param rowMin Row start
 *  \param width Width of rectangle
 *  \param height height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, 
		   u_int colorBGR)
{
  u_char colLimit = colMin + width, rowLimit = rowMin + height;
  lcd_setArea(colMin, rowMin, colLimit - 1, rowLimit - 1);
  u_int total = width * height;
  u_int c = 0;
  while ((c++) < total) {
    lcd_writeColor(colorBGR);
  }
}

  // added on the draw file */
void drawTriangle(u_char fc, u_char fr, u_char size, short color){
  for(u_char r = 0; r <= 15; r+=3){
    u_char colLeft = size-r; // size-r
    u_char colRight = size; // size
    for(u_char c = colLeft; c<=colRight; c+=3){
      /* intersint shapes with the combination of the 3 drawPixel */
      drawPixel(fc + c, fr + r, COLOR_PINK); //fc+c, fr+r, color
      drawPixel(fc - c, fr + r, COLOR_PINK); //right triangle
      drawPixel(fc + c, fr - r,COLOR_RED);
      drawPixel(fc - c, fr - r, COLOR_RED);
    }
  }
}

void drawCustom(u_char ffc, u_char ffr, u_char ssize, short color){
  for(u_char r = 0; r <= 15; r++){
    u_char colLeft = ssize-r; // size-r
    u_char colRight = ssize; // size
    for(u_char c = colLeft; c<=colRight; c++){
      drawPixel(ffc + c, ffr + r, COLOR_RED);
      drawPixel(ffc + c, ffr - r,COLOR_RED);
      drawPixel(ffr - r, ffc + c, COLOR_RED);
    }
  }
}


/* fucking diamond */
void drawDiamond(u_char lj, u_char lc,u_char size, short color){

  /* Diamond */
  int colStart;
  int colEnd;
  for(u_char j = size; j <= 30; j++){
    colStart = 0;
    colEnd = j;
    for(u_char c=colStart; c<=colEnd; c++){
      /* intersint shapes with the combination of the 3 drawPixel */
      //drawPixel(30-c,30-j/c, COLOR_BLUE); //right triangle
      drawPixel(lj-j,lc+c*c/j, COLOR_RED);
      drawPixel(lj+j,lc-c*c/j, COLOR_RED);
      //fillRectangle(50,50,30,30, COLOR_WHITE);
      //drawPixel((-c*2)+80,j, COLOR_BLUE); // traingle with lines
  //drawPixel(-c+30,-j+60, COLOR_BLUE); // left triangle
    }
   }

}

void drawSomething(u_char sc, u_char sr, u_char ssize, short color){
  for(u_char rrr = 0; rrr <= 30; rrr++){
    u_char cLeft = ssize-rrr;
    u_char cRight = ssize;
    for(u_char ccc = cLeft; ccc<=cRight; ccc++){
      drawPixel(sc, sr, COLOR_YELLOW);
      drawPixel(sc - ccc, sr - rrr, COLOR_YELLOW);
      drawPixel(sc + ccc, sr, COLOR_YELLOW);
    }
  }
}

/** Clear screen (fill with color)
 *  
 *  \param colorBGR The color to fill screen
 */
void clearScreen(u_int colorBGR) 
{
  u_char w = screenWidth;
  u_char h = screenHeight;
  fillRectangle(0, 0, screenWidth, screenHeight, colorBGR);
}

/** 5x7 font - this function draws background pixels
 *  Adapted from RobG's EduKit
 */
void drawChar5x7(u_char rcol, u_char rrow, char c, 
     u_int fgColorBGR, u_int bgColorBGR) 
{
  u_char col = 0;
  u_char row = 0;
  u_char bit = 0x01;
  u_char oc = c - 0x20;

  lcd_setArea(rcol, rrow, rcol + 4, rrow + 7); /* relative to requested col/row */
  while (row < 8) {
    while (col < 5) {
      u_int colorBGR = (font_5x7[oc][col] & bit) ? fgColorBGR : bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
    }
    col = 0;
    bit <<= 1;
    row++;
  }
}

/** Draw string at col,row
 *  Type:
 *  FONT_SM - small (5x8,) FONT_MD - medium (8x12,) FONT_LG - large (11x16)
 *  FONT_SM_BKG, FONT_MD_BKG, FONT_LG_BKG - as above, but with background color
 *  Adapted from RobG's EduKit
 *
 *  \param col Column to start drawing string
 *  \param row Row to start drawing string
 *  \param string The string
 *  \param fgColorBGR Foreground color in BGR
 *  \param bgColorBGR Background color in BGR
 */
void drawString5x7(u_char col, u_char row, char *string,
		u_int fgColorBGR, u_int bgColorBGR)
{
  u_char cols = col;
  while (*string) {
    drawChar5x7(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 6;
  }
}



void drawChar8x12(u_char rcol, u_char rrow,char c, u_int fgColorBGR, u_int bgColorBGR)

{
  u_char col=0;
  u_char row=0;
  u_char bit=0x01;
  u_char oc=c-0x20;

  lcd_setArea(rcol,rrow,rcol+7,rrow+12);
  while(row<13){
    while(col<8){
      u_int colorBGR=(font_8x12[oc][col] & bit) ? fgColorBGR : bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
    }
    col=0;
    bit<<=1;
    row++;
  }
}

void drawString8x12(u_char col,u_char row, char *string,u_int fgColorBGR, u_int byColorBGR)
{
  u_char cols=col;
  while(*string){
    drawChar8x12(cols,row,*string++,fgColorBGR,byColorBGR);
    cols +=11;
  }
}
/** Draw rectangle outline
 *  
 *  \param colMin Column start
 *  \param rowMin Row start 
 *  \param width Width of rectangle
 *  \param height Height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height,
		     u_int colorBGR)
{
  /**< top & bot */
  fillRectangle(colMin, rowMin, width, 1, colorBGR);
  fillRectangle(colMin, rowMin + height, width, 1, colorBGR);

  /**< left & right */
  fillRectangle(colMin, rowMin, 1, height, colorBGR);
  fillRectangle(colMin + width, rowMin, 1, height, colorBGR);
}

