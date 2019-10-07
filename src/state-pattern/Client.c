#include "state-pattern/Client.h"
#include "state-pattern/Water.h"
#include <stdlib.h>

void statePatternRun()
{
    Water* water = waterCreate(25);
    if (water == NULL) return;

    water->behavior(water);
    water->riseTemperature(water, 50);
    water->behavior(water);
    water->reduceTemperature(water, 100);
    water->behavior(water);
    water->riseTemperature(water, 200);
    water->behavior(water);

    waterDestroy(water);
}

