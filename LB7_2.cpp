#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream> //��� cin, cout
using namespace std; //��� cin, cout

struct Game // ��������� - ����� 
{
	char Studio[64];
	char Publisher[128];
	char Name[64];
	int Year;
};  int main(int argc, char* argv[])
{
	int n; // ����������, �������� ����� ��������� ������� 
	Game *pBook; // ��������� �� ������ �������� 
	FILE *pF;
	fopen_s(&pF, "C:\\Users\\������\\Desktop\\Visual\\MyBook.txt", "r");// ��������� ���� ��� ������ � �������� ������ 
	if (pF == 0) // ������ �������� �����, ��������, ���� �� ���������� 
	{
		cout << "Error, file not found" << endl;
		return 1;
	}
	fscanf(pF, "%d\n", &n); // ������ �� ����� ����� ��������� �������
	pBook = new Game[n]; // �������� ������ ��� ������ �������� (����)
	for (unsigned int i = 0; i < n; i++)
		fscanf(pF, "%s\n%s\n%s\n%d\n",
			&pBook[i].Studio, &pBook[i].Publisher, &pBook[i].Name,
			&pBook[i].Year); // ������ �� ����� ������ ����
	fclose(pF); // ��������� ���� 
	for (int i = 0; i < n; i++) // ���� ������ ������ � ������ �� �����
		cout << pBook[i].Studio << ". " << pBook[i].Publisher << ". " << pBook[i].Name << ". " << pBook[i].Year << "." << endl;
	_getch();  // ������������� ��������� �� ������� ����� �������
	return 0;
}