#include<stdio.h>
#include<stdlib.h>
#include"header.h"
data* order;
data *temp;
int amount;						 // количество записей о заказах
extern int main_menu()
{
	printf("1-ввести данные о заказах\n2-вывести данные о заказах\n");
	printf("3-вывести данные о определенном заказе\n4-отсортироать записи\n");
	printf("5-выход из программы\nВаш выбор?\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}
extern void input_data()
{
	register int count;
	printf("Введите количество записей, которые необходимо ввести\n");
	scanf_s("%d", &amount);
	order = (data*)malloc(amount * sizeof(data));
	temp = (data*)malloc(amount * sizeof(data));
	if (order==NULL)
	{
		printf("Невозможно выделить память\n"); exit(0);
	}
	const static int percent = 100;
	for (count = 0; count < amount; count++)
	{
		printf("Введите идентификационный номер %d-го заказа: ", count + 1);
		scanf_s("%d", &order[count].orderId);
		printf("Введите наименование деталей из %d-го заказа: ", count + 1);
		getchar();
		gets_s(order[count].orderName);
		printf("Введите количество всех деталей: ");
		scanf_s("%d", &order[count].totalDetails);
		checkDetails(order, count);
		printf("\n\n");
		order[count].percentOfUsable = (static_cast<double>(order[count].usableDetails) / order[count].totalDetails) * percent;
	}
}
extern void output_data()
{
	register int count;
	printf("\n");
	printf("№   Название  Общее кол-во  Кол-во годных  Процент годных\n");
	printf("******************************************************\n");
	for (count = 0; count < amount; count++)
	{
		printf("%d %s %12d %12d %20lf", order[count].orderId, order[count].orderName, order[count].totalDetails,
			order[count].usableDetails, order[count].percentOfUsable);
		printf("\n");
	}
	printf("\n");
}
extern void output_certain_data()
{
	register int orderNumber;
	orderNumber=checkNumber();
	printf("№   Название  Общее кол-во  Кол-во годных  Процент годных\n");
	printf("******************************************************\n");
	printf("%d %s %12d %12d %20lf", order[orderNumber - 1].orderId, order[orderNumber - 1].orderName, order[orderNumber - 1].totalDetails,
		order[orderNumber - 1].usableDetails, order[orderNumber - 1].percentOfUsable);
	printf("\n");
}
static int checkNumber()
{
	register int num;
	bool state =false;
	while (!state)
	{
		puts("Введите номер записи, которую хотите вывести");
		scanf_s("%d", &num);
		if (num <= 0) printf("Нумерация заказов начинается с 1\n");
		else if (num > amount) printf("Нету такой записи\n"); 
		else state = true; 
	}
	return num;
}
static void checkDetails(data* details, int counter)
{
	printf("Введите количество годных деталей: ");
	scanf_s("%d", &order[counter].usableDetails);
	while (order[counter].totalDetails < order[counter].usableDetails)
	{
		puts("Количество годных деталей должно быть не больше их общего количества. Введите еще раз ");
		scanf_s("%d", &order[counter].usableDetails);
	}
}
