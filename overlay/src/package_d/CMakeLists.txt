cmake_minimum_required(VERSION 3.8)
project(package_d)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(package_b REQUIRED)
find_package(package_c REQUIRED)

add_library(${PROJECT_NAME}
  src/package_d.cpp
)
ament_target_dependencies(${PROJECT_NAME}
  package_b
  # Targeting package_c causese underlay path to appear before overlay
  # The underlay contains an older version of package_a that package_b is not expecting
  package_c
  # Uncommenting this transient dependency fixes the include order
  # package_a
)

ament_package()
