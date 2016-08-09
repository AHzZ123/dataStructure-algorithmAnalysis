#include "adjList.h"

#define VertexNum 10

int min(int a, int b);

// 0 ���±�ͨͨ����.
int visited[VertexNum+1]; // ���㱻����״̬ visited[i]==1|0(�ѷ���|δ����)
int num[VertexNum+1]; // ���㱻���ʵ����.
int parent[VertexNum+1]; // parent[i]=j ���� ����i �����Ŷ���j֮�� ������.
int low[VertexNum+1]; // low[i]=j ���� ����i ���Է���(����ͨ�������)�����ȱ����ʵĶ����Ƕ���j.
int counter=0; // �ѱ����ʵĶ�������.

// dfs ������������㷨. ��������ͼ.
// �ڽӱ�adjList(ͼ�ı�׼��ʾ����)��vertexIndex ����������depth ���ڴ�ӡ�ո�
void dfs_find_directed_graph(AdjList adjList, int vertex, int depth)
{
	int i;
	Vertex temp = adjList->array[vertex-1];
	int adjVertex;
		
	visited[vertex] = 1; // ����vertex ����Ϊ �ѷ���״̬. vertex ��1��ʼȡ�����Լ�1.
	low[vertex] = num[vertex] = ++counter; // ����vertex �����ʵ����.	
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
			dfs_find_directed_graph(adjList, adjVertex, depth+1);						
			low[vertex] = min(low[vertex], low[adjVertex]); // ���ں����������low[].
		}	
		else // if(visited[adjVertex-1]) �ڽӶ��㱻���ʹ�.
		{			
			if(parent[vertex] != adjVertex) // true����(vertex, adjVertex)���Ǳ����
			{
				low[vertex] = min(low[vertex], num[adjVertex]); // ���� ��ǰ�ڵ�i��low[i]								
			} 			 			 
		}				
		temp = temp->next;
	} 	
} 

int min(int a, int b)
{
	return a>b? b:a;
}