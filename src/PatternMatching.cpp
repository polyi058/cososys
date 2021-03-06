#include "PatternMatching.h"

using namespace std;

PatternMatching::PatternMatching() {
    m_trie.case_insensitive();
}

PatternMatching::PatternMatching(string dictionary_path, vector<string> file_paths) : PatternMatching() {
    add_dictionary(dictionary_path);
    for (auto file_path : file_paths) {
        add_file_path(file_path);
    }
}

std::map<std::string, std::vector<std::string>> PatternMatching::getMatches()
{
    return m_matches;
}

// Return matches under the following format:
// <filename_1>: <match_1_1>, <match_1_2>, ...
// <filename_2>: <match_2_1>, <match_2_2>, ...
std::string PatternMatching::getMatchesStr()
{
    string matches_str;
    for (auto match : m_matches) {
        matches_str.append(match.first + ": ");
        for (auto word : match.second) {
            matches_str.append(word + ", ");
        }
        matches_str.erase(matches_str.size() - 2);
        matches_str.append("\n");
    }
    return matches_str;
}

// Register dictionary and insert into the trie
int PatternMatching::add_dictionary(string dictionary_path) {
    if (helpers::contains(m_dictionary_paths, dictionary_path))
        return -1;
    
    m_dictionary_paths.push_back(dictionary_path);
    string word;
    
    ifstream dictionary(dictionary_path);
    if (!dictionary.is_open()) {
        cout << "Can't open dictionary " << dictionary_path << endl;
        return -1;
    }

    while (getline(dictionary, word)) {
        m_trie.insert(word);
    }
    dictionary.close();

    return 0;
}

// Register new file path
int PatternMatching::add_file_path(string file_path) {
    if (helpers::contains(m_file_paths, file_path))
        return - 1;
    m_file_paths.push_back(file_path);
    return 0;
}

// Search for matches
int PatternMatching::search() {
    string text;
    m_matches.clear();
    // Loop through the file paths holding the texts
    for (string file_path : m_file_paths) {
        ifstream file(file_path);
        if (!file.is_open()) {
            cout << "Can't open file " << file_path << endl;
            continue;
        }
        // Get only the file name from a path (+ extension)
        string file_path_short = helpers::get_short_path(file_path);
        m_matches.insert({ file_path_short, {} });
        while (getline(file, text)) {
            // Parse the text, all matches are returned
            auto matches = m_trie.parse_text(text);
            for (auto emit : matches) {
                // Collect all the matches
                m_matches[file_path_short].push_back(emit.get_keyword());
            }
        }
        helpers::remove_duplicates(m_matches[file_path_short]);
        file.close();
    }
    return 0;
}

PatternMatching::~PatternMatching() {
    m_file_paths.clear();
    m_dictionary_paths.clear();
    m_matches.clear();
}

