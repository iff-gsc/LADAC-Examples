//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: MatlabController_data.cpp
//
// Code generated for Simulink model 'MatlabController'.
//
// Model version                  : 12
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Thu Jan  7 09:33:54 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "MatlabController.h"

// Constant parameters (default storage)
const ConstP rtConstP = {
  // Expression: [e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S28>/Saturation1'

  { 15.7164049F, 15.7164049F, 1000.0F, 1000.0F, 1000.0F, 1000.0F },

  // Expression: -[e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S28>/Saturation1'

  { -15.7164049F, -15.7164049F, -1000.0F, -1000.0F, -1000.0F, -1000.0F },

  // Expression: [-cntrl.rm.w_max_climb,0,cntrl.rm.w_max_descend]
  //  Referenced by: '<S21>/1-D Lookup Table'

  { -6.0F, 0.0F, 4.0F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S21>/1-D Lookup Table'

  { -1.0F, 0.0F, 1.0F },

  // Computed Parameter: x_IC_o
  //  Referenced by: '<S36>/x'

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<S13>/1-D Lookup Table1'

  { -100000.0F, -100000.0F, 0.0F, 0.0F },

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<S13>/1-D Lookup Table1'

  { 0.0F, 0.1F, 0.2F, 1.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
