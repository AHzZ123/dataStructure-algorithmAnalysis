#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define Error(str) printf("\n error: %s", str)
#define ElementType struct HeapNode

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
struct HeapNode;
typedef struct HeapNode* HeapNode;
struct HeapNode
{
	int vertex;
	int weight;
};

// ����ѵĽṹ��.
struct BinaryHeap;
typedef struct BinaryHeap* BinaryHeap;
struct BinaryHeap
{
	int capacity;
	int size;
	HeapNode array;
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