#pragma once

#include <filesystem>
#include <fstream>
#include <string_view>

namespace ut
{
inline std::filesystem::path create_resource(std::string_view ut_dir_name)
{
    const std::filesystem::path root_dpath = std::filesystem::temp_directory_path() / "dev/arba/stdx" / ut_dir_name;
    std::filesystem::create_directories(root_dpath);

    const std::filesystem::path rsc_dpath = root_dpath / "rsc";
    std::filesystem::create_directories(rsc_dpath);

    const std::filesystem::path story_fpath = rsc_dpath / "story.txt";
    std::ofstream rsc_fstream(story_fpath, std::ios::trunc);
    rsc_fstream << "Once upon a time";

    return story_fpath;
}
} // namespace ut
