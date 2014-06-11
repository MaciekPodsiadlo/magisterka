/* $Revision: 1.1.6.3 $
 *
 * Runtime library source file for Windows "Video Input" block.
 * Link:  (no import library needed)
 *
 *  Copyright 1995-2007 The MathWorks, Inc.
 */
#include <windows.h>
#include "viruntime.h"

// Global library handle.
static HMODULE _SIMAQVIModule = NULL;

// Global function pointers into the library.
static MWIMAQ_WVI_CREATE_FUNC           wviCreate = NULL;
static MWIMAQ_WVI_START_FUNC            wviStart = NULL;
static MWIMAQ_WVI_RGBOUTPUTS_FUNC       wviRGBOutputs = NULL;
static MWIMAQ_WVI_TERMINATE_FUNC        wviTerminate = NULL;
static MWIMAQ_WVI_GETERRORMSG_FUNC      wviGetErrorMsg = NULL;
static MWIMAQ_WVI_HASERROR_FUNC         wviHasError = NULL;

// **************************
// LIBRARY FUNCTION WRAPPERS
// **************************
void* exMWIMAQ_Wvi_Create(int deviceID, const char* devName, const char* formatName, 
                          int width, int height, int fps, int dType){

    if(_SIMAQVIModule == NULL){
        // Load the library.
        _SIMAQVIModule = LoadLibrary(MWIMAQ_WVI_LIB_NAME);
        if(_SIMAQVIModule == NULL){
            // If library is not loadable, return NULL.
            return NULL;
        }

        // Library was just loaded. Initialize function pointers into the library.
        wviCreate = (MWIMAQ_WVI_CREATE_FUNC) GetProcAddress(_SIMAQVIModule, MWIMAQ_WVI_CREATE_NAME);
        wviStart = (MWIMAQ_WVI_START_FUNC) GetProcAddress(_SIMAQVIModule, MWIMAQ_WVI_START_NAME);
        wviRGBOutputs = (MWIMAQ_WVI_RGBOUTPUTS_FUNC) GetProcAddress(_SIMAQVIModule, MWIMAQ_WVI_RGBOUTPUTS_NAME);
        wviTerminate = (MWIMAQ_WVI_TERMINATE_FUNC) GetProcAddress(_SIMAQVIModule, MWIMAQ_WVI_TERMINATE_NAME);
        wviGetErrorMsg = (MWIMAQ_WVI_GETERRORMSG_FUNC) GetProcAddress(_SIMAQVIModule, MWIMAQ_WVI_GETERRORMSG_NAME);
        wviHasError = (MWIMAQ_WVI_HASERROR_FUNC) GetProcAddress(_SIMAQVIModule, MWIMAQ_WVI_HASERROR_NAME);
    }

    // Create the requested block object.
    return wviCreate(deviceID, formatName, width, height, fps, dType);
}

void exMWIMAQ_Wvi_Start(void* obj){
    wviStart(obj);
}


MWIMAQ_WVI_RGBOUTPUTS_FUNC exMWIMAQ_Wvi_GetRGBOutputFcnPtr(void){
    return wviRGBOutputs;
}

void exMWIMAQ_Wvi_RGBOutputs(void* obj, void* red, void* green, void* blue){
    wviRGBOutputs(obj, red, green, blue);
}

void exMWIMAQ_Wvi_Terminate(void* obj){
    if(_SIMAQVIModule == NULL){
        return;
    }

    if(wviTerminate(obj) == 0){
        FreeLibrary(_SIMAQVIModule);
        _SIMAQVIModule = NULL;
    }
}

// **************************
// ERROR MESSAGE HANDLERS
// **************************
const char* exMWIMAQ_Wvi_GetLibaryErrorMessage(void){
    return "Unable to load dynamic-link library: MATLABROOT\\bin\\win32\\viblock.dll";
}

int exMWIMAQ_Wvi_HasError(void* obj){
    return wviHasError(obj);
}

const char* exMWIMAQ_Wvi_GetErrorMessage(void* obj){
    return wviGetErrorMsg(obj);
}

void exMWIMAQ_Wvi_ResetErrorState(void){
    //_SIMAQVIErrorStatus = S_OK;
}
