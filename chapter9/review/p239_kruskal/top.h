#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define Error(str) printf("\n error: %s", str)
#define ElementType HeapNode // �ѽڵ������ǡ��ṹ��ָ�����ͣ�

// ����Ľṹ��.
struct Vertex;
typedef struct Vertex* Vertex;
struct Vertex
{
	// ElementType value; // Ҫ֪��������һ����ʶ����������������value(���Ƕ�value�ĳ���).
	int index;
	Vertex next;
	int weight; // ��Ȩ·������Ȩֵ.
};

// �ڽӱ�Ľṹ��.
struct AdjList;
typedef struct AdjList* AdjList;
struct AdjList
{
	int capacity;
	Vertex* array;
};

// ����ѵĽڵ����͵Ľṹ��.
struct Edge;
typedef struct Edge* Edge;
typedef struct Edge* HeapNode;
struct Edge
{
	int v1; // start
	int v2; // end
	int weight; // ����v1 �� v2 ��� Ȩֵ.
};

// ����ѵĽṹ��(��ָ������ʵ��).
struct BinaryHeap;
typedef struct BinaryHeap* BinaryHeap;
struct BinaryHeap
{
	int capacity;
	int size;
	HeapNode* array; // �ṹ��ָ������.
};

// �ڽӱ�ı���ṹ��.
struct Entry;
typedef struct Entry* Entry;
struct Entry
{
	int known;
	int dv;
	int pv;
};

// ��Ȩ·����¼��Ľṹ��.
struct UnWeightedTable;
typedef struct UnWeightedTable* UnWeightedTable;

struct UnWeightedTable
{	
	int size;	
	Entry* array;
};