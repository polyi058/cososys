#pragma once
#include <string>
#include <algorithm>
#include <unordered_set>

namespace helpers {
    inline bool contains(std::vector<std::string> vec, std::string elem) {
        return (count(vec.begin(), vec.end(), elem));
    }

    inline std::string get_short_path(std::string path) {
        return path.substr(path.find_last_of("/\\") + 1);
    }

    inline void remove_duplicates(std::vector<std::string>& vec) {
        std::unordered_set<std::string> u_s;
        for (std::string s : vec) {
            u_s.insert(s);
        }
        vec.assign(u_s.begin(), u_s.end());
    }
}