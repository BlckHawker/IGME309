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

			elementNum = 0;
		}

		//push
		void push(T item)
		{
			if (elementNum == 0)
			{
				head = new Node<T>(item);
				tail = head;
				elementNum++;
				return;
			}

			//find which node the new item will be placed
			Node<T>* currentNode = head;
			Node<T>* nextNode = currentNode->getNext();

			float currentValue = currentNode->getValue();
			float itemValue = getValue(item);
			float nextValue;


			if (nextNode != nullptr || nextNode != NULL)
			{
				nextValue = nextNode->getValue();
			}


			while (nextNode != nullptr && !(itemValue < nextValue))
			{
				currentNode = nextNode;
				currentValue = currentNode->getValue();

				nextNode = nextNode->getNext();

				if (nextNode != nullptr)
				{
					nextValue = nextNode->getValue();
				}
			}

			if (nextNode == nullptr)
			{
				currentNode->setNext(new Node<T>(item));
				tail = currentNode->getNext();
			}

			else if (currentNode == head)
			{
				Node<T>* newHead = new Node<T>(item);

				newHead->setNext(head);

				head = newHead;
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
			Node<T>* node = head;

			T value = node->getValue();

			head = head->getNext();

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

			std::cout << std::endl;
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

		private:
			float getValue(T item)
			{
				if (typeid(AlbertoClass) == typeid(T))
				{
					return (AlbertoClass(item)).GetAge();
				}

				return item;
			}

};

#endif __QUEUECLASS_H_