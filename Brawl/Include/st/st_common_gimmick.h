#pragma once

#include <gr/gr_gimmick_catapult.h>
#include <gr/gr_gimmick_ladder.h>
#include <gr/gr_gimmick_spring.h>
#include <st/stage.h>
#include <types.h>

class stCommonGimmick : public Stage {
public:
    gfArchive* m_fileData;
    gfArchive* m_secondaryFileData;
    char _spacer[5];
    bool m_isPaused;
    char _spacer2[2];
    gfArchive* m_commonFileData;

    stCommonGimmick(char* name, srStageKind stageKind);
    virtual void processBegin();
    virtual ~stCommonGimmick();

    void releaseArchive();
    void createGimmickCollision(int collIndex, Ground* ground, gfArchive* archive);
    bool createGimmickBeltConveyor2(grGimmickBeltConveyorData* beltConveyorAreaData);
    bool createGimmickWaterArea(grGimmickWaterData* waterAreaData);
    bool createGimmickWind2(grGimmickWindData* windAreaData);
    bool createGimmickHitPointEffectArea(grGimmickHitPointEffectData* hitPointEffectData);
    grGimmickLadder* createGimmickLadder(grGimmickLadderData* ladderData, gfArchive* archive);
    grGimmickCatapult* createGimmickCatapult(grGimmickCatapultData* catapultData, gfArchive* archive);
};