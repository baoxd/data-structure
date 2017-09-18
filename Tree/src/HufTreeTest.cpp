/*
 * HufTreeTest.cpp
 *
 *  Created on: 2017年9月15日
 *      Author: baoxd
 */
#include <iostream>
#include "Code.h"
#include "HufTree.h"
using namespace std;
#include <vector>

/**
 * 霍夫曼树 -- 最小二叉树
 * 字符：A  B  C  D
 * 权值：7  5  2  4
 *
 *             18
 *
 *          a(7)  11
 *
 *             b(5)  6
 *
 *                c(2) d(4)
 *
 */



//int main()
//{
//	cout << "最小二叉树测试..." << endl;
//	Code codes[4];
//	Code code1;
//	code1.m_cData = 'A';
//	code1.m_iWeight = 7;
//	Code code2;
//	code2.m_cData = 'B';
//	code2.m_iWeight = 5;
//	Code code3;
//	code3.m_cData = 'C';
//	code3.m_iWeight = 2;
//	Code code4;
//	code4.m_cData = 'D';
//	code4.m_iWeight = 4;
//
//	codes[0] = code1;
//	codes[1] = code2;
//	codes[2] = code3;
//	codes[3] = code4;
//
//	HufTree *hufTree = new HufTree(codes, 4);
//	hufTree->createHufCode();
//
//	return 0;
//}



