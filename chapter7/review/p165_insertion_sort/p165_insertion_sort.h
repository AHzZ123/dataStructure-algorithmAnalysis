#include <stdio.h>

// ��������в�������.
void insertion_sort(int* array, int length)
{
	// i ��ʾ��������ĳ�Ա����.
	int i, j;	
	int temp;

	// ��1������(�±�==0)������������ i��1��ʼ����.
	for(i=1; i<length; i++)
	{
		temp = array[i];
		for(j=i-1; j>=0 && temp<array[j]; j--) // j ���������鷶Χ�ڻ������ҡ���.
		{			
			array[j+1] = array[j];// �����ҵ��󣩺���
		}
		array[j+1] = temp;		
	}
}

void printArray(int* data, int length)
{
	int i;

	for(i=0; i<length; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}