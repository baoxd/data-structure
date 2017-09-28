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
	// MD5测试
//	string s=getMD5("abc");
//	cout << s << endl;

	// DES测试
	string s = "abcdefgh";
	string k = "12345678";
	char out[8];
	bitset<64> plain = charToBitset(s.c_str());
	key = charToBitset(k.c_str());
	// 生成16个子密钥
	generateKeys();
	bitset<64> cipher = encrypt(plain);
	BitsetToChar(cipher, out, 64);
	cout << "加密前字符串：" << s << endl;
	cout << "加密后字符串：" << endl;
	for(int i = 0 ; i < 8; i++)
	{
		cout << out[i] ;
	}
	// 解密
	bitset<64> plan;
	plan = decrypt(cipher);
	BitsetToChar(plan, out, 64);
	cout << endl << "解密后数据：" << endl;
	for(int i = 0 ; i < 8; i++)
	{
		cout << out[i] ;
	}
	return 0;
}
