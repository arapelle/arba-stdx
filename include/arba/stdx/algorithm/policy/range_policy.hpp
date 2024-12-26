#pragma once

inline namespace arba
{
namespace stdx
{

struct any_element_t
{
    explicit any_element_t() = default;
};
constexpr any_element_t any_element;

struct first_element_t
{
    explicit first_element_t() = default;
};
constexpr first_element_t first_element;

struct not_first_element_t
{
    explicit not_first_element_t() = default;
};
constexpr not_first_element_t not_first_element;

struct last_element_t
{
    explicit last_element_t() = default;
};
constexpr last_element_t last_element;

struct not_last_element_t
{
    explicit not_last_element_t() = default;
};
constexpr not_last_element_t not_last_element;

}
}
