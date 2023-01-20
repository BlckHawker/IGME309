/*----------------------------------------------
Programmer: Kovu Bentley
Date: 2023/01
----------------------------------------------*/
#ifndef __QUEUECLASS_H_
#define __QUEUECLASS_H_

#include <iostream>

template <typename T> class Queue 
{

	private:
		//what will hold the values
		T* arr;

		//the size of the arr
		int arrSize;

		//what is inside the stack
		int elementNum;

	public:
		//constructor
		Queue();

		//copy constructor
		Queue(Queue const& copy);

		//copy assignment
		Queue& operator=(Queue const& copy);

		//destructor
		~Queue();

		//push
		void push(T item);

		//pop
		T pop();

		//Print
		void print();

		//GetSize
		int getSize();

		//IsEmpty
		bool isEmpty();
};

#endif //__EXAMPLECLASS_H__