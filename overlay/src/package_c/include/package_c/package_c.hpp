#ifndef PACKAGE_C__PACKAGE_C_HPP_
#define PACKAGE_C__PACKAGE_C_HPP_

#include <package_a/package_a.hpp>

void package_c_foo(int d);

/// Uses new package_a function
inline void package_c_foo_new(int d) {
  package_a_foo_new(d);
}

#endif  // PACKAGE_C__PACKAGE_C_HPP_
