#include "Time.h"

namespace Time
{
	namespace
	{
		float deltaTime = 0.0f;
		auto last = std::chrono::steady_clock::now();
		float average[180] = { 0.0f }; int i = 0;
	}

	void Time::CalculateDeltaTime()
	{
		const auto old = last;
		last = std::chrono::steady_clock::now();
		const std::chrono::duration<float> t = last - old;
		deltaTime = t.count();
		average[i] = (1.0f / deltaTime);
		i = (i + 1) % 180;
	}
	const float GetDeltatime()
	{
		return deltaTime;
	}
	const float GetTime()
	{
		return std::chrono::duration<float>(std::chrono::steady_clock::now().time_since_epoch()).count();
	}
	float FPS()
	{
		float sum = 0.0f;
		for (int x = 0; x < 180; x++)
		{
			sum += average[x];
		}
		return sum / 180.0f;
	}
}