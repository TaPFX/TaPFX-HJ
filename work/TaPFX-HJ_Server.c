#include <unistd.h>
#include "TaPFX-HJ_Server.h"


extern char *optarg;
main(int argc, char *argv[]){
	int i;
	int opt;
	int port = DEFAULTPORT;
 	debug = 0;
	int invert = 0;
	char recvmsg[BUFSIZE] = "TaPMagnetServer;ON;100;";
	

	while ((opt = getopt(argc, argv, "p:dih")) != -1) {
		switch (opt) {
		case 'p':
			if(optarg != NULL)
				port = atoi(optarg);
			break;
		case 'd':
			debug = 1;
			break;		
		case 'i':
			invert = 1;
			break;
		case 'h':
			printf("Help for TaPMagnetServer\n");
			printf("Usage: %s [-p port number] [-d] debug mode [-h] show Help\n", argv[0]);
			return 0;
			break;
		default: /* '?' */
			printf("Usage: %s [-p portnumber] [-d] debug mode [-i] invert pwm output [-h] show Help\n", argv[0]);
			return -2;
    }
  }
	printf("port: %d\n",port);
	printf("debug: %d\n",debug);
	
	if(initUDPServer(port) != 0){
		printf("ERROR whil init UDP-Server\n");
		return -1;
	}
	
	if(magnetInit(invert) != 0){
		printf("ERROR whil init Magnets\n");
		return -1;
	}
	
	while(!(strcmp(recvmsg,"TaPMagnet;exit") == 0)){
		bzero(recvmsg, BUFSIZE);
		waitForClient(recvmsg);
		printf("msg: %s\n",recvmsg);
		
		if(parseCommand(recvmsg) != 0){
			printf("ERROR wrong Syntax\n");
			continue;
		}
		
		if(strcmp(MagnetMode, "ON") == 0){
			if(setMagnetON(MagnetChan, DC) !=0){
				printf("ERROR setMagnetON(%d,%d)\n",MagnetChan,DC);
				continue;
			}
			if(debug) printf("setMagnetON(%d,%d)\n",MagnetChan,DC);}
		else if(strcmp(MagnetMode, "OFF") == 0){
			if(magnetOFF(MagnetChan) !=0){
				printf("ERROR magnetOFF(%d)\n",MagnetChan);
				continue;
			}
			if(debug) printf("magnetOFF(%d)\n",MagnetChan);
		}
	}
		

	
	return 0;
}

signed char parseCommand(char command[BUFSIZE]){
	int i;
	char copycommand[BUFSIZE];
	char *splitCommand;

	for(i=0;i<BUFSIZE;i++)
		copycommand[i] = command[i];
	
	splitCommand=strtok(copycommand,";");
	if(strcmp(splitCommand, "TaPMagnet") != 0)
		return -1;
	
	splitCommand=strtok(NULL,";");
	if(splitCommand == NULL)
		return -1;
	MagnetChan = atoi(splitCommand);
	if(MagnetChan > 4 || MagnetChan < 1){
		MagnetChan = 1;
		return -1;}
	
	splitCommand=strtok(NULL,";");
	if(strcmp(splitCommand, "ON") == 0 || strcmp(splitCommand, "OFF") == 0)
		MagnetMode = splitCommand;
	else
		return -1;
	
	if(strcmp(MagnetMode, "ON") == 0){
		splitCommand=strtok(NULL,";");
		if(splitCommand == NULL)
			return -1;
		DC = atoi(splitCommand);
		if(DC > 100 || DC < 0){
			DC = 100;
			return -1;}
		}

	
	return 0;
}
