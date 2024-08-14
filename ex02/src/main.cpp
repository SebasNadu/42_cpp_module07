/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:01:40 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/08/14 12:18:27 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.hpp>
#include <iostream>
#include <Array.hpp>

int main(void) {
	try {
		std::cout << YELLOW "\n--------Testing size 10 init -------\n" RESET;
		Array<int> arr1 = Array<int>(10);
		Array<int> arr2(10);
		arr1 = arr2;
		std::cout << "arr1 size: " GREEN << arr1.size() << RESET << std::endl;
		std::cout << "arr2 size: " GREEN << arr2.size() << RESET << std::endl;
		std::cout << "arr1: " GREEN << arr1 << RESET << std::endl;
		std::cout << "arr2: " GREEN << arr2 << RESET << std::endl;

		std::cout << YELLOW "\n--------Testing asign values -------\n" RESET;
		for (size_t i = 0; i < arr1.size(); i++) {
			try {
				arr1[i] = i + 1;
			} catch (std::exception const &e) {
				std::cerr << RED "Error: " << e.what() << RESET << std::endl;
			}
		}
		std::cout << "arr1: " GREEN << arr1 << RESET << std::endl;
		std::cout << "arr2: " GREEN << arr2 << RESET << std::endl;

		std::cout << YELLOW "\n--------Testing copy constructor -------\n" RESET;
		arr2 = arr1;
		std::cout << "arr1: " GREEN << arr1 << RESET << std::endl;
		std::cout << "arr2: " GREEN << arr2 << RESET << std::endl;

		std::cout << YELLOW "\n--------Testing change specific index and deep copy -------\n" RESET;
		arr1[0] = 42;
		arr2[arr2.size() - 1] = 42;
		std::cout << "arr1: " GREEN << arr1 << RESET << std::endl;
		std::cout << "arr2: " GREEN << arr2 << RESET << std::endl;

		std::cout << YELLOW "\n--------Testing copy to a small array -------\n" RESET;
		Array<int> arr3(5);
		std::cout << "arr1: " GREEN << arr1 << RESET << std::endl;
		std::cout << "arr3: " GREEN << arr3 << RESET << std::endl;
		arr3 = arr1;
		std::cout << "arr1: " GREEN << arr1 << RESET << std::endl;
		std::cout << "arr3: " GREEN << arr3 << RESET << std::endl;

		std::cout << YELLOW "\n--------Testing default constructor -------\n" RESET;
		arr3 = Array<int>();
		std::cout << "arr1: " GREEN << arr1 << RESET << std::endl;
		std::cout << "arr2: " GREEN << arr2 << RESET << std::endl;
		std::cout << "arr3: " GREEN << arr3 << RESET << std::endl;

		std::cout << YELLOW "\n--------Testing out of bounds index[0] -------\n" RESET;
		try {
			std::cout << "arr1: " GREEN << arr1[0] << RESET << std::endl;
			std::cout << "arr2: " GREEN << arr2[0] << RESET << std::endl;
			std::cout << "arr3: " GREEN << arr3[0] << RESET << std::endl;
		} catch (std::exception const &e) {
			std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW "\n--------Testing char Array -------\n" RESET;
		Array<char> charArr(26);
		for (size_t i = 0; i < charArr.size(); i++) {
			charArr[i] = i + 'a';
		}
		std::cout << "charArr: " GREEN << charArr << RESET << std::endl;
		std::cout << YELLOW "\n--------Testing use indexes -------\n" RESET;
		std::cout << "charArr: " GREEN << charArr[7] << charArr[4] << charArr[11] << charArr[11] << charArr[14] << " 42!" << RESET << std::endl;
	} catch (...) {
		std::cerr << RED "Error: unknown error" RESET << std::endl;
		return 1;
	}
  return 0;
}
