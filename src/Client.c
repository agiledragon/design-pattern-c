#include "Client.h"
#include "state-pattern/StatePattern.h"
#include <string.h>

void statePatternRun();

void designPatternRun(const char* patternName)
{
    if (strcmp(patternName, "state-pattern"))
    {
        statePatternRun();
    }
}

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
