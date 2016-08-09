#include "adjList.h"

#define VertexNum 7

// ��������� 0 ���±� ͨͨ���á�
int visited[VertexNum+1]; // ���㱻����״̬ visited[i]==1|0(�ѷ���|δ����)
int num[VertexNum+1]; // ���㱻���ʵ����.
int parent[VertexNum+1]; // parent[i]=j ���� ����i �����Ŷ���j֮�� ������.
int counter=0; // �ѱ����ʵĶ�������.

// dfs ������������㷨.
// �ڽӱ�adjList(ͼ�ı�׼��ʾ����)��vertexIndex ����������depth ���ڴ�ӡ�ո�visted���� ���ڴ洢 �������״̬.
void dfs_undirected_graph(AdjList adjList, int vertex, int depth)
{
	int i;
	Vertex temp = adjList->array[vertex-1];
	int adjVertex;
		
	visited[vertex] = 1; // ����vertex ����Ϊ �ѷ���״̬.
	num[vertex] = ++counter; // ����vertex �����ʵ����.	

	while(temp->next)
	{
		adjVertex = temp->next->index;		
		if(!visited[adjVertex]) // �ڽӶ���û�б����ʹ�, ������dfs ���з���.
		{
			parent[adjVertex] = vertex;			
			// just for printing effect
			for(i = 0; i < depth; i++)  
				printf("           ");
			printf("v[%c]->v[%c] (build edge)\n", vertex+64, adjVertex+64);
			dfs_undirected_graph(adjList, adjVertex, depth+1);
		}				
		temp = temp->next;
	} 
} 