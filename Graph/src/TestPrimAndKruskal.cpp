/*
 * TestPrim.cpp
 *
 *  Created on: 2017年9月19日
 *      Author: baoxd
 */
#include "CMap.h"

/**
 * Prim算法
 *
 * 算法描述
 *  1).输入：一个加权连通图，其中顶点集合为V，边集合为E；
 *  2).初始化：Vnew = {x}，其中x为集合V中的任一节点（起始点），Enew = {},为空；
 *  3).重复下列操作，直到Vnew = V：
 *   a.在集合E中选取权值最小的边<u, v>，其中u为集合Vnew中的元素，而v不在Vnew集合当中，并且v∈V（如果存在有多条满足前述条件即具有相同权值的边，则可任意选取其中之一）；
 *   b.将v加入集合Vnew中，将<u, v>边加入集合Enew中；
 *  4).输出：使用集合Vnew和Enew来描述所得到的最小生成树。
 *
 *
 * Kruskal算法
 *  1).假设N={所有点} E={所有边} E_select={已选边}
 *  2).从E中选取权值最小的边放入E_select,满足下面的条件，直到E_select的个数为N-1
 *    a.选择的边不能已被选
 *    b.选择边的顶点不能和已选顶点形成回路
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
	// 添加网节点
	map.addNode(&node1);
	map.addNode(&node2);
	map.addNode(&node3);
	map.addNode(&node4);
	map.addNode(&node5);
	map.addNode(&node6);
	map.addNode(&node7);
	// 设置邻接矩阵
	map.setValueToUndirectedGraph(0,1,7); //6 4 9， 6 5  11
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
	// 打印
	map.printMatrix();
	// prim最小生成树
	map.prim(0);
	map.resetNode();
	cout << "======================"<< endl;
	map.kruskal();

	return 0;
}



