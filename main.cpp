#pragma once
#include "TDArray.h"
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void TDA()
{
	{
		TDArray<int> intArray(3);
		intArray.Push(9);
		intArray.Push(6);
		intArray.Push(3);
		intArray.Push(12);

		intArray.Shrink();
		intArray[6] = 3;

		std::cout << intArray;
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

		std::cout << StrArray.Last() << std::endl;
		std::cout << StrArray.Get(5) << std::endl;

		StrArray.Bubble();
		std::cout << StrArray.Get(5) << std::endl;

		std::cout << std::endl << std::endl << std::endl;
		StrArray.Shrink();
		std::cout << StrArray;
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
		StrArray.Last();

		StrArray[0] = "Test";

		StrArray.Push(new std::string("Kagura"));

		StrArray.Shrink();
		std::cout << StrArray;

		StrArray.Bubble();
		std::cout << StrArray;
	}
}

int main()
{
	
	TDA();

	_CrtDumpMemoryLeaks();

	return 0;

}