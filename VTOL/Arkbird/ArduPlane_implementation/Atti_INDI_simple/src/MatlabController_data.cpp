//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: MatlabController_data.cpp
//
// Code generated for Simulink model 'MatlabController'.
//
// Model version                  : 1.392
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Nov  9 09:45:03 2020
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
  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S11>/Constant6'

  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/Constant'
  //    '<S5>/Constant'

  { 1.0F, 2.0F, 3.0F, 1.0F, 2.0F, 3.0F, 1.0F, 2.0F, 3.0F, 1.0F, 2.0F, 3.0F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/Constant3'
  //    '<S5>/Constant3'

  { 1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 2.0F, 3.0F, 3.0F, 3.0F, 4.0F, 4.0F, 4.0F },

  // Computed Parameter: nDLookupTable_tableData
  //  Referenced by: '<S4>/n-D Lookup Table'

  { -2.56997822E-7F, -0.0329232514F, -0.0250492077F, 2.57000352E-7F,
    -0.0329227559F, 0.0250467341F, 0.102651611F, 0.0F, 0.628441215F,
    -0.102653734F, 0.0F, -0.628459334F, -2.56997822E-7F, -0.0329232514F,
    -0.0250492077F, 2.57000352E-7F, -0.0329227559F, 0.0250467341F, 0.102651611F,
    0.0F, 0.628441215F, -0.102653734F, 0.0F, -0.628459334F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/n-D Lookup Table'
  //    '<S5>/n-D Lookup Table'
  //    '<S10>/Constant'
  //    '<S10>/FC rotation'

  { 1.0F, 2.0F, 3.0F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/n-D Lookup Table'
  //    '<S5>/n-D Lookup Table'

  { 1.0F, 2.0F, 3.0F, 4.0F },

  // Pooled Parameter (Expression: [0,10])
  //  Referenced by:
  //    '<S4>/n-D Lookup Table'
  //    '<S5>/n-D Lookup Table'
  //    '<S10>/FC rotation'

  { 0.0F, 10.0F },

  // Computed Parameter: nDLookupTable_tableData_e
  //  Referenced by: '<S5>/n-D Lookup Table'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, 0.0F, 0.0021F, 0.0F, 0.0F,
    -0.0021F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, 0.0F, 0.0021F, 0.0F,
    0.0F, -0.0021F },

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S11>/Constant5'

  { 1000.0F, 0.0F, 0.0F, 0.0F, 1000.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  // Computed Parameter: FCrotation_tableData
  //  Referenced by: '<S10>/FC rotation'

  { 0.0F, -1.57079637F, 0.0F, 0.0F, -1.57079637F, 0.0F },

  // Expression: cntrl.K
  //  Referenced by: '<S7>/Gain'

  { 14.3614F, 0.0F, 0.0F, 0.0F, 14.3614F, 0.0F, 0.0F, 0.0F, 7.5F, 100.0F, -0.0F,
    0.0F, -0.0F, 100.0F, -0.0F, -0.0F, 0.0F, 25.0F },

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S11>/1-D Lookup Table'

  { 1.0E-5F, 1000.0F, 1000.0F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S11>/1-D Lookup Table'

  { 1000.0F, 1200.0F, 2000.0F },

  // Pooled Parameter (Expression: [1100;1900])
  //  Referenced by:
  //    '<S12>/1-D Lookup Table'
  //    '<S12>/1-D Lookup Table1'

  { 1100.0F, 1900.0F },

  // Pooled Parameter (Expression: [cntrl.rm.minServo;cntrl.rm.maxServo])
  //  Referenced by:
  //    '<S12>/1-D Lookup Table'
  //    '<S12>/1-D Lookup Table1'

  { -0.436332315F, 0.436332315F }
};

//
// File trailer for generated code.
//
// [EOF]
//
