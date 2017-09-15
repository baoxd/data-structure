/*
 * Code.h
 *
 *  Created on: 2017年9月15日
 *      Author: baoxd
 */

#ifndef CODE_H_
#define CODE_H_
const int MAX_SIZE = 10;

class Code{
public:
	Code(char data = '\0', int weight = -1);
	// 字符value
	char m_cData;
	// 字符权值
	int m_iWeight;
	// 字符编码
	char *m_pSeq;
	// 是否已被选
	bool hasSelect;
};

Code::Code(char data, int weight)
{
	m_cData = data;
	m_iWeight = weight;
	hasSelect = false;
	m_pSeq = new char[MAX_SIZE];
	for(int i = 0 ; i < MAX_SIZE; i++)
	{
		m_pSeq[i] = '\0';
	}
}


#endif /* CODE_H_ */
