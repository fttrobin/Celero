
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

add_custom_target(celero-tests-run
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/celero-tests
    DEPENDS celero-tests
    COMMENT "Executing unit tests..."
)
