#pragma once
#include "TDArray.h"
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void TDA()
{
	{
		/*
		TDArray<int*> intArray(3);
		intArray.Push(new int(9));
		intArray.Push(new int(6));
		intArray.Push(new int(3));
		intArray.Push(new int(12));

		intArray.Bubble();

		std::cout << intArray;
		*/
	}
	
	{
		/*
		TDArray<std::string*> StrArray(8);
		StrArray.Push(new std::string("Sakaki"));
		StrArray.Push(new std::string("Nyamo"));
		StrArray.Push(new std::string("Chiyo"));
		StrArray.Push(new std::string("Tomo"));
		StrArray.Push(new std::string("Yomi"));
		StrArray.Push(new std::string("Kaori"));
		StrArray.Push(new std::string("Osaka9"));
		StrArray.Push(new std::string("Osaka8"));
		StrArray.Push(new std::string("Osaka7"));
		StrArray.Push(new std::string("Osaka6"));
		StrArray.Push(new std::string("Osaka5"));
		StrArray.Push(new std::string("Osaka4"));
		StrArray.Push(new std::string("Osaka3"));
		StrArray.Push(new std::string("Osaka2"));
		StrArray.Push(new std::string("Osaka1"));
		StrArray.Push(new std::string("Osaka0"));

		std::cout << StrArray.Last() << std::endl;
		std::cout << StrArray.Get(5) << std::endl;

		StrArray.Bubble();
		std::cout << StrArray.Get(5) << std::endl;

		std::cout << std::endl << std::endl << std::endl;
		StrArray.Shrink();
		std::cout << StrArray;
		*/
	}

	{
	
		TDArray<std::string*> StrArray(8);
		StrArray.Push(new std::string("Sakaki"));
		StrArray.Push(new std::string("Nyamo"));
		StrArray.Push(new std::string("Chiyo"));
		StrArray.Push(new std::string("Tomo"));
		StrArray.Push(new std::string("Yomi"));
		StrArray.Push(new std::string("Kaori"));
		StrArray.Push(new std::string("Osaka9"));
		StrArray.Push(new std::string("Osaka8"));
		StrArray.Push(new std::string("Osaka7"));
		StrArray.Push(new std::string("Osaka6"));
		StrArray.Push(new std::string("Osaka5"));
		StrArray.Push(new std::string("Osaka4"));
		StrArray.Push(new std::string("Osaka3"));
		StrArray.Push(new std::string("Osaka2"));
		StrArray.Push(new std::string("Osaka1"));
		StrArray.Push(new std::string("Osaka0"));
		StrArray.Push(new std::string("Kimura"));

		std::string a = StrArray.Pop();
		std::cout << a << std::endl;

		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();
		StrArray.Pop();

		StrArray.Push(new std::string("Kagura"));

		StrArray.Set(StrArray.GetSize() - 1, std::string("Osaka"));
		StrArray.Set(0, std::string(" "));

		StrArray.Shrink();
		std::cout << StrArray;
		
	}
}

int main()
{
	
	TDA();

	_CrtDumpMemoryLeaks();

	return 0;

}