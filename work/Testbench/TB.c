#include <stdio.h>
#include "TB.h"

int main(int argc,char* argv[]){
	int debug = 0;
	
	debug = atoi(argv[1]);
	Sleep = atoi(argv[2]);
	printBuff = atoi(argv[3]);
		
	init = 0;
	printf("---Start TB---\n");
	
//	tbTLC59711(debug);
	tbTaPMagnets(debug);
//	tbUDPServer(5555);
	
	printf("---End TB---\n");
	return 0;
}
