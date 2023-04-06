#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <it/item.h>



class itArchive {
public:
    enum Type {
        Temp = 0x0,
        Assist = 0x1,
        Common = 0x2,
        D = 0x3,
        Stage = 0x4,
        F = 0x5
    };

    Type m_itArchiveType;
    u8 m_4;
    char _5[3];
    itKind m_itKind;
    int m_itVariation;
    int m_commonParamArchiveId;
    int m_brresArchiveId;
    int m_paramArchiveId;
    int m_soundGroup;
    int m_32;
    int m_numItemsActive;
    int m_40;

    virtual ~itArchive();

    STATIC_CHECK(sizeof(itArchive) == 48)
};


