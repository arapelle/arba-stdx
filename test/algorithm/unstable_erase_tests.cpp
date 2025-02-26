#include <arba/stdx/algorithm/unstable_erase.hpp>

#include <gtest/gtest.h>

TEST(unstable_erase_tests, unstable_erase__any_element__not_last_string__ok)
{
    std::vector<std::string> vec = { "0", "1", "2", "3", "4", "5", "6", "10" };
    auto iter = vec.begin() + 2;
    stdx::unstable_erase(vec, iter);
    std::vector<std::string> expected_vec = { "0", "1", "10", "3", "4", "5", "6" };
    ASSERT_EQ(vec, expected_vec);
}

TEST(unstable_erase_tests, unstable_erase__any_element__last_string__ok)
{
    std::vector<std::string> vec = { "0", "1", "2", "3", "4", "5", "6", "10" };
    auto iter = --vec.end();
    stdx::unstable_erase(vec, iter);
    std::vector<std::string> expected_vec = { "0", "1", "2", "3", "4", "5", "6" };
    ASSERT_EQ(vec, expected_vec);
}

TEST(unstable_erase_tests, unstable_erase__any_element__not_last_int__ok)
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 10 };
    auto iter = vec.begin() + 2;
    stdx::unstable_erase(vec, iter);
    std::vector<int> expected_vec = { 0, 1, 10, 3, 4, 5, 6 };
    ASSERT_EQ(vec, expected_vec);
}

TEST(unstable_erase_tests, unstable_erase__any_element__last_int__ok)
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 10 };
    auto iter = --vec.end();
    stdx::unstable_erase(vec, iter);
    std::vector<int> expected_vec = { 0, 1, 2, 3, 4, 5, 6 };
    ASSERT_EQ(vec, expected_vec);
}

TEST(unstable_erase_tests, unstable_erase__not_last_element__not_last_int__ok)
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 10 };
    auto iter = vec.begin() + 2;
    stdx::unstable_erase(vec, iter, stdx::not_last_element);
    std::vector<int> expected_vec = { 0, 1, 10, 3, 4, 5, 6 };
    ASSERT_EQ(vec, expected_vec);
}
