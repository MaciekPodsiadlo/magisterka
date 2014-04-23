/*
 * proba1_data.c
 *
 * Real-Time Workshop code generation for Simulink model "proba1.mdl".
 *
 * Model Version              : 1.322
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Mar 19 12:01:30 2014
 */

#include "proba1.h"
#include "proba1_private.h"

/* Block parameters (auto storage) */
Parameters_proba1 proba1_P = {
  0.0,                                 /* Memory_X0 : '<S26>/Memory'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter_A : '<S27>/Analog Butterworth LP Filter'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter_C : '<S27>/Analog Butterworth LP Filter'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter1_A : '<S28>/Analog Butterworth LP Filter1'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter1_C : '<S28>/Analog Butterworth LP Filter1'
                                        */
  -5000.0,                             /* DeadZone_Start : '<S26>/Dead Zone'
                                        */
  5000.0,                              /* DeadZone_End : '<S26>/Dead Zone'
                                        */
  1.0,                                 /* Saturation_UpperSat : '<S26>/Saturation'
                                        */
  -1.0,                                /* Saturation_LowerSat : '<S26>/Saturation'
                                        */
  0.0,                                 /* przyciskbazowania_Value : '<S3>/przycisk bazowania'
                                        */
  0.0,                                 /* przyciskstopu_Value : '<S3>/przycisk stopu'
                                        */
  0.0,                                 /* Memory_X0_d : '<S30>/Memory'
                                        */

  /*  Logic_table : '<S30>/Logic'
   */
  { 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0 },
  6.2831853071795862E+000,             /* ConversionRotationtoAngle_Gain : '<S26>/Conversion Rotation to Angle'
                                        */
  0.0,                                 /* Memory1_X0 : '<S26>/Memory1'
                                        */
  1.0,                                 /* InitAngle_Threshold : '<S26>/Init Angle'
                                        */
  0.00633,                             /* Gear_Gain : '<S26>/Gear'
                                        */
  5.7295779513082323E+001,             /* ConversionRadtoDeg_Gain : '<S26>/Conversion Rad to Deg'
                                        */
  1.7453292519943295E-002,             /* Gain1_Gain : '<S8>/Gain1'
                                        */
  0.0,                                 /* Memory_X0_e : '<S39>/Memory'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter_A_g : '<S40>/Analog Butterworth LP Filter'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter_C_c : '<S40>/Analog Butterworth LP Filter'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter1_A_k : '<S41>/Analog Butterworth LP Filter1'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter1_C_n : '<S41>/Analog Butterworth LP Filter1'
                                        */
  -5000.0,                             /* DeadZone_Start_i : '<S39>/Dead Zone'
                                        */
  5000.0,                              /* DeadZone_End_l : '<S39>/Dead Zone'
                                        */
  1.0,                                 /* Saturation_UpperSat_g : '<S39>/Saturation'
                                        */
  -1.0,                                /* Saturation_LowerSat_n : '<S39>/Saturation'
                                        */
  0.0,                                 /* Memory_X0_g : '<S43>/Memory'
                                        */

  /*  Logic_table_i : '<S43>/Logic'
   */
  { 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0 },
  6.2831853071795862E+000,             /* ConversionRotationtoAngle_Gai_b : '<S39>/Conversion Rotation to Angle'
                                        */
  0.0,                                 /* Memory1_X0_i : '<S39>/Memory1'
                                        */
  1.0,                                 /* InitAngle_Threshold_j : '<S39>/Init Angle'
                                        */
  0.00637,                             /* Gear_Gain_n : '<S39>/Gear'
                                        */
  5.7295779513082323E+001,             /* ConversionRadtoDeg_Gain_g : '<S39>/Conversion Rad to Deg'
                                        */
  1.7453292519943295E-002,             /* Gain1_Gain_o : '<S9>/Gain1'
                                        */
  0.0,                                 /* Memory_X0_dp : '<S52>/Memory'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter_A_a : '<S53>/Analog Butterworth LP Filter'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter_C_cb : '<S53>/Analog Butterworth LP Filter'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter1_A_o : '<S54>/Analog Butterworth LP Filter1'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter1_C_m : '<S54>/Analog Butterworth LP Filter1'
                                        */
  -5000.0,                             /* DeadZone_Start_ic : '<S52>/Dead Zone'
                                        */
  5000.0,                              /* DeadZone_End_p : '<S52>/Dead Zone'
                                        */
  1.0,                                 /* Saturation_UpperSat_l : '<S52>/Saturation'
                                        */
  -1.0,                                /* Saturation_LowerSat_e : '<S52>/Saturation'
                                        */
  0.0,                                 /* Memory_X0_b : '<S56>/Memory'
                                        */

  /*  Logic_table_e : '<S56>/Logic'
   */
  { 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0 },
  6.2831853071795862E+000,             /* ConversionRotationtoAngle_Ga_bl : '<S52>/Conversion Rotation to Angle'
                                        */
  0.0,                                 /* Memory1_X0_d : '<S52>/Memory1'
                                        */
  1.0,                                 /* InitAngle_Threshold_o : '<S52>/Init Angle'
                                        */
  0.00633,                             /* Gear_Gain_g : '<S52>/Gear'
                                        */
  5.7295779513082323E+001,             /* ConversionRadtoDeg_Gain_o : '<S52>/Conversion Rad to Deg'
                                        */
  1.7453292519943295E-002,             /* Gain1_Gain_p : '<S10>/Gain1'
                                        */
  3.9788735772973838E-001,             /* Gain2_Gain : '<S74>/Gain2'
                                        */
  -0.15,                               /* Constant_Value : '<S14>/Constant'
                                        */
  -160.0,                              /* Constant_Value_i : '<S33>/Constant'
                                        */
  160.0,                               /* Constant_Value_m : '<S32>/Constant'
                                        */
  0.0,                                 /* Constant1_Value : '<S24>/Constant1'
                                        */
  0.5,                                 /* Gain_Gain : '<S14>/Gain'
                                        */
  3.0,                                 /* Saturation_UpperSat_i : '<S14>/Saturation'
                                        */
  -3.0,                                /* Saturation_LowerSat_b : '<S14>/Saturation'
                                        */
  50.0,                                /* predkosc_Value : '<S3>/predkosc'
                                        */
  0.01,                                /* Gain_Gain_d : '<S3>/Gain'
                                        */
  1.0,                                 /* Saturation_UpperSat_e : '<S3>/Saturation'
                                        */
  0.01,                                /* Saturation_LowerSat_bt : '<S3>/Saturation'
                                        */
  -40.0,                               /* Constant_Value_d : '<S46>/Constant'
                                        */
  40.0,                                /* Constant_Value_b : '<S45>/Constant'
                                        */
  0.0,                                 /* Constant1_Value_l : '<S37>/Constant1'
                                        */
  -25.0,                               /* Constant_Value_j : '<S59>/Constant'
                                        */
  40.0,                                /* Constant_Value_e : '<S58>/Constant'
                                        */
  0.0,                                 /* Constant1_Value_i : '<S50>/Constant1'
                                        */
  1.0,                                 /* Saturation_UpperSat_m : '<S20>/Saturation'
                                        */
  0.05,                                /* Saturation_LowerSat_a : '<S20>/Saturation'
                                        */
  50.0,                                /* RateLimiter_RisingLim : '<S14>/Rate Limiter'
                                        */
  -50.0,                               /* RateLimiter_FallingLim : '<S14>/Rate Limiter'
                                        */
  0.1,                                 /* Gain1_Gain_e : '<S14>/Gain1'
                                        */
  -0.15,                               /* Constant_Value_o : '<S15>/Constant'
                                        */
  0.5,                                 /* Gain_Gain_g : '<S15>/Gain'
                                        */
  3.0,                                 /* Saturation_UpperSat_k : '<S15>/Saturation'
                                        */
  -3.0,                                /* Saturation_LowerSat_c : '<S15>/Saturation'
                                        */
  1.0,                                 /* Saturation1_UpperSat : '<S20>/Saturation1'
                                        */
  0.05,                                /* Saturation1_LowerSat : '<S20>/Saturation1'
                                        */
  50.0,                                /* RateLimiter_RisingLim_a : '<S15>/Rate Limiter'
                                        */
  -50.0,                               /* RateLimiter_FallingLim_k : '<S15>/Rate Limiter'
                                        */
  0.1,                                 /* Gain1_Gain_l : '<S15>/Gain1'
                                        */
  -0.15,                               /* Constant_Value_n : '<S16>/Constant'
                                        */
  0.5,                                 /* Gain_Gain_f : '<S16>/Gain'
                                        */
  3.0,                                 /* Saturation_UpperSat_c : '<S16>/Saturation'
                                        */
  -3.0,                                /* Saturation_LowerSat_k : '<S16>/Saturation'
                                        */
  1.0,                                 /* Saturation2_UpperSat : '<S20>/Saturation2'
                                        */
  0.05,                                /* Saturation2_LowerSat : '<S20>/Saturation2'
                                        */
  50.0,                                /* RateLimiter_RisingLim_d : '<S16>/Rate Limiter'
                                        */
  -50.0,                               /* RateLimiter_FallingLim_p : '<S16>/Rate Limiter'
                                        */
  0.1,                                 /* Gain1_Gain_k : '<S16>/Gain1'
                                        */
  0.0,                                 /* Memory_X0_n : '<S62>/Memory'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter_A_c : '<S63>/Analog Butterworth LP Filter'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter_C_b : '<S63>/Analog Butterworth LP Filter'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter1_A_n : '<S64>/Analog Butterworth LP Filter1'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter1_C_b : '<S64>/Analog Butterworth LP Filter1'
                                        */
  -5000.0,                             /* DeadZone_Start_ib : '<S62>/Dead Zone'
                                        */
  5000.0,                              /* DeadZone_End_a : '<S62>/Dead Zone'
                                        */
  1.0,                                 /* Saturation_UpperSat_ma : '<S62>/Saturation'
                                        */
  -1.0,                                /* Saturation_LowerSat_m : '<S62>/Saturation'
                                        */
  1.0,                                 /* Constant1_Value_m : '<S17>/Constant1'
                                        */
  6.2831853071795862E+000,             /* ConversionRotationtoAngle_Gai_c : '<S62>/Conversion Rotation to Angle'
                                        */
  0.0,                                 /* Memory1_X0_e : '<S62>/Memory1'
                                        */
  1.0,                                 /* InitAngle_Threshold_k : '<S62>/Init Angle'
                                        */
  0.00787,                             /* Gear_Gain_nb : '<S62>/Gear'
                                        */
  5.7295779513082323E+001,             /* ConversionRadtoDeg_Gain_l : '<S62>/Conversion Rad to Deg'
                                        */
  0.0,                                 /* Constant_Value_ih : '<S17>/Constant'
                                        */
  0.5,                                 /* Gain_Gain_n : '<S17>/Gain'
                                        */
  3.0,                                 /* Saturation_UpperSat_n : '<S17>/Saturation'
                                        */
  -3.0,                                /* Saturation_LowerSat_j : '<S17>/Saturation'
                                        */
  50.0,                                /* RateLimiter_RisingLim_e : '<S17>/Rate Limiter'
                                        */
  -50.0,                               /* RateLimiter_FallingLim_e : '<S17>/Rate Limiter'
                                        */
  0.1,                                 /* Gain1_Gain_kf : '<S17>/Gain1'
                                        */
  0.0,                                 /* Memory_X0_m : '<S67>/Memory'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter_A_f : '<S68>/Analog Butterworth LP Filter'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter_C_h : '<S68>/Analog Butterworth LP Filter'
                                        */
  -1.0053096491487338E+002,            /* AnalogButterworthLPFilter1_A_c : '<S69>/Analog Butterworth LP Filter1'
                                        */
  1.0053096491487338E+002,             /* AnalogButterworthLPFilter1_C_n5 : '<S69>/Analog Butterworth LP Filter1'
                                        */
  -5000.0,                             /* DeadZone_Start_j : '<S67>/Dead Zone'
                                        */
  5000.0,                              /* DeadZone_End_lg : '<S67>/Dead Zone'
                                        */
  1.0,                                 /* Saturation_UpperSat_na : '<S67>/Saturation'
                                        */
  -1.0,                                /* Saturation_LowerSat_mt : '<S67>/Saturation'
                                        */
  1.0,                                 /* Constant1_Value_p : '<S18>/Constant1'
                                        */
  6.2831853071795862E+000,             /* ConversionRotationtoAngle_Gai_g : '<S67>/Conversion Rotation to Angle'
                                        */
  0.0,                                 /* Memory1_X0_o : '<S67>/Memory1'
                                        */
  1.0,                                 /* InitAngle_Threshold_p : '<S67>/Init Angle'
                                        */
  0.0132,                              /* Gear_Gain_a : '<S67>/Gear'
                                        */
  5.7295779513082323E+001,             /* ConversionRadtoDeg_Gain_go : '<S67>/Conversion Rad to Deg'
                                        */
  0.0,                                 /* Constant_Value_mq : '<S18>/Constant'
                                        */
  0.5,                                 /* Gain_Gain_e : '<S18>/Gain'
                                        */
  3.0,                                 /* Saturation_UpperSat_h : '<S18>/Saturation'
                                        */
  -3.0,                                /* Saturation_LowerSat_eg : '<S18>/Saturation'
                                        */
  50.0,                                /* RateLimiter_RisingLim_g : '<S18>/Rate Limiter'
                                        */
  -50.0,                               /* RateLimiter_FallingLim_h : '<S18>/Rate Limiter'
                                        */
  0.1,                                 /* Gain1_Gain_m : '<S18>/Gain1'
                                        */
  -0.5,                                /* Constant_Value_h : '<S19>/Constant'
                                        */
  0.0,                                 /* Memory_X0_m2 : '<S76>/Memory'
                                        */

  /*  Logic_table_p : '<S76>/Logic'
   */
  { 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0 },
  0.0,                                 /* Constant_Value_f : '<S79>/Constant'
                                        */
  890.0,                               /* Constant_Value_l : '<S78>/Constant'
                                        */
  0.0,                                 /* Constant1_Value_d : '<S73>/Constant1'
                                        */
  0.5,                                 /* Gain_Gain_dw : '<S19>/Gain'
                                        */
  3.0,                                 /* Saturation_UpperSat_mp : '<S19>/Saturation'
                                        */
  -3.0,                                /* Saturation_LowerSat_h : '<S19>/Saturation'
                                        */
  50.0,                                /* RateLimiter_RisingLim_o : '<S19>/Rate Limiter'
                                        */
  -50.0,                               /* RateLimiter_FallingLim_n : '<S19>/Rate Limiter'
                                        */
  0.1,                                 /* Gain1_Gain_n : '<S19>/Gain1'
                                        */
  0.0,                                 /* wybortrybu_Value : '<S4>/wybor trybu'
                                        */
  3.0,                                 /* Constant_Value_a : '<S83>/Constant'
                                        */
  0.0,                                 /* przyciskjedzdoprzedmiotu_Value : '<S4>/przycisk jedz do przedmiotu'
                                        */
  2.0,                                 /* Constant_Value_jk : '<S82>/Constant'
                                        */
  0.0,                                 /* przyciskrozpoznawanieobrazu_Val : '<S4>/przycisk rozpoznawanie obrazu'
                                        */
  0.0,                                 /* Constant_Value_c : '<S80>/Constant'
                                        */
  0.0,                                 /* przyciskwyzwolenia_Value : '<S4>/przycisk wyzwolenia'
                                        */
  1.0,                                 /* Constant_Value_ob : '<S81>/Constant'
                                        */
  0.0,                                 /* DataStoreMemory_InitialValue : '<Root>/Data Store Memory'
                                        */
  0.0,                                 /* obliczoneDist_InitialValue : '<Root>/obliczoneDist'
                                        */
  0.0,                                 /* obliczoneF3_InitialValue : '<Root>/obliczoneF3'
                                        */
  0.0,                                 /* obliczoneFi1_InitialValue : '<Root>/obliczoneFi1'
                                        */
  0.0,                                 /* obliczoneFi2_InitialValue : '<Root>/obliczoneFi2'
                                        */
  0.0,                                 /* obliczoneX_InitialValue : '<Root>/obliczoneX'
                                        */
  0.0,                                 /* obliczoneY_InitialValue : '<Root>/obliczoneY'
                                        */
  0.0,                                 /* obliczoneZ_InitialValue : '<Root>/obliczoneZ'
                                        */
  0.0,                                 /* tmpu1_InitialValue : '<Root>/tmp u1'
                                        */
  0.0,                                 /* tmpu2_InitialValue : '<Root>/tmp u2'
                                        */
  0.0,                                 /* tmpu3_InitialValue : '<Root>/tmp u3'
                                        */
  0.0,                                 /* tmpu4_InitialValue : '<Root>/tmp u4'
                                        */
  0.0,                                 /* u1_InitialValue : '<Root>/u1'
                                        */
  0.0,                                 /* u2_InitialValue : '<Root>/u2'
                                        */
  0.0,                                 /* u3_InitialValue : '<Root>/u3'
                                        */
  0.0,                                 /* u4_InitialValue : '<Root>/u4'
                                        */
  0.0,                                 /* xKon_InitialValue : '<Root>/xKon'
                                        */
  0.0,                                 /* yKon_InitialValue : '<Root>/yKon'
                                        */
  0.0,                                 /* zKon_InitialValue : '<Root>/zKon'
                                        */
  0.0,                                 /* zadaneX_InitialValue : '<Root>/zadaneX'
                                        */
  0.0,                                 /* zadaneY_InitialValue : '<Root>/zadaneY'
                                        */
  0.0,                                 /* zadaneZ_InitialValue : '<Root>/zadaneZ'
                                        */
  0.0,                                 /* Constant_Value_ea : '<S31>/Constant'
                                        */
  0.0,                                 /* Constant_Value_a5 : '<S44>/Constant'
                                        */
  0.0,                                 /* Constant_Value_l1 : '<S57>/Constant'
                                        */
  0.0,                                 /* Constant_Value_hl : '<S77>/Constant'
                                        */
  5.7295779513082323E+001,             /* Gain_Gain_ej : '<S98>/Gain'
                                        */
  5.7295779513082323E+001,             /* Gain_Gain_a : '<S99>/Gain'
                                        */
  5.7295779513082323E+001,             /* Gain_Gain_gh : '<S100>/Gain'
                                        */
  1.2544E+006,                         /* Constant_Value_k : '<S90>/Constant'
                                        */
  -160.0,                              /* Constant_Value_bw : '<S91>/Constant'
                                        */
  160.0,                               /* Constant_Value_g : '<S92>/Constant'
                                        */
  -40.0,                               /* Constant_Value_ky : '<S93>/Constant'
                                        */
  40.0,                                /* Constant_Value_iz : '<S94>/Constant'
                                        */
  -25.0,                               /* Constant_Value_on : '<S95>/Constant'
                                        */
  40.0,                                /* Constant_Value_n1 : '<S96>/Constant'
                                        */
  40.0,                                /* Constant_Value_p : '<S97>/Constant'
                                        */
  212.0,                               /* Constant_Value_gi : '<S86>/Constant'
                                        */
  0.0,                                 /* DelayInput1_X0 : '<S102>/Delay Input1'
                                        */
  0.0,                                 /* DelayInput1_X0_c : '<S103>/Delay Input1'
                                        */
  0.0                                  /* DelayInput1_X0_k : '<S104>/Delay Input1'
                                        */
};
