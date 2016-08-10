#include "top.h"

void first_fit_decreasing(BinaryHeap heap, struct Warehouse warehouse);
extern ElementType deleteMin(BinaryHeap);
extern void printBinaryHeap(BinaryHeap bh);
extern int isEmpty(BinaryHeap bh); 
void printBoxes(struct Warehouse warehouse);

// ��ʼ�� ��������.
Box* initBoxes(int size)
{
	int i;
	Box* array = (Box*)malloc(size * sizeof(Box));

	if(!array)
	{
		Error("failed initBoxes() for out of space.");
		return NULL;
	}
	for(i=0; i<size; i++)
	{
		array[i] = (Good)malloc(sizeof(struct Good));
		if(!array[i])
		{
			Error("failed initBoxes() for out of space.");
			return NULL;
		}
		array[i]->value = SUM; // ʣ����������ʼ״̬Ϊ10. �Զ���.
		array[i]->next = NULL;
	}
	return array;
}

void initWarehouse(struct Warehouse* warehouse, int capacity)
{	
	warehouse->capacity = capacity;
	warehouse->size = 0;
	warehouse->array = initBoxes(capacity);		
}

// Ϊ�������ռ䣬value==��������.
Good createGood(int value)
{
	Good good = (Good)malloc(sizeof(struct Good));
	if(good==NULL)
	{
		Error("failed createGood for out of space.");
		return NULL;
	}
	good->value = value;
	good->next = NULL;
	return good;
}

// �״��ʺϵݼ��㷨.(����Ʒ�����ܹ�ʢ�����ĵ�һ��������)
void first_fit_decreasing(BinaryHeap heap, struct Warehouse warehouse)
{	
	int i, weight;	
	Good temp;
	Box* array = warehouse.array; 
	
	// step2: ɾ������������Ԫ��.��ɾ����Ԫ�� ��ӵ� ������.
	while(!isEmpty(heap))
	{
		i=0;
		weight = deleteMin(heap);						
		while(weight > array[i++]->value);
		
		if(array[i-1]->value == SUM)
		{
			warehouse.size++;
		}

		temp = array[i-1]; // ��Ϊ����� whileѭ�������һ��1.
		while(temp->next)
		{			
			temp = temp->next;
		}	
		temp->next = createGood(weight); // ��Ϊi �Լ���һ��, ����Ҫ��1.
		if(temp->next) // ����ڴ����ɹ�.
		{
			array[i-1]->value -= weight;
		}
	}
	printBoxes(warehouse);
}

void printBoxes(struct Warehouse warehouse)
{
	int i;
	Box* array = warehouse.array;
	Good temp;
	
	printf("\n");
	for(i=0; i<warehouse.size; i++)
	{		
		printf("box[%d] = ", i+1);
		temp = array[i];
		while(temp->next)
		{
			printf("%d ", temp->next->value);
			temp = temp->next;			
		}
		printf("\n");
	}
}