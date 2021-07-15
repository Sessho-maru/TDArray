#include "TDArray.h"
#include <string>

int main()
{
	TDArray<std::string*> StrArray;
	StrArray.Init(8);
	StrArray.Push(new std::string("Sakaki"));
	StrArray.Push(new std::string("Nyamo"));
	StrArray.Push(new std::string("Chiyo"));
	StrArray.Push(new std::string("Tomo"));
	StrArray.Push(new std::string("Yomi"));
	StrArray.Push(new std::string("Osaka"));
	std::cout << StrArray;

	StrArray.Shrink();
	std::cout << StrArray;

	StrArray.Sort();
	std::cout << StrArray;

	// std::cout << StrArray.Last() << std::endl;
	// std::cout << StrArray.GetPtr(3) << std::endl;

	// StrArray.Sort();
	// std::cout << StrArray;

	// StrArray.Shrink();
	// std::cout << StrArray;
}