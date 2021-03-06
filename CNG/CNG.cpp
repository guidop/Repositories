// CNG.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <windows.h>
#include <bcrypt.h>
#include "CNG.h"
#include <iostream>

#ifndef NT_SUCCESS
#   define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)
#endif



using namespace std;

CNG::CNG(void)
{
}

CNG::~CNG(void)
{
}

int CNG::EchhoNumber(int number)
{
	return number;
}

int CNG::CheckIfFipsIsEnabled()
{
	BOOLEAN fipsIsEnabled=50;
	NTSTATUS result;
	result = BCryptGetFipsAlgorithmMode(&fipsIsEnabled);
	if(result < 0)
	{
		printf("Errore in chiamata a BCryptGetFipsAlgorithmMode\n");
	}
	printf("Fips Algorithm enabled HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Lsa\\FipsAlgorithmPolicy: %d",fipsIsEnabled);
	return (int)fipsIsEnabled;
}