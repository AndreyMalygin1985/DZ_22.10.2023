#include "Song.h"
#include <iostream>
#include <ctime>

using namespace std;

void Song::show()
{
	cout << "��� �����: " << deadline.tm_year << endl;
	cout << "�������� �����: " << name_song << endl;
	cout << "����� �����: " << text_song << endl;
}

void Song::fillByUser()
{
	cout << "������� ��� �����: ";
	cin >> deadline.tm_year;
	cout << "������� �������� �����: ";
	cin >> name_song;
	cout << "������� ����� �����: ";
	cin >> text_song;
}