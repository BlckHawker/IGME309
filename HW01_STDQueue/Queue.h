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
		T* arr;
		int arrSize;
		int elementNum;

	public:
		//constructor
		Queue()
		{
			arr = new T[1];
			arrSize = 1;
			elementNum = 0;
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

			arrSize = copy.arrSize;
			arr = new T[arrSize];
				
			for (int i = 0; i < arrSize; i++)
			{
				arr[i] = copy.arr[i];
			}
		}

		//copy assignment
		Queue& operator=(const Queue& copy)
		{
			if (&copy == this)
			{
				return *this;
			}

			if (arr != nullptr)
			{
				delete[] arr;
				arr = nullptr;
			}

			elementNum = copy.elementNum;

			arrSize = copy.arrSize;

			arr = new T[arrSize];

			for (int i = 0; i < arrSize; i++)
			{
				arr[i] = copy.arr[i];
			}

			return *this;

		}

		//destructor
		~Queue()
		{
			elementNum = 0;
			arrSize = 0;

			if (arr != nullptr)
			{
				delete[] arr;
				arr = nullptr;
			}
		}

		//push
		void push(T item)
		{
			T* tempArr;

			if (arrSize == elementNum)
			{
				arrSize *= 2;
			}

			tempArr = new T[arrSize];

			if (elementNum == 0)
			{
				arr[0] = item;
				elementNum++;
				tempArr = nullptr;
				return;
			}

			elementNum++;

			//find which index the new item will be placed
			int currentIndex = 0;

			T currentValue = getValue(arr[0]);
			T itemValue = getValue(item);

			while (!(itemValue < currentValue) && currentIndex + 1 != elementNum)
			{
				currentIndex++;

				currentValue = getValue(arr[currentIndex]);
			}

			for (int i = 0; i < currentIndex; i++)
			{
				tempArr[i] = arr[i];
			}

			tempArr[currentIndex] = item;

			for (int i = currentIndex + 1; i < elementNum; i++)
			{
				tempArr[i] = arr[i - 1];
			}

			arr = tempArr;

			tempArr = nullptr;
		}

		//pop
		T pop()
		{
			T* tempArr = new T[arrSize];

			elementNum--;

			for (int i = 0; i < elementNum; i++)
			{
				tempArr[i] = arr[i + 1];
			}

			T item = arr[0];

			arr = tempArr;

			tempArr = nullptr;

			return item;
		}

		//Print
		void print()
		{
			for (int i = 0; i < elementNum; i++)
			{
				std::cout << arr[i] << " ";
			}

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
			T getValue(T item)
			{
				if (typeid(AlbertoClass) == typeid(T))
				{
					return (AlbertoClass(item)).GetAge();
				}

				//if (typeid(Foo) == typeid(T))
				//{
				//	return (Foo(item)).content;
				//}

				return item;
			}

};

#endif __QUEUECLASS_H_