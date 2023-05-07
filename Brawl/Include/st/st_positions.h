#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>
#include <nw4r/g3d/g3d_resfile.h>

class stRange {
public:
    float m_left;
    float m_right;
    float m_top;
    float m_bottom;
};

class stPositions {
public:
    char _0[8];
    nw4r::g3d::ResFileData* m_resFile;
    char _c[88];

    float* getDeadRange(stRange* range);
    float* getCameraRange(stRange* range);
    void loadPositionData(nw4r::g3d::ResFile* resFile);

};
static_assert(sizeof(stPositions) == 100, "Class is wrong size!");