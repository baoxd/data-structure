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
	// ��С������--��³˹�����㷨
	void kruskal();
private:
	// ͼ�нڵ����
	int m_iCapacity;
	// ����ӽڵ����
	int m_iNodeCount;
	// ����ڵ�
	Node *m_pNodeArray;
	// �����ڽӾ���
	int *m_pMatrix;
	// �ҳ���С��
	int getMinEdge(vector<Edge> edgeVec, vector<vector<int>> nodeSets);
	// ��ȡ�㼯������
	void getNodeInSetIndex(vector<vector<int>> nodeSets, Edge edge, int &indexA,int &indexB);
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

void CMap::kruskal()
{
	int value = 0;
	int edgeCount = 0;
	// ���������ѡ���㼯�ϵ����飬ÿ�����Ϲ���һ����ͨ����
	vector<vector<int>> nodeSets;
	// ��ȡ���б�
	vector<Edge> edgeVec;
	// ��ѡ��
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
		// �ӱ߼���ȡ����С��
		int minEdgeIndex = getMinEdge(edgeVec, nodeSets);
		// ��С�ߵĶ���
		int nodeIndexA = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeIndexB = edgeVec[minEdgeIndex].m_iNodeIndexB;
		// �����ڼ����е�����
		int nodeAInSetIndex = -1, nodeBInSetIndex = -1;
		getNodeInSetIndex(nodeSets,edgeVec[minEdgeIndex],nodeAInSetIndex, nodeBInSetIndex);

		// ���㶼���ڼ�����
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
		// �ϲ���ͨ����
		else if(nodeAInSetIndex !=-1 && nodeBInSetIndex !=-1 && nodeAInSetIndex != nodeBInSetIndex)
		{
			for(int k = 0 ; k<(int)nodeSets[nodeBInSetIndex].size();k++)
			{
				nodeSets[nodeAInSetIndex].push_back(nodeSets[nodeBInSetIndex][k]);
			}
			// ���B����
			if(nodeBInSetIndex == (int)nodeSets.size()-1)
			{
				vector<int> tmp;
				nodeSets[nodeBInSetIndex] =tmp;
			}
			else
			{
				// ���B����
				for(int k = nodeBInSetIndex; k < (int)nodeSets.size() - 1; k++)
				{
					nodeSets[k] = nodeSets[k+1];
				}
			}
		}
		// �γɻ�·
		else if(nodeAInSetIndex !=-1 && nodeBInSetIndex !=-1 && nodeAInSetIndex == nodeBInSetIndex)
		{
			continue;
		}
		// ������ѡ�߼���
		selectEdge[edgeCount++] = edgeVec[minEdgeIndex];
		edgeVec[minEdgeIndex].m_bSelected = true;
	}

	// �����С������·��
	for(int i = 0 ; i<m_iCapacity-1;i++)
	{
		Edge edge = selectEdge[i];
		int nodeIndexA = edge.m_iNodeIndexA;
		int nodeIndexB = edge.m_iNodeIndexB;
		int weight = edge.m_iWeightValue;
		cout << m_pNodeArray[nodeIndexA].m_cData << "->" << m_pNodeArray[nodeIndexB].m_cData << "  Ȩֵ:" << weight << endl;
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
	// û�в�ѯ��
	if(weight == 0)
	{
		return index;
	}
	for(;i<(int)edgeVec.size();i++)
	{
		// �жϱߵ�����Ĺ�ϵ
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
	// �жϱߵ�����Ĺ�ϵ
	int nodeIndexA = edge.m_iNodeIndexA;
	int nodeIndexB = edge.m_iNodeIndexB;
	// �����ڼ����е�����
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
