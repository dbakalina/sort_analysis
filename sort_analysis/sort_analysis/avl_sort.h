#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Timer.h"
#include "avl_tree.h"
using namespace std;

void AVLSort_m(int* mas, int size, const char* file_name) {
	AvlTree tree;
	long float time = 0;
	std::ofstream ofs;
	Timer t;
	for (int i = 0; i < size; i++)
	{
		tree.Add(mas[i]);
	}
	tree.sort();
	time = t.elapsed();
	tree.Save(file_name);
	ofs.open(file_name, ios::app);
	ofs << " \n" << " Time:" << time << endl;
	tree.clean_tree();
}

void sort_with_AVL(int* mas, int size, const char* file_name) {
	AvlTree tree;
	long float time = 0, time2 = 0;
	std::ofstream ofs;
	clock_t start = clock();
	for (int i = 0; i < size; i++)
	{
		tree.Add(mas[i]);
	}
	tree.sort();
	clock_t end = clock();
	tree.clean_tree();
	ofs.open(file_name, ios::app);
	ofs << " " << size << "  " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}