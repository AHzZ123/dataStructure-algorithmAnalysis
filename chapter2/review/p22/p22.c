#include<stdio.h>

#define ElementType int
#define NOTFOUND -1

/* ���ֲ��ң�A[]�������� */
int binarySearch(ElementType A[], ElementType x, int N)
{
    int low, mid, high;

    low = 0;
    high = N - 1;

    while (low <= high)
	{
        mid = (low + high) / 2;
        if(A[mid] < x)
		{
            low = mid + 1;
		}
        else if(A[mid] > x)
		{
            high = mid - 1; 
		}
        else 
		{
			return mid;
		}
    }
    return NOTFOUND;
} 

main()
{
    int A[]={4, 5, 67, 67, 109, 876};
    int N=6, x=109;      	
	
	printf("\narray[] = {4, 5, 67, 67, 109, 876}");
    printf("\nthe position whose value equals to %d is %4d\n", x, binarySearch(A, x, N));
}
