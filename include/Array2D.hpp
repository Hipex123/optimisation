#pragma once

#include <initializer_list>

template<typename T>
class Array2D{
public:
	Array2D()=default;

	Array2D(const std::initializer_list<std::initializer_list<T>> &others);
	Array2D(const size_t row, const size_t column); // TODO

	Array2D(const Array2D<T> &other);
	Array2D(Array2D<T> &&other);

	Array2D<T> &operator=(const Array2D<T> &other) noexcept;
	Array2D<T> &operator=(Array2D<T> &&other) noexcept;

	T *operator[](size_t row); // TODO
	const T *operator[](size_t row); // TODO

	~Array2D(); // TODO


private:
	T *m_data;
	size_t row;
	size_t column;
};
