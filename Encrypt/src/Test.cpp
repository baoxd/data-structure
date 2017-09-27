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

int main() {
	string s=getMD5("abc");
	cout << s << endl;
	return 0;
}
