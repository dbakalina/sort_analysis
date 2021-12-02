#include <random>
#include  "avl_tree.h"
#include <time.h>
#include "avl_sort.h"
#include"quick_sort.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 1, elem;
	float time;
	int flag = 0;
	ifstream f, f2;
	ofstream ofs("data.txt", ios_base::out);
	ofstream res;
	cin >> size;
	int* mas_avl = new int[size];
	int* mas_qs = new int[size];
	int* mas = new int[size];

	for (int i = 0; i < size; i++) {
		mas[i] = rand() % 100000000;
		ofs << mas[i] << " ";
	}
	ofs.close();
	f.open("data.txt", ios_base::in);
	for (int i = 0; i < size; i++) {
		f >> elem;
		mas_qs[i] = elem;
		mas_avl[i] = elem;
		if (size < 20)
		{
			cout << " " << mas_avl[i];
		}
	}
	f.close();
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (size < 20)
		{
			cout << " " << mas_qs[i];
		}
	}
	cout << endl;
	AVLSort_m(mas_avl, size, "test_res_avl2.txt");
	sortQuick(mas_qs, size, "test_res_quick2.txt");
	return 0;
}