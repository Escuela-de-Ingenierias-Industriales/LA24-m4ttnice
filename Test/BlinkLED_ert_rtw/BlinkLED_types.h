/*
 * BlinkLED_types.h
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

#ifndef BlinkLED_types_h_
#define BlinkLED_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_um27AmhtbslH2i5VSgy0RG
#define struct_tag_um27AmhtbslH2i5VSgy0RG

struct tag_um27AmhtbslH2i5VSgy0RG
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_um27AmhtbslH2i5VSgy0RG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_um27AmhtbslH2i5VSgy0RG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_lLXm9RMdC1wJGOFiPwVXeD
#define struct_tag_lLXm9RMdC1wJGOFiPwVXeD

struct tag_lLXm9RMdC1wJGOFiPwVXeD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_lLXm9RMdC1wJGOFiPwVXeD */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_lLXm9RMdC1wJGOFiPwVXeD codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_BlinkLED_T RT_MODEL_BlinkLED_T;

#endif                                 /* BlinkLED_types_h_ */
