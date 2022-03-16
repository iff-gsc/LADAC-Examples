//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MatlabController_data.cpp
//
// Code generated for Simulink model 'ArduCopter_MinnieLoiterController'.
//
// Model version                  : 1.386
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Sun Nov 14 15:14:29 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "MatlabController.h"

// Invariant block signals (default storage)
const ConstB rtConstB = {
  {
    -0.0F,
    -0.0F,
    9.81F
  }
  // '<S21>/Gain2'
};

// Constant parameters (default storage)
const ConstP rtConstP = {
  // Computed Parameter: ny_du_red_trim_Value
  //  Referenced by: '<S46>/ny_du_red_trim'

  { -552.858215F, 599.994324F, -42.9285F, -16.0513F, -552.86F, -599.994507F,
    42.9418F, -16.0513F, 552.859802F, -598.937683F, -31.9157F, -16.0513F,
    552.858521F, 598.937927F, 31.9025F, -16.0513F },

  // Computed Parameter: ny_du_dt_Value
  //  Referenced by: '<S46>/ny_du_dt'

  { 0.069F, -0.0001F, -4.8857F, 0.0F, -0.069F, 0.0001F, 4.8857F, 0.0F, 0.069F,
    -0.0001F, -4.8857F, 0.0F, -0.069F, 0.0001F, 4.8857F, 0.0F },

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S47>/Constant5'

  { 10.0F, 0.0F, 0.0F, 0.0F, 0.0F, 10.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.0F,
    0.0F, 0.0F, 0.0F, 1.0F },

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S47>/Constant6'

  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F },

  // Expression: [horiz_pos_cntrl.limits.e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S24>/Saturation1'

  { 12.2174311F, 12.2174311F, 1000.0F, 1000.0F, 1000.0F, 1000.0F },

  // Expression: -[horiz_pos_cntrl.limits.e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S24>/Saturation1'

  { -12.2174311F, -12.2174311F, -1000.0F, -1000.0F, -1000.0F, -1000.0F },

  // Expression: horiz_pos_cntrl.K
  //  Referenced by: '<S24>/Gain'

  { 3.3528F, 0.0F, 0.0F, 3.3528F, 3.9012F, 0.0F, 0.0F, 3.9012F, 0.7114F, 0.0F,
    0.0F, 0.7114F },

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S80>/1-D Lookup Table'

  { 4.0F, 0.0F, -10.0F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S80>/1-D Lookup Table'

  { -1.0F, 0.0F, 1.0F },

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<S38>/1-D Lookup Table1'

  { -1000.0F, -1000.0F, 0.0F, 0.0F },

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<S38>/1-D Lookup Table1'

  { 0.0F, 0.1F, 0.2F, 1.0F },

  // Expression: atti_cntrl.K
  //  Referenced by: '<S53>/Gain'

  { 200.0F, 0.0F, 0.0F, 0.0F, 200.0F, 0.0F, 0.0F, -0.0F, 50.0F, 39.9604F, 0.0F,
    0.0F, 0.0F, 39.9604F, -0.0F, 0.0F, -0.0F, 15.6068F, 0.9513F, 0.0F, 0.0F,
    0.0F, 0.9513F, -0.0F, 0.0F, -0.0F, 0.4357F }
};

//
// File trailer for generated code.
//
// [EOF]
//
