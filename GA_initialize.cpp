//
// File: GA_initialize.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 21-May-2018 18:13:20
//

// Include Files
#include "rt_nonfinite.h"
#include "GA.h"
#include "GA_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void GA_initialize()
{
  rt_InitInfAndNaN(8U);
  c_eml_rand_mt19937ar_stateful_i();
}

//
// File trailer for GA_initialize.cpp
//
// [EOF]
//
