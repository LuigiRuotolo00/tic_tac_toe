#include <stdint.h>
#include <stdio.h>
#include <signal.h>

#include "menu.h"
#include "input.h"
#include "game.h"
#include "game_rules.h"

int main(void)
{
	uint8_t t_session = 1;
	uint8_t t_menu = 1;
	uint8_t t_game = 0;
	//uint8_t is_key_pressed = 0;
	char key = 0;
	uint8_t pos;

	signal(SIGINT, interrupt_handler);
	printf("\e[?25l");

	while (t_session)
	{
		system("clear");
		display_main_menu();

		while (t_menu)
		{
			flag_display_menu = 0;
			//key = 0;

			key = kbhit();

			flag_display_menu = 1;

			switch (key)
			{
				case 'w':
					change_pointer_position(1);
					break;
				case 's':
					change_pointer_position(0);
					break;
				case 10:
					pos = get_pointer_position();
					t_menu = 0;
					flag_display_menu = 0;
					if (pos == 0)
					{
						t_game = 1;
						system("clear");
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
				system("clear");
				display_main_menu();
			}
		}

		//system("clear");
		//display_grid();

		while (t_game)
		{
			key = kbhit();

			flag_display_game = 1;

			change_player_pointer(key);

			if (check_rules(1))
			{
				t_game = 0;
				t_menu = 1;
				printf("%s WIN\n", get_player_name(1));
				sleep(2);
			}else if (check_rules(2))
			{
				t_game = 0;
				t_menu = 1;
				printf("%s WIN\n", get_player_name(1));
				sleep(2);
			}else if (check_no_win())
			{
				t_game = 0;
				t_menu = 1;
				printf("NOONE WIN\n");
				sleep(2);
			}
		}
	}

	printf("\e[?25h");

	return 0;
}