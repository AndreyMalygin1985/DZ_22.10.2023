#pragma once
#include<ctime>

struct Song {
	char name_song[256];
	char text_song[2222];
	tm deadline;

	void show();
	void fillByUser();
};