#include "menu.h"

uint8_t flag_display_menu = 1;
char menu_pointer[] = {254, ' '};
const char menu_icon = 254;

static uint8_t position = 0;
static const uint8_t menu_pointer_size = sizeof(menu_pointer) / sizeof(menu_pointer[0]);

void display_main_menu()
{
    printf("\t\t\tTRIS\n");
    printf("\t\t%c NEW GAME\n", menu_pointer[0]);
    printf("\t\t%c EXIT\n", menu_pointer[1]);
}

void change_pointer_position(uint8_t pos)
{
    if (pos == 1)
    {
        position = (position + 1) % menu_pointer_size;
    }else
    {
        position = -(position - 1) % menu_pointer_size;
    }

    for (int i = 0; i < menu_pointer_size; i++)
    {
        if (i == position)
        {
            menu_pointer[i] = menu_icon;
        }else
        {
            menu_pointer[i] = ' ';
        }
    }
}

uint8_t get_pointer_position()
{
    return position;
}