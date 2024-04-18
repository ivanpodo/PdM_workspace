#ifndef API_AMBIENT_MONITOR
#define API_AMBIENT_MONITOR

#include "API_common.h"
#include "API_encoder.h"

#define UPDATE_DATA_INTERVAL 10000 /** Time between data adquisitions [ms]*/

bool_t AMB_MON_Init();
void   AMB_MON_Update(eMovingDir dir, bool_t swPress);

#endif