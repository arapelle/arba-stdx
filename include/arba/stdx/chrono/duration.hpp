#pragma once

#include <chrono>

inline namespace arba
{
namespace stdx
{

using nanoseconds_f32 = std::chrono::duration<float, std::chrono::nanoseconds::period>;
using microseconds_f32 = std::chrono::duration<float, std::chrono::microseconds::period>;
using milliseconds_f32 = std::chrono::duration<float, std::chrono::milliseconds::period>;
using seconds_f32 = std::chrono::duration<float>;
using minutes_f32 = std::chrono::duration<float, std::chrono::minutes::period>;
using hours_f32 = std::chrono::duration<float, std::chrono::hours::period>;
using days_f32 = std::chrono::duration<float, std::chrono::days::period>;
using weeks_f32 = std::chrono::duration<float, std::chrono::weeks::period>;
using years_f32 = std::chrono::duration<float, std::chrono::years::period>;

using nanoseconds_f64 = std::chrono::duration<double, std::chrono::nanoseconds::period>;
using microseconds_f64 = std::chrono::duration<double, std::chrono::microseconds::period>;
using milliseconds_f64 = std::chrono::duration<double, std::chrono::milliseconds::period>;
using seconds_f64 = std::chrono::duration<double>;
using minutes_f64 = std::chrono::duration<double, std::chrono::minutes::period>;
using hours_f64 = std::chrono::duration<double, std::chrono::hours::period>;
using days_f64 = std::chrono::duration<double, std::chrono::days::period>;
using weeks_f64 = std::chrono::duration<double, std::chrono::weeks::period>;
using years_f64 = std::chrono::duration<double, std::chrono::years::period>;

} // namespace stdx
} // namespace arba
