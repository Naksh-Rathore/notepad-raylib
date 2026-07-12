#pragma once

#include "raylib.h"

struct ToolBox {
    Rectangle rectangle;
    float roundness;
    int curveSegments;

    // Add array of tools when tools are implemented
};

struct ToolBox ToolBox_create(int posX, int posY, int width, int height, float roundness, int curveSegments);

void ToolBox_draw(const struct ToolBox *self, Color color);
