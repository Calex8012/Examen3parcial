#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=40000000)

#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif

int contador=1;
#INT_TIMER0 
void TIMER0(){
contador++;
set_timer0(15536);
}

void main (void){
   setup_oscillator(OSC_16MHZ);
   while(1){
      set_tris_a(0x00);
      set_tris_b(0x00);
      set_tris_d(0x00);
      setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8 );
      enable_interrupts(INT_TIMER0);
   }
}
