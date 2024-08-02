/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:29:53 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/07/11 21:46:55 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "whatever.hpp"

#include <iostream>

static void testMandatory(void) {
  int a = 2;
  int b = 3;

  ::swap(a, b);
  ::printValues(a, b);
  std::cout << "min(a, b) = " << ::min(a, b) << RESET << std::endl;
  std::cout << "max(a, b) = " << ::max(a, b) << RESET << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);
  ::printValues(c, d);
  std::cout << "min(c, d) = " << ::min(c, d) << RESET << std::endl;
  std::cout << "max(c, d) = " << ::max(c, d) << RESET << std::endl;
}

void testChar(char a, char b) {
  ::printValues<char>(a, b);
  ::swap<char>(a, b);
  std::cout << "Values swapped: \n";
  ::printValues<char>(a, b);
  std::cout << "min(a, b) = " << ::min<char>(a, b) << RESET "\n";
  std::cout << "max(a, b) = " << ::max<char>(a, b) << RESET << std::endl;
}

void testInt(int a, int b) {
  ::printValues<int>(a, b);
  ::swap<int>(a, b);
  std::cout << "Values swapped: \n";
  ::printValues<int>(a, b);
  std::cout << "min(a, b) = " << ::min<int>(a, b) << RESET "\n";
  std::cout << "max(a, b) = " << ::max<int>(a, b) << RESET << std::endl;
}

void testDouble(double a, double b) {
  ::printValues<double>(a, b);
  ::swap<double>(a, b);
  std::cout << "Values swapped: \n";
  ::printValues<double>(a, b);
  std::cout << "min(a, b) = " << ::min<double>(a, b) << RESET "\n";
  std::cout << "max(a, b) = " << ::max<double>(a, b) << RESET << std::endl;
}

void testString(std::string a, std::string b) {
  ::printValues<std::string>(a, b);
  ::swap<std::string>(a, b);
  std::cout << "Values swapped: ";
  ::printValues<std::string>(a, b);
  std::cout << "min(a, b) = " << ::min<std::string>(a, b) << RESET "\n";
  std::cout << "max(a, b) = " << ::max<std::string>(a, b) << std::endl;
}

int main(void) {
  std::cout << YELLOW "\n------- Test Mandatory -------\n" RESET;
  testMandatory();
  std::cout << YELLOW "\n------- Test with char -------\n" RESET;
  std::cout << '\n';
  testChar('A', 'b');
  std::cout << '\n';
  testChar('z', '<');
  std::cout << '\n';
  testChar(42, 42);
  std::cout << YELLOW "\n------- Test with Int -------\n" RESET;
  std::cout << '\n';
  testInt(45, 80);
  std::cout << '\n';
  testInt(42, 42);
  std::cout << '\n';
  testInt(-100, 0);
  std::cout << '\n';
  testInt(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max());
  std::cout << YELLOW "\n------- Test with double -------\n" RESET;
  std::cout << '\n';
  testDouble(45.5, 80.8);
  std::cout << '\n';
  testDouble(0.042, 0.042);
  std::cout << '\n';
  testDouble(-0.0001, 0.0);
  std::cout << '\n';
  testDouble(std::numeric_limits<double>::lowest(),
             std::numeric_limits<double>::max());
  std::cout << YELLOW "\n------- Test with string -------\n" RESET;
  std::cout << '\n';
  testString("Hello", "World");
  std::cout << '\n';
  testString("42", "42");
  std::cout << '\n';
  testString("abcdef", "abcdeF");
  std::cout << '\n';
  testString("Hello", "\0Hello");
  return (0);
}
