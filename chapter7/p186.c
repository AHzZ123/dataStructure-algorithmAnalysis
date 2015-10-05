/* ����ѡ�� */
#include<stdio.h>

#define ElementType int
#define CUTOFF 3

/* ��ӡ�������� */
void printArray(char *str, int* a, int N)
{
	int i = 0;
    printf("\n");
	printf("%40s", str);
    for(i = 0; i < N; i++)
        printf("%4d", a[i]);
    printf("\n");
}

/* ����Ԫ�� *a �� *b */
void swap(ElementType *a, ElementType *b)
{
    ElementType temp;
    temp = *a; 
    *a = *b; 
    *b = temp;
}

/*  ��������ֵ�ָ����������ֵ����λ����center == ��ֵ����ȡ��*/
ElementType Median3(ElementType A[], int left, int right)
{ 
    int center = (left + right) /2; 

    if(A[left] > A[center])
        swap(&A[left], &A[center]);
    if(A[left] > A[right])
        swap(&A[left], &A[right]); 
    if(A[center] > A[right])
        swap(&A[center], &A[right]);
    swap(&A[center], &A[right - 1]);    /* ����λ�����ص�������2��Ԫ�� */
	return A[right - 1];
}

/* �������� */
void InsertionSort(ElementType A[], int N)
{
    int j, p;
    ElementType tmp;

    for(p = 1; p < N; p++) {
        tmp = A[p];
        for(j = p; j > 0 && A[j - 1] > tmp; j--)
            A[j] = A[j - 1];
        A[j] = tmp;
    }
} 

/* ����ѡ�� */
void Qselect(ElementType A[], int k , int left , int right)
{
    int i, j;
    ElementType pivot;
	char *str1 = " after quick selection : ";

    if(left + CUTOFF <= right)
    {
        pivot = Median3(A, left, right);
        i = left;
        j = right - 1;     /* �����ָ�Median3�����Ԫ����A[right]�ˣ���ŦԪ����A[right-1]����СԪ����A[left] */
		for(; ;)
        {
            while(A[++i] < pivot);
            while(A[--j] > pivot);
            if(i < j)
                swap(&A[i], &A[j]);
            else
				break;        
        } //��һ�� ��������������Էָ��{S1}, pivot, {S2}

        swap(&A[i], &A[right - 1]);    /* �ָ���� */
		
        printArray(str1, A,10);    /* ���ڵ��ԵĴ�ӡ */
		if(k <= i)
            Qselect(A, k, left, i - 1);
        else if(k > i + 1)
            Qselect(A, k, i + 1, right);
    }
    else
        InsertionSort(A + left, right - left + 1);
}
 
main()
{    
    int k = 5;
    int N = 10;
	char *str = "th minest element is :";
    ElementType A[] = {13, 81, 92, 43, 31, 65, 57, 26, 75, 0};    
    
    Qselect(A, k, 0, 9);      
	    
    printf("%17d%-s%6d\n\n", k, str, A[k-1]);
}