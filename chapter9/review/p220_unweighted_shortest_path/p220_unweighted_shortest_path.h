#include "adjList.h"
#include <limits.h>

// ��¼��ı���
struct Entry;
typedef struct Entry* Entry;
struct Entry
{
	int known;
	int dv;
	int pv;
};

// ��¼�������
struct UnweightedTable;
typedef struct UnweightedTable* UnweightedTable;
struct UnweightedTable
{	
	int size;	
	Entry* array;
};

UnweightedTable initUnweightedTable(int size);
void printUnweightedtable(UnweightedTable table, int startVertex);

//allocate the memory for initializing unweighted table
UnweightedTable initUnweightedTable(int size)
{	
	int i;
	UnweightedTable table = (UnweightedTable)malloc(sizeof(struct UnweightedTable));
	
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
		table->array[i]->known = 0; // known=0 or 1��ʾ δ֪ �� ��֪.
		table->array[i]->dv= INT_MAX; // dv==distance ���� INT_MAX ��ʾ���ɴ�. �� dv=0 ��ʾ���Լ����Լ���path==0.
		table->array[i]->pv = 0; // pv==path ���� 0 ��ʾ���ɴ��Ϊpv��1��ʼȡ��
	}
	return table;
} 

//���� startVertex���� �������������Ȩ���·��
void unweighted_shortest_path(AdjList adj, UnweightedTable table, int startVertex, Queue queue)
{		
	int capacity=adj->capacity;
	Vertex* arrayVertex = adj->array;
	Vertex temp;
	Entry* arrayEntry = table->array;
	int index; // �����ʶ��(��0��ʼȡ)
	int adjVertex;

	//step1(��ʼ״̬): startVertex �������.
	enQueue(queue, startVertex-1); // �м�: ������ӵ�value(��i) �� 0 ��ʼȡ.	
	arrayEntry[startVertex-1]->dv=0;
	arrayEntry[startVertex-1]->pv=0;
	// ��ʼ״̬over.

	// step2: ����. ��������Ӷ�����ڽӶ������.
	while(!isEmpty(queue))
	{
		index = deQueue(queue);  // index��0��ʼȡ����Ϊ����value��0��ʼȡ������Ҫ��1.
		arrayEntry[index]->known=1; // ���Ӻ󣬽��� known ����Ϊ1.
		temp = arrayVertex[index];
		while(temp->next) 
		{
			adjVertex = temp->next->index; // �ڽӽڵ��ʶ��adjVertex ��1��ʼȡ.
			if(arrayEntry[adjVertex-1]->dv == INT_MAX) // ע��: �±���adjVertex-1, �� dv==INT_MAX ���� index �� adjVertex �����ڲ��ɴ�״̬������adjVertex���.
			{
				enQueue(queue, adjVertex-1); // ��ӵ�value �� 0 ��ʼȡ�����Լ�1.
				arrayEntry[adjVertex-1]->dv = arrayEntry[index]->dv + 1; 
				arrayEntry[adjVertex-1]->pv=index+1; // index ��0��ʼȡ������index��1.
			}			
			temp = temp->next;
		}		
	}	
} 

//print unweighted table
void printUnweightedtable(UnweightedTable table, int startVertex)
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

	printf("\n\t unweighted shortest path table are as follows:\n");	
	printf("\n\t %6s%6s%9s%5s", str[0], str[1], str[2], str[3]);	
	for(i=0; i<size; i++)
	{		
		if(i != startVertex-1) 				
			printf("\n\t %-3d   %3d   %5d      %-3d  ", i+1, array[i]->known, array[i]->dv, array[i]->pv);
		else
			printf("\n\t *%-3d  %3d   %5d      %-3d  ", i+1, array[i]->known, array[i]->dv, 0);
	}	 
	printf("\n");
}

 