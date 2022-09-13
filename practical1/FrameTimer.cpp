#include "FrameTimer.h"

void FrameTimer::init(int fps)
{
	QueryPerformanceFrequency(&timerFreq); //ASk CPU how many ticks per second
	QueryPerformanceCounter(&timeNow); //since the pc was switch on, how many ticks?
	QueryPerformanceCounter(&timePrevious);
	//init fps time info
	requestedFPS=fps;
	//The number of intervals in the given
	//timer, per frame at the requested rate.
	ticksPerFrame = ((float)timerFreq.QuadPart / requestedFPS);
}

int FrameTimer::FramesToUpdate()
{
	int framesToUpdate = 0;
	QueryPerformanceCounter(&timeNow);
	//getting the delta time
	ticksSinceLastUpdate = (float)timeNow.QuadPart - (float)timePrevious.QuadPart;
	framesToUpdate = (int)( ticksSinceLastUpdate / ticksPerFrame );
	//If we are not updating any frames, 
	//keep the old previous timer count
	if (framesToUpdate != 0){
		QueryPerformanceCounter(&timePrevious);
	} 
	return framesToUpdate;

}

int FrameTimer::GetFPS()
{
	return requestedFPS;
}
