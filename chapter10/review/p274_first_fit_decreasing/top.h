#include <stdio.h>
#include <malloc.h>
#include <limits.h>

// �ѽڵ�����Ϊ int.
#define ElementType int
#define Error(str) printf("\n error: %s \n",str)   
#define ElementNum 7
#define SUM 10

struct BinaryHeap;
typedef struct BinaryHeap *BinaryHeap;
struct BinaryHeap 
{
	int capacity;
	int size;	
	ElementType *array;		
};

// ����(����)�ṹ��.
struct Good;
typedef struct Good* Good;
typedef struct Good* Box;
struct Good
{
	int value;  // �����value ���ڻ��� ָ�� ��������.
				// �����value �������� ָ�� ���ӵ�ʣ������.
	Good next;
};

// ����һ���ֿ�ṹ�壬 �����������.
struct Warehouse;  // �ֿ���Կ�����������.
typedef struct Warehouse* Warehouse;
struct Warehouse
{
	int capacity;
	int size;
	Box* array; // �������.
};

