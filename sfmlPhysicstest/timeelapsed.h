#include <chrono>

class timeElapsed {
private:
	std::chrono::steady_clock::time_point startt;
public:
	void start();
	double end();
};
