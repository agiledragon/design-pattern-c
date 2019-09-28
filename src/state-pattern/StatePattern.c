#include "state-pattern/StatePattern.h"
#include <stdio.h>

void waterInit(Water* self, int temperature);
int waterGetTemperature(Water* self);
void waterRiseTemperature(Water* self, int step);
void waterReduceTemperature(Water* self, int step);
void waterChangeState(Water* self);
void waterBehavior(Water* self);
char* stateGetName(State* state);
void solidStateInit(State* self);
int solidStateMatch(State* self, int temperature);
void solidStateHandle(State* self, Water* water);
void liquidStateInit(State* self);
int liquidStateMatch(State* self, int temperature);
void liquidStateHandle(State* self, Water* water);
void gaseousStateInit(State* self);
int gaseousStateMatch(State* self, int temperature);
void gaseousStateHandle(State* self, Water* water);


void statePatternRun()
{
    Water water = {waterInit};
    water.init(&water, 25);
    water.behavior(&water);
    water.riseTemperature(&water, 50);
    water.behavior(&water);
    water.reduceTemperature(&water, 100);
    water.behavior(&water);
    water.riseTemperature(&water, 200);
    water.behavior(&water);
}


void waterInit(Water* self, int temperature)
{
    static SolidState solidState = {solidStateInit};
    static LiquidState liquidState = {liquidStateInit};
    static GaseousState gaseousState = {gaseousStateInit};
    solidState.init((State*)&solidState);
    liquidState.init((State*)&liquidState);
    gaseousState.init((State*)&gaseousState);
    self->states[0] = (State*)&solidState;
    self->states[1] = (State*)&liquidState;
    self->states[2] = (State*)&gaseousState;
    self->temperature = temperature;
    waterChangeState(self);
    self->getTemperature = waterGetTemperature;
    self->riseTemperature = waterRiseTemperature;
    self->reduceTemperature = waterReduceTemperature;
    self->changeState = waterChangeState;
    self->behavior = waterBehavior;
}


int waterGetTemperature(Water* self)
{
    return self->temperature;
}

void waterRiseTemperature(Water* self, int step)
{
    self->temperature += step;
    self->changeState(self);
}

void waterReduceTemperature(Water* self, int step)
{
    self->temperature -= step;
    self->changeState(self);
}

void waterChangeState(Water* self)
{
    for (int i = 0; i < sizeof(self->states)/sizeof(self->states[0]); i++)
    {
        if (self->states[i]->match(self->states[i], self->temperature))
        {
            self->currentState = self->states[i];
            return;
        }
    }
}

void waterBehavior(Water* self)
{
    printf("%s: ", self->currentState->getName(self->currentState));
    self->currentState->handle(self->currentState, self);
}

char* stateGetName(State* state)
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
