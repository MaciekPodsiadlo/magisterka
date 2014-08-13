/* $Revision: 1.1.6.2 $ */
/**
* @file:       viruntime.h
*              
* Purpose:     Runtime functions used for S-Function and code gen.
*              
* $Authors:    Chris Portal, Dave Tarkowski $
*              
* $Copyright: 2005-2007 The MathWorks, Inc.$
*
* $Date: 2007/06/18 22:22:21 $
*
*/
#ifndef __VIRUNTIME__HEADER__
#define __VIRUNTIME__HEADER__

// *******************************
// EXPORTED FUNCTION TYPES/NAMES
// *******************************
#define MWIMAQ_WVI_LIB_NAME	    "viblock.dll"

typedef void*       (*MWIMAQ_WVI_CREATE_FUNC)           (int, const char*, int, int, int, int);
typedef void        (*MWIMAQ_WVI_START_FUNC)            (void*);
typedef void        (*MWIMAQ_WVI_RGBOUTPUTS_FUNC)       (void*, void*, void*, void*);
typedef int         (*MWIMAQ_WVI_TERMINATE_FUNC)        (void*);
typedef const char* (*MWIMAQ_WVI_GETERRORMSG_FUNC)      (void*);
typedef int         (*MWIMAQ_WVI_HASERROR_FUNC)         (void*);

#define MWIMAQ_WVI_CREATE_NAME	        "MWIMAQ_Wvi_Create"
#define MWIMAQ_WVI_START_NAME		    "MWIMAQ_Wvi_Start"
#define MWIMAQ_WVI_RGBOUTPUTS_NAME	    "MWIMAQ_Wvi_RGBOutputs"
#define MWIMAQ_WVI_TERMINATE_NAME       "MWIMAQ_Wvi_Terminate"
#define MWIMAQ_WVI_GETERRORMSG_NAME     "MWIMAQ_Wvi_GetErrorMessage"
#define MWIMAQ_WVI_HASERROR_NAME        "MWIMAQ_Wvi_HasError"

// **************************
// LIBRARY FUNCTION WRAPPERS
// **************************
void* exMWIMAQ_Wvi_Create(int deviceID, const char* devName, const char* formatName, 
                          int width, int height, int fps, int dType);

void exMWIMAQ_Wvi_Start(void* obj);

MWIMAQ_WVI_RGBOUTPUTS_FUNC exMWIMAQ_Wvi_GetRGBOutputFcnPtr(void);

void exMWIMAQ_Wvi_RGBOutputs(void* obj, void* red, void* green, void* blue);

void exMWIMAQ_Wvi_Terminate(void* obj);

// **************************
// ERROR MESSAGE HANDLERS
// **************************
int exMWIMAQ_Wvi_HasError(void* obj);

const char* exMWIMAQ_Wvi_GetErrorMessage(void* obj);

const char* exMWIMAQ_Wvi_GetLibaryErrorMessage(void);

void exMWIMAQ_Wvi_ResetErrorState(void);

#endif
