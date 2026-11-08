#pragma once

#include <cstdint>

enum Car_command : std::uint16_t
{
    LOCK = 0,
    UNLOCK = 1,
    TRUNK = 2,
};
