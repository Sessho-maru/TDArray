#pragma once
#include <cstring>
#include <iostream>
#include <type_traits>

template <typename ElementType>
class TDArray
{
public:
	TDArray()
		: mCapacity(0)
		, mSize(0)
		, mSorted(false)
		, mPtr(nullptr)
	{}

	~TDArray()
	{
		delete[] mPtr;
	}

	void Init(const unsigned int Number)
	{
		mPtr = new ElementType[Number];
		mCapacity = Number;
	}

	void Push(const ElementType& Element)
	{
		if (mSize == mCapacity)
		{
			ResizeTo(mCapacity * 2);
		}

		*(mPtr + mSize) = Element;
		mSize = mSize + 1;
	}

	void Push(const ElementType& Element, unsigned int Number)
	{
		for (unsigned int Index = 0; Index < Number; ++Index)
		{
			Push(Element);
		}
	}

	const bool ResizeTo(unsigned int NewCapacity)
	{
		if (NewCapacity < mSize || NewCapacity == mCapacity)
		{
			return false;
		}

		const ElementType* temp = mPtr;
		Move(temp, NewCapacity);
		mCapacity = NewCapacity;
		return true;
	}

	void Shrink()
	{
		if (mSize != mCapacity)
		{
			ResizeTo(mSize);
		}
	}

	void Sort()
	{
		if (mSorted == true)
		{
			return;
		}

		for (unsigned int i = 0; i < mSize - 1; ++i)
		{
			for (unsigned int j = 0; j < mSize - 1 - i; ++j)
			{
				if (mPtr[j + 1] < mPtr[j])
				{
					Swap(&mPtr[j + 1], &mPtr[j]);
				}
			}
		}

		mSorted = true;
	}

	const bool operator==(const TDArray& Other) const
	{
		return true;
	}

	const ElementType& Get(unsigned int Position) const { return *(mPtr + Position); }
	const ElementType& Last() const { return *Top(); }
	const unsigned int GetSize() const { return mSize; }
	const unsigned int GetCapacity() const { return mCapacity; }
	const bool IsSorted() const { return mSorted; }

private:
	void Move(const ElementType* temp, unsigned int NewCapacity)
	{
		mPtr = new ElementType[NewCapacity];
		for (unsigned int Index = 0; Index < mSize; ++Index)
		{
			*(mPtr+ Index) = *(temp + Index);
		}
		delete[] temp;
	}

	const ElementType* Top() const
	{
		return mPtr + mSize;
	}

	void Swap(ElementType* x, ElementType* y)
	{
		const ElementType temp = *y;
		*y = *x;
		*x = temp;
	}

	unsigned int mCapacity;
	unsigned int mSize;
	bool mSorted;
	ElementType* mPtr;
};

template<typename ElementType>
void operator<<(std::ostream& Os, const TDArray<ElementType>& TDArray)
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

	Os << "============" << std::endl << std::endl << std::endl;
}