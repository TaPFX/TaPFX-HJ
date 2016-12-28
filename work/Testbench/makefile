# Makefie for Testbench

all: TB.o

TB.o: TB.c TB-PWM_TLC59711.c TB-TaPMagnets.c TB-UDPServer.c ../PWM_TLC59711.c ../TaPMagnets.c ../UDPServer.c 
	gcc TB.c TB-PWM_TLC59711.c TB-TaPMagnets.c TB-UDPServer.c  ../PWM_TLC59711.c ../TaPMagnets.c ../UDPServer.c  -o TB -lwiringPi 



