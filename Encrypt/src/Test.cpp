//============================================================================
// Name        : Encrypt.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string>
#include "MD5.h"
#include "DES.h"
#include "3DES.h"

int main() {
	// MD5����
//	string s=getMD5("abc");
//	cout << s << endl;

	// DES����
//	string s = "abcdefgh";
//	string k = "12345678";
//	char out[8];
//	bitset<64> plain = charToBitset(s.c_str());
//	key = charToBitset(k.c_str());
//	// ����16������Կ
//	generateKeys();
//	bitset<64> cipher = encrypt(plain);
//	BitsetToChar(cipher, out, 64);
//	cout << "����ǰ�ַ�����" << s << endl;
//	cout << "���ܺ��ַ�����" << endl;
//	for(int i = 0 ; i < 8; i++)
//	{
//		cout << out[i] ;
//	}
//	// ����
//	bitset<64> plan;
//	plan = decrypt(cipher);
//	BitsetToChar(plan, out, 64);
//	cout << endl << "���ܺ����ݣ�" << endl;
//	for(int i = 0 ; i < 8; i++)
//	{
//		cout << out[i] ;
//	}

	// 3DES����
	CDesEncode des;
	char src[512]="abcdefgh";
	char key[25]="201612302016123020161230";
	cout << "����ǰ�ַ���:" << src << endl;
	des.Des(src,key,false,true);
	cout << "���ܺ�ʮ������:" << src << endl;
	cout << "���ܺ��ַ�����" << des.m_FCiphertextAnyLength<<endl;
	cout << "����ǰʮ������:" << src << endl;
	des.Des(src,key,true,true);
	cout << "���ܺ�ʮ������:" << src << endl;

	return 0;
}
