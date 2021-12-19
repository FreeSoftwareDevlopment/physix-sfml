#include <chrono>
#define tTos(x) ((((float)x)) / 1000)
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

class timeElapsed {
private:
	std::chrono::steady_clock::time_point startt;
public:
	void start();
	double end();
};
