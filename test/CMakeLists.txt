#project(run_tests)
# add_gismo_executable(run_tests run_tests.cpp)

add_executable(run_tests run_tests.cpp)
target_link_libraries(run_tests gtest_main gismo)
add_test(NAME run_test COMMAND run_tests)
