#pragma once

#include <iostream>
#include <utility>
#include <cstring>
#include <stdexcept>

template<typename T>
class Vector2D
{
public:
	Vector2D=default();

	Vector2D(const std::initializer_list<std::initializer_list<T>> &other);
	Vector2D(const size_t row, const size_t column);

	Vector2D(const Vector2D &other);
	Vector2D(Vector2D &&other);

	Vector2D& operator=(const Vector2D &other) noexcept;
	Vector2D& operator=(Vector2D &&other) noexcept;

	T* operator[](size_t row);
	const T* operator[](size_t row) const;

	~Vector2D();

private:
	int *m_data;
	size_t m_row;
	size_t m_column;
}

template<typename T>
Vector2D::Vector2D(std::initializer_list<std::initializer_list<T>> &other)
:	m_row(other.size()), m_column(other.begin().size())
{
	m_data = new T[m_row*m_column];

	for (size_t i=0; i<m_row; i++) {
		m_data[i] = new T[m_column];
		for (size_t ii=0; ii<m_column; ii++) {
			std::memcpy(m_data[i], other[i], sizeof(T)*m_row*m_column);
		}
	}
}

template<typename T>
Vector2D<T>::Vector2D(const Vector2D &other)
:	m_row(other.m_row), m_column(other.m_column)
{
	m_data = new T[m_row*m_column];
	m_data = other.m_data;
}

template<typename T>
Vector2D(const size_t row, const size_t column)
:	m_row(row), m_column(column), m_data(new T[m_row*m_column])
{}

template<typename T>
Vector2D<T>::Vector2D(Vector2D &&other)
:	m_row(other.m_row), m_column(other.m_column)
{
	m_data = new T[m_row*m_column];
	m_data = std::move(other.m_data);

	other.m_row = 0;
	other.m_column = 0;
	other.m_data = nullptr;
}

template<typename T>
Vector2D<T>::~Vector2D()
{
	delete[] m_data;
	m_row = 0;
	m_column = 0;
}

