#include "dfs.h"

extern int low[VertexNum+1];
int start=1;

void main()
{
	int capacity=VertexNum;	 // �������
	AdjList adjList; // �ڽӱ�
	int row=VertexNum, i, j;	 							

	int adjArray[VertexNum][VertexNum] = 
	{
		{0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 0, 1, 1, 0},
		{0, 0, 0, 1, 0, 1, 0},
		{0, 0, 0, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 0},
	};
	
	// init adjacency list.
	adjList = init(capacity);	
	if(adjList==NULL)
	{
		return;
	}			
	printf("\n\n\t === reviww for DFS applie into biconnectivity graph ===");
	printf("\n\t === build adjacency list ===\n");	 
	for(i=0;i<row;i++)
	{		
		visited[i]=0;
		for(j=0; j<row; j++)
		{
			if(adjArray[i][j])
			{
				insertAdjList(adjList, i, j+1, adjArray[i][j]); // ����ڵ㵽�ڽӱ�.(����ͼȨֵΪȫ1)
			}
		}
	}
	printAdjList(adjList);
	
	// ʹ��dfs ��������ͼ.
	dfs_find_articulation(adjList, 1, 1);	

	printf("\n === low array ===\n ");
	printArray(low, VertexNum+1);

}