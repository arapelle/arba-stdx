include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

add_cpp_library_basic_tests(${PROJECT_TARGET_NAME} GTest::gtest_main
    SOURCES
        project_version_tests.cpp
        algorithm/unstable_erase_tests.cpp
        algorithm/quick_erase_tests.cpp
        chrono/format_time_point_tests.cpp
        chrono/stopwatch_tests.cpp
        container/span_tests.cpp
        design_pattern/singleton_tests.cpp
        io/check_file_tests.cpp
        io/copy_tests.cpp
        io/open_file_tests.cpp
)
