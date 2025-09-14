#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdint.h>

extern uint8_t flag_display_menu;
extern char menu_pointer[2];
extern const char menu_icon;

void display_main_menu();
void change_pointer_position(uint8_t pos);
uint8_t get_pointer_position();

#endif