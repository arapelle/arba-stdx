#include "create_resource.hpp"

#include <arba/stdx/io/check_file.hpp>
#include <format>
#include <fstream>
#include <gtest/gtest.h>

std::filesystem::path create_resource()
{
    return ut::create_resource("check_file_tests");
}

TEST(check_file_tests, check_input_file__existing_file__ok)
{
    try
    {
        stdx::check_input_file(create_resource());
        SUCCEED();
    }
    catch (const std::exception& err)
    {
        FAIL() << err.what();
    }
}

#if __linux__ || __APPLE__
TEST(check_file_tests, check_input_file__symlink_to_existing_file__ok)
{
    std::filesystem::path rsc_file = create_resource();
    try
    {
        std::filesystem::path rsc_slpath = rsc_file.parent_path() / "check_file.txt";
        if (!std::filesystem::exists(rsc_slpath))
            std::filesystem::create_symlink(rsc_file, rsc_slpath);
        stdx::check_input_file(rsc_slpath);
        SUCCEED();
    }
    catch (const std::exception& err)
    {
        FAIL() << err.what();
    }
}
#endif

TEST(check_file_tests, check_input_file__file_not_found__exception)
{
    try
    {
        stdx::check_input_file("/__does_not_exist__");
        FAIL();
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        ASSERT_EQ(err.code().message(), "No such file or directory");
        SUCCEED();
    }
    catch (const std::iostream::failure& err)
    {
        FAIL() << err.what();
    }
}

TEST(check_file_tests, check_input_file__existing_directory__exception)
{
    try
    {
        stdx::check_input_file(std::filesystem::temp_directory_path());
        FAIL();
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        ASSERT_EQ(err.code().message(), "No such file or directory");
        std::string_view err_message(err.what());
        std::string expected_err_string =
            std::format("filesystem error: Input path is not a regular file: No such file or directory [{}]",
                        std::filesystem::temp_directory_path().string());
        ASSERT_EQ(err_message, expected_err_string);
        SUCCEED();
    }
    catch (const std::iostream::failure& err)
    {
        FAIL() << err.what();
    }
}
