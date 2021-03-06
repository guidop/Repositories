#include "StdAfx.h"
#include <Windows.h>
#include "Timer.h"
#include <iostream>
#ifndef _TIMER_H_ 
#define _TIMER_H_ 
#endif

using namespace std;

CTimer::CTimer(void)
{
	m_StartTime = 0;
	m_StopTime = 0;
	m_TimeOccured = 0;
}


CTimer::~CTimer(void)
{
}

void CTimer::Start()
{		
	m_StartTime = 0;
	m_StopTime = 0;
	m_TimeOccured = 0;

	QueryPerformanceCounter((LARGE_INTEGER *)&m_StartTime);

}

void CTimer::Stop()
{
	QueryPerformanceCounter((LARGE_INTEGER *)&m_StopTime);
	QueryPerformanceFrequency((LARGE_INTEGER *)&m_Frequency);
	m_TimeOccured = (m_StopTime - m_StartTime)*1.0 / m_Frequency;

	cout << "Tempo speso : " << m_TimeOccured << " sec"<<endl;
	cout << "Tempo speso : " << m_TimeOccured*1000 << " millisec"<<endl;
	cout << "Tempo speso : " << m_TimeOccured*1000000 << " microsec"<<endl;
}

void CTimer::GetElapsedTimeInMicros()
{
	QueryPerformanceCounter((LARGE_INTEGER *)&m_StopTime);
	QueryPerformanceFrequency((LARGE_INTEGER *)&m_Frequency);
	m_TimeOccured = (m_StopTime - m_StartTime)*1.0 / m_Frequency;
	cout << "Tempo speso : " << m_TimeOccured*1000000 << " microsec"<<endl;
}