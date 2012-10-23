#pragma once
#ifndef _DEFINED_G2LOG_DLL         //---------------1---------------+
#define _DEFINED_G2LOG_DLL         //---------------1---------------+
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

  LIBSPEC bool init_g2log (const char* prefix,const char* location);
  LIBSPEC void stop_g2log ();

  // ... more declarations as needed                        // |    |
  #undef LIBSPEC   //------------------------------4-----------+    |
                                                                 // |
  #ifdef __cplusplus    //----------------5---------------+         |
  }                                                    // |         |
  #endif // __cplusplus  //---------------5---------------+         |
#endif        // _DEFINED_G2LOG_DLL //-----------------1------------+
//http://www.flounder.com/ultimateheaderfile.htm