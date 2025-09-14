#ifndef INPUT
#define INPUT

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

//extern uint8_t is_key_pressed;

int getch(void);
uint8_t kbhit();
void interrupt_handler();

#endif
