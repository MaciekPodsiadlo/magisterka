/*********************** dSPACE target specific file *************************

   Include file proba1_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1005 5.6 (16-Nov-2007)
   Fri Jul 04 13:06:39 2014

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "proba1.h"
#include "proba1_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             proba1_B
#define RTP_STRUCTURE_NAME             proba1_P

/* Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_proba1_B_real_T_0 = &proba1_B.Memory;
volatile uint8_T *p_proba1_B_uint8_T_1 = &proba1_B.Compare;
volatile boolean_T *p_proba1_B_boolean_T_2 = &proba1_B.Compare_jd;
volatile real_T *p_proba1_P_real_T_0 = &proba1_P.Memory_X0;
volatile real_T *p_proba1_DWork_real_T_0 = &proba1_DWork.Memory_PreviousInput;
volatile int_T *p_proba1_DWork_int_T_2 = &proba1_DWork.zerowanie_MODE;
volatile real_T *p_proba1_X_real_T_0 = &proba1_X.AnalogButterworthLPFilter_CSTAT;

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <ds3001.h>
#include <ds2201.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE Test-Automation Stimulus Engine */
#define TA_STIMULUS_ENGINE_ENABLE      0

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  {
    ts_timestamp_type ts = { 0, 0 };

    host_service(1, &ts);

#ifdef RTT_ENABLE

    DsDaq_Init(32, 1);

#endif

  }
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1005, (void *) 0,
                        VCM_TXT_RTI1005, 5, 6, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 7, 5, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 7, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 7, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS3001 #1 */
  ds3001_init(DS3001_1_BASE);
  ds3001_set_line_type(DS3001_1_BASE, 5, 1);

  /* dSPACE I/O Board DS2201 #1 */
  ds2201_init(DS2201_1_BASE);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_set_errmode(DS2201_1_BASE, DS2201_GROUP1, DS2201_ZERO);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
  ds2201_set_errmode(DS2201_1_BASE, DS2201_GROUP2, DS2201_ZERO);
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS2201 #1 Unit:BIT_IO */
  ds2201_pin_io_init(DS2201_1_BASE, 0);
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{

#ifdef RTT_ENABLE

  /* DsDaq background call */
  DsDaq_Background();

#endif

}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.001, 0] */
  /* dSPACE I/O Board DS2201 #1 Unit:BIT_IO Group:BIT_IN */
  {
    UInt16 io_in;
    io_in = ds2201_pin_io_in(DS2201_1_BASE);
    proba1_B.SFunction1 = (real_T) ( (io_in & (1 << 0)) > 0 );
    proba1_B.SFunction1_e = (real_T) ( (io_in & (1 << 1)) > 0 );
    proba1_B.SFunction1_o = (real_T) ( (io_in & (1 << 2)) > 0 );
    proba1_B.SFunction1_c = (real_T) ( (io_in & (1 << 3)) > 0 );
    proba1_B.SFunction1_b = (real_T) ( (io_in & (1 << 4)) > 0 );
    proba1_B.SFunction1_i = (real_T) ( (io_in & (1 << 5)) > 0 );
  }

  /* dSPACE I/O Board DS2201 #1 Unit:ADC */
  ds2201_adc_start(DS2201_1_BASE, DS2201_ADC_GR1|DS2201_ADC_GR2|DS2201_ADC_GR3);

  /* dSPACE I/O Board DS3001 #1 Unit:ENC_POS */
  proba1_B.SFunction1_h = (real_T) ds3001_read_position(DS3001_1_BASE, 5);
}

#undef __INLINE

/****** [EOF] ****************************************************************/
