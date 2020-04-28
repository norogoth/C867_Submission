#pragma once
#include <string>

enum class degreeType {SECURITY, NETWORK, SOFTWARE}; //So SECURITY=0 and so on

static const std::string degreeTypeStrings[] = {"SECURITY","NETWORK","SOFTWARE"}; //This is an array of strings that can be useful when printing types.