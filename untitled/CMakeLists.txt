cmake_minimum_required(VERSION 3.16)

project(untitled LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(untitled
  main.cpp
  unit.h unit.cpp
  classunit.h classunit.cpp
  methodunit.h methodunit.cpp
  printoperatorunit.h printoperatorunit.cpp
  cpp_classunit.h cpp_classunit.cpp
  cpp_printoperatorunit.h cpp_printoperatorunit.cpp
  cpp_methodunit.h cpp_methodunit.cpp
  java_classunit.h java_classunit.cpp
  java_printoperatorunit.h java_printoperatorunit.cpp
  java_methodunit.h java_methodunit.cpp
  csharp_classunit.h csharp_classunit.cpp
  csharp_printoperatorunit.h csharp_printoperatorunit.cpp
  csharp_methodunit.h csharp_methodunit.cpp
)
target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS untitled
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
