#include<stdio.h>
#include<stdlib.h>
#include"header.h"
data* order;
data* temp;
int amount;						 // êîëè÷åñòâî çàïèñåé î çàêàçàõ
extern int main_menu()
{
	printf("1-ââåñòè äàííûå î çàêàçàõ\n2-âûâåñòè äàííûå î çàêàçàõ\n");
	printf("3-âûâåñòè äàííûå î îïðåäåëåííîì çàêàçå\n4-îòñîðòèðîàòü çàïèñè\n");
	printf("5-âûõîä èç ïðîãðàììû\nÂàø âûáîð?\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}
extern void input_data()
{
	register int count;
	printf("Ââåäèòå êîëè÷åñòâî çàïèñåé, êîòîðûå íåîáõîäèìî ââåñòè\n");
	scanf_s("%d", &amount);
	order = (data*)malloc(amount * sizeof(data));
	temp = (data*)malloc(amount * sizeof(data));
	if (order == NULL)
	{
		printf("Íåâîçìîæíî âûäåëèòü ïàìÿòü\n"); exit(0);
	}
	const static int percent = 100;
	for (count = 0; count < amount; count++)
	{
		printf("Ââåäèòå èäåíòèôèêàöèîííûé íîìåð %d-ãî çàêàçà: ", count + 1);
		scanf_s("%d", &order[count].orderId);
		printf("Ââåäèòå íàèìåíîâàíèå äåòàëåé èç %d-ãî çàêàçà: ", count + 1);
		getchar();
		gets_s(order[count].orderName);
		puts("Ââåäèòå êîëè÷åñòâî âñåõ äåòàëåé: ");
		scanf_s("%d", &order[count].totalDetails);
		puts("Ââåäèòå êîëè÷åñòâî ãîäíûõ äåòàëåé: ");
		scanf_s("%d", &order[count].usableDetails);
		order[count].percentOfUsable = (static_cast<double>(order[count].usableDetails) / order[count].totalDetails) * percent;
	}
}
extern void output_data()
{
	register int count;
	printf("\n");
	printf("¹   Íàçâàíèå  Îáùåå êîë-âî  Êîë-âî ãîäíûõ  Ïðîöåíò ãîäíûõ\n");
	printf("******************************************************\n");
	for (count = 0; count < amount; count++)
	{
		printf("%d %s %12d %16d %16lf.3", order[count].orderId, order[count].orderName, order[count].totalDetails,
			order[count].usableDetails, order[count].percentOfUsable);
		printf("\n");
	}
	printf("\n");
}
extern void output_certain_data()
{
	register int orderNumber, count;
	printf("Ââåäèòå íîìåð çàïèñè, êîòîðóþ õîòèòå ââåñòè\n");
	scanf_s("%d", &orderNumber);
	for (count = 0; count < amount; count++)
	{
		if (orderNumber == order[count].orderId)
		{
			printf("¹   Íàçâàíèå  Îáùåå êîë-âî  Êîë-âî ãîäíûõ  Ïðîöåíò ãîäíûõ\n");
			printf("******************************************************\n");
			printf("%d %s %12d %18d %16lf", order[orderNumber - 1].orderId, order[orderNumber - 1].orderName, order[orderNumber - 1].totalDetails,
				order[orderNumber - 1].usableDetails, order[orderNumber - 1].percentOfUsable);
			printf("\n");
		}
	}
	
}
static bool checkNumber(int num)
{
	bool state = false;
	while (!state)
	{
		if (num==0) printf("Íóìåðàöèÿ çàêàçîâ íà÷èíàåòñÿ ñ 1\n");
		else if (num > amount) printf("Íåòó òàêîé çàïèñè\n");
		else state = true;
	}
	return state;
}
