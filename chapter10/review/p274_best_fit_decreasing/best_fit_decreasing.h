#include "top.h"

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

// ����ʺϵݼ��㷨.(���ȱ������ӣ��ҳ��û����ź󣬶�Ӧ���ӵ�ʣ��������С������)
void best_fit_decreasing(BinaryHeap heap, struct Warehouse warehouse)
{	
	int i, weight, diff;	
	Box temp;
	Box* array = warehouse.array; 
	int minIndex=-1, minValue = SUM;

	// step2: ɾ������������Ԫ��.��ɾ����Ԫ�� ��ӵ� ������.
	while(!isEmpty(heap))
	{		
		weight = deleteMin(heap);
		for(i=0; i<warehouse.size;i++) // �����ֿ��е���������.
		{				
			diff = array[i]->value - weight; // diff �˿̱�ʾ��ֵ.
			if(diff>=0 && diff <= minValue) // key if condition.
			{
				minValue = diff;
				minIndex = i;
				if(diff==0) //����ֵ����0ʱ����ʾ��ѵ�.
				{
					break;
				}
			}
		} // �������ӱ���over.
		
		if(minValue == SUM) // û���ҵ��ʺϵ����ӣ���Ҫ����һ��������(size++).
		{
			minIndex = i;
			warehouse.size++;
		}

		// װ������.
		temp = array[minIndex]; 
		while(temp->next)
		{			
			temp = temp->next;
		}	
		temp->next = createGood(weight); 
		if(temp->next) // ����ڴ����ɹ�.
		{
			array[minIndex]->value -= weight;
		} // װ��over.
		//printBoxes(warehouse); // ȡ������ע�����ڵ���.
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