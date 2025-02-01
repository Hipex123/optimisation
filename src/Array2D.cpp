#include <iostream>
#include <cstring>
#include <utility>
#include "Array2D.hpp"

template<typename T>
Array2D<T>::Array2D(const std::initializer_list<std::initializer_list<T>> &other)
{
	m_row = other.size();
	m_column = other.begin()->size();

	delete[] m_data;
	m_data = new T[m_row*m_column];

	for (int i=0; i<m_row; i++) {
		for (int ii=0; ii<m_column; ii++) {
			m_data[i*m_column+ii] = (*std::next(other.begin(), i))[ii];
		}
	}
}

template<typename T>
Array2D<T>::Array2D(const Array2D<T> &other)
{
	m_row = other.m_row;
	m_column = other.m_column;

	delete[] m_data;
	m_data = new T[m_row*m_column];

	std::memcpy(m_data, other.m_data, sizeof(T)*m_row*m_column);
}

template<typename T>
Array2D<T>::Array2D(Array2D<T> &&other)
: m_data(std::move(other.m_data))
{
	other.m_row = 0;
	other.m_column = 0;
	other.m_data = nullptr;
}

template<typename T>
Array2D<T> &Array2D<T>::operator=(const Array2D<T> &other) noexcept
{
	if (this == &other)
		return *this;

	m_row = other.m_row;
	m_column = other.m_column;

	delete[] m_data;
	m_data = new T[m_row*m_column];

	std::memcpy(m_data, other.m_data, sizeof(T)*m_row*m_column);

	return *this;
}

template<typename T>
Array2D<T> &Array2D<T>::operator=(Array2D<T> &&other) noexcept
{
	delete[] m_data;
	m_data = std::move(other.m_data);

	other.m_row = 0;
	other.m_column = 0;
	other.m_data = nullptr;

	return *this;
}
