#include <iostream>
#include <vector>
#include <string_view>

std::vector<std::string_view> split(std::string_view input, char separator=' ') {
    std::vector<std::string_view> words;

    std::size_t start = input.find_first_not_of(separator);
    for (auto end = input.find(separator, start); end != std::string_view::npos; end = input.find(separator, start)) {
        words.push_back(input.substr(start, end-start));
        // avoid multiple sperators together
        start = input.find_first_not_of(separator, end + 1);
    }

    if (start != std::string_view::npos) {
        words.push_back(input.substr(start));
    }
    return words;
}

int main() {
    std::string input("    I am  a string to     be splitted ");
    for (const auto& token : split(input)) {
        std::cerr << "[" << token << "]" << std::endl;
    }
    return 0;
}

/*
Output:
[I]
[am]
[a]
[string]
[to]
[be]
[splitted]
*/
