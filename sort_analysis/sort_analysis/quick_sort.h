#pragma once
#include <iostream>
#include "Timer.h"
#include <fstream>

using namespace std;

void QuickSort(int* mas, int left, int right)
{
	int x = 0, l = left, r = right, temp;
	x = mas[(r + l) / 2];
	while (l < r)
	{
		while (mas[l] < x)
			l++;
		while (mas[r] > x)
			r--;
		if (l <= r)
		{
			temp = mas[r];
			mas[r] = mas[l];
			mas[l] = temp;
			l++; r--;
		}
	}
	if (left < r)
		QuickSort(mas, left, r);
	if (right > l)
		QuickSort(mas, l, right);

}

void save_mas(int* mas,int size,const char* file_name) {
	std::ofstream ofs(file_name);
	for (int i = 0; i < size; i++) {
		ofs << mas[i] << " ";
	}
	ofs.close();
}

void sortQuick(int* mas, int size, const char* file_name) {
	long float time = 0;
	std::ofstream ofs;
	Timer t;
	QuickSort(mas, 0, size - 1);
	time = t.elapsed();
	save_mas(mas, size, file_name);
	ofs.open(file_name, ios::app);
	ofs << "\n" << " Time:" << time << endl;
}

void sortQuick_with_time(int* mas, int size, const char* file_name) {
	long float time = 0;
	std::ofstream ofs;
	clock_t start = clock();
	QuickSort(mas, 0, size - 1);
	clock_t end = clock();
	ofs.open(file_name, ios::app);
	ofs << size << "  " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}