#pragma once
#include <cstring>

template <typename ElementType>
class TDABase
{
public:
	TDABase()
		: mCapacity(0)
		, mSize(0)
		, mArr(nullptr)
		, mSorted(false)
	{}

	virtual ~TDABase()
	{
		delete[] mArr;
	}

	void Init(const unsigned int Number)
	{
		mArr = new ElementType[Number];
		mCapacity = Number;
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

		const ElementType* temp = mArr;
		Move(temp, NewCapacity);
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
	ElementType* GetArrMutable()
	{
		return mArr;
	}

	void SetSorted(const bool NewSorted)
	{
		mSorted = NewSorted;
	}

private:
	void Move(const ElementType* temp, const unsigned int NewCapacity)
	{
		mArr = new ElementType[NewCapacity];
		for (unsigned int Index = 0; Index < mSize; ++Index)
		{
			*(mArr + Index) = *(temp + Index);
		}
		delete[] temp;
	}

	unsigned int mCapacity;
	unsigned int mSize;
	ElementType* mArr;
	bool mSorted;
};