#include "state-pattern/State.h"
#include "state-pattern/Water.h"
#include <stdio.h>

const char* stateGetName(State* state)
{
    return state->name;
}

void solidStateInit(State* self)
{
    SolidState* state = (SolidState*)self;
    state->name = "SolidState";
    state->getName = stateGetName;
    state->match = solidStateMatch;
    state->handle = solidStateHandle;
}

int solidStateMatch(State* self, int temperature)
{
    return temperature < 0;
}

void solidStateHandle(State* self, Water* water)
{
    printf("我性格高冷，当前体温%d摄氏度，我坚如钢铁，仿如一冷血动物，请用我砸人……\n", water->getTemperature(water));
}

void liquidStateInit(State* self)
{
    SolidState* state = (SolidState*)self;
    state->name = "LiquidState";
    state->getName = stateGetName;
    state->match = liquidStateMatch;
    state->handle = liquidStateHandle;
}

int liquidStateMatch(State* self, int temperature)
{
    return temperature >= 0 && temperature < 100;
}

void liquidStateHandle(State* self, Water* water)
{
    printf("我性格温和，当前体温%d摄氏度，我可滋润万物，饮用我可让你活力倍增……\n", water->getTemperature(water));
}

void gaseousStateInit(State* self)
{
    SolidState* state = (SolidState*)self;
    state->name = "GaseousState";
    state->getName = stateGetName;
    state->match = gaseousStateMatch;
    state->handle = gaseousStateHandle;
}

int gaseousStateMatch(State* self, int temperature)
{
    return temperature > 100;
}

void gaseousStateHandle(State* self, Water* water)
{
    printf("我性格热烈，当前体温%d摄氏度，飞向天空是我毕生的梦想，在这你将看不到我的存在，我将达到无我的境界……\n", water->getTemperature(water));
}

