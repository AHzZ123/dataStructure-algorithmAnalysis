#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define Error(str) printf("\n error: %s", str)
 
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
