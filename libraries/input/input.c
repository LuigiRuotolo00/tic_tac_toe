#include "input.h"

//uint8_t is_key_pressed = 0;

int getch(void)
{
	struct termios oldt, newt;
	uint8_t ch;

	tcgetattr(STDIN_FILENO, &oldt); //save current settings
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO); //disabilità input canonico ed echo
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	ch = getchar(); //legge carattere

	tcsetattr(STDIN_FILENO, TCSANOW, &newt); //rimpristina impostazioni vecchie

	return ch;
}

uint8_t kbhit()
{
	struct termios oldt, newt;

	int chr, oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	//newt.c_cflag &= ~(ICANON | ECHO);
	newt.c_lflag &= ~(ICANON | ECHO);

	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	//oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	//fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	chr = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	//fcntl(STDIN_FILENO, F_SETFL, oldf);

	/*if (chr != -1)
	{
		ungetc(chr, stdin);
		return 1;
	}*/

	return chr;
}

void interrupt_handler()
{
	printf("\e[?25h");
	exit(1);
}