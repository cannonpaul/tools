#pragma once
#include <string>
#include <vector>

class OptionParser {
public:
	OptionParser(int &argc, char **argv) {
		for (int i = 1; i < argc; ++i)
			this->tokens.push_back(std::string(argv[i]));
	}
	const std::string& optionParse(const std::string &option) {
		std::vector<std::string>::const_iterator itr;
		itr = std::find(this->tokens.begin(), this->tokens.end(), option);
		if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
			return *itr;
		}
		return{};
	}
	bool optionContains(const std::string &option) {
		return std::find(this->tokens.begin(), this->tokens.end(), option)
			!= this->tokens.end();
	}
	bool optionContains(const std::vector<std::string> &options) {
		bool valid = true;
		for (auto option : options)
			valid &= std::find(this->tokens.begin(), this->tokens.end(), option)
			!= this->tokens.end();
		return valid;
	}
private:
	std::vector <std::string> tokens;
};
