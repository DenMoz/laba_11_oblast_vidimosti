#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
extern data* order;
extern data* temp;
extern int amount;
extern void sort_data()
{
	setlocale(LC_ALL, "rus");
	switch (menu())
	{
	case 1: sort_by_ID(); break;
	case 2: sort_by_name(); break;
	case 3: sort_by_total(); break;
	case 4: sort_by_usable(); break;
	case 5: sort_by_percentage(); break;
	default: puts("Ќеверное значение. ѕопробуйте еще раз\n");
	}
	printf("\n");
}
static int menu()
{
	setlocale(LC_ALL, "rus");
	printf("1-отсортировать по ID\n2-отсортировать по наименованию деталей заказа\n");
	printf("3-отсортировать по общему количеству деталей\n4-отсортировать по количеству годных деталей\n");
	printf("5-отсортировать по проценту годных деталей\n¬аш выбор?\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}
static void sort_by_ID()
{
	register int count, iterations;
	for (iterations = 0; iterations < amount; iterations++)
	{
		for (count = 0; count < amount - 1; count++)
		{
			if (order[count].orderId > order[count + 1].orderId)
			{
				temp[count] = order[count];
				order[count] = order[count + 1];
				order[count + 1] = temp[count];
			}
		}
	}
	output_data();
}
static void sort_by_name()
{
	register int count, iterations;
	for (iterations = 0; iterations < amount; iterations++)
	{
		for (count = 0; count < amount - 1; count++)
		{
			if (strcmp(order[count].orderName, order[count + 1].orderName) > 0)
			{
				temp[count] = order[count];
				order[count] = order[count + 1];
				order[count + 1] = temp[count];
			}
		}
	}
	output_data();
}
static void sort_by_total()
{
	register int count, iterations;
	for (iterations = 0; iterations < amount; iterations++)
	{
		for (count = 0; count < amount - 1; count++)
		{
			if (order[count].totalDetails > order[count + 1].totalDetails)
			{
				temp[count] = order[count];
				order[count] = order[count + 1];
				order[count + 1] = temp[count];
			}
		}
	}
	output_data();
}
static void sort_by_usable()
{
	register int count, iterations;
	for (iterations = 0; iterations < amount; iterations++)
	{
		for (count = 0; count < amount - 1; count++)
		{
			if (order[count].usableDetails > order[count + 1].usableDetails)
			{
				temp[count] = order[count];
				order[count] = order[count + 1];
				order[count + 1] = temp[count];
			}
		}
	}
	output_data();
}
static void sort_by_percentage()
{
	register int count, iterations;
	for (iterations = 0; iterations < amount; iterations++)
	{
		for (count = 0; count < amount - 1; count++)
		{
			if (order[count].percentOfUsable > order[count + 1].percentOfUsable)
			{
				temp[count] = order[count];
				order[count] = order[count + 1];
				order[count + 1] = temp[count];
			}
		}
	}
	output_data();
}
