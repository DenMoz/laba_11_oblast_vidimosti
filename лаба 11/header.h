#pragma once
struct orders
{
	int orderId;                 // ����������������� ����� ������
	char orderName[30];			 // ������������ ������� � ������
	int totalDetails;			 // ����� ���������� �������
	int usableDetails;           // ���������� ������ �������
	double percentOfUsable;      // ������� ������ �������
};
typedef orders data;

extern int main_menu();
extern void input_data();
extern void output_data();

extern void output_certain_data();
static bool checkNumber(int);

extern void sort_data();
static int menu();
static void sort_by_ID();
static void sort_by_name();
static void sort_by_total();	  // ������������� �� ������ ���������� �������
static void sort_by_usable();     // ������������� �� ���������� ������ �������
static void sort_by_percentage(); // ������������� �� �������� ������ �������

