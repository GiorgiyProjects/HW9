cmake_minimum_required(VERSION 3.5)

project(bulk_server)

find_package(Boost COMPONENTS system unit_test_framework REQUIRED)
add_executable(bulk_server main.cpp async_server.cpp async_server.h CommandBlock.h)
add_executable(test tests.cpp async_server.cpp async_server.h CommandBlock.h)

set(TARGETS bulk_server test)

foreach(target ${TARGETS})
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
            CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${target} PRIVATE "-g;-Wall;-Wextra;-Werror;-pedantic")
        target_link_libraries(${target} PUBLIC pthread)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${target} PRIVATE "/W4;/WX")
    endif()
    target_compile_features(${target} PUBLIC cxx_std_17)
endforeach(target IN ${TARGETS})

target_link_libraries(bulk_server PUBLIC Boost::system)
target_link_libraries(test PUBLIC Boost::system)