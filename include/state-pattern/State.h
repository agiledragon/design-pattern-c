#ifndef HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5
#define HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5

#include "pub/Keyword.h"
#include "pub/BasicType.h"

struct Water;

typedef struct State
{
    VIRTUAL(void (*handle)(struct State* self, struct Water* water));
    VIRTUAL(Boolean (*match)(struct State* self, int temperature));
    const char* (*getName)(struct State* self);
    char* name;
}State;


typedef struct SolidState
{
    State base;
}SolidState;

typedef struct LiquidState
{
    State base;
}LiquidState;

typedef struct GaseousState
{
    State base;
}GaseousState;

typedef enum
{
    SOLID,
    LIQUID,
    GASEOUS
}StateIdentifier;

State* newState(StateIdentifier identifier);
void deleteState(State* state);

#endif
