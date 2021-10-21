#include "ChiliException.h"

ChiliException::ChiliException(int line, const char* file) noexcept
{

}

const char* ChiliException::what() const noexcept
{
	return nullptr;
}
