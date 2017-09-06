/*
 * coordinate.cpp
 *
 *  Created on: 2017Äê9ÔÂ6ÈÕ
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



