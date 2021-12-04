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
				// ������ �������� �������
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

int* create_mas(int size,int w,int q)
{
	int* mas = new int[size];
	for (int i = 0; i < size; i++) {
		mas[i] = gen_random(w, q);
	}
	return mas;
}

void print_mas(int* mas, int size) {
	for (int i = 0; i < size; i++) {
		cout << mas[i] << "  ";
	}
	cout << endl;
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
		cout << "����:\n\n";
		cout << "\t\t 1.������ ����� ���������." << endl;

		cout << "\t\t 2.������ ������� ��� �������� ���������." << endl;
		cout << endl;
		cout << "\t\t 3.��������� ������ ���������������� �������." << endl;
		cout << "\t\t 4.��������� ������� �� ����������." << endl;
		cout << "\t\t 5.��������� ������ �� �������������." << endl;
		cout << endl;
		cout << "\t\t 6.����������� 1 �� ������� ��������������� �����." << endl;
		cout << "\t\t 7.����������� 1 �� ������� �������������� �� ����������." << endl;
		cout << "\t\t 8.����������� 1 �� ������� �������������� �� �������������." << endl;
		cout << endl;
		cout << "\t\t 9.����������� 2 �� ������� ��������������� �����." << endl;
		cout << "\t\t 10.����������� 2 �� ������� �������������� �� ����������." << endl;
		cout << "\t\t 11.����������� 2 �� ������� �������������� �� �������������." << endl;
		cout << endl;
		cout << "\t\t ��� ������ �� ���������� ������� 0." << endl;
		cout << "\n�������� ������ ��������: ";
		cin >> choice;

		switch (choice)
		{
		case 1: //������ ����� ���������
		{
			cout << "������� ����� ��������� n:";
			cin >> size;
		}break;

		case 2: //������ �������
		{
			cout << "������� ������ ������� w:";
			cin >> w;
			cout << "������� ������� ������� q:";
			cin >> q;
		}break;

		case 3: //��������������� �����
		{
			mas_avl = create_mas(size, w, q);
			mas_qs = create_mas(size, w, q);
			if (size < 20) {
				print_mas(mas_avl, size);
				print_mas(mas_qs, size);
			}
		}break;

		case 4: //�� ����������
		{
			mas_avl = create_mas(size, w, q);
			mas_qs = create_mas(size, w, q);
			//�������������� �� �����������
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

		case 5: //�� �������������
		{
			mas_avl = create_mas(size, w, q);
			mas_qs = create_mas(size, w, q);
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

		case 6: //����������
		{
			cout << "������� n ��� ������������:";
			cin >> SIZE_1;
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_avl = create_mas(i, w, q);
				sort_with_AVL(mas_avl, i, "res_AVL_random_exp1_test1.txt");

			}

			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_qs = create_mas(i, w, q);
				sortQuick_with_time(mas_qs, i, "res_quick_sort_random_exp1_test1.txt");
			}
		}break;
		case 7:
		{
			cout << "�������  n ��� ������������:";
			cin >> SIZE_1;
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_avl = create_mas(i, w, q);
				sort(mas_avl, mas_avl + i);
				sort_with_AVL(mas_avl, i, "res_AVL_ascending_exp1_test1.txt");
			}
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_qs = create_mas(i, w, q);
				sort(mas_qs, mas_qs + i);
				sortQuick_with_time(mas_qs, i, "res_quick_sort_ascending_exp1_test1.txt");
			}

		}break;
		case 8:
		{
			cout << "�������  n ��� ������������:";
			cin >> SIZE_1;
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_avl = create_mas(i, w, q);
				sort(mas_avl, mas_avl + i, compare);
				sort_with_AVL(mas_avl, i, "res_AVL_descending_exp1_test1.txt");
			}
			for (int i = 1; i <= SIZE_1; i += 10000)
			{
				mas_qs = create_mas(i, w, q);
				sort(mas_qs, mas_qs + i, compare);
				sortQuick_with_time(mas_qs, i, "res_quick_sort_descending_exp1_test1.txt");
			}
		}break;
		case 9:  //������ ������-�
		{
			cout << "������� q ��� ������������:";
			cin >> q;
			cout << "������� w ��� ������������:";
			cin >> SIZE_2;
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_avl = create_mas(size, q, i);
				sort_with_AVL(mas_avl, size, "res_AVL_random_exp2_test3.txt");
			}
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_qs = create_mas(size, q, i);
				sortQuick_with_time(mas_qs, size, "res_quick_sort_random_exp2.txt");
			}
		}break;
		case 10:
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			cout << "������� q ��� ������������:";
			cin >> q;
			cout << "������� w ��� ������������:";
			cin >> SIZE_2;
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_avl = create_mas(size, q, i);
				sort(mas_avl, mas_avl + size);
				sort_with_AVL(mas_avl, size, "res_AVL_ascending_exp2_test3.txt");
			}
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_qs = create_mas(size, q, i);
				sort(mas_qs, mas_qs + size);
				sortQuick_with_time(mas_qs, size, "res_quick_sort_ascending_exp2.txt");
			}
		}break;
		case 11:
		{
			mas_avl = new int[size];
			mas_qs = new int[size];
			cout << "������� q ��� ������������:";
			cin >> q;
			cout << "������� w ��� ������������:";
			cin >> SIZE_2;
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_avl = create_mas(size, q, i);
				sort(mas_avl, mas_avl + size, compare);
				sort_with_AVL(mas_avl, size, "res_AVL_descending_exp2.txt");
			}
			for (int i = 1; i <= SIZE_2; i++)
			{
				mas_qs = create_mas(size, q, i);
				sort(mas_qs, mas_qs + size, compare);
				sortQuick_with_time(mas_qs, size, "res_quick_sort_descending_exp2.txt");
			}
			save_mas(mas_avl, size, "test_res_exp2.txt");
		}break;
		}
	} while (choice != 0);

	return 0;
}


//1000001
//1000000000

//1000000