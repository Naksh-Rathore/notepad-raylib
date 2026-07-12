#include "toolbox.h"

#include "raylib.h"

struct ToolBox ToolBox_create(int posX, int posY, int width, int height, float roundness, int curveSegments) {
    struct ToolBox toolbox;

    toolbox.rectangle = (struct Rectangle){ posX, posY, width, height };
    toolbox.curveSegments = curveSegments;
    toolbox.roundness = roundness;

    return toolbox;
}

void ToolBox_draw(const struct ToolBox *self, Color color) {
    DrawRectangleRounded(self->rectangle, self->roundness, self->curveSegments, color);
}

