/*
 * BlinkLED.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BlinkLED".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Sep 20 20:22:33 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BlinkLED.h"
#include "BlinkLED_private.h"
#include <string.h>

/* Block states (default storage) */
DW_BlinkLED_T BlinkLED_DW;

/* Real-time model */
static RT_MODEL_BlinkLED_T BlinkLED_M_;
RT_MODEL_BlinkLED_T *const BlinkLED_M = &BlinkLED_M_;

/* Model step function */
void BlinkLED_step(void)
{
  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  writeDigitalPin(13, 0);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++BlinkLED_M->Timing.clockTick0)) {
    ++BlinkLED_M->Timing.clockTickH0;
  }

  BlinkLED_M->Timing.taskTime0 = BlinkLED_M->Timing.clockTick0 *
    BlinkLED_M->Timing.stepSize0 + BlinkLED_M->Timing.clockTickH0 *
    BlinkLED_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void BlinkLED_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BlinkLED_M, 0,
                sizeof(RT_MODEL_BlinkLED_T));
  rtmSetTFinal(BlinkLED_M, -1);
  BlinkLED_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  BlinkLED_M->Sizes.checksums[0] = (449500547U);
  BlinkLED_M->Sizes.checksums[1] = (2693602001U);
  BlinkLED_M->Sizes.checksums[2] = (3971325881U);
  BlinkLED_M->Sizes.checksums[3] = (522981196U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    BlinkLED_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BlinkLED_M->extModeInfo,
      &BlinkLED_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BlinkLED_M->extModeInfo, BlinkLED_M->Sizes.checksums);
    rteiSetTPtr(BlinkLED_M->extModeInfo, rtmGetTPtr(BlinkLED_M));
  }

  /* states (dwork) */
  (void) memset((void *)&BlinkLED_DW, 0,
                sizeof(DW_BlinkLED_T));

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  BlinkLED_DW.obj.matlabCodegenIsDeleted = false;
  BlinkLED_DW.objisempty = true;
  BlinkLED_DW.obj.isInitialized = 1;
  digitalIOSetup(13, 1);
  BlinkLED_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void BlinkLED_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!BlinkLED_DW.obj.matlabCodegenIsDeleted) {
    BlinkLED_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}
