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
private:
	// 图中节点个数
	int m_iCapacity;
	// 已添加节点个数
	int m_iNodeCount;
	// 保存节点
	Node *m_pNodeArray;
	// 保存邻接矩阵
	int *m_pMatrix;
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

#endif /* CMAP_H_ */
