//============================================================================
// Name        : Tree.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Tree.h"
#include "Node.h"

/**
 * ¶þ²æÊ÷
 *
 * 		 1
 * 	  2	    3
 *  4   5  6  7
 */


int main() {
	Node<char> *root = new Node<char>;
	root->data = '1';
	Tree<char> tree(root);
	cout << "Éî¶È£º" << tree.depth();
	return 0;
}
