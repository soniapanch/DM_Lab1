#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define S 8
int parent[S];
int read_matrix(int cost[S][S]) {
	char line[2];
	ifstream in("l1_2.txt");
	printf("Розмiрнiсть матрицi: \n");
	if (in.is_open())
	{
		in.getline(line, 2);
		std::cout << line << std::endl;
		printf("Задана матриця: \n");
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				in >> cost[i][j];

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << cost[i][j] << "\t";
			cout << "\n";
		}

		in.close();
		printf("\n");
		return **cost;
	}
	else
	{
		cout << "Файл не знайдено.";
		return 0;
	}
}
int search(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void obyedn1(int i, int j)
{
	int x = search(i);
	int y = search(j);
	parent[x] = y;
}

void kruskalsol(int cost[][S])
{
	int mincost = 0; 
	for (int i = 0; i < S; i++)
		parent[i] = i;
	int edg_count = 0;
	while (edg_count < S - 1) {
		int min = INT_MAX, x = -1, y = -1;
		for (int i = 0; i < S; i++) {
			for (int j = 0; j < S; j++) {
				if (search(i) != search(j) && cost[i][j] < min && cost[i][j] > 0) {
					min = cost[i][j];
					x = i;
					y = j;
				}
			}
		}
		obyedn1(x, y);
		printf("Включене ребро %d:(%d-%d) Вага:%d \n", edg_count++, x, y, min);
		mincost += min;
	}
	printf("\nМiнiмальна цiна шляху= %d \n", mincost);
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	int cost[S][S];
	read_matrix(cost);
	kruskalsol(cost);
	system ("pause");
}