/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:00:07 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/14 12:18:33 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T = int>
class Array {
public:
	Array(void) : _arr(NULL), _size(0) {}
	Array(unsigned int n) : _arr(new T[n]), _size(n) {}
	Array(Array const &other) : _arr(NULL), _size(0) {
		*this = other;
	}
	~Array(void) { delete[] _arr;}

	Array &operator=(Array const &other) {
		if (this != &other) {
			delete[] this->_arr;
			this->_size = other.size();
			this->_arr = new T[this->_size];
			for (size_t i = 0; i < this->_size; i++) {
				this->_arr[i] = other._arr[i];
			}
		}
		return *this;
	}
	T &operator[](size_t index) {
		if (index >= this->_size)
			throw (OutOfBoundsException());
		return (this->_arr[index]);
	}

	size_t size(void) const { return _size; }

	class OutOfBoundsException : public std::exception {
		virtual const char *what() const throw() {
			return "Out of bounds";
		}
	};

private:
	T 		*_arr;
	size_t _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		out << arr[i];
		if (i + 1 < arr.size())
			out << ", ";
	}
	return out;
}
