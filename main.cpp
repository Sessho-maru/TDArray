#pragma once
#include "TDArray.h"
#include <string>

int main()
{
	/*
	TDArray<int> IntVArray;
	IntVArray.Init(8);
	IntVArray.Push(1);
	std::cout << IntVArray.Get(0);

	TDArray<int*> IntPArray;
	IntPArray.Init(8);
	IntPArray.Push(new int(1));
	std::cout << IntPArray.Get(0);

	TDArray<std::string> StrVArray;
	StrVArray.Init(8);
	StrVArray.Push(std::string("test"));
	std::cout << StrVArray.Get(0);

	TDArray<std::string*> StrPArray;
	StrPArray.Init(8);
	StrPArray.Push(new std::string("test"));
	std::cout << StrPArray.Get(0);
	*/

	{

		TDArray<std::string*> StrArray;
		StrArray.Init(8);
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
		std::cout << StrArray;

		StrArray.Push(new std::string("Osaka"));
		std::cout << StrArray;

		// StrArray.Bubble();
		std::cout << StrArray;

	}

	{
		/*
		TDArray<std::string> StackStrArray;
		StackStrArray.Init(8);
		StackStrArray.Push(std::string("Sakaki"));
		StackStrArray.Push(std::string("Nyamo"));
		StackStrArray.Push(std::string("Chiyo"));
		StackStrArray.Push(std::string("Tomo"));
		StackStrArray.Push(std::string("Yomi"));
		StackStrArray.Push(std::string("Osaka"));
		std::cout << StackStrArray;

		StackStrArray.Shrink();
		// StackStrArray.Bubble();

		std::cout << StackStrArray;
		*/
	}

	{
		/*
		TDArray<int*> intArray;
		intArray.Init(8);
		intArray.Push(new int(6));
		intArray.Push(new int(5));
		intArray.Push(new int(4));
		intArray.Push(new int(3));
		intArray.Push(new int(2));
		intArray.Push(new int(1));
		std::cout << intArray;

		intArray.Sort();
		std::cout << intArray;
		*/
	}

	{
		/*
		TDArray<int> StackintArray;
		StackintArray.Init(8);
		StackintArray.Push(6);
		StackintArray.Push(5);
		StackintArray.Push(4);
		StackintArray.Push(3);
		StackintArray.Push(2);
		StackintArray.Push(1);
		std::cout << StackintArray;

		StackintArray.Sort();
		std::cout << StackintArray;
		*/
	}
}