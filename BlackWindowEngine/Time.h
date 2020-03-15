#pragma once
#include <Windows.h>


class Time
{
private:
	LARGE_INTEGER start, end, f;
	unsigned int fps = 0;
	float elapsed_time = 0;
public:
	float deltaTime = 0;

	void StartMeasure()
	{
		fps++;
		QueryPerformanceFrequency(&f);
		QueryPerformanceCounter(&start);
	}
	void EndMeasure()
	{
		elapsed_time += deltaTime;
		Sleep(100);
		QueryPerformanceCounter(&end);
		deltaTime = (end.QuadPart - start.QuadPart) / (float)f.QuadPart;
	}
};