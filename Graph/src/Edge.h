/*
 * Edge.h
 *
 *  Created on: 2017��9��19��
 *      Author: baoxd
 */

#ifndef EDGE_H_
#define EDGE_H_
/**
 * ��
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
