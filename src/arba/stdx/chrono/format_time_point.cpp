#include <arba/stdx/chrono/format_time_point.hpp>

#include <iomanip>
#include <sstream>

inline namespace arba
{
namespace stdx
{
namespace private_
{

std::ostringstream& format_time_point(std::ostringstream& stream, std::string_view fmt_str,
                                      std::chrono::system_clock::time_point time_point)
{
    // convert to std::time_t in order to convert to std::tm (broken time)
    std::time_t timer = std::chrono::system_clock::to_time_t(time_point);
    std::tm* tm = std::localtime(&timer);
    stream << std::put_time(tm, fmt_str.data());
    std::string str = stream.str();
    return stream;
}

std::string format_time_point(std::string_view fmt_str, std::chrono::system_clock::time_point time_point)
{
    std::ostringstream stream;
    format_time_point(stream, fmt_str, time_point);
    return stream.str();
}

std::string format_time_point_ms(std::string_view fmt_str, char sep, std::chrono::system_clock::time_point time_point)
{
    std::ostringstream stream;
    // get number of milliseconds for the current second (remainder after division into seconds)
    std::chrono::milliseconds ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(time_point.time_since_epoch()) % 1000;
    format_time_point(stream, fmt_str, time_point) << sep << std::setfill('0') << std::setw(3) << ms.count();
    return stream.str();
}

std::string format_time_point_mcs(std::string_view fmt_str, char sep, std::chrono::system_clock::time_point time_point)
{
    std::ostringstream stream;
    // get number of microseconds for the current second (remainder after division into seconds)
    std::chrono::microseconds mcs =
        std::chrono::duration_cast<std::chrono::microseconds>(time_point.time_since_epoch()) % 1'000'000;
    format_time_point(stream, fmt_str, time_point) << sep << std::setfill('0') << std::setw(6) << mcs.count();
    return stream.str();
}

} // namespace private_

namespace
{
constexpr std::string_view HMS_fmt_str = "%H:%M:%S";
}

std::string format_HMS(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point(HMS_fmt_str, time_point);
}

std::string format_HMS_ms(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point_ms(HMS_fmt_str, '.', time_point);
}

std::string format_HMS_mcs(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point_mcs(HMS_fmt_str, '.', time_point);
}

namespace
{
constexpr std::string_view Ymd_HMS_fmt_str = "%Y-%m-%d %H:%M:%S";
}

std::string format_Ymd_HMS(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point(Ymd_HMS_fmt_str, time_point);
}

std::string format_Ymd_HMS_ms(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point_ms(Ymd_HMS_fmt_str, '.', time_point);
}

std::string format_Ymd_HMS_mcs(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point_mcs(Ymd_HMS_fmt_str, '.', time_point);
}

namespace
{
constexpr std::string_view filename_Ymd_HMS_fmt_str = "%Y%m%d_%H%M%S";
}

std::string format_Ymd_HMS_as_filename(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point(filename_Ymd_HMS_fmt_str, time_point);
}

std::string format_Ymd_HMS_ms_as_filename(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point_ms(filename_Ymd_HMS_fmt_str, '_', time_point);
}

std::string format_Ymd_HMS_mcs_as_filename(std::chrono::system_clock::time_point time_point)
{
    return private_::format_time_point_mcs(filename_Ymd_HMS_fmt_str, '_', time_point);
}

} // namespace stdx
} // namespace arba
