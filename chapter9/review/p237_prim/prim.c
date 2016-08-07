#include "dijkstra.h"

extern BinaryHeap buildHeap(int capacity);

void main()
{
	int capacity=7;	 // �������
	AdjList adjList; // �ڽӱ�
	int row=7, col=7, i, j;	 
	BinaryHeap heap; // ��ʼ�������.
	int start = 1; // ��ʼ����Ϊ3.	
	UnWeightedTable table;

	int adjArray[7][7] = 
	{
		{0, 2, 4, 1, 0, 0, 0},
		{2, 0, 0, 3, 10, 0, 0},
		{4, 0, 0, 2, 0, 5, 0},
		{1, 3, 2, 0, 7, 8, 4},
		{0, 10, 0, 7, 0, 0, 6},
		{0, 0, 5, 8, 0, 0, 1},
		{0, 0, 0, 4, 6, 1, 0}
	};
	
	// init adjacency list.
	adjList = init(7);	
	if(adjList==NULL)
	{
		return;
	}			
	printf("\n\n\t === review for prim alg to find minimum spanning tree ===");
	printf("\n\t === build adjacency list ===\n");	 
	for(i=0;i<row;i++)
	{		
		for(j=0; j<row; j++)
		{
			if(adjArray[i][j])
			{
				insertAdjList(adjList, i, j+1, adjArray[i][j]); // ����ڵ㵽�ڽӱ�.
			}
		}
	}
	printAdjList(adjList);

	// ���� �ؽ�˹������ ��Ȩ���·��.
	table = initUnWeightedTable(capacity);
	heap = buildHeap(10); // ��ʼ�������.
	prim(adjList, table, 1, heap); // startVertex=1.
	printWeightedtable(table, 1);
}