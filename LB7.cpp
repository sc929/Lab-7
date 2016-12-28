#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <list>
#include <iterator>
#include <iostream> //для cin, cout
using namespace std; //для cin, cout

struct Game // Структура - книга 
{
	char Studio[64];
	char Publisher[128];
	char Name[64];
	int Year;
};

int main(int argc, char* argv[])
{
	list<Game> myList;
	int n; // Переменная, задающая число элементов массива
	Game pBook; // Указатель на массив структур
	printf("n="); scanf_s("%d", &n); // Ввод числа книг
	//pBook = new Game; // Выделяем память под массив структур (книг)
	for (int i = 0; i < n; i++) // Цикл ввода данных о книгах с клавиатуры 
	{
		printf("Game N=%d:\n", i + 1);
		printf("Studio: ");
		cin >> pBook.Studio;
		printf("Publisher: ");
		cin >> pBook.Publisher;
		printf("Name: ");
		cin >> pBook.Name;
		printf("Year: ");
		scanf_s("%d", &pBook.Year);
		myList.push_back(pBook);
	}
	FILE *pF;
	fopen_s(&pF, "C:\\Users\\Максим\\Desktop\\Visual\\MyBook.txt", "w"); // Открываем файл для записи в двоичном режиме
	fprintf(pF, "%d\n", n); // Записываем в файл число элементов массива
	for (int i = 0; i < n; i++)
	{
		fprintf(pF, "%s\n%s\n%s\n%d\n", myList.front().Studio, myList.front().Publisher, myList.front().Name, myList.front().Year);
		myList.pop_front();
	}
	fclose(pF); // Закрываем файл 
	_getch(); // Останавливаем программу, ждем нажатия любой клавиши
	return 0; 
}
