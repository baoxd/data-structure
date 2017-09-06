/*
 * Person.h
 *
 *  Created on: 2017年9月6日
 *      Author: baoxd
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>
using namespace std;


class Person{
public:
	Person(string name = "", int age = 0);
	virtual ~Person();
	string getName();
	int getAge();
private:
	string m_sName;
	int m_iAge;
};

Person::Person(string name, int age)
{
	m_sName = name;
	m_iAge = age;
}

Person::~Person()
{
//	cout << m_sName << "被销毁" << endl;
}

string Person::getName()
{
	return m_sName;
}

int Person::getAge()
{
	return m_iAge;
}



#endif /* PERSON_H_ */
