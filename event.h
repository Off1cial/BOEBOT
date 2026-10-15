#ifndef EVENT_H
#define EVENT_H


typedef enum event_type_t
{
    EVENT_TURN_RIGHT = 0,
    EVENT_TURN_LEFT,

    EVENT_STOP, // Stop both wheels
    EVENT_FORWARD, // Set both wheels to the same value
    EVENT_BACKWARDS, // Set both wheels to the same value, negative
} event_type_t;



typedef struct event_t
{
    event_type_t type;
    union
    {
        struct {
            int duration;
            enum { LEFT, RIGHT } direction;
        } turn;

        struct {
            float fraction; // -1.0f to 1.0f fraction mapped to the servo range
        } move;

    };
    
} event_t;


#endif
