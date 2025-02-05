#include <arba/stdx/io/copy.hpp>
#include <arba/stdx/io/open_file.hpp>

#include <array>
#include <fstream>

inline namespace arba
{
namespace stdx
{

void copy_stream(std::istream& input_stream, std::size_t number_of_bytes, std::ostream& output_stream)
{
    constexpr std::size_t buffer_size = 1024;
    std::array<char, buffer_size> bytes;

    for (std::size_t file_size = number_of_bytes; file_size > 0;)
    {
        std::size_t byte_count = std::min<std::size_t>(bytes.size(), file_size);
        if (!input_stream.read(bytes.data(), byte_count)) [[unlikely]]
            input_stream.exceptions(std::ifstream::failbit);
        if (!output_stream.write(bytes.data(), byte_count)) [[unlikely]]
            input_stream.exceptions(std::ifstream::failbit);
        file_size -= byte_count;
    }
}

void copy_fstream(std::ifstream& input_fstream, std::ostream& output_stream)
{
    const auto cur_pos = input_fstream.tellg();
    input_fstream.seekg(0, std::ifstream::end);
    const std::size_t number_of_bytes = input_fstream.tellg() - cur_pos;
    input_fstream.seekg(cur_pos, std::ifstream::beg);
    copy_stream(input_fstream, number_of_bytes, output_stream);
}

void copy_file(const std::filesystem::path& input_fpath, std::ostream& output_stream)
{
    std::ifstream input_fstream = open_input_file(input_fpath, std::ifstream::ate | std::ifstream::binary);
    const std::size_t number_of_bytes = input_fstream.tellg();
    input_fstream.seekg(0, std::ifstream::beg);
    copy_stream(input_fstream, number_of_bytes, output_stream);
}

} // namespace stdx
} // namespace arba
