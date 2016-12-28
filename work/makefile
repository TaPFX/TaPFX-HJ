all: TaPFX-HJ_Server.o
	
TaPFX-HJ_Server.o: TaPFX-HJ_Server.c UDPServer.c TaPMagnets.c PWM_TLC59711.c
	gcc TaPFX-HJ_Server.c UDPServer.c TaPMagnets.c PWM_TLC59711.c -o TaPFX-HJ_Server -lwiringPi
