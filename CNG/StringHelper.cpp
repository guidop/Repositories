#include "StdAfx.h"
#include "StringHelper.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

StringHelper::StringHelper(void)
{
}


StringHelper::~StringHelper(void)
{
}


wstring StringHelper::ConvertByteArrayToString(const PUCHAR & byteArray, const int arrayLength)
{
    wstring ret = L"";
	if(byteArray)
	{
        wstring strDigest;
		
        for ( int i = 0; i < arrayLength; i++ )
        {

           wstringstream strHexByte;

		   int numberConverted = (int)byteArray[i];

			if(numberConverted < 16)
				strHexByte << "0" << std::hex << byteArray[i];
			else
				strHexByte << std::hex << byteArray[i];
			
            strDigest += strHexByte.str();
        }
    		
		return strDigest;
	}
	return ret;
}