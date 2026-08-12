cmake_minimum_required(VERSION 3.20)
project(HOA5_1)

set(CMAKE_CXX_STANDARD 20)

# 1. ILOA: No header files
add_executable(HOA5_1_ILOA ILOA.cpp)

# 2. ILOB: Linked with Linked List Queue (queuell.h)
add_executable(HOA5_1_ILOB ILOB.cpp queuell.h)

# 3. ILOB2: Linked with Array Queue (queueArr.h)
add_executable(HOA5_1_ILOB2 ILOB.2.cpp queueArr.h)

# 4. ILOC: Shared Printer Simulation (Job.h, Printer.h, ILOC.cpp)
add_executable(HOA5_1_ILOC ILOC.cpp Job.h Printer.h)