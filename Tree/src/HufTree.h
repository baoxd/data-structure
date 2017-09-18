/*
 * HufTree.h
 *
 *  Created on: 2017年9月15日
 *      Author: baoxd
 */

#ifndef HUFTREE_H_
#define HUFTREE_H_
#include "Tree.h"
#include "Node.h"
#include "Code.h"
using namespace std;

/**
 * 霍夫曼树
 */
class HufTree{
public:
	HufTree(Code *codes, int size);
	// 获取权值最小的code
	int getMinCode();
	// 生成新的树
	void createTree(Node<Code> *node);
	// 构造霍夫曼树
	void createHufTree();
	// 叶子节点生成霍夫曼编码
	void createHufCode();
	// 获取所有叶子节点
	void getLeaf(Node<Code> *node);
	// 获取节点的seq
	void getNodeSeqs(Node<Code> *node);
	// 打印霍夫曼树
	void Traverse();
private:
	// 霍夫曼树
	Tree<Code> *m_pTree;
	// 所有叶子节点
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
	// 生成非叶子节点
	for(int i = 0 ; i < m_iLength - 1 ; i++)
	{
		int index = getMinCode();
		Code code = m_pCodes[index];
		if(code.hasSelect)
		{
			return;
		}
		// 生成树节点
		Node<Code> *node= new Node<Code>;
		node->m_data  = code;
		// 当前树的根节点
		createTree(node);
		m_pCodes[index].hasSelect = true;
	}
}

void HufTree::createTree(Node<Code> *node)
{
	/**
	 *  这里新创建一个对象，但是孩子节点指向的还是原来的地址，而不是oldRoot这个新地址
	 *  导致了根的孩子节点的m_pParent指向丢失。因此需要在getLeaf(获取叶子节点)中重新建立
	 *  m_pParent指向
	 */
	Node<Code> *oldRoot = new Node<Code>;
	m_pTree->getRoot(oldRoot);
	// 树新节点
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
	// 获取所有叶子节点
	getLeaf(root);

	for(int i = 0 ; i < m_iLength ; i++)
	{
		cout << leafNodes[i]->m_data.m_cData << "的霍夫曼编码："<< endl;
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
	cout << "字符:"  << code.m_iWeight << "  " ;
}

void HufTree::Traverse()
{
	Node<Code> *root = new Node<Code>;
	m_pTree->getRoot(root);
	root->preOrderTraverse(toString);
}



#endif /* HUFTREE_H_ */
