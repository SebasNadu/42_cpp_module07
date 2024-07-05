/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:07:12 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/07/05 12:34:27 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"

#include <iostream>

template <typename T>

void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>

T min(T const &a, T const &b) {
  return ((a < b ? std::cout << CYAN : std::cout << PURPLE), (a < b ? a : b));
}

template <typename T>

T max(T const &a, T const &b) {
  return ((a > b ? std::cout << CYAN : std::cout << PURPLE), (a > b ? a : b));
}

template <typename T>

void printValues(T const &a, T const &b) {
  std::cout << CYAN "a = " << a << RESET ", " << PURPLE "b = " << b << RESET
            << std::endl;
}
