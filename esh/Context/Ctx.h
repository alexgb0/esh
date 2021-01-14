#pragma once

#include <map>
#include <string>
#include <vector>
#include <any>
#include <fmt/color.h>

class CContext
{
public:
	/// <summary>
	/// This is the raw line what we got from the command line.
	/// </summary>
	std::string sLine;
	/// <summary>
	/// This is the line splitted. vSplitted[0] == command.
	/// </summary>
	std::vector<std::string> vSplitted;
	/// <summary>
	/// A vector of all arguments.
	/// Important! All the elements what starts with "-" like "-h" will be catalog as attributes (mArgs).
	/// Important! vCmd[0] != sCmd
	/// </summary>
	std::vector<std::string> vCmd;
	/// <summary>
	/// A vector of all arguments.
	/// Important! All the elements what starts with "-" like "-h" will be catalog as attributes (mArgs).
	/// Important! vCmd[0] != sCmd
	/// </summary>
	std::vector<std::string> vCmd2;
	/// <summary>
	/// This is a map where we store the attributes.
	/// </summary>
	std::map<std::string, std::any> mAttrib;
	/// <summary>
	/// This is a map where we store the attributes.
	/// </summary>
	std::map<std::string, std::any> mAttrib2;
	/// <summary>
	/// This is the command.
	/// </summary>
	std::string sCmd;
	/// <summary>
	/// This is the command.
	/// </summary>
	std::string sCmd2;
	/// <summary>
	/// True if you want to print something on the console.
	/// </summary>
	bool bVerbose;
	/// <summary>
	/// This will be the output of the program. If bVerbose is set to true
	/// </summary>
	std::string sOutput;
	/// <summary>
	/// Allow program to return a value.
	/// Important: Not confuse with sOutput
	/// </summary>
	bool bReturn;
	/// <summary>
	/// True if there is another command what can be execute if the first cmd returns true.
	/// </summary>
	bool bConditionalScond;
	

}; 