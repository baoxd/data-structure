/*
 * TestPrim.cpp
 *
 *  Created on: 2017��9��19��
 *      Author: baoxd
 */
#include "CMap.h"

/**
 * Prim�㷨
 *
 * �㷨����
 *  1).���룺һ����Ȩ��ͨͼ�����ж��㼯��ΪV���߼���ΪE��
 *  2).��ʼ����Vnew = {x}������xΪ����V�е���һ�ڵ㣨��ʼ�㣩��Enew = {},Ϊ�գ�
 *  3).�ظ����в�����ֱ��Vnew = V��
 *   a.�ڼ���E��ѡȡȨֵ��С�ı�<u, v>������uΪ����Vnew�е�Ԫ�أ���v����Vnew���ϵ��У�����v��V����������ж�������ǰ��������������ͬȨֵ�ıߣ��������ѡȡ����֮һ����
 *   b.��v���뼯��Vnew�У���<u, v>�߼��뼯��Enew�У�
 *  4).�����ʹ�ü���Vnew��Enew���������õ�����С��������
 *
 *
 * Kruskal�㷨
 *  1).����N={���е�} E={���б�} E_select={��ѡ��}
 *  2).��E��ѡȡȨֵ��С�ı߷���E_select,���������������ֱ��E_select�ĸ���ΪN-1
 *    a.ѡ��ı߲����ѱ�ѡ
 *    b.ѡ��ߵĶ��㲻�ܺ���ѡ�����γɻ�·
 *
 *
 *      A       C
 *     | \7   8/ |
 *     |  \   /  |
 *    5|    B    5
 *     |   / \   |
 *     | 9/  7\  |
 *     | /     \ |
 *      D --15---E
 *      \      / |
 *      6\    8  9
 *        \  /   |
 *          F--11-G
 *
 *
 *    | A | B | C | D | E | F | G |
 *  --|---|---|---|---|---|---|---|
 *  A |   | 7 |   | 5 |   |   |   |
 *  --|---|---|---|---|---|---|---|
 *  B | 7 |   | 8 | 9 | 7 |   |   |
 *  --|---|---|---|---|---|---|---|
 *  C |   | 8 |   |   | 5 |   |   |
 *  --|---|---|---|---|---|---|---|
 *  D | 5 | 9 |   |   | 15| 6 |   |
 *  --|---|---|---|---|---|---|---|
 *  E |   | 7 | 5 | 15|   | 8 | 9 |
 *  --|---|---|---|---|---|---|---|
 *  F |   |   |   | 6 | 8 |   | 11|
 *  --|---|---|---|---|---|---|---|
 *  G |   |   |   |   | 9 | 11|   |
 *  --|---|---|---|---|---|---|---|
 *
 */

int main()
{
	Node node1('A');
	Node node2('B');
	Node node3('C');
	Node node4('D');
	Node node5('E');
	Node node6('F');
	Node node7('G');

	CMap map(7);
	// ������ڵ�
	map.addNode(&node1);
	map.addNode(&node2);
	map.addNode(&node3);
	map.addNode(&node4);
	map.addNode(&node5);
	map.addNode(&node6);
	map.addNode(&node7);
	// �����ڽӾ���
	map.setValueToUndirectedGraph(0,1,7); //6 4 9�� 6 5  11
	map.setValueToUndirectedGraph(0,3,5);
	map.setValueToUndirectedGraph(1,0,7);
	map.setValueToUndirectedGraph(1,2,8);
	map.setValueToUndirectedGraph(1,3,9);
	map.setValueToUndirectedGraph(1,4,7);
	map.setValueToUndirectedGraph(2,1,8);
	map.setValueToUndirectedGraph(2,4,5);
	map.setValueToUndirectedGraph(3,0,5);
	map.setValueToUndirectedGraph(3,1,9);
	map.setValueToUndirectedGraph(3,4,15);
	map.setValueToUndirectedGraph(3,5,6);
	map.setValueToUndirectedGraph(4,1,7);
	map.setValueToUndirectedGraph(4,2,5);
	map.setValueToUndirectedGraph(4,3,15);
	map.setValueToUndirectedGraph(4,5,8);
	map.setValueToUndirectedGraph(4,6,9);
	map.setValueToUndirectedGraph(5,3,6);
	map.setValueToUndirectedGraph(5,4,8);
	map.setValueToUndirectedGraph(5,6,11);
	map.setValueToUndirectedGraph(6,4,9);
	map.setValueToUndirectedGraph(6,5,11);
	// ��ӡ
	map.printMatrix();
	// prim��С������
	map.prim(0);
	map.resetNode();
	cout << "======================"<< endl;
	map.kruskal();

	return 0;
}



