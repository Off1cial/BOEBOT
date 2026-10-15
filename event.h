#ifndef EVENT_H
#define EVENT_H


enum event_type_t
{
    EVENT_TURN_RIGHT = 0,
    EVENT_TURN_LEFT,

    EVENT_STOP, // Stop both wheels
    EVENT_FORWARD, // Set both wheels to the same value
    EVENT_BACKWARDS, // Set both wheels to the same value, negative
};

typedef struct event_t
{
    int type;
    union
    {
        struct {
            int duration;
        } turn;

    };
    
} event_t;


#endif
