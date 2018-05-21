/*
 * File: _coder_GA_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 21-May-2018 18:13:20
 */

#ifndef _CODER_GA_API_H
#define _CODER_GA_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_GA_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void GA(real_T jobList[6], real_T NumberOfMachines, real_T MaxGen, real_T
               fitness, real_T fitold, real_T range, real_T sol, real_T pop,
               real_T limitedRange, real_T solnew, real_T popnew, real_T
               userdefinedn, real_T chromesomesize, emxArray_real_T *costs,
               real_T schedule[6]);
extern void GA_api(const mxArray * const prhs[13], const mxArray *plhs[2]);
extern void GA_atexit(void);
extern void GA_initialize(void);
extern void GA_terminate(void);
extern void GA_xil_terminate(void);

#endif

/*
 * File trailer for _coder_GA_api.h
 *
 * [EOF]
 */
