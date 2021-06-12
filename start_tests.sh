#!/bin/bash

echo "LIST"
cd ./unit_tests && ./test_list.sh && cd ..
echo ""

echo "VECTOR"
cd ./unit_tests && ./test_vector.sh && cd ..
echo ""

echo "MAP"
cd ./unit_tests && ./test_map.sh && cd ..
echo ""

echo "STACK"
cd ./unit_tests && ./test_stack.sh && cd ..
echo ""

echo "QUEUE"
cd ./unit_tests && ./test_queue.sh && cd ..

