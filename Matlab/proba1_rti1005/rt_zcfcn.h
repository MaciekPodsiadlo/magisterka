/*
 * rt_zcfcn.h
 *
 * Real-Time Workshop code generation for Simulink model "proba1.mdl".
 *
 * Model Version              : 1.322
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Mar 19 12:01:30 2014
 */

#ifndef RTW_HEADER_rt_zcfcn_h_
#define RTW_HEADER_rt_zcfcn_h_
#include "rtwtypes.h"
#include "solver_zc.h"
# define rt_SET_RZC_SIGSTATE(sig)      ( ((sig) < 0.0) ? NEG_ZCSIG : ((sig) > 0.0 ? POS_ZCSIG : ZERO_ZCSIG) )
#define rt_SET_IZC_SIGSTATE(sig)       ( ((sig) < 0) ? NEG_ZCSIG : ((sig) > 0 ? POS_ZCSIG : ZERO_ZCSIG) )
#define rt_SET_UZC_SIGSTATE(sig)       (((sig) > 0)? POS_ZCSIG : ZERO_ZCSIG)
#define rt_SET_BZC_SIGSTATE(sig)       ((sig)? POS_ZCSIG : ZERO_ZCSIG)
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       ( (ev & zcsDir) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ( ( ( slZcHadEvent(evL,SL_ZCS_EVENT_N2Z) && slZcHadEvent(evR,SL_ZCS_EVENT_Z2P) ) || ( slZcHadEvent(evL,SL_ZCS_EVENT_P2Z) && slZcHadEvent(evR,SL_ZCS_EVENT_Z2N) ) ) ? SL_ZCS_EVENT_NUL : evR )
#endif

extern ZCEventType rt_ZCFcn(ZCDirection direction,
  ZCSigState *prevzc,
  real_T zcSig);

#endif                                 /* RTW_HEADER_rt_zcfcn_h_ */
