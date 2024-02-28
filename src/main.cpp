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
  static void parse(std::string, std::any);
};

void Evaluate::parse(std::string key, std::any value)
{
  if (key == "A")
  {
    A a;
    a.integerValue = std::any_cast<int>(value);
    selectedStruct = a;
  }
  else if (key == "B")
  {
    B b;
    b.doubleValue = std::any_cast<double>(value);
    selectedStruct = b;
  }
  else
  {
    throw std::runtime_error("Value type not supported");
  }
}

int main()
{
  Evaluate::parse("A", 123);
  std::cout << std::any_cast<A>(selectedStruct).integerValue << std::endl;

  Evaluate::parse("B", 456.789);
  std::cout << std::any_cast<B>(selectedStruct).doubleValue << std::endl;

  return EXIT_SUCCESS;
}
