#include <msp430.h>
#include "stateMachines.h"
#include "switch_machines.h" // to control switches
#include "switches.h"
//#include "buzzer.h"
//#include "blink.h"
//#include "song.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  switch_interrupt_handler();
  if(switch_state_down){
    if(++blink_count == 125){
      onPressSW1();
      blink_count = 0;
    }
  }
  if(switch_state_down2){
    if (++blink_count == 125) {
      onPressSW2();
      blink_count = 0;
    }
  }
  if(switch_state_down3){
    if(++blink_count == 125){
      onPressSW3();
      blink_count = 0;
    }
  }
 if(switch_state_down4){
    if(++blink_count == 125){
      onPressSW4();
      blink_count = 0;
    }
  }
}
