set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB SOURCES LIST_DIRECTORIES true *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}-run ${SOURCES})
#add_library(${BINARY}-lib SHARED ${SOURCES})

