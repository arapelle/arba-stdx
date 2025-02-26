#include "create_resource.hpp"
#include <arba/stdx/io/open_file.hpp>

#include <gtest/gtest.h>

#include <format>
#include <fstream>

std::filesystem::path create_resource()
{
    return ut::create_resource("open_file_tests");
}

TEST(open_file_tests, test_open_input_file)
{
    try
    {
        std::ifstream input_fstream = stdx::open_input_file(create_resource());
        SUCCEED();
    }
    catch (...)
    {
        FAIL();
    }
}

TEST(open_file_tests, test_open_input_file_exception_file_not_found)
{
    try
    {
        std::ifstream input_fstream = stdx::open_input_file("/__does_not_exist__");
        FAIL();
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        EXPECT_EQ(err.code().message(), "No such file or directory");
        SUCCEED();
    }
    catch (const std::iostream::failure& err)
    {
        FAIL();
    }
}

TEST(open_file_tests, test_open_input_file_exception_not_regular_file)
{
    try
    {
        std::ifstream input_fstream = stdx::open_input_file(std::filesystem::temp_directory_path());
        FAIL();
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        EXPECT_EQ(err.code().message(), "No such file or directory");
        std::string_view err_message(err.what());
        std::string expected_err_string =
            std::format("filesystem error: Input path is not a regular file: No such file or directory [{}]",
                        std::filesystem::temp_directory_path().string());
        EXPECT_EQ(err_message, expected_err_string);
        SUCCEED();
    }
    catch (const std::iostream::failure& err)
    {
        FAIL();
    }
}
