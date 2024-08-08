cmake_minimum_required(VERSION 3.15)

project(sKit VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)

set(SKIT_PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/BRect.hpp
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${SKIT_PUBLIC_HEADERS}
        ${PROJECT_NAME}/BRect.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/sKit
)

install(FILES ${SKIT_PUBLIC_HEADERS} DESTINATION include/sKit)