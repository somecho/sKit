cmake_minimum_required(VERSION 3.15)

project(sKit VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)

set(SKIT_PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/BRect.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/grids.hpp
)

find_package(glm REQUIRED)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${SKIT_PUBLIC_HEADERS}
        ${PROJECT_NAME}/BRect.cpp
        ${PROJECT_NAME}/grids.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/sKit
)

install(FILES ${SKIT_PUBLIC_HEADERS} DESTINATION include/sKit)

# TESTS
include(lib/doctest/doctest.cmake)
enable_testing()

set(SKIT_TESTS 
    BRect 
    grids
) 

foreach(TEST_NAME IN LISTS SKIT_TESTS)
    add_executable(${TEST_NAME}Test ${PROJECT_NAME}/${TEST_NAME}.test.cpp)
    target_include_directories(${TEST_NAME}Test PRIVATE lib)
    target_link_libraries(${TEST_NAME}Test ${PROJECT_NAME})
    doctest_discover_tests(${TEST_NAME}Test)
endforeach()