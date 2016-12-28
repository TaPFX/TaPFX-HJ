#include "TB.h"
#include "../UDPServer.h"

int tbUDPServer(int debug){
	signed char retinitUDPS, retwaitForClient, retgetAddres, retsendBack;
	
	printf("---UDPServer Testbench---\n");
	
	retinitUDPS = initUDPServer(5555);
	if(retinitUDPS != 0){
		printf("ERROR  initUDPServer(5555)\n");
		ErrCNT++; }
	else if(debug) 
		printf("PASSED initUDPServer(5555)\n");
	
	
	while(1){
		retwaitForClient = waitForClient();
		if(retwaitForClient != 0){
			printf("ERROR  waitForClient()\n");
			ErrCNT++; }
		else if(debug) 
			printf("PASSED waitForClient()\n");
			
		printf("\n");
	}
	
	return 0;
	
}
