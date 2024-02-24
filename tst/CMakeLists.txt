cmake_minimum_required(VERSION 3.10)
project(demo)

set(BINARY ${CMAKE_PROJECT_NAME}-ut)
set(LIBRARY ${CMAKE_PROJECT_NAME}-lib)

file(GLOB SOURCES LIST_DIRECTORIES true ../src/*.cpp)
file(GLOB TEST_SOURCES LIST_DIRECTORIES false *.cpp)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include_directories(../src)
#add_library(${LIBRARY} STATIC ${SOURCES}) 
add_library(${LIBRARY} SHARED ${SOURCES}) 
add_executable(${BINARY} ${TEST_SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ${LIBRARY} gtest gmock)

