#ifndef API_FSM_H
#define API_FSM_H

#include <stdint.h>
#include <stdbool.h>
#include "API_common.h"

typedef struct fsm_t fsm_t;

typedef void (*fsm_state_t)(fsm_t *);

struct fsm_t
{
    bool entry;
    bool exit;
    fsm_state_t state;
};

void FSM_init(fsm_t *self, fsm_state_t initialState);
void FSM_tran(fsm_t *self, fsm_state_t nextState);
void FSM_start(fsm_t *self);
void FSM_evaluate(fsm_t *self);

bool_t FSM_isEntry(fsm_t *self);
bool_t FSM_isExit(fsm_t *self);

#endif