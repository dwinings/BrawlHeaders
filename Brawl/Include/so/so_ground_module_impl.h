#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <memory.h>
#include <mt/mt_coll2d.h>
#include <so/so_null.h>
#include <so/so_array.h>
#include <so/so_event_observer.h>
#include <so/so_event_presenter.h>
#include <so/so_ground_tracer_impl.h>
#include <gr/gr_collision_status.h>
#include <so/so_collision_attack_part.h>

class soModuleAccesser;
class StageObject;

class soGroundConditionChecker {
    virtual ~soGroundConditionChecker();
    virtual bool isConditionNoCliffStop(soModuleAccesser* moduleAccesser);
};

class soGroundShapeImpl {
    char _0[4];
    grCollStatus* m_collStatus;
    Vec2f m_savePos;
    Vec2f m_offset;
    float m_24;
    float m_28;
    float m_rhombusUp;
    float m_rhombusDown;
    float m_rhombusWidth;
    int m_rhombusFollowNode;
    float m_downFriction;
    u8 m_materialType;
    char _53[3];
    u8 m_correct;
    u8 m_cliffCheck;
    char _58[6];

    virtual ~soGroundShapeImpl();

    STATIC_CHECK(sizeof(soGroundShapeImpl) == 68)
};

class soGroundNull {

};

class soGroundModule : public soGroundNull, public soNullable {

public:
    virtual ~soGroundModule();
    virtual void setup(void*, int taskId, bool);
    virtual void clean();
    virtual void constructGrCollision(int, int, Heaps::HeapType, u8, u8, u8);
    virtual void activate(int taskId, Vec2f*);
    virtual void deactivate();
    virtual void relocate(Vec2f*, u32 index);
    virtual void begin();
    virtual void update(u32);
    virtual void processFixPosition();
    virtual float getRotateYForGrCollisionMatrix();
    virtual void updateCheckGrCollision();
    virtual void updateGrCollisionMatrix();
    virtual void pause(u32);
    virtual void apply();
    virtual bool isReferenceModelNode();
    virtual void setCorrect(u8 correct, u32 index);
    virtual u8 getCorrect(u32 index);
    virtual void setCalcLineMove(bool calcLineMove, u32 index);
    virtual void setTargetLineCategory(u8 targetLineCategory, u32 index);
    virtual void setExclusiveLineAttr(short exclusiveLineAttr, u32 index);
    virtual void setPassableCheck(bool passableCheck, u32 index);
    virtual bool isPassableCheck(u32 index);
    virtual void setCloudThrough(bool cloudThrough, u32 index);
    virtual bool isCloudThrough(u32 index);
    virtual bool isCloudThroughOut(Vec2f* out, u32 index);
    virtual void setCorrectIgnoreSlope(u8 correctIgnoreSlope, u32 index);
    virtual void setCliffCheck(u8 cliffCheck, u32 index);
    virtual void setCliffHangData(void*);
    virtual void selectCliffHangData(u32 i,u32 index);
    virtual void setCliffBackRangeXMul(float cliffBackRangeXMul);
    virtual bool isStCliff(u32 index);
    virtual Vec3f getCorrectPos(u32 index);
    virtual void setCliffTeam(u8 cliffTeam, u32 index);
    virtual void entryCliff(u32 index);
    virtual void leaveCliff(u32 index);
    virtual Vec3f getCliffPos(u32 index);
    virtual float getCliffDir(u32 index);
    virtual void setStGroundForce(u32 index);
    virtual void setTestCollStop(bool testCollStop, u32 index);
    virtual void setTestCollStopStatus(bool testCollStop, u32 index);
    virtual void setTestPreMap(bool testPreMap, u32 index);
    virtual void setTestPreMapStatus(bool testPreMap, u32 index);
    virtual void setTestDynamicCollisionStatus(bool testDynamicCollision, u32 index);
    virtual void setTestDynamicCollision(bool testDynamicCollision, u32 index);
    virtual void setEventToGround(bool eventToGround, u32 index);
    virtual void setEventToGroundStatus(bool eventToGround, u32 index);
    virtual grCollStatus* getCollStatus(u32 index);
    virtual bool isOttotto(float, u32 index);
    virtual bool isNearCliff(float, float, u32 index);
    virtual bool isMissStepR(u32 index);
    virtual bool isMissStepL(u32 index);
    virtual bool isTouch(u8, u32 index);
    virtual u8 getTouchCount(u32 index);
    virtual Vec2f getTouchNormal(u8, u32 index);
    virtual Vec2f getTouchSpeed(u8, u32 index);
    virtual Vec2f getAttachMovementSpeed(u32 index);
    virtual Vec2f getAttachNormal(u32 index);
    virtual u8 getTouchFlag(u32 index);
    virtual u8 getTouchMaterialType(u8, u32 index);
    virtual Vec2f getTouchPos(u8, u32 index);
    virtual bool getTouchAttackData(soCollisionAttackData* outAttackData, int* out2, int* out3, u32 index);
    virtual float getTouchLength(u8, u32 index);
    virtual float getTouchLineRate(u8, u32 index);
    virtual bool getTouchNextNormal(bool getNext, Vec2f* outNormal, u8, u32 index);
    virtual void ignoreTouchLine(u8,u32 index);
    virtual bool isDiveDown(u32 index);
    virtual bool isCrush(float, u32 index);
    virtual bool isOnDynamicCollision(u32 index);
    virtual u32 getDownLineId(u32 index);
    virtual u32 getRightLineId(u32 index);
    virtual u32 getLeftLineId(u32 index);
    virtual u32 getUpLineId(u32 index);
    virtual u32 getDownLeftLineId(u32 index);
    virtual u32 getDownRightLineId(u32 index);
    virtual u32 getUpLeftLineId(u32 index);
    virtual u32 getUpRightLineId(u32 index);
    virtual u32 getCliffId(u32 index);
    virtual bool isSameJoint(int*, int*);
    virtual Vec2f getUpPos(u32 index);
    virtual Vec2f getDownPos(u32 index);
    virtual Vec2f getLeftPos(u32 index);
    virtual Vec2f getRightPos(u32 index);
    virtual Vec2f getCenterPos(u32 index);
    virtual float getWidth(u32 index);
    virtual Vec2f getDownMovementSpeed(u32 index);
    virtual bool getDownCorrectPos(Vec3f*, Vec3f*, u32 index);
    virtual float getDownFriction(u32 index);
    virtual bool isCliffOver(u8, u32 index);
    virtual bool isCliffOverPos(Vec2f* pos, u8, u32 index);
    virtual void initRhombus(u32 index);
    virtual void modifyRhombus(float newRhombusUp, float newRhombusDown, float newRhombusWidth, u32 index);
    virtual void modifyRhombusUp(float newRhombusUp, u32 index);
    virtual void modifyRhombusDown(float newRhombusDown, u32 index);
    virtual void modifyRhombusWidth(float newRhombusWidth, u32 index);
    virtual void modifyRhombusFollowNode(float newRhombusUp, float newRhombusDown, float newRhombusWidth, int newRhombusFollowNode, u32 index);
    virtual void getRhombus(float* outRhombusUp, float* outRhombusDown, float* outRhombusWidth, u32 index);
    virtual void getRhombus(float* outRhombusUp, float* outRhombusDown, float* outRhombusWidth, int* outRhombusFollowNode, u32 index);
    virtual void getRhombus(clRhombus2D* outPrevCollShape, clRhombus2D* outCurrentCollShape, u32 index);
    virtual void calcRhombusModify(float* out1, float* out2, float* out3, float* out4, u32 index);
    virtual void setOffsetX(float offsetX, u32 index);
    virtual void setOffsetY(float offsetY, u32 index);
    virtual void setShapeFlag(u16 flag, bool setFlag, u32 index);
    virtual bool checkShapeFlag(u16 flag, u32 index);
    virtual void setShapeSafePos(Vec2f* safePos, u32 index);
    virtual void setShapeKind(u8 shapeKind, u32 index);
    virtual bool isPassableGround(u32 index);
    virtual void setZ(float Z);
    virtual float getZ();
    virtual bool attachGround(u32 index);
    virtual bool isAttachable(u8, u32 index);
    virtual void attach(u8, u32 index);
    virtual bool isAttach(u32 index);
    virtual void detach(u32 index);
    virtual void setAttackPoint(bool, bool, bool, bool, bool, u32 index);
    virtual void getAttackPointBreak(bool*, bool*, bool*, bool*, u32 index);
    virtual void test(u32 index);
    virtual bool rayCheckTarget(StageObject* stageobject, u8);
    virtual bool rayCheck(Vec3f*, Vec3f*, u8);
    virtual bool rayCheck(Vec3f*, Vec3f*, Vec3f* out1, Vec3f* out2,u8);
    virtual bool rayCheck(Vec3f*, Vec3f*, int* out0, Vec3f* out1, Vec3f* out2, u8);
    virtual float getDistanceFromUnderGrCol(float, Vec3f*, u8);
    virtual grCollision* getGrCollision();
    virtual bool isEnableGrCollision();
    virtual void setGrCollisionMode(bool);
    virtual short getGrCollisionVertexNum();
    virtual void initGrCollisionVertexPos(u16 vtxPosIndex, Vec2f* vertexPo);
    virtual void setGrCollisionVertexPos(u16 vtxPosIndex, Vec2f* vertexPos);
    virtual void setGrCollisionFlagAll(u16, int);
    virtual void setGrCollisionFlagDefaultAll();
    virtual void renderDebug();
    virtual bool isTraced();
    virtual bool canTraceStart(u8, u32, u32 index, float);
    virtual bool startTrace(u8, u32 , u32 index, u8, float, float, float);
    virtual Vec2f getTraceTargetVec(u32 index, float);
    virtual Vec2f getTraceTargetPosturePos(u32 index, float);
    virtual bool isTraceArrived(u32 index, float);
    virtual bool canIntercept(u8 ,u32 , u32 index, float );
    virtual bool renewTrace(u8, u32, u32 index, float, float);
    virtual void endTrace(u32 index);
    virtual Vec2f getTraceGroundMovementSpeed();
    virtual float getTraceDistanceFromLine(u32 index);
    virtual Vec2f getTraceVecFromLine(u32 index);
    virtual bool isSameNormalTraceLineCurrentAndNext(u32);
    virtual bool isOpenTraceLineCurrentAndNext(u32);
    virtual bool isTouchTraceLine(u32 index);
    virtual void updateTrace(bool, u32 index);
    virtual void testGround(u32 index);
    virtual void* getConditionChecker();
    virtual void setIgnoreFriction(bool);
    virtual void setDetachChangeStatus(bool);

    STATIC_CHECK(sizeof(soGroundModule) == 12)
};

class soGroundModuleImpl : public soGroundModule, public soStatusEventObserver, public soAnimCmdEventObserver, public grCollStatusEventReceiver {
    soArray<soGroundShapeImpl>* m_groundShapeArray;
    grCollData* m_collData;
    grCollision* m_collision;
    int m_52;
    u8 m_56;
    char _57[3];
    void* m_cliffHangData;
    float m_cliffBackRangeXMul;
    soGroundTracer* m_groundTracer;
    soGroundConditionChecker* m_groundConditionChecker;
    float m_Z;
    u8 m_80;
    char _81[3];
    soModuleAccesser* m_moduleAccesser;

public:
    virtual ~soGroundModuleImpl();
    virtual void setup(void*, int taskId, bool);
    virtual void clean();
    virtual void constructGrCollision(int, int, Heaps::HeapType, u8, u8, u8);
    virtual void activate(int taskId, Vec2f*);
    virtual void deactivate();
    virtual void relocate(Vec2f*, u32 index);
    virtual void begin();
    virtual void update(u32);
    virtual void processFixPosition();
    virtual float getRotateYForGrCollisionMatrix();
    virtual void updateCheckGrCollision();
    virtual void updateGrCollisionMatrix();
    virtual void pause(u32);
    virtual void apply();
    virtual bool isReferenceModelNode();
    virtual void setCorrect(u8 correct, u32 index);
    virtual u8 getCorrect(u32 index);
    virtual void setCalcLineMove(bool calcLineMove, u32 index);
    virtual void setTargetLineCategory(u8 targetLineCategory, u32 index);
    virtual void setExclusiveLineAttr(short exclusiveLineAttr, u32 index);
    virtual void setPassableCheck(bool passableCheck, u32 index);
    virtual bool isPassableCheck(u32 index);
    virtual void setCloudThrough(bool cloudThrough, u32 index);
    virtual bool isCloudThrough(u32 index);
    virtual bool isCloudThroughOut(Vec2f* out, u32 index);
    virtual void setCorrectIgnoreSlope(u8 correctIgnoreSlope, u32 index);
    virtual void setCliffCheck(u8 cliffCheck, u32 index);
    virtual void setCliffHangData(void*);
    virtual void selectCliffHangData(u32 i,u32 index);
    virtual void setCliffBackRangeXMul(float cliffBackRangeXMul);
    virtual bool isStCliff(u32 index);
    virtual Vec3f getCorrectPos(u32 index);
    virtual void setCliffTeam(u8 cliffTeam, u32 index);
    virtual void entryCliff(u32 index);
    virtual void leaveCliff(u32 index);
    virtual Vec3f getCliffPos(u32 index);
    virtual float getCliffDir(u32 index);
    virtual void setStGroundForce(u32 index);
    virtual void setTestCollStop(bool testCollStop, u32 index);
    virtual void setTestCollStopStatus(bool testCollStop, u32 index);
    virtual void setTestPreMap(bool testPreMap, u32 index);
    virtual void setTestPreMapStatus(bool testPreMap, u32 index);
    virtual void setTestDynamicCollisionStatus(bool testDynamicCollision, u32 index);
    virtual void setTestDynamicCollision(bool testDynamicCollision, u32 index);
    virtual void setEventToGround(bool eventToGround, u32 index);
    virtual void setEventToGroundStatus(bool eventToGround, u32 index);
    virtual grCollStatus* getCollStatus(u32 index);
    virtual bool isOttotto(float, u32 index);
    virtual bool isNearCliff(float, float, u32 index);
    virtual bool isMissStepR(u32 index);
    virtual bool isMissStepL(u32 index);
    virtual bool isTouch(u8, u32 index);
    virtual u8 getTouchCount(u32 index);
    virtual Vec2f getTouchNormal(u8, u32 index);
    virtual Vec2f getTouchSpeed(u8, u32 index);
    virtual Vec2f getAttachMovementSpeed(u32 index);
    virtual Vec2f getAttachNormal(u32 index);
    virtual u8 getTouchFlag(u32 index);
    virtual u8 getTouchMaterialType(u8, u32 index);
    virtual Vec2f getTouchPos(u8, u32 index);
    virtual bool getTouchAttackData(soCollisionAttackData* outAttackData, int* out2, int* out3, u32 index);
    virtual float getTouchLength(u8, u32 index);
    virtual float getTouchLineRate(u8, u32 index);
    virtual bool getTouchNextNormal(bool getNext, Vec2f* outNormal, u8, u32 index);
    virtual void ignoreTouchLine(u8,u32 index);
    virtual bool isDiveDown(u32 index);
    virtual bool isCrush(float, u32 index);
    virtual bool isOnDynamicCollision(u32 index);
    virtual u32 getDownLineId(u32 index);
    virtual u32 getRightLineId(u32 index);
    virtual u32 getLeftLineId(u32 index);
    virtual u32 getUpLineId(u32 index);
    virtual u32 getDownLeftLineId(u32 index);
    virtual u32 getDownRightLineId(u32 index);
    virtual u32 getUpLeftLineId(u32 index);
    virtual u32 getUpRightLineId(u32 index);
    virtual u32 getCliffId(u32 index);
    virtual bool isSameJoint(int*, int*);
    virtual Vec2f getUpPos(u32 index);
    virtual Vec2f getDownPos(u32 index);
    virtual Vec2f getLeftPos(u32 index);
    virtual Vec2f getRightPos(u32 index);
    virtual Vec2f getCenterPos(u32 index);
    virtual float getWidth(u32 index);
    virtual Vec2f getDownMovementSpeed(u32 index);
    virtual bool getDownCorrectPos(Vec3f*, Vec3f*, u32 index);
    virtual float getDownFriction(u32 index);
    virtual bool isCliffOver(u8, u32 index);
    virtual bool isCliffOverPos(Vec2f* pos, u8, u32 index);
    virtual void initRhombus(u32 index);
    virtual void modifyRhombus(float newRhombusUp, float newRhombusDown, float newRhombusWidth, u32 index);
    virtual void modifyRhombusUp(float newRhombusUp, u32 index);
    virtual void modifyRhombusDown(float newRhombusDown, u32 index);
    virtual void modifyRhombusWidth(float newRhombusWidth, u32 index);
    virtual void modifyRhombusFollowNode(float newRhombusUp, float newRhombusDown, float newRhombusWidth, int newRhombusFollowNode, u32 index);
    virtual void getRhombus(float* outRhombusUp, float* outRhombusDown, float* outRhombusWidth, u32 index);
    virtual void getRhombus(float* outRhombusUp, float* outRhombusDown, float* outRhombusWidth, int* outRhombusFollowNode, u32 index);
    virtual void getRhombus(clRhombus2D* outPrevCollShape, clRhombus2D* outCurrentCollShape, u32 index);
    virtual void calcRhombusModify(float* out1, float* out2, float* out3, float* out4, u32 index);
    virtual void setOffsetX(float offsetX, u32 index);
    virtual void setOffsetY(float offsetY, u32 index);
    virtual void setShapeFlag(u16 flag, bool setFlag, u32 index);
    virtual bool checkShapeFlag(u16 flag, u32 index);
    virtual void setShapeSafePos(Vec2f* safePos, u32 index);
    virtual void setShapeKind(u8 shapeKind, u32 index);
    virtual bool isPassableGround(u32 index);
    virtual void setZ(float Z);
    virtual float getZ();
    virtual bool attachGround(u32 index);
    virtual bool isAttachable(u8, u32 index);
    virtual void attach(u8, u32 index);
    virtual bool isAttach(u32 index);
    virtual void detach(u32 index);
    virtual void setAttackPoint(bool, bool, bool, bool, bool, u32 index);
    virtual void getAttackPointBreak(bool*, bool*, bool*, bool*, u32 index);
    virtual void test(u32 index);
    virtual bool rayCheckTarget(StageObject* stageobject, u8);
    virtual bool rayCheck(Vec3f*, Vec3f*, u8);
    virtual bool rayCheck(Vec3f*, Vec3f*, Vec3f* out1, Vec3f* out2,u8);
    virtual bool rayCheck(Vec3f*, Vec3f*, int* out0, Vec3f* out1, Vec3f* out2, u8);
    virtual float getDistanceFromUnderGrCol(float, Vec3f*, u8);
    virtual grCollision* getGrCollision();
    virtual bool isEnableGrCollision();
    virtual void setGrCollisionMode(bool);
    virtual short getGrCollisionVertexNum();
    virtual void initGrCollisionVertexPos(u16 vtxPosIndex, Vec2f* vertexPo);
    virtual void setGrCollisionVertexPos(u16 vtxPosIndex, Vec2f* vertexPos);
    virtual void setGrCollisionFlagAll(u16, int);
    virtual void setGrCollisionFlagDefaultAll();
    virtual void renderDebug();
    virtual bool isTraced();
    virtual bool canTraceStart(u8, u32, u32 index, float);
    virtual bool startTrace(u8, u32 , u32 index, u8, float, float, float);
    virtual Vec2f getTraceTargetVec(u32 index, float);
    virtual Vec2f getTraceTargetPosturePos(u32 index, float);
    virtual bool isTraceArrived(u32 index, float);
    virtual bool canIntercept(u8 ,u32 , u32 index, float );
    virtual bool renewTrace(u8, u32, u32 index, float, float);
    virtual void endTrace(u32 index);
    virtual Vec2f getTraceGroundMovementSpeed();
    virtual float getTraceDistanceFromLine(u32 index);
    virtual Vec2f getTraceVecFromLine(u32 index);
    virtual bool isSameNormalTraceLineCurrentAndNext(u32);
    virtual bool isOpenTraceLineCurrentAndNext(u32);
    virtual bool isTouchTraceLine(u32 index);
    virtual void updateTrace(bool, u32 index);
    virtual void testGround(u32 index);
    virtual void* getConditionChecker();
    virtual void setIgnoreFriction(bool);
    virtual void setDetachChangeStatus(bool);

    virtual void receive(int, bool);
    virtual void notifyEventChangeStatus(int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);

    STATIC_CHECK(sizeof(soGroundModuleImpl) == 88)

};
