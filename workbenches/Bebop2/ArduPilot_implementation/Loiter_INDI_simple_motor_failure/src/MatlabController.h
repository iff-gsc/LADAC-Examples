//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: MatlabController.h
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
  real32_T s_Kg_init[3];
  real32_T yaw_init;
  real32_T RC1_pwm;
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

#ifndef DEFINED_TYPEDEF_FOR_struct_aA933oIvocY9zUQb3NeE5C_
#define DEFINED_TYPEDEF_FOR_struct_aA933oIvocY9zUQb3NeE5C_

typedef struct {
  real_T omega;
  real_T D;
} struct_aA933oIvocY9zUQb3NeE5C;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_M2PQM8CIBuhDafozQTuwpG_
#define DEFINED_TYPEDEF_FOR_struct_M2PQM8CIBuhDafozQTuwpG_

typedef struct {
  real_T T;
} struct_M2PQM8CIBuhDafozQTuwpG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_VDaOuwBBsMjJJ9ezG2QtWC_
#define DEFINED_TYPEDEF_FOR_struct_VDaOuwBBsMjJJ9ezG2QtWC_

typedef struct {
  real32_T Phi_max;
  real32_T Theta_max;
  real32_T r_max;
  real_T uv_max;
  real_T uv_dt_max;
  real32_T w_max_climb;
  real32_T w_max_descend;
  struct_aA933oIvocY9zUQb3NeE5C Phi;
  struct_aA933oIvocY9zUQb3NeE5C Theta;
  struct_M2PQM8CIBuhDafozQTuwpG w;
  struct_M2PQM8CIBuhDafozQTuwpG u;
  real_T w_dt_max;
  real_T w_dt_min;
  real_T timeConstantMotor;
  struct_aA933oIvocY9zUQb3NeE5C acc_filter;
} struct_VDaOuwBBsMjJJ9ezG2QtWC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_uuVM5iCJRh0lWMg9ww4boE_
#define DEFINED_TYPEDEF_FOR_struct_uuVM5iCJRh0lWMg9ww4boE_

typedef struct {
  real_T u_min[4];
  real_T u_max[4];
  real_T u_d[4];
  real_T W_v[16];
  real_T W_u[16];
  real_T gamma;
  real_T W[4];
  real_T i_max;
} struct_uuVM5iCJRh0lWMg9ww4boE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_MEcmzRVPGSpBEP8QmwPNUF_
#define DEFINED_TYPEDEF_FOR_struct_MEcmzRVPGSpBEP8QmwPNUF_

typedef struct {
  struct_VDaOuwBBsMjJJ9ezG2QtWC rm;
  struct_uuVM5iCJRh0lWMg9ww4boE ca;
  real_T sample_time;
  real_T u_trim[4];
  real_T ny_du_red[16];
  real_T ny_du_dt[16];
  real32_T K[75];
  real32_T Kpos[12];
  real32_T Kpos_NDI[12];
  real32_T Kpos_I_NDI[4];
  real32_T e_xy_max[2];
  real_T enable_remote_control;
} struct_MEcmzRVPGSpBEP8QmwPNUF;

#endif

// Custom Type definition for MATLAB Function: '<Root>/Quaternions to Rotation Matrix' 
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
  real32_T x_DSTATE[4];                // '<S11>/x'
  real32_T x_DSTATE_f[4];              // '<S56>/x'
  real32_T x_dt_DSTATE[4];             // '<S56>/x_dt'
  real32_T DiscreteTimeIntegrator6_DSTATE[4];// '<S21>/Discrete-Time Integrator6' 
  real32_T x_DSTATE_g[2];              // '<S29>/x'
  real32_T DiscreteTimeIntegrator_DSTATE[2];// '<S27>/Discrete-Time Integrator'
  real32_T x_DSTATE_c[3];              // '<S38>/x'
  real32_T x_DSTATE_l[3];              // '<S39>/x'
  real32_T x_DSTATE_fe[3];             // '<S40>/x'
  real32_T x_DSTATE_c5[9];             // '<S36>/x'
  real32_T UnitDelay_DSTATE[4];        // '<S34>/Unit Delay'
  real32_T x_DSTATE_gw[3];             // '<S37>/x'
  real32_T UD_DSTATE[3];               // '<S35>/UD'
  real32_T x_dt_DSTATE_a[9];           // '<S36>/x_dt'
  real32_T UnitDelay1_DSTATE[4];       // '<S13>/Unit Delay1'
  real32_T DiscreteTimeIntegrator_DSTATE_n[4];// '<S10>/Discrete-Time Integrator' 
  real32_T UD_DSTATE_o[3];             // '<S2>/UD'
  real32_T UD_DSTATE_n[3];             // '<S3>/UD'
  real32_T UD_DSTATE_m[3];             // '<S4>/UD'
  real32_T DiscreteTimeIntegrator2_DSTATE[3];// '<Root>/Discrete-Time Integrator2' 
  real32_T DiscreteTimeIntegrator1_DSTATE[3];// '<Root>/Discrete-Time Integrator1' 
  real32_T x_dt_DSTATE_i[4];           // '<S11>/x_dt'
  real32_T Delay_DSTATE[4];            // '<S5>/Delay'
  real32_T x_dt_DSTATE_i0[3];          // '<S40>/x_dt'
  real32_T x_dt_DSTATE_e[3];           // '<S37>/x_dt'
  real32_T x_dt_DSTATE_j[3];           // '<S39>/x_dt'
  real32_T x_dt_DSTATE_f[3];           // '<S38>/x_dt'
  real32_T DiscreteTimeIntegrator_DSTATE_f[3];// '<Root>/Discrete-Time Integrator' 
  real32_T x_DSTATE_h;                 // '<S55>/x'
  real32_T DiscreteTimeIntegrator3_DSTATE;// '<S21>/Discrete-Time Integrator3'
  uint8_T DiscreteTimeIntegrator6_IC_LOAD;// '<S21>/Discrete-Time Integrator6'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S27>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator3_IC_LOAD;// '<S21>/Discrete-Time Integrator3'
} DW;

// Constant parameters (default storage)
typedef struct {
  // Expression: [e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S28>/Saturation1'

  real32_T Saturation1_UpperSat[6];

  // Expression: -[e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S28>/Saturation1'

  real32_T Saturation1_LowerSat[6];

  // Expression: [-cntrl.rm.w_max_climb,0,cntrl.rm.w_max_descend]
  //  Referenced by: '<S21>/1-D Lookup Table'

  real32_T uDLookupTable_tableData[3];

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S21>/1-D Lookup Table'

  real32_T uDLookupTable_bp01Data[3];

  // Computed Parameter: x_IC_o
  //  Referenced by: '<S36>/x'

  real32_T x_IC_o[9];

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<S13>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData[4];

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<S13>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data[4];
} ConstP;

// External inputs (root inport signals with default storage)
typedef struct {
  cmdBus cmd;                          // '<Root>/cmd'
  measureBus measure;                  // '<Root>/measure'
} ExtU;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real32_T u[23];                      // '<Root>/u'
} ExtY;

// Constant parameters (default storage)
extern const ConstP rtConstP;

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern struct_MEcmzRVPGSpBEP8QmwPNUF cntrl;// Variable: cntrl
                                           //  Referenced by:
                                           //    '<S7>/Saturation'
                                           //    '<S8>/Gain'
                                           //    '<S15>/Constant'
                                           //    '<S15>/Constant2'
                                           //    '<S15>/Constant4'
                                           //    '<S15>/ny_du_red_trim'
                                           //    '<S28>/Gain'
                                           //    '<S28>/Saturation'
                                           //    '<S31>/Constant1'
                                           //    '<S31>/Constant10'
                                           //    '<S31>/Constant3'
                                           //    '<S31>/Constant4'
                                           //    '<S31>/Constant5'
                                           //    '<S31>/Constant6'
                                           //    '<S31>/Constant7'
                                           //    '<S31>/Constant9'
                                           //    '<S55>/Saturation'
                                           //    '<S29>/Saturation'


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
  real32_T norm(const real32_T x[4]);
  void quatmultiply(const real32_T q[4], const real32_T r[4], real32_T qout[4]);
  void quatInv(const real32_T q[4], real32_T q_inv[4]);
  void quatNormalize(const real32_T quat[4], real32_T quat_normal[4]);
  void LSQFromQR(const real32_T A_data[], const int32_T A_size[2], const
                 real32_T tau_data[], const int32_T jpvt_data[], real32_T B_3[8],
                 int32_T rankA, real32_T Y_data[], int32_T *Y_size);
  real32_T xnrm2(int32_T n, const real32_T x_data[], int32_T ix0);
  void xzlarf(int32_T m, int32_T n, int32_T iv0, real32_T tau, real32_T C_data[],
              int32_T ic0, real32_T work_data[]);
  void qrsolve(const real32_T A_data[], const int32_T A_size[2], const real32_T
               B_1[8], real32_T Y_data[], int32_T *Y_size);
  void mldivide(const real32_T A_data[], const int32_T A_size[2], const real32_T
                B_0[8], real32_T Y_data[], int32_T *Y_size);
  boolean_T any(const boolean_T x_data[], const int32_T *x_size);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Data Type Duplicate' : Unused code path elimination
//  Block '<S3>/Data Type Duplicate' : Unused code path elimination
//  Block '<S4>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/Scope' : Unused code path elimination
//  Block '<S5>/Scope1' : Unused code path elimination
//  Block '<S5>/Scope17' : Unused code path elimination
//  Block '<S5>/Scope2' : Unused code path elimination
//  Block '<S5>/Scope6' : Unused code path elimination
//  Block '<S5>/Scope8' : Unused code path elimination
//  Block '<S5>/Scope9' : Unused code path elimination
//  Block '<S13>/Scope7' : Unused code path elimination
//  Block '<S35>/Data Type Duplicate' : Unused code path elimination
//  Block '<S20>/Scope3' : Unused code path elimination
//  Block '<S21>/Scope1' : Unused code path elimination
//  Block '<S21>/Scope9' : Unused code path elimination
//  Block '<S10>/Saturation' : Eliminated Saturate block
//  Block '<S11>/Saturation' : Eliminated Saturate block
//  Block '<S31>/Reshape' : Reshape block reduction
//  Block '<S31>/Reshape1' : Reshape block reduction
//  Block '<S31>/Reshape2' : Reshape block reduction
//  Block '<S31>/Reshape4' : Reshape block reduction
//  Block '<S31>/Reshape5' : Reshape block reduction
//  Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S14>/Gain' : Eliminated nontunable gain of 1
//  Block '<S14>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S14>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S14>/Gain3' : Eliminated nontunable gain of 1
//  Block '<S36>/Saturation' : Eliminated Saturate block
//  Block '<S37>/Saturation' : Eliminated Saturate block
//  Block '<S38>/Saturation' : Eliminated Saturate block
//  Block '<S39>/Saturation' : Eliminated Saturate block
//  Block '<S40>/Saturation' : Eliminated Saturate block
//  Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S21>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S21>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S56>/Saturation' : Eliminated Saturate block


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
//  '<S1>'   : 'MatlabController/Actuator//log muxer'
//  '<S2>'   : 'MatlabController/Discrete Derivative'
//  '<S3>'   : 'MatlabController/Discrete Derivative1'
//  '<S4>'   : 'MatlabController/Discrete Derivative2'
//  '<S5>'   : 'MatlabController/Loiter INDI simple (NE) quaternion'
//  '<S6>'   : 'MatlabController/Quaternions to Rotation Matrix'
//  '<S7>'   : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1'
//  '<S8>'   : 'MatlabController/Loiter INDI simple (NE) quaternion/LQR for error regulation1'
//  '<S9>'   : 'MatlabController/Loiter INDI simple (NE) quaternion/MATLAB Function5'
//  '<S10>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/PT1 reference model1'
//  '<S11>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/PT2 discrete reference model3'
//  '<S12>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Quaternions to Euler angles'
//  '<S13>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Subsystem'
//  '<S14>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering'
//  '<S15>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/control effectiveness'
//  '<S16>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/convert control command to ny'
//  '<S17>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/error computation'
//  '<S18>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/ny from reference'
//  '<S19>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/ny measured'
//  '<S20>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reduced attitude'
//  '<S21>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model'
//  '<S22>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/MATLAB Function1'
//  '<S23>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/MATLAB Function11'
//  '<S24>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/MATLAB Function2'
//  '<S25>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/MATLAB Function8'
//  '<S26>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/MATLAB Function9'
//  '<S27>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/filtered command'
//  '<S28>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/position controller'
//  '<S29>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Horizontal INDI position (NE) controller cascade with reduced attitude increment (quaternion) command1/filtered command/PT1 discrete reference model'
//  '<S30>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/LQR for error regulation1/MATLAB Function'
//  '<S31>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Subsystem/INDI control allocation'
//  '<S32>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Subsystem/INDI control allocation/MATLAB Function'
//  '<S33>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/Subsystem/INDI control allocation/MATLAB Function1'
//  '<S34>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/DCM 2 q_bg continuous1'
//  '<S35>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/Discrete Derivative'
//  '<S36>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/Sensor filter'
//  '<S37>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/Sensor filter1'
//  '<S38>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/Sensor filter2'
//  '<S39>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/Sensor filter3'
//  '<S40>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/Sensor filter4'
//  '<S41>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/quaternion time derivative'
//  '<S42>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/additional outputs computation and filtering/DCM 2 q_bg continuous1/MATLAB Function3'
//  '<S43>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/control effectiveness/MATLAB Function'
//  '<S44>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/convert control command to ny/MATLAB Function1'
//  '<S45>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/convert control command to ny/MATLAB Function3'
//  '<S46>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/error computation/MATLAB Function2'
//  '<S47>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/ny from reference/MATLAB Function'
//  '<S48>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/ny from reference/MATLAB Function1'
//  '<S49>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reduced attitude/MATLAB Function1'
//  '<S50>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reduced attitude/MATLAB Function3'
//  '<S51>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model/Euler Angles to Quaternions'
//  '<S52>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model/MATLAB Function2'
//  '<S53>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model/MATLAB Function6'
//  '<S54>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model/MATLAB Function7'
//  '<S55>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model/PT1 discrete reference model1'
//  '<S56>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model/PT2 discrete reference model'
//  '<S57>'  : 'MatlabController/Loiter INDI simple (NE) quaternion/reference model/PT2 discrete reference model/MATLAB Function'

#endif                                 // RTW_HEADER_MatlabController_h_

//
// File trailer for generated code.
//
// [EOF]
//
