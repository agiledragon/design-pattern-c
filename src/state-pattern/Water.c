#include "state-pattern/Water.h"
#include "state-pattern/State.h"
#include <stdio.h>

int waterGetTemperature(Water* self);
void waterRiseTemperature(Water* self, int step);
void waterReduceTemperature(Water* self, int step);
void waterChangeState(Water* self);
void waterBehavior(Water* self);

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
