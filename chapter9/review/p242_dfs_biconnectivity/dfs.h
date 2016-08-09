#include "adjList.h"

#define VertexNum 7

int min(int a, int b);

// �������� 0 ���±�ͨͨ����.
int visited[VertexNum+1]; // ���㱻����״̬ visited[i]==1|0(�ѷ���|δ����)
int num[VertexNum+1]; // ���㱻���ʵ����.
int parent[VertexNum+1]; // parent[i]=j ���� ����i �����Ŷ���j֮�� ������.
int low[VertexNum+1]; // low[i]=j ���� ����i ���Է���(����ͨ�������)�����ȱ����ʵĶ����Ƕ���j.
int counter=0; // �ѱ����ʵĶ�������.

// dfs ������������㷨.����Ѱ�ұ���ߺ͸��.
// �ڽӱ�adjList(ͼ�ı�׼��ʾ����)��vertexIndex ����������depth ���ڴ�ӡ�ո�
void dfs_find_articulation(AdjList adjList, int vertex, int depth)
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
			printf("v[%c]->v[%c] (build edge) (%c, %d/%d)\n", vertex+64, adjVertex+64, vertex+64, num[vertex], low[vertex]);
			dfs_find_articulation(adjList, adjVertex, depth+1);
			
			if(low[adjVertex] >= num[vertex]) // �ж� vertex�Ƿ��Ǹ��.
			{
					// just for printing effect
				for(i = 0; i < depth; i++)  
					printf("           ");
				printf("%c is an articulation point for (low[%c]=%d) >= (num[%c]=%d)\n", vertex+64, adjVertex+64, low[adjVertex], vertex+64, num[vertex]);
			}
			low[vertex] = min(low[vertex], low[adjVertex]); // ���ں����������low[].
		}	
		else // �ڽӶ��㱻���ʹ�.
		{						
			if(parent[vertex] != adjVertex) // true����(vertex, adjVertex)���Ǳ����
			{
				low[vertex] = min(low[vertex], num[adjVertex]); // ���� ��ǰ�ڵ�i��low[i]				
				// just for printing effect, ����Ϊ�㷨��һ����.
				for(i = 0; i < depth; i++)  
					printf("           ");	
				// ����Ϊ�㷨��һ����over.
				printf("v[%c]->v[%c] (backside) (%c, %d/%d)\n", vertex+64, adjVertex+64, vertex+64, num[vertex], low[vertex]);				
			} 			 			 
		}				
		temp = temp->next;
	} 
} 

int min(int a, int b)
{
	return a>b? b:a;
}