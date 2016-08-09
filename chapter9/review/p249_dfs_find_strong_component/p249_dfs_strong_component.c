#include "dfs.h"

extern ElementType createHeapNode(int index,int value);
extern BinaryHeap initBinaryHeap(int capacity);
extern void insert(ElementType value, BinaryHeap bh);
extern int isEmpty(BinaryHeap bh);
extern ElementType deleteMin(BinaryHeap);
extern void printBinaryHeap(BinaryHeap bh);

void main()
{
	int capacity=VertexNum;	 // �������
	AdjList adjList; // �ڽӱ�
	AdjList adjListReverse; // �����ڽӱ�
	BinaryHeap heap; // �����, ��������ѡȡ ������ı�. �ѽڵ������ǽṹ��, ��ΪҪ�洢�����źͶ�Ӧ�ı��������.
	int row=VertexNum, col=3, i, j;	 							
	int vertex;

	int adjArray[VertexNum][VertexNum] = 
	{
		{2, 4, 0}, // A
		{3, 6, 0}, // B
		{1, 4, 5}, // C
		{5, 0, 0}, // D
		{0, 0, 0}, // E
		{3, 0, 0}, // F
		{6, 8, 0}, // G
		{6, 10, 0}, // H
		{8, 0, 0}, // I
		{9, 0, 0}, // J
	};
	
	// init adjacency list.
	adjList = init(capacity);	
	if(adjList==NULL)
	{
		return;
	}			
	printf("\n\n\t === reviww for DFS applie into directed graph ===");
	printf("\n\t === build adjacency list ===\n");	 
	for(i=0;i<row;i++)
	{				
		for(j=0; j<col; j++)
		{
			if(adjArray[i][j])
			{
				insertAdjList(adjList, i, adjArray[i][j], adjArray[i][j]); // ����ڵ㵽�ڽӱ�.(����ͼȨֵΪȫ1)
			}
		}
	}
	printAdjList(adjList);
	
	// ʹ�� dfs ����ǿ��ͨ��֧.
	// step1: ����dfs ���� ����ͼG���Զ���ķ���˳����.
	printf("\n=== dfs_find_directed_graph(adjList, 2, 1) ===\n");
	dfs_find_strong_component(adjList, 2, 1);	 // start=1.
	for(i=1; i<=VertexNum; i++)
	{
		if(!visited[i])
		{
			printf("\n");
			dfs_find_strong_component(adjList, i, 1);
		}
	}// step1 over.
	printf("\n\t === num array are as follows. ===");
	printArray(num, VertexNum+1);		

	//step2: ��G�����б߷��� -> Gr.
	adjListReverse = init(capacity);	
	if(adjListReverse==NULL)
	{
		return;
	}				
	printf("\n\t === build reverse adjacency list ===\n");
	for(i=0;i<row;i++)
	{			
		for(j=0; j<col; j++)
		{
			if(adjArray[i][j])
			{
				insertAdjList(adjListReverse, adjArray[i][j]-1, i+1, adjArray[i][j]); // ����ڵ㵽�ڽӱ�.(����ͼȨֵΪȫ1)
			}
		}
	} // step2 over.
	printAdjList(adjListReverse);	 

	// step3: ��������Ķ��㿪ʼ�����ζ�Gr ���� dfs.��������Ҫ����һ������ѣ�	
	// step3.1: ����num[] ���������
	heap = initBinaryHeap(VertexNum+1); // ��Ϊ0���±겻��.
	for(i=1; i<=VertexNum; i++)
	{
		insert(createHeapNode(i, num[i]), heap);
		// ��ʼ������Ϊ0
		visited[i] = 0;
		num[i] = 0;				
		parent[i] = 0;	
	} // step3.1 over.
	printf("\n\t === binary heap is as follows.===");
	printBinaryHeap(heap);
	counter=0; // ��ʼ��count=0��

	// step3.2 ����ѡȡ �����ŵĶ������dfs
	printf("\n=== dfs_find_strong_component(adjListReverse, deleteMin(heap).index, 1) ===\n");
	
	while(!isEmpty(heap) && counter!=VertexNum)
	{			
		vertex = deleteMin(heap).index; // ����ѡȡ ��������ŵĶ���.		
		if(!visited[vertex]) // ����ö���û�б����ʵĻ�.
		{
			dfs_find_strong_component(adjListReverse, vertex, 1);
		}		
	}	
}