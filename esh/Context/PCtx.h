#pragma once

#include <map>
#include <string>
#include <vector>
#include <any>
#include <fmt/color.h>

class CVContext
{
public:
	/// <summary>
	/// This is the PS1. 
	/// Also know as the prompt.
	/// </summary>
	std::string fsPS1 = fmt::format(fmt::fg(fmt::color::white), "$ ");
	/// <summary>
	/// Allow have runtime variables.
	/// </summary>
	std::map<std::string, std::any> mVars =
	{
		{"$PS1", fsPS1},
	};
};