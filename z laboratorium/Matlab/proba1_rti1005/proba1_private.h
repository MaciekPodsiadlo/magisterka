/*
 * proba1_private.h
 *
 * Real-Time Workshop code generation for Simulink model "proba1.mdl".
 *
 * Model Version              : 1.322
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Mar 19 12:01:30 2014
 */
#ifndef RTW_HEADER_proba1_private_h_
#define RTW_HEADER_proba1_private_h_
#include "rtwtypes.h"
#  include "rtlibsrc.h"
#define CALL_EVENT                     (MAX_uint8_T)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

/* private model entry point functions */
extern void proba1_derivatives(void);
void proba1_jedzdoprzedmiotu_Disable(rtDW_jedzdoprzedmiotu_proba1 *localDW);
void proba1_jedzdoprzedmiotu(uint8_T rtu_0, real_T rtu_1, RT_MODEL_proba1 *rtm,
  rtB_jedzdoprzedmiotu_proba1 *localB, rtDW_jedzdoprzedmiotu_proba1 *localDW,
  rtZCE_jedzdoprzedmiotu_proba1 *localZCE, real_T *rtd_obliczoneDist, real_T
  *rtd_obliczoneFi1, real_T *rtd_obliczoneFi2, real_T *rtd_obliczoneFi3, real_T *
  rtd_tmp_u1, real_T *rtd_tmp_u2, real_T *rtd_tmp_u3, real_T *rtd_tmp_u4, real_T
  *rtd_u1, real_T *rtd_u2, real_T *rtd_u3, real_T *rtd_u4);

#endif                                 /* RTW_HEADER_proba1_private_h_ */
