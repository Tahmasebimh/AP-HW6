cmake_minimum_required(VERSION 3.15)
project(HW6)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW6 main.cpp cpp/basicGoods.cpp h/basicGoods.h cpp/food.cpp h/food.h cpp/appliance.cpp h/appliance.h cpp/material.cpp h/material.h cpp/productID.cpp h/productID.h cpp/product.cpp h/product.h)