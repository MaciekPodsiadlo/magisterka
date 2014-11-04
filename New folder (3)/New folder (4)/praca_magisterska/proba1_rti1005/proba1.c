/*
 * proba1.c
 *
 * Real-Time Workshop code generation for Simulink model "proba1.mdl".
 *
 * Model Version              : 1.378
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Jul 02 15:19:38 2014
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
  real_T *rtd_tmp_u0, real_T *rtd_tmp_u1, real_T *rtd_tmp_u2, real_T *rtd_tmp_u3,
  real_T *rtd_u0, real_T *rtd_u1, real_T *rtd_u2, real_T *rtd_u3)
{
  if (rtu_0 > 0U) {
    if (localDW->jedzdoprzedmiotu_MODE == SUBSYS_DISABLED) {
      localDW->jedzdoprzedmiotu_MODE = SUBSYS_ENABLED;
    }

    if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
          &localZCE->jedzdoprzedmiotu_Trig_ZCE,
          (rtu_1)) != NO_ZCEVENT)) {
      /* DataStoreRead: '<S100>/Data Store Read' */
      localB->DataStoreRead = (*rtd_obliczoneFi1);

      /* DataStoreWrite: '<S100>/Data Store Write' */
      (*rtd_tmp_u1) = localB->DataStoreRead;

      /* DataStoreWrite: '<S100>/Data Store Write3' */
      (*rtd_u1) = localB->DataStoreRead;

      /* DataStoreRead: '<S100>/Data Store Read1' */
      localB->DataStoreRead1 = (*rtd_obliczoneFi3);

      /* DataStoreWrite: '<S100>/Data Store Write2' */
      (*rtd_tmp_u3) = localB->DataStoreRead1;

      /* DataStoreWrite: '<S100>/Data Store Write5' */
      (*rtd_u3) = localB->DataStoreRead1;

      /* DataStoreRead: '<S100>/Data Store Read2' */
      localB->DataStoreRead2 = (*rtd_obliczoneFi2);

      /* DataStoreWrite: '<S100>/Data Store Write1' */
      (*rtd_tmp_u2) = localB->DataStoreRead2;

      /* DataStoreWrite: '<S100>/Data Store Write4' */
      (*rtd_u2) = localB->DataStoreRead2;

      /* DataStoreRead: '<S100>/Data Store Read3' */
      localB->DataStoreRead3 = (*rtd_obliczoneDist);

      /* DataStoreWrite: '<S100>/Data Store Write6' */
      (*rtd_tmp_u0) = localB->DataStoreRead3;

      /* DataStoreWrite: '<S100>/Data Store Write7' */
      (*rtd_u0) = localB->DataStoreRead3;
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

      /* Fcn: '<S90>/Fcn' */
      proba1_B.Fcn = proba1_B.SFunction1_h * pow(2.0, 23.0) * 3.1415926535897931
        / 1000.0;

      /* Gain: '<S90>/Gain2' */
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
    proba1_B.Compare_jd = (proba1_B.DataStoreRead >= proba1_P.Constant_Value_i);

    /* RelationalOperator: '<S32>/Compare' incorporates:
     *  Constant: '<S32>/Constant'
     */
    proba1_B.Compare_e = (proba1_B.DataStoreRead <= proba1_P.Constant_Value_m);

    /* Logic: '<S24>/Logical Operator' */
    proba1_B.LogicalOperator_a = (proba1_B.Compare_jd && proba1_B.Compare_e);

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
    proba1_B.Compare_dg = (proba1_B.DataStoreRead_b <= proba1_P.Constant_Value_b);

    /* Logic: '<S37>/Logical Operator' */
    proba1_B.LogicalOperator_ad = (proba1_B.Compare_m && proba1_B.Compare_dg);

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

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Logic: '<S61>/Logical Operator' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      proba1_B.LogicalOperator_n = (real_T)((proba1_B.SFunction1_c != 0.0) ||
        (proba1_P.przyciskstopu_Value != 0.0));

      /* Memory: '<S69>/Memory' */
      proba1_B.Memory_c = proba1_DWork.Memory_PreviousInput_o;

      /* CombinatorialLogic Block: '<S69>/Logic'
       */
      {
        int_T rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (int_T)(proba1_P.przyciskbazowania_Value != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.LogicalOperator_n != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.Memory_c != 0.0);

        /* Copy the appropriate row of the table into the block output vector */
        proba1_B.Logic_p[0] = proba1_P.Logic_table_l[rowidx];
        proba1_B.Logic_p[1] = proba1_P.Logic_table_l[rowidx + 8];
      }

      /* Memory: '<S65>/Memory' */
      proba1_B.Memory_gz = proba1_DWork.Memory_PreviousInput_e;
    }

    /* ZeroPole Block: '<S66>/Analog Butterworth LP Filter' */
    {
      proba1_B.AnalogButterworthLPFilter_k =
        proba1_P.AnalogButterworthLPFilter_C_b*
        proba1_X.AnalogButterworthLPFilter_CS_oj;
    }

    /* ZeroPole Block: '<S67>/Analog Butterworth LP Filter1' */
    {
      proba1_B.AnalogButterworthLPFilter1_c =
        proba1_P.AnalogButterworthLPFilter1_C_b*
        proba1_X.AnalogButterworthLPFilter1_CS_j;
    }

    /* Fcn: '<S65>/Atan2' */
    tmp = proba1_B.AnalogButterworthLPFilter_k;
    tmp_0 = proba1_B.AnalogButterworthLPFilter1_c;
    proba1_B.Atan2_b = rt_atan2(tmp, tmp_0);

    /* Derivative Block: '<S65>/Derivative' */
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

    /* DeadZone Block: '<S65>/Dead Zone'
     */
    if (proba1_B.Derivative_f >= proba1_P.DeadZone_End_a) {
      proba1_B.DeadZone_n = proba1_B.Derivative_f - proba1_P.DeadZone_End_a;
    } else if (proba1_B.Derivative_f > proba1_P.DeadZone_Start_ib) {
      proba1_B.DeadZone_n = 0.0;
    } else {
      proba1_B.DeadZone_n = proba1_B.Derivative_f - proba1_P.DeadZone_Start_ib;
    }

    /* Saturate: '<S65>/Saturation' */
    tmp = proba1_B.DeadZone_n;
    proba1_B.Saturation_c = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_m,
      proba1_P.Saturation_UpperSat_ma);

    /* Sum: '<S65>/Sum' */
    proba1_B.Sum_c = proba1_B.Memory_gz - proba1_B.Saturation_c;

    /* Product: '<S65>/Product' */
    proba1_B.Product_n = proba1_B.Sum_c * proba1_B.Logic_p[1];

    /* Gain: '<S65>/Conversion Rotation to Angle' */
    proba1_B.ConversionRotationtoAngle_g =
      proba1_P.ConversionRotationtoAngle_Gai_c * proba1_B.Product_n;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S65>/Memory1' */
      proba1_B.Memory1_k = proba1_DWork.Memory1_PreviousInput_j;
    }

    /* Switch: '<S65>/Init Angle' */
    if (proba1_B.Logic_p[1] >= proba1_P.InitAngle_Threshold_k) {
      proba1_B.InitAngle_a = proba1_B.Memory1_k;
    } else {
      proba1_B.InitAngle_a = proba1_B.Atan2_b;
    }

    /* Sum: '<S65>/Sum1' */
    proba1_B.Sum1_d = (proba1_B.ConversionRotationtoAngle_g + proba1_B.Atan2_b)
      - proba1_B.InitAngle_a;

    /* Gain: '<S65>/Gear' */
    proba1_B.Gear_k = proba1_P.Gear_Gain_nb * proba1_B.Sum1_d;

    /* Gain: '<S65>/Conversion Rad to Deg' */
    proba1_B.ConversionRadtoDeg_j = proba1_P.ConversionRadtoDeg_Gain_l *
      proba1_B.Gear_k;

    /* DataStoreRead: '<S17>/Data Store Read1' */
    proba1_B.DataStoreRead1_a = proba1_DWork.u4;

    /* RelationalOperator: '<S72>/Compare' incorporates:
     *  Constant: '<S72>/Constant'
     */
    proba1_B.Compare_ds = (proba1_B.DataStoreRead1_a >=
      proba1_P.Constant_Value_a);

    /* RelationalOperator: '<S71>/Compare' incorporates:
     *  Constant: '<S71>/Constant'
     */
    proba1_B.Compare_as = (proba1_B.DataStoreRead1_a <=
      proba1_P.Constant_Value_k);

    /* Logic: '<S63>/Logical Operator' */
    proba1_B.LogicalOperator_h = (proba1_B.Compare_ds && proba1_B.Compare_as);

    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/Constant1'
     */
    if (proba1_B.LogicalOperator_h) {
      proba1_B.Switch_pm = proba1_B.DataStoreRead1_a;
    } else {
      proba1_B.Switch_pm = proba1_P.Constant1_Value_p;
    }

    /* Sum: '<S17>/Sum1' */
    proba1_B.Sum1_nk = proba1_B.Switch_pm - proba1_B.ConversionRadtoDeg_j;

    /* Gain: '<S17>/Gain2' */
    proba1_B.Gain2_d = proba1_P.Gain2_Gain_m * proba1_B.Sum1_nk;

    /* Saturate: '<S17>/Saturation1' */
    tmp = proba1_B.Gain2_d;
    proba1_B.Saturation1_i = rt_SATURATE(tmp, proba1_P.Saturation1_LowerSat_h,
      proba1_P.Saturation1_UpperSat_f);

    /* Product: '<S17>/Product' */
    proba1_B.Product_fe = proba1_B.Saturation1_i * proba1_B.Saturation_f;

    /* RateLimiter: '<S17>/Rate Limiter1' */
    if (proba1_DWork.LastMajorTime_j == rtInf) {
      proba1_B.RateLimiter1 = proba1_B.Product_fe;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_j;
      tmp_0 = tmp * proba1_P.RateLimiter1_RisingLim;
      tmp_1 = proba1_B.Product_fe - proba1_DWork.PrevY_i;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter1 = proba1_DWork.PrevY_i + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter1_FallingLim;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter1 = proba1_DWork.PrevY_i + tmp;
        } else {
          proba1_B.RateLimiter1 = proba1_B.Product_fe;
        }
      }
    }

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/Constant2'
     */
    if (proba1_B.Logic_p[0] != 0.0) {
      proba1_B.Switch_e = proba1_P.Constant2_Value;
    } else {
      proba1_B.Switch_e = proba1_B.RateLimiter1;
    }

    /* Gain: '<S17>/Gain3' */
    proba1_B.Gain3 = proba1_P.Gain3_Gain * proba1_B.Switch_e;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP1 */
      ds2201_dac_out(DS2201_1_BASE, 4, (dsfloat) proba1_B.Gain3);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Logic: '<S74>/Logical Operator' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      proba1_B.LogicalOperator_c = (real_T)((proba1_B.SFunction1_b != 0.0) ||
        (proba1_P.przyciskstopu_Value != 0.0));

      /* Memory: '<S82>/Memory' */
      proba1_B.Memory_c1 = proba1_DWork.Memory_PreviousInput_co;

      /* CombinatorialLogic Block: '<S82>/Logic'
       */
      {
        int_T rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (int_T)(proba1_P.przyciskbazowania_Value != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.LogicalOperator_c != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.Memory_c1 != 0.0);

        /* Copy the appropriate row of the table into the block output vector */
        proba1_B.Logic_a[0] = proba1_P.Logic_table_o[rowidx];
        proba1_B.Logic_a[1] = proba1_P.Logic_table_o[rowidx + 8];
      }

      /* Memory: '<S78>/Memory' */
      proba1_B.Memory_j5 = proba1_DWork.Memory_PreviousInput_h;
    }

    /* ZeroPole Block: '<S79>/Analog Butterworth LP Filter' */
    {
      proba1_B.AnalogButterworthLPFilter_c =
        proba1_P.AnalogButterworthLPFilter_C_h*
        proba1_X.AnalogButterworthLPFilter_CST_c;
    }

    /* ZeroPole Block: '<S80>/Analog Butterworth LP Filter1' */
    {
      proba1_B.AnalogButterworthLPFilter1_n =
        proba1_P.AnalogButterworthLPFilter1_C_n5*
        proba1_X.AnalogButterworthLPFilter1_C_je;
    }

    /* Fcn: '<S78>/Atan2' */
    tmp = proba1_B.AnalogButterworthLPFilter_c;
    tmp_0 = proba1_B.AnalogButterworthLPFilter1_n;
    proba1_B.Atan2_j = rt_atan2(tmp, tmp_0);

    /* Derivative Block: '<S78>/Derivative' */
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

    /* DeadZone Block: '<S78>/Dead Zone'
     */
    if (proba1_B.Derivative_g >= proba1_P.DeadZone_End_lg) {
      proba1_B.DeadZone_o = proba1_B.Derivative_g - proba1_P.DeadZone_End_lg;
    } else if (proba1_B.Derivative_g > proba1_P.DeadZone_Start_j) {
      proba1_B.DeadZone_o = 0.0;
    } else {
      proba1_B.DeadZone_o = proba1_B.Derivative_g - proba1_P.DeadZone_Start_j;
    }

    /* Saturate: '<S78>/Saturation' */
    tmp = proba1_B.DeadZone_o;
    proba1_B.Saturation_a = rt_SATURATE(tmp, proba1_P.Saturation_LowerSat_mt,
      proba1_P.Saturation_UpperSat_n);

    /* Sum: '<S78>/Sum' */
    proba1_B.Sum_mv = proba1_B.Memory_j5 - proba1_B.Saturation_a;

    /* Product: '<S78>/Product' */
    proba1_B.Product_o5 = proba1_B.Sum_mv * proba1_B.Logic_a[1];

    /* Gain: '<S78>/Conversion Rotation to Angle' */
    proba1_B.ConversionRotationtoAngle_e =
      proba1_P.ConversionRotationtoAngle_Gai_g * proba1_B.Product_o5;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S78>/Memory1' */
      proba1_B.Memory1_fx = proba1_DWork.Memory1_PreviousInput_n;
    }

    /* Switch: '<S78>/Init Angle' */
    if (proba1_B.Logic_a[1] >= proba1_P.InitAngle_Threshold_p) {
      proba1_B.InitAngle_f = proba1_B.Memory1_fx;
    } else {
      proba1_B.InitAngle_f = proba1_B.Atan2_j;
    }

    /* Sum: '<S78>/Sum1' */
    proba1_B.Sum1_f = (proba1_B.ConversionRotationtoAngle_e + proba1_B.Atan2_j)
      - proba1_B.InitAngle_f;

    /* Gain: '<S78>/Gear' */
    proba1_B.Gear_l = proba1_P.Gear_Gain_a * proba1_B.Sum1_f;

    /* Gain: '<S78>/Conversion Rad to Deg' */
    proba1_B.ConversionRadtoDeg_h = proba1_P.ConversionRadtoDeg_Gain_go *
      proba1_B.Gear_l;

    /* DataStoreRead: '<S18>/Data Store Read1' */
    proba1_B.DataStoreRead1_j = proba1_DWork.u5;

    /* RelationalOperator: '<S85>/Compare' incorporates:
     *  Constant: '<S85>/Constant'
     */
    proba1_B.Compare_pd = (proba1_B.DataStoreRead1_j >=
      proba1_P.Constant_Value_c);

    /* RelationalOperator: '<S84>/Compare' incorporates:
     *  Constant: '<S84>/Constant'
     */
    proba1_B.Compare_eo = (proba1_B.DataStoreRead1_j <=
      proba1_P.Constant_Value_ku);

    /* Logic: '<S76>/Logical Operator' */
    proba1_B.LogicalOperator_l = (proba1_B.Compare_pd && proba1_B.Compare_eo);

    /* Switch: '<S76>/Switch' incorporates:
     *  Constant: '<S76>/Constant1'
     */
    if (proba1_B.LogicalOperator_l) {
      proba1_B.Switch_my = proba1_B.DataStoreRead1_j;
    } else {
      proba1_B.Switch_my = proba1_P.Constant1_Value_e;
    }

    /* Sum: '<S18>/Sum1' */
    proba1_B.Sum1_f3 = proba1_B.Switch_my - proba1_B.ConversionRadtoDeg_h;

    /* Gain: '<S18>/Gain2' */
    proba1_B.Gain2_p = proba1_P.Gain2_Gain_l * proba1_B.Sum1_f3;

    /* Saturate: '<S18>/Saturation1' */
    tmp = proba1_B.Gain2_p;
    proba1_B.Saturation1_m = rt_SATURATE(tmp, proba1_P.Saturation1_LowerSat_b,
      proba1_P.Saturation1_UpperSat_d);

    /* Product: '<S18>/Product' */
    proba1_B.Product_e = proba1_B.Saturation1_m * proba1_B.Saturation_f;

    /* RateLimiter: '<S18>/Rate Limiter1' */
    if (proba1_DWork.LastMajorTime_a == rtInf) {
      proba1_B.RateLimiter1_e = proba1_B.Product_e;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_a;
      tmp_0 = tmp * proba1_P.RateLimiter1_RisingLim_g;
      tmp_1 = proba1_B.Product_e - proba1_DWork.PrevY_eu;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter1_e = proba1_DWork.PrevY_eu + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter1_FallingLim_g;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter1_e = proba1_DWork.PrevY_eu + tmp;
        } else {
          proba1_B.RateLimiter1_e = proba1_B.Product_e;
        }
      }
    }

    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S18>/Constant2'
     */
    if (proba1_B.Logic_a[0] != 0.0) {
      proba1_B.Switch_en = proba1_P.Constant2_Value_a;
    } else {
      proba1_B.Switch_en = proba1_B.RateLimiter1_e;
    }

    /* Gain: '<S18>/Gain3' */
    proba1_B.Gain3_o = proba1_P.Gain3_Gain_h * proba1_B.Switch_en;
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2201 #1 Unit:DAC Group:DS2201_GROUP2 */
      ds2201_dac_out(DS2201_1_BASE, 5, (dsfloat) proba1_B.Gain3_o);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* Logic: '<S87>/Logical Operator' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      proba1_B.LogicalOperator_nv = (real_T)((proba1_B.SFunction1_i != 0.0) ||
        (proba1_P.przyciskstopu_Value != 0.0));

      /* Memory: '<S92>/Memory' */
      proba1_B.Memory_jn = proba1_DWork.Memory_PreviousInput_k;

      /* CombinatorialLogic Block: '<S92>/Logic'
       */
      {
        int_T rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (int_T)(proba1_P.przyciskbazowania_Value != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.LogicalOperator_nv != 0.0);
        rowidx = (rowidx << 1) + (int_T)(proba1_B.Memory_jn != 0.0);

        /* Copy the appropriate row of the table into the block output vector */
        proba1_B.Logic_he[0] = proba1_P.Logic_table_p[rowidx];
        proba1_B.Logic_he[1] = proba1_P.Logic_table_p[rowidx + 8];
      }
    }

    /* DataStoreRead: '<S19>/Data Store Read1' */
    proba1_B.DataStoreRead1_m = proba1_DWork.u0;

    /* RelationalOperator: '<S95>/Compare' incorporates:
     *  Constant: '<S95>/Constant'
     */
    proba1_B.Compare_hw = (proba1_B.DataStoreRead1_m >=
      proba1_P.Constant_Value_f);

    /* RelationalOperator: '<S94>/Compare' incorporates:
     *  Constant: '<S94>/Constant'
     */
    proba1_B.Compare_gk = (proba1_B.DataStoreRead1_m <=
      proba1_P.Constant_Value_l);

    /* Logic: '<S89>/Logical Operator' */
    proba1_B.LogicalOperator_oc = (proba1_B.Compare_hw && proba1_B.Compare_gk);

    /* Switch: '<S89>/Switch' incorporates:
     *  Constant: '<S89>/Constant1'
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
    proba1_B.Product_ey = proba1_B.Saturation_i * proba1_B.Saturation_f;

    /* RateLimiter: '<S19>/Rate Limiter' */
    if (proba1_DWork.LastMajorTime_d == rtInf) {
      proba1_B.RateLimiter_p = proba1_B.Product_ey;
    } else {
      tmp = proba1_M->Timing.t[0] - proba1_DWork.LastMajorTime_d;
      tmp_0 = tmp * proba1_P.RateLimiter_RisingLim_o;
      tmp_1 = proba1_B.Product_ey - proba1_DWork.PrevY_g;
      if (tmp_1 > tmp_0) {
        proba1_B.RateLimiter_p = proba1_DWork.PrevY_g + tmp_0;
      } else {
        tmp *= proba1_P.RateLimiter_FallingLim_n;
        if (tmp_1 < tmp) {
          proba1_B.RateLimiter_p = proba1_DWork.PrevY_g + tmp;
        } else {
          proba1_B.RateLimiter_p = proba1_B.Product_ey;
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

      /* Outputs for trigger SubSystem: '<S17>/blok stopu' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
            &proba1_PrevZCSigState.blokstopu_Trig_ZCE_ke,
            (proba1_P.przyciskstopu_Value)) != NO_ZCEVENT)) {
        /* DataStoreWrite: '<S62>/Data Store Write' */
        proba1_DWork.u4 = proba1_B.ConversionRadtoDeg_j;

        /* DataStoreWrite: '<S62>/Data Store Write1' */
        proba1_DWork.tmp_u4 = proba1_B.ConversionRadtoDeg_j;
      }

      /* end of Outputs for SubSystem: '<S17>/blok stopu' */

      /* Outputs for enable SubSystem: '<S61>/zerowanie' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Logic_p[0] > 0.0) {
            if (proba1_DWork.zerowanie_MODE_g == SUBSYS_DISABLED) {
              proba1_DWork.zerowanie_MODE_g = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.zerowanie_MODE_g == SUBSYS_ENABLED) {
            proba1_DWork.zerowanie_MODE_g = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.zerowanie_MODE_g == SUBSYS_ENABLED) {
          /* DataStoreWrite: '<S70>/Data Store Write' incorporates:
           *  Constant: '<S70>/Constant'
           */
          proba1_DWork.u4 = proba1_P.Constant_Value_p;

          /* DataStoreWrite: '<S70>/Data Store Write1' incorporates:
           *  Constant: '<S70>/Constant'
           */
          proba1_DWork.tmp_u4 = proba1_P.Constant_Value_p;
        }
      }

      /* end of Outputs for SubSystem: '<S61>/zerowanie' */

      /* Outputs for trigger SubSystem: '<S18>/blok stopu' incorporates:
       *  Constant: '<S3>/przycisk stopu'
       */
      if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
            &proba1_PrevZCSigState.blokstopu_Trig_ZCE_k,
            (proba1_P.przyciskstopu_Value)) != NO_ZCEVENT)) {
        /* DataStoreWrite: '<S75>/Data Store Write' */
        proba1_DWork.u5 = proba1_B.ConversionRadtoDeg_h;

        /* DataStoreWrite: '<S75>/Data Store Write1' */
        proba1_DWork.tmp_u5 = proba1_B.ConversionRadtoDeg_h;
      }

      /* end of Outputs for SubSystem: '<S18>/blok stopu' */

      /* Outputs for enable SubSystem: '<S74>/zerowanie' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Logic_a[0] > 0.0) {
            if (proba1_DWork.zerowanie_MODE_m == SUBSYS_DISABLED) {
              proba1_DWork.zerowanie_MODE_m = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.zerowanie_MODE_m == SUBSYS_ENABLED) {
            proba1_DWork.zerowanie_MODE_m = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.zerowanie_MODE_m == SUBSYS_ENABLED) {
          /* DataStoreWrite: '<S83>/Data Store Write' incorporates:
           *  Constant: '<S83>/Constant'
           */
          proba1_DWork.u5 = proba1_P.Constant_Value_dm;

          /* DataStoreWrite: '<S83>/Data Store Write1' incorporates:
           *  Constant: '<S83>/Constant'
           */
          proba1_DWork.tmp_u5 = proba1_P.Constant_Value_dm;
        }
      }

      /* end of Outputs for SubSystem: '<S74>/zerowanie' */

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
        /* DataStoreWrite: '<S88>/Data Store Write' */
        proba1_DWork.u0 = proba1_B.Gain2;

        /* DataStoreWrite: '<S88>/Data Store Write1' */
        proba1_DWork.tmp_u0 = proba1_B.Gain2;
      }

      /* end of Outputs for SubSystem: '<S19>/blok stopu' */

      /* Outputs for enable SubSystem: '<S87>/zerowanie' */
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
          /* DataStoreWrite: '<S93>/Data Store Write' incorporates:
           *  Constant: '<S93>/Constant'
           */
          proba1_DWork.u0 = proba1_P.Constant_Value_hl;

          /* DataStoreWrite: '<S93>/Data Store Write1' incorporates:
           *  Constant: '<S93>/Constant'
           */
          proba1_DWork.tmp_u0 = proba1_P.Constant_Value_hl;
        }
      }

      /* end of Outputs for SubSystem: '<S87>/zerowanie' */

      /* RelationalOperator: '<S99>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S99>/Constant'
       */
      proba1_B.Compare = (proba1_P.wybortrybu_Value ==
                          proba1_P.Constant_Value_ac);

      /* Outputs for enable and trigger SubSystem: '<S4>/jedz do przedmiotu' */
      proba1_jedzdoprzedmiotu(proba1_B.Compare,
        proba1_P.przyciskjedzdoprzedmiotu_Value, proba1_M,
        &proba1_B.jedzdoprzedmiotu, &proba1_DWork.jedzdoprzedmiotu,
        &proba1_PrevZCSigState.jedzdoprzedmiotu, &proba1_DWork.obliczoneDist,
        &proba1_DWork.obliczoneFi1, &proba1_DWork.obliczoneFi2,
        &proba1_DWork.obliczoneFi3, &proba1_DWork.tmp_u0, &proba1_DWork.tmp_u1,
        &proba1_DWork.tmp_u2, &proba1_DWork.tmp_u3, &proba1_DWork.u0,
        &proba1_DWork.u1, &proba1_DWork.u2, &proba1_DWork.u3);

      /* end of Outputs for SubSystem: '<S4>/jedz do przedmiotu' */

      /* RelationalOperator: '<S98>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S98>/Constant'
       */
      proba1_B.Compare_p = (proba1_P.wybortrybu_Value ==
                            proba1_P.Constant_Value_jk);
    }

    /* Outputs for enable SubSystem: '<S4>/kinematyka odwrotna' */
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0 && rtmIsMajorTimeStep(proba1_M))
    {
      if (proba1_B.Compare_p > 0U) {
        if (proba1_DWork.kinematykaodwrotna_MODE == SUBSYS_DISABLED) {
          proba1_DWork.kinematykaodwrotna_MODE = SUBSYS_ENABLED;
        }
      } else if (proba1_DWork.kinematykaodwrotna_MODE == SUBSYS_ENABLED) {
        /* Disable for enable SubSystem: '<S101>/podaj wyliczone wartosci' */
        proba1_DWork.podajwyliczonewartosci_MODE = SUBSYS_DISABLED;

        /* end of Disable for SubSystem: '<S101>/podaj wyliczone wartosci' */
        proba1_DWork.kinematykaodwrotna_MODE = SUBSYS_DISABLED;
      }
    }

    if (proba1_DWork.kinematykaodwrotna_MODE == SUBSYS_ENABLED) {
      /* DataStoreRead: '<S101>/Data Store Read' */
      proba1_B.DataStoreRead_h = proba1_DWork.zadaneX;

      /* DataStoreRead: '<S101>/Data Store Read6' */
      proba1_B.DataStoreRead6_j5 = proba1_DWork.yKon;

      /* DataStoreRead: '<S120>/Data Store Read6' */
      proba1_B.DataStoreRead6_o = proba1_DWork.yKon;

      /* DataStoreRead: '<S101>/Data Store Read2' */
      proba1_B.DataStoreRead2_k = proba1_DWork.zadaneY;

      /* Sum: '<S120>/Sum' */
      proba1_B.Sum_oi = proba1_B.DataStoreRead2_k - proba1_B.DataStoreRead6_o;

      /* DataStoreRead: '<S101>/Data Store Read1' */
      proba1_B.DataStoreRead1_jb = proba1_DWork.zadaneZ;

      /* Fcn: '<S120>/r' */
      tmp = proba1_B.DataStoreRead_h;
      tmp_0 = proba1_B.Sum_oi;
      proba1_B.r_b = sqrt(pow(tmp, 2.0) + pow(tmp_0, 2.0));

      /* Switch: '<S120>/Switch1' incorporates:
       *  Constant: '<S120>/Constant1'
       */
      if (proba1_B.r_b != 0.0) {
        proba1_B.Switch1_g = proba1_B.r_b;
      } else {
        proba1_B.Switch1_g = proba1_P.Constant1_Value_k;
      }

      /* Fcn: '<S120>/fi' */
      tmp = proba1_B.DataStoreRead_h;
      tmp_0 = proba1_B.Sum_oi;
      tmp_1 = proba1_B.Switch1_g;
      proba1_B.fi_n = acos(tmp / tmp_1) * rt_SGN(tmp_0);

      /* RelationalOperator: '<S122>/Compare' incorporates:
       *  Constant: '<S122>/Constant'
       */
      proba1_B.Compare_bb = (proba1_B.fi_n >= proba1_P.Constant_Value_cn);

      /* Outputs for atomic SubSystem: '<S120>/warunek na Fi' */

      /* Switch: '<S126>/Switch1' incorporates:
       *  Constant: '<S126>/FImax'
       *  Constant: '<S126>/FImin1'
       */
      if (proba1_B.Compare_bb != 0U) {
        proba1_B.Switch1_n3 = proba1_P.FImax_Value;
      } else {
        proba1_B.Switch1_n3 = proba1_P.FImin1_Value;
      }

      /* Fcn: '<S126>/Xgran' */
      tmp = proba1_B.DataStoreRead_h;
      tmp_1 = proba1_B.Switch1_n3;
      proba1_B.Xgran_kn = tmp * tan(tmp_1);

      /* Fcn: '<S126>/Xnastawy2' */
      tmp_0 = proba1_B.Sum_oi;
      tmp_1 = proba1_B.Xgran_kn;
      proba1_B.Xnastawy2_o = tmp_0 + tmp_1;

      /* DataStoreRead: '<S128>/Data Store Read6' */
      proba1_B.DataStoreRead6_d = proba1_DWork.yKon;

      /* Sum: '<S128>/Add' */
      proba1_B.Add_oq = proba1_B.Xnastawy2_o + proba1_B.DataStoreRead6_d;

      /* RelationalOperator: '<S131>/Compare' incorporates:
       *  Constant: '<S131>/Constant'
       */
      proba1_B.Compare_n = (proba1_B.Add_oq > proba1_P.Constant_Value_dg);

      /* RelationalOperator: '<S130>/Compare' incorporates:
       *  Constant: '<S130>/Constant'
       */
      proba1_B.Compare_bp = (proba1_B.Add_oq < proba1_P.Constant_Value_oo);

      /* Logic: '<S128>/Logical Operator4' */
      proba1_B.LogicalOperator4_j = ((proba1_B.Compare_n != 0U) &&
        (proba1_B.Compare_bp != 0U));

      /* Fcn: '<S126>/Xnastawy1' */
      tmp_0 = proba1_B.Sum_oi;
      tmp_1 = proba1_B.Xgran_kn;
      proba1_B.Xnastawy1_n = tmp_0 - tmp_1;

      /* DataStoreRead: '<S129>/Data Store Read6' */
      proba1_B.DataStoreRead6_ky = proba1_DWork.yKon;

      /* Sum: '<S129>/Add' */
      proba1_B.Add_cp = proba1_B.Xnastawy1_n + proba1_B.DataStoreRead6_ky;

      /* RelationalOperator: '<S133>/Compare' incorporates:
       *  Constant: '<S133>/Constant'
       */
      proba1_B.Compare_bm = (proba1_B.Add_cp > proba1_P.Constant_Value_ex);

      /* RelationalOperator: '<S132>/Compare' incorporates:
       *  Constant: '<S132>/Constant'
       */
      proba1_B.Compare_im = (proba1_B.Add_cp < proba1_P.Constant_Value_it);

      /* Logic: '<S129>/Logical Operator4' */
      proba1_B.LogicalOperator4_k = ((proba1_B.Compare_bm != 0U) &&
        (proba1_B.Compare_im != 0U));

      /* Switch: '<S126>/Switch4' */
      if (proba1_B.LogicalOperator4_k) {
        proba1_B.Switch4_g = proba1_B.Xnastawy1_n;
      } else {
        /* Switch: '<S126>/Switch5' incorporates:
         *  Constant: '<S126>/nieosiagalna'
         */
        if (proba1_B.LogicalOperator4_j) {
          proba1_B.Switch5_f = proba1_B.Xnastawy2_o;
        } else {
          proba1_B.Switch5_f = proba1_P.nieosiagalna_Value;
        }

        proba1_B.Switch4_g = proba1_B.Switch5_f;
      }

      /* end of Outputs for SubSystem: '<S120>/warunek na Fi' */

      /* RelationalOperator: '<S123>/Compare' incorporates:
       *  Constant: '<S123>/Constant'
       */
      proba1_B.Compare_jz = (proba1_B.fi_n <= proba1_P.Constant_Value_kv);

      /* Logic: '<S120>/Logical Operator1' */
      proba1_B.LogicalOperator1_e = ((proba1_B.Compare_bb != 0U) ||
        (proba1_B.Compare_jz != 0U));

      /* RelationalOperator: '<S124>/Compare' incorporates:
       *  Constant: '<S124>/Constant'
       */
      proba1_B.Compare_l = (proba1_B.Switch1_g >= proba1_P.Constant_Value_i4);

      /* RelationalOperator: '<S125>/Compare' incorporates:
       *  Constant: '<S125>/Constant'
       */
      proba1_B.Compare_bd = (proba1_B.Switch1_g <= proba1_P.Constant_Value_d1);

      /* Logic: '<S120>/Logical Operator2' */
      proba1_B.LogicalOperator2_i = ((proba1_B.Compare_l != 0U) ||
        (proba1_B.Compare_bd != 0U));

      /* Outputs for atomic SubSystem: '<S120>/warunek na R' */

      /* Switch: '<S127>/Switch1' incorporates:
       *  Constant: '<S127>/Rmax'
       *  Constant: '<S127>/Rmin'
       */
      if (proba1_B.Compare_bd != 0U) {
        proba1_B.Switch1_na = proba1_P.Rmin_Value;
      } else {
        proba1_B.Switch1_na = proba1_P.Rmax_Value;
      }

      /* Fcn: '<S127>/fi' */
      tmp = proba1_B.DataStoreRead_h;
      tmp_0 = proba1_B.Sum_oi;
      tmp_1 = proba1_B.Switch1_na;
      proba1_B.fi_k = acos(tmp / tmp_1) * rt_SGN(tmp_0);

      /* Gain: '<S127>/Gain' */
      tmp = proba1_B.Switch1_na;
      tmp_0 = proba1_B.fi_k;
      proba1_B.Gain_jp[0] = proba1_P.Gain_Gain_k * tmp;
      proba1_B.Gain_jp[1] = proba1_P.Gain_Gain_k * tmp_0;

      /* Fcn: '<S136>/Xgran' */
      proba1_B.Xgran_c = (-proba1_B.Gain_jp[0]) * sin(proba1_B.Gain_jp[1]);

      /* Fcn: '<S136>/Xgran1' */
      tmp_0 = proba1_B.Sum_oi;
      tmp_1 = proba1_B.Xgran_c;
      proba1_B.Xgran1_b = tmp_1 - tmp_0;

      /* Gain: '<S136>/Gain' */
      proba1_B.Gain_ik = proba1_P.Gain_Gain_gw * proba1_B.Xgran1_b;

      /* DataStoreRead: '<S134>/Data Store Read6' */
      proba1_B.DataStoreRead6_kz = proba1_DWork.yKon;

      /* Sum: '<S134>/Add' */
      proba1_B.Add_h = proba1_B.Gain_ik + proba1_B.DataStoreRead6_kz;

      /* RelationalOperator: '<S139>/Compare' incorporates:
       *  Constant: '<S139>/Constant'
       */
      proba1_B.Compare_lx = (proba1_B.Add_h > proba1_P.Constant_Value_bb);

      /* RelationalOperator: '<S138>/Compare' incorporates:
       *  Constant: '<S138>/Constant'
       */
      proba1_B.Compare_io = (proba1_B.Add_h < proba1_P.Constant_Value_ih);

      /* Logic: '<S134>/Logical Operator4' */
      proba1_B.LogicalOperator4_p = ((proba1_B.Compare_lx != 0U) &&
        (proba1_B.Compare_io != 0U));

      /* Fcn: '<S135>/Xgran' */
      tmp = proba1_B.Switch1_na;
      tmp_0 = proba1_B.fi_k;
      proba1_B.Xgran_d = tmp * sin(tmp_0);

      /* Fcn: '<S135>/Xgran1' */
      tmp_0 = proba1_B.Sum_oi;
      tmp_1 = proba1_B.Xgran_d;
      proba1_B.Xgran1_d = tmp_1 - tmp_0;

      /* Gain: '<S135>/Gain' */
      proba1_B.Gain_jk = proba1_P.Gain_Gain_b * proba1_B.Xgran1_d;

      /* RelationalOperator: '<S140>/Compare' incorporates:
       *  Constant: '<S140>/Constant'
       */
      proba1_B.Compare_a3 = (proba1_B.fi_k <= proba1_P.Constant_Value_av);

      /* RelationalOperator: '<S141>/Compare' incorporates:
       *  Constant: '<S141>/Constant'
       */
      proba1_B.Compare_f5 = (proba1_B.fi_k >= proba1_P.Constant_Value_k4);

      /* Logic: '<S135>/Logical Operator1' */
      proba1_B.LogicalOperator1_j = ((proba1_B.Compare_a3 != 0U) &&
        (proba1_B.Compare_f5 != 0U));

      /* RelationalOperator: '<S142>/Compare' incorporates:
       *  Constant: '<S142>/Constant'
       */
      tmp = proba1_B.Gain_jp[1];
      proba1_B.Compare_lh = (tmp <= proba1_P.Constant_Value_oh);

      /* RelationalOperator: '<S143>/Compare' incorporates:
       *  Constant: '<S143>/Constant'
       */
      tmp = proba1_B.Gain_jp[1];
      proba1_B.Compare_fz = (tmp >= proba1_P.Constant_Value_kue);

      /* Logic: '<S136>/Logical Operator1' */
      proba1_B.LogicalOperator1_m = ((proba1_B.Compare_lh != 0U) &&
        (proba1_B.Compare_fz != 0U));

      /* DataStoreRead: '<S137>/Data Store Read6' */
      proba1_B.DataStoreRead6_e = proba1_DWork.yKon;

      /* Sum: '<S137>/Add' */
      proba1_B.Add_o = proba1_B.Gain_jk + proba1_B.DataStoreRead6_e;

      /* RelationalOperator: '<S145>/Compare' incorporates:
       *  Constant: '<S145>/Constant'
       */
      proba1_B.Compare_bv = (proba1_B.Add_o > proba1_P.Constant_Value_kg);

      /* RelationalOperator: '<S144>/Compare' incorporates:
       *  Constant: '<S144>/Constant'
       */
      proba1_B.Compare_ae = (proba1_B.Add_o < proba1_P.Constant_Value_m3);

      /* Logic: '<S137>/Logical Operator4' */
      proba1_B.LogicalOperator4_a = ((proba1_B.Compare_bv != 0U) &&
        (proba1_B.Compare_ae != 0U));

      /* Switch: '<S127>/Switch4' */
      if (proba1_B.LogicalOperator4_a) {
        proba1_B.Switch4_m = proba1_B.Gain_jk;
      } else {
        /* Switch: '<S127>/Switch5' incorporates:
         *  Constant: '<S127>/nieosiagalna'
         */
        if (proba1_B.LogicalOperator4_p) {
          proba1_B.Switch5_k = proba1_B.Gain_ik;
        } else {
          proba1_B.Switch5_k = proba1_P.nieosiagalna_Value_a;
        }

        proba1_B.Switch4_m = proba1_B.Switch5_k;
      }

      /* Switch: '<S127>/Switch6' */
      if (proba1_B.LogicalOperator4_a) {
        proba1_B.Switch6_l = (real_T)proba1_B.LogicalOperator1_j;
      } else {
        /* Switch: '<S127>/Switch2' incorporates:
         *  Constant: '<S127>/nieosiagalna1'
         */
        if (proba1_B.LogicalOperator4_p) {
          proba1_B.Switch2_h = (real_T)proba1_B.LogicalOperator1_m;
        } else {
          proba1_B.Switch2_h = proba1_P.nieosiagalna1_Value;
        }

        proba1_B.Switch6_l = proba1_B.Switch2_h;
      }

      /* end of Outputs for SubSystem: '<S120>/warunek na R' */

      /* Logic: '<S120>/Logical Operator3' */
      proba1_B.LogicalOperator3_f = (proba1_B.LogicalOperator1_e &&
        proba1_B.LogicalOperator2_i);

      /* Logic: '<S120>/not1' */
      proba1_B.not1_h = !proba1_B.LogicalOperator3_f;

      /* Switch: '<S120>/Switch2' */
      if (proba1_B.not1_h) {
        /* Switch: '<S120>/Switch5' */
        if (proba1_B.LogicalOperator1_e) {
          /* Switch: '<S120>/Switch3' incorporates:
           *  Constant: '<S120>/ 1'
           */
          if (proba1_B.LogicalOperator1_e) {
            proba1_B.Switch3_o = proba1_B.Switch4_g;
          } else {
            proba1_B.Switch3_o = proba1_P.u_Value;
          }

          proba1_B.Switch5_h = proba1_B.Switch3_o;
        } else {
          /* Logic: '<S120>/not' */
          proba1_B.not_o = !proba1_B.LogicalOperator2_i;

          /* Switch: '<S120>/Switch4' incorporates:
           *  Constant: '<S120>/ '
           */
          if (proba1_B.not_o) {
            proba1_B.Switch4_p = proba1_P._Value;
          } else {
            proba1_B.Switch4_p = proba1_B.Switch4_m;
          }

          proba1_B.Switch5_h = proba1_B.Switch4_p;
        }

        proba1_B.Switch2_n = proba1_B.Switch5_h;
      } else {
        /* Switch: '<S120>/Switch6' */
        if (proba1_B.Switch6_l != 0.0) {
          proba1_B.Switch6_a = proba1_B.Switch4_m;
        } else {
          proba1_B.Switch6_a = proba1_B.Switch4_g;
        }

        proba1_B.Switch2_n = proba1_B.Switch6_a;
      }

      /* Sum: '<S101>/Add2' */
      proba1_B.Add2_o = proba1_B.DataStoreRead6_j5 + proba1_B.Switch2_n;

      /* Sum: '<S101>/Add1' */
      proba1_B.Add1_n = proba1_B.DataStoreRead2_k - proba1_B.Add2_o;

      /* Fcn: '<S101>/fi1' */
      tmp = proba1_B.DataStoreRead_h;
      tmp_0 = proba1_B.Add1_n;
      proba1_B.fi1_g = rt_atan2(tmp_0, tmp);

      /* Gain: '<S117>/Gain' */
      proba1_B.Gain_a0 = proba1_P.Gain_Gain_e * proba1_B.fi1_g;

      /* Fcn: '<S101>/fi2' */
      tmp = proba1_B.DataStoreRead_h;
      tmp_0 = proba1_B.Add1_n;
      tmp_1 = proba1_B.DataStoreRead1_jb;
      proba1_B.fi2_b = (1.57075 - rt_atan2(tmp_1 - 700.0, sqrt(pow(tmp, 2.0) +
        pow(tmp_0, 2.0)))) - acos(((((pow(450.0, 2.0) + pow(tmp, 2.0)) + pow
        (tmp_0, 2.0)) + pow(tmp_1 - 700.0, 2.0)) - pow(670.0, 2.0)) / (sqrt((pow
                                     (tmp, 2.0) + pow(tmp_0, 2.0)) + pow(tmp_1 -
        700.0, 2.0)) * 900.0));

      /* Gain: '<S118>/Gain' */
      proba1_B.Gain_m4 = proba1_P.Gain_Gain_a * proba1_B.fi2_b;

      /* Fcn: '<S101>/fi3' */
      tmp = proba1_B.DataStoreRead1_jb;
      tmp_1 = proba1_B.fi2_b;
      proba1_B.fi3_a = asin(((450.0 * cos(tmp_1) - tmp) + 700.0) / 670.0);

      /* Gain: '<S119>/Gain' */
      proba1_B.Gain_f = proba1_P.Gain_Gain_gh * proba1_B.fi3_a;

      /* RelationalOperator: '<S115>/Compare' incorporates:
       *  Constant: '<S115>/Constant'
       */
      proba1_B.Compare_kr = (proba1_B.DataStoreRead_h >=
        proba1_P.Constant_Value_hm);

      /* RelationalOperator: '<S116>/Compare' incorporates:
       *  Constant: '<S116>/Constant'
       */
      proba1_B.Compare_km = (proba1_B.DataStoreRead_h <=
        proba1_P.Constant_Value_aj);

      /* Fcn: '<S101>/ograniczenie' */
      tmp = proba1_B.DataStoreRead_h;
      tmp_0 = proba1_B.Add1_n;
      tmp_1 = proba1_B.DataStoreRead1_jb;
      proba1_B.ograniczenie_h = (pow(tmp_1 - 700.0, 2.0) + pow(tmp, 2.0)) + pow
        (tmp_0, 2.0);

      /* RelationalOperator: '<S107>/Compare' incorporates:
       *  Constant: '<S107>/Constant'
       */
      proba1_B.Compare_mr = (proba1_B.ograniczenie_h <=
        proba1_P.Constant_Value_kq);

      /* RelationalOperator: '<S108>/Compare' incorporates:
       *  Constant: '<S108>/Constant'
       */
      proba1_B.Compare_fr = (proba1_B.Gain_a0 >= proba1_P.Constant_Value_bw);

      /* RelationalOperator: '<S109>/Compare' incorporates:
       *  Constant: '<S109>/Constant'
       */
      proba1_B.Compare_jp = (proba1_B.Gain_a0 <= proba1_P.Constant_Value_g);

      /* RelationalOperator: '<S110>/Compare' incorporates:
       *  Constant: '<S110>/Constant'
       */
      proba1_B.Compare_b4 = (proba1_B.Gain_m4 >= proba1_P.Constant_Value_ky);

      /* RelationalOperator: '<S111>/Compare' incorporates:
       *  Constant: '<S111>/Constant'
       */
      proba1_B.Compare_mp = (proba1_B.Gain_m4 <= proba1_P.Constant_Value_iz);

      /* RelationalOperator: '<S112>/Compare' incorporates:
       *  Constant: '<S112>/Constant'
       */
      proba1_B.Compare_py = (proba1_B.Gain_f >= proba1_P.Constant_Value_on);

      /* RelationalOperator: '<S113>/Compare' incorporates:
       *  Constant: '<S113>/Constant'
       */
      proba1_B.Compare_ee = (proba1_B.Gain_f <= proba1_P.Constant_Value_n1);

      /* Sum: '<S101>/Add' */
      proba1_B.Add_c = proba1_B.Gain_m4 - proba1_B.Gain_f;

      /* Abs: '<S101>/Abs' */
      proba1_B.Abs_n = fabs(proba1_B.Add_c);

      /* RelationalOperator: '<S114>/Compare' incorporates:
       *  Constant: '<S114>/Constant'
       */
      proba1_B.Compare_cm = (proba1_B.Abs_n <= proba1_P.Constant_Value_ps);

      /* Logic: '<S101>/Logical Operator' */
      proba1_B.LogicalOperator_nh = (proba1_B.Compare_kr && proba1_B.Compare_km &&
        proba1_B.Compare_mr && proba1_B.Compare_fr && proba1_B.Compare_jp &&
        proba1_B.Compare_b4 && proba1_B.Compare_mp && proba1_B.Compare_py &&
        proba1_B.Compare_ee && proba1_B.Compare_cm);

      /* Outputs for enable SubSystem: '<S101>/podaj wyliczone wartosci' */
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
        /* DataStoreWrite: '<S121>/Data Store Write' */
        proba1_DWork.obliczoneFi1 = proba1_B.Gain_a0;

        /* DataStoreWrite: '<S121>/Data Store Write1' */
        proba1_DWork.obliczoneFi2 = proba1_B.Gain_m4;

        /* DataStoreWrite: '<S121>/Data Store Write2' */
        proba1_DWork.obliczoneFi3 = proba1_B.Gain_f;

        /* DataStoreWrite: '<S121>/Data Store Write3' */
        proba1_DWork.obliczoneDist = proba1_B.Switch2_n;
      }

      /* end of Outputs for SubSystem: '<S101>/podaj wyliczone wartosci' */
    }

    /* end of Outputs for SubSystem: '<S4>/kinematyka odwrotna' */
    if (rtmIsMajorTimeStep(proba1_M) &&
        proba1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Outputs for enable SubSystem: '<S4>/rozpoznawanie obrazu' */
      if (rtmIsMajorTimeStep(proba1_M) &&
          proba1_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(proba1_M)) {
          if (proba1_B.Compare > 0U) {
            if (proba1_DWork.rozpoznawanieobrazu_MODE == SUBSYS_DISABLED) {
              proba1_DWork.rozpoznawanieobrazu_MODE = SUBSYS_ENABLED;
            }
          } else if (proba1_DWork.rozpoznawanieobrazu_MODE == SUBSYS_ENABLED) {
            proba1_DWork.rozpoznawanieobrazu_MODE = SUBSYS_DISABLED;
          }
        }

        if (proba1_DWork.rozpoznawanieobrazu_MODE == SUBSYS_ENABLED) {
          /* DataStoreWrite: '<S103>/Data Store Write4' incorporates:
           *  Constant: '<S103>/obliczoneX'
           */
          proba1_DWork.ObliczoneX = proba1_P.obliczoneX_Value;

          /* DataStoreWrite: '<S103>/Data Store Write5' incorporates:
           *  Constant: '<S103>/obliczoneY'
           */
          proba1_DWork.ObliczoneY = proba1_P.obliczoneY_Value;

          /* DataStoreWrite: '<S103>/Data Store Write6' incorporates:
           *  Constant: '<S103>/obliczoneZ'
           */
          proba1_DWork.ObliczoneZ = proba1_P.obliczoneZ_Value;

          /* Constant: '<S103>/wlacz' */
          proba1_B.wlacz = proba1_P.wlacz_Value;
        }
      }

      /* end of Outputs for SubSystem: '<S4>/rozpoznawanie obrazu' */

      /* Outputs for enable and trigger SubSystem: '<S4>/kinematyka odwrotna1' */
      if (proba1_B.Compare > 0U) {
        if (proba1_DWork.kinematykaodwrotna1_MODE == SUBSYS_DISABLED) {
          proba1_DWork.kinematykaodwrotna1_MODE = SUBSYS_ENABLED;
        }

        if (rtmIsMajorTimeStep(proba1_M) && (rt_ZCFcn(RISING_ZERO_CROSSING,
              &proba1_PrevZCSigState.kinematykaodwrotna1_Trig_ZCE,
              (proba1_B.wlacz)) != NO_ZCEVENT)) {
          /* DataStoreRead: '<S102>/Data Store Read3' */
          proba1_B.DataStoreRead3_j = proba1_DWork.ObliczoneX;

          /* DataStoreRead: '<S102>/Data Store Read6' */
          proba1_B.DataStoreRead6 = proba1_DWork.yKon;

          /* DataStoreRead: '<S159>/Data Store Read6' */
          proba1_B.DataStoreRead6_k = proba1_DWork.yKon;

          /* DataStoreRead: '<S102>/Data Store Read5' */
          proba1_B.DataStoreRead5_o = proba1_DWork.ObliczoneY;

          /* Sum: '<S159>/Sum' */
          proba1_B.Sum_e = proba1_B.DataStoreRead5_o - proba1_B.DataStoreRead6_k;

          /* DataStoreRead: '<S102>/Data Store Read4' */
          proba1_B.DataStoreRead4_p = proba1_DWork.ObliczoneZ;

          /* Fcn: '<S159>/r' */
          tmp = proba1_B.DataStoreRead3_j;
          tmp_0 = proba1_B.Sum_e;
          proba1_B.r = sqrt(pow(tmp, 2.0) + pow(tmp_0, 2.0));

          /* Switch: '<S159>/Switch1' incorporates:
           *  Constant: '<S159>/Constant1'
           */
          if (proba1_B.r != 0.0) {
            proba1_B.Switch1 = proba1_B.r;
          } else {
            proba1_B.Switch1 = proba1_P.Constant1_Value_pi;
          }

          /* Fcn: '<S159>/fi' */
          tmp = proba1_B.DataStoreRead3_j;
          tmp_0 = proba1_B.Sum_e;
          tmp_1 = proba1_B.Switch1;
          proba1_B.fi = acos(tmp / tmp_1) * rt_SGN(tmp_0);

          /* RelationalOperator: '<S161>/Compare' incorporates:
           *  Constant: '<S161>/Constant'
           */
          proba1_B.Compare_d = (proba1_B.fi >= proba1_P.Constant_Value_ix);

          /* Outputs for atomic SubSystem: '<S159>/warunek na Fi' */

          /* Switch: '<S165>/Switch1' incorporates:
           *  Constant: '<S165>/FImax'
           *  Constant: '<S165>/FImin1'
           */
          if (proba1_B.Compare_d != 0U) {
            proba1_B.Switch1_n = proba1_P.FImax_Value_f;
          } else {
            proba1_B.Switch1_n = proba1_P.FImin1_Value_i;
          }

          /* Fcn: '<S165>/Xgran' */
          tmp = proba1_B.DataStoreRead3_j;
          tmp_1 = proba1_B.Switch1_n;
          proba1_B.Xgran_f = tmp * tan(tmp_1);

          /* Fcn: '<S165>/Xnastawy2' */
          tmp_0 = proba1_B.Sum_e;
          tmp_1 = proba1_B.Xgran_f;
          proba1_B.Xnastawy2 = tmp_0 + tmp_1;

          /* DataStoreRead: '<S167>/Data Store Read6' */
          proba1_B.DataStoreRead6_m = proba1_DWork.yKon;

          /* Sum: '<S167>/Add' */
          proba1_B.Add_k = proba1_B.Xnastawy2 + proba1_B.DataStoreRead6_m;

          /* RelationalOperator: '<S170>/Compare' incorporates:
           *  Constant: '<S170>/Constant'
           */
          proba1_B.Compare_f = (proba1_B.Add_k > proba1_P.Constant_Value_de);

          /* RelationalOperator: '<S169>/Compare' incorporates:
           *  Constant: '<S169>/Constant'
           */
          proba1_B.Compare_hb = (proba1_B.Add_k < proba1_P.Constant_Value_ft);

          /* Logic: '<S167>/Logical Operator4' */
          proba1_B.LogicalOperator4_h = ((proba1_B.Compare_f != 0U) &&
            (proba1_B.Compare_hb != 0U));

          /* Fcn: '<S165>/Xnastawy1' */
          tmp_0 = proba1_B.Sum_e;
          tmp_1 = proba1_B.Xgran_f;
          proba1_B.Xnastawy1 = tmp_0 - tmp_1;

          /* DataStoreRead: '<S168>/Data Store Read6' */
          proba1_B.DataStoreRead6_lg = proba1_DWork.yKon;

          /* Sum: '<S168>/Add' */
          proba1_B.Add_f = proba1_B.Xnastawy1 + proba1_B.DataStoreRead6_lg;

          /* RelationalOperator: '<S172>/Compare' incorporates:
           *  Constant: '<S172>/Constant'
           */
          proba1_B.Compare_gw = (proba1_B.Add_f > proba1_P.Constant_Value_p2);

          /* RelationalOperator: '<S171>/Compare' incorporates:
           *  Constant: '<S171>/Constant'
           */
          proba1_B.Compare_dd = (proba1_B.Add_f < proba1_P.Constant_Value_go);

          /* Logic: '<S168>/Logical Operator4' */
          proba1_B.LogicalOperator4_i = ((proba1_B.Compare_gw != 0U) &&
            (proba1_B.Compare_dd != 0U));

          /* Switch: '<S165>/Switch4' */
          if (proba1_B.LogicalOperator4_i) {
            proba1_B.Switch4_k = proba1_B.Xnastawy1;
          } else {
            /* Switch: '<S165>/Switch5' incorporates:
             *  Constant: '<S165>/nieosiagalna'
             */
            if (proba1_B.LogicalOperator4_h) {
              proba1_B.Switch5_b = proba1_B.Xnastawy2;
            } else {
              proba1_B.Switch5_b = proba1_P.nieosiagalna_Value_o;
            }

            proba1_B.Switch4_k = proba1_B.Switch5_b;
          }

          /* end of Outputs for SubSystem: '<S159>/warunek na Fi' */

          /* RelationalOperator: '<S162>/Compare' incorporates:
           *  Constant: '<S162>/Constant'
           */
          proba1_B.Compare_dt = (proba1_B.fi <= proba1_P.Constant_Value_ka);

          /* Logic: '<S159>/Logical Operator1' */
          proba1_B.LogicalOperator1 = ((proba1_B.Compare_d != 0U) ||
            (proba1_B.Compare_dt != 0U));

          /* RelationalOperator: '<S163>/Compare' incorporates:
           *  Constant: '<S163>/Constant'
           */
          proba1_B.Compare_j = (proba1_B.Switch1 >= proba1_P.Constant_Value_nx);

          /* RelationalOperator: '<S164>/Compare' incorporates:
           *  Constant: '<S164>/Constant'
           */
          proba1_B.Compare_b = (proba1_B.Switch1 <= proba1_P.Constant_Value_lc);

          /* Logic: '<S159>/Logical Operator2' */
          proba1_B.LogicalOperator2 = ((proba1_B.Compare_j != 0U) ||
            (proba1_B.Compare_b != 0U));

          /* Outputs for atomic SubSystem: '<S159>/warunek na R' */

          /* Switch: '<S166>/Switch1' incorporates:
           *  Constant: '<S166>/Rmax'
           *  Constant: '<S166>/Rmin'
           */
          if (proba1_B.Compare_b != 0U) {
            proba1_B.Switch1_j = proba1_P.Rmin_Value_f;
          } else {
            proba1_B.Switch1_j = proba1_P.Rmax_Value_i;
          }

          /* Fcn: '<S166>/fi' */
          tmp = proba1_B.DataStoreRead3_j;
          tmp_0 = proba1_B.Sum_e;
          tmp_1 = proba1_B.Switch1_j;
          proba1_B.fi_i = acos(tmp / tmp_1) * rt_SGN(tmp_0);

          /* Gain: '<S166>/Gain' */
          tmp = proba1_B.Switch1_j;
          tmp_0 = proba1_B.fi_i;
          proba1_B.Gain_m[0] = proba1_P.Gain_Gain_o * tmp;
          proba1_B.Gain_m[1] = proba1_P.Gain_Gain_o * tmp_0;

          /* Fcn: '<S175>/Xgran' */
          proba1_B.Xgran = (-proba1_B.Gain_m[0]) * sin(proba1_B.Gain_m[1]);

          /* Fcn: '<S175>/Xgran1' */
          tmp_0 = proba1_B.Sum_e;
          tmp_1 = proba1_B.Xgran;
          proba1_B.Xgran1 = tmp_1 - tmp_0;

          /* Gain: '<S175>/Gain' */
          proba1_B.Gain_a = proba1_P.Gain_Gain_fs * proba1_B.Xgran1;

          /* DataStoreRead: '<S173>/Data Store Read6' */
          proba1_B.DataStoreRead6_j = proba1_DWork.yKon;

          /* Sum: '<S173>/Add' */
          proba1_B.Add_m = proba1_B.Gain_a + proba1_B.DataStoreRead6_j;

          /* RelationalOperator: '<S178>/Compare' incorporates:
           *  Constant: '<S178>/Constant'
           */
          proba1_B.Compare_i = (proba1_B.Add_m > proba1_P.Constant_Value_kd);

          /* RelationalOperator: '<S177>/Compare' incorporates:
           *  Constant: '<S177>/Constant'
           */
          proba1_B.Compare_jq = (proba1_B.Add_m < proba1_P.Constant_Value_a4);

          /* Logic: '<S173>/Logical Operator4' */
          proba1_B.LogicalOperator4 = ((proba1_B.Compare_i != 0U) &&
            (proba1_B.Compare_jq != 0U));

          /* Fcn: '<S174>/Xgran' */
          tmp = proba1_B.Switch1_j;
          tmp_0 = proba1_B.fi_i;
          proba1_B.Xgran_k = tmp * sin(tmp_0);

          /* Fcn: '<S174>/Xgran1' */
          tmp_0 = proba1_B.Sum_e;
          tmp_1 = proba1_B.Xgran_k;
          proba1_B.Xgran1_g = tmp_1 - tmp_0;

          /* Gain: '<S174>/Gain' */
          proba1_B.Gain_ed = proba1_P.Gain_Gain_an * proba1_B.Xgran1_g;

          /* RelationalOperator: '<S179>/Compare' incorporates:
           *  Constant: '<S179>/Constant'
           */
          proba1_B.Compare_j4 = (proba1_B.fi_i <= proba1_P.Constant_Value_da);

          /* RelationalOperator: '<S180>/Compare' incorporates:
           *  Constant: '<S180>/Constant'
           */
          proba1_B.Compare_h = (proba1_B.fi_i >= proba1_P.Constant_Value_br);

          /* Logic: '<S174>/Logical Operator1' */
          proba1_B.LogicalOperator1_l = ((proba1_B.Compare_j4 != 0U) &&
            (proba1_B.Compare_h != 0U));

          /* RelationalOperator: '<S181>/Compare' incorporates:
           *  Constant: '<S181>/Constant'
           */
          tmp = proba1_B.Gain_m[1];
          proba1_B.Compare_a = (tmp <= proba1_P.Constant_Value_ajh);

          /* RelationalOperator: '<S182>/Compare' incorporates:
           *  Constant: '<S182>/Constant'
           */
          tmp = proba1_B.Gain_m[1];
          proba1_B.Compare_k = (tmp >= proba1_P.Constant_Value_cc);

          /* Logic: '<S175>/Logical Operator1' */
          proba1_B.LogicalOperator1_f = ((proba1_B.Compare_a != 0U) &&
            (proba1_B.Compare_k != 0U));

          /* DataStoreRead: '<S176>/Data Store Read6' */
          proba1_B.DataStoreRead6_l = proba1_DWork.yKon;

          /* Sum: '<S176>/Add' */
          proba1_B.Add_j = proba1_B.Gain_ed + proba1_B.DataStoreRead6_l;

          /* RelationalOperator: '<S184>/Compare' incorporates:
           *  Constant: '<S184>/Constant'
           */
          proba1_B.Compare_pf = (proba1_B.Add_j > proba1_P.Constant_Value_b0);

          /* RelationalOperator: '<S183>/Compare' incorporates:
           *  Constant: '<S183>/Constant'
           */
          proba1_B.Compare_ht = (proba1_B.Add_j < proba1_P.Constant_Value_cz);

          /* Logic: '<S176>/Logical Operator4' */
          proba1_B.LogicalOperator4_n = ((proba1_B.Compare_pf != 0U) &&
            (proba1_B.Compare_ht != 0U));

          /* Switch: '<S166>/Switch4' */
          if (proba1_B.LogicalOperator4_n) {
            proba1_B.Switch4 = proba1_B.Gain_ed;
          } else {
            /* Switch: '<S166>/Switch5' incorporates:
             *  Constant: '<S166>/nieosiagalna'
             */
            if (proba1_B.LogicalOperator4) {
              proba1_B.Switch5 = proba1_B.Gain_a;
            } else {
              proba1_B.Switch5 = proba1_P.nieosiagalna_Value_f;
            }

            proba1_B.Switch4 = proba1_B.Switch5;
          }

          /* Switch: '<S166>/Switch6' */
          if (proba1_B.LogicalOperator4_n) {
            proba1_B.Switch6 = (real_T)proba1_B.LogicalOperator1_l;
          } else {
            /* Switch: '<S166>/Switch2' incorporates:
             *  Constant: '<S166>/nieosiagalna1'
             */
            if (proba1_B.LogicalOperator4) {
              proba1_B.Switch2_a = (real_T)proba1_B.LogicalOperator1_f;
            } else {
              proba1_B.Switch2_a = proba1_P.nieosiagalna1_Value_o;
            }

            proba1_B.Switch6 = proba1_B.Switch2_a;
          }

          /* end of Outputs for SubSystem: '<S159>/warunek na R' */

          /* Logic: '<S159>/Logical Operator3' */
          proba1_B.LogicalOperator3 = (proba1_B.LogicalOperator1 &&
            proba1_B.LogicalOperator2);

          /* Logic: '<S159>/not1' */
          proba1_B.not1 = !proba1_B.LogicalOperator3;

          /* Switch: '<S159>/Switch2' */
          if (proba1_B.not1) {
            /* Switch: '<S159>/Switch5' */
            if (proba1_B.LogicalOperator1) {
              /* Switch: '<S159>/Switch3' incorporates:
               *  Constant: '<S159>/ 1'
               */
              if (proba1_B.LogicalOperator1) {
                proba1_B.Switch3 = proba1_B.Switch4_k;
              } else {
                proba1_B.Switch3 = proba1_P.u_Value_j;
              }

              proba1_B.Switch5_l = proba1_B.Switch3;
            } else {
              /* Logic: '<S159>/not' */
              proba1_B.not = !proba1_B.LogicalOperator2;

              /* Switch: '<S159>/Switch4' incorporates:
               *  Constant: '<S159>/ '
               */
              if (proba1_B.not) {
                proba1_B.Switch4_j = proba1_P._Value_l;
              } else {
                proba1_B.Switch4_j = proba1_B.Switch4;
              }

              proba1_B.Switch5_l = proba1_B.Switch4_j;
            }

            proba1_B.Switch2 = proba1_B.Switch5_l;
          } else {
            /* Switch: '<S159>/Switch6' */
            if (proba1_B.Switch6 != 0.0) {
              proba1_B.Switch6_h = proba1_B.Switch4;
            } else {
              proba1_B.Switch6_h = proba1_B.Switch4_k;
            }

            proba1_B.Switch2 = proba1_B.Switch6_h;
          }

          /* Sum: '<S102>/Add2' */
          proba1_B.Add2 = proba1_B.DataStoreRead6 + proba1_B.Switch2;

          /* Sum: '<S102>/Add1' */
          proba1_B.Add1 = proba1_B.DataStoreRead5_o - proba1_B.Add2;

          /* Fcn: '<S102>/fi1' */
          tmp = proba1_B.DataStoreRead3_j;
          tmp_0 = proba1_B.Add1;
          proba1_B.fi1 = rt_atan2(tmp_0, tmp);

          /* Gain: '<S156>/Gain' */
          proba1_B.Gain_i = proba1_P.Gain_Gain_bs * proba1_B.fi1;

          /* Fcn: '<S102>/fi2' */
          tmp = proba1_B.DataStoreRead3_j;
          tmp_0 = proba1_B.Add1;
          tmp_1 = proba1_B.DataStoreRead4_p;
          proba1_B.fi2 = (1.57075 - rt_atan2(tmp_1 - 700.0, sqrt(pow(tmp, 2.0) +
            pow(tmp_0, 2.0)))) - acos(((((pow(450.0, 2.0) + pow(tmp, 2.0)) + pow
            (tmp_0, 2.0)) + pow(tmp_1 - 700.0, 2.0)) - pow(670.0, 2.0)) / (sqrt
                                       ((pow(tmp, 2.0) + pow(tmp_0, 2.0)) + pow
            (tmp_1 - 700.0, 2.0)) * 900.0));

          /* Gain: '<S157>/Gain' */
          proba1_B.Gain_i1 = proba1_P.Gain_Gain_dc * proba1_B.fi2;

          /* Fcn: '<S102>/fi3' */
          tmp = proba1_B.DataStoreRead4_p;
          tmp_1 = proba1_B.fi2;
          proba1_B.fi3 = asin(((450.0 * cos(tmp_1) - tmp) + 700.0) / 670.0);

          /* Gain: '<S158>/Gain' */
          proba1_B.Gain_g = proba1_P.Gain_Gain_di * proba1_B.fi3;

          /* RelationalOperator: '<S154>/Compare' incorporates:
           *  Constant: '<S154>/Constant'
           */
          proba1_B.Compare_ly = (proba1_B.DataStoreRead3_j >=
            proba1_P.Constant_Value_ee);

          /* RelationalOperator: '<S155>/Compare' incorporates:
           *  Constant: '<S155>/Constant'
           */
          proba1_B.Compare_fy = (proba1_B.DataStoreRead3_j <=
            proba1_P.Constant_Value_jh);

          /* Fcn: '<S102>/ograniczenie' */
          tmp = proba1_B.DataStoreRead3_j;
          tmp_0 = proba1_B.Add1;
          tmp_1 = proba1_B.DataStoreRead4_p;
          proba1_B.ograniczenie = (pow(tmp_1 - 700.0, 2.0) + pow(tmp, 2.0)) +
            pow(tmp_0, 2.0);

          /* RelationalOperator: '<S146>/Compare' incorporates:
           *  Constant: '<S146>/Constant'
           */
          proba1_B.Compare_mk = (proba1_B.ograniczenie <=
            proba1_P.Constant_Value_hk);

          /* RelationalOperator: '<S147>/Compare' incorporates:
           *  Constant: '<S147>/Constant'
           */
          proba1_B.Compare_kj = (proba1_B.Gain_i >= proba1_P.Constant_Value_mx);

          /* RelationalOperator: '<S148>/Compare' incorporates:
           *  Constant: '<S148>/Constant'
           */
          proba1_B.Compare_i0 = (proba1_B.Gain_i <= proba1_P.Constant_Value_iw);

          /* RelationalOperator: '<S149>/Compare' incorporates:
           *  Constant: '<S149>/Constant'
           */
          proba1_B.Compare_o = (proba1_B.Gain_i1 >= proba1_P.Constant_Value_kvn);

          /* RelationalOperator: '<S150>/Compare' incorporates:
           *  Constant: '<S150>/Constant'
           */
          proba1_B.Compare_fe = (proba1_B.Gain_i1 <= proba1_P.Constant_Value_fr);

          /* RelationalOperator: '<S151>/Compare' incorporates:
           *  Constant: '<S151>/Constant'
           */
          proba1_B.Compare_j3 = (proba1_B.Gain_g >= proba1_P.Constant_Value_jl);

          /* RelationalOperator: '<S152>/Compare' incorporates:
           *  Constant: '<S152>/Constant'
           */
          proba1_B.Compare_mt = (proba1_B.Gain_g <= proba1_P.Constant_Value_cc1);

          /* Sum: '<S102>/Add' */
          proba1_B.Add = proba1_B.Gain_i1 - proba1_B.Gain_g;

          /* Abs: '<S102>/Abs' */
          proba1_B.Abs_i = fabs(proba1_B.Add);

          /* RelationalOperator: '<S153>/Compare' incorporates:
           *  Constant: '<S153>/Constant'
           */
          proba1_B.Compare_fk = (proba1_B.Abs_i <= proba1_P.Constant_Value_hq);

          /* Logic: '<S102>/Logical Operator' */
          proba1_B.LogicalOperator_m = (proba1_B.Compare_ly &&
            proba1_B.Compare_fy && proba1_B.Compare_mk && proba1_B.Compare_kj &&
            proba1_B.Compare_i0 && proba1_B.Compare_o && proba1_B.Compare_fe &&
            proba1_B.Compare_j3 && proba1_B.Compare_mt && proba1_B.Compare_fk);

          /* Outputs for enable SubSystem: '<S102>/podaj wyliczone wartosci' */
          if (proba1_B.LogicalOperator_m) {
            /* DataStoreWrite: '<S160>/Data Store Write' */
            proba1_DWork.obliczoneFi1 = proba1_B.Gain_i;

            /* DataStoreWrite: '<S160>/Data Store Write1' */
            proba1_DWork.obliczoneFi2 = proba1_B.Gain_i1;

            /* DataStoreWrite: '<S160>/Data Store Write2' */
            proba1_DWork.obliczoneFi3 = proba1_B.Gain_g;

            /* DataStoreWrite: '<S160>/Data Store Write3' */
            proba1_DWork.obliczoneDist = proba1_B.Switch2;
          }

          /* end of Outputs for SubSystem: '<S102>/podaj wyliczone wartosci' */
        }
      } else if (proba1_DWork.kinematykaodwrotna1_MODE == SUBSYS_ENABLED) {
        proba1_DWork.kinematykaodwrotna1_MODE = SUBSYS_DISABLED;
      }

      proba1_PrevZCSigState.kinematykaodwrotna1_Trig_ZCE = proba1_B.wlacz < 0.0 ?
        NEG_ZCSIG : proba1_B.wlacz > 0.0 ? POS_ZCSIG : ZERO_ZCSIG;

      /* end of Outputs for SubSystem: '<S4>/kinematyka odwrotna1' */

      /* RelationalOperator: '<S96>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S96>/Constant'
       */
      proba1_B.Compare_g = (proba1_P.wybortrybu_Value ==
                            proba1_P.Constant_Value_cw);

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
          /* DataStoreRead: '<S104>/Data Store Read' */
          proba1_B.DataStoreRead_j = proba1_DWork.tmp_u2;

          /* DataStoreWrite: '<S104>/Data Store Write1' */
          proba1_DWork.u2 = proba1_B.DataStoreRead_j;

          /* DataStoreRead: '<S104>/Data Store Read1' */
          proba1_B.DataStoreRead1_n = proba1_DWork.tmp_u3;

          /* DataStoreWrite: '<S104>/Data Store Write2' */
          proba1_DWork.u3 = proba1_B.DataStoreRead1_n;

          /* DataStoreRead: '<S104>/Data Store Read2' */
          proba1_B.DataStoreRead2_c = proba1_DWork.tmp_u1;

          /* DataStoreWrite: '<S104>/Data Store Write' */
          proba1_DWork.u1 = proba1_B.DataStoreRead2_c;

          /* DataStoreRead: '<S104>/Data Store Read3' */
          proba1_B.DataStoreRead3_n = proba1_DWork.tmp_u0;

          /* DataStoreWrite: '<S104>/Data Store Write3' */
          proba1_DWork.u0 = proba1_B.DataStoreRead3_n;

          /* DataStoreRead: '<S104>/Data Store Read4' */
          proba1_B.DataStoreRead4_a = proba1_DWork.tmp_u4;

          /* DataStoreWrite: '<S104>/Data Store Write4' */
          proba1_DWork.u4 = proba1_B.DataStoreRead4_a;

          /* DataStoreRead: '<S104>/Data Store Read5' */
          proba1_B.DataStoreRead5_n = proba1_DWork.tmp_u5;

          /* DataStoreWrite: '<S104>/Data Store Write5' */
          proba1_DWork.u5 = proba1_B.DataStoreRead5_n;
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
        &proba1_DWork.tmp_u0, &proba1_DWork.tmp_u1, &proba1_DWork.tmp_u2,
        &proba1_DWork.tmp_u3, &proba1_DWork.u0, &proba1_DWork.u1,
        &proba1_DWork.u2, &proba1_DWork.u3);

      /* end of Outputs for SubSystem: '<S4>/tryb kinematyki odwrotnej' */

      /* RelationalOperator: '<S97>/Compare' incorporates:
       *  Constant: '<S4>/wybor trybu'
       *  Constant: '<S97>/Constant'
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
          /* DataStoreRead: '<S106>/Data Store Read' */
          proba1_B.DataStoreRead_p = proba1_DWork.tmp_u2;

          /* DataStoreWrite: '<S106>/Data Store Write1' */
          proba1_DWork.u2 = proba1_B.DataStoreRead_p;

          /* DataStoreRead: '<S106>/Data Store Read1' */
          proba1_B.DataStoreRead1_an = proba1_DWork.tmp_u3;

          /* DataStoreWrite: '<S106>/Data Store Write2' */
          proba1_DWork.u3 = proba1_B.DataStoreRead1_an;

          /* DataStoreRead: '<S106>/Data Store Read2' */
          proba1_B.DataStoreRead2 = proba1_DWork.tmp_u1;

          /* DataStoreWrite: '<S106>/Data Store Write' */
          proba1_DWork.u1 = proba1_B.DataStoreRead2;

          /* DataStoreRead: '<S106>/Data Store Read3' */
          proba1_B.DataStoreRead3 = proba1_DWork.tmp_u4;

          /* DataStoreWrite: '<S106>/Data Store Write3' */
          proba1_DWork.u4 = proba1_B.DataStoreRead3;

          /* DataStoreRead: '<S106>/Data Store Read4' */
          proba1_B.DataStoreRead4 = proba1_DWork.tmp_u0;

          /* DataStoreWrite: '<S106>/Data Store Write4' */
          proba1_DWork.u0 = proba1_B.DataStoreRead4;

          /* DataStoreRead: '<S106>/Data Store Read5' */
          proba1_B.DataStoreRead5 = proba1_DWork.tmp_u5;

          /* DataStoreWrite: '<S106>/Data Store Write5' */
          proba1_DWork.u5 = proba1_B.DataStoreRead5;
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
    /* Update for Memory: '<S69>/Memory' */
    proba1_DWork.Memory_PreviousInput_o = proba1_B.Logic_p[0];

    /* Update for Memory: '<S65>/Memory' */
    proba1_DWork.Memory_PreviousInput_e = proba1_B.Product_n;
  }

  /* Derivative Block: '<S65>/Derivative' */
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
    /* Update for Memory: '<S65>/Memory1' */
    proba1_DWork.Memory1_PreviousInput_j = proba1_B.InitAngle_a;
  }

  /* Update for RateLimiter: '<S17>/Rate Limiter1' */
  proba1_DWork.PrevY_i = proba1_B.RateLimiter1;
  proba1_DWork.LastMajorTime_j = proba1_M->Timing.t[0];
  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S82>/Memory' */
    proba1_DWork.Memory_PreviousInput_co = proba1_B.Logic_a[0];

    /* Update for Memory: '<S78>/Memory' */
    proba1_DWork.Memory_PreviousInput_h = proba1_B.Product_o5;
  }

  /* Derivative Block: '<S78>/Derivative' */
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
    /* Update for Memory: '<S78>/Memory1' */
    proba1_DWork.Memory1_PreviousInput_n = proba1_B.InitAngle_f;
  }

  /* Update for RateLimiter: '<S18>/Rate Limiter1' */
  proba1_DWork.PrevY_eu = proba1_B.RateLimiter1_e;
  proba1_DWork.LastMajorTime_a = proba1_M->Timing.t[0];
  if (rtmIsMajorTimeStep(proba1_M) &&
      proba1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S92>/Memory' */
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

  /* ZeroPole Block: '<S66>/Analog Butterworth LP Filter' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CS_oj = proba1_B.SFunction2[2];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CS_oj +=
      (proba1_P.AnalogButterworthLPFilter_A_c)*
      proba1_X.AnalogButterworthLPFilter_CS_oj;
  }

  /* ZeroPole Block: '<S67>/Analog Butterworth LP Filter1' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_j = proba1_B.SFunction2[3];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter1_CS_j +=
      (proba1_P.AnalogButterworthLPFilter1_A_n)*
      proba1_X.AnalogButterworthLPFilter1_CS_j;
  }

  /* ZeroPole Block: '<S79>/Analog Butterworth LP Filter' */
  {
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_c = proba1_B.SFunction3[0];
    ((StateDerivatives_proba1 *) proba1_M->ModelData.derivs)
      ->AnalogButterworthLPFilter_CST_c +=
      (proba1_P.AnalogButterworthLPFilter_A_f)*
      proba1_X.AnalogButterworthLPFilter_CST_c;
  }

  /* ZeroPole Block: '<S80>/Analog Butterworth LP Filter1' */
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
    for (i = 0; i < 191; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&proba1_B.DataStoreRead_p);
    for (i = 0; i < 119; i++) {
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
    real_T *dwork_ptr = (real_T *) &proba1_DWork.Memory_PreviousInput;
    for (i = 0; i < 75; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  proba1_PrevZCSigState.trybwyzwalany_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.trybkinematykiodwrotnej.jedzdoprzedmiotu_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.kinematykaodwrotna1_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.jedzdoprzedmiotu.jedzdoprzedmiotu_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.blokstopu_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.DS3001ENC_RESET_B1_C1_Trig_ZCE = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.blokstopu_Trig_ZCE_k = UNINITIALIZED_ZCSIG;
  proba1_PrevZCSigState.blokstopu_Trig_ZCE_ke = UNINITIALIZED_ZCSIG;
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
  proba1_M->Sizes.numBlocks = (659);   /* Number of blocks */
  proba1_M->Sizes.numBlockIO = (403);  /* Number of block outputs */
  proba1_M->Sizes.numBlockPrms = (376);/* Sum of parameter "widths" */
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

  /* InitializeConditions for Memory: '<S69>/Memory' */
  proba1_DWork.Memory_PreviousInput_o = proba1_P.Memory_X0_c;

  /* InitializeConditions for Memory: '<S65>/Memory' */
  proba1_DWork.Memory_PreviousInput_e = proba1_P.Memory_X0_n;

  /* ZeroPole Block: '<S66>/Analog Butterworth LP Filter' */
  proba1_X.AnalogButterworthLPFilter_CS_oj = 0.0;

  /* ZeroPole Block: '<S67>/Analog Butterworth LP Filter1' */
  proba1_X.AnalogButterworthLPFilter1_CS_j = 0.0;

  /* Derivative Block: '<S65>/Derivative' */
  proba1_DWork.Derivative_RWORK_k.TimeStampA = rtInf;
  proba1_DWork.Derivative_RWORK_k.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<S65>/Memory1' */
  proba1_DWork.Memory1_PreviousInput_j = proba1_P.Memory1_X0_e;

  /* InitializeConditions for RateLimiter: '<S17>/Rate Limiter1' */
  proba1_DWork.LastMajorTime_j = rtInf;

  /* InitializeConditions for Memory: '<S82>/Memory' */
  proba1_DWork.Memory_PreviousInput_co = proba1_P.Memory_X0_a;

  /* InitializeConditions for Memory: '<S78>/Memory' */
  proba1_DWork.Memory_PreviousInput_h = proba1_P.Memory_X0_m;

  /* ZeroPole Block: '<S79>/Analog Butterworth LP Filter' */
  proba1_X.AnalogButterworthLPFilter_CST_c = 0.0;

  /* ZeroPole Block: '<S80>/Analog Butterworth LP Filter1' */
  proba1_X.AnalogButterworthLPFilter1_C_je = 0.0;

  /* Derivative Block: '<S78>/Derivative' */
  proba1_DWork.Derivative_RWORK_m.TimeStampA = rtInf;
  proba1_DWork.Derivative_RWORK_m.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<S78>/Memory1' */
  proba1_DWork.Memory1_PreviousInput_n = proba1_P.Memory1_X0_o;

  /* InitializeConditions for RateLimiter: '<S18>/Rate Limiter1' */
  proba1_DWork.LastMajorTime_a = rtInf;

  /* InitializeConditions for Memory: '<S92>/Memory' */
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

  /* Start for enable SubSystem: '<S61>/zerowanie' */
  proba1_DWork.zerowanie_MODE_g = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S61>/zerowanie' */

  /* Start for enable SubSystem: '<S74>/zerowanie' */
  proba1_DWork.zerowanie_MODE_m = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S74>/zerowanie' */

  /* Start for trigger SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */

  /* end of Start for SubSystem: '<S19>/DS3001ENC_RESET_B1_C1' */

  /* Start for enable SubSystem: '<S87>/zerowanie' */
  proba1_DWork.zerowanie_MODE_e = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S87>/zerowanie' */

  /* Start for enable SubSystem: '<S4>/kinematyka odwrotna' */
  proba1_DWork.kinematykaodwrotna_MODE = SUBSYS_DISABLED;

  /* Start for enable SubSystem: '<S101>/podaj wyliczone wartosci' */
  proba1_DWork.podajwyliczonewartosci_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S101>/podaj wyliczone wartosci' */

  /* end of Start for SubSystem: '<S4>/kinematyka odwrotna' */

  /* Start for enable SubSystem: '<S4>/rozpoznawanie obrazu' */
  proba1_DWork.rozpoznawanieobrazu_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S4>/rozpoznawanie obrazu' */

  /* Start for enable SubSystem: '<S4>/tryb ciagly' */
  proba1_DWork.trybciagly_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S4>/tryb ciagly' */

  /* Start for DataStoreMemory: '<Root>/obliczoneDist' */
  proba1_DWork.obliczoneDist = proba1_P.obliczoneDist_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneFi1' */
  proba1_DWork.obliczoneFi1 = proba1_P.obliczoneFi1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneFi2' */
  proba1_DWork.obliczoneFi2 = proba1_P.obliczoneFi2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneFi3' */
  proba1_DWork.obliczoneFi3 = proba1_P.obliczoneFi3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneFi4' */
  proba1_DWork.obliczoneFi4 = proba1_P.obliczoneFi4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneFi5' */
  proba1_DWork.obliczoneFi5 = proba1_P.obliczoneFi5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneX' */
  proba1_DWork.ObliczoneX = proba1_P.obliczoneX_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneY' */
  proba1_DWork.ObliczoneY = proba1_P.obliczoneY_InitialValue;

  /* Start for DataStoreMemory: '<Root>/obliczoneZ' */
  proba1_DWork.ObliczoneZ = proba1_P.obliczoneZ_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u0' */
  proba1_DWork.tmp_u0 = proba1_P.tmpu0_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u1' */
  proba1_DWork.tmp_u1 = proba1_P.tmpu1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u2' */
  proba1_DWork.tmp_u2 = proba1_P.tmpu2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u3' */
  proba1_DWork.tmp_u3 = proba1_P.tmpu3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u4' */
  proba1_DWork.tmp_u4 = proba1_P.tmpu4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/tmp u5' */
  proba1_DWork.tmp_u5 = proba1_P.tmpu5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u0' */
  proba1_DWork.u0 = proba1_P.u0_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u1' */
  proba1_DWork.u1 = proba1_P.u1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u2' */
  proba1_DWork.u2 = proba1_P.u2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u3' */
  proba1_DWork.u3 = proba1_P.u3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u4' */
  proba1_DWork.u4 = proba1_P.u4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/u5' */
  proba1_DWork.u5 = proba1_P.u5_InitialValue;

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
