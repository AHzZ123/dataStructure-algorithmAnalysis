#include "huffman.h"

extern BinaryHeap initBinaryHeap(int capacity);
extern void insert(ElementType value, BinaryHeap bh);
extern void printBinaryHeap(BinaryHeap bh);
extern int isEmpty(BinaryHeap bh);
extern ElementType deleteMin(BinaryHeap);
extern ElementType createHeapNode(int value, char flag);

void main()
{
	char flag[ElementNum] = {'a', 'e', 'i', 's', 't', 'p', 'n'};
	int frequency[ElementNum] = {10, 15, 12, 3, 4, 13, 1};
	ElementType root, temp1, temp2;
	int i;
	BinaryHeap heap;

	// step1: ����.
	heap = initBinaryHeap(ElementNum+1); // ��Ϊ0���±겻��.
	if(heap==NULL)
	{
		return ;
	}
	for(i=0; i<ElementNum; i++)
	{				
		insert(createHeapNode(frequency[i], flag[i]), heap);
	}
	printBinaryHeap(heap);
	// step1: over.

	// step2: ����ɾ��������СԪ�� �� ������������.		
	while(!isEmpty(heap))
	{
		temp1 = deleteMin(heap);
		if(!isEmpty(heap))
		{
			temp2 = deleteMin(heap);
			root = createHeapNode(temp1->value+temp2->value, ' ');
			root->right = temp1; // ���ȷ��ұ�.
			root->left = temp2;				
			// �ϲ��������Ҫ�����.
			insert(root, heap);	
		}		
	}
	// step2 over.
	printf("\n === nodes in huffman tree are as follows.===\n");
	printPreorder(root, 1);

	// step3 save huffman code.			
	huffmanCodeRecursion(root, 0);
	// step3 over.

	// ��¼�� ����������󣬴�ӡ����Ч��.
	for(i=0; i<ElementNum; i++)
	{
		printf("\n code[%c] = %s", codes[i].flag, codes[i].code);
	}
	printf("\n");
}
