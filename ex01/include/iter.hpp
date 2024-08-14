/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:00:07 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/14 12:33:29 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T, typename TFunction>
void iter(T *array, size_t len, TFunction fn) {
  for (size_t i = 0; i < len; i++)
    fn(array[i]);
}

template <typename T> void printArray(T const *array, size_t len) {
  if (len) {
    std::cout << array[0];
    for (size_t i = 1; i < len; i++)
      std::cout << ", " << array[i];
    std::cout << '.';
  }
  std::cout << std::endl;
}

template <typename T> void multiplyByTwo(T &n) { n *= 2; }

template <typename T> void addOne(T &n) { n += 1; }

template <> void addOne(std::string &str) { str += "1"; }
