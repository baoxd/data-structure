/*
 * HufTree2.cpp
 *
 *  Created on: 2017��9��18��
 *      Author: baoxd
 */
#include <iostream>
using namespace std;
// Ȩֵ���ֵ
const int MaxValue = 10000;
// ������λ��
const int MaxBit = 4;
// ���ڵ����
const int MaxN = 10;
// ���������Ľڵ�ṹ
struct HaffNode
{
	// Ȩֵ
	int weight;
	// ���
	int flag;
	// ˫�׽ڵ��±�
	int parent;
	// �����±�
	int leftChild;
	// �Һ����±�
	int rightChild;
};
// ���������������Ԫ�ؽṹ
struct Code
{
	// ����
	int bit[MaxBit];
	// �������ʼ�±�
	int start;
	// �ַ���Ȩֵ
	int weight;
};

// ����Ҷ�ӽڵ���Ϊn�Ļ�������
void Haffman(int weight[], int n, HaffNode haffTree[])
//����Ҷ������ΪnȨֵΪweight�Ĺ�������haffTree
{
    int j, m1, m2, x1, x2;
    //��������haffTree��ʼ����n��Ҷ���Ĺ�����������2n-1�����
    for (int i = 0; i<2 * n - 1; i++)
    {
        if (i<n)
            haffTree[i].weight = weight[i];
        else
            haffTree[i].weight = 0;
        //ע������û��else��{}����������n��Ҷ�ӽڵ㻹��n-1����Ҷ�ӽڵ㶼���������4���ĳ�ʼ��
        haffTree[i].parent = 0;
        haffTree[i].flag = 0;
        haffTree[i].leftChild = -1;
        haffTree[i].rightChild = -1;
    }
    //�����������haffTree��n-1����Ҷ���
    for (int i = 0; i<n - 1; i++)
    {
        m1 = m2 = MaxValue;//Maxvalue=10000;(����һ���൱�����)
        x1 = x2 = 0;//x1��x2������������С������ֵ�������Ӧ���±�

        for (j = 0; j<n + i; j++)//ѭ���ҳ�����Ȩ���У���С�Ķ���ֵ--morgan
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
        //���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
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
	//��n��Ҷ�ӽڵ�Ļ���������
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
		// ��ת����
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
		cout << "�����nԽ�磬�޸�MaxN��" << endl;
		exit(0);
	}
	Haffman(weight, n, myHaffTree);
	HaffmanCode(myHaffTree, n, myHaffCode);
	// ���ÿ��Ҷ�ӽڵ�Ļ���������
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


