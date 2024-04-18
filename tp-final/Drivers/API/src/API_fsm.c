#include "API_fsm.h"

/**
 * @brief Perform mef initialization without execution
 * 
 * @note Use evaluate to start execution
 * 
 * @param self 
 * @param initialState 
 */
void FSM_init(fsm_t *self, fsm_state_t initialState)
{
    self->entry = true;
    self->exit  = false;
    self->state = initialState;
}

/**
 * @brief Trigger fsm
 * 
 * @param self 
 */
void FSM_start(fsm_t *self)
{
    FSM_evaluate(self);
    self->entry = false;
}

/**
 * @brief Execute current mef state
 * 
 * @param self 
 */
void FSM_evaluate(fsm_t *self)
{
    self->state(self);
}

/**
 * @brief Perform a transition between two states
 * 
 * @param self 
 * @param fx 
 */
void FSM_tran(fsm_t *self, fsm_state_t nextState)
{
    self->exit = true;
    FSM_evaluate(self);          /** Evaluate exit condition of current state */
    self->exit = false;
    self->state = nextState;
    self->entry = true;
    FSM_evaluate(self);          /** Evaluate entry condition of next state */
    self->entry = false;
};

bool_t FSM_isEntry(fsm_t *self)
{
    return self->entry;
}

bool_t FSM_isExit(fsm_t *self)
{
    return self->exit;
}
