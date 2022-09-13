#pragma once
#include<Windows.h>

//FrameTimer.h
class FrameTimer{
	public:
		void init(int);
		int FramesToUpdate();
		int GetFPS();

	private:
		LARGE_INTEGER timerFreq;
		LARGE_INTEGER timeNow;
		LARGE_INTEGER timePrevious;
		int requestedFPS;
		float ticksPerFrame;
		float ticksSinceLastUpdate;
		
};

