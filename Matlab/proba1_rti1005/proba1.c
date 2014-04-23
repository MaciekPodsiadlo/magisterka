/*
 * proba1.c
 *
 * Real-Time Workshop code generation for Simulink model "proba1.mdl".
 *
 * Model Version              : 1.322
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Mar 19 12:01:30 2014
 */

#include "proba1.h"
#include "proba1_private.h"

/* Block signals (auto storage) */
BlockIO_proba1 proba1_B;

/* Continuous states */
ContinuousStates_proba1 proba1_X;

/* Block states (auto storage) */
D_Work_proba1 proba1_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_proba1 proba1_PrevZCSigState;

/* Real-time model */
RT_MODEL_proba1 proba1_M_;
RT_MODEL_proba1 *proba1_M = &proba1_M_;

/* This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  proba1_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Disable for enable_with_trigger system:
 *   '<S4>/jedz do przedmiotu'
 *   '<S4>/tryb kinematyki odwrotnej'
 */
void proba1_jedzdoprzedmiotu_Disable(rtDW_jedzdoprzedmiotu_proba1 *localDW)
{
  localDW->jedzdoprzedmiotu_MODE = SUBSYS_DISABLED;
}

/* Output and update for enable_with_trigger system:
 *   '<S4>/jedz do przedmiotu'
 *   '<S4>/tryb kinematyki odwrotnej'
 */
void proba1_jedzdoprzedmiotu(uint8_T rtu_0, real_T rtu_1, RT_MODEL_proba1
  *proba1_M, rtB_jedzdoprzedmiotu_proba1 *localB, rtDW_jedzdoprzedmiotu_proba1
  *localDW, rtZCE_jedzdoprzedmiotu_proba1 *localZCE, real_T *rtd_obliczoneDist,
  real_T *rtd_obliczoneFi1, real_T *rtd_obliczoneFi2, real_T *rtd_obliczoneFi3,
  real_T *rtd_tmp_u1, real_T *rtd_tmp_u2, real_T *rtd_tmp_u3, real_T *rtd_tmp_u4,
  real_T *rtd_u1, real_T *rtd_u2, real_T *rtd_u3, real_T *rtd_u4)
{
  if (rtu_0 > 0U) {
    if (localDW->jedzdoprzedmiotu_MODE == SUBSYS_DISABLED) {
      localDW->jedzdoprzedmiotu_MODE = SUBSYS_ENABLED;
    }

    if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
          &localZCE->jedzdoprzedmiotu_Trig_ZCE,
          (rtu_1)) != NO_ZCEVENT)) {
      /* DataStoreRead: '<S84>/Data Store Read' */
      localB->DataStoreRead = (*rtd_obliczoneFi1);

      /* DataStoreWrite: '<S84>/Data Store Write' */
      (*rtd_tmp_u1) = localB->DataStoreRead;

      /* DataStoreWrite: '<S84>/Data Store Write3' */
      (*rtd_u1) = localB->DataStoreRead;

      /* DataStoreRead: '<S84>/Data Store Read1' */
      localB->DataStoreRead1 = (*rtd_obliczoneFi3);

      /* DataStoreWrite: '<S84>/Data Store Write2' */
      (*rtd_tmp_u3) = localB->DataStoreRead1;

      /* DataStoreWrite: '<S84>/Data Store Write5' */
      (*rtd_u3) = localB->DataStoreRead1;

      /* DataStoreRead: '<S84>/Data Store Read2' */
      localB->DataStoreRead2 = (*rtd_obliczoneFi2);

      /* DataStoreWrite: '<S84>/Data Store Write1' */
      (*rtd_tmp_u2) = localB->DataStoreRead2;

      /* DataStoreWrite: '<S84>/Data Store Write4' */
      (*rtd_u2) = localB->DataStoreRead2;

      /* DataStoreRead: '<S84>/Data Store Read3' */
      localB->DataStoreRead3 = (*rtd_obliczoneDist);

      /* DataStoreWrite: '<S84>/Data Store Write6' */
      (*rtd_tmp_u4) = localB->DataStoreRead3;

      /* DataStoreWrite: '<S84>/Data Store Write7' */
      (*rtd_u4) = localB->DataStoreRead3;
    }
  } else if (localDW->jedzdoprzedmiotu_MODE == SUBSYS_ENABLED) {
    proba1_jedzdoprzedmiotu_Disable(localDW);
  }

  localZCE->jedzdoprzedmiotu_Trig_ZCE = rtu_1 < 0.0 ? NEG_ZCSIG : rtu_1 > 0.0 ?
    POS_ZCSIG : ZERO_ZCSIG;
}

/* Model output function */
void proba1_output(int_T tid)
{
  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(proba1_M)) {
    proba1_M->Timing.t[0] = rtsiGetT(&proba1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(proba1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&proba1_M->solverInfo,
                          ((proba1_M->Timing.clockTick0+1)*
      proba1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S26>/Memory' */
      proba1_B.Memory = proba1_DWork.Memory_PreviousInput;
    }

    /* ZeroPole Block: '<S27>/Analog Butterworth LP Filter' */
    {
      proba1_B.AnalogButterworthLPFilter = proba1_P.AnalogButterworthLPFilter_C*
        proba1_X.AnalogButterworthLPFilter_CSTAT;
    }

    /* ZeroPole Block: '<S28>/Analog Butterworth LP Filter1' */
    {
      proba1_B.AnalogButterworthLPFilter1 =
        proba1_P.AnalogButterworthLPFilter1_C*
        proba1_X.AnalogButterworthLPFilter1_CSTA;
    }

    /* Fcn: '<S26>/Atan2' */
    tmp = proba1_B.AnalogButterworthLPFilter;
    tmp_0 = proba1_B.AnalogButterworthLPFilter1;
    proba1_B.Atan2 = rt_atan2(tmp, tmp_0);

    /* Derivative Block: '<S26>/Derivative' */
    {
      real_T t = proba1_M->Timing.t[0];
      real_T timeStampA = proba1_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = proba1_DWork.Derivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        proba1_B.Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &proba1_DWork.Derivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        proba1_B.Derivative = (proba1_B.Atan2 - *lastBank++) / deltaT;
      }
    }

    /* DeadZone Block: '<S26>/Dead Zone'
     */
    if (proba1_B.Derivative >= proba1_P.DeadZone_End) {
      proba1_B.DeadZone = proba1_B.Derivative - proba1_P.DeadZone_End;
    } else if (proba1_B.Derivative > proba1_P.DeadZone_Start) {
      proba1_B.DeadZone = 0.0;
    } else {
      proba1_B.DeadZone = proba1_B.Derivative - proba1_P.DeadZone_Start;
    }

    /* Saturate: '<S26>/Saturation' */
    tmp = proba1_B.DeadZone;
    proba1_B.Saturation = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat,
      proba1_P.Saturation_UpperSat);

    /* Sum: '<S26>/Sum' */
    proba1_B.Sum = proba1_B.Memory - proba1_B.Saturation;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Logic: '<S22>/Logical Operator' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      proba1_B.LogicalOperator = (real_T)((proba1_B.SFunction1 != 0.0) ||
        (proba1_P.przyciskstopu_Value != 0.0));

      /* Memory: '<S30>/Memory' */
      proba1_B.Memory_j = proba1_DWork.Memory_PreviousInput_c;

      /* CombinatorialLogic Block: '<S30>/Logic'
       */
      {
        int_T rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (int_T)(proba1_P.przyciskbazowania_Value != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.LogicalOperator != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.Memory_j != 0.0);

        /* Copy the appropriate row of the table into the block output vector */
        proba1_B.Logic[0] = proba1_P.Logic_table[rowidx];
        proba1_B.Logic[1] = proba1_P.Logic_table[rowidx + 8];
      }
    }

    /* Product: '<S26>/Product' */
    proba1_B.Product = proba1_B.Sum * proba1_B.Logic[1];

    /* Gain: '<S26>/Conversion Rotation to Angle' */
    proba1_B.ConversionRotationtoAngle = proba1_P.ConversionRotationtoAngle_Gain
      * proba1_B.Product;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S26>/Memory1' */
      proba1_B.Memory1 = proba1_DWork.Memory1_PreviousInput;
    }

    /* Switch: '<S26>/Init Angle' */
    if (proba1_B.Logic[1] >= proba1_P.InitAngle_Threshold) {
      proba1_B.InitAngle = proba1_B.Memory1;
    } else {
      proba1_B.InitAngle = proba1_B.Atan2;
    }

    /* Sum: '<S26>/Sum1' */
    proba1_B.Sum1 = (proba1_B.ConversionRotationtoAngle + proba1_B.Atan2) -
      proba1_B.InitAngle;

    /* Gain: '<S26>/Gear' */
    proba1_B.Gear = proba1_P.Gear_Gain * proba1_B.Sum1;

    /* Gain: '<S26>/Conversion Rad to Deg' */
    proba1_B.ConversionRadtoDeg = proba1_P.ConversionRadtoDeg_Gain *
      proba1_B.Gear;

    /* Gain: '<S8>/Gain1' */
    proba1_B.Gain1 = proba1_P.Gain1_Gain * proba1_B.ConversionRadtoDeg;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S39>/Memory' */
      proba1_B.Memory_g = proba1_DWork.Memory_PreviousInput_g;
    }

    /* ZeroPole Block: '<S40>/Analog Butterworth LP Filter' */
    {
      proba1_B.AnalogButterworthLPFilter_a =
        proba1_P.AnalogButterworthLPFilter_C_c*
        proba1_X.AnalogButterworthLPFilter_CST_f;
    }

    /* ZeroPole Block: '<S41>/Analog Butterworth LP Filter1' */
    {
      proba1_B.AnalogButterworthLPFilter1_j =
        proba1_P.AnalogButterworthLPFilter1_C_n*
        proba1_X.AnalogButterworthLPFilter1_CS_c;
    }

    /* Fcn: '<S39>/Atan2' */
    tmp = proba1_B.AnalogButterworthLPFilter_a;
    tmp_0 = proba1_B.AnalogButterworthLPFilter1_j;
    proba1_B.Atan2_i = rt_atan2(tmp, tmp_0);

    /* Derivative Block: '<S39>/Derivative' */
    {
      real_T t = proba1_M->Timing.t[0];
      real_T timeStampA = proba1_DWork.Derivative_RWORK_p.TimeStampA;
      real_T timeStampB = proba1_DWork.Derivative_RWORK_p.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        proba1_B.Derivative_d = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &proba1_DWork.Derivative_RWORK_p.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        proba1_B.Derivative_d = (proba1_B.Atan2_i - *lastBank++) / deltaT;
      }
    }

    /* DeadZone Block: '<S39>/Dead Zone'
     */
    if (proba1_B.Derivative_d >= proba1_P.DeadZone_End_l) {
      proba1_B.DeadZone_l = proba1_B.Derivative_d - proba1_P.DeadZone_End_l;
    } else if (proba1_B.Derivative_d > proba1_P.DeadZone_Start_i) {
      proba1_B.DeadZone_l = 0.0;
    } else {
      proba1_B.DeadZone_l = proba1_B.Derivative_d - proba1_P.DeadZone_Start_i;
    }

    /* Saturate: '<S39>/Saturation' */
    tmp = proba1_B.DeadZone_l;
    proba1_B.Saturation_o = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_n,
      proba1_P.Saturation_UpperSat_g);

    /* Sum: '<S39>/Sum' */
    proba1_B.Sum_j = proba1_B.Memory_g - proba1_B.Saturation_o;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Logic: '<S35>/Logical Operator' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      proba1_B.LogicalOperator_j = (real_T)((proba1_B.SFunction1_e != 0.0) ||
        (proba1_P.przyciskstopu_Value != 0.0));

      /* Memory: '<S43>/Memory' */
      proba1_B.Memory_n = proba1_DWork.Memory_PreviousInput_f;

      /* CombinatorialLogic Block: '<S43>/Logic'
       */
      {
        int_T rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (int_T)(proba1_P.przyciskbazowania_Value != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.LogicalOperator_j != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.Memory_n != 0.0);

        /* Copy the appropriate row of the table into the block output vector */
        proba1_B.Logic_c[0] = proba1_P.Logic_table_i[rowidx];
        proba1_B.Logic_c[1] = proba1_P.Logic_table_i[rowidx + 8];
      }
    }

    /* Product: '<S39>/Product' */
    proba1_B.Product_a = proba1_B.Sum_j * proba1_B.Logic_c[1];

    /* Gain: '<S39>/Conversion Rotation to Angle' */
    proba1_B.ConversionRotationtoAngle_j =
      proba1_P.ConversionRotationtoAngle_Gai_b * proba1_B.Product_a;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S39>/Memory1' */
      proba1_B.Memory1_a = proba1_DWork.Memory1_PreviousInput_g;
    }

    /* Switch: '<S39>/Init Angle' */
    if (proba1_B.Logic_c[1] >= proba1_P.InitAngle_Threshold_j) {
      proba1_B.InitAngle_d = proba1_B.Memory1_a;
    } else {
      proba1_B.InitAngle_d = proba1_B.Atan2_i;
    }

    /* Sum: '<S39>/Sum1' */
    proba1_B.Sum1_n = (proba1_B.ConversionRotationtoAngle_j + proba1_B.Atan2_i)
      - proba1_B.InitAngle_d;

    /* Gain: '<S39>/Gear' */
    proba1_B.Gear_m = proba1_P.Gear_Gain_n * proba1_B.Sum1_n;

    /* Gain: '<S39>/Conversion Rad to Deg' */
    proba1_B.ConversionRadtoDeg_l = proba1_P.ConversionRadtoDeg_Gain_g *
      proba1_B.Gear_m;

    /* Gain: '<S9>/Gain1' */
    proba1_B.Gain1_m = proba1_P.Gain1_Gain_o * proba1_B.ConversionRadtoDeg_l;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S52>/Memory' */
      proba1_B.Memory_e = proba1_DWork.Memory_PreviousInput_b;
    }

    /* ZeroPole Block: '<S53>/Analog Butterworth LP Filter' */
    {
      proba1_B.AnalogButterworthLPFilter_i =
        proba1_P.AnalogButterworthLPFilter_C_cb*
        proba1_X.AnalogButterworthLPFilter_CST_o;
    }

    /* ZeroPole Block: '<S54>/Analog Butterworth LP Filter1' */
    {
      proba1_B.AnalogButterworthLPFilter1_o =
        proba1_P.AnalogButterworthLPFilter1_C_m*
        proba1_X.AnalogButterworthLPFilter1_CS_b;
    }

    /* Fcn: '<S52>/Atan2' */
    tmp = proba1_B.AnalogButterworthLPFilter_i;
    tmp_0 = proba1_B.AnalogButterworthLPFilter1_o;
    proba1_B.Atan2_l = rt_atan2(tmp, tmp_0);

    /* Derivative Block: '<S52>/Derivative' */
    {
      real_T t = proba1_M->Timing.t[0];
      real_T timeStampA = proba1_DWork.Derivative_RWORK_c.TimeStampA;
      real_T timeStampB = proba1_DWork.Derivative_RWORK_c.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        proba1_B.Derivative_a = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &proba1_DWork.Derivative_RWORK_c.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        proba1_B.Derivative_a = (proba1_B.Atan2_l - *lastBank++) / deltaT;
      }
    }

    /* DeadZone Block: '<S52>/Dead Zone'
     */
    if (proba1_B.Derivative_a >= proba1_P.DeadZone_End_p) {
      proba1_B.DeadZone_j = proba1_B.Derivative_a - proba1_P.DeadZone_End_p;
    } else if (proba1_B.Derivative_a > proba1_P.DeadZone_Start_ic) {
      proba1_B.DeadZone_j = 0.0;
    } else {
      proba1_B.DeadZone_j = proba1_B.Derivative_a - proba1_P.DeadZone_Start_ic;
    }

    /* Saturate: '<S52>/Saturation' */
    tmp = proba1_B.DeadZone_j;
    proba1_B.Saturation_e = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_e,
      proba1_P.Saturation_UpperSat_l);

    /* Sum: '<S52>/Sum' */
    proba1_B.Sum_o = proba1_B.Memory_e - proba1_B.Saturation_e;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Logic: '<S48>/Logical Operator' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      proba1_B.LogicalOperator_o = (real_T)((proba1_B.SFunction1_o != 0.0) ||
        (proba1_P.przyciskstopu_Value != 0.0));

      /* Memory: '<S56>/Memory' */
      proba1_B.Memory_f = proba1_DWork.Memory_PreviousInput_m;

      /* CombinatorialLogic Block: '<S56>/Logic'
       */
      {
        int_T rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (int_T)(proba1_P.przyciskbazowania_Value != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.LogicalOperator_o != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.Memory_f != 0.0);

        /* Copy the appropriate row of the table into the block output vector */
        proba1_B.Logic_h[0] = proba1_P.Logic_table_e[rowidx];
        proba1_B.Logic_h[1] = proba1_P.Logic_table_e[rowidx + 8];
      }
    }

    /* Product: '<S52>/Product' */
    proba1_B.Product_o = proba1_B.Sum_o * proba1_B.Logic_h[1];

    /* Gain: '<S52>/Conversion Rotation to Angle' */
    proba1_B.ConversionRotationtoAngle_o =
      proba1_P.ConversionRotationtoAngle_Ga_bl * proba1_B.Product_o;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S52>/Memory1' */
      proba1_B.Memory1_f = proba1_DWork.Memory1_PreviousInput_d;
    }

    /* Switch: '<S52>/Init Angle' */
    if (proba1_B.Logic_h[1] >= proba1_P.InitAngle_Threshold_o) {
      proba1_B.InitAngle_j = proba1_B.Memory1_f;
    } else {
      proba1_B.InitAngle_j = proba1_B.Atan2_l;
    }

    /* Sum: '<S52>/Sum1' */
    proba1_B.Sum1_b = (proba1_B.ConversionRotationtoAngle_o + proba1_B.Atan2_l)
      - proba1_B.InitAngle_j;

    /* Gain: '<S52>/Gear' */
    proba1_B.Gear_g = proba1_P.Gear_Gain_g * proba1_B.Sum1_b;

    /* Gain: '<S52>/Conversion Rad to Deg' */
    proba1_B.ConversionRadtoDeg_n = proba1_P.ConversionRadtoDeg_Gain_o *
      proba1_B.Gear_g;

    /* Gain: '<S10>/Gain1' */
    proba1_B.Gain1_p = proba1_P.Gain1_Gain_p * proba1_B.ConversionRadtoDeg_n;

    /* Fcn: '<S2>/x' */
    tmp = proba1_B.Gain1;
    tmp_0 = proba1_B.Gain1_m;
    tmp_1 = proba1_B.Gain1_p;
    proba1_B.x = (cos(1.570795 - tmp_0) * 450.0 + 670.0 * cos(-tmp_1)) * cos(tmp);

    /* DataStoreWrite: '<S2>/Data Store Write' */
    proba1_DWork.xKon = proba1_B.x;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Fcn: '<S74>/Fcn' */
      proba1_B.Fcn = proba1_B.SFunction1_h * pow(2.0, 23.0) * 3.1415926535897931
        / 1000.0;

      /* Gain: '<S74>/Gain2' */
      proba1_B.Gain2 = proba1_P.Gain2_Gain * proba1_B.Fcn;
    }

    /* Fcn: '<S2>/y' */
    tmp = proba1_B.Gain1;
    tmp_0 = proba1_B.Gain1_m;
    tmp_1 = proba1_B.Gain1_p;
    proba1_B.y = (cos(1.570795 - tmp_0) * 450.0 + 670.0 * cos(-tmp_1)) * sin(tmp);

    /* Sum: '<S2>/Sum' */
    proba1_B.Sum_g = proba1_B.Gain2 + proba1_B.y;

    /* DataStoreWrite: '<S2>/Data Store Write1' */
    proba1_DWork.yKon = proba1_B.Sum_g;

    /* Fcn: '<S2>/z' */
    tmp_0 = proba1_B.Gain1_m;
    tmp_1 = proba1_B.Gain1_p;
    proba1_B.z = (sin(1.570795 - tmp_0) * 450.0 + 670.0 * sin(-tmp_1)) + 700.0;

    /* DataStoreWrite: '<S2>/Data Store Write2' */
    proba1_DWork.zKon = proba1_B.z;

    /* DataStoreRead: '<S14>/Data Store Read' */
    proba1_B.DataStoreRead = proba1_DWork.u1;

    /* RelationalOperator: '<S33>/Compare' incorporates:
     *  Constant: '<S33>/Constant'
     */
    proba1_B.Compare_j = (proba1_B.DataStoreRead >= proba1_P.Constant_Value_i);

    /* RelationalOperator: '<S32>/Compare' incorporates:
     *  Constant: '<S32>/Constant'
     */
    proba1_B.Compare_e = (proba1_B.DataStoreRead <= proba1_P.Constant_Value_m);

    /* Logic: '<S24>/Logical Operator' */
    proba1_B.LogicalOperator_a = (proba1_B.Compare_j && proba1_B.Compare_e);

    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S24>/Constant1'
     */
    if (proba1_B.LogicalOperator_a) {
      proba1_B.Switch = proba1_B.DataStoreRead;
    } else {
      proba1_B.Switch = proba1_P.Constant1_Value;
    }

    /* Sum: '<S14>/Sum' */
    proba1_B.Sum_m = proba1_B.Switch - proba1_B.ConversionRadtoDeg;

    /* Gain: '<S14>/Gain' */
    proba1_B.Gain = proba1_P.Gain_Gain * proba1_B.Sum_m;

    /* Saturate: '<S14>/Saturation' */
    tmp = proba1_B.Gain;
    proba1_B.Saturation_d = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_b,
      proba1_P.Saturation_UpperSat_i);
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S3>/Gain' incorporates:
       *  Constant: '<S3>/predkosc'
       */
      proba1_B.Gain_k = proba1_P.Gain_Gain_d * proba1_P.predkosc_Value;

      /* Saturate: '<S3>/Saturation' */
      tmp = proba1_B.Gain_k;
      proba1_B.Saturation_f = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_bt,
        proba1_P.Saturation_UpperSat_e);
    }

    /* Abs: '<S20>/Abs' */
    proba1_B.Abs = fabs(proba1_B.Sum_m);

    /* DataStoreRead: '<S15>/Data Store Read' */
    proba1_B.DataStoreRead_b = proba1_DWork.u2;

    /* RelationalOperator: '<S46>/Compare' incorporates:
     *  Constant: '<S46>/Constant'
     */
    proba1_B.Compare_m = (proba1_B.DataStoreRead_b >= proba1_P.Constant_Value_d);

    /* RelationalOperator: '<S45>/Compare' incorporates:
     *  Constant: '<S45>/Constant'
     */
    proba1_B.Compare_d = (proba1_B.DataStoreRead_b <= proba1_P.Constant_Value_b);

    /* Logic: '<S37>/Logical Operator' */
    proba1_B.LogicalOperator_ad = (proba1_B.Compare_m && proba1_B.Compare_d);

    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    if (proba1_B.LogicalOperator_ad) {
      proba1_B.Switch_f = proba1_B.DataStoreRead_b;
    } else {
      proba1_B.Switch_f = proba1_P.Constant1_Value_l;
    }

    /* Sum: '<S15>/Sum1' */
    proba1_B.Sum1_h = proba1_B.Switch_f - proba1_B.ConversionRadtoDeg_l;

    /* Abs: '<S20>/Abs1' */
    proba1_B.Abs1 = fabs(proba1_B.Sum1_h);

    /* DataStoreRead: '<S16>/Data Store Read1' */
    proba1_B.DataStoreRead1 = proba1_DWork.u3;

    /* RelationalOperator: '<S59>/Compare' incorporates:
     *  Constant: '<S59>/Constant'
     */
    proba1_B.Compare_pa = (proba1_B.DataStoreRead1 >= proba1_P.Constant_Value_j);

    /* RelationalOperator: '<S58>/Compare' incorporates:
     *  Constant: '<S58>/Constant'
     */
    proba1_B.Compare_c = (proba1_B.DataStoreRead1 <= proba1_P.Constant_Value_e);

    /* Logic: '<S50>/Logical Operator' */
    proba1_B.LogicalOperator_o1 = (proba1_B.Compare_pa && proba1_B.Compare_c);

    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S50>/Constant1'
     */
    if (proba1_B.LogicalOperator_o1) {
      proba1_B.Switch_m = proba1_B.DataStoreRead1;
    } else {
      proba1_B.Switch_m = proba1_P.Constant1_Value_i;
    }

    /* Sum: '<S16>/Sum1' */
    proba1_B.Sum1_m = proba1_B.Switch_m - proba1_B.ConversionRadtoDeg_n;

    /* Abs: '<S20>/Abs2' */
    proba1_B.Abs2 = fabs(proba1_B.Sum1_m);

    /* MinMax: '<S20>/MinMax' */
    tmp = proba1_B.Abs;
    tmp = rt_MAX(tmp, proba1_B.Abs1);
    tmp = rt_MAX(tmp, proba1_B.Abs2);
    proba1_B.MinMax = tmp;

    /* Product: '<S20>/Divide' */
    proba1_B.Divide = proba1_B.Abs / proba1_B.MinMax;

    /* Saturate: '<S20>/Saturation' */
    tmp = proba1_B.Divide;
    proba1_B.Saturation_p = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_a,
      proba1_P.Saturation_UpperSat_m);

    /* Product: '<S14>/Product' */
    proba1_B.Product_f = proba1_B.Saturation_d * proba1_B.Saturation_f *
      proba1_B.Saturation_p;

    /* RateLimiter: '<S14>/Rate Limiter' */
    if (proba1_DWork.LastMajorTime == rtInf) {
      proba1_B.RateLimiter = proba1_B.Product_f;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime;
      tmp_0 = tmp * proba1_P.RateLimiter_RisingLim;
      tmp_1 = proba1_B.Product_f - proba1_DWork.PrevY;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter = proba1_DWork.PrevY + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter_FallingLim;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter = proba1_DWork.PrevY + tmp;
        } else {
          proba1_B.RateLimiter = proba1_B.Product_f;
        }
      }
    }

    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S14>/Constant'
     */
    if (proba1_B.Logic[0] != 0.0) {
      proba1_B.Switch_c = proba1_P.Constant_Value;
    } else {
      proba1_B.Switch_c = proba1_B.RateLimiter;
    }

    /* Gain: '<S14>/Gain1' */
    proba1_B.Gain1_k = proba1_P.Gain1_Gain_e * proba1_B.Switch_c;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
      ds2201_dac_out(DS2201_1_BASE, 1, (dsfloat) proba1_B.Gain1_k);
    }

    /* Gain: '<S15>/Gain' */
    proba1_B.Gain_j = proba1_P.Gain_Gain_g * proba1_B.Sum1_h;

    /* Saturate: '<S15>/Saturation' */
    tmp = proba1_B.Gain_j;
    proba1_B.Saturation_n = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_c,
      proba1_P.Saturation_UpperSat_k);

    /* Product: '<S20>/Divide1' */
    proba1_B.Divide1 = proba1_B.Abs1 / proba1_B.MinMax;

    /* Saturate: '<S20>/Saturation1' */
    tmp = proba1_B.Divide1;
    proba1_B.Saturation1 = rt_SATURATE(tmp, proba1_P.Saturation1_LowerSat,
      proba1_P.Saturation1_UpperSat);

    /* Product: '<S15>/Product' */
    proba1_B.Product_k = proba1_B.Saturation_n * proba1_B.Saturation_f *
      proba1_B.Saturation1;

    /* RateLimiter: '<S15>/Rate Limiter' */
    if (proba1_DWork.LastMajorTime_h == rtInf) {
      proba1_B.RateLimiter_a = proba1_B.Product_k;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_h;
      tmp_0 = tmp * proba1_P.RateLimiter_RisingLim_a;
      tmp_1 = proba1_B.Product_k - proba1_DWork.PrevY_p;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter_a = proba1_DWork.PrevY_p + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter_FallingLim_k;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter_a = proba1_DWork.PrevY_p + tmp;
        } else {
          proba1_B.RateLimiter_a = proba1_B.Product_k;
        }
      }
    }

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     */
    if (proba1_B.Logic_c[0] != 0.0) {
      proba1_B.Switch_b = proba1_P.Constant_Value_o;
    } else {
      proba1_B.Switch_b = proba1_B.RateLimiter_a;
    }

    /* Gain: '<S15>/Gain1' */
    proba1_B.Gain1_e = proba1_P.Gain1_Gain_l * proba1_B.Switch_b;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
      ds2201_dac_out(DS2201_1_BASE, 2, (dsfloat) proba1_B.Gain1_e);
    }

    /* Gain: '<S16>/Gain' */
    proba1_B.Gain_e = proba1_P.Gain_Gain_f * proba1_B.Sum1_m;

    /* Saturate: '<S16>/Saturation' */
    tmp = proba1_B.Gain_e;
    proba1_B.Saturation_b = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_k,
      proba1_P.Saturation_UpperSat_c);

    /* Product: '<S20>/Divide2' */
    proba1_B.Divide2 = proba1_B.Abs2 / proba1_B.MinMax;

    /* Saturate: '<S20>/Saturation2' */
    tmp = proba1_B.Divide2;
    proba1_B.Saturation2 = rt_SATURATE(tmp, proba1_P.Saturation2_LowerSat,
      proba1_P.Saturation2_UpperSat);

    /* Product: '<S16>/Product' */
    proba1_B.Product_a0 = proba1_B.Saturation_b * proba1_B.Saturation_f *
      proba1_B.Saturation2;

    /* RateLimiter: '<S16>/Rate Limiter' */
    if (proba1_DWork.LastMajorTime_hr == rtInf) {
      proba1_B.RateLimiter_m = proba1_B.Product_a0;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_hr;
      tmp_0 = tmp * proba1_P.RateLimiter_RisingLim_d;
      tmp_1 = proba1_B.Product_a0 - proba1_DWork.PrevY_e;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter_m = proba1_DWork.PrevY_e + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter_FallingLim_p;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter_m = proba1_DWork.PrevY_e + tmp;
        } else {
          proba1_B.RateLimiter_m = proba1_B.Product_a0;
        }
      }
    }

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant'
     */
    if (proba1_B.Logic_h[0] != 0.0) {
      proba1_B.Switch_p = proba1_P.Constant_Value_n;
    } else {
      proba1_B.Switch_p = proba1_B.RateLimiter_m;
    }

    /* Gain: '<S16>/Gain1' */
    proba1_B.Gain1_i = proba1_P.Gain1_Gain_k * proba1_B.Switch_p;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
      ds2201_dac_out(DS2201_1_BASE, 3, (dsfloat) proba1_B.Gain1_i);

      /* Memory: '<S62>/Memory' */
      proba1_B.Memory_gz = proba1_DWork.Memory_PreviousInput_e;
    }

    /* ZeroPole Block: '<S63>/Analog Butterworth LP Filter' */
    {
      proba1_B.AnalogButterworthLPFilter_k =
        proba1_P.AnalogButterworthLPFilter_C_b*
        proba1_X.AnalogButterworthLPFilter_CS_oj;
    }

    /* ZeroPole Block: '<S64>/Analog Butterworth LP Filter1' */
    {
      proba1_B.AnalogButterworthLPFilter1_c =
        proba1_P.AnalogButterworthLPFilter1_C_b*
        proba1_X.AnalogButterworthLPFilter1_CS_j;
    }

    /* Fcn: '<S62>/Atan2' */
    tmp = proba1_B.AnalogButterworthLPFilter_k;
    tmp_0 = proba1_B.AnalogButterworthLPFilter1_c;
    proba1_B.Atan2_b = rt_atan2(tmp, tmp_0);

    /* Derivative Block: '<S62>/Derivative' */
    {
      real_T t = proba1_M->Timing.t[0];
      real_T timeStampA = proba1_DWork.Derivative_RWORK_k.TimeStampA;
      real_T timeStampB = proba1_DWork.Derivative_RWORK_k.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        proba1_B.Derivative_f = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &proba1_DWork.Derivative_RWORK_k.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        proba1_B.Derivative_f = (proba1_B.Atan2_b - *lastBank++) / deltaT;
      }
    }

    /* DeadZone Block: '<S62>/Dead Zone'
     */
    if (proba1_B.Derivative_f >= proba1_P.DeadZone_End_a) {
      proba1_B.DeadZone_n = proba1_B.Derivative_f - proba1_P.DeadZone_End_a;
    } else if (proba1_B.Derivative_f > proba1_P.DeadZone_Start_ib) {
      proba1_B.DeadZone_n = 0.0;
    } else {
      proba1_B.DeadZone_n = proba1_B.Derivative_f - proba1_P.DeadZone_Start_ib;
    }

    /* Saturate: '<S62>/Saturation' */
    tmp = proba1_B.DeadZone_n;
    proba1_B.Saturation_c = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_m,
      proba1_P.Saturation_UpperSat_ma);

    /* Sum: '<S62>/Sum' */
    proba1_B.Sum_c = proba1_B.Memory_gz - proba1_B.Saturation_c;

    /* Product: '<S62>/Product' incorporates:
     *  Constant: '<S17>/Constant1'
     */
    proba1_B.Product_n = proba1_B.Sum_c * proba1_P.Constant1_Value_m;

    /* Gain: '<S62>/Conversion Rotation to Angle' */
    proba1_B.ConversionRotationtoAngle_g =
      proba1_P.ConversionRotationtoAngle_Gai_c * proba1_B.Product_n;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S62>/Memory1' */
      proba1_B.Memory1_k = proba1_DWork.Memory1_PreviousInput_j;
    }

    /* Switch: '<S62>/Init Angle' incorporates:
     *  Constant: '<S17>/Constant1'
     */
    if (proba1_P.Constant1_Value_m >= proba1_P.InitAngle_Threshold_k) {
      proba1_B.InitAngle_a = proba1_B.Memory1_k;
    } else {
      proba1_B.InitAngle_a = proba1_B.Atan2_b;
    }

    /* Sum: '<S62>/Sum1' */
    proba1_B.Sum1_d = (proba1_B.ConversionRotationtoAngle_g + proba1_B.Atan2_b)
      - proba1_B.InitAngle_a;

    /* Gain: '<S62>/Gear' */
    proba1_B.Gear_k = proba1_P.Gear_Gain_nb * proba1_B.Sum1_d;

    /* Gain: '<S62>/Conversion Rad to Deg' */
    proba1_B.ConversionRadtoDeg_j = proba1_P.ConversionRadtoDeg_Gain_l *
      proba1_B.Gear_k;

    /* Sum: '<S17>/Sum' incorporates:
     *  Constant: '<S17>/Constant'
     */
    proba1_B.Sum_gv = proba1_P.Constant_Value_ih - proba1_B.ConversionRadtoDeg_j;

    /* Gain: '<S17>/Gain' */
    proba1_B.Gain_m = proba1_P.Gain_Gain_n * proba1_B.Sum_gv;

    /* Saturate: '<S17>/Saturation' */
    tmp = proba1_B.Gain_m;
    proba1_B.Saturation_m = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_j,
      proba1_P.Saturation_UpperSat_n);

    /* RateLimiter: '<S17>/Rate Limiter' */
    if (proba1_DWork.LastMajorTime_hz == rtInf) {
      proba1_B.RateLimiter_d = proba1_B.Saturation_m;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_hz;
      tmp_0 = tmp * proba1_P.RateLimiter_RisingLim_e;
      tmp_1 = proba1_B.Saturation_m - proba1_DWork.PrevY_l;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter_d = proba1_DWork.PrevY_l + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter_FallingLim_e;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter_d = proba1_DWork.PrevY_l + tmp;
        } else {
          proba1_B.RateLimiter_d = proba1_B.Saturation_m;
        }
      }
    }

    /* Gain: '<S17>/Gain1' */
    proba1_B.Gain1_c = proba1_P.Gain1_Gain_kf * proba1_B.RateLimiter_d;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
      ds2201_dac_out(DS2201_1_BASE, 4, (dsfloat) proba1_B.Gain1_c);

      /* Memory: '<S67>/Memory' */
      proba1_B.Memory_j5 = proba1_DWork.Memory_PreviousInput_h;
    }

    /* ZeroPole Block: '<S68>/Analog Butterworth LP Filter' */
    {
      proba1_B.AnalogButterworthLPFilter_c =
        proba1_P.AnalogButterworthLPFilter_C_h*
        proba1_X.AnalogButterworthLPFilter_CST_c;
    }

    /* ZeroPole Block: '<S69>/Analog Butterworth LP Filter1' */
    {
      proba1_B.AnalogButterworthLPFilter1_n =
        proba1_P.AnalogButterworthLPFilter1_C_n5*
        proba1_X.AnalogButterworthLPFilter1_C_je;
    }

    /* Fcn: '<S67>/Atan2' */
    tmp = proba1_B.AnalogButterworthLPFilter_c;
    tmp_0 = proba1_B.AnalogButterworthLPFilter1_n;
    proba1_B.Atan2_j = rt_atan2(tmp, tmp_0);

    /* Derivative Block: '<S67>/Derivative' */
    {
      real_T t = proba1_M->Timing.t[0];
      real_T timeStampA = proba1_DWork.Derivative_RWORK_m.TimeStampA;
      real_T timeStampB = proba1_DWork.Derivative_RWORK_m.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        proba1_B.Derivative_g = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &proba1_DWork.Derivative_RWORK_m.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        proba1_B.Derivative_g = (proba1_B.Atan2_j - *lastBank++) / deltaT;
      }
    }

    /* DeadZone Block: '<S67>/Dead Zone'
     */
    if (proba1_B.Derivative_g >= proba1_P.DeadZone_End_lg) {
      proba1_B.DeadZone_o = proba1_B.Derivative_g - proba1_P.DeadZone_End_lg;
    } else if (proba1_B.Derivative_g > proba1_P.DeadZone_Start_j) {
      proba1_B.DeadZone_o = 0.0;
    } else {
      proba1_B.DeadZone_o = proba1_B.Derivative_g - proba1_P.DeadZone_Start_j;
    }

    /* Saturate: '<S67>/Saturation' */
    tmp = proba1_B.DeadZone_o;
    proba1_B.Saturation_a = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_mt,
      proba1_P.Saturation_UpperSat_na);

    /* Sum: '<S67>/Sum' */
    proba1_B.Sum_mv = proba1_B.Memory_j5 - proba1_B.Saturation_a;

    /* Product: '<S67>/Product' incorporates:
     *  Constant: '<S18>/Constant1'
     */
    proba1_B.Product_o5 = proba1_B.Sum_mv * proba1_P.Constant1_Value_p;

    /* Gain: '<S67>/Conversion Rotation to Angle' */
    proba1_B.ConversionRotationtoAngle_e =
      proba1_P.ConversionRotationtoAngle_Gai_g * proba1_B.Product_o5;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S67>/Memory1' */
      proba1_B.Memory1_fx = proba1_DWork.Memory1_PreviousInput_n;
    }

    /* Switch: '<S67>/Init Angle' incorporates:
     *  Constant: '<S18>/Constant1'
     */
    if (proba1_P.Constant1_Value_p >= proba1_P.InitAngle_Threshold_p) {
      proba1_B.InitAngle_f = proba1_B.Memory1_fx;
    } else {
      proba1_B.InitAngle_f = proba1_B.Atan2_j;
    }

    /* Sum: '<S67>/Sum1' */
    proba1_B.Sum1_f = (proba1_B.ConversionRotationtoAngle_e + proba1_B.Atan2_j)
      - proba1_B.InitAngle_f;

    /* Gain: '<S67>/Gear' */
    proba1_B.Gear_l = proba1_P.Gear_Gain_a * proba1_B.Sum1_f;

    /* Gain: '<S67>/Conversion Rad to Deg' */
    proba1_B.ConversionRadtoDeg_h = proba1_P.ConversionRadtoDeg_Gain_go *
      proba1_B.Gear_l;

    /* Sum: '<S18>/Sum' incorporates:
     *  Constant: '<S18>/Constant'
     */
    proba1_B.Sum_f = proba1_P.Constant_Value_mq - proba1_B.ConversionRadtoDeg_h;

    /* Gain: '<S18>/Gain' */
    proba1_B.Gain_ev = proba1_P.Gain_Gain_e * proba1_B.Sum_f;

    /* Saturate: '<S18>/Saturation' */
    tmp = proba1_B.Gain_ev;
    proba1_B.Saturation_g = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_eg,
      proba1_P.Saturation_UpperSat_h);

    /* RateLimiter: '<S18>/Rate Limiter' */
    if (proba1_DWork.LastMajorTime_a == rtInf) {
      proba1_B.RateLimiter_j = proba1_B.Saturation_g;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_a;
      tmp_0 = tmp * proba1_P.RateLimiter_RisingLim_g;
      tmp_1 = proba1_B.Saturation_g - proba1_DWork.PrevY_k;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter_j = proba1_DWork.PrevY_k + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter_FallingLim_h;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter_j = proba1_DWork.PrevY_k + tmp;
        } else {
          proba1_B.RateLimiter_j = proba1_B.Saturation_g;
        }
      }
    }

    /* Gain: '<S18>/Gain1' */
    proba1_B.Gain1_ps = proba1_P.Gain1_Gain_m * proba1_B.RateLimiter_j;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
      ds2201_dac_out(DS2201_1_BASE, 5, (dsfloat) proba1_B.Gain1_ps);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Logic: '<S71>/Logical Operator' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      proba1_B.LogicalOperator_n = (real_T)((proba1_B.SFunction1_i != 0.0) ||
        (proba1_P.przyciskstopu_Value != 0.0));

      /* Memory: '<S76>/Memory' */
      proba1_B.Memory_jn = proba1_DWork.Memory_PreviousInput_k;

      /* CombinatorialLogic Block: '<S76>/Logic'
       */
      {
        int_T rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (int_T)(proba1_P.przyciskbazowania_Value != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.LogicalOperator_n != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.Memory_jn != 0.0);

        /* Copy the appropriate row of the table into the block output vector */
        proba1_B.Logic_he[0] = proba1_P.Logic_table_p[rowidx];
        proba1_B.Logic_he[1] = proba1_P.Logic_table_p[rowidx + 8];
      }
    }

    /* DataStoreRead: '<S19>/Data Store Read1' */
    proba1_B.DataStoreRead1_m = proba1_DWork.u4;

    /* RelationalOperator: '<S79>/Compare' incorporates:
     *  Constant: '<S79>/Constant'
     */
    proba1_B.Compare_h = (proba1_B.DataStoreRead1_m >= proba1_P.Constant_Value_f);

    /* RelationalOperator: '<S78>/Compare' incorporates:
     *  Constant: '<S78>/Constant'
     */
    proba1_B.Compare_gk = (proba1_B.DataStoreRead1_m <=
      proba1_P.Constant_Value_l);

    /* Logic: '<S73>/Logical Operator' */
    proba1_B.LogicalOperator_oc = (proba1_B.Compare_h && proba1_B.Compare_gk);

    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S73>/Constant1'
     */
    if (proba1_B.LogicalOperator_oc) {
      proba1_B.Switch_h = proba1_B.DataStoreRead1_m;
    } else {
      proba1_B.Switch_h = proba1_P.Constant1_Value_d;
    }

    /* Sum: '<S19>/Sum1' */
    proba1_B.Sum1_d2 = proba1_B.Switch_h - proba1_B.Gain2;

    /* Gain: '<S19>/Gain' */
    proba1_B.Gain_c = proba1_P.Gain_Gain_dw * proba1_B.Sum1_d2;

    /* Saturate: '<S19>/Saturation' */
    tmp = proba1_B.Gain_c;
    proba1_B.Saturation_i = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_h,
      proba1_P.Saturation_UpperSat_mp);

    /* Product: '<S19>/Product' */
    proba1_B.Product_e = proba1_B.Saturation_i * proba1_B.Saturation_f;

    /* RateLimiter: '<S19>/Rate Limiter' */
    if (proba1_DWork.LastMajorTime_d == rtInf) {
      proba1_B.RateLimiter_p = proba1_B.Product_e;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_d;
      tmp_0 = tmp * proba1_P.RateLimiter_RisingLim_o;
      tmp_1 = proba1_B.Product_e - proba1_DWork.PrevY_g;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter_p = proba1_DWork.PrevY_g + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter_FallingLim_n;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter_p = proba1_DWork.PrevY_g + tmp;
        } else {
          proba1_B.RateLimiter_p = proba1_B.Product_e;
        }
      }
    }

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/Constant'
     */
    if (proba1_B.Logic_he[0] != 0.0) {
      proba1_B.Switch_hv = proba1_P.Constant_Value_h;
    } else {
      proba1_B.Switch_hv = proba1_B.RateLimiter_p;
    }

    /* Gain: '<S19>/Gain1' */
    proba1_B.Gain1_h = proba1_P.Gain1_Gain_n * proba1_B.Switch_hv;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
      ds2201_dac_out(DS2201_1_BASE, 8, (dsfloat) proba1_B.Gain1_h);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:ADC Group:GROUP1 */
      proba1_B.SFunction1_j[0] = (real_T)ds2201_adc_in(DS2201_1_BASE, 1);
      proba1_B.SFunction1_j[1] = (real_T)ds2201_adc_in(DS2201_1_BASE, 2);
      proba1_B.SFunction1_j[2] = (real_T)ds2201_adc_in(DS2201_1_BASE, 3);
      proba1_B.SFunction1_j[3] = (real_T)ds2201_adc_in(DS2201_1_BASE, 4);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:ADC Group:GROUP2 */
      proba1_B.SFunction2[0] = (real_T)ds2201_adc_in(DS2201_1_BASE, 5);
      proba1_B.SFunction2[1] = (real_T)ds2201_adc_in(DS2201_1_BASE, 6);
      proba1_B.SFunction2[2] = (real_T)ds2201_adc_in(DS2201_1_BASE, 7);
      proba1_B.SFunction2[3] = (real_T)ds2201_adc_in(DS2201_1_BASE, 8);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:ADC Group:GROUP3 */
      proba1_B.SFunction3[0] = (real_T)ds2201_adc_in(DS2201_1_BASE, 9);
      proba1_B.SFunction3[1] = (real_T)ds2201_adc_in(DS2201_1_BASE, 10);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Outputs for trigger SubSystem: '<S14>/blok stopu' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
            &proba1_PrevZCSigState.blokstopu_Trig_ZCE_f,
            (proba1_P.przyciskstopu_Value)) != NO_ZCEVENT)) {
        /* DataStoreWrite: '<S23>/Data Store Write' */
        proba1_DWork.u1 = proba1_B.ConversionRadtoDeg;

        /* DataStoreWrite: '<S23>/Data Store Write1' */
        proba1_DWork.tmp_u1 = proba1_B.ConversionRadtoDeg;
      }

      /* end of Outputs for SubSystem: '<S14>/blok stopu' */

      /* Outputs for enable SubSystem: '<S22>/zerowanie' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Logic[0] > 0.0) {
            if (proba1_DWork.zerowanie_MODE == SUBSYS_DISABLED) {
              proba1_DWork.zerowanie_MODE = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.zerowanie_MODE == SUBSYS_ENABLED) {
            proba1_DWork.zerowanie_MODE = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.zerowanie_MODE == SUBSYS_ENABLED) {
          /* DataStoreWrite: '<S31>/Data Store Write' incorporates:
           *  Constant: '<S31>/Constant'
           */
          proba1_DWork.u1 = proba1_P.Constant_Value_ea;

          /* DataStoreWrite: '<S31>/Data Store Write1' incorporates:
           *  Constant: '<S31>/Constant'
           */
          proba1_DWork.tmp_u1 = proba1_P.Constant_Value_ea;
        }
      }

      /* end of Outputs for SubSystem: '<S22>/zerowanie' */

      /* Outputs for trigger SubSystem: '<S15>/blok stopu' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
            &proba1_PrevZCSigState.blokstopu_Trig_ZCE_p,
            (proba1_P.przyciskstopu_Value)) != NO_ZCEVENT)) {
        /* DataStoreWrite: '<S36>/Data Store Write' */
        proba1_DWork.u2 = proba1_B.ConversionRadtoDeg_l;

        /* DataStoreWrite: '<S36>/Data Store Write1' */
        proba1_DWork.tmp_u2 = proba1_B.ConversionRadtoDeg_l;
      }

      /* end of Outputs for SubSystem: '<S15>/blok stopu' */

      /* Outputs for enable SubSystem: '<S35>/zerowanie' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Logic_c[0] > 0.0) {
            if (proba1_DWork.zerowanie_MODE_l == SUBSYS_DISABLED) {
              proba1_DWork.zerowanie_MODE_l = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.zerowanie_MODE_l == SUBSYS_ENABLED) {
            proba1_DWork.zerowanie_MODE_l = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.zerowanie_MODE_l == SUBSYS_ENABLED) {
          /* DataStoreWrite: '<S44>/Data Store Write' incorporates:
           *  Constant: '<S44>/Constant'
           */
          proba1_DWork.u2 = proba1_P.Constant_Value_a5;

          /* DataStoreWrite: '<S44>/Data Store Write1' incorporates:
           *  Constant: '<S44>/Constant'
           */
          proba1_DWork.tmp_u2 = proba1_P.Constant_Value_a5;
        }
      }

      /* end of Outputs for SubSystem: '<S35>/zerowanie' */

      /* Outputs for trigger SubSystem: '<S16>/blok stopu' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
            &proba1_PrevZCSigState.blokstopu_Trig_ZCE_b,
            (proba1_P.przyciskstopu_Value)) != NO_ZCEVENT)) {
        /* DataStoreWrite: '<S49>/Data Store Write' */
        proba1_DWork.u3 = proba1_B.ConversionRadtoDeg_n;

        /* DataStoreWrite: '<S49>/Data Store Write1' */
        proba1_DWork.tmp_u3 = proba1_B.ConversionRadtoDeg_n;
      }

      /* end of Outputs for SubSystem: '<S16>/blok stopu' */

      /* Outputs for enable SubSystem: '<S48>/zerowanie' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Logic_h[0] > 0.0) {
            if (proba1_DWork.zerowanie_MODE_k == SUBSYS_DISABLED) {
              proba1_DWork.zerowanie_MODE_k = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.zerowanie_MODE_k == SUBSYS_ENABLED) {
            proba1_DWork.zerowanie_MODE_k = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.zerowanie_MODE_k == SUBSYS_ENABLED) {
          /* DataStoreWrite: '<S57>/Data Store Write' incorporates:
           *  Constant: '<S57>/Constant'
           */
          proba1_DWork.u3 = proba1_P.Constant_Value_l1;

          /* DataStoreWrite: '<S57>/Data Store Write1' incorporates:
           *  Constant: '<S57>/Constant'
           */
          proba1_DWork.tmp_u3 = proba1_P.Constant_Value_l1;
        }
      }

      /* end of Outputs for SubSystem: '<S48>/zerowanie' */

      /* Outputs for trigger SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */
      if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
            &proba1_PrevZCSigState.DS3001ENC_RESET_B1_C1_Trig_ZCE,
            (proba1_B.Logic_he[1])) != NO_ZCEVENT)) {
        /* This comment workarounds a Real-Time Workshop code generation problem */

        /* dSPACE I/O Board DS3001 #1 Unit:ENC_RESET */
        ds3001_clear_counter(DS3001_1_BASE, 1);
      }

      /* end of Outputs for SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */

      /* Outputs for trigger SubSystem: '<S19>/blok stopu' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
            &proba1_PrevZCSigState.blokstopu_Trig_ZCE,
            (proba1_P.przyciskstopu_Value)) != NO_ZCEVENT)) {
        /* DataStoreWrite: '<S72>/Data Store Write' */
        proba1_DWork.u4 = proba1_B.Gain2;

        /* DataStoreWrite: '<S72>/Data Store Write1' */
        proba1_DWork.tmp_u4 = proba1_B.Gain2;
      }

      /* end of Outputs for SubSystem: '<S19>/blok stopu' */

      /* Outputs for enable SubSystem: '<S71>/zerowanie' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Logic_he[0] > 0.0) {
            if (proba1_DWork.zerowanie_MODE_e == SUBSYS_DISABLED) {
              proba1_DWork.zerowanie_MODE_e = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.zerowanie_MODE_e == SUBSYS_ENABLED) {
            proba1_DWork.zerowanie_MODE_e = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.zerowanie_MODE_e == SUBSYS_ENABLED) {
          /* DataStoreWrite: '<S77>/Data Store Write' incorporates:
           *  Constant: '<S77>/Constant'
           */
          proba1_DWork.u4 = proba1_P.Constant_Value_hl;

          /* DataStoreWrite: '<S77>/Data Store Write1' incorporates:
           *  Constant: '<S77>/Constant'
           */
          proba1_DWork.tmp_u4 = proba1_P.Constant_Value_hl;
        }
      }

      /* end of Outputs for SubSystem: '<S71>/zerowanie' */

      /* RelationalOperator: '<S83>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S83>/Constant'
       */
      proba1_B.Compare = (proba1_P.wybortrybu_Value == proba1_P.Constant_Value_a);

      /* Outputs for enable and trigger SubSystem: '<S4>/jedz do przedmiotu' */
      proba1_jedzdoprzedmiotu(proba1_B.Compare,
        proba1_P.przyciskjedzdoprzedmiotu_Value, proba1_M,
        &proba1_B.jedzdoprzedmiotu, &proba1_DWork.jedzdoprzedmiotu,
        &proba1_PrevZCSigState.jedzdoprzedmiotu, &proba1_DWork.obliczoneDist,
        &proba1_DWork.obliczoneFi1, &proba1_DWork.obliczoneFi2,
        &proba1_DWork.obliczoneFi3, &proba1_DWork.tmp_u1, &proba1_DWork.tmp_u2,
        &proba1_DWork.tmp_u3, &proba1_DWork.tmp_u4, &proba1_DWork.u1,
        &proba1_DWork.u2, &proba1_DWork.u3, &proba1_DWork.u4);

      /* end of Outputs for SubSystem: '<S4>/jedz do przedmiotu' */

      /* RelationalOperator: '<S82>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S82>/Constant'
       */
      proba1_B.Compare_p = (proba1_P.wybortrybu_Value ==
                            proba1_P.Constant_Value_jk);

      /* Outputs for enable and trigger SubSystem: '<S4>/rozpoznawanie obrazu' incorporates:
       *  Constant: '<S4>/przycisk rozpoznawanie obrazu'
       */
      if (proba1_B.Compare > 0U) {
        if (proba1_DWork.rozpoznawanieobrazu_MODE == SUBSYS_DISABLED) {
          proba1_DWork.rozpoznawanieobrazu_MODE = SUBSYS_ENABLED;
        }

        if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
              &proba1_PrevZCSigState.rozpoznawanieobrazu_Trig_ZCE,
              (proba1_P.przyciskrozpoznawanieobrazu_Val)) != NO_ZCEVENT)) {
          /* Embedded MATLAB Block: '<S86>/Embedded MATLAB Function'
           */
          /*  This block supports the Embedded MATLAB subset. */
          /*  See the help menu for details.  */
          proba1_B.x_a = 700.0;
          proba1_B.y_k = 200.0;
          proba1_B.z_m = 1100.0;

          /* DataStoreWrite: '<S86>/Data Store Write' */
          proba1_DWork.zadaneX = proba1_B.x_a;

          /* DataStoreWrite: '<S86>/Data Store Write1' */
          proba1_DWork.zadaneY = proba1_B.y_k;

          /* DataStoreWrite: '<S86>/Data Store Write2' */
          proba1_DWork.zadaneZ = proba1_B.z_m;

          /* DataStoreWrite: '<S86>/Data Store Write3' incorporates:
           *  Constant: '<S86>/Constant'
           */
          proba1_DWork.A = proba1_P.Constant_Value_gi;

          /* Outputs for atomic SubSystem: '<S86>/podaj wyliczone wartosci' */

          /* DataStoreWrite: '<S106>/Data Store Write' */
          proba1_DWork.ObliczoneX = proba1_B.x_a;

          /* DataStoreWrite: '<S106>/Data Store Write1' */
          proba1_DWork.ObliczoneY = proba1_B.y_k;

          /* DataStoreWrite: '<S106>/Data Store Write2' */
          proba1_DWork.ObliczoneZ = proba1_B.z_m;

          /* end of Outputs for SubSystem: '<S86>/podaj wyliczone wartosci' */

          /* UnitDelay: '<S102>/Delay Input1' */
          proba1_B.Uk1 = proba1_DWork.DelayInput1_DSTATE;

          /* RelationalOperator: '<S102>/FixPt Relational Operator' */
          proba1_B.FixPtRelationalOperator = (proba1_B.x_a != proba1_B.Uk1);

          /* UnitDelay: '<S103>/Delay Input1' */
          proba1_B.Uk1_o = proba1_DWork.DelayInput1_DSTATE_g;

          /* RelationalOperator: '<S103>/FixPt Relational Operator' */
          proba1_B.FixPtRelationalOperator_c = (proba1_B.y_k != proba1_B.Uk1_o);

          /* UnitDelay: '<S104>/Delay Input1' */
          proba1_B.Uk1_d = proba1_DWork.DelayInput1_DSTATE_m;

          /* RelationalOperator: '<S104>/FixPt Relational Operator' */
          proba1_B.FixPtRelationalOperator_m = (proba1_B.z_m != proba1_B.Uk1_d);

          /* Logic: '<S86>/Logical Operator' */
          proba1_B.LogicalOperator_d = ((proba1_B.FixPtRelationalOperator != 0U)
            && (proba1_B.FixPtRelationalOperator_c != 0U) &&
            (proba1_B.FixPtRelationalOperator_m != 0U));

          /* Update for UnitDelay: '<S102>/Delay Input1' */
          proba1_DWork.DelayInput1_DSTATE = proba1_B.x_a;

          /* Update for UnitDelay: '<S103>/Delay Input1' */
          proba1_DWork.DelayInput1_DSTATE_g = proba1_B.y_k;

          /* Update for UnitDelay: '<S104>/Delay Input1' */
          proba1_DWork.DelayInput1_DSTATE_m = proba1_B.z_m;
        }
      } else if (proba1_DWork.rozpoznawanieobrazu_MODE == SUBSYS_ENABLED) {
        proba1_DWork.rozpoznawanieobrazu_MODE = SUBSYS_DISABLED;
      }

      proba1_PrevZCSigState.rozpoznawanieobrazu_Trig_ZCE =
        proba1_P.przyciskrozpoznawanieobrazu_Val < 0.0 ? NEG_ZCSIG :
        proba1_P.przyciskrozpoznawanieobrazu_Val > 0.0 ? POS_ZCSIG : ZERO_ZCSIG;

      /* end of Outputs for SubSystem: '<S4>/rozpoznawanie obrazu' */

      /* Logic: '<S4>/Logical Operator' */
      proba1_B.LogicalOperator_nz = ((proba1_B.Compare_p != 0U) ||
        proba1_B.LogicalOperator_d);
    }

    /* Outputs for enable SubSystem: '<S4>/kinematyka odwrotna' */
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0 && rtmIsMajorTimeStep(proba1_M))
    {
      if (proba1_B.LogicalOperator_nz) {
        if (proba1_DWork.kinematykaodwrotna_MODE == SUBSYS_DISABLED) {
          proba1_DWork.kinematykaodwrotna_MODE = SUBSYS_ENABLED;
        }
      } else if (proba1_DWork.kinematykaodwrotna_MODE == SUBSYS_ENABLED) {
        /* Disable for enable SubSystem: '<S85>/podaj wyliczone wartosci' */
        proba1_DWork.podajwyliczonewartosci_MODE = SUBSYS_DISABLED;

        /* end of Disable for SubSystem: '<S85>/podaj wyliczone wartosci' */
        proba1_DWork.kinematykaodwrotna_MODE = SUBSYS_DISABLED;
      }
    }

    if (proba1_DWork.kinematykaodwrotna_MODE == SUBSYS_ENABLED) {
      /* DataStoreRead: '<S85>/Data Store Read' */
      proba1_B.DataStoreRead_h = proba1_DWork.zadaneX;

      /* DataStoreRead: '<S85>/Data Store Read2' */
      proba1_B.DataStoreRead2_k = proba1_DWork.zadaneY;

      /* DataStoreRead: '<S85>/Data Store Read1' */
      proba1_B.DataStoreRead1_j = proba1_DWork.zadaneZ;

      /* DataStoreRead: '<S85>/Data Store Read3' */
      proba1_B.DataStoreRead3_a = proba1_DWork.ObliczoneX;

      /* DataStoreRead: '<S85>/Data Store Read5' */
      proba1_B.DataStoreRead5 = proba1_DWork.ObliczoneY;

      /* DataStoreRead: '<S85>/Data Store Read4' */
      proba1_B.DataStoreRead4 = proba1_DWork.ObliczoneZ;

      /* Switch: '<S85>/Switch' */
      if (proba1_B.Compare_p != 0U) {
        tmp = proba1_B.DataStoreRead_h;
        tmp_0 = proba1_B.DataStoreRead2_k;
        tmp_1 = proba1_B.DataStoreRead1_j;
        proba1_B.Switch_g[0] = tmp;
        proba1_B.Switch_g[1] = tmp_0;
        proba1_B.Switch_g[2] = tmp_1;
      } else {
        tmp = proba1_B.DataStoreRead3_a;
        tmp_0 = proba1_B.DataStoreRead5;
        tmp_1 = proba1_B.DataStoreRead4;
        proba1_B.Switch_g[0] = tmp;
        proba1_B.Switch_g[1] = tmp_0;
        proba1_B.Switch_g[2] = tmp_1;
      }

      /* Fcn: '<S85>/fi1' */
      proba1_B.fi1 = rt_atan2(proba1_B.Switch_g[1], proba1_B.Switch_g[0]);

      /* Gain: '<S98>/Gain' */
      proba1_B.Gain_a = proba1_P.Gain_Gain_ej * proba1_B.fi1;

      /* Fcn: '<S85>/fi2' */
      proba1_B.fi2 = (1.57075 - rt_atan2(proba1_B.Switch_g[2] - 700.0, sqrt(pow
        (proba1_B.Switch_g[0], 2.0) + pow(proba1_B.Switch_g[1], 2.0)))) - acos
        (((((pow(450.0, 2.0) + pow(proba1_B.Switch_g[0], 2.0)) + pow
            (proba1_B.Switch_g[1], 2.0)) + pow(proba1_B.Switch_g[2] - 700.0, 2.0))
          - pow(670.0, 2.0)) / (sqrt((pow(proba1_B.Switch_g[0], 2.0) + pow
            (proba1_B.Switch_g[1], 2.0)) + pow(proba1_B.Switch_g[2] - 700.0, 2.0))
          * 900.0));

      /* Gain: '<S99>/Gain' */
      proba1_B.Gain_m4 = proba1_P.Gain_Gain_a * proba1_B.fi2;

      /* Fcn: '<S85>/fi3' */
      tmp = proba1_B.Switch_g[2];
      tmp_0 = proba1_B.fi2;
      proba1_B.fi3 = asin(((450.0 * cos(tmp_0) - tmp) + 700.0) / 670.0);

      /* Gain: '<S100>/Gain' */
      proba1_B.Gain_f = proba1_P.Gain_Gain_gh * proba1_B.fi3;

      /* Fcn: '<S85>/ograniczenie' */
      proba1_B.ograniczenie = (pow(proba1_B.Switch_g[2] - 700.0, 2.0) + pow
        (proba1_B.Switch_g[0], 2.0)) + pow(proba1_B.Switch_g[1], 2.0);

      /* RelationalOperator: '<S90>/Compare' incorporates:
       *  Constant: '<S90>/Constant'
       */
      proba1_B.Compare_mr = (proba1_B.ograniczenie <= proba1_P.Constant_Value_k);

      /* RelationalOperator: '<S91>/Compare' incorporates:
       *  Constant: '<S91>/Constant'
       */
      proba1_B.Compare_f = (proba1_B.Gain_a >= proba1_P.Constant_Value_bw);

      /* RelationalOperator: '<S92>/Compare' incorporates:
       *  Constant: '<S92>/Constant'
       */
      proba1_B.Compare_jp = (proba1_B.Gain_a <= proba1_P.Constant_Value_g);

      /* RelationalOperator: '<S93>/Compare' incorporates:
       *  Constant: '<S93>/Constant'
       */
      proba1_B.Compare_b = (proba1_B.Gain_m4 >= proba1_P.Constant_Value_ky);

      /* RelationalOperator: '<S94>/Compare' incorporates:
       *  Constant: '<S94>/Constant'
       */
      proba1_B.Compare_mp = (proba1_B.Gain_m4 <= proba1_P.Constant_Value_iz);

      /* RelationalOperator: '<S95>/Compare' incorporates:
       *  Constant: '<S95>/Constant'
       */
      proba1_B.Compare_py = (proba1_B.Gain_f >= proba1_P.Constant_Value_on);

      /* RelationalOperator: '<S96>/Compare' incorporates:
       *  Constant: '<S96>/Constant'
       */
      proba1_B.Compare_ee = (proba1_B.Gain_f <= proba1_P.Constant_Value_n1);

      /* Sum: '<S85>/Add' */
      proba1_B.Add = proba1_B.Gain_m4 - proba1_B.Gain_f;

      /* Abs: '<S85>/Abs' */
      proba1_B.Abs_n = fabs(proba1_B.Add);

      /* RelationalOperator: '<S97>/Compare' incorporates:
       *  Constant: '<S97>/Constant'
       */
      proba1_B.Compare_cm = (proba1_B.Abs_n <= proba1_P.Constant_Value_p);

      /* Logic: '<S85>/Logical Operator' */
      proba1_B.LogicalOperator_nh = (proba1_B.Compare_mr && proba1_B.Compare_f &&
        proba1_B.Compare_jp && proba1_B.Compare_b && proba1_B.Compare_mp &&
        proba1_B.Compare_py && proba1_B.Compare_ee && proba1_B.Compare_cm);

      /* Outputs for enable SubSystem: '<S85>/podaj wyliczone wartosci' */
      if (rtmIsMajorTimeStep(proba1_M)) {
        if (proba1_B.LogicalOperator_nh) {
          if (proba1_DWork.podajwyliczonewartosci_MODE == SUBSYS_DISABLED) {
            proba1_DWork.podajwyliczonewartosci_MODE = SUBSYS_ENABLED;
          }
        } else if (proba1_DWork.podajwyliczonewartosci_MODE == SUBSYS_ENABLED) {
          proba1_DWork.podajwyliczonewartosci_MODE = SUBSYS_DISABLED;
        }
      }

      if (proba1_DWork.podajwyliczonewartosci_MODE == SUBSYS_ENABLED) {
        /* DataStoreWrite: '<S101>/Data Store Write' */
        proba1_DWork.obliczoneFi1 = proba1_B.Gain_a;

        /* DataStoreWrite: '<S101>/Data Store Write1' */
        proba1_DWork.obliczoneFi2 = proba1_B.Gain_m4;

        /* DataStoreWrite: '<S101>/Data Store Write2' */
        proba1_DWork.obliczoneFi3 = proba1_B.Gain_f;
      }

      /* end of Outputs for SubSystem: '<S85>/podaj wyliczone wartosci' */
    }

    /* end of Outputs for SubSystem: '<S4>/kinematyka odwrotna' */
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* RelationalOperator: '<S80>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S80>/Constant'
       */
      proba1_B.Compare_g = (proba1_P.wybortrybu_Value ==
                            proba1_P.Constant_Value_c);

      /* Outputs for enable SubSystem: '<S4>/tryb ciagly' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Compare_g > 0U) {
            if (proba1_DWork.trybciagly_MODE == SUBSYS_DISABLED) {
              proba1_DWork.trybciagly_MODE = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.trybciagly_MODE == SUBSYS_ENABLED) {
            proba1_DWork.trybciagly_MODE = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.trybciagly_MODE == SUBSYS_ENABLED) {
          /* DataStoreRead: '<S87>/Data Store Read' */
          proba1_B.DataStoreRead_j = proba1_DWork.tmp_u2;

          /* DataStoreWrite: '<S87>/Data Store Write1' */
          proba1_DWork.u2 = proba1_B.DataStoreRead_j;

          /* DataStoreRead: '<S87>/Data Store Read1' */
          proba1_B.DataStoreRead1_n = proba1_DWork.tmp_u3;

          /* DataStoreWrite: '<S87>/Data Store Write2' */
          proba1_DWork.u3 = proba1_B.DataStoreRead1_n;

          /* DataStoreRead: '<S87>/Data Store Read2' */
          proba1_B.DataStoreRead2_c = proba1_DWork.tmp_u1;

          /* DataStoreWrite: '<S87>/Data Store Write' */
          proba1_DWork.u1 = proba1_B.DataStoreRead2_c;

          /* DataStoreRead: '<S87>/Data Store Read3' */
          proba1_B.DataStoreRead3_n = proba1_DWork.tmp_u4;

          /* DataStoreWrite: '<S87>/Data Store Write3' */
          proba1_DWork.u4 = proba1_B.DataStoreRead3_n;
        }
      }

      /* end of Outputs for SubSystem: '<S4>/tryb ciagly' */

      /* Outputs for enable and trigger SubSystem: '<S4>/tryb kinematyki odwrotnej' */
      proba1_jedzdoprzedmiotu(proba1_B.Compare_p,
        proba1_P.przyciskwyzwolenia_Value, proba1_M,
        &proba1_B.trybkinematykiodwrotnej, &proba1_DWork.trybkinematykiodwrotnej,
        &proba1_PrevZCSigState.trybkinematykiodwrotnej,
        &proba1_DWork.obliczoneDist, &proba1_DWork.obliczoneFi1,
        &proba1_DWork.obliczoneFi2, &proba1_DWork.obliczoneFi3,
        &proba1_DWork.tmp_u1, &proba1_DWork.tmp_u2, &proba1_DWork.tmp_u3,
        &proba1_DWork.tmp_u4, &proba1_DWork.u1, &proba1_DWork.u2,
        &proba1_DWork.u3, &proba1_DWork.u4);

      /* end of Outputs for SubSystem: '<S4>/tryb kinematyki odwrotnej' */

      /* RelationalOperator: '<S81>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S81>/Constant'
       */
      proba1_B.Compare_gt = (proba1_P.wybortrybu_Value ==
        proba1_P.Constant_Value_ob);

      /* Outputs for enable and trigger SubSystem: '<S4>/tryb wyzwalany' incorporates:
       *  Constant: '<S4>/przycisk wyzwolenia'
       */
      if (proba1_B.Compare_gt > 0U) {
        if (proba1_DWork.trybwyzwalany_MODE == SUBSYS_DISABLED) {
          proba1_DWork.trybwyzwalany_MODE = SUBSYS_ENABLED;
        }

        if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
              &proba1_PrevZCSigState.trybwyzwalany_Trig_ZCE,
              (proba1_P.przyciskwyzwolenia_Value)) != NO_ZCEVENT)) {
          /* DataStoreRead: '<S89>/Data Store Read' */
          proba1_B.DataStoreRead_p = proba1_DWork.tmp_u2;

          /* DataStoreWrite: '<S89>/Data Store Write1' */
          proba1_DWork.u2 = proba1_B.DataStoreRead_p;

          /* DataStoreRead: '<S89>/Data Store Read1' */
          proba1_B.DataStoreRead1_a = proba1_DWork.tmp_u3;

          /* DataStoreWrite: '<S89>/Data Store Write2' */
          proba1_DWork.u3 = proba1_B.DataStoreRead1_a;

          /* DataStoreRead: '<S89>/Data Store Read2' */
          proba1_B.DataStoreRead2 = proba1_DWork.tmp_u1;

          /* DataStoreWrite: '<S89>/Data Store Write' */
          proba1_DWork.u1 = proba1_B.DataStoreRead2;

          /* DataStoreRead: '<S89>/Data Store Read3' */
          proba1_B.DataStoreRead3 = proba1_DWork.tmp_u4;

          /* DataStoreWrite: '<S89>/Data Store Write3' */
          proba1_DWork.u4 = proba1_B.DataStoreRead3;
        }
      } else if (proba1_DWork.trybwyzwalany_MODE == SUBSYS_ENABLED) {
        proba1_DWork.trybwyzwalany_MODE = SUBSYS_DISABLED;
      }

      proba1_PrevZCSigState.trybwyzwalany_Trig_ZCE =
        proba1_P.przyciskwyzwolenia_Value < 0.0 ? NEG_ZCSIG :
        proba1_P.przyciskwyzwolenia_Value > 0.0 ? POS_ZCSIG : ZERO_ZCSIG;

      /* end of Outputs for SubSystem: '<S4>/tryb wyzwalany' */
    }

    /* user code (Output function Trailer) */
    /* dSPACE Data Capture block: (none) */
    /* ... Service number: 1 */
    /* ... Service name:   (default) */
    if (rtmIsContinuousTask(proba1_M, 0) && rtmIsMajorTimeStep(proba1_M)) {
      host_service(1, rtk_current_task_absolute_time_ptr_get());

#ifdef RTT_ENABLE

      DsDaq_Service(1, (DsDaqSTimestampStruct *)
                    rtk_current_task_absolute_time_ptr_get());

#endif

    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void proba1_update(int_T tid)
{
  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S26>/Memory' */
    proba1_DWork.Memory_PreviousInput = proba1_B.Product;
  }

  /* Derivative Block: '<S26>/Derivative' */
  {
    real_T timeStampA = proba1_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = proba1_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastBank = &proba1_DWork.Derivative_RWORK.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }

    *lastBank++ = proba1_M->Timing.t[0];
    *lastBank++ = proba1_B.Atan2;
  }

  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S30>/Memory' */
    proba1_DWork.Memory_PreviousInput_c = proba1_B.Logic[0];

    /* Update for Memory: '<S26>/Memory1' */
    proba1_DWork.Memory1_PreviousInput = proba1_B.InitAngle;

    /* Update for Memory: '<S39>/Memory' */
    proba1_DWork.Memory_PreviousInput_g = proba1_B.Product_a;
  }

  /* Derivative Block: '<S39>/Derivative' */
  {
    real_T timeStampA = proba1_DWork.Derivative_RWORK_p.TimeStampA;
    real_T timeStampB = proba1_DWork.Derivative_RWORK_p.TimeStampB;
    real_T *lastBank = &proba1_DWork.Derivative_RWORK_p.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }

    *lastBank++ = proba1_M->Timing.t[0];
    *lastBank++ = proba1_B.Atan2_i;
  }

  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S43>/Memory' */
    proba1_DWork.Memory_PreviousInput_f = proba1_B.Logic_c[0];

    /* Update for Memory: '<S39>/Memory1' */
    proba1_DWork.Memory1_PreviousInput_g = proba1_B.InitAngle_d;

    /* Update for Memory: '<S52>/Memory' */
    proba1_DWork.Memory_PreviousInput_b = proba1_B.Product_o;
  }

  /* Derivative Block: '<S52>/Derivative' */
  {
    real_T timeStampA = proba1_DWork.Derivative_RWORK_c.TimeStampA;
    real_T timeStampB = proba1_DWork.Derivative_RWORK_c.TimeStampB;
    real_T *lastBank = &proba1_DWork.Derivative_RWORK_c.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }

    *lastBank++ = proba1_M->Timing.t[0];
    *lastBank++ = proba1_B.Atan2_l;
  }

  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S56>/Memory' */
    proba1_DWork.Memory_PreviousInput_m = proba1_B.Logic_h[0];

    /* Update for Memory: '<S52>/Memory1' */
    proba1_DWork.Memory1_PreviousInput_d = proba1_B.InitAngle_j;
  }

  /* Update for RateLimiter: '<S14>/Rate Limiter' */
  proba1_DWork.PrevY = proba1_B.RateLimiter;
  proba1_DWork.LastMajorTime = proba1_M->Timing.t[0];

  /* Update for RateLimiter: '<S15>/Rate Limiter' */
  proba1_DWork.PrevY_p = proba1_B.RateLimiter_a;
  proba1_DWork.LastMajorTime_h = proba1_M->Timing.t[0];

  /* Update for RateLimiter: '<S16>/Rate Limiter' */
  proba1_DWork.PrevY_e = proba1_B.RateLimiter_m;
  proba1_DWork.LastMajorTime_hr = proba1_M->Timing.t[0];
  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S62>/Memory' */
    proba1_DWork.Memory_PreviousInput_e = proba1_B.Product_n;
  }

  /* Derivative Block: '<S62>/Derivative' */
  {
    real_T timeStampA = proba1_DWork.Derivative_RWORK_k.TimeStampA;
    real_T timeStampB = proba1_DWork.Derivative_RWORK_k.TimeStampB;
    real_T *lastBank = &proba1_DWork.Derivative_RWORK_k.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }

    *lastBank++ = proba1_M->Timing.t[0];
    *lastBank++ = proba1_B.Atan2_b;
  }

  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S62>/Memory1' */
    proba1_DWork.Memory1_PreviousInput_j = proba1_B.InitAngle_a;
  }

  /* Update for RateLimiter: '<S17>/Rate Limiter' */
  proba1_DWork.PrevY_l = proba1_B.RateLimiter_d;
  proba1_DWork.LastMajorTime_hz = proba1_M->Timing.t[0];
  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S67>/Memory' */
    proba1_DWork.Memory_PreviousInput_h = proba1_B.Product_o5;
  }

  /* Derivative Block: '<S67>/Derivative' */
  {
    real_T timeStampA = proba1_DWork.Derivative_RWORK_m.TimeStampA;
    real_T timeStampB = proba1_DWork.Derivative_RWORK_m.TimeStampB;
    real_T *lastBank = &proba1_DWork.Derivative_RWORK_m.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }

    *lastBank++ = proba1_M->Timing.t[0];
    *lastBank++ = proba1_B.Atan2_j;
  }

  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S67>/Memory1' */
    proba1_DWork.Memory1_PreviousInput_n = proba1_B.InitAngle_f;
  }

  /* Update for RateLimiter: '<S18>/Rate Limiter' */
  proba1_DWork.PrevY_k = proba1_B.RateLimiter_j;
  proba1_DWork.LastMajorTime_a = proba1_M->Timing.t[0];
  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S76>/Memory' */
    proba1_DWork.Memory_PreviousInput_k = proba1_B.Logic_he[0];
  }

  /* Update for RateLimiter: '<S19>/Rate Limiter' */
  proba1_DWork.PrevY_g = proba1_B.RateLimiter_p;
  proba1_DWork.LastMajorTime_d = proba1_M->Timing.t[0];
  if (rtmIsMajorTimeStep(proba1_M)) {
    rt_ertODEUpdateContinuousStates(&proba1_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++proba1_M->Timing.clockTick0))
    ++proba1_M->Timing.clockTickH0;
  proba1_M->Timing.t[0] = proba1_M->Timing.clockTick0 *
    proba1_M->Timing.stepSize0 + proba1_M->Timing.clockTickH0 *
    proba1_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++proba1_M->Timing.clockTick1))
      ++proba1_M->Timing.clockTickH1;
    proba1_M->Timing.t[1] = proba1_M->Timing.clockTick1 *
      proba1_M->Timing.stepSize1 + proba1_M->Timing.clockTickH1 *
      proba1_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void proba1_derivatives(void)
{
  /* ZeroPole Block: '<S27>/Analog Butterworth LP Filter' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CSTAT = proba1_B.SFunction1_j[0];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CSTAT += (proba1_P.AnalogButterworthLPFilter_A)*
      proba1_X.AnalogButterworthLPFilter_CSTAT;
  }

  /* ZeroPole Block: '<S28>/Analog Butterworth LP Filter1' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CSTA = proba1_B.SFunction1_j[1];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CSTA +=
      (proba1_P.AnalogButterworthLPFilter1_A)*
      proba1_X.AnalogButterworthLPFilter1_CSTA;
  }

  /* ZeroPole Block: '<S40>/Analog Butterworth LP Filter' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_f = proba1_B.SFunction1_j[2];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_f +=
      (proba1_P.AnalogButterworthLPFilter_A_g)*
      proba1_X.AnalogButterworthLPFilter_CST_f;
  }

  /* ZeroPole Block: '<S41>/Analog Butterworth LP Filter1' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_c = proba1_B.SFunction1_j[3];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_c +=
      (proba1_P.AnalogButterworthLPFilter1_A_k)*
      proba1_X.AnalogButterworthLPFilter1_CS_c;
  }

  /* ZeroPole Block: '<S53>/Analog Butterworth LP Filter' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_o = proba1_B.SFunction2[0];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_o +=
      (proba1_P.AnalogButterworthLPFilter_A_a)*
      proba1_X.AnalogButterworthLPFilter_CST_o;
  }

  /* ZeroPole Block: '<S54>/Analog Butterworth LP Filter1' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_b = proba1_B.SFunction2[1];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_b +=
      (proba1_P.AnalogButterworthLPFilter1_A_o)*
      proba1_X.AnalogButterworthLPFilter1_CS_b;
  }

  /* ZeroPole Block: '<S63>/Analog Butterworth LP Filter' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CS_oj = proba1_B.SFunction2[2];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CS_oj +=
      (proba1_P.AnalogButterworthLPFilter_A_c)*
      proba1_X.AnalogButterworthLPFilter_CS_oj;
  }

  /* ZeroPole Block: '<S64>/Analog Butterworth LP Filter1' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_j = proba1_B.SFunction2[3];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_j +=
      (proba1_P.AnalogButterworthLPFilter1_A_n)*
      proba1_X.AnalogButterworthLPFilter1_CS_j;
  }

  /* ZeroPole Block: '<S68>/Analog Butterworth LP Filter' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_c = proba1_B.SFunction3[0];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_c +=
      (proba1_P.AnalogButterworthLPFilter_A_f)*
      proba1_X.AnalogButterworthLPFilter_CST_c;
  }

  /* ZeroPole Block: '<S69>/Analog Butterworth LP Filter1' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_C_je = proba1_B.SFunction3[1];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_C_je +=
      (proba1_P.AnalogButterworthLPFilter1_A_c)*
      proba1_X.AnalogButterworthLPFilter1_C_je;
  }
}

/* Model initialize function */
void proba1_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)proba1_M,0,
                sizeof(RT_MODEL_proba1));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&proba1_M->solverInfo, &proba1_M->Timing.simTimeStep);
    rtsiSetTPtr(&proba1_M->solverInfo, &rtmGetTPtr(proba1_M));
    rtsiSetStepSizePtr(&proba1_M->solverInfo, &proba1_M->Timing.stepSize0);
    rtsiSetdXPtr(&proba1_M->solverInfo, &proba1_M->ModelData.derivs);
    rtsiSetContStatesPtr(&proba1_M->solverInfo, &proba1_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&proba1_M->solverInfo,
      &proba1_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&proba1_M->solverInfo, (&rtmGetErrorStatus(proba1_M)));
    rtsiSetRTModelPtr(&proba1_M->solverInfo, proba1_M);
  }

  rtsiSetSimTimeStep(&proba1_M->solverInfo, MAJOR_TIME_STEP);
  proba1_M->ModelData.intgData.f[0] = proba1_M->ModelData.odeF[0];
  proba1_M->ModelData.contStates = ((real_T *) &proba1_X);
  rtsiSetSolverData(&proba1_M->solverInfo, (void *)&proba1_M->ModelData.intgData);
  rtsiSetSolverName(&proba1_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = proba1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    proba1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    proba1_M->Timing.sampleTimes = (&proba1_M->Timing.sampleTimesArray[0]);
    proba1_M->Timing.offsetTimes = (&proba1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    proba1_M->Timing.sampleTimes[0] = (0.0);
    proba1_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    proba1_M->Timing.offsetTimes[0] = (0.0);
    proba1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(proba1_M, &proba1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = proba1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    proba1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(proba1_M, -1);
  proba1_M->Timing.stepSize0 = 0.001;
  proba1_M->Timing.stepSize1 = 0.001;
  proba1_M->solverInfoPtr = (&proba1_M->solverInfo);
  proba1_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&proba1_M->solverInfo, 0.001);
  rtsiSetSolverMode(&proba1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  proba1_M->ModelData.blockIO = ((void *) &proba1_B);
  (void) memset(((void *) &proba1_B),0,
                sizeof(BlockIO_proba1));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&proba1_B.Memory);
    for (i = 0; i < 173; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&proba1_B.DataStoreRead_p);
    for (i = 0; i < 32; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)
      (&proba1_B.trybkinematykiodwrotnej.DataStoreRead);
    for (i = 0; i < 4; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&proba1_B.jedzdoprzedmiotu.DataStoreRead);
    for (i = 0; i < 4; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  proba1_M->ModelData.defaultParam = ((real_T *) &proba1_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &proba1_X;
    proba1_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_proba1));
  }

  /* states (dwork) */
  proba1_M->Work.dwork = ((void *) &proba1_DWork);
  (void) memset((char_T *) &proba1_DWork,0,
                sizeof(D_Work_proba1));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &proba1_DWork.DelayInput1_DSTATE;
    for (i = 0; i < 71; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  proba1_PrevZCSigState.trybwyzwalany_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.trybkinematykiodwrotnej.jedzdoprzedmiotu_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.rozpoznawanieobrazu_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.jedzdoprzedmiotu.jedzdoprzedmiotu_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.blokstopu_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.DS3001ENC_RESET_B1_C1_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.blokstopu_Trig_ZCE_b = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.blokstopu_Trig_ZCE_p = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.blokstopu_Trig_ZCE_f = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void proba1_terminate(void)
{
  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 1, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 2, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 3, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 4, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
  ds2201_dac_out(DS2201_1_BASE, 5, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
  ds2201_dac_out(DS2201_1_BASE, 8, 0);

  /* Terminate for trigger SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */

  /* end of Terminate for SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  proba1_output(tid);
}

void MdlUpdate(int_T tid)
{
  proba1_update(tid);
}

void MdlInitializeSizes(void)
{
  proba1_M->Sizes.numContStates = (10);/* Number of continuous states */
  proba1_M->Sizes.numY = (0);          /* Number of model outputs */
  proba1_M->Sizes.numU = (0);          /* Number of model inputs */
  proba1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  proba1_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  proba1_M->Sizes.numBlocks = (366);   /* Number of blocks */
  proba1_M->Sizes.numBlockIO = (232);  /* Number of block outputs */
  proba1_M->Sizes.numBlockPrms = (259);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S26>/Memory' */
  proba1_DWork.Memory_PreviousInput = proba1_P.Memory_X0;

  /* ZeroPole Block: '<S27>/Analog Butterworth LP Filter' */
  proba1_X.AnalogButterworthLPFilter_CSTAT = 0.0;

  /* ZeroPole Block: '<S28>/Analog Butterworth LP Filter1' */
  proba1_X.AnalogButterworthLPFilter1_CSTA = 0.0;

  /* Derivative Block: '<S26>/Derivative' */
  proba1_DWork.Derivative_RWORK.TimeStampA = rtInf;
  proba1_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<S30>/Memory' */
  proba1_DWork.Memory_PreviousInput_c = proba1_P.Memory_X0_d;

  /* InitializeConditions for Memory: '<S26>/Memory1' */
  proba1_DWork.Memory1_PreviousInput = proba1_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S39>/Memory' */
  proba1_DWork.Memory_PreviousInput_g = proba1_P.Memory_X0_e;

  /* ZeroPole Block: '<S40>/Analog Butterworth LP Filter' */
  proba1_X.AnalogButterworthLPFilter_CST_f = 0.0;

  /* ZeroPole Block: '<S41>/Analog Butterworth LP Filter1' */
  proba1_X.AnalogButterworthLPFilter1_CS_c = 0.0;

  /* Derivative Block: '<S39>/Derivative' */
  proba1_DWork.Derivative_RWORK_p.TimeStampA = rtInf;
  proba1_DWork.Derivative_RWORK_p.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<S43>/Memory' */
  proba1_DWork.Memory_PreviousInput_f = proba1_P.Memory_X0_g;

  /* InitializeConditions for Memory: '<S39>/Memory1' */
  proba1_DWork.Memory1_PreviousInput_g = proba1_P.Memory1_X0_i;

  /* InitializeConditions for Memory: '<S52>/Memory' */
  proba1_DWork.Memory_PreviousInput_b = proba1_P.Memory_X0_dp;

  /* ZeroPole Block: '<S53>/Analog Butterworth LP Filter' */
  proba1_X.AnalogButterworthLPFilter_CST_o = 0.0;

  /* ZeroPole Block: '<S54>/Analog Butterworth LP Filter1' */
  proba1_X.AnalogButterworthLPFilter1_CS_b = 0.0;

  /* Derivative Block: '<S52>/Derivative' */
  proba1_DWork.Derivative_RWORK_c.TimeStampA = rtInf;
  proba1_DWork.Derivative_RWORK_c.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<S56>/Memory' */
  proba1_DWork.Memory_PreviousInput_m = proba1_P.Memory_X0_b;

  /* InitializeConditions for Memory: '<S52>/Memory1' */
  proba1_DWork.Memory1_PreviousInput_d = proba1_P.Memory1_X0_d;

  /* InitializeConditions for RateLimiter: '<S14>/Rate Limiter' */
  proba1_DWork.LastMajorTime = rtInf;

  /* InitializeConditions for RateLimiter: '<S15>/Rate Limiter' */
  proba1_DWork.LastMajorTime_h = rtInf;

  /* InitializeConditions for RateLimiter: '<S16>/Rate Limiter' */
  proba1_DWork.LastMajorTime_hr = rtInf;

  /* InitializeConditions for Memory: '<S62>/Memory' */
  proba1_DWork.Memory_PreviousInput_e = proba1_P.Memory_X0_n;

  /* ZeroPole Block: '<S63>/Analog Butterworth LP Filter' */
  proba1_X.AnalogButterworthLPFilter_CS_oj = 0.0;

  /* ZeroPole Block: '<S64>/Analog Butterworth LP Filter1' */
  proba1_X.AnalogButterworthLPFilter1_CS_j = 0.0;

  /* Derivative Block: '<S62>/Derivative' */
  proba1_DWork.Derivative_RWORK_k.TimeStampA = rtInf;
  proba1_DWork.Derivative_RWORK_k.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<S62>/Memory1' */
  proba1_DWork.Memory1_PreviousInput_j = proba1_P.Memory1_X0_e;

  /* InitializeConditions for RateLimiter: '<S17>/Rate Limiter' */
  proba1_DWork.LastMajorTime_hz = rtInf;

  /* InitializeConditions for Memory: '<S67>/Memory' */
  proba1_DWork.Memory_PreviousInput_h = proba1_P.Memory_X0_m;

  /* ZeroPole Block: '<S68>/Analog Butterworth LP Filter' */
  proba1_X.AnalogButterworthLPFilter_CST_c = 0.0;

  /* ZeroPole Block: '<S69>/Analog Butterworth LP Filter1' */
  proba1_X.AnalogButterworthLPFilter1_C_je = 0.0;

  /* Derivative Block: '<S67>/Derivative' */
  proba1_DWork.Derivative_RWORK_m.TimeStampA = rtInf;
  proba1_DWork.Derivative_RWORK_m.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<S67>/Memory1' */
  proba1_DWork.Memory1_PreviousInput_n = proba1_P.Memory1_X0_o;

  /* InitializeConditions for RateLimiter: '<S18>/Rate Limiter' */
  proba1_DWork.LastMajorTime_a = rtInf;

  /* InitializeConditions for Memory: '<S76>/Memory' */
  proba1_DWork.Memory_PreviousInput_k = proba1_P.Memory_X0_m2;

  /* InitializeConditions for RateLimiter: '<S19>/Rate Limiter' */
  proba1_DWork.LastMajorTime_d = rtInf;
}

void MdlStart(void)
{
  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 1, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 2, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 3, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
  ds2201_dac_out(DS2201_1_BASE, 4, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
  ds2201_dac_out(DS2201_1_BASE, 5, 0);

  /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
  ds2201_dac_out(DS2201_1_BASE, 8, 0);

  /* Start for enable SubSystem: '<S22>/zerowanie' */
  proba1_DWork.zerowanie_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S22>/zerowanie' */

  /* Start for enable SubSystem: '<S35>/zerowanie' */
  proba1_DWork.zerowanie_MODE_l = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S35>/zerowanie' */

  /* Start for enable SubSystem: '<S48>/zerowanie' */
  proba1_DWork.zerowanie_MODE_k = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S48>/zerowanie' */

  /* Start for trigger SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */

  /* end of Start for SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */

  /* Start for enable SubSystem: '<S71>/zerowanie' */
  proba1_DWork.zerowanie_MODE_e = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S71>/zerowanie' */

  /* Start for enable and trigger SubSystem: '<S4>/rozpoznawanie obrazu' */

  /* InitializeConditions for UnitDelay: '<S102>/Delay Input1' */
  proba1_DWork.DelayInput1_DSTATE = proba1_P.DelayInput1_X0;

  /* InitializeConditions for UnitDelay: '<S103>/Delay Input1' */
  proba1_DWork.DelayInput1_DSTATE_g = proba1_P.DelayInput1_X0_c;

  /* InitializeConditions for UnitDelay: '<S104>/Delay Input1' */
  proba1_DWork.DelayInput1_DSTATE_m = proba1_P.DelayInput1_X0_k;

  /* end of Start for SubSystem: '<S4>/rozpoznawanie obrazu' */

  /* Start for enable SubSystem: '<S4>/kinematyka odwrotna' */
  proba1_DWork.kinematykaodwrotna_MODE = SUBSYS_DISABLED;

  /* Start for enable SubSystem: '<S85>/podaj wyliczone wartosci' */
  proba1_DWork.podajwyliczonewartosci_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S85>/podaj wyliczone wartosci' */

  /* end of Start for SubSystem: '<S4>/kinematyka odwrotna' */

  /* Start for enable SubSystem: '<S4>/tryb ciagly' */
  proba1_DWork.trybciagly_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S4>/tryb ciagly' */

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  proba1_DWork.A = proba1_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneDist' */
  proba1_DWork.obliczoneDist = proba1_P.obliczoneDist_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneF3' */
  proba1_DWork.obliczoneFi3 = proba1_P.obliczoneF3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneFi1' */
  proba1_DWork.obliczoneFi1 = proba1_P.obliczoneFi1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneFi2' */
  proba1_DWork.obliczoneFi2 = proba1_P.obliczoneFi2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneX' */
  proba1_DWork.ObliczoneX = proba1_P.obliczoneX_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneY' */
  proba1_DWork.ObliczoneY = proba1_P.obliczoneY_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneZ' */
  proba1_DWork.ObliczoneZ = proba1_P.obliczoneZ_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u1' */
  proba1_DWork.tmp_u1 = proba1_P.tmpu1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u2' */
  proba1_DWork.tmp_u2 = proba1_P.tmpu2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u3' */
  proba1_DWork.tmp_u3 = proba1_P.tmpu3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u4' */
  proba1_DWork.tmp_u4 = proba1_P.tmpu4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u1' */
  proba1_DWork.u1 = proba1_P.u1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u2' */
  proba1_DWork.u2 = proba1_P.u2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u3' */
  proba1_DWork.u3 = proba1_P.u3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u4' */
  proba1_DWork.u4 = proba1_P.u4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/xKon' */
  proba1_DWork.xKon = proba1_P.xKon_InitialValue;

  /* Start for DataStoreMemory: '<Root>/yKon' */
  proba1_DWork.yKon = proba1_P.yKon_InitialValue;

  /* Start for DataStoreMemory: '<Root>/zKon' */
  proba1_DWork.zKon = proba1_P.zKon_InitialValue;

  /* Start for DataStoreMemory: '<Root>/zadaneX' */
  proba1_DWork.zadaneX = proba1_P.zadaneX_InitialValue;

  /* Start for DataStoreMemory: '<Root>/zadaneY' */
  proba1_DWork.zadaneY = proba1_P.zadaneY_InitialValue;

  /* Start for DataStoreMemory: '<Root>/zadaneZ' */
  proba1_DWork.zadaneZ = proba1_P.zadaneZ_InitialValue;
  MdlInitialize();
}

RT_MODEL_proba1 *proba1(void)
{
  proba1_initialize(1);
  return proba1_M;
}

void MdlTerminate(void)
{
  proba1_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
