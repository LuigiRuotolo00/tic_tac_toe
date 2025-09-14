#include <stdint.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
	#include <conio.h>
	#include <windows.h>
#endif

#include "menu.h"
#ifdef __linux__
	#include "input.h"
#endif
#include "game.h"
#include "game_rules.h"

#ifdef __linux__
	#ifndef ENTER
		#define ENTER 10
	#endif
#else
	#ifndef ENTER
		#define ENTER 13
	#endif
#endif

int main(void)
{
	uint8_t t_session = 1;
	uint8_t t_menu = 1;
	uint8_t t_game = 0;
	//uint8_t is_key_pressed = 0;
	char key = 0;
	uint8_t pos;

	char clear[5];

	memset(clear, 0, sizeof(clear));

	#ifdef __linux__
			clear[0] = 'c';
			clear[1] = 'l';
			clear[2] = 'e';
			clear[3] = 'a';
			clear[4] = 'r';
 		#elif defined(_WIN32)
			clear[0] = 'c';
			clear[1] = 'l';
			clear[2] = 's';
 		#endif
 		
 	#ifdef __linux__
		signal(SIGINT, interrupt_handler);
	#endif
	printf("\e[?25l");

	while (t_session)
	{
		system(clear);
		display_main_menu();

		while (t_menu)
		{
			flag_display_menu = 0;

			#ifdef __linux__
				key = kbhit();
			#elif defined(_WIN32)
				key = getch();
			#endif

			flag_display_menu = 1;

			switch (key)
			{
				case 'w':
					change_pointer_position(1);
					break;
				case 's':
					change_pointer_position(0);
					break;
				case ENTER:
					pos = get_pointer_position();
					t_menu = 0;
					flag_display_menu = 0;
					if (pos == 0)
					{
						t_game = 1;
						system(clear);
						game_init();
					}else if (pos == 1)
					{
						t_session = 0;
					}
					break;
				default:
					flag_display_menu = 0;
					break;
			}
			

			if (flag_display_menu == 1)
			{
				system(clear);
				display_main_menu();
			}
		}


		while (t_game)
		{
			#ifdef __linux__
				key = kbhit();
			#elif defined(_WIN32)
				key = getch();
			#endif

			flag_display_game = 1;

			change_player_pointer(key);

			if (check_rules(1))
			{
				t_game = 0;
				t_menu = 1;
				printf("%s WIN\n", get_player_name(1));
				#ifdef __linux__
					sleep(2);
				#elif defined(_WIN32)
					Sleep(2000);
				#endif
			}else if (check_rules(2))
			{
				t_game = 0;
				t_menu = 1;
				printf("%s WIN\n", get_player_name(1));
				#ifdef __linux__
					sleep(2);
				#elif defined(_WIN32)
					Sleep(2000);
				#endif
			}else if (check_no_win())
			{
				t_game = 0;
				t_menu = 1;
				printf("NOONE WIN\n");
				#ifdef __linux__
					sleep(2);
				#elif defined(_WIN32)
					Sleep(2000);
				#endif
			}
		}
	}

	printf("\e[?25h");

	return 0;
}
