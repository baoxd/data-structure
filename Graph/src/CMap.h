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

#endif /* CMAP_H_ */
