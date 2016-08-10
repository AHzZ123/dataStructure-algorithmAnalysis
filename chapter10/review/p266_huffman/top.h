#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define Error(str) printf("\n error: %s", str)
#define ElementNum 7

// �ѽڵ������� �ṹ��ָ������ �����ǵ����� int����.
#define ElementType HeapNode 

// ����ѵĶѽڵ�����Ϊ �ṹ��ָ������. 
struct HeapNode; 
typedef struct HeapNode* HeapNode;
struct HeapNode
{
	int value; // �ַ����ֵ�Ƶ��
	char flag; // �ַ���ʶ
	HeapNode left;
	HeapNode right;
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

struct HuffmanCode;
typedef struct HuffmanCode* HuffmanCode;
struct HuffmanCode                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
{
	char flag;
	char code[ElementNum-2+1]; // ��Ϊ���� '\0'
	// Ϊʲô code�ĳ�����ElementNum-2����Ϊ ��Ԫ�ظ�����7�������߶�Ϊ5. 
};