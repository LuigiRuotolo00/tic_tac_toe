#include "game_rules.h"

/*player_rules:
0 - vertical left
1 - vertical center
2 - vertical right
3 - horizontal up
4 - horizontal center
5 - horizontal down
6 - diagonal from left
7 - diagonal from right
*/
static uint8_t player1_rules[8] = {1, 1, 1, 1, 1, 1, 1, 1};
static uint8_t player2_rules[8] = {1, 1, 1, 1, 1, 1, 1, 1};

uint8_t check_rules(uint8_t player)
{
    if ((get_player_matrix(0, 0) == player && get_player_matrix(0, 1) == player &&
    get_player_matrix(0, 2) == player)
    || (get_player_matrix(0, 0) == player && get_player_matrix(1, 0) == player &&
    get_player_matrix(2, 0) == player)
    || (get_player_matrix(0, 0) == player && get_player_matrix(1, 1) == player &&
    get_player_matrix(2, 2) == player)
    || (get_player_matrix(1, 0) == player && get_player_matrix(1, 1) == player &&
    get_player_matrix(1, 2) == player)
    || (get_player_matrix(2, 0) == player && get_player_matrix(2, 1) == player &&
    get_player_matrix(2, 2) == player)
    || (get_player_matrix(0, 1) == player && get_player_matrix(1, 1) == player &&
    get_player_matrix(2, 1) == player)
    || (get_player_matrix(0, 2) == player && get_player_matrix(1, 2) == player &&
    get_player_matrix(2, 2) == player)
    || (get_player_matrix(0, 2) == player && get_player_matrix(1, 1) == player &&
    get_player_matrix(2, 0) == player))
    {
        return 1;
    }else
    {
        uint8_t count = 0;
        for (uint8_t i = 0; i < 3; i++)
        {
            for (uint8_t j = 0; j < 3; j++)
            {
                if (get_player_matrix(i, j) == 0)
                {
                    count++;
                }
            }
        }
        return 0;
    }
}

uint8_t check_no_win()
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < 3; i++)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            if (get_player_matrix(i, j) == 0)
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        return 1;
    }else return 0;
}