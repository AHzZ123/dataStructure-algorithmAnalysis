#include <stdio.h>

int elements[255];

// ����쳲��������������㷨
void fibonacci(int index)
{
	if(index==0)
	{
		elements[index]=0;
	}
	else if(index==1)
	{
		elements[index]=1;
	}
	else // ������Ҫ��� else ���.
	{
		elements[index] = elements[index-1] + elements[index-2];
	}	
}

void main()
{
	int i;
	int size = 10;	

	for(i=0; i<size; i++)
	{
		fibonacci(i);
		printf("fibonacci(%d) = %d\n", i, elements[i]);
	}
}