#include "stdafx.h"
#include "KeyStorageManager.h"

using namespace std;

CKeyStorageManager::CKeyStorageManager(void)
{
}


CKeyStorageManager::~CKeyStorageManager(void)
{
}

void CKeyStorageManager::EnumStorageProvider(vector<wstring> & listOfProvider)
{
	SECURITY_STATUS ret;
	DWORD pdwProviderCount;
	NCryptProviderName *ppProviderList;
	DWORD dwFlags = 0;
	
	ret = NCryptEnumStorageProviders(&pdwProviderCount, &ppProviderList, dwFlags);
	
	if(ret != TRUE)
	{
		for (DWORD i=0; i<pdwProviderCount; i++)
		{
			listOfProvider.push_back((ppProviderList[i]).pszName);
		}
	}
	
	NCryptFreeBuffer(ppProviderList);		
}

NCRYPT_PROV_HANDLE CKeyStorageManager::OpenStorageProvider(wstring providerName)
{
	SECURITY_STATUS ret;
	DWORD dwFlags = 0;
	NCRYPT_PROV_HANDLE hProvider;
	ret = NCryptOpenStorageProvider(&hProvider, providerName.c_str(), dwFlags);
	return hProvider;
}

void CKeyStorageManager::CreatePersistedKey(NCRYPT_PROV_HANDLE hProvider, NCRYPT_KEY_HANDLE *phKey, const wstring & pszAlgId, const wstring & pszKeyName, DWORD dwLegacyKeySpec, DWORD dwFlags)
{
	SECURITY_STATUS ret;
	ret = NCryptCreatePersistedKey(hProvider, phKey, pszAlgId.c_str(), pszKeyName.c_str(), dwLegacyKeySpec, dwFlags);
	if(ret != FALSE)
	{
		char  msgbuf[200];
		sprintf_s(msgbuf, "CKeyStorageManager::CreatePersistedKey failed. Error: %ld\n", GetLastError());
		OutputDebugStringA(msgbuf);
	}
}

void CKeyStorageManager::FinalizePersistedKey(NCRYPT_KEY_HANDLE hKey)
{
	SECURITY_STATUS ret;
	ret = NCryptFinalizeKey(hKey, 0);
	if(ret != FALSE)
	{
		char  msgbuf[200];
		sprintf_s(msgbuf, "CKeyStorageManager::CreatePersistedKey failed. Error: %ld\n", GetLastError());
		OutputDebugStringA(msgbuf);
	}
}


void CKeyStorageManager::OpenExistingPersistedKey(NCRYPT_PROV_HANDLE hProvider, NCRYPT_KEY_HANDLE *phKey, const wstring & pszAlgId, const wstring & pszKeyName, DWORD dwLegacyKeySpec, DWORD dwFlags)
{		
	SECURITY_STATUS ret;
	ret =  NCryptOpenKey(hProvider, phKey, pszKeyName.c_str(), dwLegacyKeySpec, dwFlags);
	if(ret != FALSE)
	{
		char  msgbuf[200];
		sprintf_s(msgbuf, "CKeyStorageManager::OpenExistingPersistedKey failed. Error: %ld\n", GetLastError());
		OutputDebugStringA(msgbuf);
	}
}


void CKeyStorageManager::DeleteExistingPersistedKey(NCRYPT_KEY_HANDLE hKey, DWORD dwFlags)
{		
	SECURITY_STATUS ret;
	ret =  NCryptDeleteKey(hKey, dwFlags);
	if(ret != FALSE)
	{
		char  msgbuf[200];
		sprintf_s(msgbuf, "CKeyStorageManager::DeleteExistingPersistedKey failed. Error: %ld\n", GetLastError());
		OutputDebugStringA(msgbuf);
	}
}