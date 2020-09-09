#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Array
{
private:
	T* m_address;//存数据的地址
	int m_capacity;//容量
	int m_size;//当前元素个数
public:
	Array(int capacity);
	~Array();
	Array(const Array& arr);
	Array& operator=(const Array & arr);
	void PushBack(const T& val);
	void Popback();
	T& operator[](int index);
	int GetCapacity();
	int GetSize();
};
template <typename T>
Array<T>::Array(int capacity)
{
	this->m_capacity = capacity;
	this->m_size = 0;
	this->m_address = new T[m_capacity];
}
template <typename T>
Array<T>::~Array()
{
	if (this->m_address != NULL)
	{
		delete[] m_address;
		this->m_address = 0;
		m_size = 0;
		m_capacity = 0;
	}
}
template <typename T>
Array<T>::Array(const Array& arr)
{
	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->m_address = new T[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		this->m_address[i] = arr.m_address[i];
	}
}
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arr)
{
	if (this->m_address != NULL)
	{
		delete[] m_address;
		this->m_address = NULL;
		this->m_size = 0;
		this->m_capacity = 0;
	}
	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->m_address = new T[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		this->m_address[i] = arr.m_address[i];
	}
	return *this;
}
template <typename T>
void Array<T>::PushBack(const T& val)
{
	if (this->m_capacity == this->m_size)
	{
		return;
	}
	m_address[m_size] = val;
	m_size++;
}
template <typename T>
void Array<T>::Popback()
{
	if (this->m_size == 0)
	{
		return;
	}
	m_size--;
}
template <typename T>
T& Array<T>::operator[](int index)
{
	return this->m_address[index];
}
template <typename T>
int Array<T>::GetCapacity()
{
	return this->m_capacity;
}
template <typename T>
int Array<T>::GetSize()
{
	return m_size;
}