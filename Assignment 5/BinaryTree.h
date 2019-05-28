#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "Position.h"

using namespace std;

/*struct Node{
        Position *left; 
        Position *right;
        Position *parent;
    };*/

class BinaryTree
{
private:
	Position *root;
	int size;
	// Position *left; 
 //    Position *right;
 //    Position *parent;

public:
	// BinaryTree(Position* l, Position* r, Position* p, int s) :
	// 	 size(s), left(new Position), right(new Position), parent(new Position) {}
	// BinaryTree(Position *p, int n) :
	// 	root(new Position), size(n) {}
	BinaryTree() :
		root(NULL), size(0) {}
	// static Position *p;
	// BinaryTree() {
	// 	p = NULL;
	// }
	void Rotation(Position *p, const char d);
	Position* newNode(int e, Position *p, Position *l, Position *r);
	Position* newRoot(int e);
	void insertRight(Position *r, int pos, int e);
	void insertLeft(Position *r, int pos, int e);
	void inOrderPrint(Position *r) const;
	Position* getRoot() const;
	void changeRoot(Position *r);
	void caterpillarMode(Position *r);
	// Position* findPosition(Position *cur, int pos) const;
};


#endif