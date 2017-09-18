/*
 * HufTree2.cpp
 *
 *  Created on: 2017年9月18日
 *      Author: baoxd
 */
#include <iostream>
using namespace std;
// 权值最大值
const int MaxValue = 10000;
// 最大编码位数
const int MaxBit = 4;
// 最大节点个数
const int MaxN = 10;
// 霍夫曼树的节点结构
struct HaffNode
{
	// 权值
	int weight;
	// 标记
	int flag;
	// 双亲节点下标
	int parent;
	// 左孩子下标
	int leftChild;
	// 右孩子下标
	int rightChild;
};
// 霍夫曼编码的数据元素结构
struct Code
{
	// 数组
	int bit[MaxBit];
	// 编码的起始下标
	int start;
	// 字符的权值
	int weight;
};

// 创建叶子节点数为n的霍夫曼树
void Haffman(int weight[], int n, HaffNode haffTree[])
//建立叶结点个数为n权值为weight的哈夫曼树haffTree
{
    int j, m1, m2, x1, x2;
    //哈夫曼树haffTree初始化。n个叶结点的哈夫曼树共有2n-1个结点
    for (int i = 0; i<2 * n - 1; i++)
    {
        if (i<n)
            haffTree[i].weight = weight[i];
        else
            haffTree[i].weight = 0;
        //注意这里没打else那{}，故无论是n个叶子节点还是n-1个非叶子节点都会进行下面4步的初始化
        haffTree[i].parent = 0;
        haffTree[i].flag = 0;
        haffTree[i].leftChild = -1;
        haffTree[i].rightChild = -1;
    }
    //构造哈夫曼树haffTree的n-1个非叶结点
    for (int i = 0; i<n - 1; i++)
    {
        m1 = m2 = MaxValue;//Maxvalue=10000;(就是一个相当大的数)
        x1 = x2 = 0;//x1、x2是用来保存最小的两个值在数组对应的下标

        for (j = 0; j<n + i; j++)//循环找出所有权重中，最小的二个值--morgan
        {
            if (haffTree[j].weight<m1&&haffTree[j].flag == 0)
            {
                m2 = m1;
                x2 = x1;
                m1 = haffTree[j].weight;
                x1 = j;
            }
            else if(haffTree[j].weight<m2&&haffTree[j].flag == 0)
            {
                m2 = haffTree[j].weight;
                x2 = j;
            }
        }
        //将找出的两棵权值最小的子树合并为一棵子树
        haffTree[x1].parent = n + i;
        haffTree[x2].parent = n + i;
        haffTree[x1].flag = 1;
        haffTree[x2].flag = 1;
        haffTree[n + i].weight = haffTree[x1].weight + haffTree[x2].weight;
        haffTree[n + i].leftChild = x1;
        haffTree[n + i].rightChild = x2;
    }
}

void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[])
{
	Code *cd = new Code;
	int child,parent;
	//求n个叶子节点的霍夫曼编码
	for(int i = 0 ; i < n ;i++)
	{
		cd->start = 0;
		cd->weight = haffTree[i].weight;
		child = i;
		parent = haffTree[child].parent;
		while(parent != 0)
		{
			if(haffTree[parent].leftChild == child)
			{
				cd->bit[cd->start] = 0;
			}
			else
				cd->bit[cd->start] = 1;
			cd->start++;
			child = parent;
			parent = haffTree[child].parent;
		}
		// 反转编码
		for(int j = cd->start - 1; j >=0; j--)
		{
			haffCode[i].bit[cd->start - j - 1] = cd->bit[j];
		}
		haffCode[i].start = cd->start;
		haffCode[i].weight = cd->weight;
	}
}


int main()
{
	int i, j, n = 4, m = 0;
	int weight[] = {2, 4, 5, 7};
	HaffNode *myHaffTree = new HaffNode[2 * n - 1];
	Code *myHaffCode = new Code[n];
	if(n > MaxN)
	{
		cout << "定义的n越界，修改MaxN！" << endl;
		exit(0);
	}
	Haffman(weight, n, myHaffTree);
	HaffmanCode(myHaffTree, n, myHaffCode);
	// 输出每个叶子节点的霍夫曼编码
	for(i = 0 ; i < n; i++)
	{
		cout << "Weight:" << myHaffCode[i].weight << " Code=";
		for(j = 0 ; j < myHaffCode[i].start; j++)
			cout << myHaffCode[i].bit[j];
		m = m + myHaffCode[i].weight*myHaffCode[i].start;
		cout << endl;
	}
	cout << "huffman's WPL is:";
	cout << m;
	cout << endl;
	return 0;
}


