/*
 * proba1.h
 *
 * Real-Time Workshop code generation for Simulink model "proba1.mdl".
 *
 * Model Version              : 1.350
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Thu Jul 10 14:13:41 2014
 */
#ifndef RTW_HEADER_proba1_h_
#define RTW_HEADER_proba1_h_
#ifndef proba1_COMMON_INCLUDES_
# define proba1_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <ds3001.h>
#include <ds2201.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rt_atan2.h"
#include "rtlibsrc.h"
#endif                                 /* proba1_COMMON_INCLUDES_ */

#include "proba1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define proba1_rtModel                 RT_MODEL_proba1

/* Block signals for system '<S4>/jedz do przedmiotu' */
typedef struct {
  real_T DataStoreRead;                /* '<S100>/Data Store Read' */
  real_T DataStoreRead1;               /* '<S100>/Data Store Read1' */
  real_T DataStoreRead2;               /* '<S100>/Data Store Read2' */
  real_T DataStoreRead3;               /* '<S100>/Data Store Read3' */
} rtB_jedzdoprzedmiotu_proba1;

/* Block states (auto storage) for system '<S4>/jedz do przedmiotu' */
typedef struct {
  int_T jedzdoprzedmiotu_MODE;         /* '<S4>/jedz do przedmiotu' */
} rtDW_jedzdoprzedmiotu_proba1;

/* Zero-crossing (trigger) state for system '<S4>/jedz do przedmiotu' */
typedef struct {
  ZCSigState jedzdoprzedmiotu_Trig_ZCE;/* '<S4>/jedz do przedmiotu' */
} rtZCE_jedzdoprzedmiotu_proba1;

/* Block signals (auto storage) */
typedef struct {
  real_T Memory;                       /* '<S26>/Memory' */
  real_T AnalogButterworthLPFilter;    /* '<S27>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1;   /* '<S28>/Analog Butterworth LP Filter1' */
  real_T Atan2;                        /* '<S26>/Atan2' */
  real_T Derivative;                   /* '<S26>/Derivative' */
  real_T DeadZone;                     /* '<S26>/Dead Zone' */
  real_T Saturation;                   /* '<S26>/Saturation' */
  real_T Sum;                          /* '<S26>/Sum' */
  real_T SFunction1;                   /* '<S29>/S-Function1' */
  real_T LogicalOperator;              /* '<S22>/Logical Operator' */
  real_T Memory_j;                     /* '<S30>/Memory' */
  real_T Logic[2];                     /* '<S30>/Logic' */
  real_T Product;                      /* '<S26>/Product' */
  real_T ConversionRotationtoAngle;    /* '<S26>/Conversion Rotation to Angle' */
  real_T Memory1;                      /* '<S26>/Memory1' */
  real_T InitAngle;                    /* '<S26>/Init Angle' */
  real_T Sum1;                         /* '<S26>/Sum1' */
  real_T Gear;                         /* '<S26>/Gear' */
  real_T ConversionRadtoDeg;           /* '<S26>/Conversion Rad to Deg' */
  real_T Gain1;                        /* '<S8>/Gain1' */
  real_T Memory_g;                     /* '<S39>/Memory' */
  real_T AnalogButterworthLPFilter_a;  /* '<S40>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_j; /* '<S41>/Analog Butterworth LP Filter1' */
  real_T Atan2_i;                      /* '<S39>/Atan2' */
  real_T Derivative_d;                 /* '<S39>/Derivative' */
  real_T DeadZone_l;                   /* '<S39>/Dead Zone' */
  real_T Saturation_o;                 /* '<S39>/Saturation' */
  real_T Sum_j;                        /* '<S39>/Sum' */
  real_T SFunction1_e;                 /* '<S42>/S-Function1' */
  real_T LogicalOperator_j;            /* '<S35>/Logical Operator' */
  real_T Memory_n;                     /* '<S43>/Memory' */
  real_T Logic_c[2];                   /* '<S43>/Logic' */
  real_T Product_a;                    /* '<S39>/Product' */
  real_T ConversionRotationtoAngle_j;  /* '<S39>/Conversion Rotation to Angle' */
  real_T Memory1_a;                    /* '<S39>/Memory1' */
  real_T InitAngle_d;                  /* '<S39>/Init Angle' */
  real_T Sum1_n;                       /* '<S39>/Sum1' */
  real_T Gear_m;                       /* '<S39>/Gear' */
  real_T ConversionRadtoDeg_l;         /* '<S39>/Conversion Rad to Deg' */
  real_T Gain1_m;                      /* '<S9>/Gain1' */
  real_T Memory_e;                     /* '<S52>/Memory' */
  real_T AnalogButterworthLPFilter_i;  /* '<S53>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_o; /* '<S54>/Analog Butterworth LP Filter1' */
  real_T Atan2_l;                      /* '<S52>/Atan2' */
  real_T Derivative_a;                 /* '<S52>/Derivative' */
  real_T DeadZone_j;                   /* '<S52>/Dead Zone' */
  real_T Saturation_e;                 /* '<S52>/Saturation' */
  real_T Sum_o;                        /* '<S52>/Sum' */
  real_T SFunction1_o;                 /* '<S55>/S-Function1' */
  real_T LogicalOperator_o;            /* '<S48>/Logical Operator' */
  real_T Memory_f;                     /* '<S56>/Memory' */
  real_T Logic_h[2];                   /* '<S56>/Logic' */
  real_T Product_o;                    /* '<S52>/Product' */
  real_T ConversionRotationtoAngle_o;  /* '<S52>/Conversion Rotation to Angle' */
  real_T Memory1_f;                    /* '<S52>/Memory1' */
  real_T InitAngle_j;                  /* '<S52>/Init Angle' */
  real_T Sum1_b;                       /* '<S52>/Sum1' */
  real_T Gear_g;                       /* '<S52>/Gear' */
  real_T ConversionRadtoDeg_n;         /* '<S52>/Conversion Rad to Deg' */
  real_T Gain1_p;                      /* '<S10>/Gain1' */
  real_T x;                            /* '<S2>/x' */
  real_T SFunction1_h;                 /* '<S13>/S-Function1' */
  real_T Fcn;                          /* '<S90>/Fcn' */
  real_T Gain2;                        /* '<S90>/Gain2' */
  real_T y;                            /* '<S2>/y' */
  real_T Sum_g;                        /* '<S2>/Sum' */
  real_T z;                            /* '<S2>/z' */
  real_T DataStoreRead;                /* '<S14>/Data Store Read' */
  real_T Switch;                       /* '<S24>/Switch' */
  real_T Sum_m;                        /* '<S14>/Sum' */
  real_T Gain;                         /* '<S14>/Gain' */
  real_T Saturation_d;                 /* '<S14>/Saturation' */
  real_T Gain_k;                       /* '<S3>/Gain' */
  real_T Saturation_f;                 /* '<S3>/Saturation' */
  real_T Abs;                          /* '<S20>/Abs' */
  real_T DataStoreRead_b;              /* '<S15>/Data Store Read' */
  real_T Switch_f;                     /* '<S37>/Switch' */
  real_T Sum1_h;                       /* '<S15>/Sum1' */
  real_T Abs1;                         /* '<S20>/Abs1' */
  real_T DataStoreRead1;               /* '<S16>/Data Store Read1' */
  real_T Switch_m;                     /* '<S50>/Switch' */
  real_T Sum1_m;                       /* '<S16>/Sum1' */
  real_T Abs2;                         /* '<S20>/Abs2' */
  real_T MinMax;                       /* '<S20>/MinMax' */
  real_T Divide;                       /* '<S20>/Divide' */
  real_T Saturation_p;                 /* '<S20>/Saturation' */
  real_T Product_f;                    /* '<S14>/Product' */
  real_T RateLimiter;                  /* '<S14>/Rate Limiter' */
  real_T Switch_c;                     /* '<S14>/Switch' */
  real_T Gain1_k;                      /* '<S14>/Gain1' */
  real_T Gain_j;                       /* '<S15>/Gain' */
  real_T Saturation_n;                 /* '<S15>/Saturation' */
  real_T Divide1;                      /* '<S20>/Divide1' */
  real_T Saturation1;                  /* '<S20>/Saturation1' */
  real_T Product_k;                    /* '<S15>/Product' */
  real_T RateLimiter_a;                /* '<S15>/Rate Limiter' */
  real_T Switch_b;                     /* '<S15>/Switch' */
  real_T Gain1_e;                      /* '<S15>/Gain1' */
  real_T Gain_e;                       /* '<S16>/Gain' */
  real_T Saturation_b;                 /* '<S16>/Saturation' */
  real_T Divide2;                      /* '<S20>/Divide2' */
  real_T Saturation2;                  /* '<S20>/Saturation2' */
  real_T Product_a0;                   /* '<S16>/Product' */
  real_T RateLimiter_m;                /* '<S16>/Rate Limiter' */
  real_T Switch_p;                     /* '<S16>/Switch' */
  real_T Gain1_i;                      /* '<S16>/Gain1' */
  real_T SFunction1_c;                 /* '<S68>/S-Function1' */
  real_T LogicalOperator_n;            /* '<S61>/Logical Operator' */
  real_T Memory_c;                     /* '<S69>/Memory' */
  real_T Logic_p[2];                   /* '<S69>/Logic' */
  real_T Memory_gz;                    /* '<S65>/Memory' */
  real_T AnalogButterworthLPFilter_k;  /* '<S66>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_c; /* '<S67>/Analog Butterworth LP Filter1' */
  real_T Atan2_b;                      /* '<S65>/Atan2' */
  real_T Derivative_f;                 /* '<S65>/Derivative' */
  real_T DeadZone_n;                   /* '<S65>/Dead Zone' */
  real_T Saturation_c;                 /* '<S65>/Saturation' */
  real_T Sum_c;                        /* '<S65>/Sum' */
  real_T Product_n;                    /* '<S65>/Product' */
  real_T ConversionRotationtoAngle_g;  /* '<S65>/Conversion Rotation to Angle' */
  real_T Memory1_k;                    /* '<S65>/Memory1' */
  real_T InitAngle_a;                  /* '<S65>/Init Angle' */
  real_T Sum1_d;                       /* '<S65>/Sum1' */
  real_T Gear_k;                       /* '<S65>/Gear' */
  real_T ConversionRadtoDeg_j;         /* '<S65>/Conversion Rad to Deg' */
  real_T DataStoreRead1_a;             /* '<S17>/Data Store Read1' */
  real_T Switch_pm;                    /* '<S63>/Switch' */
  real_T Sum1_nk;                      /* '<S17>/Sum1' */
  real_T Gain2_d;                      /* '<S17>/Gain2' */
  real_T Saturation1_i;                /* '<S17>/Saturation1' */
  real_T Product_fe;                   /* '<S17>/Product' */
  real_T RateLimiter1;                 /* '<S17>/Rate Limiter1' */
  real_T Switch_e;                     /* '<S17>/Switch' */
  real_T Gain3;                        /* '<S17>/Gain3' */
  real_T SFunction1_b;                 /* '<S81>/S-Function1' */
  real_T LogicalOperator_c;            /* '<S74>/Logical Operator' */
  real_T Memory_c1;                    /* '<S82>/Memory' */
  real_T Logic_a[2];                   /* '<S82>/Logic' */
  real_T Memory_j5;                    /* '<S78>/Memory' */
  real_T AnalogButterworthLPFilter_c;  /* '<S79>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_n; /* '<S80>/Analog Butterworth LP Filter1' */
  real_T Atan2_j;                      /* '<S78>/Atan2' */
  real_T Derivative_g;                 /* '<S78>/Derivative' */
  real_T DeadZone_o;                   /* '<S78>/Dead Zone' */
  real_T Saturation_a;                 /* '<S78>/Saturation' */
  real_T Sum_mv;                       /* '<S78>/Sum' */
  real_T Product_o5;                   /* '<S78>/Product' */
  real_T ConversionRotationtoAngle_e;  /* '<S78>/Conversion Rotation to Angle' */
  real_T Memory1_fx;                   /* '<S78>/Memory1' */
  real_T InitAngle_f;                  /* '<S78>/Init Angle' */
  real_T Sum1_f;                       /* '<S78>/Sum1' */
  real_T Gear_l;                       /* '<S78>/Gear' */
  real_T ConversionRadtoDeg_h;         /* '<S78>/Conversion Rad to Deg' */
  real_T DataStoreRead1_j;             /* '<S18>/Data Store Read1' */
  real_T Switch_my;                    /* '<S76>/Switch' */
  real_T Sum1_f3;                      /* '<S18>/Sum1' */
  real_T Gain2_p;                      /* '<S18>/Gain2' */
  real_T Saturation1_m;                /* '<S18>/Saturation1' */
  real_T Product_e;                    /* '<S18>/Product' */
  real_T RateLimiter1_e;               /* '<S18>/Rate Limiter1' */
  real_T Switch_en;                    /* '<S18>/Switch' */
  real_T Gain3_o;                      /* '<S18>/Gain3' */
  real_T SFunction1_i;                 /* '<S91>/S-Function1' */
  real_T LogicalOperator_nv;           /* '<S87>/Logical Operator' */
  real_T Memory_jn;                    /* '<S92>/Memory' */
  real_T Logic_he[2];                  /* '<S92>/Logic' */
  real_T DataStoreRead1_m;             /* '<S19>/Data Store Read1' */
  real_T Switch_h;                     /* '<S89>/Switch' */
  real_T Sum1_d2;                      /* '<S19>/Sum1' */
  real_T Gain_c;                       /* '<S19>/Gain' */
  real_T Saturation_i;                 /* '<S19>/Saturation' */
  real_T Product_ey;                   /* '<S19>/Product' */
  real_T RateLimiter_p;                /* '<S19>/Rate Limiter' */
  real_T Switch_hv;                    /* '<S19>/Switch' */
  real_T Gain1_h;                      /* '<S19>/Gain1' */
  real_T SFunction1_j[4];              /* '<S11>/S-Function1' */
  real_T SFunction2[4];                /* '<S11>/S-Function2' */
  real_T SFunction3[2];                /* '<S11>/S-Function3' */
  real_T DataStoreRead_p;              /* '<S105>/Data Store Read' */
  real_T DataStoreRead1_an;            /* '<S105>/Data Store Read1' */
  real_T DataStoreRead2;               /* '<S105>/Data Store Read2' */
  real_T DataStoreRead3;               /* '<S105>/Data Store Read3' */
  real_T DataStoreRead4;               /* '<S105>/Data Store Read4' */
  real_T DataStoreRead5;               /* '<S105>/Data Store Read5' */
  real_T DataStoreRead_j;              /* '<S103>/Data Store Read' */
  real_T DataStoreRead1_n;             /* '<S103>/Data Store Read1' */
  real_T DataStoreRead2_c;             /* '<S103>/Data Store Read2' */
  real_T DataStoreRead3_n;             /* '<S103>/Data Store Read3' */
  real_T DataStoreRead4_a;             /* '<S103>/Data Store Read4' */
  real_T DataStoreRead5_n;             /* '<S103>/Data Store Read5' */
  real_T Uk1;                          /* '<S118>/Delay Input1' */
  real_T Uk1_o;                        /* '<S119>/Delay Input1' */
  real_T Uk1_d;                        /* '<S120>/Delay Input1' */
  real_T x_a;                          /* '<S102>/Embedded MATLAB Function' */
  real_T y_k;                          /* '<S102>/Embedded MATLAB Function' */
  real_T z_m;                          /* '<S102>/Embedded MATLAB Function' */
  real_T DataStoreRead_h;              /* '<S101>/Data Store Read' */
  real_T DataStoreRead2_k;             /* '<S101>/Data Store Read2' */
  real_T DataStoreRead1_jb;            /* '<S101>/Data Store Read1' */
  real_T DataStoreRead3_a;             /* '<S101>/Data Store Read3' */
  real_T DataStoreRead5_p;             /* '<S101>/Data Store Read5' */
  real_T DataStoreRead4_i;             /* '<S101>/Data Store Read4' */
  real_T Switch_g[3];                  /* '<S101>/Switch' */
  real_T fi1;                          /* '<S101>/fi1' */
  real_T Gain_a;                       /* '<S114>/Gain' */
  real_T fi2;                          /* '<S101>/fi2' */
  real_T Gain_m;                       /* '<S115>/Gain' */
  real_T fi3;                          /* '<S101>/fi3' */
  real_T Gain_f;                       /* '<S116>/Gain' */
  real_T ograniczenie;                 /* '<S101>/ograniczenie' */
  real_T Add;                          /* '<S101>/Add' */
  real_T Abs_n;                        /* '<S101>/Abs' */
  uint8_T Compare;                     /* '<S99>/Compare' */
  uint8_T Compare_p;                   /* '<S98>/Compare' */
  uint8_T Compare_g;                   /* '<S96>/Compare' */
  uint8_T Compare_gt;                  /* '<S97>/Compare' */
  uint8_T FixPtRelationalOperator;     /* '<S118>/FixPt Relational Operator' */
  uint8_T FixPtRelationalOperator_c;   /* '<S119>/FixPt Relational Operator' */
  uint8_T FixPtRelationalOperator_m;   /* '<S120>/FixPt Relational Operator' */
  boolean_T Compare_j;                 /* '<S33>/Compare' */
  boolean_T Compare_e;                 /* '<S32>/Compare' */
  boolean_T LogicalOperator_a;         /* '<S24>/Logical Operator' */
  boolean_T Compare_m;                 /* '<S46>/Compare' */
  boolean_T Compare_d;                 /* '<S45>/Compare' */
  boolean_T LogicalOperator_ad;        /* '<S37>/Logical Operator' */
  boolean_T Compare_pa;                /* '<S59>/Compare' */
  boolean_T Compare_c;                 /* '<S58>/Compare' */
  boolean_T LogicalOperator_o1;        /* '<S50>/Logical Operator' */
  boolean_T Compare_ds;                /* '<S72>/Compare' */
  boolean_T Compare_a;                 /* '<S71>/Compare' */
  boolean_T LogicalOperator_h;         /* '<S63>/Logical Operator' */
  boolean_T Compare_pd;                /* '<S85>/Compare' */
  boolean_T Compare_eo;                /* '<S84>/Compare' */
  boolean_T LogicalOperator_l;         /* '<S76>/Logical Operator' */
  boolean_T Compare_h;                 /* '<S95>/Compare' */
  boolean_T Compare_gk;                /* '<S94>/Compare' */
  boolean_T LogicalOperator_oc;        /* '<S89>/Logical Operator' */
  boolean_T LogicalOperator_nz;        /* '<S4>/Logical Operator' */
  boolean_T LogicalOperator_d;         /* '<S102>/Logical Operator' */
  boolean_T Compare_mr;                /* '<S106>/Compare' */
  boolean_T Compare_f;                 /* '<S107>/Compare' */
  boolean_T Compare_jp;                /* '<S108>/Compare' */
  boolean_T Compare_b;                 /* '<S109>/Compare' */
  boolean_T Compare_mp;                /* '<S110>/Compare' */
  boolean_T Compare_py;                /* '<S111>/Compare' */
  boolean_T Compare_ee;                /* '<S112>/Compare' */
  boolean_T Compare_cm;                /* '<S113>/Compare' */
  boolean_T LogicalOperator_nh;        /* '<S101>/Logical Operator' */
  rtB_jedzdoprzedmiotu_proba1 trybkinematykiodwrotnej;/* '<S4>/tryb kinematyki odwrotnej' */
  rtB_jedzdoprzedmiotu_proba1 jedzdoprzedmiotu;/* '<S4>/jedz do przedmiotu' */
} BlockIO_proba1;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S118>/Delay Input1' */
  real_T DelayInput1_DSTATE_g;         /* '<S119>/Delay Input1' */
  real_T DelayInput1_DSTATE_m;         /* '<S120>/Delay Input1' */
  real_T Memory_PreviousInput;         /* '<S26>/Memory' */
  real_T Memory_PreviousInput_c;       /* '<S30>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S26>/Memory1' */
  real_T Memory_PreviousInput_g;       /* '<S39>/Memory' */
  real_T Memory_PreviousInput_f;       /* '<S43>/Memory' */
  real_T Memory1_PreviousInput_g;      /* '<S39>/Memory1' */
  real_T Memory_PreviousInput_b;       /* '<S52>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S56>/Memory' */
  real_T Memory1_PreviousInput_d;      /* '<S52>/Memory1' */
  real_T PrevY;                        /* '<S14>/Rate Limiter' */
  real_T LastMajorTime;                /* '<S14>/Rate Limiter' */
  real_T PrevY_p;                      /* '<S15>/Rate Limiter' */
  real_T LastMajorTime_h;              /* '<S15>/Rate Limiter' */
  real_T PrevY_e;                      /* '<S16>/Rate Limiter' */
  real_T LastMajorTime_hr;             /* '<S16>/Rate Limiter' */
  real_T Memory_PreviousInput_o;       /* '<S69>/Memory' */
  real_T Memory_PreviousInput_e;       /* '<S65>/Memory' */
  real_T Memory1_PreviousInput_j;      /* '<S65>/Memory1' */
  real_T PrevY_i;                      /* '<S17>/Rate Limiter1' */
  real_T LastMajorTime_j;              /* '<S17>/Rate Limiter1' */
  real_T Memory_PreviousInput_co;      /* '<S82>/Memory' */
  real_T Memory_PreviousInput_h;       /* '<S78>/Memory' */
  real_T Memory1_PreviousInput_n;      /* '<S78>/Memory1' */
  real_T PrevY_eu;                     /* '<S18>/Rate Limiter1' */
  real_T LastMajorTime_a;              /* '<S18>/Rate Limiter1' */
  real_T Memory_PreviousInput_k;       /* '<S92>/Memory' */
  real_T PrevY_g;                      /* '<S19>/Rate Limiter' */
  real_T LastMajorTime_d;              /* '<S19>/Rate Limiter' */
  real_T A;                            /* '<Root>/Data Store Memory' */
  real_T obliczoneDist;                /* '<Root>/obliczoneDist' */
  real_T obliczoneFi1;                 /* '<Root>/obliczoneFi1' */
  real_T obliczoneFi2;                 /* '<Root>/obliczoneFi2' */
  real_T obliczoneFi3;                 /* '<Root>/obliczoneFi3' */
  real_T obliczoneFi4;                 /* '<Root>/obliczoneFi4' */
  real_T obliczoneFi5;                 /* '<Root>/obliczoneFi5' */
  real_T ObliczoneX;                   /* '<Root>/obliczoneX' */
  real_T ObliczoneY;                   /* '<Root>/obliczoneY' */
  real_T ObliczoneZ;                   /* '<Root>/obliczoneZ' */
  real_T tmp_u0;                       /* '<Root>/tmp u0' */
  real_T tmp_u1;                       /* '<Root>/tmp u1' */
  real_T tmp_u2;                       /* '<Root>/tmp u2' */
  real_T tmp_u3;                       /* '<Root>/tmp u3' */
  real_T tmp_u4;                       /* '<Root>/tmp u4' */
  real_T tmp_u5;                       /* '<Root>/tmp u5' */
  real_T u0;                           /* '<Root>/u0' */
  real_T u1;                           /* '<Root>/u1' */
  real_T u2;                           /* '<Root>/u2' */
  real_T u3;                           /* '<Root>/u3' */
  real_T u4;                           /* '<Root>/u4' */
  real_T u5;                           /* '<Root>/u5' */
  real_T xKon;                         /* '<Root>/xKon' */
  real_T yKon;                         /* '<Root>/yKon' */
  real_T zKon;                         /* '<Root>/zKon' */
  real_T zadaneX;                      /* '<Root>/zadaneX' */
  real_T zadaneY;                      /* '<Root>/zadaneY' */
  real_T zadaneZ;                      /* '<Root>/zadaneZ' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S26>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_p;                /* '<S39>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_c;                /* '<S52>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_k;                /* '<S65>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_m;                /* '<S78>/Derivative' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S3>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S102>/Scope' */

  int_T zerowanie_MODE;                /* '<S22>/zerowanie' */
  int_T zerowanie_MODE_l;              /* '<S35>/zerowanie' */
  int_T zerowanie_MODE_k;              /* '<S48>/zerowanie' */
  int_T zerowanie_MODE_g;              /* '<S61>/zerowanie' */
  int_T zerowanie_MODE_m;              /* '<S74>/zerowanie' */
  int_T zerowanie_MODE_e;              /* '<S87>/zerowanie' */
  int_T rozpoznawanieobrazu_MODE;      /* '<S4>/rozpoznawanie obrazu' */
  int_T kinematykaodwrotna_MODE;       /* '<S4>/kinematyka odwrotna' */
  int_T trybciagly_MODE;               /* '<S4>/tryb ciagly' */
  int_T trybwyzwalany_MODE;            /* '<S4>/tryb wyzwalany' */
  int_T podajwyliczonewartosci_MODE;   /* '<S101>/podaj wyliczone wartosci' */
  rtDW_jedzdoprzedmiotu_proba1 trybkinematykiodwrotnej;/* '<S4>/tryb kinematyki odwrotnej' */
  rtDW_jedzdoprzedmiotu_proba1 jedzdoprzedmiotu;/* '<S4>/jedz do przedmiotu' */
} D_Work_proba1;

/* Continuous states (auto storage) */
typedef struct {
  real_T AnalogButterworthLPFilter_CSTAT;/* '<S27>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CSTA;/* '<S28>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CST_f;/* '<S40>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CS_c;/* '<S41>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CST_o;/* '<S53>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CS_b;/* '<S54>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CS_oj;/* '<S66>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CS_j;/* '<S67>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CST_c;/* '<S79>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_C_je;/* '<S80>/Analog Butterworth LP Filter1' */
} ContinuousStates_proba1;

/* State derivatives (auto storage) */
typedef struct {
  real_T AnalogButterworthLPFilter_CSTAT;/* '<S27>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CSTA;/* '<S28>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CST_f;/* '<S40>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CS_c;/* '<S41>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CST_o;/* '<S53>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CS_b;/* '<S54>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CS_oj;/* '<S66>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_CS_j;/* '<S67>/Analog Butterworth LP Filter1' */
  real_T AnalogButterworthLPFilter_CST_c;/* '<S79>/Analog Butterworth LP Filter' */
  real_T AnalogButterworthLPFilter1_C_je;/* '<S80>/Analog Butterworth LP Filter1' */
} StateDerivatives_proba1;

/* State disabled  */
typedef struct {
  boolean_T AnalogButterworthLPFilter_CSTAT;/* '<S27>/Analog Butterworth LP Filter' */
  boolean_T AnalogButterworthLPFilter1_CSTA;/* '<S28>/Analog Butterworth LP Filter1' */
  boolean_T AnalogButterworthLPFilter_CST_f;/* '<S40>/Analog Butterworth LP Filter' */
  boolean_T AnalogButterworthLPFilter1_CS_c;/* '<S41>/Analog Butterworth LP Filter1' */
  boolean_T AnalogButterworthLPFilter_CST_o;/* '<S53>/Analog Butterworth LP Filter' */
  boolean_T AnalogButterworthLPFilter1_CS_b;/* '<S54>/Analog Butterworth LP Filter1' */
  boolean_T AnalogButterworthLPFilter_CS_oj;/* '<S66>/Analog Butterworth LP Filter' */
  boolean_T AnalogButterworthLPFilter1_CS_j;/* '<S67>/Analog Butterworth LP Filter1' */
  boolean_T AnalogButterworthLPFilter_CST_c;/* '<S79>/Analog Butterworth LP Filter' */
  boolean_T AnalogButterworthLPFilter1_C_je;/* '<S80>/Analog Butterworth LP Filter1' */
} StateDisabled_proba1;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState trybwyzwalany_Trig_ZCE;   /* '<S4>/tryb wyzwalany' */
  rtZCE_jedzdoprzedmiotu_proba1 trybkinematykiodwrotnej;/* '<S4>/jedz do przedmiotu' */
  ZCSigState rozpoznawanieobrazu_Trig_ZCE;/* '<S4>/rozpoznawanie obrazu' */
  rtZCE_jedzdoprzedmiotu_proba1 jedzdoprzedmiotu;/* '<S4>/jedz do przedmiotu' */
  ZCSigState blokstopu_Trig_ZCE;       /* '<S19>/blok stopu' */
  ZCSigState DS3001ENC_RESET_B1_C1_Trig_ZCE;/* '<S19>/DS3001ENC_RESET_B1_C1' */
  ZCSigState blokstopu_Trig_ZCE_k;     /* '<S18>/blok stopu' */
  ZCSigState blokstopu_Trig_ZCE_ke;    /* '<S17>/blok stopu' */
  ZCSigState blokstopu_Trig_ZCE_b;     /* '<S16>/blok stopu' */
  ZCSigState blokstopu_Trig_ZCE_p;     /* '<S15>/blok stopu' */
  ZCSigState blokstopu_Trig_ZCE_f;     /* '<S14>/blok stopu' */
} PrevZCSigStates_proba1;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            proba1_B
#define BlockIO                        BlockIO_proba1
#define rtX                            proba1_X
#define ContinuousStates               ContinuousStates_proba1
#define rtP                            proba1_P
#define Parameters                     Parameters_proba1
#define rtDWork                        proba1_DWork
#define D_Work                         D_Work_proba1
#define rtPrevZCSigState               proba1_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_proba1

/* Parameters (auto storage) */
struct Parameters_proba1 {
  real_T Memory_X0;                    /* Expression: 0
                                        * '<S26>/Memory'
                                        */
  real_T AnalogButterworthLPFilter_A;  /* Computed Parameter: A
                                        * '<S27>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter_C;  /* Computed Parameter: C
                                        * '<S27>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter1_A; /* Computed Parameter: A
                                        * '<S28>/Analog Butterworth LP Filter1'
                                        */
  real_T AnalogButterworthLPFilter1_C; /* Computed Parameter: C
                                        * '<S28>/Analog Butterworth LP Filter1'
                                        */
  real_T DeadZone_Start;               /* Expression: -5000
                                        * '<S26>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 5000
                                        * '<S26>/Dead Zone'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * '<S26>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * '<S26>/Saturation'
                                        */
  real_T przyciskbazowania_Value;      /* Expression: 0
                                        * '<S3>/przycisk bazowania'
                                        */
  real_T przyciskstopu_Value;          /* Expression: 0
                                        * '<S3>/przycisk stopu'
                                        */
  real_T Memory_X0_d;                  /* Expression: initial_condition
                                        * '<S30>/Memory'
                                        */
  real_T Logic_table[16];              /* Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0]
                                        * '<S30>/Logic'
                                        */
  real_T ConversionRotationtoAngle_Gain;/* Expression: 2*pi
                                         * '<S26>/Conversion Rotation to Angle'
                                         */
  real_T Memory1_X0;                   /* Expression: 0
                                        * '<S26>/Memory1'
                                        */
  real_T InitAngle_Threshold;          /* Expression: 1
                                        * '<S26>/Init Angle'
                                        */
  real_T Gear_Gain;                    /* Expression: 6.33e-3
                                        * '<S26>/Gear'
                                        */
  real_T ConversionRadtoDeg_Gain;      /* Expression: 180/pi
                                        * '<S26>/Conversion Rad to Deg'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * '<S8>/Gain1'
                                        */
  real_T Memory_X0_e;                  /* Expression: 0
                                        * '<S39>/Memory'
                                        */
  real_T AnalogButterworthLPFilter_A_g;/* Computed Parameter: A
                                        * '<S40>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter_C_c;/* Computed Parameter: C
                                        * '<S40>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter1_A_k;/* Computed Parameter: A
                                         * '<S41>/Analog Butterworth LP Filter1'
                                         */
  real_T AnalogButterworthLPFilter1_C_n;/* Computed Parameter: C
                                         * '<S41>/Analog Butterworth LP Filter1'
                                         */
  real_T DeadZone_Start_i;             /* Expression: -5000
                                        * '<S39>/Dead Zone'
                                        */
  real_T DeadZone_End_l;               /* Expression: 5000
                                        * '<S39>/Dead Zone'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1
                                        * '<S39>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: -1
                                        * '<S39>/Saturation'
                                        */
  real_T Memory_X0_g;                  /* Expression: initial_condition
                                        * '<S43>/Memory'
                                        */
  real_T Logic_table_i[16];            /* Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0]
                                        * '<S43>/Logic'
                                        */
  real_T ConversionRotationtoAngle_Gai_b;/* Expression: 2*pi
                                          * '<S39>/Conversion Rotation to Angle'
                                          */
  real_T Memory1_X0_i;                 /* Expression: 0
                                        * '<S39>/Memory1'
                                        */
  real_T InitAngle_Threshold_j;        /* Expression: 1
                                        * '<S39>/Init Angle'
                                        */
  real_T Gear_Gain_n;                  /* Expression: 6.37e-3
                                        * '<S39>/Gear'
                                        */
  real_T ConversionRadtoDeg_Gain_g;    /* Expression: 180/pi
                                        * '<S39>/Conversion Rad to Deg'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: pi/180
                                        * '<S9>/Gain1'
                                        */
  real_T Memory_X0_dp;                 /* Expression: 0
                                        * '<S52>/Memory'
                                        */
  real_T AnalogButterworthLPFilter_A_a;/* Computed Parameter: A
                                        * '<S53>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter_C_cb;/* Computed Parameter: C
                                         * '<S53>/Analog Butterworth LP Filter'
                                         */
  real_T AnalogButterworthLPFilter1_A_o;/* Computed Parameter: A
                                         * '<S54>/Analog Butterworth LP Filter1'
                                         */
  real_T AnalogButterworthLPFilter1_C_m;/* Computed Parameter: C
                                         * '<S54>/Analog Butterworth LP Filter1'
                                         */
  real_T DeadZone_Start_ic;            /* Expression: -5000
                                        * '<S52>/Dead Zone'
                                        */
  real_T DeadZone_End_p;               /* Expression: 5000
                                        * '<S52>/Dead Zone'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1
                                        * '<S52>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -1
                                        * '<S52>/Saturation'
                                        */
  real_T Memory_X0_b;                  /* Expression: initial_condition
                                        * '<S56>/Memory'
                                        */
  real_T Logic_table_e[16];            /* Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0]
                                        * '<S56>/Logic'
                                        */
  real_T ConversionRotationtoAngle_Ga_bl;/* Expression: 2*pi
                                          * '<S52>/Conversion Rotation to Angle'
                                          */
  real_T Memory1_X0_d;                 /* Expression: 0
                                        * '<S52>/Memory1'
                                        */
  real_T InitAngle_Threshold_o;        /* Expression: 1
                                        * '<S52>/Init Angle'
                                        */
  real_T Gear_Gain_g;                  /* Expression: 6.33e-3
                                        * '<S52>/Gear'
                                        */
  real_T ConversionRadtoDeg_Gain_o;    /* Expression: 180/pi
                                        * '<S52>/Conversion Rad to Deg'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: pi/180
                                        * '<S10>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1.25/pi()
                                        * '<S90>/Gain2'
                                        */
  real_T Constant_Value;               /* Expression: -0.15
                                        * '<S14>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: const
                                        * '<S33>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * '<S32>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * '<S24>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * '<S14>/Gain'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 3
                                        * '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -3
                                        * '<S14>/Saturation'
                                        */
  real_T predkosc_Value;               /* Expression: 50
                                        * '<S3>/predkosc'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 0.01
                                        * '<S3>/Gain'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: 1
                                        * '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_bt;       /* Expression: 0.01
                                        * '<S3>/Saturation'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * '<S46>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: const
                                        * '<S45>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * '<S37>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: const
                                        * '<S59>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * '<S58>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * '<S50>/Constant1'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 1
                                        * '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0.05
                                        * '<S20>/Saturation'
                                        */
  real_T RateLimiter_RisingLim;        /* Expression: 50
                                        * '<S14>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Expression: -50
                                        * '<S14>/Rate Limiter'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 0.1
                                        * '<S14>/Gain1'
                                        */
  real_T Constant_Value_o;             /* Expression: -0.15
                                        * '<S15>/Constant'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 0.5
                                        * '<S15>/Gain'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 3
                                        * '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -3
                                        * '<S15>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * '<S20>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0.05
                                        * '<S20>/Saturation1'
                                        */
  real_T RateLimiter_RisingLim_a;      /* Expression: 50
                                        * '<S15>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_k;     /* Expression: -50
                                        * '<S15>/Rate Limiter'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 0.1
                                        * '<S15>/Gain1'
                                        */
  real_T Constant_Value_n;             /* Expression: -0.15
                                        * '<S16>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.5
                                        * '<S16>/Gain'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 3
                                        * '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -3
                                        * '<S16>/Saturation'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * '<S20>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0.05
                                        * '<S20>/Saturation2'
                                        */
  real_T RateLimiter_RisingLim_d;      /* Expression: 50
                                        * '<S16>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_p;     /* Expression: -50
                                        * '<S16>/Rate Limiter'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 0.1
                                        * '<S16>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: -0.15
                                        * '<S17>/Constant2'
                                        */
  real_T Memory_X0_c;                  /* Expression: initial_condition
                                        * '<S69>/Memory'
                                        */
  real_T Logic_table_l[16];            /* Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0]
                                        * '<S69>/Logic'
                                        */
  real_T Memory_X0_n;                  /* Expression: 0
                                        * '<S65>/Memory'
                                        */
  real_T AnalogButterworthLPFilter_A_c;/* Computed Parameter: A
                                        * '<S66>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter_C_b;/* Computed Parameter: C
                                        * '<S66>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter1_A_n;/* Computed Parameter: A
                                         * '<S67>/Analog Butterworth LP Filter1'
                                         */
  real_T AnalogButterworthLPFilter1_C_b;/* Computed Parameter: C
                                         * '<S67>/Analog Butterworth LP Filter1'
                                         */
  real_T DeadZone_Start_ib;            /* Expression: -5000
                                        * '<S65>/Dead Zone'
                                        */
  real_T DeadZone_End_a;               /* Expression: 5000
                                        * '<S65>/Dead Zone'
                                        */
  real_T Saturation_UpperSat_ma;       /* Expression: 1
                                        * '<S65>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: -1
                                        * '<S65>/Saturation'
                                        */
  real_T ConversionRotationtoAngle_Gai_c;/* Expression: 2*pi
                                          * '<S65>/Conversion Rotation to Angle'
                                          */
  real_T Memory1_X0_e;                 /* Expression: 0
                                        * '<S65>/Memory1'
                                        */
  real_T InitAngle_Threshold_k;        /* Expression: 1
                                        * '<S65>/Init Angle'
                                        */
  real_T Gear_Gain_nb;                 /* Expression: 7.87e-3
                                        * '<S65>/Gear'
                                        */
  real_T ConversionRadtoDeg_Gain_l;    /* Expression: 180/pi
                                        * '<S65>/Conversion Rad to Deg'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * '<S72>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * '<S71>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * '<S63>/Constant1'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 0.5
                                        * '<S17>/Gain2'
                                        */
  real_T Saturation1_UpperSat_f;       /* Expression: 3
                                        * '<S17>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_h;       /* Expression: -3
                                        * '<S17>/Saturation1'
                                        */
  real_T RateLimiter1_RisingLim;       /* Expression: 50
                                        * '<S17>/Rate Limiter1'
                                        */
  real_T RateLimiter1_FallingLim;      /* Expression: -50
                                        * '<S17>/Rate Limiter1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.1
                                        * '<S17>/Gain3'
                                        */
  real_T Constant2_Value_a;            /* Expression: -0.15
                                        * '<S18>/Constant2'
                                        */
  real_T Memory_X0_a;                  /* Expression: initial_condition
                                        * '<S82>/Memory'
                                        */
  real_T Logic_table_o[16];            /* Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0]
                                        * '<S82>/Logic'
                                        */
  real_T Memory_X0_m;                  /* Expression: 0
                                        * '<S78>/Memory'
                                        */
  real_T AnalogButterworthLPFilter_A_f;/* Computed Parameter: A
                                        * '<S79>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter_C_h;/* Computed Parameter: C
                                        * '<S79>/Analog Butterworth LP Filter'
                                        */
  real_T AnalogButterworthLPFilter1_A_c;/* Computed Parameter: A
                                         * '<S80>/Analog Butterworth LP Filter1'
                                         */
  real_T AnalogButterworthLPFilter1_C_n5;/* Computed Parameter: C
                                          * '<S80>/Analog Butterworth LP Filter1'
                                          */
  real_T DeadZone_Start_j;             /* Expression: -5000
                                        * '<S78>/Dead Zone'
                                        */
  real_T DeadZone_End_lg;              /* Expression: 5000
                                        * '<S78>/Dead Zone'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: 1
                                        * '<S78>/Saturation'
                                        */
  real_T Saturation_LowerSat_mt;       /* Expression: -1
                                        * '<S78>/Saturation'
                                        */
  real_T ConversionRotationtoAngle_Gai_g;/* Expression: 2*pi
                                          * '<S78>/Conversion Rotation to Angle'
                                          */
  real_T Memory1_X0_o;                 /* Expression: 0
                                        * '<S78>/Memory1'
                                        */
  real_T InitAngle_Threshold_p;        /* Expression: 1
                                        * '<S78>/Init Angle'
                                        */
  real_T Gear_Gain_a;                  /* Expression: 1.32e-2
                                        * '<S78>/Gear'
                                        */
  real_T ConversionRadtoDeg_Gain_go;   /* Expression: 180/pi
                                        * '<S78>/Conversion Rad to Deg'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * '<S85>/Constant'
                                        */
  real_T Constant_Value_ku;            /* Expression: const
                                        * '<S84>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * '<S76>/Constant1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 0.5
                                        * '<S18>/Gain2'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 3
                                        * '<S18>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -3
                                        * '<S18>/Saturation1'
                                        */
  real_T RateLimiter1_RisingLim_g;     /* Expression: 50
                                        * '<S18>/Rate Limiter1'
                                        */
  real_T RateLimiter1_FallingLim_g;    /* Expression: -50
                                        * '<S18>/Rate Limiter1'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 0.1
                                        * '<S18>/Gain3'
                                        */
  real_T Constant_Value_h;             /* Expression: -0.5
                                        * '<S19>/Constant'
                                        */
  real_T Memory_X0_m2;                 /* Expression: initial_condition
                                        * '<S92>/Memory'
                                        */
  real_T Logic_table_p[16];            /* Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0]
                                        * '<S92>/Logic'
                                        */
  real_T Constant_Value_f;             /* Expression: const
                                        * '<S95>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: const
                                        * '<S94>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * '<S89>/Constant1'
                                        */
  real_T Gain_Gain_dw;                 /* Expression: 0.5
                                        * '<S19>/Gain'
                                        */
  real_T Saturation_UpperSat_mp;       /* Expression: 3
                                        * '<S19>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: -3
                                        * '<S19>/Saturation'
                                        */
  real_T RateLimiter_RisingLim_o;      /* Expression: 50
                                        * '<S19>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_n;     /* Expression: -50
                                        * '<S19>/Rate Limiter'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 0.1
                                        * '<S19>/Gain1'
                                        */
  real_T wybortrybu_Value;             /* Expression: 0
                                        * '<S4>/wybor trybu'
                                        */
  real_T Constant_Value_ac;            /* Expression: const
                                        * '<S99>/Constant'
                                        */
  real_T przyciskjedzdoprzedmiotu_Value;/* Expression: 0
                                         * '<S4>/przycisk jedz do przedmiotu'
                                         */
  real_T Constant_Value_jk;            /* Expression: const
                                        * '<S98>/Constant'
                                        */
  real_T przyciskrozpoznawanieobrazu_Val;/* Expression: 0
                                          * '<S4>/przycisk rozpoznawanie obrazu'
                                          */
  real_T Constant_Value_cw;            /* Expression: const
                                        * '<S96>/Constant'
                                        */
  real_T przyciskwyzwolenia_Value;     /* Expression: 0
                                        * '<S4>/przycisk wyzwolenia'
                                        */
  real_T Constant_Value_ob;            /* Expression: const
                                        * '<S97>/Constant'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * '<Root>/Data Store Memory'
                                        */
  real_T obliczoneDist_InitialValue;   /* Expression: 0
                                        * '<Root>/obliczoneDist'
                                        */
  real_T obliczoneFi1_InitialValue;    /* Expression: 0
                                        * '<Root>/obliczoneFi1'
                                        */
  real_T obliczoneFi2_InitialValue;    /* Expression: 0
                                        * '<Root>/obliczoneFi2'
                                        */
  real_T obliczoneFi3_InitialValue;    /* Expression: 0
                                        * '<Root>/obliczoneFi3'
                                        */
  real_T obliczoneFi4_InitialValue;    /* Expression: 0
                                        * '<Root>/obliczoneFi4'
                                        */
  real_T obliczoneFi5_InitialValue;    /* Expression: 0
                                        * '<Root>/obliczoneFi5'
                                        */
  real_T obliczoneX_InitialValue;      /* Expression: 0
                                        * '<Root>/obliczoneX'
                                        */
  real_T obliczoneY_InitialValue;      /* Expression: 0
                                        * '<Root>/obliczoneY'
                                        */
  real_T obliczoneZ_InitialValue;      /* Expression: 0
                                        * '<Root>/obliczoneZ'
                                        */
  real_T tmpu0_InitialValue;           /* Expression: 0
                                        * '<Root>/tmp u0'
                                        */
  real_T tmpu1_InitialValue;           /* Expression: 0
                                        * '<Root>/tmp u1'
                                        */
  real_T tmpu2_InitialValue;           /* Expression: 0
                                        * '<Root>/tmp u2'
                                        */
  real_T tmpu3_InitialValue;           /* Expression: 0
                                        * '<Root>/tmp u3'
                                        */
  real_T tmpu4_InitialValue;           /* Expression: 0
                                        * '<Root>/tmp u4'
                                        */
  real_T tmpu5_InitialValue;           /* Expression: 0
                                        * '<Root>/tmp u5'
                                        */
  real_T u0_InitialValue;              /* Expression: 0
                                        * '<Root>/u0'
                                        */
  real_T u1_InitialValue;              /* Expression: 0
                                        * '<Root>/u1'
                                        */
  real_T u2_InitialValue;              /* Expression: 0
                                        * '<Root>/u2'
                                        */
  real_T u3_InitialValue;              /* Expression: 0
                                        * '<Root>/u3'
                                        */
  real_T u4_InitialValue;              /* Expression: 0
                                        * '<Root>/u4'
                                        */
  real_T u5_InitialValue;              /* Expression: 0
                                        * '<Root>/u5'
                                        */
  real_T xKon_InitialValue;            /* Expression: 0
                                        * '<Root>/xKon'
                                        */
  real_T yKon_InitialValue;            /* Expression: 0
                                        * '<Root>/yKon'
                                        */
  real_T zKon_InitialValue;            /* Expression: 0
                                        * '<Root>/zKon'
                                        */
  real_T zadaneX_InitialValue;         /* Expression: 0
                                        * '<Root>/zadaneX'
                                        */
  real_T zadaneY_InitialValue;         /* Expression: 0
                                        * '<Root>/zadaneY'
                                        */
  real_T zadaneZ_InitialValue;         /* Expression: 0
                                        * '<Root>/zadaneZ'
                                        */
  real_T Constant_Value_ea;            /* Expression: 0
                                        * '<S31>/Constant'
                                        */
  real_T Constant_Value_a5;            /* Expression: 0
                                        * '<S44>/Constant'
                                        */
  real_T Constant_Value_l1;            /* Expression: 0
                                        * '<S57>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * '<S70>/Constant'
                                        */
  real_T Constant_Value_dm;            /* Expression: 0
                                        * '<S83>/Constant'
                                        */
  real_T Constant_Value_hl;            /* Expression: 0
                                        * '<S93>/Constant'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * '<S114>/Gain'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * '<S115>/Gain'
                                        */
  real_T Gain_Gain_gh;                 /* Expression: 180/pi
                                        * '<S116>/Gain'
                                        */
  real_T Constant_Value_kq;            /* Expression: const
                                        * '<S106>/Constant'
                                        */
  real_T Constant_Value_bw;            /* Expression: const
                                        * '<S107>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: const
                                        * '<S108>/Constant'
                                        */
  real_T Constant_Value_ky;            /* Expression: const
                                        * '<S109>/Constant'
                                        */
  real_T Constant_Value_iz;            /* Expression: const
                                        * '<S110>/Constant'
                                        */
  real_T Constant_Value_on;            /* Expression: const
                                        * '<S111>/Constant'
                                        */
  real_T Constant_Value_n1;            /* Expression: const
                                        * '<S112>/Constant'
                                        */
  real_T Constant_Value_ps;            /* Expression: const
                                        * '<S113>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * '<S102>/Constant1'
                                        */
  real_T Constant_Value_gi;            /* Expression: 212
                                        * '<S102>/Constant'
                                        */
  real_T DelayInput1_X0;               /* Expression: vinit
                                        * '<S118>/Delay Input1'
                                        */
  real_T DelayInput1_X0_c;             /* Expression: vinit
                                        * '<S119>/Delay Input1'
                                        */
  real_T DelayInput1_X0_k;             /* Expression: vinit
                                        * '<S120>/Delay Input1'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_proba1 {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][10];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_proba1 proba1_P;

/* Block signals (auto storage) */
extern BlockIO_proba1 proba1_B;

/* Continuous states (auto storage) */
extern ContinuousStates_proba1 proba1_X;

/* Block states (auto storage) */
extern D_Work_proba1 proba1_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_proba1 proba1_PrevZCSigState;

/* Model entry point functions */
extern void proba1_initialize(boolean_T firstTime);
extern void proba1_output(int_T tid);
extern void proba1_update(int_T tid);
extern void proba1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_proba1 *proba1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : proba1
 * '<S1>'   : proba1/RTI Data
 * '<S2>'   : proba1/kinematyka prosta
 * '<S3>'   : proba1/serwomechanizmy
 * '<S4>'   : proba1/tryby
 * '<S5>'   : proba1/RTI Data/RTI Data Store
 * '<S6>'   : proba1/RTI Data/RTI Data Store/RTI Data Store
 * '<S7>'   : proba1/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store
 * '<S8>'   : proba1/kinematyka prosta/Degrees to Radians
 * '<S9>'   : proba1/kinematyka prosta/Degrees to Radians1
 * '<S10>'  : proba1/kinematyka prosta/Degrees to Radians2
 * '<S11>'  : proba1/serwomechanizmy/DS2201ADC_B1
 * '<S12>'  : proba1/serwomechanizmy/DS2201DAC_B1
 * '<S13>'  : proba1/serwomechanizmy/DS3001ENC_POS_B1_C5
 * '<S14>'  : proba1/serwomechanizmy/os1
 * '<S15>'  : proba1/serwomechanizmy/os2
 * '<S16>'  : proba1/serwomechanizmy/os3
 * '<S17>'  : proba1/serwomechanizmy/os4
 * '<S18>'  : proba1/serwomechanizmy/os5
 * '<S19>'  : proba1/serwomechanizmy/os6
 * '<S20>'  : proba1/serwomechanizmy/quasiliniowosc
 * '<S21>'  : proba1/serwomechanizmy/os1/Position 1
 * '<S22>'  : proba1/serwomechanizmy/os1/blok bazowania
 * '<S23>'  : proba1/serwomechanizmy/os1/blok stopu
 * '<S24>'  : proba1/serwomechanizmy/os1/ograniczenie1
 * '<S25>'  : proba1/serwomechanizmy/os1/Position 1/Filters 1
 * '<S26>'  : proba1/serwomechanizmy/os1/Position 1/Position Calculation 1
 * '<S27>'  : proba1/serwomechanizmy/os1/Position 1/Filters 1/Analog Butterworth LP Filter
 * '<S28>'  : proba1/serwomechanizmy/os1/Position 1/Filters 1/Analog Butterworth LP Filter1
 * '<S29>'  : proba1/serwomechanizmy/os1/blok bazowania/DS2201IN_B1
 * '<S30>'  : proba1/serwomechanizmy/os1/blok bazowania/S-R Flip-Flop
 * '<S31>'  : proba1/serwomechanizmy/os1/blok bazowania/zerowanie
 * '<S32>'  : proba1/serwomechanizmy/os1/ograniczenie1/Compare To Constant
 * '<S33>'  : proba1/serwomechanizmy/os1/ograniczenie1/Compare To Constant1
 * '<S34>'  : proba1/serwomechanizmy/os2/Position 2
 * '<S35>'  : proba1/serwomechanizmy/os2/blok bazowania
 * '<S36>'  : proba1/serwomechanizmy/os2/blok stopu
 * '<S37>'  : proba1/serwomechanizmy/os2/ograniczenie2
 * '<S38>'  : proba1/serwomechanizmy/os2/Position 2/Filters 2
 * '<S39>'  : proba1/serwomechanizmy/os2/Position 2/Position Calculation 2
 * '<S40>'  : proba1/serwomechanizmy/os2/Position 2/Filters 2/Analog Butterworth LP Filter
 * '<S41>'  : proba1/serwomechanizmy/os2/Position 2/Filters 2/Analog Butterworth LP Filter1
 * '<S42>'  : proba1/serwomechanizmy/os2/blok bazowania/DS2201IN_B1
 * '<S43>'  : proba1/serwomechanizmy/os2/blok bazowania/S-R Flip-Flop
 * '<S44>'  : proba1/serwomechanizmy/os2/blok bazowania/zerowanie
 * '<S45>'  : proba1/serwomechanizmy/os2/ograniczenie2/Compare To Constant
 * '<S46>'  : proba1/serwomechanizmy/os2/ograniczenie2/Compare To Constant1
 * '<S47>'  : proba1/serwomechanizmy/os3/Position 3
 * '<S48>'  : proba1/serwomechanizmy/os3/blok bazowania
 * '<S49>'  : proba1/serwomechanizmy/os3/blok stopu
 * '<S50>'  : proba1/serwomechanizmy/os3/ograniczenie3
 * '<S51>'  : proba1/serwomechanizmy/os3/Position 3/Filters 3
 * '<S52>'  : proba1/serwomechanizmy/os3/Position 3/Position Calculation 3
 * '<S53>'  : proba1/serwomechanizmy/os3/Position 3/Filters 3/Analog Butterworth LP Filter
 * '<S54>'  : proba1/serwomechanizmy/os3/Position 3/Filters 3/Analog Butterworth LP Filter1
 * '<S55>'  : proba1/serwomechanizmy/os3/blok bazowania/DS2201IN_B1
 * '<S56>'  : proba1/serwomechanizmy/os3/blok bazowania/S-R Flip-Flop
 * '<S57>'  : proba1/serwomechanizmy/os3/blok bazowania/zerowanie
 * '<S58>'  : proba1/serwomechanizmy/os3/ograniczenie3/Compare To Constant
 * '<S59>'  : proba1/serwomechanizmy/os3/ograniczenie3/Compare To Constant1
 * '<S60>'  : proba1/serwomechanizmy/os4/Position 4
 * '<S61>'  : proba1/serwomechanizmy/os4/blok bazowania
 * '<S62>'  : proba1/serwomechanizmy/os4/blok stopu
 * '<S63>'  : proba1/serwomechanizmy/os4/ograniczenie3
 * '<S64>'  : proba1/serwomechanizmy/os4/Position 4/Filters 4
 * '<S65>'  : proba1/serwomechanizmy/os4/Position 4/Position Calculation 4
 * '<S66>'  : proba1/serwomechanizmy/os4/Position 4/Filters 4/Analog Butterworth LP Filter
 * '<S67>'  : proba1/serwomechanizmy/os4/Position 4/Filters 4/Analog Butterworth LP Filter1
 * '<S68>'  : proba1/serwomechanizmy/os4/blok bazowania/DS2201IN_B1
 * '<S69>'  : proba1/serwomechanizmy/os4/blok bazowania/S-R Flip-Flop
 * '<S70>'  : proba1/serwomechanizmy/os4/blok bazowania/zerowanie
 * '<S71>'  : proba1/serwomechanizmy/os4/ograniczenie3/Compare To Constant
 * '<S72>'  : proba1/serwomechanizmy/os4/ograniczenie3/Compare To Constant1
 * '<S73>'  : proba1/serwomechanizmy/os5/Position 5
 * '<S74>'  : proba1/serwomechanizmy/os5/blok bazowania
 * '<S75>'  : proba1/serwomechanizmy/os5/blok stopu
 * '<S76>'  : proba1/serwomechanizmy/os5/ograniczenie3
 * '<S77>'  : proba1/serwomechanizmy/os5/Position 5/Filters 5
 * '<S78>'  : proba1/serwomechanizmy/os5/Position 5/Position Calculation 5
 * '<S79>'  : proba1/serwomechanizmy/os5/Position 5/Filters 5/Analog Butterworth LP Filter
 * '<S80>'  : proba1/serwomechanizmy/os5/Position 5/Filters 5/Analog Butterworth LP Filter1
 * '<S81>'  : proba1/serwomechanizmy/os5/blok bazowania/DS2201IN_B1
 * '<S82>'  : proba1/serwomechanizmy/os5/blok bazowania/S-R Flip-Flop
 * '<S83>'  : proba1/serwomechanizmy/os5/blok bazowania/zerowanie
 * '<S84>'  : proba1/serwomechanizmy/os5/ograniczenie3/Compare To Constant
 * '<S85>'  : proba1/serwomechanizmy/os5/ograniczenie3/Compare To Constant1
 * '<S86>'  : proba1/serwomechanizmy/os6/DS3001ENC_RESET_B1_C1
 * '<S87>'  : proba1/serwomechanizmy/os6/blok bazowania
 * '<S88>'  : proba1/serwomechanizmy/os6/blok stopu
 * '<S89>'  : proba1/serwomechanizmy/os6/ograniczenie3
 * '<S90>'  : proba1/serwomechanizmy/os6/skalowanie
 * '<S91>'  : proba1/serwomechanizmy/os6/blok bazowania/DS2201IN_B1
 * '<S92>'  : proba1/serwomechanizmy/os6/blok bazowania/S-R Flip-Flop
 * '<S93>'  : proba1/serwomechanizmy/os6/blok bazowania/zerowanie
 * '<S94>'  : proba1/serwomechanizmy/os6/ograniczenie3/Compare To Constant
 * '<S95>'  : proba1/serwomechanizmy/os6/ograniczenie3/Compare To Constant1
 * '<S96>'  : proba1/tryby/Compare To Constant
 * '<S97>'  : proba1/tryby/Compare To Constant1
 * '<S98>'  : proba1/tryby/Compare To Constant2
 * '<S99>'  : proba1/tryby/Compare To Constant3
 * '<S100>' : proba1/tryby/jedz do przedmiotu
 * '<S101>' : proba1/tryby/kinematyka odwrotna
 * '<S102>' : proba1/tryby/rozpoznawanie obrazu
 * '<S103>' : proba1/tryby/tryb ciagly
 * '<S104>' : proba1/tryby/tryb kinematyki odwrotnej
 * '<S105>' : proba1/tryby/tryb wyzwalany
 * '<S106>' : proba1/tryby/kinematyka odwrotna/Compare To Constant
 * '<S107>' : proba1/tryby/kinematyka odwrotna/Compare To Constant1
 * '<S108>' : proba1/tryby/kinematyka odwrotna/Compare To Constant2
 * '<S109>' : proba1/tryby/kinematyka odwrotna/Compare To Constant3
 * '<S110>' : proba1/tryby/kinematyka odwrotna/Compare To Constant4
 * '<S111>' : proba1/tryby/kinematyka odwrotna/Compare To Constant5
 * '<S112>' : proba1/tryby/kinematyka odwrotna/Compare To Constant6
 * '<S113>' : proba1/tryby/kinematyka odwrotna/Compare To Constant7
 * '<S114>' : proba1/tryby/kinematyka odwrotna/Radians to Degrees
 * '<S115>' : proba1/tryby/kinematyka odwrotna/Radians to Degrees1
 * '<S116>' : proba1/tryby/kinematyka odwrotna/Radians to Degrees2
 * '<S117>' : proba1/tryby/kinematyka odwrotna/podaj wyliczone wartosci
 * '<S118>' : proba1/tryby/rozpoznawanie obrazu/Detect Change
 * '<S119>' : proba1/tryby/rozpoznawanie obrazu/Detect Change1
 * '<S120>' : proba1/tryby/rozpoznawanie obrazu/Detect Change2
 * '<S121>' : proba1/tryby/rozpoznawanie obrazu/Embedded MATLAB Function
 * '<S122>' : proba1/tryby/rozpoznawanie obrazu/podaj wyliczone wartosci
 */
#endif                                 /* RTW_HEADER_proba1_h_ */
