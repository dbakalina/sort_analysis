#include <time.h>
#include <algorithm>
#include "../sort_analysis/avl_sort.h"
#include "../sort_analysis/quick_sort.h"
#include "../sort_analysis/Timer.h"

bool compare(int a, int b) {
	return (a > b);
}

int gen_random(int range_min, int range_max) {

	if (range_min > range_max) {
		fprintf(stderr, "gen_random(): Invalid arguments\n"); exit(1);
	}

	return range_min + rand() % (range_max - range_min + 1);
}

void ascending(int* mas, int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				// меняем элементы местами
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
}

void descending(int* mas, int size) {
	int temp;
	for (int i = size; i != 0; --i)
	{
		for (int j = size; --j != size - i; )
		{
			if (mas[j - 1] < mas[j])
			{
				temp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = temp;
			}
		}
	}
}



void print_mas(int* mas, int size) {
	for (int i = 0; i < size; i++) {
		cout << mas[i] << "  ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int SIZE_1 = 0, SIZE_2 = 0;
	int h = 0;
	int choice, elem;
	int size = 0;
	int* mas_avl = 0;
	int* mas_qs = 0;
	int q, w;
	int rand_val;

	do {
		cout << "Меню:\n\n";
		cout << "\t\t Сортировки" << endl;
		cout << "\t\t 1.Задать число элементов." << endl;

		cout << "\t\t 2.Задать границы для значений элементов." << endl;

		cout << "\t\t 3.Заполнить массив псевдослучайными числами." << endl;
		cout << "\t\t 4.Заполнить числами по неубыванию." << endl;
		cout << "\t\t 5.Заполнить массив по невозрастанию." << endl;

		cout << "\t\t 6.Эксперимент 1 на массиве псевдослучайных чисел." << endl;
		cout << "\t\t 7.Эксперимент 1 на массиве упорядоченному по неубыванию." << endl;
		cout << "\t\t 8.Эксперимент 1 на массиве упорядоченному по невозрастанию." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: //Задать число элементов
		{
			cout << "Введите число элементов n:";
			cin >> size;
		}break;

		case 2: //Задать границы
		{
			cout << "Введите нижнюю границу w:";
			cin >> w;
			cout << "Введите верхнюю границу q:";
			cin >> q;
		}break;

		case 3: //псевдослучайные числа
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			srand(time(NULL));
			for (int i = 0; i < size; i++)
			{
				mas_avl[i] = gen_random(w, q);
				if (size < 20)
				{
					cout << " " << mas_avl[i];
				}
			}
			cout << endl;

			for (int i = 0; i < size; i++) {
				mas_qs[i] = gen_random(w, q);
				if (size < 20)
				{
					cout << " " << mas_qs[i];
				}
			}
			cout << endl;
		}break;

		case 4: //по неубыванию
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			//Заполнение массива случайными числами
			for (int i = 0; i < size; i++)
			{
				mas_avl[i] = gen_random(w, q);
			}
			cout << endl;
			for (int i = 0; i < size; i++) {
				mas_qs[i] = gen_random(w, q);
			}
			cout << endl;
			//упорядочивание по возрастанию
			ascending(mas_qs, size);
			ascending(mas_avl, size);
			if (size < 20)
			{
				print_mas(mas_qs, size);
				cout << endl;
				print_mas(mas_avl, size);
				cout << endl;
			}
		}break;

		case 5: //по невозрастанию
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			//Заполнение массива случайными числами
			for (int i = 0; i < size; i++)
			{
				mas_avl[i] = gen_random(w, q);
			}
			cout << endl;
			for (int i = 0; i < size; i++) {
				mas_qs[i] = gen_random(w, q);
			}
			cout << endl;
			sort(mas_qs, mas_qs + size, compare);
			sort(mas_avl, mas_avl + size, compare);
			if (size < 20)
			{
				print_mas(mas_qs, size);
				cout << endl;
				print_mas(mas_avl, size);
				cout << endl;
			}
		}break;

		case 6: //Сортировка
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			//mas_avl[size] = gen_random(w, q);
			cout << "Введите n для эксперимента:";
			cin >> SIZE_1;
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_avl[i] = gen_random(w, q);
				sort_with_AVL(mas_avl, i, "res_AVL_random_exp1_test2.txt");

			}

			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_qs[i] = gen_random(w, q);
				sortQuick_with_time(mas_qs, i, "res_quick_sort_random_exp1_test2.txt");
			}
		}break;
		case 7:
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			cout << "Введите  n для эксперимента:";
			cin >> SIZE_1;
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_avl[i] = gen_random(w, q);
				sort(mas_avl, mas_avl + size);
				sort_with_AVL(mas_avl, i, "res_AVL_ascending_exp1_test2.txt");
			}
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_qs[i] = gen_random(w, q);
				sort(mas_qs, mas_qs + size);
				sortQuick_with_time(mas_qs, i, "res_quick_sort_ascending_exp1_test2.txt");
			}

		}break;
		case 8:
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			cout << "Введите  n для эксперимента:";
			cin >> SIZE_1;
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_avl[i] = gen_random(w, q);
				sort(mas_avl, mas_avl + size, compare);
				sort_with_AVL(mas_avl, i, "res_AVL_descending_exp1_test2.txt");
			}
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_qs[i] = gen_random(w, q);
				sort(mas_qs, mas_qs + size, compare);
				sortQuick_with_time(mas_qs, i, "res_quick_sort_descending_exp1.txt");
			}
		}break;
		case 9:  //Второй экспер-т
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			cout << "Введите q для эксперимента:";
			cin >> q;
			cout << "Введите w для эксперимента:";
			cin >> SIZE_2;
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_avl[size] = gen_random(q, i);
				sort_with_AVL(mas_avl, size, "res_AVL_random_exp2_test3.txt");
			}
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_qs[size] = gen_random(q, i);
				sortQuick_with_time(mas_qs, size, "res_quick_sort_random_exp2.txt");
			}
		}break;
		case 10:
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			cout << "Введите q для эксперимента:";
			cin >> q;
			cout << "Введите w для эксперимента:";
			cin >> SIZE_2;
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_avl[size] = gen_random(q, i);
				sort(mas_avl, mas_avl + size);
				sort_with_AVL(mas_avl, size, "res_AVL_ascending_exp2_test3.txt");
			}
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_qs[size] = gen_random(q, i);
				sort(mas_qs, mas_qs + size);
				sortQuick_with_time(mas_qs, size, "res_quick_sort_ascending_exp2.txt");
			}
		}break;
		case 11:
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			cout << "Введите q для эксперимента:";
			cin >> q;
			cout << "Введите w для эксперимента:";
			cin >> SIZE_2;
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_avl[size] = gen_random(q, i);
				sort(mas_avl, mas_avl + size, compare);
				sort_with_AVL(mas_avl, size, "res_AVL_descending_exp2_test2.txt");
			}
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_qs[size] = gen_random(q, i);
				sort(mas_qs, mas_qs + size, compare);
				sortQuick_with_time(mas_qs, size, "res_quick_sort_descending_exp2.txt");
			}
			save_mas(mas_avl, size, "testres_exp2.txt");
		}break;
		case 12:
		{
			sort_with_AVL(mas_avl, size, "test_avl5.txt");
			//print_mas(mas_avl, size);
		}
		}
	} while (choice != 0);

	return 0;
}


//1000001
//1000000000

//1000000