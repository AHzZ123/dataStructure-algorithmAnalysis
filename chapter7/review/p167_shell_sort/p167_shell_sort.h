#include <stdio.h>
#include <math.h>
// ���������и�ֵ �� �ҳ�����Ҫ���������.
// �� Rebort Sedgewick(�޲��ء���������) ����� increment = 9*4^i - 9*2^i +1  �� increment = 4^i - 3*2^i +1;
// incrementSeq[] ����1 ��ʼ.
int incrementSeqFunc(int* incrementSeq, int length)
{	
	int i, startup1 =0 , startup2 = 2;

	for(i=0; i<length; i++)
	{
		if(i%2==0)
		{
			incrementSeq[i] = 9*pow(4, startup1) - 9*pow(2, startup1) +1;
			startup1++;
		}
		else
		{
			incrementSeq[i] = pow(4, startup2) - 3*pow(2, startup2) +1;
			startup2++;
		}
		if(incrementSeq[i] >= length)
		{
			break;
		}
	}
	return i; // ����������ÿ�ֶ�ʹ�ã�����һ�֣���С����������
}

void printArray(int data[], int size)
{
	int i;
 
	for(i = 0; i < size; i++)
		printf("%d ", data[i]);
	
	printf("\n");
}

void shell_sort(int* array, int length)
{	
	int incrementSeq[255]; // ��������(startup == 0).
	int i, j, round=incrementSeqFunc(incrementSeq, length);
	int increment, temp;

	for(; round>=1; round--)
	{
		increment = incrementSeq[round-1];
		for(i=1*increment; i<length; i+=increment) // Ĭ�ϵ�,array[0*increment]�������Դ�1*increment��ʼ.
		{
			temp = array[i]; // ��1�������Ա.
			for(j=i-increment; j>=0; j-=increment) // j �����򲿷ֽ��л���.
			{
				if(temp < array[j])
				{
					array[j+increment] = array[j];
				}
				else
				{
					break;
				}
			}
			array[j+increment] = temp;
		}
	}	
}