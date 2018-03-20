#include <iostream>

#define version() versionf(argv[0])

void versionf(char* argv)
{
	std::cout << argv << " version " << VERSION << std::endl;
}
