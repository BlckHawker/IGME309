/*----------------------------------------------
Programmer: Kovu Bentley
Date: 2023/01
----------------------------------------------*/
#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>

//System Class
template <typename T> class Node
{
private:
	T item;
	Node* next;

public:

	//constructor
	Node(T item)
	{
		this->item = item;
		next = nullptr;
	}

	//copy constructor
	Node(const Node& copy)
	{
		item = copy.item;

		next = copy.next;
	}

	//copy assignment
	Node& operator=(const Node& copy)
	{
		if (&copy == this)
		{
			return *this;
		}

		if (next != nullptr)
		{
			delete next;
			next = nullptr;
		}

		item = copy.item;

		head = copy.head;
		tail = copy.tail;

		return *this;
	}

	bool operator==(const Node& copy)
	{
		return cmp(lhs, rhs) == 0; 
	}

	//destructor
	~Node()
	{
		item = NULL;

		if (next != nullptr)
		{
			delete next;
			next = nullptr;
		}
	}

	Node* getNext()
	{
		return next;
	}

	void setNext(Node* next)
	{
		this->next = next;
	}

	float getValue()
	{
		if (typeid(AlbertoClass) == typeid(T))
		{
			return (AlbertoClass(item)).GetAge();
		}

		return item;
	}

};


#endif __NODE_H_