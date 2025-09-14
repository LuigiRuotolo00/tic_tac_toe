#ifndef GAME
#define GAME

#include <stdio.h>
#include <stdint.h>

extern uint8_t flag_display_game;

void game_init();
void display_grid();
void change_player_pointer(char key);
void turn_management();
void find_empty_cell();
uint8_t get_player_matrix(uint8_t x, uint8_t y);
char* get_player_name(uint8_t player);

#endif
