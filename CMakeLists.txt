cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(OpenAL_Tinkering)

if (NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 11)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find OpenAL
find_package(OpenAL REQUIRED)

# find alut
find_package(PkgConfig)
pkg_check_modules(ALUT REQUIRED freealut)

include_directories(
  ${OPENAL_INCLUDE_DIR}
  ${ALUT_INCLUDE_DIRS}
)

# my example
add_executable(test_exe
  src/main.cc
)
target_link_libraries(test_exe
  ${OPENAL_LIBRARY}
  ${ALUT_LIBRARIES}
)

# alut demo (from the docs)
add_executable(alut_demo
  src/alut_demo.cc
)
target_link_libraries(alut_demo
  ${OPENAL_LIBRARY}
  ${ALUT_LIBRARIES}
)
