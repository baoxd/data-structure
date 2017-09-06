//============================================================================
// Name        : Queue.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "CircularQueue.h"
#include "Coordinate.h"
using namespace std;

// 打印整形
void printInt(int o)
{
	cout << o << endl;
}

// 打印Coordinate类型
void printCoordinate(Coordinate o)
{
	cout << "(" << o.getX() << "," << o.getY() << ")" << endl;
}


int main() {
	cout << "***************int型环形队列**************" << endl;
	CircularQueue<int> cQueueInt(3);
	// 入队列
	cQueueInt.enQueue(10);
	cQueueInt.enQueue(20);
	cQueueInt.enQueue(30);
	cout << "length: " << cQueueInt.length() << endl;

	// 出队
	int tmp1, tmp2, tmp3;
	cQueueInt.deQueue(tmp1);
	cQueueInt.deQueue(tmp2);
	cQueueInt.deQueue(tmp3);
	cout << "出队数据：" << tmp1 << endl;
	cout << "出队数据：" << tmp2 << endl;
	cout << "出队数据：" << tmp3 << endl;

	cQueueInt.enQueue(11);
	cQueueInt.enQueue(22);
	cQueueInt.enQueue(33);
	cQueueInt.enQueue(44);
	cQueueInt.printQueue(&printInt);


	cout << "***************Coordinate**************" << endl;
	CircularQueue<Coordinate> cQueueCoor(3);
	Coordinate c1 = Coordinate(1,2);
	Coordinate c2 = Coordinate(2,3);
	Coordinate c3 = Coordinate(3,4);

	// 入队
	cQueueCoor.enQueue(c1);
	cQueueCoor.enQueue(c2);
	cQueueCoor.enQueue(c3);
	cQueueCoor.printQueue(&printCoordinate);

	// 出队
	Coordinate cTmp;
	cQueueCoor.deQueue(cTmp);
	cout << cTmp.getX() << "," << cTmp.getY() << endl;

	Coordinate c4 = Coordinate(4,5);
	Coordinate c5 = Coordinate(5,6);
	Coordinate c6 = Coordinate(6,7);

	cQueueCoor.enQueue(c4);
	cQueueCoor.enQueue(c5);
	cQueueCoor.enQueue(c6);

	cQueueCoor.printQueue(&printCoordinate);
}
