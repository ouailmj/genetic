/*
 * File: _coder_GA_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 21-May-2018 18:13:20
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_GA_api.h"
#include "_coder_GA_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "GA",                                /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[6];
static const mxArray *b_emlrt_marshallOut(const real_T u[6]);
static real_T c_emlrt_marshallIn(const mxArray *NumberOfMachines, const char_T
  *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T (*e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[6];
static real_T (*emlrt_marshallIn(const mxArray *jobList, const char_T
  *identifier))[6];
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush);
static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[6]
 */
static real_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[6]
{
  real_T (*y)[6];
  y = e_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u[6]
 * Return Type  : const mxArray *
 */
  static const mxArray *b_emlrt_marshallOut(const real_T u[6])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 0, 0 };

  static const int32_T iv2[2] = { 1, 6 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, *(int32_T (*)[2])&iv2[0], 2);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const mxArray *NumberOfMachines
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const mxArray *NumberOfMachines, const char_T
  *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(NumberOfMachines), &thisId);
  emlrtDestroyArray(&NumberOfMachines);
  return y;
}

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[6]
 */
static real_T (*e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[6]
{
  real_T (*ret)[6];
  static const int32_T dims[2] = { 1, 6 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  ret = (real_T (*)[6])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray *jobList
 *                const char_T *identifier
 * Return Type  : real_T (*)[6]
 */
  static real_T (*emlrt_marshallIn(const mxArray *jobList, const char_T
  *identifier))[6]
{
  real_T (*y)[6];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(jobList), &thisId);
  emlrtDestroyArray(&jobList);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void (*)(void *))emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U,
    &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[13]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void GA_api(const mxArray * const prhs[13], const mxArray *plhs[2])
{
  real_T (*schedule)[6];
  emxArray_real_T *costs;
  real_T (*jobList)[6];
  real_T NumberOfMachines;
  real_T MaxGen;
  real_T fitness;
  real_T fitold;
  real_T range;
  real_T sol;
  real_T pop;
  real_T limitedRange;
  real_T solnew;
  real_T popnew;
  real_T userdefinedn;
  real_T chromesomesize;
  schedule = (real_T (*)[6])mxMalloc(sizeof(real_T [6]));
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&costs, 1, true);

  /* Marshall function inputs */
  jobList = emlrt_marshallIn(emlrtAlias((const mxArray *)prhs[0]), "jobList");
  NumberOfMachines = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[1]),
    "NumberOfMachines");
  MaxGen = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[2]), "MaxGen");
  fitness = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[3]), "fitness");
  fitold = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[4]), "fitold");
  range = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[5]), "range");
  sol = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[6]), "sol");
  pop = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[7]), "pop");
  limitedRange = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[8]),
    "limitedRange");
  solnew = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[9]), "solnew");
  popnew = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[10]), "popnew");
  userdefinedn = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[11]),
    "userdefinedn");
  chromesomesize = c_emlrt_marshallIn(emlrtAliasP((const mxArray *)prhs[12]),
    "chromesomesize");

  /* Invoke the target function */
  GA(*jobList, NumberOfMachines, MaxGen, fitness, fitold, range, sol, pop,
     limitedRange, solnew, popnew, userdefinedn, chromesomesize, costs,
     *schedule);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(costs);
  plhs[1] = b_emlrt_marshallOut(*schedule);
  costs->canFreeData = false;
  emxFree_real_T(&costs);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GA_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  GA_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GA_initialize(void)
{
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GA_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_GA_api.c
 *
 * [EOF]
 */
