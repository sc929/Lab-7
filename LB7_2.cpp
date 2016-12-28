#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream> //для cin, cout
using namespace std; //для cin, cout

struct Game // Структура - книга 
{
	char Studio[64];
	char Publisher[128];
	char Name[64];
	int Year;
};  int main(int argc, char* argv[])
{
	int n; // Переменная, задающая число элементов массива 
	Game *pBook; // Указатель на массив структур 
	FILE *pF;
	fopen_s(&pF, "C:\\Users\\Максим\\Desktop\\Visual\\MyBook.txt", "r");// Открываем файл для чтения в двоичном режиме 
	if (pF == 0) // Ошибка открытия файла, например, файл не существует 
	{
		cout << "Error, file not found" << endl;
		return 1;
	}
	fscanf(pF, "%d\n", &n); // Читаем из файла число элементов массива
	pBook = new Game[n]; // Выделяем память под массив структур (книг)
	for (unsigned int i = 0; i < n; i++)
		fscanf(pF, "%s\n%s\n%s\n%d\n",
			&pBook[i].Studio, &pBook[i].Publisher, &pBook[i].Name,
			&pBook[i].Year); // Читаем из файла массив книг
	fclose(pF); // Закрываем файл 
	for (int i = 0; i < n; i++) // Цикл вывода данных о книгах на экран
		cout << pBook[i].Studio << ". " << pBook[i].Publisher << ". " << pBook[i].Name << ". " << pBook[i].Year << "." << endl;
	_getch();  // Останавливаем программу до нажатия любой клавиши
	return 0;
}