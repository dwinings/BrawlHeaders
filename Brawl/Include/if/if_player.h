#pragma once

#include <StaticAssert.h>
#include <types.h>

class IfPlayer {
    char _0[1492];
    virtual ~IfPlayer();
};
static_assert(sizeof(IfPlayer) == 1496, "Class is wrong size!");