#include "ProgressBar.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main()
{
	ProgressBar foo {'.', '#', 30};

	foo.done = 0;
	foo.todo = 27;

	std::cout << "Doing a task\n";

	for(std::size_t i = 0; i < foo.todo; ++i)
	{
		std::this_thread::sleep_for(0.1s);

		foo.fillUp();
		++foo.done;

		foo.displayPercentage();

		std::cout << " | ";

		foo.displayTasksDone();
	}

	foo.end();

	std::cout << "Done!\n";

	return 0;
}
