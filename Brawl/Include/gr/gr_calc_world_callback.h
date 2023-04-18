#pragma once

#include <StaticAssert.h>
#include <memory.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_calcworldcallback.h>
#include <types.h>

class grNodeCallbackData {
public:
    int m_nodeIndex;
    union {
        struct {
            int _pad : 25;
            bool m_flag7 : 1; // & 0x40
            bool m_flag6 : 1; // & 0x20
            bool m_flag5 : 1; // & 0x10
            bool m_flag4 : 1; // & 8
            bool m_flag3 : 1; // & 4
            bool m_flag2 : 1; // & 2
            bool m_flag1 : 1; // & 1
        };
        u32 m_flags;
    };

    Vec3f m_pos;
    Vec3f m_rot;
    Vec3f m_scale;
    Vec3f m_offsetPos;
    Vec3f m_offsetRot;
    Vec3f m_offsetScale;
    Matrix m_matrix;
};
static_assert(sizeof(grNodeCallbackData) == 128, "Class is wrong size!");

class grCalcWorldCallBack : public nw4r::g3d::ICalcWorldCallBack {

public:
    grNodeCallbackData* m_nodeCallbackDataArray;
    unsigned int m_numNodeCallbackData;
    unsigned int m_index;

    virtual ~grCalcWorldCallBack();
    virtual void ExecCallbackA(int* unk1, int unk2, int* unk3); // TODO
    virtual void ExecCallbackB(int* unk1, int unk2, int* unk3); // TODO
    virtual void ExecCallbackC();                               // TODO
    virtual int initialize(bool unk1, HeapType heapType);
    virtual int clearAll();
};
static_assert(sizeof(grCalcWorldCallBack) == 16, "Class is wrong size!");

// Size: 16