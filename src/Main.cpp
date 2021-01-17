#include "ProgressBar.hpp"

int main()
{
	ProgressBar bar {' ', '#', 48};
	bar.fillUpCells(6);
	bar.displayPercentage();
	bar.end();

	return 0;
}
