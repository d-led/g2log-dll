#pragma once

#ifndef _DEFINED_G2LOG_DLL
#define _DEFINED_G2LOG_DLL 

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _MSC_VER
#ifdef _COMPILING_G2LOG_DLL
    #define LIBSPEC __declspec(dllexport)
#else
    #define LIBSPEC __declspec(dllimport)
#endif // _COMPILING_G2LOG_DLL
#else
 #define LIBSPEC
#endif

LIBSPEC int init_g2log (const char* prefix,const char* location);
LIBSPEC void printf_g2log(const char* _file,const int _line,const char* _function,const char* _level,const char* _message);
LIBSPEC void stop_g2log ();

#undef LIBSPEC
#ifdef __cplusplus
}
#endif
#endif
