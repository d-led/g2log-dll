#pragma once
#ifndef _DEFINED_G2LOG_DLL         //---------------1---------------+
#define _DEFINED_G2LOG_DLL         //---------------1---------------+

#include <varargs.h>
                                                                 // |
  #if _MSC_VER > 1000  //--------------2---------------+            |
    #pragma once                                    // |            |
  #endif //----------------------------2---------------+            |
                                                                 // |
  #ifdef __cplusplus  //---------------3---------------+            |
  extern "C" {                                      // |            |
  #endif // __cplusplus  //------------3---------------+            |
                                                                 // |
  #ifdef _COMPILING_G2LOG_DLL         //-----------4-----------+    |
    #define LIBSPEC __declspec(dllexport)                   // |    |
  #else                                                     // |    |
    #define LIBSPEC __declspec(dllimport)                   // |    |
  #endif // _COMPILING_G2LOG_DLL         //--------4-----------+    |
                                                            // |    |

  LIBSPEC int init_g2log (const char* prefix,const char* location);
  LIBSPEC void printf_g2log(const char* _file,const int _line,const char* _function,const char* _level,const char* _message);
  LIBSPEC void stop_g2log ();

  // ... more declarations as needed                        // |    |
  #undef LIBSPEC   //------------------------------4-----------+    |
                                                                 // |
  #ifdef __cplusplus    //----------------5---------------+         |
  }                                                    // |         |
  #endif // __cplusplus  //---------------5---------------+         |
#endif        // _DEFINED_G2LOG_DLL //-----------------1------------+
//http://www.flounder.com/ultimateheaderfile.htm