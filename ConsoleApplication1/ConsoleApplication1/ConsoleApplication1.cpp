// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//graph1.cpp

#include "stdafx.h"
#include <iostream>
using namespace std;
typedef int elementtype;
const int MaxVertex = 20;
int E;
bool visited[MaxVertex];
class  graph
{
public:
	graph();
	void Travel_DFS();
	void dfs(elementtype v);
	void createadj();                //建立邻接矩阵
	int firstadj(elementtype v);
	int nextadj(elementtype v, elementtype m);
	int numofGC();
	int Enum();
private:
	elementtype vertex[MaxVertex];     //顶点表 
	int edge[MaxVertex][MaxVertex];  //邻接矩阵
	int CurrentVertex;       //当前顶点数
};

//初始化
graph::graph()
{
	int i, j;
	for (i = 0; i<MaxVertex; i++)
		vertex[i] = 0;
	for (i = 0; i<MaxVertex; i++)
		for (j = 0; j<MaxVertex; j++)
			edge[i][j] = 0;
}



//建立邻接矩阵（无向图）
void graph::createadj()
{
	int i, j, k;
	cout << "请输入顶点数" << endl;
	cin >> CurrentVertex;
	cout << "请输入各顶点的值" << endl;
	for (k = 0; k<CurrentVertex; k++)
		cin >> vertex[k];
	cout << "请输入边：i j，i为-1时结束" << endl;
	cin >> i >> j;
	while (i != -1)
	{
		edge[i][j] = edge[j][i] = 1;
		cin >> i >> j;
	}
}

//求顶点v的第一个邻接点
int graph::firstadj(elementtype v)
{
	if (v != -1)
	{
		for (int col = 0; col<CurrentVertex; col++)
			if (edge[v][col]>0) return col;
	}
	return -1;
}

//求顶点v的m邻接点后的邻接点
int graph::nextadj(elementtype v, elementtype m)
{
	if (v != -1 && m != -1)
	{
		for (int col = m + 1; col<CurrentVertex; col++)
			if (edge[v][col]>0) return col;
	}
	return  -1;
}


int  main()
{
	return 0;
}