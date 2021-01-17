#include "ProgressBar.hpp"

int main()
{
	ProgressBar bar {' ', '#', 101};
	bar.fillUp();
	bar.displayPercentage();

	return 0;
}
