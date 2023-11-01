#include "SongCollection.h"
#include "Song.h"
#include "Menu.h"
#include<iostream>
#include<stdio.h>

using namespace std;

void SongCollection::show()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "********************************************" << endl;
		Songs[i].show();
		cout << endl;
	}
}

void SongCollection::add(Song song)
{
	Song* temp = new Song[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = Songs[i];
	}
	delete[] Songs;
	Songs = temp;

	Songs[size] = song;
	size++;
}

void SongCollection::addByUser()
{
	Song temp{};
	temp.fillByUser();
	add(temp);
}

void SongCollection::saveSong()
{
	FILE* SongCollection{};
	fopen_s(&SongCollection, "SongCollection.txt", "w");
	if (SongCollection == NULL)
	{
		cout << "Ошибка сохранения в файл";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		fprintf(SongCollection, "%d\n", Songs[i].deadline.tm_year);
		fprintf(SongCollection, "%s\n", Songs[i].name_song);
		fprintf(SongCollection, "%s\n", Songs[i].text_song);
	}
	if (fclose(SongCollection) == EOF)
	{
		cout << "Ошибка закрытия файла";
	}
	return;
}

void SongCollection::loadSong()
{
	FILE* SongCollection{};
	fopen_s(&SongCollection, "SongCollection.txt", "r");
	if (SongCollection == NULL)
	{
		cout << "Ошибка открытия файла";
		return;
	}
	Song temp{};
	int scan_result;
	while (true)
	{
		scan_result = fscanf_s(SongCollection, "%d", &temp.deadline.tm_year);
		if (scan_result == EOF) {
			break;
		}
		scan_result = fscanf_s(SongCollection, "%s", &temp.name_song,256);
		if (scan_result == EOF) {
			break;
		}
		scan_result = fscanf_s(SongCollection, "%s", temp.text_song, 256);
		if (scan_result == EOF) {
			break;
		}
		add(temp);
	}

	if (fclose(SongCollection) == EOF)
	{
		cout << "Ошибка закрытия файла";
	}
}

void SongCollection::editSong()
{
	cout << "Укажите название песни для редактирования текста: " << endl;
	char temp[256]{};
	cin >> temp;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(temp, Songs[i].name_song) == 0)
		{
			cout << "Введите новый текст песни: ";
			cin >> Songs[i].text_song;

		}
	}
}

void SongCollection::searchSongName()
{
	cout << "Введите название песни для поиска" << endl;
	char temp[256]{};
	cin >> temp;

	int flag = 1;
	for (size_t i{}; i < size; i++)
	{
		if (strcmp(temp, Songs[i].name_song) == 0)
		{
			Songs[i].show();
		}
	}
}

void SongCollection::deleteSong()
{
	cout << "Укажите название песни для удаления" << endl;
	char temp[256]{};
	cin >> temp;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size - 1; j++)
		{
			Songs[j] = Songs[j + 1];
		}
		size--;
		cout << "Песня " << temp << " удалена" << endl;
	}
}