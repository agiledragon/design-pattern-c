#ifndef HE48FCBEB_BF4E_4FDB_A359_5514BD1AA2E7
#define HE48FCBEB_BF4E_4FDB_A359_5514BD1AA2E7

struct Water;

typedef struct State
{
    void (*init)(struct State* self);

    const char* (*getName)(struct State* self);
    int (*match)(struct State* self, int temperature);
    void (*handle)(struct State* self, struct Water* water);

    const char* name;
}State;

#define INHERITED_FROM_STATE \
        void (*init)(struct State* self);\
        const char* (*getName)(struct State* self);\
        int (*match)(struct State* self, int temperature);\
        void (*handle)(struct State* self, struct Water* water);\
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

typedef struct Water
{
    void (*init)(struct Water* self, int temperature);

    int (*getTemperature)(struct Water* self);
    void (*riseTemperature)(struct Water* self, int step);
    void (*reduceTemperature)(struct Water* self, int step);
    void (*behavior)(struct Water* self);

    void (*changeState)(struct Water* self);

    State* states[3];
    int temperature;
    State* currentState;
} Water;

void waterInit(Water* self, int temperature);

#endif
