#include <stdio.h>
#include <malloc.h>

#define Error(str) printf("\nerror: %s", str)
#define ElementType int

ElementType* createArray(int size);
void mergeArray(ElementType* raw ,ElementType* temp, int left, int right);
void mergesort(ElementType* raw, ElementType* temp, int left, int right);
void printArray(ElementType data[], int size);

// allocate memory for array with size.
ElementType* createArray(int size)
{
	ElementType* array = (ElementType*)malloc(sizeof(ElementType)*size);
	
	if(array==NULL)
	{
		Error("failed createArray() for out of space.");		
	}
	return array;
}

// �ϲ�����raw[left,center] �� ����raw[center+1, right] �� temp����.
void mergeArray(ElementType* raw ,ElementType* temp, int left, int right)
{
	int center = (left+right)/2;
	int start1, start2;	
	int end1, end2;	
	int index;

	start1 = left; //��һ���������.
	end1 = center; //��һ�������յ�.
	start2 = center+1; // �ڶ����������.
	end2 = right; // �ڶ��������յ�.
	index = left; // ��������.
	
	// ����ϲ�2�����鵽 ��3������ ��3��steps��

	// step1: ������raw[left,center]��raw[center+1,right]�е�Ԫ��copy�� temp������.
	while(start1 <= end1 && start2 <= end2)
	{
		if(raw[start1] < raw[start2]) // ˭С��˭��copy�� temp������.
		{
			temp[index++] = raw[start1++];
		}
		else
		{
			temp[index++] = raw[start2++];
		}
	} // step1 over.

	// �ϲ���󣬿϶�����һ�������е�Ԫ��û�� copy�꣬��Ϊ��������ĳ��Ȳ���.
	// step2: ��û��copy��������е�Ԫ��copy�� temp�����У�
	while(start1 <= end1)
	{
		temp[index++] = raw[start1++];
	}	
	while(start2 <= end2)
	{
		temp[index++] = raw[start2++];
	} // step2 over.

	// step3: ����temp �����е�Ԫ���Ѿ������ˣ��ٰ�temp�е�����copy �� raw������.
	for(index = left; index <= right ; index++)
	{
		raw[index] = temp[index];
	}
}

// ������raw[left, right]���й鲢����. 
// �鲢�����Ǻϲ�����������ı����ɺϲ�����洢�� ����������temp��.
void mergesort(ElementType* raw, ElementType* temp, int left, int right)
{
	int center;
	if(left < right)
	{
		center = (left + right) / 2;
		mergesort(raw, temp, left, center);
		mergesort(raw, temp, center + 1, right);
		mergeArray(raw, temp, left, right); // �ϲ��������������[left,center] �� [center+1,right]
	}
}

void printArray(ElementType data[], int size)
{
	int i;

	for(i = 0; i < size; i++)	 
		printf("\n\t index[%d] = %d", i, data[i]);					 
	printf("\n");
} 