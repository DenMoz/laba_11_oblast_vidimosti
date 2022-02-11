#include<stdio.h>
#include<locale.h>
#include"header.h"
int main()
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		switch (main_menu())
		{
		case 1: input_data(); break;
		case 2: output_data(); break;
		case 3: output_certain_data; break;
		case 4: sort_data(); break;
		case 5: return 0; break;
		default: puts("Неверное значение. Попробуйте еще раз\n");
		}
		printf("\n");
	}
	return 0;
}