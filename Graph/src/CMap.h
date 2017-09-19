/*
 * CMap.h
 *
 *  Created on: 2017��9��19��
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
	// ����ڵ�
	bool addNode(Node *pNode);
	// ���ýڵ�
	void resetNode();
	// ��������ͼ�ڽӾ���
	bool setValueToDirectedGraph(int row, int col, int val = 1);
	// ��������ͼ�ڽӾ���
	bool setValueToUndirectedGraph(int row, int col, int val = 1);
	// ��ȡ�ڽӾ���ֵ
	bool getValueFromMatrix(int row, int col, int &val);
	// ��ӡ�ڽӾ���
	void printMatrix();
	// ������ȱ���
	void depthFirstTraversal(int nodeIndex);
	// ������ȱ���
	void breadthFirstTraversal(int nodeIndex);
	void breadthFirstTraversalImpl(vector<int> preVec);
	// ��С������--����ķ�㷨
	void prim(int nodeIndex);
private:
	// ͼ�нڵ����
	int m_iCapacity;
	// ����ӽڵ����
	int m_iNodeCount;
	// ����ڵ�
	Node *m_pNodeArray;
	// �����ڽӾ���
	int *m_pMatrix;
};

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	// ��ʼ���ڽӾ���
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
	// �㼯��
	vector<int> selecedNode;
	// �߼���
	vector<Edge> selecedEdge;
	// ��ѡ�߼���
	vector<Edge> toBeSelectEdge;
	int weight = 0;
	// ����㼯��
	selecedNode.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// ��ѯ��ѡ��
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
				// �ж��Ƿ�ѡ��
				if(!(m_pNodeArray[start].m_bIsVisited
					&& m_pNodeArray[end].m_bIsVisited))
				{

					k = j;
				}
			}
		}
		// ��һ����Ҫ����㼯�ϵĵ�����
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
			// ���ô�ѡ���ѱ�ѡ
			toBeSelectEdge[k].m_bSelected = true;
			// ����߼���
			selecedEdge.push_back(toBeSelectEdge[k]);
			// ����㼯��
			selecedNode.push_back(nextIndex);
			// ���õ��ѱ�ѡ
			m_pNodeArray[nextIndex].m_bIsVisited = true;
			// �����ѡ��
			for(int i = 0 ; i < m_iCapacity; i++)
			{
				getValueFromMatrix(nextIndex, i, weight);
				// ���ڱ��ҵ㲻����ѡ�㼯����
				if(weight != 0 && !m_pNodeArray[i].m_bIsVisited)
				{
					Edge edge(nextIndex, i, weight);
					// �����ѡ�߼���
					toBeSelectEdge.push_back(edge);
				}
			}
		}
	}
	// �����С������·��
	for(int i = 0 ; i < (int)selecedEdge.size(); i++)
	{
		cout << m_pNodeArray[selecedEdge[i].m_iNodeIndexA].m_cData << "-->"
			 << m_pNodeArray[selecedEdge[i].m_iNodeIndexB].m_cData
			 << " Ȩֵ:" << selecedEdge[i].m_iWeightValue << endl;
	}
}

#endif /* CMAP_H_ */
