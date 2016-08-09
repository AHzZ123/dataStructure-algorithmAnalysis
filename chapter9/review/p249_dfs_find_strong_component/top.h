#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define Error(str) printf("\n error: %s", str)
// �ѽڵ������� �ṹ������ �����ǵ����� int����.
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

// �ѽڵ������ǽṹ��.
struct HeapNode; 
typedef struct HeapNode* HeapNode;
struct HeapNode
{
	int index; // �ڵ��� �� 1 ��ʼȡ.
	int value; // value == num[i] �ڵ㱻���ʵ����.
};

// ����ѵĽṹ��.
struct BinaryHeap;
typedef struct BinaryHeap *BinaryHeap;
struct BinaryHeap 
{
	int capacity;
	int size;	
	HeapNode array; // �����ʵ��Ϊ�ṹ������.
};