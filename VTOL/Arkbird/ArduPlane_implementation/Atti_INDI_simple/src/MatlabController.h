//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: MatlabController.h
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
#ifndef RTW_HEADER_MatlabController_h_
#define RTW_HEADER_MatlabController_h_
#include "rtwtypes.h"
#include <cmath>
#include <string.h>
#ifndef MatlabController_COMMON_INCLUDES_
# define MatlabController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // MatlabController_COMMON_INCLUDES_

// Macros for accessing real-time model data structure
#ifndef DEFINED_TYPEDEF_FOR_cmdBus_
#define DEFINED_TYPEDEF_FOR_cmdBus_

typedef struct {
  real32_T roll;
  real32_T pitch;
  real32_T yaw;
  real32_T thr;
} cmdBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_measureBus_
#define DEFINED_TYPEDEF_FOR_measureBus_

typedef struct {
  real32_T omega_Kb[3];
  real32_T EulerAngles[3];
  real32_T q_bg[4];
  real32_T a_Kg[3];
  real32_T V_Kg[3];
  real32_T s_Kg[3];
  real32_T lla[3];
} measureBus;

#endif

// Custom Type definition for MATLAB Function: '<S10>/Euler angles second derivate' 
#ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
#define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
  uint32_T SafeEq;
  uint32_T Absolute;
  uint32_T NaNBias;
  uint32_T NaNWithFinite;
  uint32_T FiniteWithNaN;
  uint32_T NaNWithNaN;
};

#endif                                 //struct_tag_skA4KFEZ4HPkJJBOYCrevdH

#ifndef typedef_skA4KFEZ4HPkJJBOYCrevdH
#define typedef_skA4KFEZ4HPkJJBOYCrevdH

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH skA4KFEZ4HPkJJBOYCrevdH;

#endif                                 //typedef_skA4KFEZ4HPkJJBOYCrevdH

#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 //struct_tag_sJCxfmxS8gBOONUZjbjUd9E

#ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E
#define typedef_sJCxfmxS8gBOONUZjbjUd9E

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E;

#endif                                 //typedef_sJCxfmxS8gBOONUZjbjUd9E

// Block signals and states (default storage) for system '<Root>'
typedef struct {
  real32_T x_DSTATE[2];                // '<S31>/x'
  real32_T x_dt_DSTATE[2];             // '<S31>/x_dt'
  real32_T x_DSTATE_k[3];              // '<S19>/x'
  real32_T UnitDelay_DSTATE[4];        // '<S2>/Unit Delay'
  real32_T x_DSTATE_m[4];              // '<S9>/x'
  real32_T x_dt_DSTATE_p[4];           // '<S9>/x_dt'
  real32_T A[2];                       // '<S8>/Discrete-Time Integrator'
  real32_T x_DSTATE_c[2];              // '<S26>/x'
  real32_T x_dt_DSTATE_k[3];           // '<S19>/x_dt'
  real32_T UD_DSTATE[3];               // '<S16>/UD'
  real32_T x_dt_DSTATE_d[2];           // '<S26>/x_dt'
  real32_T m_bpLambda[3];              // '<S4>/n-D Lookup Table'
  real32_T m_bpLambda_h[3];            // '<S5>/n-D Lookup Table'
  real32_T x_DSTATE_a;                 // '<S30>/x'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S14>/Discrete-Time Integrator'
  uint32_T m_bpIndex[36];              // '<S4>/n-D Lookup Table'
  uint32_T m_bpIndex_k[36];            // '<S5>/n-D Lookup Table'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S14>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S14>/Discrete-Time Integrator'
} DW;

// Constant parameters (default storage)
typedef struct {
  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S11>/Constant6'

  real32_T Constant6_Value[16];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/Constant'
  //    '<S5>/Constant'

  real32_T pooled3[12];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/Constant3'
  //    '<S5>/Constant3'

  real32_T pooled4[12];

  // Computed Parameter: nDLookupTable_tableData
  //  Referenced by: '<S4>/n-D Lookup Table'

  real32_T nDLookupTable_tableData[24];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/n-D Lookup Table'
  //    '<S5>/n-D Lookup Table'
  //    '<S10>/Constant'
  //    '<S10>/FC rotation'

  real32_T pooled5[3];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S4>/n-D Lookup Table'
  //    '<S5>/n-D Lookup Table'

  real32_T pooled6[4];

  // Pooled Parameter (Expression: [0,10])
  //  Referenced by:
  //    '<S4>/n-D Lookup Table'
  //    '<S5>/n-D Lookup Table'
  //    '<S10>/FC rotation'

  real32_T pooled7[2];

  // Computed Parameter: nDLookupTable_tableData_e
  //  Referenced by: '<S5>/n-D Lookup Table'

  real32_T nDLookupTable_tableData_e[24];

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S11>/Constant5'

  real32_T Constant5_Value[9];

  // Computed Parameter: FCrotation_tableData
  //  Referenced by: '<S10>/FC rotation'

  real32_T FCrotation_tableData[6];

  // Expression: cntrl.K
  //  Referenced by: '<S7>/Gain'

  real32_T Gain_Gain[18];

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S11>/1-D Lookup Table'

  real32_T uDLookupTable_tableData[3];

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S11>/1-D Lookup Table'

  real32_T uDLookupTable_bp01Data[3];

  // Pooled Parameter (Expression: [1100;1900])
  //  Referenced by:
  //    '<S12>/1-D Lookup Table'
  //    '<S12>/1-D Lookup Table1'

  real32_T pooled15[2];

  // Pooled Parameter (Expression: [cntrl.rm.minServo;cntrl.rm.maxServo])
  //  Referenced by:
  //    '<S12>/1-D Lookup Table'
  //    '<S12>/1-D Lookup Table1'

  real32_T pooled16[2];
} ConstP;

// External inputs (root inport signals with default storage)
typedef struct {
  cmdBus cmd;                          // '<Root>/cmd'
  measureBus measure;                  // '<Root>/measure'
} ExtU;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real32_T u[8];                       // '<Root>/u'
} ExtY;

// Constant parameters (default storage)
extern const ConstP rtConstP;

// Class declaration for model MatlabController
class MatlabControllerClass {
  // public data and function members
 public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  MatlabControllerClass();

  // Destructor
  ~MatlabControllerClass();

  // private data and function members
 private:
  // Block signals and states
  DW rtDW;

  // private member function(s) for subsystem '<Root>'
  void LSQFromQR(const real32_T A_data[], const int32_T A_size[2], const
                 real32_T tau_data[], const int32_T jpvt_data[], real32_T B_3[7],
                 int32_T rankA, real32_T Y_data[], int32_T *Y_size);
  real32_T xnrm2(int32_T n, const real32_T x_data[], int32_T ix0);
  void xzlarf(int32_T m, int32_T n, int32_T iv0, real32_T tau, real32_T C_data[],
              int32_T ic0, real32_T work_data[]);
  void qrsolve(const real32_T A_data[], const int32_T A_size[2], const real32_T
               B_1[7], real32_T Y_data[], int32_T *Y_size);
  void mldivide(const real32_T A_data[], const int32_T A_size[2], const real32_T
                B_0[7], real32_T Y_data[], int32_T *Y_size);
  boolean_T any(const boolean_T x_data[], const int32_T *x_size);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/Scope' : Unused code path elimination
//  Block '<S2>/Scope' : Unused code path elimination
//  Block '<S2>/Scope1' : Unused code path elimination
//  Block '<S2>/Scope2' : Unused code path elimination
//  Block '<S2>/Scope4' : Unused code path elimination
//  Block '<S2>/Scope6' : Unused code path elimination
//  Block '<S2>/Scope7' : Unused code path elimination
//  Block '<S16>/Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/Scope' : Unused code path elimination
//  Block '<S10>/Scope1' : Unused code path elimination
//  Block '<S10>/Scope2' : Unused code path elimination
//  Block '<S11>/Scope' : Unused code path elimination
//  Block '<S11>/Scope1' : Unused code path elimination
//  Block '<S11>/Scope2' : Unused code path elimination
//  Block '<S11>/Scope3' : Unused code path elimination
//  Block '<S13>/Scope' : Unused code path elimination
//  Block '<S13>/Scope1' : Unused code path elimination
//  Block '<S13>/Scope14' : Unused code path elimination
//  Block '<S13>/Scope16' : Unused code path elimination
//  Block '<S14>/Scope' : Unused code path elimination
//  Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S2>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S2>/Gain3' : Eliminated nontunable gain of 1
//  Block '<S2>/Gain4' : Eliminated nontunable gain of 1
//  Block '<S8>/Saturation' : Eliminated Saturate block
//  Block '<S9>/Saturation' : Eliminated Saturate block
//  Block '<S19>/Saturation' : Eliminated Saturate block
//  Block '<S11>/Reshape' : Reshape block reduction
//  Block '<S11>/Reshape1' : Reshape block reduction
//  Block '<S11>/Reshape2' : Reshape block reduction
//  Block '<S11>/Reshape4' : Reshape block reduction
//  Block '<S11>/Reshape5' : Reshape block reduction
//  Block '<S12>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S26>/Saturation' : Eliminated Saturate block
//  Block '<S30>/Saturation' : Eliminated Saturate block
//  Block '<S31>/Saturation' : Eliminated Saturate block


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'MatlabController'
//  '<S1>'   : 'MatlabController/Actuator muxer'
//  '<S2>'   : 'MatlabController/Atti INDI simple2'
//  '<S3>'   : 'MatlabController/output norm'
//  '<S4>'   : 'MatlabController/Atti INDI simple2/B'
//  '<S5>'   : 'MatlabController/Atti INDI simple2/B2'
//  '<S6>'   : 'MatlabController/Atti INDI simple2/Ground speed'
//  '<S7>'   : 'MatlabController/Atti INDI simple2/LQR for error regulation'
//  '<S8>'   : 'MatlabController/Atti INDI simple2/PT1 reference model'
//  '<S9>'   : 'MatlabController/Atti INDI simple2/PT2 discrete reference model1'
//  '<S10>'  : 'MatlabController/Atti INDI simple2/additional outputs computation'
//  '<S11>'  : 'MatlabController/Atti INDI simple2/control allocation'
//  '<S12>'  : 'MatlabController/Atti INDI simple2/elesvons'
//  '<S13>'  : 'MatlabController/Atti INDI simple2/error'
//  '<S14>'  : 'MatlabController/Atti INDI simple2/reference trajectory'
//  '<S15>'  : 'MatlabController/Atti INDI simple2/B/MATLAB Function'
//  '<S16>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/Discrete Derivative'
//  '<S17>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/Euler angles derivative'
//  '<S18>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/Euler angles second derivate'
//  '<S19>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/PT2 discrete reference model'
//  '<S20>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/Quaternions to Rotation Matrix'
//  '<S21>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/get attitude in FC frame'
//  '<S22>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/get attitude in FC frame/Euler Angles to Rotation Matrix'
//  '<S23>'  : 'MatlabController/Atti INDI simple2/additional outputs computation/get attitude in FC frame/Rotations matrix to Euler angles'
//  '<S24>'  : 'MatlabController/Atti INDI simple2/control allocation/MATLAB Function'
//  '<S25>'  : 'MatlabController/Atti INDI simple2/control allocation/MATLAB Function1'
//  '<S26>'  : 'MatlabController/Atti INDI simple2/elesvons/PT2 discrete reference model'
//  '<S27>'  : 'MatlabController/Atti INDI simple2/error/angle error'
//  '<S28>'  : 'MatlabController/Atti INDI simple2/error/wrap angle'
//  '<S29>'  : 'MatlabController/Atti INDI simple2/reference trajectory/Compare To Constant'
//  '<S30>'  : 'MatlabController/Atti INDI simple2/reference trajectory/PT1 discrete reference model'
//  '<S31>'  : 'MatlabController/Atti INDI simple2/reference trajectory/PT2 discrete reference model'
//  '<S32>'  : 'MatlabController/Atti INDI simple2/reference trajectory/wrap angle'
//  '<S33>'  : 'MatlabController/output norm/MATLAB Function'

#endif                                 // RTW_HEADER_MatlabController_h_

//
// File trailer for generated code.
//
// [EOF]
//
