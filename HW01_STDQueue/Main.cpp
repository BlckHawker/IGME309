#include "Main.h"
#include "Queue.h"
template <typename T> 
void Print(std::deque<T> a_queue)
{
	std::cout << "Begining of queue......." << std::endl;
	uint count = a_queue.size();
	for (uint i = 0; i < count; ++i)
	{
		std::cout << a_queue[i];
		std::cout << std::endl;
	}
	std::cout << "End of queue............" << std::endl;
}

void queueTests()
{
	std::cout << "==========FLOAT QUEUE==========" << std::endl << std::endl;

	Queue<float> floatQueue = Queue<float>();

	
	floatQueue.push(0);
	std::cout << "just pushed 0" << std::endl;
	std::cout << "expecting 0" << std::endl;
	std::cout << "got ";
	floatQueue.print();
	std::cout << std::endl;


	floatQueue.push(3);
	std::cout << "just pushed 3" << std::endl;
	std::cout << "expecting 0 3" << std::endl;
	std::cout << "got ";
	floatQueue.print();
	std::cout << std::endl;

	floatQueue.push(1);
	std::cout << "just pushed 1" << std::endl;
	std::cout << "expecting 0 1 3" << std::endl;
	std::cout << "got ";
	floatQueue.print();
	std::cout << std::endl;

	floatQueue.push(2);
	std::cout << "just pushed 2" << std::endl;
	std::cout << "expecting 0 1 2 3" << std::endl;
	std::cout << "got ";
	floatQueue.print();
	std::cout << std::endl << std::endl;

	floatQueue.pop();
	std::cout << "called pop" << std::endl;
	floatQueue.print();
	std::cout << std::endl << std::endl;
	
	std::cout << "==========INT QUEUE==========" << std::endl << std::endl;

	Queue<int> intQueue = Queue<int>(3);

	int pop;

	std::cout << "started with 3" << std::endl;
	std::cout << "expecting 3" << std::endl;
	std::cout << "got ";
	intQueue.print();
	std::cout << std::endl;

	pop = intQueue.pop();
	std::cout << "just popped 3" << std::endl;
	std::cout << "got " << pop;
	std::cout << std::endl;
	std::cout << "expecting" << std::endl;
	intQueue.print();
	std::cout << std::endl;

	intQueue.push(10);
	std::cout << "just pushed 10" << std::endl;
	std::cout << "expecting 10" << std::endl;
	std::cout << "got ";
	intQueue.print();
	std::cout << std::endl;

	intQueue.push(9);
	std::cout << "just pushed 9" << std::endl;
	std::cout << "expecting 9 10" << std::endl;
	std::cout << "got ";
	intQueue.print();
	std::cout << std::endl;

	pop = intQueue.pop();
	std::cout << "just popped 9" << std::endl;
	std::cout << "got " << pop;
	std::cout << std::endl;
	std::cout << "expecting 10" << std::endl;
	intQueue.print();
	std::cout << std::endl;

	intQueue.push(6);
	std::cout << "just pushed 6" << std::endl;
	std::cout << "expecting 6 10" << std::endl;
	std::cout << "got ";
	intQueue.print();
	std::cout << std::endl;

	intQueue.push(7);
	std::cout << "just pushed 7" << std::endl;
	std::cout << "expecting 6 7 10" << std::endl;
	std::cout << "got ";
	intQueue.print();
	std::cout << std::endl;

	pop = intQueue.pop();
	std::cout << "just popped 6" << std::endl;
	std::cout << "got " << pop;
	std::cout << std::endl;
	std::cout << "expecting 7 10" << std::endl;
	intQueue.print();
	std::cout << std::endl;


	intQueue.push(7);
	std::cout << "just pushed 7" << std::endl;
	std::cout << "expecting 7 7 10" << std::endl;
	std::cout << "got ";
	intQueue.print();
	std::cout << std::endl;

	intQueue.push(6);
	std::cout << "just pushed 6" << std::endl;
	std::cout << "expecting 6 7 7 10" << std::endl;
	std::cout << "got ";
	intQueue.print();
	std::cout << std::endl;



	//not clearing the float queue to make sure the destructor works on its own

	//Complex Data usage


	std::cout << "==========ALBERTO QUEUE 1==========" << std::endl << std::endl;

	Queue<AlbertoClass> albertoQueue = Queue<AlbertoClass>(AlbertoClass(29));

	std::cout << "started with 29" << std::endl;

	for (uint i = 30; i < 40; ++i)
	{
		AlbertoClass alberto(i);
		albertoQueue.push(alberto);
		std::cout << "just pushed " << i << std::endl;
	}
	std::cout << "Content" << std::endl;
	albertoQueue.print();

	std::cout << std::endl << "==========ALBERTO QUEUE 2==========" << std::endl << std::endl;
	std::cout << "Copying Alberto 1 " << std::endl;
	Queue<AlbertoClass> albertoQueue2 = albertoQueue;
	std::cout << "Printing alberto queue 2 " << std::endl;

	albertoQueue2.print();

	std::cout << "Press Enter to finish." << std::endl;

	getchar();
}

int main(void)
{
	queueTests();

	_CrtDumpMemoryLeaks();
}

