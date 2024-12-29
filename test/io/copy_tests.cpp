#include "create_resource.hpp"

#include <arba/stdx/io/copy.hpp>
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>

std::filesystem::path create_resource()
{
    return ut::create_resource("copy_tests");
}

TEST(copy_tests, copy_stream__sstream_to_sstream__ok)
{
    std::istringstream iss("hello world", std::ios::binary);
    std::ostringstream oss(std::ios::binary);
    stdx::copy_stream(iss, 4, oss);
    ASSERT_EQ(oss.str(), "hell");
}

TEST(copy_tests, copy_stream__fstream_to_sstream__ok)
{
    std::ifstream ifs(create_resource(), std::ios::binary);
    std::ostringstream oss(std::ios::binary);
    stdx::copy_fstream(ifs, oss);
    ASSERT_EQ(oss.str(), "Once upon a time");
}

TEST(copy_tests, copy_stream__fstream_to_sstream__get__ok)
{
    std::ifstream ifs(create_resource(), std::ios::binary);
    ifs.get();
    std::ostringstream oss(std::ios::binary);
    stdx::copy_fstream(ifs, oss);
    ASSERT_EQ(oss.str(), "nce upon a time");
}

TEST(copy_tests, copy_file__file_to_sstream__ok)
{
    std::ostringstream oss(std::ios::binary);
    stdx::copy_file(create_resource(), oss);
    ASSERT_EQ(oss.str(), "Once upon a time");
}

TEST(copy_tests, copy_file__missing_file__exception)
{
    std::ostringstream oss(std::ios::binary);
    try
    {
        stdx::copy_file("/__does_not_exists__", oss);
        FAIL() << "stdx::copy_file(\"/__does_not_exists__\", oss) should throw an error\n";
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        ASSERT_EQ(err.code().message(), "No such file or directory");
        SUCCEED();
    }
    catch (const std::iostream::failure& err)
    {
        FAIL();
    }
}

TEST(copy_tests, copy_file__existing_directory__exception)
{
    std::ostringstream oss(std::ios::binary);
    try
    {
        stdx::copy_file(std::filesystem::temp_directory_path(), oss);
        FAIL() << "stdx::copy_file(std::filesystem::temp_directory_path(), oss) should throw an error\n";
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        ASSERT_EQ(err.code().message(), "No such file or directory");
        SUCCEED();
    }
    catch (const std::iostream::failure& err)
    {
        FAIL();
    }
}
