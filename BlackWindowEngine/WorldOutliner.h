#pragma once
#include<iostream>
#include<vector>
#include <Windows.h>

#include "Object.h"

using namespace std;

class WorldOutliner
{
private:
	vector<Object> object;

public:
	// add Obgect

	Object findObject(string name) {

	}
};
class Tools
{
public:

	void cersorMoveTo(Position p)
	{
		COORD position = { p.x, p.y };
		static HANDLE handle;
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(handle, position);
	}
	void backCersor() {
		cersorMoveTo({ 0, 0 });
	}

};
