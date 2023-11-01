#pragma once
#include"Song.h"

struct  SongCollection {
	Song* Songs;
	size_t size;

	void show();
	void add(Song song);
	void addByUser();
	void loadSong();
	void saveSong();
	void editSong();
	void deleteSong();
	void searchSongName();
};