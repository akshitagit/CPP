#include <iostream>
#include <stack>
#include <string>
// This program checks if a strings parenthesis are balanced or not. Happy Hacktober :]
class parenthesis {
public:
	bool validator(std::string str) {
		std::stack<char> trax;
		for (const auto& t : str) {
			switch (t) {
			case '(': trax.push(')'); break;
			case '[': trax.push(']'); break;
			case '{': trax.push('}'); break;
			default:
				if (trax.size() == 0 || t != trax.top()) return false;
				else trax.pop();
			}
		}
		return trax.size() == 0;
	}
};
int main() {
	parenthesis checkitout;
	std::string str;
	std::cout << "Here to check your strings parenthesis? Go ahead enter a string.." << std::endl;
	std::cin >> str;
	std::cout << "the result it: " << checkitout.validator(str) << std::endl;
}