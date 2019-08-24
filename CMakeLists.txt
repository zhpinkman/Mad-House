cmake_minimum_required(VERSION 3.14)
project(AP_TA_EXAM)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_TA_EXAM main.cpp Types/Kid_type.h Types/Impact_type.h Kids/Kid.h Kids/Kid.cpp Kids/Coward_kid.h Kids/Peaceful_kid.h Kids/Angry_kid.h Kids/Angry_kid.cpp Kids/Peaceful_kid.cpp Kids/Coward_kid.cpp Input_handler/Input_handler.h Input_handler/Input_handler.cpp)