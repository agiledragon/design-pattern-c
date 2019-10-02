#ifndef HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5
#define HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5

#include "pub/Keyword.h"
#include "pub/BasicType.h"

struct Water;

#define STATE_MEMBER_DECL \
        VIRTUAL(void (*handle)(struct State* self, struct Water* water));\
        VIRTUAL(Boolean (*match)(struct State* self, int temperature));\
        const char* (*getName)(struct State* self);\
        char* name;

typedef struct State
{
    STATE_MEMBER_DECL
}State;

#define INHERITED_FROM_STATE STATE_MEMBER_DECL

typedef struct SolidState
{
    INHERITED_FROM_STATE
}SolidState;

typedef struct LiquidState
{
    INHERITED_FROM_STATE
}LiquidState;

typedef struct GaseousState
{
    INHERITED_FROM_STATE
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
