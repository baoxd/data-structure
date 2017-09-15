/*
 * Code.h
 *
 *  Created on: 2017��9��15��
 *      Author: baoxd
 */

#ifndef CODE_H_
#define CODE_H_
const int MAX_SIZE = 10;

class Code{
public:
	Code(char data = '\0', int weight = -1);
	// �ַ�value
	char m_cData;
	// �ַ�Ȩֵ
	int m_iWeight;
	// �ַ�����
	char *m_pSeq;
	// �Ƿ��ѱ�ѡ
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
