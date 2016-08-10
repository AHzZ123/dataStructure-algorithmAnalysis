#include <stdio.h>
#include <malloc.h>

#define ElementType int

void swap(ElementType* a, ElementType* b);
ElementType median3(ElementType* array, int left, int right);
void quicksort(ElementType* array, int left, int right);
void printArray(ElementType* array, int N);
void insertionSort(ElementType* array, int left, int right);

// swap array arraynd b.
void swap(ElementType* array, ElementType* b)
{
	ElementType t;

	t=*array;
	*array=*b;
	*b=t;
}

// 3����ֵ�ָ ѡ�� left center right �ֱ�洢��С���м䣬���ֵ
// Ȼ�� ����λ�����ص�������2��Ԫ�� 
ElementType median3(ElementType* array, int left, int right)
{	
	int center = (left+right)/2;

	if(array[left]>array[center])
	{
		swap(&array[left], &array[center]);	
	}
	if(array[left]>array[right])
	{
		swap(&array[left], &array[right]);	
	}
	if(array[center]>array[right])
	{
		swap(&array[center], &array[right]);	
	}
	/* ����λ�����ص�������2��Ԫ�� */
	swap(&array[center], &array[right-1]);
	return array[right-1];
}

/* �������� */
void quicksort(ElementType array[], int left, int right)
{
    int i, j;
    ElementType pivot; // ����.
	
	// if(right-left >= 10) { also you can let lower limit be 10.
    if(right-left >= 3) { /* rihgt-left>=3,����������ֵ�ָ��Ӧ�� */
		/* �����ָ� median3 �����Ԫ����array[right]�ˣ���ŦԪ����array[right-1]����СԪ����array[left] */
        pivot = median3(array, left, right);    
        i = left; //i ָ����СԪ.
        j = right-1; // j ָ����ŦԪ.
		for(;;) 
		{
            while(array[++i] < pivot);    /* (�������++i, ����i++)�Ҵ�Ԫ�أ�iͣ������,i��ʼ�� left+1 */
			while(array[--j] > pivot);    /* (�������--j, ����j--)��СԪ�أ�jͣ������,j��ʼ�� right-2 */
			if(i<j)
			{
				swap(&array[i], &array[j]);    /* �ָ���� */
			}
			else
			{
				break;
			}
        }
		//key: array[i]���ָ���Ԫ�أ�array[right-1]ָ����ŦԪ�������ǽ�����		
        swap(&array[i], &array[right-1]);  
		// ������, array[i]=��ŦԪ, ǰ���Ԫ��С����, �����Ԫ�ش�����.

        quicksort(array, left, i-1);  		/* �ݹ���п������� */
        quicksort(array, i+1, right);		/* �ݹ���п������� */
    } 
    else	/* �����鳤��С��cutoff-���Ͼ���Ļ�����ô�Ͳ��ò���������Ϊ����Ч�ʸ�Щ*/
	{
		insertionSort(array, left, right);
	}
}

// ��������
void insertionSort(ElementType* array, int left, int right)
{
	int i, j;
	ElementType temp;	

	for(i=left+1; i<=right; i++) // �±�i �洢���򲿷ֵĵ�һ��Ԫ�أ����±�i-1 �洢��������һ��Ԫ��.
	{
		temp = array[i];
		for(j=i-1; j>=left; j--) // �±�j ��ʼ�洢���򲿷ֵ����һ��Ԫ�أ��������򲿷����򻬶�.
		{
			if(temp < array[j])
			{
				array[j+1] = array[j];
			}
			else
			{
				break;
			}
		}
		array[j+1] = temp; // who not array[j]? ��Ϊj--ִ�к� ���Ƴ���ѭ��������Ҫ�ӻ�ȥ.
	}
}

/* ��ӡ�������� */
void printArray(int* array, int size)
{
	int i;

    for(i=0; i<size; i++)
	{
        printf("%d ", array[i]);
	}
    printf("\n");
}