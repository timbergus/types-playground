#pragma once

#include <string>
#include <any>

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
  static std::any parse(std::string_view, std::any);
};
