/*
 * CMap.h
 *
 *  Created on: 2017年9月19日
 *      Author: baoxd
 */

#ifndef CMAP_H_
#define CMAP_H_
#include <iostream>
#include <vector>
#include <memory.h>
#include "Node.h"
#include "Edge.h"
using namespace std;

class CMap{
public:
	CMap(int capacity);
	~CMap();
	// 插入节点
	bool addNode(Node *pNode);
	// 重置节点
	void resetNode();
	// 设置有向图邻接矩阵
	bool setValueToDirectedGraph(int row, int col, int val = 1);
	// 设置无向图邻接矩阵
	bool setValueToUndirectedGraph(int row, int col, int val = 1);
	// 获取邻接矩阵值
	bool getValueFromMatrix(int row, int col, int &val);
	// 打印邻接矩阵
	void printMatrix();
	// 深度优先遍历
	void depthFirstTraversal(int nodeIndex);
	// 广度优先遍历
	void breadthFirstTraversal(int nodeIndex);
	void breadthFirstTraversalImpl(vector<int> preVec);
	// 最小生成树--普利姆算法
	void prim(int nodeIndex);
	// 最小生成树--克鲁斯卡尔算法
	void kruskal();
private:
	// 图中节点个数
	int m_iCapacity;
	// 已添加节点个数
	int m_iNodeCount;
	// 保存节点
	Node *m_pNodeArray;
	// 保存邻接矩阵
	int *m_pMatrix;
	// 找出最小边
	int getMinEdge(vector<Edge> edgeVec, vector<vector<int>> nodeSets);
	// 获取点集合索引
	void getNodeInSetIndex(vector<vector<int>> nodeSets, Edge edge, int &indexA,int &indexB);
};

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	// 初始化邻接矩阵
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));
}

CMap::~CMap()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
}

bool CMap::addNode(Node *pNode)
{
	if(pNode == NULL)
		return false;
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	m_iNodeCount++;
	return true;
}

void CMap::resetNode()
{
	for(int i = 0 ; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToDirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToUndirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

bool CMap::getValueFromMatrix(int row,int col, int &val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

void CMap::printMatrix()
{
	for(int i = 0 ; i < m_iCapacity; i++)
	{
		for(int j = 0 ; j < m_iCapacity; j++)
		{
			cout << m_pMatrix[i * m_iCapacity +  j] << " " ;
		}
		cout << endl;
	}
}

void CMap::depthFirstTraversal(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << "->";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	for(int i = 0 ; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i,value);
		if(value !=0)
		{
			if(m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			depthFirstTraversal(i);
		}
	}
}

void CMap::breadthFirstTraversal(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << "->";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	vector<int> curVec;
	curVec.push_back(nodeIndex);
	breadthFirstTraversalImpl(curVec);
}

void CMap::breadthFirstTraversalImpl(vector<int> preVec)
{
	int value = 0 ;
	vector<int> curVec;

	for(int i = 0 ; i < (int)preVec.size(); i++)
	{
		for(int j = 0 ; j < m_iCapacity; j++)
		{
			getValueFromMatrix(preVec[i], j, value);
			if(value !=0)
			{
				if(m_pNodeArray[j].m_bIsVisited)
				{
					continue;
				}
				else
				{
					cout << m_pNodeArray[j].m_cData << "->";
					m_pNodeArray[j].m_bIsVisited = true;
					curVec.push_back(j);
				}
			}
		}
	}
	if(curVec.size() >0)
	{
		breadthFirstTraversalImpl(curVec);
	}
}

void CMap::prim(int nodeIndex)
{
	if(nodeIndex <0 || nodeIndex >=m_iCapacity)
	{
		return ;
	}
	// 点集合
	vector<int> selecedNode;
	// 边集合
	vector<Edge> selecedEdge;
	// 待选边集合
	vector<Edge> toBeSelectEdge;
	int weight = 0;
	// 放入点集合
	selecedNode.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// 查询待选边
	for(int i = 0 ; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, weight);
		if(weight !=0)
		{
			Edge edge(nodeIndex, i, weight);
			toBeSelectEdge.push_back(edge);
		}
	}

	while((int)selecedNode.size() < m_iCapacity)
	{
		int k = 0, start, end;

		for(int j = 1 ; j < (int)toBeSelectEdge.size(); j++)
		{
			if(toBeSelectEdge[k].m_bSelected && !toBeSelectEdge[j].m_bSelected &&
					!(m_pNodeArray[toBeSelectEdge[j].m_iNodeIndexA].m_bIsVisited
							&& m_pNodeArray[toBeSelectEdge[j].m_iNodeIndexB].m_bIsVisited))
			{
				k = j;
			}
			if(toBeSelectEdge[k].m_iWeightValue >toBeSelectEdge[j].m_iWeightValue && !toBeSelectEdge[j].m_bSelected)
			{
				start = toBeSelectEdge[j].m_iNodeIndexA;
				end = toBeSelectEdge[j].m_iNodeIndexB ;
				// 判断是否被选过
				if(!(m_pNodeArray[start].m_bIsVisited
					&& m_pNodeArray[end].m_bIsVisited))
				{

					k = j;
				}
			}
		}
		// 下一个将要加入点集合的点索引
		int nextIndex = -1;
		if(!m_pNodeArray[toBeSelectEdge[k].m_iNodeIndexB].m_bIsVisited)
		{
			nextIndex = toBeSelectEdge[k].m_iNodeIndexB;
		}
		else if(!m_pNodeArray[toBeSelectEdge[k].m_iNodeIndexA].m_bIsVisited)
		{
			nextIndex = toBeSelectEdge[k].m_iNodeIndexA;
		}
		if(nextIndex != -1)
		{
			// 设置待选边已被选
			toBeSelectEdge[k].m_bSelected = true;
			// 保存边集合
			selecedEdge.push_back(toBeSelectEdge[k]);
			// 保存点集合
			selecedNode.push_back(nextIndex);
			// 设置点已被选
			m_pNodeArray[nextIndex].m_bIsVisited = true;
			// 扩充待选边
			for(int i = 0 ; i < m_iCapacity; i++)
			{
				getValueFromMatrix(nextIndex, i, weight);
				// 存在边且点不在已选点集合中
				if(weight != 0 && !m_pNodeArray[i].m_bIsVisited)
				{
					Edge edge(nextIndex, i, weight);
					// 放入待选边集合
					toBeSelectEdge.push_back(edge);
				}
			}
		}
	}
	// 输出最小生成树路径
	for(int i = 0 ; i < (int)selecedEdge.size(); i++)
	{
		cout << m_pNodeArray[selecedEdge[i].m_iNodeIndexA].m_cData << "-->"
			 << m_pNodeArray[selecedEdge[i].m_iNodeIndexB].m_cData
			 << " 权值:" << selecedEdge[i].m_iWeightValue << endl;
	}
}

void CMap::kruskal()
{
	int value = 0;
	int edgeCount = 0;
	// 定义存在已选顶点集合的数组，每个集合构成一个连通分量
	vector<vector<int>> nodeSets;
	// 获取所有边
	vector<Edge> edgeVec;
	// 已选边
	Edge selectEdge[m_iCapacity-1];

	for(int i = 0 ; i < m_iCapacity; i++)
	{
		for(int j = i ; j < m_iCapacity; j++)
		{
			getValueFromMatrix(i, j, value);
			if(value != 0)
			{
				Edge edge(i,j,value);
				edgeVec.push_back(edge);
			}
		}
	}
	while(edgeCount < m_iCapacity - 1)
	{
		// 从边集合取出最小边
		int minEdgeIndex = getMinEdge(edgeVec, nodeSets);
		// 最小边的顶点
		int nodeIndexA = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeIndexB = edgeVec[minEdgeIndex].m_iNodeIndexB;
		// 顶点在集合中的索引
		int nodeAInSetIndex = -1, nodeBInSetIndex = -1;
		getNodeInSetIndex(nodeSets,edgeVec[minEdgeIndex],nodeAInSetIndex, nodeBInSetIndex);

		// 顶点都不在集合中
		if(nodeAInSetIndex == -1 && nodeBInSetIndex == -1)
		{
			vector<int> nodeVec;
			nodeVec.push_back(nodeIndexA);
			nodeVec.push_back(nodeIndexB);
			nodeSets.push_back(nodeVec);
		}
		else if(nodeAInSetIndex == -1 && nodeBInSetIndex !=-1)
		{
			nodeSets[nodeBInSetIndex].push_back(nodeIndexA);
		}
		else if(nodeAInSetIndex !=-1 && nodeBInSetIndex == -1)
		{
			nodeSets[nodeAInSetIndex].push_back(nodeIndexB);
		}
		// 合并连通分量
		else if(nodeAInSetIndex !=-1 && nodeBInSetIndex !=-1 && nodeAInSetIndex != nodeBInSetIndex)
		{
			for(int k = 0 ; k<(int)nodeSets[nodeBInSetIndex].size();k++)
			{
				nodeSets[nodeAInSetIndex].push_back(nodeSets[nodeBInSetIndex][k]);
			}
			// 清除B集合
			if(nodeBInSetIndex == (int)nodeSets.size()-1)
			{
				vector<int> tmp;
				nodeSets[nodeBInSetIndex] =tmp;
			}
			else
			{
				// 清除B集合
				for(int k = nodeBInSetIndex; k < (int)nodeSets.size() - 1; k++)
				{
					nodeSets[k] = nodeSets[k+1];
				}
			}
		}
		// 形成回路
		else if(nodeAInSetIndex !=-1 && nodeBInSetIndex !=-1 && nodeAInSetIndex == nodeBInSetIndex)
		{
			continue;
		}
		// 保存已选边集合
		selectEdge[edgeCount++] = edgeVec[minEdgeIndex];
		edgeVec[minEdgeIndex].m_bSelected = true;
	}

	// 输出最小生成树路径
	for(int i = 0 ; i<m_iCapacity-1;i++)
	{
		Edge edge = selectEdge[i];
		int nodeIndexA = edge.m_iNodeIndexA;
		int nodeIndexB = edge.m_iNodeIndexB;
		int weight = edge.m_iWeightValue;
		cout << m_pNodeArray[nodeIndexA].m_cData << "->" << m_pNodeArray[nodeIndexB].m_cData << "  权值:" << weight << endl;
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec, vector<vector<int>> nodeSets)
{
	int weight = 0, index = -1, i = 0;

	for(; i <(int)edgeVec.size(); i++)
	{
		int indexA = -1, indexB = -1;
		getNodeInSetIndex(nodeSets, edgeVec[i], indexA, indexB);
		if(indexA !=-1 && indexB !=-1 && indexA == indexB)
		{
			continue;
		}
		if(!edgeVec[i].m_bSelected)
		{
			weight = edgeVec[i].m_iWeightValue;
			index = i;
			break;
		}
	}
	// 没有查询到
	if(weight == 0)
	{
		return index;
	}
	for(;i<(int)edgeVec.size();i++)
	{
		// 判断边的两点的关系
		int indexA = -1, indexB = -1;
		getNodeInSetIndex(nodeSets, edgeVec[i], indexA, indexB);
		if(indexA !=-1 && indexB !=-1 && indexA == indexB)
		{
			continue;
		}

		if(edgeVec[i].m_iWeightValue < weight && !edgeVec[i].m_bSelected)
		{
			{
				weight = edgeVec[i].m_iWeightValue;
				index = i;
			}
		}
	}
	return index;
}

void CMap::getNodeInSetIndex(vector<vector<int>> nodeSets, Edge edge, int &indexA,int &indexB)
{
	// 判断边的两点的关系
	int nodeIndexA = edge.m_iNodeIndexA;
	int nodeIndexB = edge.m_iNodeIndexB;
	// 顶点在集合中的索引
	vector<int> nodeVec;
	for(int j = 0;j<(int)nodeSets.size();j++)
	{
		nodeVec = nodeSets[j];
		for(int k = 0 ; k<(int)nodeVec.size();k++)
		{

			if(nodeVec[k] == nodeIndexA)
			{
				indexA = j;
			}
			if(nodeVec[k] == nodeIndexB)
			{
				indexB = j;
			}
		}
	}
}

#endif /* CMAP_H_ */
