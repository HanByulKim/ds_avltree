#pragma once
#include "Node.h"
template<typename T>
class Avl{
public:

	Avl(){}

	void insert(T n){ insert(n, root); }
	void insert(T x, Node<T>*& t){
		if (t == NULL) t = new Node<T>(x);
		else if (x < t->n){
			insert(x, t->left);
			if (height(t->left) - height(t->right) == 2){
				if (x < t->left->n) RRrotate(t);	//LL
				else RLrotate(t);	//LR
			}
		}
		else if (x>t->n){
			insert(x, t->right);
			if (height(t->right) - height(t->left) == 2){
				if (x < t->right->n) LRrotate(t);	//RL
				else LLrotate(t);	//RR
			}
		}
		t->height = std::max(height(t->left), height(t->right)) + 1;
	}
	int height(Node<T>* t){
		if (t == NULL) return -1;
		else return t->height;
	}

	void LLrotate(Node<T>*& t){
		Node<T>* centre = t->right;
		t->right = centre->left;
		centre->left = t;
		t->height = std::max(height(t->left), height(t->right)) + 1;
		centre->height = std::max(height(t), height(centre->right)) + 1;
		t = centre;
	}
	void RRrotate(Node<T>*& t){
		Node<T>* centre = t->left;
		t->left = centre->right;
		centre->right = t;
		t->height = std::max(height(t->left), height(t->right)) + 1;
		centre->height = std::max(height(centre->left), height(t)) + 1;
		t = centre;
	}
	void LRrotate(Node<T>*& t){
		RRrotate(t->right);
		LLrotate(t);
	}
	void RLrotate(Node<T>*& t){
		LLrotate(t->left);
		RRrotate(t);
	}

	void print(){ print(root); }
	void print(Node<T>* t){
		if (t == NULL) return;
		std::cout << t->n << std::endl;
		print(t->left);
		print(t->right);
	}

private:
	Node<T>* root;
};