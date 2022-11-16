#pragma once

#include <types.h>

struct OrthographicParameters {
    float top;
    float bottom;
    float left;
    float right;
};

enum CameraProjection {
    Camera_Projection_Orthogonal = 0x0,
    Camera_Projection_Perspective = 0x1,
};

class gfCamera {
public:
    char _spacer[220];
    float near;
    float far;
    char _spacer2[4];
    OrthographicParameters ortho;
    char _spacer3[8];
    CameraProjection projection;
    char _spacer4[48];
};

class gfCameraManager {
public:
    gfCamera cameras[6];
    char _spacer[8];
    static gfCameraManager* getManager();
};