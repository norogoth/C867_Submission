#pragma once
#include <string>
#include <map>

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE }; //So SECURITY=0 and so on

static inline const std::string degreeTypeStrings[] = { "SECURITY","NETWORK","SOFTWARE" }; //This is an array of strings that can be useful when printing types.

static inline std::map<std::string, DegreeProgram> lookup = { {"SECURITY",DegreeProgram::SECURITY}, {"NETWORK",DegreeProgram::NETWORK}, {"SOFTWARE",DegreeProgram::SOFTWARE} };