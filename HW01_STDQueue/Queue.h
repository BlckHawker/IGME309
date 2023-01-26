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
		//constructor that doesn't hold any items
		Queue()
		{
			arr = new T[1];
			arrSize = 1;
			elementNum = 0;
		}

		//constructor that takes one item
		Queue(T item)
		{
			elementNum = 1;
			arrSize = 1;

			arr = new T[1];

			arr[0] = item;
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
				delete arr;
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
			if (arr != nullptr)
			{
				delete[] arr;

			}
			arr = nullptr;
			delete arr;

			elementNum = 0;
			arrSize = 0;
		}

		//adds the new item starting from lowest to highest
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
				delete[] tempArr;
				tempArr = nullptr;
				return;
			}

			elementNum++;

			//find which index the new item will be placed
			int currentIndex = 0;

			T currentValue = arr[0];
			T itemValue = item;

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

			delete[] arr;
			arr = tempArr;

			tempArr = nullptr;
		}

		//removes the first item in the list and returns it
		T pop()
		{
			T* tempArr = new T[arrSize];

			elementNum--;

			for (int i = 0; i < elementNum; i++)
			{
				tempArr[i] = arr[i + 1];
			}

			T item = arr[0];

			delete[] arr;

			arr = tempArr;

			tempArr = nullptr;
			delete tempArr;
			return item;
		}

		//prints all items in the queue
		void print()
		{
			for (int i = 0; i < elementNum; i++)
			{
				std::cout << arr[i] << " ";
			}

			std::cout << std::endl;
		}

		//tells how many items are in the queue
		int getSize()
		{
			return elementNum;
		}


		//tells if the queue is empty
		bool isEmpty()
		{
			return elementNum == 0;
		}

		private:
			//helper function to evaluate where an item goes in the queue
			T getValue(T item)
			{
				if (typeid(AlbertoClass) == typeid(T))
				{
					return (AlbertoClass(item)).GetAge();
				}

				return item;
			}

};

#endif __QUEUECLASS_H_