#ifndef API_AMBIENT_MONITOR
#define API_AMBIENT_MONITOR

#include "API_common.h"
#include "API_encoder.h"

#define UPDATE_DATA_INTERVAL 15000 /** Time between sensor polling [ms]*/

bool_t  AMB_MON_init();
void    AMB_MON_update(eMovingDir dir, bool_t swPress);

#endif