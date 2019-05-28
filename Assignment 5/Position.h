#ifndef POSITION_H
#define POSITION_H
#include <iostream>

using namespace std;



class Position
{
private:
    Position *leftChild; 
    Position *rightChild;
    Position *parentOf;
    int pos;
public:
    // Position *left; 
    // Position *right;
    // Position *parent;
	/*struct Node{
        Position *left; 
        Position *right;
        Position *parent;
    };*/

    //Node *root;
    Position(int e, Position *p, Position *l, Position *r) {
    	leftChild = l;
    	rightChild = r;
    	parentOf = p;
        pos = e;
    }
	
	// Position* rightChild();
	// Position* leftChild();
	// Position* parentOf();
    int getPos() const;
    void addRight(Position* r);
    void addLeft(Position* l);
    void addParent(Position *p);
    Position* right() const;
    Position* left() const;
    Position* parent() const;
	bool isRoot() const;
	bool isLeaf() const;
	
	
};


#endif