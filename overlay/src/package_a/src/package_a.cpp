#include <iostream>
#include "package_a/package_a.hpp"

void package_a_foo(int d) {
  std::cerr << "package_a_foo() -> " << std::to_string(d) << std::endl;
}

void package_a_foo_new(int d) {
  std::cerr << "package_a_foo_new() -> " << std::to_string(d) << std::endl;
}
