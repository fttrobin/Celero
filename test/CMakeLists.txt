
file(GLOB CELERO_TESTS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
)

add_executable(celero-tests ${CELERO_TESTS_SOURCES})

target_link_libraries(celero-tests
    gtest
    gtest_main
    pthread
)
