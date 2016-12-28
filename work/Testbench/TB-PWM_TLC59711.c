/* Testbench for TLC59711 Functions
 *
 *
 */

#include "TB.h"
#include  "../PWM_TLC59711.h"

int tbTLC59711(int debug){
	signed char retInitSPI, retfullON, retsetAllChan, retClearAll,retsetChan;
	int i = 0;
	ErrCNT = 0;
	
	printf("----Testing TLC59711----\n");
	
	if(init == 0){
		init = 1;
		retInitSPI = initSPI();
		if(retInitSPI != 0){
			printf("ERROR  %d SPI Init faild\n",retInitSPI);
			ErrCNT++;
			return -1; }
		else if(debug)	printf("PASSED %d Init succses!\n",retInitSPI);
		if(printBuff) printSPIBuff();
	}
	
	// Test clearAll()
	retClearAll = clearAll();
	if(retClearAll != 0){
		printf("ERROR  %d clearAll faild\n",retClearAll);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d clearAll()\n",retClearAll); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	// Test fullON()
	retfullON = fullON();
	if(retfullON != 0){
		printf("ERROR  %d fullON faild\n",retfullON);;
		ErrCNT++;}
	else if(debug){ printf("PASSED %d fullON()\n",retfullON); usleep(Sleep);}
		if(printBuff) printSPIBuff();
		
	// Test setALLChan(int pwmVal)
		// Check for Vaild
	retsetAllChan = setAllChan(0);
	if(retsetAllChan != 0){
		printf("ERROR  %d setAllChan(0) faild\n",retsetAllChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setAllChan(0)\n",retsetAllChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
		
	retsetAllChan = setAllChan(30000);
	if(retsetAllChan == -1){
		printf("ERROR  %d setAllChan(30000) faild\n",retsetAllChan);
		ErrCNT++;}
	else	if(debug){ printf("PASSED %d setAllChan(30000)\n",retsetAllChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
		
	retsetAllChan = setAllChan(0xFFFF);
	if(retsetAllChan == -1){
		printf("ERROR  %d setAllChan(0xFFFF) faild\n",retsetAllChan);
		ErrCNT++;}
	else	if(debug){ printf("PASSED %d setAllChan(0xFFFF)\n",retsetAllChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
			
	// Check for fail
	retsetAllChan = setAllChan(-10);
	if(retsetAllChan != -2){
		printf("ERROR  %d setAllChan(-10) faild\n",retsetAllChan);
		ErrCNT++;}
	else	if(debug){ printf("PASSED %d setAllChan(-10)\n",retsetAllChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
			
	retsetAllChan = setAllChan(66666);
	if(retsetAllChan != -2){
		printf("ERROR  %d setAllChan(66666) faild\n",retsetAllChan);
		ErrCNT++;}
	else	if(debug){ printf("PASSED %d setAllChan(66666)\n",retsetAllChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	clearAll();	
	// Ttest serChannel(channel, pwmVal)
		// PASSED Check
	retsetChan = setChannel(0,0xFFFF);
	if(retsetChan != 0){
		printf("ERROR  %d setChannel(0,0xFF) faild\n",retsetChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setChannel(0,0xFF)\n",retsetChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	retsetChan = setChannel(7,0xFFFF);
	if(retsetChan != 0){
		printf("ERROR  %d setChannel(7,0xFFFF) faild\n",retsetChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setChannel(7,0xFFFF)\n",retsetChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	retsetChan = setChannel(11,0xFFFF);
	if(retsetChan != 0){
		printf("ERROR  %d setChannel(11,0x01) faild\n",retsetChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setChannel(11,0x01)\n",retsetChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	retsetChan = setChannel(12,0x01);
	if(retsetChan != -2){
		printf("ERROR  %d setChannel(12,0x01) faild\n",retsetChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setChannel(12,0x01)\n",retsetChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	retsetChan = setChannel(-2,0x01);
	if(retsetChan != -2){
		printf("ERROR  %d setChannel(-2,0x01) faild\n",retsetChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setChannel(-2,0x01)\n",retsetChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();	
	retsetChan = setChannel(5,0x1FFFF);
	if(retsetChan != -2){
		printf("ERROR  %d setChannel(5,0x1FFFF) faild\n",retsetChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setChannel(5,0x1FFFF)\n",retsetChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	retsetChan = setChannel(4,-1);
	if(retsetChan != -2){
		printf("ERROR  %d setChannel(4,-1) faild\n",retsetChan);
		ErrCNT++;}
	else if(debug){ printf("PASSED %d setChannel(4,-1)\n",retsetChan); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	for(i=0;i<12;i++){
		if(clearAll() != 0)
			printf("ERROR clear\n");
		if(setChannel(i,0xFFFF) != 0)
			printf("ERROR setChannel\n");
		usleep(Sleep);
	}
	
	for(i=0;i<0xFFFF;i++){
		setChannel(1,i);
		if(printBuff) printSPIBuff();}

	if(ErrCNT == 0)
		printf("PASSED PWM_TLC59711\n");
	else{
		printf("ERROR PWM_TLC59711 faild\n");
		return -1;}
	return 0;
}
