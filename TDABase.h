#pragma once
#include <cstring>

template <typename ElementType>
class TDABase
{
public:
	virtual ~TDABase()
	{
		delete[] mArr;
	}

	void Push(const ElementType& Element)
	{
		if (mSize == mCapacity)
		{
			ResizeTo(mCapacity * 2);
		}

		mArr[mSize] = Element;
		mSize = mSize + 1;
	}

	void Push(const ElementType& Element, const unsigned int Number)
	{
		for (unsigned int Index = 0; Index < Number; ++Index)
		{
			Push(Element);
		}
	}

	const bool ResizeTo(const unsigned int NewCapacity)
	{
		if (NewCapacity < mSize || NewCapacity == mCapacity)
		{
			return false;
		}

		const ElementType* Temp = mArr;
		Move(Temp, NewCapacity);
		mCapacity = NewCapacity;
		return true;
	}

	const bool Shrink()
	{
		if (mSize != mCapacity)
		{
			return ResizeTo(mSize);
		}
		return false;
	}

	const ElementType* GetArr() const { return mArr; }
	const unsigned int GetSize() const { return mSize; }
	const unsigned int GetCapacity() const { return mCapacity; }
	const bool IsSorted() const { return mSorted; }

protected:
	TDABase(const unsigned int Capacity)
		: mSize(0)
		, mSorted(false)
	{
		Init(Capacity);
	}

	ElementType* GetArrMutable() const { return mArr; }

	unsigned int mSize;
	bool mSorted;

private:
	void Init(const unsigned int Capacity)
	{
		mArr = new ElementType[Capacity];
		mCapacity = Capacity;
	}

	void Move(const ElementType* Temp, const unsigned int NewCapacity)
	{
		mArr = new ElementType[NewCapacity];
		for (unsigned int Index = 0; Index < mSize; ++Index)
		{
			*(mArr + Index) = *(Temp + Index);
		}
		delete[] Temp;
	}

	unsigned int mCapacity;
	ElementType* mArr;
};