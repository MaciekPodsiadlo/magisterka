/* $Revision: 1.1.6.2 $ */
/**
 * @file:       simaqruntime.h
 *              
 * Purpose:     Runtime interface for simulink IAT utilities.
 *              
 * $Authors:    S. S. $
 *              
 * $Copyright: 2006-2007 The MathWorks, Inc.$
 *
 * $Date: 2007/06/18 22:22:18 $
 *
 */
 
#ifndef __SIMAQRUNTIME__HEADER__
#define __SIMAQRUNTIME__HEADER__

// Define the import/export macros based on who is including 
// this, i.e. if it's an S-Function, it needs to import the functions.
// Otherwise it needs to export them to make them available.
#ifndef S_FUNCTION_NAME
#define SIMAQ_RUNTIME_EXPORT __declspec(dllexport)
#else
#define SIMAQ_RUNTIME_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Exported function used to create an FVD/VI subsystem.
     *
     * @param blockHandle:	Current block handle in the model.
     * @param constructor:	IAT object constructor to evaluate.
     * @param videoFormat:	Video format of the selected device. 
     * @param cameraFile:	Camera File format for the device. 
     * @param videoSource:	Video Source selected as input. 
     * @param roiPosition:	ROI Position as an array of size 4.
     * @param hardwareTriggerEnabled: True if hardware trigger is enabled.
     * @param triggerConfiguration: Current trigger configuration.
     * @param nPorts:		Number of ports option selected.
     * @param dataType:		User specified data type option.
     * @param portWidth:	Width of signal at the output port.
     *
     * @return void*: IAT subsystem constructed.
     */

    SIMAQ_RUNTIME_EXPORT void* exIMAQCreateFVDSystem(const char* const blockHandle, const char* const constructor, 
                                                     const char* const videoFormat, const char* const cameraFile, 
                                                     const char* const videoSource, const char* const roiPosition, 
                                                     const bool hardwareTriggerEnabled, const char* const triggerConfiguration, 
                                                     const int nPorts, const char* const dataType, const int portWidth);

     /**
     * Initializes the IMAQ subsystem passed in by creating the IAT
     * object it needs behind the scenes.
     *
     * @param imaqSys: IMAQ subsystem to initialize.
     *
     * @return bool : True if successful, false otherwise.
     */
    SIMAQ_RUNTIME_EXPORT bool exIMAQInitializeSystem(void* imaqSys);

    /**
     * Invokes the START command on the IMAQ subsystem provided.
     *
     * @param imaqSys: IMAQ subsystem to start running.
     *
     * @return bool : True if successful, false otherwise.
     */
    SIMAQ_RUNTIME_EXPORT bool exIMAQStartSystem(void* imaqSys);

    /**
     * Acquires data from the IMAQ subsystem and copies it into 
     * the Simulink signal pointers provided.
     *
     * @param imaqSys: IMAQ subsystem to acquire data from.
     * @param outputSignals[]: Array of signal pointers to populate.
     *
     * @return bool : True if successful, false otherwise.
     */
    SIMAQ_RUNTIME_EXPORT bool exIMAQAcquireData(void* imaqSys, void* outputSignals[]);

    /**
     * Terminates the IMAQ subsystem by destroying the underlying objects.
     *
     * @param imaqSys: IMAQ subsystem to terminate.
     */
    SIMAQ_RUNTIME_EXPORT void exIMAQTerminateSystem(void* imaqSys);

    /**
     * Returns the last error message that occurred.
     *
     * @param imaqSys: The IMAQ subsystem that encountered an error.
     *
     * @return const char* : The last error message string.
     */
    SIMAQ_RUNTIME_EXPORT const char* exIMAQGetLastError(void* imaqSys);

#ifdef __cplusplus
}
#endif

#endif

