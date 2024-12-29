#pragma once

#include <filesystem>
#include <istream>
#include <ostream>

inline namespace arba
{
namespace stdx
{

void copy_stream(std::istream& input_stream, std::size_t number_of_bytes, std::ostream& output_stream);
void copy_fstream(std::ifstream& input_fstream, std::ostream& output_stream);
void copy_file(const std::filesystem::path& input_fpath, std::ostream& output_stream);

} // namespace stdx
} // namespace arba
