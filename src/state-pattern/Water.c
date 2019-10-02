#include "state-pattern/Water.h"
#include "state-pattern/State.h"
#include "pub/ErrCode.h"
#include <stdio.h>
#include <stdlib.h>


ErrCode waterInit(Water* self, int temperature);
void waterCleanUp(Water* self);
int waterGetTemperature(Water* self);
void waterRiseTemperature(Water* self, int step);
void waterReduceTemperature(Water* self, int step);
void waterChangeState(Water* self);
void waterBehavior(Water* self);

Water* newWater(int temperature)
{
    Water* water = (Water*)malloc(sizeof(Water));
    if (water != NULL)
    {
        ErrCode err = waterInit(water, temperature);
        if (err != ERR_SUCC)
        {
            return NULL;
        }
    }
    return water;
}

void deleteWater(Water* water)
{
    waterCleanUp(water);
    free(water);
}

ErrCode waterInit(Water* self, int temperature)
{
    self->states[0] = newState(SOLID);
    self->states[1] = newState(LIQUID);
    self->states[2] = newState(GASEOUS);
    for (int i = 0; i < MAX_STATE_NUM; i++)
    {
        if (self->states[i] == NULL)
        {
            return ERR_MEM_MALLOC_FAILED;
        }
    }
    self->temperature = temperature;
    waterChangeState(self);
    self->getTemperature = waterGetTemperature;
    self->riseTemperature = waterRiseTemperature;
    self->reduceTemperature = waterReduceTemperature;
    self->changeState = waterChangeState;
    self->behavior = waterBehavior;
    return ERR_SUCC;
}

void waterCleanUp(Water* self)
{
    for (int i = 0; i < MAX_STATE_NUM; i++)
    {
        deleteState(self->states[i]);
        self->states[i] = NULL;
    }
    self->currentState = NULL;
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
    for (int i = 0; i < MAX_STATE_NUM; i++)
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
