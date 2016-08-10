#include "p189_bucket_sort.h"

//free the memory bucketSet->array own.
void clearBuckets(BucketSet bucketSet)
{
	int i, size = bucketSet->size;
	Node* array = bucketSet->array;
	Node temp, tempcopy;

	for(i=0; i<size; i++)
	{
		temp = array[i]->next;
		while(temp)
		{
			tempcopy = temp;
			temp = temp->next;
			free(tempcopy);
			tempcopy = NULL;			
		}
		array[i]->next = NULL;
	}
}

// ����Ͱʽ����Ļ�������. ��������Ԫ�ظ���Ϊsize��
void radixsort(ElementType* array, int size)
{
	BucketSet bucketSet;	
	int	capacity=10; // Ͱ������Ϊ 10.
	int i, j;

	bucketSet = initBucketSet(capacity);
	if(bucketSet==NULL)
	{
		return ;
	}  
	
	for(i=1; i<=3; i++)
	{
		for(j=0; j<size; j++)
		{
			bucketsort(bucketSet->array, array[j], i);
		}
		bucketsToArray(bucketSet, array); // �����ǽ�Ͱ������copy ������.
		printArray(array, size);	
		clearBuckets(bucketSet); // ÿ�ֶ�Ҫ���� ����ʽ����.
	}
}
void main()
{ 		 
	ElementType array[] = {110, 245, 895, 658, 321, 852, 147, 458, 469, 159, 347, 28};	
	int size=12;

	printf("\n radix sort based on {110, 245, 895, 658, 321, 852, 147, 458, 469, 159, 347, 28}\n");	
	radixsort(array, size);			
} 

