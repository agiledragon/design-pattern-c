#include "state-pattern/Client.h"
#include "state-pattern/Water.h"

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

