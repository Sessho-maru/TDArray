# Dynamic array implementation using templated C++
- Template specialization for pointer type 
- Support some utility functions

## Specifications
### TDBase \<typename T\>
&nbsp;&nbsp;&nbsp;&nbsp; - Parant class of TDArray </br>
&nbsp;&nbsp;&nbsp;&nbsp; - Manage memory (de)allocation </br>

##### Member variables
&nbsp;&nbsp;&nbsp;&nbsp; private: </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **unsigned int** `mCapacity` </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **T*** `mArr`</br>

&nbsp;&nbsp;&nbsp;&nbsp; protected: </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **unsigned int** `mSize` </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **bool** `mSorted` </br>


* &nbsp;&nbsp;TDABase &nbsp;( **const unsigned int** ) &nbsp; : protected
    -
    - Constructor
    - TDBase only can be initialized from TDArray
* &nbsp;&nbsp;~TDABase &nbsp;() &nbsp; : public
    -
    - Virtual destructor
    - Deallocates `mArr`
* *void* &nbsp;&nbsp;Push &nbsp;( **const T&** ) &nbsp; : public
    -
    - Push passed T& parameter into `mArr`
    - If this call causes exceeding `mCapacity`, then it calls ResizeTo() to make it double
* *const bool* &nbsp;&nbsp;ResizeTo &nbsp;( **const unsigned int** ) &nbsp; : public
    -
    - Reallocate memory with capacity specified as parameter
    - Copy all elements from existing memory area into reallocated one
* *const bool* &nbsp;&nbsp;Shrink &nbsp;() &nbsp; : public
    -
    - Reduce `mCapacity` into current `mSize`
* *T** &nbsp;&nbsp;GetArrMutable &nbsp;() &nbsp;const &nbsp; : protected
    -
    - Non-const version `mArr` getter
    
</br>

### TDArray <typename T*>
&nbsp;&nbsp;&nbsp;&nbsp; - Template specialization for pointer type </br>

* &nbsp;&nbsp;TDArray &nbsp;( **const unsigned int** ) &nbsp; : public
    -
    - Calls parent's constructor
* &nbsp;&nbsp;~TDArray &nbsp;() &nbsp; : public
    -   
    - Deallocates all of allocated memory spaces via each pointer type element in `mArr`
* &nbsp;&nbsp;const T& Get &nbsp;( **const unsigned int** ) &nbsp;const : public
    -   
    - Return the element from `mArr` whose index is specified as parameter
* &nbsp;&nbsp;const T& Last &nbsp;() &nbsp;const : public
    -   
    - Return the tail element from `mArr`
* &nbsp;&nbsp;T Pop &nbsp;() &nbsp; : public
    -   
    - Return the tail element from `mArr` and deallocates that portion
* &nbsp;&nbsp;void Bubble &nbsp;() &nbsp; : public
    -   
    - Executes bubble sort algorithm, then sets `mSorted` to true
* &nbsp;&nbsp;T& operator\[\] &nbsp;( **const unsigned int** ) &nbsp;const : public
    -
    - Operator[] overloading
    - Non-const conversion of Get()
</br>
    
### Others
* &nbsp;&nbsp;std::ostream& operator\<\< &nbsp;( **std::ostream&, const TDArary\<T\>&** )
    -   
    - Operator<< overloading
