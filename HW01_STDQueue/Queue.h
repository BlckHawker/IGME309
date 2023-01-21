/*----------------------------------------------
Programmer: Kovu Bentley
Date: 2023/01
----------------------------------------------*/
#ifndef __QUEUECLASS_H_
#define __QUEUECLASS_H_

#include <iostream>
#include "Node.h"

template <typename T> class Queue
{

	private:
		Node<T>* head;
		Node<T>* tail;

		//what is inside the queue
		int elementNum;

	public:
		//constructor
		Queue()
		{
			elementNum = 0;
			head = nullptr;
			tail = nullptr;
		}

		//constructor with an object
		Queue(T item)
		{
			elementNum = 1;
			head = new Node<T> (item);
			tail = head;
		}

		//copy constructor
		Queue(const Queue& copy)
		{
			elementNum = copy.elementNum;

			head = copy.head;
			tail = copy.tail;

			copy.head = nullptr;
			copy.tail = nullptr;
		}

		//copy assignment
		Queue& operator=(const Queue& copy)
		{
			if (&copy == this)
			{
				return *this;
			}

			if (head != NULL)
			{
				Node<T> currentHead = head;
				Node<T> newHead = head.getNext();

				while (newHead != NULL)
				{
					delete currentHead;
					currentHead = newHead;
					newHead = currentHead.getNext();
				}

				delete currentHead;
			}

			elementNum = copy.elementNum;

			head = copy.head;
			tail = copy.tail;

			return this*;
		}

		//destructor
		~Queue()
		{
			elementNum = 0;

			if (head != nullptr)
			{
				Node<T>* currentHead = head;
				Node<T>* newHead = head->getNext();

				while (newHead != nullptr)
				{
					delete currentHead;
					currentHead = newHead;
					newHead = currentHead->getNext();
				}

				delete currentHead;
			}
		}

		//push
		void push(T item)
		{
			if (elementNum == 0)
			{
				head = new Node<T>(item);
				tail = head;
				return;
			}

			//find which node the new item will be placed
			Node<T>* currentNode = head;
			Node<T>* nextNode = currentNode->getNext();


			while (currentNode->getNext() == NULL || currentNode->getValue() > nextNode->getValue())
			{
				currentNode = nextNode;
				nextNode = nextNode->getNext();
			}

			if (currentNode->getNext() == NULL)
			{
				tail->setNext(new Node<T>(item));
				tail = tail->getNext();
			}

			else
			{
				Node<T>* target = new Node<T>(item);

				Node<T>* targetNext = currentNode->getNext();

				currentNode->setNext(target);

				target->setNext(targetNext);
			}

			elementNum++;
		}

		//pop
		T pop()
		{
			Node<T> node = head;

			T value = node.getValue();

			head = head.getNext();

			delete node;

			return value;
		}

		//Print
		void print()
		{
			Node<T>* currentNode = head;
			do
			{
				std::cout << currentNode->getValue() << " ";
				currentNode = currentNode->getNext();

			} while (currentNode != nullptr);
		}

		//GetSize
		int getSize()
		{
			return elementNum;
		}


		//IsEmpty
		bool isEmpty()
		{
			return elementNum == 0;
		}

};

#endif __QUEUECLASS_H_