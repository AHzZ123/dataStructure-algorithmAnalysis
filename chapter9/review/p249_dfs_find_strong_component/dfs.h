#include "adjList.h"

#define VertexNum 10

int min(int a, int b);

// 0 ���±�ͨͨ����.
int visited[VertexNum+1]; // ���㱻����״̬ visited[i]==1|0(�ѷ���|δ����)
int num[VertexNum+1]; // ���㱻���ʵ����.
int parent[VertexNum+1]; // parent[i]=j ���� ����i �����Ŷ���j֮�� ������.
int counter=0; // �ѱ����ʵĶ�������.

// dfs ������������㷨.
// �ڽӱ�adjList(ͼ�ı�׼��ʾ����) , vertex ����������depth ���ڴ�ӡ�ո�
void dfs_find_strong_component(AdjList adjList, int vertex, int depth)
{
	int i;
	Vertex temp = adjList->array[vertex-1];
	int adjVertex;
		
	visited[vertex] = 1; // ����vertex ����Ϊ �ѷ���״̬. vertex ��1��ʼȡ�����Լ�1.	
	while(temp->next)
	{
		adjVertex = temp->next->index;		
		if(!visited[adjVertex]) // �ڽӶ���û�б����ʹ�, ������dfs ���з���.
		{			
			parent[adjVertex] = vertex;	
			// just for printing effect
			for(i = 0; i < depth; i++)  
				printf("           ");
			printf("v[%c]->v[%c] (build edge) \n", vertex+64, adjVertex+64);
			dfs_find_strong_component(adjList, adjVertex, depth+1);									
		}	
		else // if(visited[adjVertex-1]) �ڽӶ��㱻���ʹ�.
		{		
			if(parent[vertex] != adjVertex) // true����(vertex, adjVertex)���Ǳ����
			{								
				// just for printing effect, ����Ϊ�㷨��һ����.
				for(i = 0; i < depth; i++)  
					printf("           ");	
				printf("v[%c]->v[%c] (backside)\n", vertex+64, adjVertex+64);
				// ����Ϊ�㷨��һ����over.
			} 			 			 
		}				
		temp = temp->next;
	} 	
	num[vertex] = ++counter; // ����vertex �����ʵ����. // attention, p249: ��ȷ˵�� ʹ��dfs ����������� ������.
} 

int min(int a, int b)
{
	return a>b? b:a;
}