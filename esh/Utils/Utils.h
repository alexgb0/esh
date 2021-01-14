#pragma once

#include "../common.h"

namespace Utils
{
	inline void Panic(std::string arg)
	{
#if _DEBUG
		fmt::print(fmt::fg(fmt::color::red), "[DEBUG PANIC] {}.", arg);
#else
		fmt::print(fmt::fg(fmt::color::red), "{}.", arg);
#endif // _DEBU

	}
}