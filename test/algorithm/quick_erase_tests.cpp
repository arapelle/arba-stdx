#include <arba/stdx/algorithm/quick_erase.hpp>
#include <gtest/gtest.h>
#include <list>

TEST(quick_erase_tests, quick_erase__any_element__last_int__ok)
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 10 };
    auto iter = --vec.end();
    stdx::quick_erase(vec, iter);
    std::vector<int> expected_vec = { 0, 1, 2, 3, 4, 5, 6 };
    ASSERT_EQ(vec, expected_vec);
}

TEST(quick_erase_tests, quick_erase__not_last_element__not_last_int__ok)
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 10 };
    auto iter = vec.begin();
    stdx::quick_erase(vec, iter, stdx::not_last_element);
    std::vector<int> expected_vec = { 10, 1, 2, 3, 4, 5, 6 };
    ASSERT_EQ(vec, expected_vec);
}

TEST(quick_erase_tests, quick_erase__not_random_range__ok)
{
    std::list<int> collection = { 0, 1, 2, 3, 4, 5, 6, 10 };
    auto iter = collection.begin();
    stdx::quick_erase(collection, iter);
    std::list<int> expected_collection = { 1, 2, 3, 4, 5, 6, 10 };
    ASSERT_EQ(collection, expected_collection);
}
