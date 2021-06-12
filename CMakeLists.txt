cmake_minimum_required(VERSION 3.17.3)
project(cont_my)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(cont_my
        src/list.hpp
        src/Reverse_iterator.hpp
        src/stack.hpp
        src/queue.hpp
        src/Algorithm.hpp
        src/vector.hpp
        src/map_node.hpp
        src/node.hpp
#        unit_tests/test_list.cpp
#        unit_tests/test_list.sh
#        unit_tests/test_map.cpp
#        unit_tests/test_map.sh
#        unit_tests/test_queue.cpp
#        unit_tests/test_queue.sh
#        unit_tests/test_stack.cpp
#        unit_tests/test_stack.sh
        unit_tests/test_vector.cpp
        unit_tests/test_vector.sh
        unit_tests/unit_tests.hpp
        )
