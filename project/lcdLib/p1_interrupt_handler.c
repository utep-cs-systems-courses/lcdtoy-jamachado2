#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "switch_machines.h"
#include "buzzer.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
    switch_interrupt_handler();/* single handler for all switches */
    if(switch_func == 1){
      drawSquare_interrupt_handler();
      }
    /* draw custom shape */
    if(switch_func == 2){
      drawCustom_interrupt_handler();
    }
    if(switch_func == 3){
      draw_Triangle_interrupt_handler();
      }
    if(switch_func == 4){
      draw2_Custom_handler();
      }
  }
}
