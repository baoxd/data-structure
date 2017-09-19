/*
 * Edge.cpp
 *
 *  Created on: 2017Äê9ÔÂ19ÈÕ
 *      Author: baoxd
 */
#include "Edge.h"

Edge::Edge(int nodeIndexA , int nodeIndexB, int weightValue)
{
	m_iNodeIndexA = nodeIndexA;
	m_iNodeIndexB = nodeIndexB;
	m_iWeightValue = weightValue;
	m_bSelected = false;
}




