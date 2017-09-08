/*
 * Person.h
 *
 *  Created on: 2017Äê9ÔÂ8ÈÕ
 *      Author: baoxd
 */

#ifndef PERSON_H_
#define PERSON_H_

using namespace std;

class Person{
public:
	Person(int age = 0, string name = "");
	string getName();
	int getAge();
private:
	string m_sName;
	int m_iAge;
};

Person::Person(int age, string name)
{
	m_iAge = age;
	m_sName = name;
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
