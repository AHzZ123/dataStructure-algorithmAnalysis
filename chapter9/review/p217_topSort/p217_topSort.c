#include "adjList.h"

void main()
{
	int capacity=7;	 // �������
	AdjList adjList;
	int row=7, col=3, i, j;
	int indegreeArray[7]; // ÿ��������������.
	Queue queue = initQueue(10);

	int adjArray[7][3] = 
	{
		{2, 4, 3},
		{4, 5, 0},
		{6, 0, 0},
		{6, 7, 3},
		{4, 7, 0},
		{0, 0, 0},
		{6, 0, 0}
	};
	
	// init adjacency list.
	adjList = init(7);	
	if(adjList==NULL)
	{
		return;
	}			
	
	printf("\n\n\t ====== review for topological sorting with adjacency list ======\n");			
	for(i=0; i<row; i++)
	{
		indegreeArray[i]=0;
	}
	for(i=0;i<row;i++)
	{		
		for(j=0;j<col;j++)
		{
			if(adjArray[i][j])
			{
				insertAdjList(adjList, i, adjArray[i][j]); // ����ڵ㵽�ڽӱ�.
				indegreeArray[adjArray[i][j]-1]++; // ����ÿ���ڵ�����.
			}
		}
	}
	printAdjList(adjList);
	printf("\n\t indegreeArray[] = ");
	printArray(indegreeArray, capacity);

	// ����������������õ��˶���, �ڽӱ�.
	topSort(adjList, queue, indegreeArray);
}