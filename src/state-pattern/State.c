#include "state-pattern/State.h"
#include "state-pattern/Water.h"
#include <stdio.h>
#include <stdlib.h>

const char* stateGetName(State* state);
void solidStateInit(SolidState* self);
Boolean solidStateMatch(State* self, int temperature);
void solidStateHandle(State* self, struct Water* water);
void liquidStateInit(LiquidState* self);
Boolean liquidStateMatch(State* self, int temperature);
void liquidStateHandle(State* self, struct Water* water);
void gaseousStateInit(GaseousState* self);
Boolean gaseousStateMatch(State* self, int temperature);
void gaseousStateHandle(State* self, struct Water* water);

State* newState(StateIdentifier identifier)
{
    State* state = NULL;
    switch(identifier)
    {
    case SOLID:
        state = (State*)malloc(sizeof(SolidState));
        if (state != NULL)
        {
            solidStateInit((SolidState*)state);
        }
        break;

    case LIQUID:
        state = (State*)malloc(sizeof(LiquidState));
        if (state != NULL)
        {
            liquidStateInit((LiquidState*)state);
        }
        break;

    case GASEOUS:
        state = (State*)malloc(sizeof(GaseousState));
        if (state != NULL)
        {
            gaseousStateInit((GaseousState*)state);
        }
        break;

    default:
        break;
    }

    return state;
}

void deleteState(State* state)
{
    free(state);
}

const char* stateGetName(State* state)
{
    return state->name;
}

void solidStateInit(SolidState* self)
{
    self->base.name = "SolidState";
    self->base.getName = stateGetName;
    self->base.match = solidStateMatch;
    self->base.handle = solidStateHandle;
}

Boolean solidStateMatch(State* self, int temperature)
{
    return temperature < 0;
}

void solidStateHandle(State* self, Water* water)
{
    printf("我性格高冷，当前体温%d摄氏度，我坚如钢铁，仿如一冷血动物，请用我砸人……\n", water->getTemperature(water));
}

void liquidStateInit(LiquidState* self)
{
    self->base.name = "LiquidState";
    self->base.getName = stateGetName;
    self->base.match = liquidStateMatch;
    self->base.handle = liquidStateHandle;
}

Boolean liquidStateMatch(State* self, int temperature)
{
    return temperature >= 0 && temperature < 100;
}

void liquidStateHandle(State* self, Water* water)
{
    printf("我性格温和，当前体温%d摄氏度，我可滋润万物，饮用我可让你活力倍增……\n", water->getTemperature(water));
}

void gaseousStateInit(GaseousState* self)
{
    self->base.name = "GaseousState";
    self->base.getName = stateGetName;
    self->base.match = gaseousStateMatch;
    self->base.handle = gaseousStateHandle;
}

Boolean gaseousStateMatch(State* self, int temperature)
{
    return temperature > 100;
}

void gaseousStateHandle(State* self, Water* water)
{
    printf("我性格热烈，当前体温%d摄氏度，飞向天空是我毕生的梦想，在这你将看不到我的存在，我将达到无我的境界……\n", water->getTemperature(water));
}

