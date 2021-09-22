#pragma once
#include <iostream>
#include "TDABase.h"

#define LAST_INDEX (this->mSize - 1)

template <typename ElementType>
class TDArray final : public TDABase<ElementType>
{
public:
	TDArray(const unsigned int Capacity)
		: TDABase<ElementType>(Capacity)
	{}

	~TDArray() {}

	ElementType& operator[](const unsigned int Position) const
	{
		return const_cast<ElementType&>(this->GetArr()[Position]);
	}

	const ElementType& Get(const unsigned int Position) const
	{
		return this->GetArr()[Position];
	}

	const ElementType& Last() const
	{
		return this->GetArr()[LAST_INDEX];
	}

	ElementType Pop()
	{
		ElementType Element = Last();
		this->mSize = this->mSize - 1;
		return Element;
	}

	void Bubble()
	{
		if (this->mSorted == true)
		{
			return;
		}

		for (unsigned int i = 0; i < LAST_INDEX; ++i)
		{
			for (unsigned int j = 0; j < (LAST_INDEX) - i; ++j)
			{
				if (Get(j + 1) < Get(j))
				{
					Swap(&(GetMutable(j + 1)), &(GetMutable(j)));
				}
			}
		}

		this->mSorted = true;
	}

private:
	ElementType& GetMutable(const unsigned int Position)
	{
		return this->GetArrMutable()[Position];
	}

	void Swap(ElementType* x, ElementType* y)
	{
		ElementType Temp = *y;
		*y = *x;
		*x = Temp;
	}
};

template <typename ElementType>
class TDArray<ElementType*> final : public TDABase<ElementType*>
{
public:
	TDArray(const unsigned int Capacity)
		: TDABase<ElementType*>(Capacity)
	{}

	~TDArray()
	{
		auto Arr = this->GetArr();
		for (unsigned int i = 0; i < this->mSize; ++i)
		{
			delete Arr[i];
		}
	}

	ElementType& operator[](const unsigned int Position) const
	{
		return *this->GetArr()[Position];
	}

	const ElementType& Get(const unsigned int Position) const
	{
		return *this->GetArr()[Position];
	}

	const ElementType& Last() const
	{
		return *this->GetArr()[LAST_INDEX];
	}

	ElementType Pop()
	{
		ElementType Element = Last();
		delete this->GetArr()[LAST_INDEX];
		this->mSize = this->mSize - 1;
		return Element;
	}

	void Bubble()
	{
		if (this->mSorted == true)
		{
			return;
		}

		for (unsigned int i = 0; i < LAST_INDEX; ++i)
		{
			for (unsigned int j = 0; j < (LAST_INDEX) - i; ++j)
			{
				if (Get(j + 1) < Get(j))
				{
					Swap(&(GetMutable(j + 1)), &(GetMutable(j)));
				}
			}
		}

		this->mSorted = true;
	}

private:
	ElementType& GetMutable(const unsigned int Position)
	{
		return *this->GetArrMutable()[Position];
	}

	void Swap(ElementType* x, ElementType* y)
	{
		ElementType Temp = *y;
		*y = *x;
		*x = Temp;
	}
};

template<typename ElementType>
std::ostream& operator<<(std::ostream& Os, const TDArray<ElementType>& TDArray)
{
	unsigned int Size = TDArray.GetSize();

	Os << "capacity: " << TDArray.GetCapacity() << std::endl
		<< "size: " << Size << std::endl
		<< "isSorted: " << std::boolalpha << TDArray.IsSorted() << std::endl;

	Os << "+++++++++++++++" << std::endl;

	for (unsigned int Index = 0; Index < Size; ++Index)
	{
		Os << "[ " << Index << " ] => " << std::endl << "\t" << TDArray.Get(Index) << std::endl;
	}

	Os << "===============" << std::endl << std::endl;
	return Os;
}