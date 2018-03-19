/************************************
* Copied
* Title: Check if a file exists
* Author: Rico Cordova
* Date: 20110610
* Code Version: No version given
* Availability: https://stackoverflow.com/a/6296808
************************************/

#include <sys/stat.h>
// Function: fileExists
/**
    Check if a file exists
@param[in] filename - the name of the file to check

@return    true if the file exists, else false

*/
bool fileExists(const std::string& filename)
{
	struct stat buf;
	if (stat(filename.c_str(), &buf) != -1)
	{
		return true;
	}
	return false;
}
