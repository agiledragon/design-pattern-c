#ifndef HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5
#define HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5

#include "pub/Keyword.h"
#include "pub/BasicType.h"

struct Water;

#define STATE_MEMBER_DECL \
        void (*init)(struct State* self);\
        VIRTUAL(void (*handle)(struct State* self, struct Water* water));\
        VIRTUAL(boolean (*match)(struct State* self, int temperature));\
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

const char* stateGetName(State* state);
void solidStateInit(State* self);
boolean solidStateMatch(State* self, int temperature);
void solidStateHandle(State* self, struct Water* water);
void liquidStateInit(State* self);
boolean liquidStateMatch(State* self, int temperature);
void liquidStateHandle(State* self, struct Water* water);
void gaseousStateInit(State* self);
boolean gaseousStateMatch(State* self, int temperature);
void gaseousStateHandle(State* self, struct Water* water);

#endif
