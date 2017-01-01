#include<iostream>
#include<string>
#include<assert.h>
 
using namespace std;
 
template<class DataType >
 
class SeqList
{

public:
    SeqList();
    SeqList(const DataType& data);
    ~SeqList();
    void PushFront(const DataType& data);
    void PushBack(const DataType& data);
	void PopFront();
    void PopBack();
    void Display();
private:
    DataType* _data;
    size_t _capacity;
    size_t _size;
    void ChickCapacity();
};
 
template<class DataType>
 
SeqList<DataType>::SeqList()
:_data(NULL)
, _size(0)
, _capacity(0)
{}
 
template<class DataType>
 
SeqList<DataType>::SeqList(const DataType& data)
:_data(NULL)
, _size(0)
, _capacity(0)
{
    PushBack(data);
}
template<class DataType>
void SeqList< DataType>::ChickCapacity()
{
    if (_capacity == 0)
    {
        _capacity = 1;
        _data = new DataType[_capacity];
    }
    if (_size == _capacity)
    {
         
        _capacity *= 2;
        DataType* tmp = new DataType[_capacity];
        size_t i = 0;
        while (i < _size)
        {
            tmp[index] = _data[index];
            ++i;
        }
        delete[] _data;
        _data = tmp;
    }
}
 

 
template<class DataType>
 
SeqList<DataType>::~SeqList()
{
    delete[] _data;
}
 
template<class DataType>
 
void SeqList<DataType>::PushBack(const DataType& data)
{
    ChickCapacity();
    _data[_size++] = data;
}
 
template<class DataType>
 
void SeqList<DataType>::PopBack()
{
    if (_size > 0)
        --_size;
    if (_size == 0 && _data != NULL)
    {
        delete[] _data;
        _data = NULL;
    }
}

template<class DataType>
void SeqList<DataType>::PushFront(const DataType &data)
{
    for(int i=_size ; i>0 ; --i)
    {
        _data[i] = _data[i-1];
    }
    _data[0] = data;
    _size++;
}

template<class DataType>
void SeqList<DataType>::PopFront()
{
    for (i = 0; i < _size-1; i++)  
    {  
      _data[i] =_data[i + 1];  
    }  
    _size--;  
}
 
template<class DataType> 
void SeqList<DataType>::operator=(const SeqList& tmp)
{
    if (&tmp == this)
        return;
    _size = tmp._size;
    _capacity = tmp._capacity;
    delete[] _data;
    _data = new DataType[_capacity];
    size_t index = 0;
    while (index < _size)
    {
        _data[index] =tmp._data[index] ;
        ++index;
    }
}
 
template<class DataType>
 
void SeqList<DataType>::Display()
{
    size_t index = 0;
    while (index < _size)
    {
        cout << _data[index] << "-" << endl;
        ++index;
    }
}

void test()
{
	SeqList<int> s1;
    s1.PushBack(1);
    s1.PushBack(2);
    s1.PushBack(3);
    s1.PushBack(4);
    s1.Display();
    s1.PopBack();
    s1.PopBack();
    s1.PopBack();
    s1.PopBack();
    s1.PopBack();
    s1.Display();
}

int main()
{
	test();
	return 0;
}