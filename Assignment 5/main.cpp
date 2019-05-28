#include <iostream>
#include "Position.h"
#include "BinaryTree.h"

using namespace std;

/*===========================================
ASSIGNMENT 5 QUESTION 1

        ===========================================
*/
Position* Position::right() const{
	if(isLeaf()) return NULL;
	//BinaryTree::p = BinaryTree::p->right;
	//return BinaryTree::p->right;
	return rightChild;
}

Position* Position::left() const{
	if(isLeaf()) return NULL;
	//BinaryTree::p = BinaryTree::p->left;
	//return BinaryTree::p->left;
	return leftChild;
}

Position* Position::parent() const{
	if(isRoot()) return NULL;
	//BinaryTree::p = BinaryTree::p->parent;
	//return BinaryTree::p->parent;
	return parentOf;
}

bool Position::isRoot() const{
	//return BinaryTree::p == NULL;
	return parentOf == NULL;
}

bool Position::isLeaf() const{
	//return BinaryTree::p->right == NULL && BinaryTree::p->left == NULL;
	return rightChild == NULL && leftChild == NULL;
}

int Position::getPos() const{
	return pos;
}

void Position::addRight(Position *r){
	rightChild = r;
}

void Position::addLeft(Position *l){
	leftChild = l;
}

void Position::addParent(Position *p){
	parentOf = p;
}

// BT METHODS ==========================================================================

Position* BinaryTree::newNode(int e, Position *p, Position *l, Position *r){
	return new Position(e, p, l, r);
}

Position* BinaryTree::newRoot(int e){
	size++;
	root = newNode(e, NULL, NULL, NULL);
	return root;
}

void BinaryTree::insertRight(Position *r, int pos, int e){
	//BinaryTree* cur = T;
	//Position* cur = root;
	// while(!T->root->isLeaf() && !(T->root->getPos() == e)){
	// 	cur = cur->left();
	// }
	
	// if(!cur->root->isLeaf()){
	// 	cur->root = cur->root->left();
	// 	cur = insertRight(cur, pos, e);
	// }
	// if (cur->root->getPos() == pos)
	// {
	// 	Position* newnode = newNode(e, cur->root, NULL, NULL);
	// 	cur->root->addRight(newnode);
	// 	cur->size++;
	// 	return cur;
	// }
	// if(!cur->root->isLeaf()){
	// 	cur->root = cur->root->right();
	// 	cur = insertRight(cur, pos, e);
	// }
	if(!r->isLeaf()){
		//cur = cur->left();
		insertRight(r->left(), pos, e);
	}
	if (r->getPos() == pos)
	{
		Position* newnode = newNode(e, r, NULL, NULL);
		r->addRight(newnode);
		size++;
		return;
	}
	if(!r->isLeaf()){
		//root = root->right();
		insertRight(r->right(), pos, e);
	}
	//return cur;
}

void BinaryTree::insertLeft(Position *r, int pos, int e){
	if(!r->isLeaf()){
		insertLeft(r->left(), pos, e);
	}
	if (r->getPos() == pos)
	{
		Position* newnode = newNode(e, r, NULL, NULL);
		r->addLeft(newnode);
		size++;
		return;
	}
	if(!r->isLeaf()){
		insertLeft(r->right(), pos, e);
	}
}

void BinaryTree::inOrderPrint(Position *r) const{
	// BinaryTree* cur = T;
	// if(!cur->root->isLeaf()){
	// 	cur->root = cur->root->left();
	// 	inOrderPrint(cur);
	// }
	// cout << cur->root->getPos() << endl;
	// if(!cur->root->isLeaf()){
	// 	cur->root = cur->root->right();
	// 	inOrderPrint(cur);
	// }
	if(!r->isLeaf() && r->left() != NULL){
		//root = root->left();
		inOrderPrint(r->left());
	}
	cout << r->getPos() << ' ';
	if(!r->isLeaf() && r->right() != NULL){
		//root = root->right();
		inOrderPrint(r->right());
	}
}

Position* BinaryTree::getRoot() const{
	return root;
}

void BinaryTree::Rotation(Position *p, const char d){
	if(d == 'l'){
		Position *temp = p->right();
		p->addRight(temp->left());
		if (temp->left() != NULL)
		{
			//p->rightChild()->leftChild()->parentOf() = p;
			temp->left()->addParent(p);
		}
		//temp->parentOf() = p->parentOf();
		if (p->isRoot())
		{
			//cerr << "ballst" << endl;
			temp->addParent(NULL);
			//cerr << "Swag" << endl;
		} else
		{
			//cerr << "Swa3" << endl;
			temp->addParent(p->parent());
			//cerr << "Swag 2" << endl;
		}
		if (p->isRoot())
		{
			root = temp;
		} else if (p == p->parent()->left())
		{
			p->parent()->addLeft(temp);
		} else
		{
			p->parent()->addRight(temp);
		}
		temp->addLeft(p);
		p->addParent(temp);
	} else if (d == 'r')
	{
		Position *temp = p->left();
		p->addLeft(temp->right());
		//cerr << "Swap" << endl;
		if (temp->right() != NULL)
		{
			//p->rightChild()->leftChild()->parentOf() = p;
			temp->right()->addParent(p);
			//cerr << "Swap2" << endl;
		}
		//temp->parentOf() = p->parentOf();
		if (p->isRoot())
		{
			//cerr << "ballst" << endl;
			temp->addParent(NULL);
			//cerr << "Swag" << endl;
		} else
		{
			//cerr << "Swa3" << endl;
			temp->addParent(p->parent());
			//cerr << "Swag 2" << endl;
		}
		
		//cerr << "Swap parent" << endl;
		if (p->isRoot())
		{
			root = temp;
		} else if (p == p->parent()->left())
		{
			p->parent()->addLeft(temp);
		} else
		{
			p->parent()->addRight(temp);
		}
		temp->addRight(p);
		p->addParent(temp);
	}
}

void BinaryTree::changeRoot(Position *r){
	root = r;
}

// Position* BinaryTree::findPosition(Position *cur, int pos) const{
// 	if(!cur->isLeaf() && cur->left() != NULL){
// 		inOrderPrint(cur->left());
// 	}
// 	if (cur->getPos() == pos)
// 	{
// 		return
// 	}
// 	if(!cur->isLeaf() && cur->right() != NULL){
// 		inOrderPrint(cur->right());
// 	}
// }

void BinaryTree::caterpillarMode(Position *r){
	// Position* cur = r;
	// while(!r->getRoot()->left()->isLeaf()){
	// 	r->Rotation(r->getRoot(), 'r');
	// }
	// while(!r->getRoot()->isLeaf()){

	// }
	if (!r->isLeaf())
	{
		//cerr << "lol" << endl;
		caterpillarMode(r->right());
	}
	//cerr << "dank" << endl;
	if (!r->isLeaf() && !r->left()->isLeaf())
	{
		//cerr << "rootatin" << endl;
		Rotation(r, 'r');
	}
	//cerr << "don ratat" << endl;
}

int main(int argc, char const *argv[])
{
	BinaryTree* T = new BinaryTree;
	T->newRoot(1);

	// TEST 1 =============================
	// T->insertLeft(T->getRoot(), 1, 2);
	// T->insertRight(T->getRoot(), 1, 3);
	// T->insertLeft(T->getRoot(), 2, 4);
	// T->insertRight(T->getRoot(), 2, 5);
	// T->insertLeft(T->getRoot(), 5, 10);
	// T->insertRight(T->getRoot(), 5, 11);
	//cout << "Done inserting." << endl;
	// TEST 1 =============================
	// TEST 2 =============================
	T->insertLeft(T->getRoot(), 1, 2);
	T->insertRight(T->getRoot(), 1, 3);
	T->insertLeft(T->getRoot(), 2, 4);
	T->insertRight(T->getRoot(), 2, 5);
	T->insertLeft(T->getRoot(), 3, 6);
	T->insertRight(T->getRoot(), 3, 7);
	T->insertLeft(T->getRoot(), 4, 8);
	T->insertRight(T->getRoot(), 4, 9);
	T->insertLeft(T->getRoot(), 5, 10);
	T->insertRight(T->getRoot(), 5, 11);
	T->insertLeft(T->getRoot(), 6, 12);
	// TEST 2 =============================

	while(!T->getRoot()->left()->isLeaf()){
		T->Rotation(T->getRoot(), 'r');
	}
	T->caterpillarMode(T->getRoot());
	// T->Rotation(T->getRoot(), 'r');
	//cout << "Done rotating." << endl;

	T->inOrderPrint(T->getRoot());
	cout << endl;
	return 0;
}