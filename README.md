# Dynamic array implementation using template C++
- Template specialization for pointer type 
- Support some utility functions

## Specifications
### TDBase \<typename T\>
&nbsp;&nbsp;&nbsp;&nbsp; - Parants class of TDArray </br>
&nbsp;&nbsp;&nbsp;&nbsp; - Manage memory (de)allocation </br>

##### Member variables
&nbsp;&nbsp;&nbsp;&nbsp; private: </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **unsigned int** `mCapacity` </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **T*** `mArr`</br>

&nbsp;&nbsp;&nbsp;&nbsp; protected: </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **unsigned int** `mSize` </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **bool** `mSorted` </br>

##### Getters
&nbsp;&nbsp;&nbsp;&nbsp; **const T*** &nbsp; GetArr()</br>
&nbsp;&nbsp;&nbsp;&nbsp; **const unsigned int** &nbsp; GetSize()</br>
&nbsp;&nbsp;&nbsp;&nbsp; **const unsigned int** &nbsp; GetCapacity()</br>
&nbsp;&nbsp;&nbsp;&nbsp; **const bool** &nbsp; isSorted()</br>

* [&nbsp;&nbsp;TDABase &nbsp;( **const unsigned int** ) &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDABase.h#L60-L65) : protected
    -
    - Constructor
    - TDBase only can be initialized from TDArray
* [&nbsp;&nbsp;~TDABase &nbsp;() &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDABase.h#L8-L11) : public
    -
    - Virtual destructor
    - Deallocates `mArr`
* [*void* &nbsp;&nbsp;Push &nbsp;( **const T&** ) &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDABase.h#L13-L22) : public
    -
    - Push passed T& parameter into `mArr`
    - If this call causes exceeding `mCapacity`, then it invokes ResizeTo() to make current allocation size double
* [*const bool* &nbsp;&nbsp;ResizeTo &nbsp;( **const unsigned int** ) &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDABase.h#L32-L43) : public
    -
    - Reallocate memory with capacity specified as parameter
    - Move all elements on the existing memory area into the area newly allocataed
* [*const bool* &nbsp;&nbsp;Shrink &nbsp;() &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDABase.h#L45-L52) : public
    -
    - Reduce `mCapacity` into current `mSize`
    - Any memory deallocation doesn't take place and the area get shrinked be overwritten when the new parameter is pushed
* [*T** &nbsp;&nbsp;GetArrMutable &nbsp;() &nbsp;const &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDABase.h#L67) : protected
    -
    - Non-const version `mArr` getter
    
</br>

### TDArray <typename T*>
&nbsp;&nbsp;&nbsp;&nbsp; - Template specialization for pointer type </br>

* [&nbsp;&nbsp;TDArray &nbsp;( **const unsigned int** ) &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L78-L80) : public
    -
    - Initialize a TDBase object
* [&nbsp;&nbsp;~TDArray &nbsp;() &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L82-L89) : public
    -   
    - Deallocates all of allocated memory spaces via each pointer type element in `mArr`
* [&nbsp;&nbsp;const T& Get &nbsp;( **const unsigned int** ) &nbsp;const](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L96-L99) : public
    -   
    - Return the element from `mArr` whose index is specified as parameter
* [&nbsp;&nbsp;const T& Last &nbsp;() &nbsp;const](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L101-L104) : public
    -   
    - Return the tail element from `mArr`
* [&nbsp;&nbsp;T Pop &nbsp;() &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L106-L112) : public
    -   
    - Return the tail element from `mArr` and deallocates that portion
* [&nbsp;&nbsp;void Bubble &nbsp;() &nbsp;](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L114-L133) : public
    -   
    - Executes bubble sort algorithm, then sets `mSorted` to true
* [&nbsp;&nbsp;T& operator\[\] &nbsp;( **const unsigned int** ) &nbsp;const](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L91-L94) : public
    -
    - Operator[] overloading
    - Non-const conversion of Get()
</br>
    
### Others
* [&nbsp;&nbsp;std::ostream& operator\<\< &nbsp;( **std::ostream&, const TDArary\<T\>&** )](https://github.com/Sessho-maru/TDArray/blob/master/TDArray.h#L149-L167)
    -   
    - Operator<< overloading
