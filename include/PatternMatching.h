#pragma once
#include "aho_corasick.hpp"
#include "helpers.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace ac = aho_corasick;
using trie = ac::trie;

class PatternMatching {
public:
	PatternMatching();
	PatternMatching(std::string dictionary_path, std::vector<std::string> text_paths);
	std::map<std::string, std::vector<std::string>> getMatches();
	std::string getMatchesStr();
	int add_dictionary(std::string dictionary_path);
	int add_file_path(std::string text_path);
	int search();
	~PatternMatching();
private:
	trie m_trie;
	std::vector<std::string> m_file_paths;
	std::vector<std::string> m_dictionary_paths;
	std::map<std::string, std::vector<std::string>> m_matches;
};

