#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <list>
#include <iterator>
#include <iostream> //��� cin, cout
using namespace std; //��� cin, cout

struct Game // ��������� - ����� 
{
	char Studio[64];
	char Publisher[128];
	char Name[64];
	int Year;
};

int main(int argc, char* argv[])
{
	list<Game> myList;
	int n; // ����������, �������� ����� ��������� �������
	Game pBook; // ��������� �� ������ ��������
	printf("n="); scanf_s("%d", &n); // ���� ����� ����
	//pBook = new Game; // �������� ������ ��� ������ �������� (����)
	for (int i = 0; i < n; i++) // ���� ����� ������ � ������ � ���������� 
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
	fopen_s(&pF, "C:\\Users\\������\\Desktop\\Visual\\MyBook.txt", "w"); // ��������� ���� ��� ������ � �������� ������
	fprintf(pF, "%d\n", n); // ���������� � ���� ����� ��������� �������
	for (int i = 0; i < n; i++)
	{
		fprintf(pF, "%s\n%s\n%s\n%d\n", myList.front().Studio, myList.front().Publisher, myList.front().Name, myList.front().Year);
		myList.pop_front();
	}
	fclose(pF); // ��������� ���� 
	_getch(); // ������������� ���������, ���� ������� ����� �������
	return 0; 
}
