#pragma once
#include <iostream>
#include <algorithm>
template <typename T>
class Node{
public:
	Node() : left(NULL), right(NULL){}
	Node(T data) : n(data), left(NULL), right(NULL){}
	Node(T data, Node<T>* lt, Node<T>* rt) : n(data), left(lt), right(rt){}

	T n;
	Node<T>* left;
	Node<T>* right;
	int height=0;
};