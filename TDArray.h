#pragma once
#include <iostream>
#include "TDABase.h"

template <typename ElementType>
class TDArray final : public TDABase<ElementType>
{
public:
	TDArray()
		: TDABase<ElementType>()
	{}

	~TDArray() {}

	const ElementType& Get(const unsigned int Position) const
	{
		return this->GetArr()[Position];
	}

	const ElementType& Last() const
	{
		return this->GetArr()[this->GetSize() - 1];
	}

	void Bubble()
	{
		if (this->IsSorted() == true)
		{
			return;
		}

		unsigned int Size = this->GetSize();
		for (unsigned int i = 0; i < Size - 1; ++i)
		{
			for (unsigned int j = 0; j < (Size - 1) - i; ++j)
			{
				if (Get(j + 1) < Get(j))
				{
					Swap(&(GetMutable(j + 1)), &(GetMutable(j)));
				}
			}
		}

		this->SetSorted(true);
	}

private:
	ElementType& GetMutable(const unsigned int Position)
	{
		return this->GetArrMutable()[Position];
	}

	void Swap(ElementType* x, ElementType* y)
	{
		ElementType temp = *y;
		*y = *x;
		*x = temp;
	}
};

template <typename ElementType>
class TDArray<ElementType*> final : public TDABase<ElementType*>
{
public:
	TDArray()
		: TDABase<ElementType*>()
	{}

	~TDArray() {}

	const ElementType& Get(const unsigned int Position) const
	{
		return *this->GetArr()[Position];
	}

	const ElementType& Last() const
	{
		return *this->GetArr()[this->GetSize() - 1];
	}

	void Bubble()
	{
		if (this->IsSorted() == true)
		{
			return;
		}

		unsigned int Size = this->GetSize();
		for (unsigned int i = 0; i < Size - 1; ++i)
		{
			for (unsigned int j = 0; j < (Size - 1) - i; ++j)
			{
				if (Get(j + 1) < Get(j))
				{
					Swap(&(GetMutable(j + 1)), &(GetMutable(j)));
				}
			}
		}

		this->SetSorted(true);
	}

private:
	ElementType& GetMutable(const unsigned int Position)
	{
		return *this->GetArrMutable()[Position];
	}

	void Swap(ElementType* x, ElementType* y)
	{
		ElementType temp = *y;
		*y = *x;
		*x = temp;
	}
};

template<typename ElementType>
std::ostream& operator<<(std::ostream& Os, const TDArray<ElementType>& TDArray)
{
	unsigned int Size = TDArray.GetSize();

	Os << "capacity: " << TDArray.GetCapacity() << std::endl
		<< "size: " << Size << std::endl
		<< TDArray.IsSorted() << std::endl;

	Os << "++++++++++++" << std::endl;

	for (unsigned int Index = 0; Index < Size; ++Index)
	{
		Os << "[ " << Index << " ] => " << std::endl << "\t" << TDArray.Get(Index) << std::endl;
	}

	Os << "============" << std::endl << std::endl;
	return Os;
}