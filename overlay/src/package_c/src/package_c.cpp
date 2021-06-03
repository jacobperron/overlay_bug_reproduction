#include <iostream>
#include "package_c/package_c.hpp"
#include "package_a/package_a.hpp"

void package_c_foo(int d) {
  std::cerr << "package_c_foo() -> " << std::to_string(d) << std::endl;
  package_a_foo_new(d);
}
