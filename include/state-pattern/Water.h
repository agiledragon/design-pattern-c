#ifndef H2876AC91_31AE_428F_84B0_AE0CB9D82D4E
#define H2876AC91_31AE_428F_84B0_AE0CB9D82D4E

#define MAX_STATE_NUM (int)3

struct State;

typedef struct Water
{
    int (*getTemperature)(struct Water* self);
    void (*riseTemperature)(struct Water* self, int step);
    void (*reduceTemperature)(struct Water* self, int step);
    void (*behavior)(struct Water* self);
    void (*changeState)(struct Water* self);
    struct State* states[MAX_STATE_NUM];
    struct State* currentState;
    int temperature;
} Water;

Water* newWater(int temperature);
void deleteWater(Water* water);

#endif
