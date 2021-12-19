#include "timeelapsed.h"

void timeElapsed::start()
{
	startt = std::chrono::high_resolution_clock::now();
}

double timeElapsed::end()
{
	return std::chrono::duration<double, std::milli>(
		std::chrono::high_resolution_clock::now() - startt
		).count();
}
