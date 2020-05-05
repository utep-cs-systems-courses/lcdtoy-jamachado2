#include <msp430.h>
#include "switch_machines.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"

char switch_func = 1;

void drawCustom_interrupt_handler(){
  /* blink with sound */
  if(switch_state_down2){
    switch_func = 2;
  }
}

void drawSquare_interrupt_handler(){
  if(switch_state_down){
    switch_func = 1;
  }
}

void draw_Triangle_interrupt_handler(){
  if(switch_state_down3){
    switch_func = 3;
  }
}

void draw2_Custom_handler(){
  if(switch_state_down4){
    switch_func = 4;
  }
}
