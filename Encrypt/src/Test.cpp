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

int main() {
	// MD5����
//	string s=getMD5("abc");
//	cout << s << endl;

	// DES����
	string s = "abcdefgh";
	string k = "12345678";
	char out[8];
	bitset<64> plain = charToBitset(s.c_str());
	key = charToBitset(k.c_str());
	// ����16������Կ
	generateKeys();
	bitset<64> cipher = encrypt(plain);
	BitsetToChar(cipher, out, 64);
	cout << "����ǰ�ַ�����" << s << endl;
	cout << "���ܺ��ַ�����" << endl;
	for(int i = 0 ; i < 8; i++)
	{
		cout << out[i] ;
	}
	// ����
	bitset<64> plan;
	plan = decrypt(cipher);
	BitsetToChar(plan, out, 64);
	cout << endl << "���ܺ����ݣ�" << endl;
	for(int i = 0 ; i < 8; i++)
	{
		cout << out[i] ;
	}
	return 0;
}
