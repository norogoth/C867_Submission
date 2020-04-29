#pragma once
#include <string>
#include <map>

enum class DegreeType { SECURITY, NETWORK, SOFTWARE }; //So SECURITY=0 and so on

static inline const std::string degreeTypeStrings[] = { "SECURITY","NETWORK","SOFTWARE" }; //This is an array of strings that can be useful when printing types.

static inline std::map<std::string, DegreeType> lookup = { {"SECURITY",DegreeType::SECURITY}, {"NETWORK",DegreeType::NETWORK}, {"SOFTWARE",DegreeType::SOFTWARE} };