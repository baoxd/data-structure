/*
 * coordinate.cpp
 *
 *  Created on: 2017��9��6��
 *      Author: baoxd
 */
#include "Coordinate.h"

Coordinate::Coordinate()
{
}

Coordinate::Coordinate(double x, double y)
{
	m_iX = x;
	m_iY = y;
}

double Coordinate::getX(){
	return m_iX;
}

double Coordinate::getY()
{
	return m_iY;
}



