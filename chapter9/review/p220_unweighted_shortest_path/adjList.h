#include "queue.h"

struct Vertext;
typedef struct Vertex* Vertex;

struct Vertex
{
	// ElementType value; // Ҫ֪��������һ����ʶ����������������value(���Ƕ�value�ĳ���).
	int index;
	Vertex next;
};

struct AdjList;
typedef struct AdjList* AdjList;

struct AdjList
{
	int capacity;
	Vertex* array;
};

AdjList init(int capacity);
void insertAdjList(AdjList adjList, int start, int index);
void printAdjList(AdjList adjList);

// create vertex with index.
Vertex create(int index)
{
	Vertex v = (Vertex)malloc(sizeof(struct Vertex));

	if(v==NULL)
	{
		Error("failed create() for out of space.");
		return NULL;
	}
	v->index=index;
	v->next=NULL;
	return v;
}

// initilizing the adjacency list with capacity
AdjList init(int capacity)
{
	int i;
	AdjList adjList = (AdjList)malloc(sizeof(struct AdjList));
	
	if(adjList==NULL)
	{
		Error("failed init() for out of space.");
		return NULL;
	}
	adjList->capacity = capacity;
	
	adjList->array = (Vertex*)malloc(capacity * sizeof(Vertex));	
	if(adjList->array==NULL)
	{
		Error("failed init() for out of space.");
		return NULL;
	}

	for(i=0; i<capacity; i++)
	{
		adjList->array[i] = (Vertex)malloc(sizeof(struct Vertex));
		if(adjList->array[i]==NULL)
		{
			Error("failed init() for out of space.");
			return NULL;
		}
		adjList->array[i]->next = NULL;
	}
	return adjList;
} 

// ���� �����ʶ��index ���ڽӱ��±�Ϊ start ��λ��. 
void insertAdjList(AdjList adjList, int start, int index)
{
	Vertex temp = adjList->array[start];	
		
	while(temp->next)
	{
		temp = temp->next;
	}	
	temp->next = create(index);;	
	if(temp->next ==NULL)
	{
		return ;
	}
}

// ��������
void topSort(AdjList adjList, Queue queue, int* indegreeArray)
{
	int i;
	Vertex* array = adjList->array;
	Vertex temp;
	int index;
	int adjVertex;

	// step1: �����Ϊ0�Ķ���������.
	for(i=0; i<adjList->capacity; i++) // �м�: ������ӵ�value(��i) �� 0 ��ʼȡ.
	{
		if(indegreeArray[i]==0) 
		{
			enQueue(queue, i);
		}
	}

	//step2: �����в�Ϊ��ʱ��һ������v���ӣ�������v�ڽӵ����ж������ȼ�1.
	printf("\n\t top sorting result: ");
	while(!isEmpty(queue))
	{
		index = deQueue(queue); // while ѭ���Ѿ���֤�� ���в�����Ϊ��.
		printf("v[%d] ", index+1); // ע��: �����index Ҫ��1����ΪԪ������Ǵ� 0 ��ʼȡ�ģ����������Ӳ���.
		temp = array[index];
		while(temp->next)
		{
			adjVertex = temp->next->index; // ��Ϊ temp->next->index ��1 ��ʼȡ��,
			indegreeArray[adjVertex-1]--; // adjVertex Ҫ��1, ��indegreeArray�����0��ʼȡ.
			if(indegreeArray[adjVertex-1]==0) // step3: ���붥��v(��ʶ��=index)���ڵģ������Ϊ0�Ķ���������.
			{
				enQueue(queue, adjVertex-1); //��ӵ�value(��index) �� 0 ��ʼȡ.				
			}
			temp = temp->next;
		}
	}
	//  ѭ��������: ����������Ƕ�����ӵ�˳��.
}

// ��ӡ�ڽӱ�.
void printAdjList(AdjList adjList)
{
	int i;
	Vertex* array = adjList->array;
	Vertex temp;

	for(i = 0; i < adjList->capacity; i++)
	{
		printf("\t adjList[%d]-> ", i+1);
		temp = array[i];
		while(temp->next)
		{
			printf("%d ", temp->next->index);
			temp = temp->next;
		}	
		printf("\n");
	}	
}

void printArray(int* array, int size)
{
	int i;
		
	for(i=0; i<size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}