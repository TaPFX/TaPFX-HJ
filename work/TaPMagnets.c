#include "TaPMagnets.h"

char invert = 0;
signed char magnetInit(int inv){
	
	if(inv > 1 || inv < 0)
		return -2;

	invert = inv;
	
	if(initSPI() != 0)
		return -1;

	return 0;
}

signed char setMagnetON(int magChan, char dutyCycle){
	int pwmVal;
	if(magChan > 4 || magChan < 1)
		return -2;
	
	if(dutyCycle > 100 || dutyCycle < 0)
		return -2;
	
	if(invert)
		dutyCycle = 100-dutyCycle;
	
	if( dutyCycle == 0)
		pwmVal = 0;
	else
		pwmVal = (int)((double)dutyCycle/100*65535);
	
	printf("dc: %d pwmval: %d \n",dutyCycle,pwmVal);
	if(setChannel(magChan*3-1, pwmVal) != 0)
		return -1;
	
	if(setChannel(magChan*3-2, pwmVal) != 0)
		return -1;
	
	if(setChannel(magChan*3-3, pwmVal) != 0)
		return -1;


	return 0;
}

signed char magnetOFF(int magChan){
	int dc = 0;

	if(magChan > 4 || magChan < 1)
		return -2;
	
	if(invert)
		dc = 100;
	else
		dc = 0;
	
	setMagnetON(magChan, dc);

	return 0;
}


signed char magnetON(int magChan){
	int dc = 0;

	if(magChan > 4 || magChan < 1)
		return -2;
	
	if(invert)
		dc = 0;
	else
		dc = 100;
	
	setMagnetON(magChan, dc);

	return 0;
}
