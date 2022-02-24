#pragma once
struct orders
{
	int orderId;						// идентификационный номер заказа
	char orderName[30];					// наименование деталей в заказе
	int totalDetails;					// общее количество деталей
	int usableDetails;				    // количество годных деталей
	double percentOfUsable;				// процент годных деталей
};
typedef orders data;

extern int main_menu();
extern void input_data();
static void checkDetails(data*, int);   // функция для проверки того, не является ли введенное количество годных деталей 
										// больше полного количества деталей
extern void output_data();

extern void output_certain_data();
static int checkNumber();

extern void sort_data();
static int menu();
static void sort_by_ID();
static void sort_by_name();
static void sort_by_total();			// отсортировать по общему количеству деталей
static void sort_by_usable();			// отсортировать по количеству годных деталей
static void sort_by_percentage();		// отсортировать по проценту годных деталей


