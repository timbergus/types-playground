#include "logic.h"

std::any Evaluate::parse(std::string_view sample, std::any value)
{
  std::string key{sample.substr(0, 1)};

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
