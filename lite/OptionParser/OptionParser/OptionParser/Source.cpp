#include "OptionParser.h"

int main (int argc, char** argv)
{
	OptionParser op_input_param(argc, argv);
	if (op_input_param.optionContains("-h")) {
		// Print help msg
	}
	const std::string &str_input_file = op_input_param.optionParse("-f");
	if (!str_input_file.empty()) {
		// Do sth.
	}
	return 0;
}