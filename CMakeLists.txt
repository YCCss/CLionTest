cmake_minimum_required(VERSION 3.16)
project(CLionTest)

set(CMAKE_CXX_STANDARD 14)


add_executable(CLionTest
        main.cpp
        solve1.h
        prime_number.h
        learn_easyx.h
        bigheap.h mthread.cpp thread_pool1.cpp thread_pool2.h package.h test.cpp semaphore.h output_container.h)

#target_link_libraries(CLionTest libEasyX.a)