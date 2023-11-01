#include "Song.h"
#include <iostream>
#include <ctime>

using namespace std;

void Song::show()
{
	cout << "Год песни: " << deadline.tm_year << endl;
	cout << "Название песни: " << name_song << endl;
	cout << "Текст песни: " << text_song << endl;
}

void Song::fillByUser()
{
	cout << "Укажите год песни: ";
	cin >> deadline.tm_year;
	cout << "Укажите название песни: ";
	cin >> name_song;
	cout << "Введите текст песни: ";
	cin >> text_song;
}