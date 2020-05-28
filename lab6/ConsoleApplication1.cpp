#include "pch.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

#define MAX 10
mutex mt;

void Producer(int &product)
{
	while (true)
	{
		if (product <= (MAX - 3))
		{
			mt.lock();
			product += 3;
			cout << "Producer " << product << endl;
			mt.unlock();
			this_thread::sleep_for(chrono::milliseconds(1500));
			
		}
	}
	
}

void Consumer(int &product)
{
	while (true)
	{
		if (product > 0)
		{
			mt.lock();
			product--;
			cout << "Consumer " << product << endl;
			mt.unlock();
			this_thread::sleep_for(chrono::milliseconds(1000));
			
		}
	}
}

int main()
{
	int product = 0;
	thread producer(Producer,std::ref(product));
	thread consumer(Consumer, std::ref(product));

	producer.join();
	consumer.join();
}

