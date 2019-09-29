#ifndef H2876AC91_31AE_428F_84B0_AE0CB9D82D4E
#define H2876AC91_31AE_428F_84B0_AE0CB9D82D4E

struct State;

typedef struct Water
{
    void (*init)(struct Water* self, int temperature);

    int (*getTemperature)(struct Water* self);
    void (*riseTemperature)(struct Water* self, int step);
    void (*reduceTemperature)(struct Water* self, int step);
    void (*behavior)(struct Water* self);

    void (*changeState)(struct Water* self);

    struct State* states[3];
    int temperature;
    struct State* currentState;
} Water;

void waterInit(Water* self, int temperature);

#endif
