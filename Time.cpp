#include "Time.h"

namespace Time
{
	namespace
	{
		float deltaTime = 0.0f;
		auto last = std::chrono::steady_clock::now();
	}

	void Time::CalculateDeltaTime()
	{
		const auto old = last;
		last = std::chrono::steady_clock::now();
		const std::chrono::duration<float> t = last - old;
		deltaTime = t.count();
	}
	const float GetDeltatime()
	{
		return deltaTime;
	}
}