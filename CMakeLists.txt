cmake_minimum_required(VERSION 3.2)

project(helloworld)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/inc/version.h)

#file(GLOB_RECURSE SRCS src/*.cpp)
set(HEADERS ${PROJECT_SOURCE_DIR}/inc/lib.h)
set(INC_DIR ${PROJECT_SOURCE_DIR}/inc)

add_executable(helloworld_cli src/main.cpp ${HEADER_FILES})
target_include_directories(helloworld_cli PUBLIC ${INC_DIR})

add_library(helloworld src/lib.cpp ${HEADER_FILES})
target_include_directories(helloworld PUBLIC ${INC_DIR})

add_executable(test_version src/test_version.cpp ${HEADER_FILES})
target_include_directories(test_version PUBLIC ${INC_DIR})

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra;-g;-O0"
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_cli
    helloworld
    Threads::Threads
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")

set(CPACK_PACKAGE_CONTACT shebdim@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(helloworld_tests test_version)
