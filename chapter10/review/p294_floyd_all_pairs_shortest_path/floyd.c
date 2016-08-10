#include <stdio.h>
#include <limits.h>

#define ElementNum 4
#define MyMax 100000
void printArray(int array[ElementNum][ElementNum]);

// ���������㷨���� �������е�����·��.
// distance ���ڽӾ��� �� path ����ת��.
void floyd_all_pairs(int distance[ElementNum][ElementNum], int path[ElementNum][ElementNum])
{
	int i, j, k;

	for(k=0; k<ElementNum; k++)
	{
		for(i=0; i<ElementNum; i++)
		{
			for(j=0; j<ElementNum; j++)
			{
				if(distance[i][j] > distance[i][k] + distance[k][j])
				{
					distance[i][j] = distance[i][k] + distance[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	// �ڽӾ���
	int distance[ElementNum][ElementNum] = 
	{
		{0, 5, MyMax, 7},
		{MyMax, 0, 4, 2},
		{3, 3, 0, 2},
		{MyMax, MyMax, 1, 0},
	};
	int path[ElementNum][ElementNum] = 
	{
		{-1, -1, -1, -1},
		{-1, -1, -1, -1},
		{-1, -1, -1, -1},
		{-1, -1, -1, -1},
	};
	// ���������㷨���� �������е�����·��.
	floyd_all_pairs(distance, path);
	
	// ��ӡ floyd �� ������.
	printf("\n\t === distance array are as follows.===\n");
	printArray(distance);

	printf("\n\t === path array are as follows.===\n");
	printArray(path);	
}

void printArray(int array[ElementNum][ElementNum])
{
	int i, j;

	for(i=0; i<ElementNum; i++)
	{
		for(j=0; j<ElementNum; j++)
		{
			printf("%3d, ", array[i][j]);
		}
		printf("\n");
	}
}