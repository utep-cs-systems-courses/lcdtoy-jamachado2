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

    drawString8x12(25,20, "SCORE !!", COLOR_BLUE, COLOR_BLACK);
    // draw a square with a rombo inside
    //drawTriangle(30,30,15, COLOR_WHITE);
    //drawSomething(60,60,60, COLOR_PINK);
    //    fillRectangle(35, 35, 60, 60, COLOR_BLUE);
    drawCustom(90,120,30, COLOR_WHITE);
    //drawDiamond(20,20,40, COLOR_RED);
    //drawSomething(10,10,30, COLOR_RED);
    u_char j;
    u_char i ;
    /*
    for(j = 0; j<=10; j++){
      for(i = 0; i<=j; i++)
    }
    */


    /* Diamond */
    /*  u_char c;
  int colStart;
  int colEnd;
  for(j = 0; j <= 30; j++){
    colStart = 0;
    colEnd = j;
    for(c=colStart; c<=colEnd; c++){
      /* intersint shapes with the combination of the 3 drawPixel */
      //drawPixel(30-c,30-j/c, COLOR_BLUE); //right triangle
      /*drawPixel(45-j,40+c*c/j, COLOR_RED);
      drawPixel(30+j,60-c*c/j, COLOR_RED);
      //fillRectangle(50,50,30,30, COLOR_WHITE);
      //drawPixel((-c*2)+80,j, COLOR_BLUE); // traingle with lines
  //drawPixel(-c+30,-j+60, COLOR_BLUE); // left triangle
    }
   }
      */
    /*
  for(u_char i = 0; i<=10; i++){
    for(u_char j = i; j<=i; j++){
      drawPixel(i,j, COLOR_RED);
    }
  }
    */
  /* dot */
  //for(j = 0; j < 90; j++)
  //drawPixel(10, 10, COLOR_YELLOW);

  /* Right triangle */
  /*
  for(j = 0; j < 15; j++){
    drawPixel(j, j, COLOR_BLUE);   // diagonal
    drawPixel(0,j, COLOR_BLUE);    // vertical
    drawPixel(j,15,COLOR_YELLOW);  // horizontal
  }
  */
  
  /* Right triangle */
  /*
  for(j = 0; j <= 40; j++){
    drawPixel((j/2),40,COLOR_YELLOW);  // horizontal
    drawPixel(0,j, COLOR_BLUE);    // vertical
    drawPixel((j/2), j, COLOR_BLUE);   // diagonal
  }
  */

  /* Filled right triangle */
  /*u_char c;
  int colStart;
  int colEnd;
  for(j = 0; j <= 30; j++){
    colStart = 0;
    colEnd = j;
    for(c=colStart; c<=colEnd; c++){
      /* intersint shapes with the combination of the 3 drawPixel */
  //drawPixel(c,j, COLOR_BLUE); //right triangle
      //drawPixel(j,c, COLOR_BLUE); // left triangle
  //drawPixel(j+30,-c+30, COLOR_BLUE); // an arrow wtf?
  //}
  //}

   /* trapecio with 2 triangles */
  /*  u_char c;
  u_char r;
  int colStart;
  int colEnd;
  for(r = 0; r <= 30; r++){
    colStart = 0;
    colDiagonal = 1/2;
    colEnd = r;
    //for(c = 0; c <= 30; c++){
    //rowStart = 0;
    //rowEnd = c;
       for(c=colStart; c<=colEnd; c++){
      drawPixel(c,r, COLOR_BLUE); //right triangle
      //drawPixel((-c*2)+80,j, COLOR_BLUE); // traingle with lines
      drawPixel(-c+30,-r+60, COLOR_BLUE); // left triangle
    }
    }*/
    //}

  // added on the draw file */
  // drawTriangle(u_char fc, u_char fr, u_char size, short color)
  /*  for(u_char r = 0; r <= 15; r+=3){
    u_char colLeft = 15-r; // size-r
    u_char colRight = 15; // size
    for(u_char c = colLeft; c<=colRight; c+=3){
      // intersint shapes with the combination of the 3 drawPixel 
      drawPixel(20+c,30+r, COLOR_PINK); //fc+c, fr+r, color
      drawPixel(20-c,30+r, COLOR_PINK); //right triangle
      drawPixel(20+c,30-r,COLOR_RED);
      drawPixel(20-c,30-r, COLOR_RED);
    }
  }
  */
  /* right diagonal line*/
  //for(j = 0; j < 50; j++)
  //drawPixel(j, j, COLOR_BLUE);

  /* vertical line */
  //for(j = 0; j < 50; j++)
  //drawPixel(0, j, COLOR_RED);

  /* horizontal LINE */
  //for(j = 0; j < 50; j++)
  //drawPixel(j, 50, COLOR_YELLOW);

  /* what's this a dot? */
  //for(j = 0; j < 90; j++)
  //drawPixel(j, -j, COLOR_WHITE);
  
  /* right diagonal line */
  //for(j = 0; j > 90; j++)
  //drawPixel(50, j, COLOR_RED);
}
