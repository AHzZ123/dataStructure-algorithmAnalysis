#include "first_fit_decreasing.h"

extern BinaryHeap initBinaryHeap(int capacity);
extern void insert(ElementType value, BinaryHeap bh);
extern ElementType deleteMin(BinaryHeap);
extern void printBinaryHeap(BinaryHeap bh);
extern int isEmpty(BinaryHeap bh); 

void main()
{
	int i;
	int goods[] = {2, 5, 4, 7, 1, 3, 8};
	BinaryHeap heap;
	struct Warehouse warehouse;
	
	initWarehouse(&warehouse, ElementNum); //  ��ʼ���ֿ�(��������);

	// step1: ���������.
	heap = initBinaryHeap(ElementNum+1); // �ѵ��±�0��Ԫ�ز��ã�����������̸��.
	if(heap==NULL)
	{
		return ;
	}
	for(i=0; i<ElementNum; i++)
	{	
		insert(goods[i], heap);
	}
	//step1 over.
	printBinaryHeap(heap);
	
	// step2: Ӧ���״��ʺϵݼ��㷨.
	printf("\n\t === review for first fit decreasing alg ===\n");
	first_fit_decreasing(heap, warehouse);
}