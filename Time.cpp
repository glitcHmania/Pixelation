#include "Time.h"

namespace Time
{
	namespace
	{	
		std::vector<std::shared_ptr<TimeTracker>> trackers;
		float deltaTime = 0.0f;
		auto last = std::chrono::steady_clock::now();
		float average[180] = { 0.0f }; int i = 0;
	}

	std::shared_ptr<TimeTracker> RequestTracker(float period)
	{
		auto tracker = std::make_shared<TimeTracker>(period);
		trackers.emplace_back(tracker);
		return tracker;
	}

	void Time::CalculateDeltaTime()
	{
		const auto old = last;
		last = std::chrono::steady_clock::now();
		const std::chrono::duration<float> t = last - old;
		deltaTime = t.count();

		for (auto t : trackers)
			t->CalculateTime();

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


	TimeTracker::TimeTracker(float _limit)
		:
		period(_limit)
	{
		timePassed = 0.0f;
	}
	void TimeTracker::CalculateTime()
	{
		timePassed += deltaTime;
	}
	float TimeTracker::GetPeriod()
	{
		return period;
	}
	bool TimeTracker::Check()
	{
		if (timePassed >= 2 * period)
		{
			timePassed -= period;
			return true;
		}
		return false;
	}
	bool TimeTracker::CheckOnce()
	{
		if (timePassed >= period)
		{
			timePassed = 0.0f;
			return true;
		}
		return false;
	}
}