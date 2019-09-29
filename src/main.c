#include <stdio.h>
#include <string.h>
#include "state-pattern/Client.h"

void designPatternRun(const char* patternName);

int main(int argc,char* argv[])
{
    designPatternRun(argv[1]);
    return 0;
}

void designPatternRun(const char* patternName)
{
    if (strcmp(patternName, "state-pattern") == 0)
    {
        statePatternRun();
    }
}
