#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include <time.h>
#include "led.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"

/* When SW1 is press draw custom shape */
char drawCustomShape()
{
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    green_on = 0;
    drawCustom(90,120,30, COLOR_RED);
    buzzer_set_period(1000);
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 2;
    buzzer_set_period(0);
    break;
  }
}

void onPressSW2()
{
  led_changed = drawCustomShape();
  led_update();
}

/* When SW2 is press draw filled square */
char drawSquare()
{
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    green_on = 0;
    state = 1;
    fillRectangle(10,30,30,30, COLOR_RED);
    buzzer_set_period(250);
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 2;
    buzzer_set_period(0);
    break;
  }
}

void onPressSW1()
{
  led_changed = drawSquare();
  led_update();
}

/* when SW3 is press draw triangle */
char draw_Triangle()
{
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    green_on = 0;
    state = 1;
    drawTriangle(60,60,10, COLOR_RED);
    buzzer_set_period(5000);
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 2;
    buzzer_set_period(0);
    break;
  }
}
void onPressSW3()
{
  led_changed = draw_Triangle();
  led_update();
}

/* draws the same custome figure as SW1 but with different color */
char draw2Custom()
{
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    green_on = 0;
    state = 1;
    drawCustom(40,40,10, COLOR_RED);
    buzzer_set_period(450);
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 2;
    buzzer_set_period(0);
    break;
  }
}

void onPressSW4()
{
  led_changed = draw2Custom();
  led_update();
}
