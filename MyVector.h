#pragma once
#include <iostream>
#include <cstring>
using namespace std;
template<typename T>
class MyVector
{
public:
	template<typename T2>
	friend ostream& operator<<(ostream& out, const MyVector<T2>& ve);
	MyVector(int length,T* element);
	MyVector(const MyVector<T> & ve);
	~MyVector();
	//MyVector<T>& operator=(T& element);
	T& operator[](int);
public:
	int m_length;
	T* m_element;
	int m_max;//ÈÝÆ÷×î´óÈÝÁ¿
};
template<typename T>
MyVector<T>::MyVector(int length, T* element):m_max(16)
{
	m_max = length + m_max;
	m_length = length;
	m_element = new T[m_max];
	for (int i = 0; i < m_length; i++)
	{
		m_element[i] = element[i];
	}

}
template<typename T>
MyVector<T>::MyVector(const MyVector<T>& ve)
{
	m_max = ve.m_max;
	m_length = ve.m_length;
	m_element = new T[m_max];
	for (int i = 0; i < m_length; i++)
	{
		m_element[i] = ve.m_element[i];
	}
}
template<typename T>
T& MyVector<T>::operator[](int index)
{
	m_length++;
	return m_element[index];
}
template<typename T>
MyVector<T>::~MyVector()
{
	delete[] m_element;
}
template<typename T2>
ostream& operator<<(ostream& out, const MyVector<T2>& ve) 
{
	for(int i = 0;i < ve.m_length;i++)
		out << ve.m_element[i]<<endl;
	
	return out;
}
