#include "kruskal.h"

extern void printBinaryHeap(BinaryHeap bh);

Edge* createEdges(int size)
{
	Edge* array = (Edge*)malloc(sizeof(Edge) * size);
	if(array==NULL)
	{
		Error("failed createEdges() for out of space.");
		return NULL;
	}
	return array;
}

void main()
{
	int capacity=7;	 // �������
	AdjList adjList; // �ڽӱ�
	int row=7, col=7, i, j;	 			
	BinaryHeap heap;
	int* setArray; // ���㼯������.
	Edge* edgeSet;

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
	printf("\n\n\t === revirw for dijkstra alg to compute weighted shortest path ===");
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

	// ���� ��³˹�����㷨Ѱ�� ��С������.
	// �� �ڽӱ������ ����
	heap = buildHeapWithAdjList(adjList);
	setArray = buildSet(capacity+1);
	edgeSet = createEdges(capacity-1); // ��Ϊ capacity �� ������� capacity-1����.
	if(heap==NULL || setArray==NULL || edgeSet==NULL)
	{
		return;
	}
	// printBinaryHeap(heap);				

	//�� Ȩֵ��С�ı߿�ʼ��
	kruskal(heap, setArray, edgeSet, capacity-1);  
	printf("\nafter kruskal alg, the results are : \n ");
	printEdgeSet(edgeSet, capacity-1);
}