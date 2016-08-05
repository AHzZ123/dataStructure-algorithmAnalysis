#include "p220_unweighted_shortest_path.h"

void main()
{
	int capacity=7;	 // �������
	AdjList adjList; // �ڽӱ�
	int row=7, col=4, i, j;	
	Queue queue = initQueue(10); // ����
	int start = 3; // ��ʼ����Ϊ3.
	UnweightedTable table;

	int adjArray[7][4] = 
	{
		{2, 4, 0, 0},
		{4, 5, 0, 0},
		{1, 6, 0, 0},
		{3, 5, 6, 7},
		{7, 0, 0, 0},
		{0, 0, 0, 0},
		{6, 0, 0, 0}
	};
	
	// init adjacency list.
	adjList = init(7);	
	if(adjList==NULL)
	{
		return;
	}			
	printf("\n\t === review for computing unweighted shortest path ===");	 
	printf("\n\n\t === build adjacency list ===\n");	 
	for(i=0;i<row;i++)
	{		
		for(j=0;j<col;j++)
		{
			if(adjArray[i][j])
			{
				insertAdjList(adjList, i, adjArray[i][j]); // ����ڵ㵽�ڽӱ�.				
			}
		}
	}
	printAdjList(adjList);

	table=initUnweightedTable(capacity);
	unweighted_shortest_path(adjList, table, 3, queue); // startVertex=3.

	printUnweightedtable(table, 3);
}