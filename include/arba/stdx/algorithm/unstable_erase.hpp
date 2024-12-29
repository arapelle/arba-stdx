#pragma once

#include "policy/range_policy.hpp"

#include <arba/meta/type_traits/is_moveable_to_itself.hpp>
#include <cassert>
#include <ranges>

inline namespace arba
{
namespace stdx
{

template <class PolicyType>
concept UnstableEraseElementPolicy =
    std::is_same_v<PolicyType, any_element_t> || std::is_same_v<PolicyType, not_last_element_t>;

template <std::ranges::random_access_range range_type>
inline void unstable_erase(range_type& range, std::ranges::iterator_t<range_type> iter, any_element_t = any_element)
{
    assert(std::ranges::size(range) > 0);
    const auto last_iter = --std::ranges::end(range);
    if constexpr (meta::is_move_assignable_to_itself_v<std::ranges::range_value_t<range_type>>)
    {
        *iter = std::move(*last_iter);
    }
    else
    {
        if (iter != last_iter) [[likely]]
            *iter = std::move(*last_iter);
    }
    range.pop_back();
}

template <std::ranges::random_access_range range_type>
inline void unstable_erase(range_type& range, std::ranges::iterator_t<range_type> iter, not_last_element_t)
{
    assert(std::ranges::size(range) > 0);
    const auto last_iter = --std::ranges::end(range);
    assert(iter != --std::ranges::end(range));
    *iter = std::move(*last_iter);
    range.pop_back();
}

} // namespace stdx
} // namespace arba
