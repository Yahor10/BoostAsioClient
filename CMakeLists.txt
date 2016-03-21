cmake_minimum_required(VERSION 3.3)
project(BoostAsioClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_thread -lboost_system -lboost_serialization")
set(SOURCE_FILES main.cpp client.cpp client.h payload/payload.cpp payload/payload.h)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system filesystem thread serialization REQUIRED)
add_executable(BoostAsioClient ${SOURCE_FILES})

target_link_libraries(BoostAsioClient
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_REGEX_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_SERIALIZATION_LIBRARY}
        )