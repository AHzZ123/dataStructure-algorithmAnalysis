#include <stdio.h>
#include <malloc.h>
#include <limits.h>

// #define ElementType int �ѽڵ��ǽṹ������
#define Error(str) printf("\n error: %s \n",str)   

struct HeapNode; 
typedef struct HeapNode* HeapNode;
struct HeapNode
{
	int value;
};

// ����ѵĽṹ��.
struct BinaryHeap;
typedef struct BinaryHeap *BinaryHeap;
struct BinaryHeap 
{
	int capacity;
	int size;	
	HeapNode* array;  // �ѽڵ������ǽṹ��ָ��. �����ȶ����ǽṹ��ָ������.
};