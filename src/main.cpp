#include <iostream>
#include <string>
#include <any>

std::any selectedStruct;

struct A
{
  int integerValue;
};

struct B
{
  double doubleValue;
};

class Evaluate
{
public:
  static std::any parse(std::string, std::any);
};

std::any Evaluate::parse(std::string key, std::any value)
{
  if (key == "A")
  {
    A a;
    a.integerValue = std::any_cast<int>(value);
    return a;
  }
  else if (key == "B")
  {
    B b;
    b.doubleValue = std::any_cast<double>(value);
    return b;
  }
  else
  {
    throw std::runtime_error("Value type not supported");
  }
}

int main()
{
  selectedStruct = Evaluate::parse("A", 123);
  std::cout << std::any_cast<A>(selectedStruct).integerValue << std::endl;

  selectedStruct = Evaluate::parse("B", 456.789);
  std::cout << std::any_cast<B>(selectedStruct).doubleValue << std::endl;

  return EXIT_SUCCESS;
}
