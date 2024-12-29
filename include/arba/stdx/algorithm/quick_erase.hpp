#pragma once

#include "unstable_erase.hpp"

inline namespace arba
{
namespace stdx
{

template <std::ranges::random_access_range range_type, UnstableEraseElementPolicy PolicyType>
inline void quick_erase(range_type& range, std::ranges::iterator_t<range_type> iter, PolicyType policy)
{
    unstable_erase(range, iter, policy);
}

template <std::ranges::range range_type, UnstableEraseElementPolicy PolicyType>
inline void quick_erase(range_type& range, std::ranges::iterator_t<range_type> iter, PolicyType)
{
    range.erase(iter);
}

template <std::ranges::range range_type>
inline void quick_erase(range_type& range, std::ranges::iterator_t<range_type> iter)
{
    quick_erase(range, iter, any_element);
}

} // namespace stdx
} // namespace arba
