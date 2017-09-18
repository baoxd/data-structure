/*
 * HufTree.h
 *
 *  Created on: 2017��9��15��
 *      Author: baoxd
 */

#ifndef HUFTREE_H_
#define HUFTREE_H_
#include "Tree.h"
#include "Node.h"
#include "Code.h"
using namespace std;

/**
 * ��������
 */
class HufTree{
public:
	HufTree(Code *codes, int size);
	// ��ȡȨֵ��С��code
	int getMinCode();
	// �����µ���
	void createTree(Node<Code> *node);
	// �����������
	void createHufTree();
	// Ҷ�ӽڵ����ɻ���������
	void createHufCode();
	// ��ȡ����Ҷ�ӽڵ�
	void getLeaf(Node<Code> *node);
	// ��ȡ�ڵ��seq
	void getNodeSeqs(Node<Code> *node);
	// ��ӡ��������
	void Traverse();
private:
	// ��������
	Tree<Code> *m_pTree;
	// ����Ҷ�ӽڵ�
	Node<Code> **leafNodes;
	int leafNum;
	Code *m_pCodes;
	int m_iLength;
};

HufTree::HufTree(Code *codes,  int size)
{
	m_pCodes = codes;
	m_iLength = size;
	leafNodes = new Node<Code>*[m_iLength];
	leafNum = 0;
	int index = getMinCode();
	Node<Code> *node= new Node<Code>;
	node->m_data  = m_pCodes[index];
	m_pCodes[index].hasSelect = true;
	m_pTree = new Tree<Code>(node);
	createHufTree();
}

int HufTree::getMinCode()
{
	Code tmp = m_pCodes[0];
	int index = 0;
	for(int i = 1 ; i < m_iLength; i++)
	{
		if(tmp.m_iWeight > m_pCodes[i].m_iWeight && !m_pCodes[i].hasSelect)
		{
			tmp = m_pCodes[i];
			index =  i;
		}
	}
	return index;
}

void HufTree::createHufTree()
{
	// ���ɷ�Ҷ�ӽڵ�
	for(int i = 0 ; i < m_iLength - 1 ; i++)
	{
		int index = getMinCode();
		Code code = m_pCodes[index];
		if(code.hasSelect)
		{
			return;
		}
		// �������ڵ�
		Node<Code> *node= new Node<Code>;
		node->m_data  = code;
		// ��ǰ���ĸ��ڵ�
		createTree(node);
		m_pCodes[index].hasSelect = true;
	}
}

void HufTree::createTree(Node<Code> *node)
{
	/**
	 *  �����´���һ�����󣬵��Ǻ��ӽڵ�ָ��Ļ���ԭ���ĵ�ַ��������oldRoot����µ�ַ
	 *  �����˸��ĺ��ӽڵ��m_pParentָ��ʧ�������Ҫ��getLeaf(��ȡҶ�ӽڵ�)�����½���
	 *  m_pParentָ��
	 */
	Node<Code> *oldRoot = new Node<Code>;
	m_pTree->getRoot(oldRoot);
	// ���½ڵ�
	Node<Code> *newRoot = new Node<Code>;
	Code rCode = oldRoot->m_data;
	Code lCode = node->m_data;
	Code rootCode;
	rootCode.m_iWeight = rCode.m_iWeight + lCode.m_iWeight;
	newRoot->m_data = rootCode;
	newRoot->m_iIndex = rCode.m_iWeight + lCode.m_iWeight;
	newRoot->m_pLChild = node;
	newRoot->m_pRChild = oldRoot;
	oldRoot->m_pParent = newRoot;
	node->m_pParent = newRoot;
	m_pTree->setRoot(newRoot);
}

void HufTree::getLeaf(Node<Code> *node)
{
	if(node->m_pLChild != NULL || node->m_pRChild !=NULL)
	{
		if(node->m_pLChild != NULL)
		{
			node->m_pLChild->m_pParent = node;
			getLeaf(node->m_pLChild);
		}
		if(node->m_pRChild)
		{
			node->m_pRChild->m_pParent = node;
			getLeaf(node->m_pRChild);
		}
	}
	else
	{
		leafNodes[leafNum++] = node;
	}
}

void HufTree::createHufCode()
{
	Node<Code> *root = new Node<Code>;
	m_pTree->getRoot(root);
	// ��ȡ����Ҷ�ӽڵ�
	getLeaf(root);

	for(int i = 0 ; i < m_iLength ; i++)
	{
		cout << leafNodes[i]->m_data.m_cData << "�Ļ��������룺"<< endl;
		getNodeSeqs(leafNodes[i]);
	}
}

void HufTree::getNodeSeqs(Node<Code> *node)
{
	char *seqs = new char[m_iLength];
	char *tmp = new char[m_iLength];
	Node<Code> *tmpNode = node;
	int num = 0;

	while(tmpNode->m_pParent)
	{
		if(tmpNode->m_pParent->m_pLChild == tmpNode)
		{
			tmp[num++] = '0';
		}
		if(tmpNode->m_pParent->m_pRChild == tmpNode)
		{
			tmp[num++] = '1';
		}
		tmpNode = tmpNode->m_pParent;
	}
	num = 0;
	for(int i = m_iLength - 1 ; i >=0  ; i--)
	{
		if(tmp[i] == '0' || tmp[i] == '1')
		{
			cout << tmp[i];
			seqs[num] = tmp[i];
		}
	}
	cout << endl;
	node->m_data.m_pSeq = seqs;
}

void toString(Code code)
{
	cout << "�ַ�:"  << code.m_iWeight << "  " ;
}

void HufTree::Traverse()
{
	Node<Code> *root = new Node<Code>;
	m_pTree->getRoot(root);
	root->preOrderTraverse(toString);
}



#endif /* HUFTREE_H_ */
