#include "adjList.h"

extern void insert(BinaryHeap heap, ElementType data);
extern ElementType deleteMin(BinaryHeap heap);
extern int isEmpty(BinaryHeap heap);

UnWeightedTable initUnWeightedTable(int size);
void prim(AdjList adj, UnWeightedTable table, int startVertex, BinaryHeap heap);
void printWeightedtable(UnWeightedTable table, int startVertex);

//allocate the memory for initializing unweighted table
UnWeightedTable initUnWeightedTable(int size)
{	
	int i;
	UnWeightedTable table = (UnWeightedTable)malloc(sizeof(struct UnWeightedTable));
	
	if(table==NULL)
	{
		Error("failed initUnweightedTable() for out of space.");
		return NULL;
	}
	table->size = size;
	
	table->array = (Entry*)malloc(size * sizeof(Entry));	
	if(table->array==NULL)
	{
		Error("failed initUnweightedTable() for out of space.");
		return NULL;
	}

	for(i=0; i<size; i++)
	{
		table->array[i] = (Entry)malloc(sizeof(struct Entry));
		if(table->array[i]==NULL)
		{
			Error("failed initUnweightedTable() for out of space.");
			return NULL;
		}
		table->array[i]->known = 0; // known ���� 0 or 1 ��ʾ δ֪ or ��֪.
		table->array[i]->dv= INT_MAX; // dv==distance ���� INT_MAX ��ʾ���ɴ�.(��Ȩ·����ʾweight)
		table->array[i]->pv = 0; // pv==path ���� 0 Ҳ��ʾ���ɴ�.
	}
	return table;
} 

// ���е������ıߵ�Ȩֵ��С.
// adj:�ڽӱ�ͼ�ı�׼��ʾ������, table: ������Ȩ���·�������ñ�heap������ѡȡ��СȨֵ���ڽӶ����С����.
void prim(AdjList adj, UnWeightedTable table, int startVertex, BinaryHeap heap)
{		
	int capacity=adj->capacity;
	Vertex* arrayVertex = adj->array;
	Vertex temp;
	Entry* arrayEntry = table->array;
	int index; // �����ʶ��(��0��ʼȡ)
	int adjVertex;
	struct HeapNode node;
	int weight;

	//step1(��ʼ״̬): startVertex ��������. startVertex ��1 ��ʼȡ.
	node.vertex=startVertex-1; // ����ѵ� node.vertex �� 0 ��ʼȡ������startVertex-1.
	node.weight=0;
	insert(heap, node); // �����.
	arrayEntry[startVertex-1]->dv=0;
	arrayEntry[startVertex-1]->pv=0;
	// ��ʼ״̬over.

	// step2: �Ѳ�Ϊ�գ�ִ�� deleteMin����. ������ɾ��������ڽӶ�������.
	while(!isEmpty(heap))
	{		
		index = deleteMin(heap).vertex;  // index��ʾ�ڽӱ��±꣬��0��ʼȡ���μ�����ѵĲ���.
		arrayEntry[index]->known=1; // �Ӷ�ȡ���󣬽��� known ����Ϊ1.
		temp = arrayVertex[index];		
		while(temp->next) 
		{
			adjVertex = temp->next->index; // ����index ���ڽӽڵ��ʶ��adjVertex ��1��ʼȡ.
			weight = temp->next->weight; // ����index�����ڽӶ��� ��Ȩֵ.

			if(arrayEntry[adjVertex-1]->known == 0) // ע��: �±���adjVertex-1, ��known==0 ���� adjVertex���㻹����δ֪״̬,����adjVertex�����.
			{
				// prim �㷨�Ĵ���汾.
				if(arrayEntry[adjVertex-1]->dv > weight ) // [key code] ����ǰȨֵ�� �� ֮ǰȨֵ�� С��ʱ�� �Ÿ��£����򲻸���.
				{
					node.vertex=adjVertex-1; // ����ѵ� node.vertex �� 0 ��ʼȡ.
					node.weight=weight;
					insert(heap, node); // �����.
					arrayEntry[adjVertex-1]->dv = weight; // [also key code]					
					arrayEntry[adjVertex-1]->pv=index+1; // index ��0��ʼȡ������index��1.	
				}
				
				/* dijkstra �㷨�Ĵ���汾.
				if(arrayEntry[adjVertex-1]->dv > arrayEntry[index]->dv + weight ) // [key code] ����ǰȨֵ�� �� ֮ǰȨֵ�� С��ʱ�� �Ÿ��£����򲻸���.
				{
					node.vertex=adjVertex-1; // ����ѵ� node.vertex �� 0 ��ʼȡ.
					node.weight=weight;
					insert(heap, node); // �����.
					arrayEntry[adjVertex-1]->dv = arrayEntry[index]->dv + weight; // [also key code]					
					arrayEntry[adjVertex-1]->pv=index+1; // index ��0��ʼȡ������index��1.	
				}*/
			}			
			temp = temp->next;
		}
		  //printWeightedtable(table, 1);  // ȡ������ע�Ϳ��� follow �Ͻ�˹���� alg �����й���.
	}	
} 

//print unweighted table
void printWeightedtable(UnWeightedTable table, int startVertex)
{
	int i;
	Entry* array = table->array;
	int size=table->size;
	char *str[4] = 
	{
		"vertex",
		"known",
		"distance",
		"path"
	};

	// printf("\n\t unweighted shortest path table are as follows:\n");	
	printf("\n\t %6s%6s%9s%5s", str[0], str[1], str[2], str[3]);	
	for(i=0; i<size; i++)
	{		
		if(i != startVertex-1) 				
			printf("\n\t %-3d   %3d   %5d      v%-3d  ", i+1, array[i]->known, array[i]->dv, array[i]->pv);
		else
			printf("\n\t *%-3d  %3d   %5d      %-3d  ", i+1, array[i]->known, array[i]->dv, 0);
	}	 
	printf("\n");
}

 