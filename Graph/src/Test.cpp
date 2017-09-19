//============================================================================
// Name        : Graph.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "CMap.h"
using namespace std;

/**
 * 图 -- 无向图
 *
 * 				A
 * 			  /   \
 *           B     D
 *          / \   / \
 *         C   F G - H
 *         \  /
 *           E
 *
 *
 *    | A | B | C | D | E | F | G | H |
 *  --|---|---|---|---|---|---|---|---|
 *  A |   | 1 |   | 1 |   |   |   |   |
 *  --|---|---|---|---|---|---|---|---|
 *  B | 1 |   | 1 |   |   | 1 |   |   |
 *  --|---|---|---|---|---|---|---|---|
 *  C |   | 1 |   |   | 1 |   |   |   |
 *  --|---|---|---|---|---|---|---|---|
 *  D | 1 |   |   |   |   |   | 1 | 1 |
 *  --|---|---|---|---|---|---|---|---|
 *  E |   |   | 1 |   |   | 1 |   |   |
 *  --|---|---|---|---|---|---|---|---|
 *  F |   | 1 |   |   | 1 |   |   |   |
 *  --|---|---|---|---|---|---|---|---|
 *  G |   |   |   | 1 |   |   |   | 1 |
 *  --|---|---|---|---|---|---|---|---|
 *  H |   |   |   | 1 |   |   | 1 |   |
 *
 *
 */
//int main() {
//	Node node1('A');
//	Node node2('B');
//	Node node3('C');
//	Node node4('D');
//	Node node5('E');
//	Node node6('F');
//	Node node7('G');
//	Node node8('H');
//
//	CMap map(8);
//	// 添加节点
//	map.addNode(&node1);
//	map.addNode(&node2);
//	map.addNode(&node3);
//	map.addNode(&node4);
//	map.addNode(&node5);
//	map.addNode(&node6);
//	map.addNode(&node7);
//	map.addNode(&node8);
//	// 设置无向图邻接矩阵值
//	map.setValueToUndirectedGraph(0,1);
//	map.setValueToUndirectedGraph(0,3);
//	map.setValueToUndirectedGraph(1,0);
//	map.setValueToUndirectedGraph(1,2);
//	map.setValueToUndirectedGraph(1,5);
//	map.setValueToUndirectedGraph(2,1);
//	map.setValueToUndirectedGraph(2,4);
//	map.setValueToUndirectedGraph(3,0);
//	map.setValueToUndirectedGraph(3,6);
//	map.setValueToUndirectedGraph(3,7);
//	map.setValueToUndirectedGraph(4,2);
//	map.setValueToUndirectedGraph(4,5);
//	map.setValueToUndirectedGraph(5,1);
//	map.setValueToUndirectedGraph(5,4);
//	map.setValueToUndirectedGraph(6,3);
//	map.setValueToUndirectedGraph(6,7);
//	map.setValueToUndirectedGraph(7,3);
//	map.setValueToUndirectedGraph(7,6);
//	// 打印
//	map.printMatrix();
//	// 深度优先遍历
//	map.depthFirstTraversal(0);
//	// 广度优先遍历
//	map.resetNode();
//	cout << endl;
//	map.breadthFirstTraversal(0);
//
//	return 0;
//}
