#include "adjList.h"

void kruskal(BinaryHeap heap, int* setArray, Edge* edgeSet, int size) ;
BinaryHeap buildHeapWithAdjList(AdjList adjList);
void printEdgeSet(Edge* array, int size);
extern int isEmpty(BinaryHeap bh);
ElementType deleteMin(BinaryHeap);
extern BinaryHeap initBinaryHeap(int capacity);
extern ElementType createHeapNode(int v1, int v2, int value);
extern void insert(ElementType value, BinaryHeap bh);

int stack[255];

// ������СΪ size �ı߼������飬����ֵ a[i]=i. 0 ���±겻��.
int* buildSet(int size) // set�����С ���� �������+1����Ϊ0���±겻��.
{
	int i;
	int* array = (int*)malloc(sizeof(int) * size);
	if(array == NULL)
	{
		Error("failed buildArray() for out of space");
		return NULL;
	}

	for(i=0; i<size; i++)
	{
		array[i] = i;
	}
	return array;
}

// Ѱ�� index��ʶ�� ���� ���ڵļ���.
// find() �漰��·��ѹ����·��ѹ�� ���� ջ��ʵ�֣��Ƚ������.
int find(int* setArray, int index)
{
	int temp = index;
	int i=0;			
			
	while(index != setArray[index])
	{
		stack[i++] = index; // index �� 1 ��ʼȡ��stack ��Ԫ�� Ҳ�� 1 ��ʼȡ.
		index = setArray[index]; // setArray �±��1 ��ʼ.
	}	
		
	// �������·��ѹ��(����ջ�Ĺ۵�). 
	while(--i >= 0)
	{
		setArray[ stack[i] ] = index;
	}	

	return index;
} 

// ��³˹�����㷨 ����Ѱ�� ��С������.
// Ϊʲô����û�а� �ڽӱ���Ϊ��������������Ϊ��ʹ������Ϊ�������仹��Ҫת��Ϊ �ѣ�
// ���ԣ�Ϊ���㷨�ļ���ԣ��ڵ��� kruskal() ����ǰ �ͽ� �ڽӱ�ת��Ϊ ��������ȶ�����.
void kruskal(BinaryHeap heap, int* setArray, Edge* edgeSet, int edgeNum)  // ��������=7ʱ��edgeNum=6 ��Ϊ 7���������6����.
{
	int i=0;
	Edge edge;
	int set1, set2;

	while(!isEmpty(heap) && i<edgeNum)
	{
		edge = deleteMin(heap); // edge ������Ϊ�գ���Ϊheap ��Ϊ�գ�whileѭ������
		set1 = find(setArray, edge->v1);
		set2 = find(setArray, edge->v2);

		// ��³˹�����㷨����Ҫ������ Ӧ����ӻ���Ӧ�÷���
		if(set1 != set2) // ��� v1 �� v2 ������ͬһ�����ϣ��߾ͽ��кϲ�.
		{
			// setUnion begins.
			edgeSet[i++] = edge; // ��ӱ�.			
			setArray[set2] = set1; //���� edge->v2 �ĸ��� ���ϱ�ʶ. ������д��setArray[edge->v2] = set1;
			// setUnion over.
		}
	}
}	

// ���ڽӱ�����ݽ���.
BinaryHeap buildHeapWithAdjList(AdjList adjList)
{	
	int i, capacity = adjList->capacity;
	Vertex vertex;
	Vertex* array = adjList->array;
	Edge edge;
	BinaryHeap heap = initBinaryHeap((capacity-1)*(capacity-1) + 1); // ��Ϊ capacity������������(capacity-1)^2 ����.��Ϊ0���±겻��,���Լ�1.		
	if(heap==NULL)
	{
		Error("failed buildHeapWithAdjList() for out of space.");
		return NULL;
	}

	for(i=0; i<capacity; i++)
	{
		vertex = array[i];
		while(vertex->next)
		{
			if(i+1 < vertex->next->index)
			{
				edge = createHeapNode(i+1, vertex->next->index, vertex->next->weight);
				insert(edge, heap);
			}			
			vertex = vertex->next;
		}
	}
	return heap;
}

void printEdgeSet(Edge* array, int size)
{
	int i;
	
	for(i=0; i<size; i++)
	{
		printf("\n\tv[%d] -weight[%d]- v[%d]", array[i]->v1, array[i]->weight, array[i]->v2);
	}
	printf("\n");
}