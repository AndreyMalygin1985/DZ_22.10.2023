#include "Config.h"
#include <Windows.h>
#include"Menu.h"

void Config::init(Menu& menu)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu.add(1, "Показать сборник текстов песен");
	menu.add(2, "Добавить песню");
	menu.add(3, "Изменение текста песни");
	menu.add(4, "Удалить песню");
	menu.add(5, "Поиск и отображение песени по названию");
}