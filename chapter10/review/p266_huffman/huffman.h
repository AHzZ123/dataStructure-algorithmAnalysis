#include "top.h"

// Attention: ������� ����Ĵ�С����Ϊ ElementNum-2+1�� ���������ݻ�Ī�����
// �� ElementNum=7�� �������߶�Ϊ5������������5���ռ䶼����Ļ�����û�пռ��� '\0'��puts(str) ��ʱ�� ��Ī������Ķ�Щ�ַ�.
char code[ElementNum-2+1]; 
struct HuffmanCode codes[ElementNum];
int counter=0;

void copyCodes(char* src, char* des);

// traverse the huffman tree in preorder.
void printPreorder(HeapNode root, int depth)
{	
	int i = 0;

	for(;i<depth;i++)
	{
		printf("    ");
	}	
	if(root==NULL)
	{
		printf("NULL\n");
	}
	else if(root != NULL) 
	{		
		printf("%d \n", root->value);
		printPreorder(root->left, depth+1);
		printPreorder(root->right, depth+1);
	}
} 

// (�ݹ�ʵ��)��¼ÿ���ַ��Ĺ��������룻root == ����������, depth == �������, ��0��ʼȡ.
void huffmanCodeRecursion(HeapNode root, int depth)
{			
	if(root->left)
	{
		code[depth] = '0';
		code[depth+1] = '\0';
		huffmanCodeRecursion(root->left, depth+1);
	}

	if(root->right)
	{
		code[depth] = '1';
		code[depth+1] = '\0';
		huffmanCodeRecursion(root->right, depth+1);
	}	
	else
	{		
		codes[counter].flag = root->flag;
		copyCodes(code, codes[counter++].code);		
		// printf("%s\n", code); // ȡ������ע�Ϳ��Ե��Գ���.
	}
}

// �� src �е����� copy �� des ��.
void copyCodes(char* src, char* des)
{
	int i;
	
	for(i=0; i<ElementNum-2; i++)
	{
		des[i] = src[i];
	}
}