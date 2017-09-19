/*
 * Edge.h
 *
 *  Created on: 2017Äê9ÔÂ19ÈÕ
 *      Author: baoxd
 */

#ifndef EDGE_H_
#define EDGE_H_
/**
 * ±ß
 */

class Edge{
public:
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);
	int m_iNodeIndexA;
	int m_iNodeIndexB;
	int m_iWeightValue;
	bool m_bSelected;
};


#endif /* EDGE_H_ */
