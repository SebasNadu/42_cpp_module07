/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:01:40 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/14 12:33:56 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "iter.hpp"
#include <iostream>
#include <string>

static inline void upperChar(char &c) { c = std::toupper(c); }

static void upperString(std::string &str) {
  for (std::string::iterator it = str.begin(); it != str.end(); it++)
    *it = std::toupper(*it);
}

int main(void) {
  std::cout << YELLOW "\n--------Testing with int array-------\n" RESET;
  int intArr[] = {1, 2, 3, 4, 5};
  size_t len = 5;

  std::cout << "Original array: " GREEN;
  ::printArray<int>(intArr, len);
  ::iter<int>(intArr, len, ::addOne<int>);
  std::cout << RESET "Array after iter with addOne: " GREEN;
  ::printArray<int>(intArr, len);
  ::iter<int>(intArr, len, ::multiplyByTwo<int>);
  std::cout << RESET "Array after iter with multiplyByTwo: " GREEN;
  ::printArray<int>(intArr, len);

  std::cout << YELLOW "\n--------Testing with double array-------\n" RESET;
  double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << "Original array: " GREEN;
  ::printArray<double>(doubleArr, len);
  ::iter<double>(doubleArr, len, ::addOne<double>);
  std::cout << RESET "Array after iter with addOne: " GREEN;
  ::printArray<double>(doubleArr, len);
  ::iter<double>(doubleArr, len, ::multiplyByTwo<double>);
  std::cout << RESET "Array after iter with multiplyByTwo: " GREEN;
  ::printArray<double>(doubleArr, len);

  std::cout << YELLOW "\n--------Testing with char array-------\n" RESET;
  char charArr[] = {'a', 'b', 'c', 'd', 'e'};
  std::cout << "Original array: " GREEN;
  ::printArray<char>(charArr, len);
  ::iter<char>(charArr, len, ::addOne<char>);
  std::cout << RESET "Array after iter with addOne: " GREEN;
  ::printArray<char>(charArr, len);
  ::iter<char>(charArr, len, upperChar);
  std::cout << RESET "Array after iter with upperChar: " GREEN;
  ::printArray<char>(charArr, len);

  std::cout << YELLOW "\n--------Testing with string array-------\n" RESET;
  std::string strArr[] = {"hello", "world", "this", "is", "42"};
  std::cout << "Original array: " GREEN;
  ::printArray<std::string>(strArr, len);
  ::iter<std::string>(strArr, len, ::addOne<std::string>);
  std::cout << RESET "Array after iter with addOne: " GREEN;
  ::printArray<std::string>(strArr, len);
  ::iter<std::string>(strArr, len, upperString);
  std::cout << RESET "Array after iter with upperString: " GREEN;
  ::printArray<std::string>(strArr, len);
  return 0;
}
