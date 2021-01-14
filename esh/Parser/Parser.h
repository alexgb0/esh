#pragma once
#include "../common.h"

#include <vector>

class CParser
{
public:
	void Parse(CContext *ctx, CVContext* ctxp);
	
private:

	std::vector<std::string> split(const std::string& s, char delimiter);
	void map(std::vector<std::string> vec, std::map<std::string, std::any> &mVars, std::map<std::string, std::any> &mArgs, std::vector<std::string> &vCmd);
	std::vector<std::string> vTrim;
};

