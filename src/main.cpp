#include <iostream>
#include <string>
#include <any>

#include "logic.h"

std::any selectedStruct;

int main()
{
  std::string_view keyA{"A,DATA"};
  std::string_view keyB{"B,DATA"};

  selectedStruct = Evaluate::parse(keyA, 123);
  std::cout << std::any_cast<A>(selectedStruct).integerValue << std::endl;

  selectedStruct = Evaluate::parse(keyB, 456.789);
  std::cout << std::any_cast<B>(selectedStruct).doubleValue << std::endl;

  return EXIT_SUCCESS;
}
