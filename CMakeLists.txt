cmake_minimum_required(VERSION 3.16)
project(CLionTest)

set(CMAKE_CXX_STANDARD 14)

set(EasyX_ROOT E:\\YCQ\\code\\C++\\CLionTest\\lib\\easyx)
set(EasyX_INC  ${EasyX_ROOT}/include)
set(EasyX_LINK  ${EasyX_ROOT}/lib64)
include_directories(${EasyX_INC})
link_directories(${EasyX_LINK})


add_executable(CLionTest
        main.cpp
        test.cpp
        solve1.h
        prime_number.h
        learn_easyx.h
        bigheap.h mthread.cpp thread_pool1.cpp thread_pool2.h package.h semaphore.h output_container.h)

target_link_libraries(CLionTest libeasyx.a)


#add_executable(CLionTest
#        #Game/Tetris/Game_Tetris1.cpp
#        Game/Snake/snake.cpp)
#
#target_link_libraries(CLionTest libeasyx.a)
