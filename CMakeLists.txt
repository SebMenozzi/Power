# OPTIMISATION FLAGS :
set(OPT_FLAGS, "-Ofast")
# END OPTIMIZATION FLAGS

# SOURCES :
# Put all your sources here EXCEPT YOUR MAIN.CC
set(SRC_ENGINE
    src/board/board.cc
    src/board/force.cc
    src/board/tile.cc
    src/board/move_gen.cc
    src/player/player.cc
)

# Directories containing headers must be specified in the include_directories()
include_directories(src)

# END SOURCES

# SETUP
cmake_minimum_required(VERSION 3.12)
project(Chess)

# BUILD OPTIONS
set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OPT_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3 -fsanitize=address")

# LIBRARIES
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(Boost_USE_STATIC_LIBS ON)
endif()
find_package(Boost REQUIRED COMPONENTS system program_options)
set(LIBRARIES Boost::system Boost::program_options ${CMAKE_DL_LIBS})

# POWER
add_executable(power)
target_sources(power PRIVATE "src/main.cc" ${SRC_ENGINE})
target_link_libraries(power PRIVATE ${LIBRARIES})
