include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    lr1_tests
    lr1_test.cpp
        lr1_test.cpp
)

target_link_libraries(
    lr1_tests
    lr1_lib
    GTest::gtest_main
)

target_include_directories(lr1_tests PUBLIC ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(lr1_tests)