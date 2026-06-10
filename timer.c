#include <LPC21xx.H>

#define TIMER_RESET 0x2
#define TIMER_ENABLE 0x1
#define MATCH_CONTROL_INTERRUPT 0x1
#define MATCH_CONTROL_RESET 0x2
#define MATCH_CONTROL_STOP 0x4
#define INTERRUPT_RESET 0x1


void InitTimer0()
{
	
	T0TCR = TIMER_ENABLE;
	
}

void WaitOnTimer0(unsigned int uiTime)
{
	
	T0MR0 = uiTime * 15;
	T0MCR = MATCH_CONTROL_STOP;
	
	T0TCR |= TIMER_RESET;
	T0TCR = TIMER_ENABLE;
	
	while(T0TC != (uiTime *15)) 		//tu cos zmienic zeby byBo != nie trzeba trzymac sie argumentu funkcji
	{
		
	}

}

void InitTimer0Match0(unsigned int iDelayTime)
{
	
	T0MR0 = iDelayTime * 15;
	T0MCR = MATCH_CONTROL_INTERRUPT | MATCH_CONTROL_RESET;
	T0TCR |= TIMER_RESET;
	T0TCR = TIMER_ENABLE;
	
}

void WaitOnTimer0Match0()
{
	
	while(T0IR != 1)
	{
		
	}
	T0IR = INTERRUPT_RESET;
}
