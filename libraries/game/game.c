#include "game.h"

static char player1_name[20];
static char player2_name[20];

static uint8_t turn = 0;

static char grid[3][5] = {{' ', '|', ' ', '|', ' '}, {' ', '|', ' ', '|', ' '}, {' ', '|', ' ', '|', ' '}};
static uint8_t game_grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

static char player1_icon = 'X';
static char player2_icon = 'O';

static uint8_t icon_position_x;
static uint8_t icon_position_y;

static char old_icon = ' ';

uint8_t flag_display_game = 0;

static char clear[5];


void game_init()
{
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
 	
    memset(grid, ' ', sizeof(grid));
    grid[0][1] = '|';
    grid[0][3] = '|';
    grid[1][1] = '|';
    grid[1][3] = '|';
    grid[2][1] = '|';
    grid[2][3] = '|';

    memset(game_grid, 0, sizeof(game_grid));

    memset(player1_name, 0, sizeof(player1_name));
    memset(player2_name, 0, sizeof(player2_name));

    turn = 0;
    old_icon = ' ';
    flag_display_game = 0;

    printf("Player 1, insert your name (MAX 20 CHAR) ");
    scanf("%20s", player1_name);
    system(clear);
    printf("Player 2, insert your name (MAX 20 CHAR) ");
    scanf("%20s", player2_name);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} //cleaning of input buffer

    system(clear);
    char icon;
    if (turn % 2 == 0)
    {
        icon = player1_icon;
    }else
    {
        icon = player2_icon;
    }

    find_empty_cell();
    grid[icon_position_x][icon_position_y] = icon;
    display_grid();
    //sleep(1);
}

void display_grid()
{
    if (turn % 2 == 0)
    {
        printf("it's the turn of %s\n\n", player1_name);
    }else
    {
        printf("it's the turn of %s\n\n", player2_name);
    }
    for(int i = 0; i < 3; i++)
    {
        printf("\t\t");
        for(int j = 0; j < 5; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void change_player_pointer(char key)
{
    char icon;
    uint8_t player_matrix;
    uint8_t old_x, old_y;
    if (turn % 2 == 0)
    {
        icon = player1_icon;
        player_matrix = 1;
    }else
    {
        icon = player2_icon;
        player_matrix = 2;
    }
    
    flag_display_game = 1;
    old_x = icon_position_x;
    old_y = icon_position_y;

    switch (key)
	{
		case 'w':
            if (icon_position_x == 0) icon_position_x--;
			icon_position_x = (icon_position_x - 1) % 3;
			break;
		case 's':
            icon_position_x = (icon_position_x + 1) % 3;
			break;
        case 'a':
			icon_position_y = (icon_position_y - 2) % 5;
            if (icon_position_y == 254) icon_position_y = 4;
			break;
		case 'd':
            if (icon_position_y == 4) icon_position_y--;
            icon_position_y = (icon_position_y + 2) % 5;
            break;
		case ENTER:
            if (old_icon == ' ')
            {
                game_grid[icon_position_x][icon_position_y / 2] = player_matrix;
                flag_display_game = 0;
                turn++;
                turn_management();
            }
            break;
        default:
            flag_display_game = 0;
            break;
    }

    if (flag_display_game)
    {
        grid[old_x][old_y] = old_icon;
        old_icon = grid[icon_position_x][icon_position_y];
        if (grid[icon_position_x][icon_position_y] == ' ')
        {
            grid[icon_position_x][icon_position_y] = icon;
        }
        system(clear);
        display_grid();
        /*printf("x = %d, y = %d\n", icon_position_x, icon_position_y);
        printf("turn = %d\n", turn);
        printf("old_icon = %c\n", old_icon);*/
    }
}

void turn_management()
{
    char icon;
    if (turn % 2 == 0)
    {
        icon = player1_icon;
    }else
    {
        icon = player2_icon;
    }

    find_empty_cell();
    old_icon = ' ';
    grid[icon_position_x][icon_position_y] = icon;
    system(clear);
    display_grid();
}

void find_empty_cell()
{
    uint8_t i = 0,j = 0, found = 0;

    icon_position_x = 255;
    icon_position_y = 255;

    while (i < 3 && !found)
    {
        j = 0;
        while (j < 5 && !found)
        {
            if (grid[i][j] == ' ')
            {
                found = 1;
            }else
            {
                j++;
            }
        }
        if (!found)
        {
            i++;
        }
    }

    if (found)
    {
        icon_position_x = i;
        icon_position_y = j;
    }
}

uint8_t get_player_matrix(uint8_t x, uint8_t y)
{
    return game_grid[x][y];
}

char* get_player_name(uint8_t player)
{
    if (player == 1)
    {
        return player1_name;
    }else if (player == 2)
    {
        return player2_name;
    }else return NULL;
}
