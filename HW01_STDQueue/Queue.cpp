#include "Queue.h"

//default constructor
template <typename T> Queue<T>::Queue()
{
	arr = new T[1];
	arrSize = 1;
	elementNum = 0;
}

//copy constructor
template <typename T> Queue<T>::Queue(const Queue& copy)
{
	elementNum = stack.elementNum;

	arrSize = stack.arrSize;
	arr = new T[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = stack.arr[i];
	}
}

//copy assignment
template<typename T> Queue<T>& Queue<T>::operator=(const Queue<T>& copy)
{
	if (&stack == this)
	{
		return *this;
	}

	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}

	elementNum = stack.elementNum;

	arrSize = stack.arrSize;

	arr = new T[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = stack.arr[i];
	}

	return *this;

}

//destructor
template<typename T> Queue<T>::~Queue()
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
 template<typename T> void Queue<T>::push(T item)
{

	 //check to see if the arr needs resizing
	 if (arrSize == elementNum)
	 {
		 //-if so, double the size of the arr
		 arrSize *= 2;
	 }

	 T* tempArr;

	 //the index the new variable will go
	 int targetIndex = 0;

	 int currentIndex = 1;

	 while (item.GetAge() > arr[currentIndex].GetAge())
	 {
		 currentIndex++;
		 targetIndex++;

		 if (currentIndex == elementNum)
		 {
			 break;
		 }
	 }
	 

	 //create a temp arr that is the same size of the thing
	 tempArr = new T[arrSize];

	 //copy all values up to the targetIndex of the new item
	 for (int i = 0; i < targetIndex; i++)
	 {
		 tempArr[i] = arr[i];
	 }

	 //add the new item
	 tempArr[targetIndex] = item.GetAge();

	 //add the rest of the items
	 for(int i = targetIndex + 1; i < elementNum; i++)
	 {
		 tempArr[i] = arr[i];
	 }

	 //increase element num by 1
	 elementNum++;

	 //delete the old arr
	 delete[] arr;

	 //assign the new arr to temp
	 arr = tempArr;

	 //delete the temp pointer
	 tempArr = nullptr;
}

 template<typename T> T Queue<T>::pop()
 {
	 if (elementNum == 0)
	 {
		 return NULL;
	 }

	 elementNum--;

	 return arr[elementNum];
 }

 template<typename T> void Queue<T>::print()
 {
	 for (int i = 0; i < elementNum; i++)
	 {
		 std::cout << arr[i] << " ";
	 }

	 std::cout << std::endl;
 }

 template<typename T> int Queue<T>::getSize()
 {
	 return elementNum;
 }

 template<typename T> bool Queue<T>::isEmpty()
 {
	 return elementNum == 0;
 }



