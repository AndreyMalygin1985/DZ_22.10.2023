#include<iostream>
#include<Windows.h>
#include<ctime>
#include<chrono>
#include"Song.h"
#include"SongCollection.h"
#include"Menu.h"
#include"Config.h"

using namespace std;

int main()
{
	Menu menu{};
	SongCollection songs{};
	Config config{};
	config.init(menu);

	songs.loadSong();
	cout << endl;
	while (menu.show())
	{
		switch (menu.lastChoise)
		{
		case 1:
			songs.show();
			break;
		case 2:
			songs.addByUser();
			break;
		case 3:
			songs.editSong();
			break;
		case 4:
			songs.deleteSong();
			break;
		case 5:
			songs.searchSongName();
			break;
		default:
			break;
		}
	}
	songs.saveSong();
	return 0;
}