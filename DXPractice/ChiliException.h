#pragma once
#include <string>

class ChiliException : public std::exception
{
public:
	ChiliException(int line,const char* file)noexcept;
	const char* what() const noexcept override;
};
