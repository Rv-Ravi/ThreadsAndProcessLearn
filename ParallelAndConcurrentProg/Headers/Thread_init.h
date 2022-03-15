#ifndef THREAD_INIT_H
#define THREAD_INIT_H

#include <iostream>
#include <thread>
#include <chrono>

void threadRun() {
	std::cout << "The thread ID is " << std::this_thread::get_id() << std::endl;
	unsigned int var = 0;
	while (1) {
		if (var >= 60)
			break;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		++var;
	}
	std::cout << "End of Thread of ID " << std::this_thread::get_id() << std::endl;

}

int main_1()
{
	std::cout << "The Main thread ID is " << std::this_thread::get_id() << std::endl;
	std::thread th1(threadRun);
	std::thread th2(threadRun);

	while (1)
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	th1.join(); th2.join();
	return 0;
}


#endif // !THREAD_INIT_H

