/*
 * coordinate.h
 *
 *  Created on: 2017Äê9ÔÂ6ÈÕ
 *      Author: baoxd
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

class Coordinate{
public:
	Coordinate();
	Coordinate(double x, double y);
	virtual ~Coordinate(){};
	double getX();
	double getY();
private:
	double m_iX;
	double m_iY;
};

#endif /* COORDINATE_H_ */
