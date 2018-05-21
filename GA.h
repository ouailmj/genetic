//
// File: GA.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 21-May-2018 18:13:20
//
#ifndef GA_H
#define GA_H

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "GA_types.h"

// Function Declarations
extern void GA(const double jobList[6], double NumberOfMachines, double MaxGen,
               double fitness, double fitold, double range, double sol, double
               pop, double limitedRange, double solnew, double popnew, double
               userdefinedn, double chromesomesize, emxArray_real_T *costs,
               double schedule[6]);

#endif

//
// File trailer for GA.h
//
// [EOF]
//
