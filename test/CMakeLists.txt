cmake_minimum_required(VERSION 2.6)

project(pedalboard_tests)

message(BUILDING PEDALBOARD TESTS)

set(PEDALBOARD_TESTS "pedalboardTests")
set(PEDALBOARD_INC "$ENV{HOME}/Projects/BLEMidiESP32/main/Inc")
set(LIB_PATH "$ENV{HOME}/Projects/BLEMidiESP32/build/esp-idf")
set(COMPONENTS_PATH "$ENV{IDF_PATH}/components")

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS}/)
include_directories(${PEDALBOARD_INC}/
                    ${COMPONENTS_PATH}/freertos/include/
                    ${COMPONENTS_PATH}/driver/include/
                    )

file(GLOB TEST_SOURCES "main_test.cpp")

add_executable(${PEDALBOARD_TESTS} ${TEST_SOURCES})
target_link_libraries(${PEDALBOARD_TESTS}
                      ${LIB_PATH}/freertos/libfreertos.a
                      ${LIB_PATH}/driver/libdriver.a
                      )
target_link_libraries(${PEDALBOARD_TESTS} ${GTEST_LIBRARIES} pthread)