#ifndef HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5
#define HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5

#include "pub/Keywords.h"

struct Water;

typedef struct State
{
    void (*init)(struct State* self);

    ABSTRACT(void (*handle)(struct State* self, struct Water* water));
    ABSTRACT(int (*match)(struct State* self, int temperature));
    const char* (*getName)(struct State* self);

    const char* name;
}State;

#define INHERITED_FROM_STATE \
        void (*init)(struct State* self);\
        OVERRIDE(void (*handle)(struct State* self, struct Water* water));\
        OVERRIDE(int (*match)(struct State* self, int temperature));\
        const char* (*getName)(struct State* self);\
        char* name;

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
int solidStateMatch(State* self, int temperature);
void solidStateHandle(State* self, struct Water* water);
void liquidStateInit(State* self);
int liquidStateMatch(State* self, int temperature);
void liquidStateHandle(State* self, struct Water* water);
void gaseousStateInit(State* self);
int gaseousStateMatch(State* self, int temperature);
void gaseousStateHandle(State* self, struct Water* water);

#endif
