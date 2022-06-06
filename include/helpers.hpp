#pragma once
#include <string>
#include <algorithm>

inline bool contains(std::vector<std::string> vec, std::string elem) {
    return (count(vec.begin(), vec.end(), elem));
}

inline std::string get_short_path(std::string path) {
    return path.substr(path.find_last_of("/\\") + 1);
}