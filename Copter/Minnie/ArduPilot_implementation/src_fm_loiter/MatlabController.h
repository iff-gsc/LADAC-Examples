//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MatlabController.h
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
#ifndef RTW_HEADER_MatlabController_h_
#define RTW_HEADER_MatlabController_h_
#include "rtwtypes.h"
#include <cmath>
#include <string.h>
#ifndef ArduCopter_MinnieLoiterController_COMMON_INCLUDES_
# define ArduCopter_MinnieLoiterController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // ArduCopter_MinnieLoiterController_COMMON_INCLUDES_ 

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
  uint16_T mission_change;
  real32_T waypoints[40];
  uint16_T num_waypoints;
  real32_T RC_pwm[16];
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
  real32_T rangefinder[6];
} measureBus;

#endif

// Custom Type definition for MATLAB Function: '<S12>/DCM to quaternions'
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
  real32_T DiscreteTimeIntegrator_DSTATE[4];// '<S83>/Discrete-Time Integrator'
  real32_T UD_DSTATE[3];               // '<S36>/UD'
  real32_T DiscreteTimeIntegratory_DSTATE[3];// '<S71>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_DSTAT_m[3];// '<S72>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DSTA[3];// '<S71>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_DSTAT_h[3];// '<S73>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];// '<S34>/Discrete-Time Integrator' 
  real32_T UD_DSTATE_h[3];             // '<S7>/UD'
  real32_T DiscreteTimeIntegratory_DSTA_hs[6];// '<S35>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_DSTAT_i[3];// '<S74>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DS_b[6];// '<S35>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegrator_DSTAT_ki[2];// '<S22>/Discrete-Time Integrator' 
  real32_T UnitDelay1_DSTATE[4];       // '<S38>/Unit Delay1'
  real32_T DiscreteTimeIntegratory_DSTAT_g[4];// '<S44>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DS_j[4];// '<S44>/Discrete-Time Integrator y_dt' 
  real32_T Delay_DSTATE[4];            // '<S9>/Delay'
  real32_T DiscreteTimeIntegratory_dt_DS_g[3];// '<S74>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_dt_DS_c[3];// '<S73>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_dt_DS_p[3];// '<S72>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegrator_DSTATE_i;// '<S82>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator2_DSTATE;// '<S56>/Discrete-Time Integrator2'
  real32_T DiscreteTimeIntegrator_DSTATE_d;// '<S70>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator3_DSTATE;// '<S80>/Discrete-Time Integrator3'
  real32_T UD_DSTATE_a;                // '<S37>/UD'
  uint8_T DiscreteTimeIntegratory_IC_LOAD;// '<S72>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_LO_e;// '<S73>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_LO_j;// '<S74>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegrator2_IC_LOAD;// '<S56>/Discrete-Time Integrator2'
  uint8_T DiscreteTimeIntegrator3_IC_LOAD;// '<S80>/Discrete-Time Integrator3'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S22>/Discrete-Time Integrator'
} DW;

// Invariant block signals (default storage)
typedef const struct tag_ConstB {
  real32_T Gain2[3];                   // '<S21>/Gain2'
} ConstB;

// Constant parameters (default storage)
typedef struct {
  // Computed Parameter: ny_du_red_trim_Value
  //  Referenced by: '<S46>/ny_du_red_trim'

  real32_T ny_du_red_trim_Value[16];

  // Computed Parameter: ny_du_dt_Value
  //  Referenced by: '<S46>/ny_du_dt'

  real32_T ny_du_dt_Value[16];

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S47>/Constant5'

  real32_T Constant5_Value[16];

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S47>/Constant6'

  real32_T Constant6_Value[16];

  // Expression: [horiz_pos_cntrl.limits.e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S24>/Saturation1'

  real32_T Saturation1_UpperSat[6];

  // Expression: -[horiz_pos_cntrl.limits.e_xy_max;1000;1000;1000;1000]
  //  Referenced by: '<S24>/Saturation1'

  real32_T Saturation1_LowerSat[6];

  // Expression: horiz_pos_cntrl.K
  //  Referenced by: '<S24>/Gain'

  real32_T Gain_Gain_i[12];

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S80>/1-D Lookup Table'

  real32_T uDLookupTable_tableData[3];

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S80>/1-D Lookup Table'

  real32_T uDLookupTable_bp01Data[3];

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<S38>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData[4];

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<S38>/1-D Lookup Table1'

  real32_T uDLookupTable1_bp01Data[4];

  // Expression: atti_cntrl.K
  //  Referenced by: '<S53>/Gain'

  real32_T Gain_Gain_m[27];
} ConstP;

// External inputs (root inport signals with default storage)
typedef struct {
  cmdBus cmd;                          // '<Root>/cmd'
  measureBus measure;                  // '<Root>/measure'
} ExtU;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real32_T u[8];                       // '<Root>/u'
  real32_T logs[15];                   // '<Root>/logs'
} ExtY;

extern const ConstB rtConstB;          // constant block i/o

// Constant parameters (default storage)
extern const ConstP rtConstP;

// Class declaration for model ArduCopter_MinnieLoiterController
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
//  Block '<Root>/Constant' : Unused code path elimination
//  Block '<S2>/Constant' : Unused code path elimination
//  Block '<S12>/Scope' : Unused code path elimination
//  Block '<S7>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/Add4' : Unused code path elimination
//  Block '<S36>/Data Type Duplicate' : Unused code path elimination
//  Block '<S37>/Data Type Duplicate' : Unused code path elimination
//  Block '<S56>/Gain1' : Unused code path elimination
//  Block '<S56>/Gain2' : Unused code path elimination
//  Block '<S56>/Gain4' : Unused code path elimination
//  Block '<S56>/Gain5' : Unused code path elimination
//  Block '<S56>/Switch' : Unused code path elimination
//  Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S21>/Gain' : Eliminated nontunable gain of 1
//  Block '<S21>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S22>/Gain' : Eliminated nontunable gain of 1
//  Block '<S22>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S35>/Saturation' : Eliminated Saturate block
//  Block '<S47>/Reshape' : Reshape block reduction
//  Block '<S47>/Reshape1' : Reshape block reduction
//  Block '<S47>/Reshape2' : Reshape block reduction
//  Block '<S47>/Reshape4' : Reshape block reduction
//  Block '<S47>/Reshape5' : Reshape block reduction
//  Block '<S41>/Reshape' : Reshape block reduction
//  Block '<S41>/Reshape1' : Reshape block reduction
//  Block '<S41>/Reshape2' : Reshape block reduction
//  Block '<S51>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S56>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S56>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S56>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S56>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S56>/Gain' : Eliminated nontunable gain of 1
//  Block '<S56>/Gain3' : Eliminated nontunable gain of 1
//  Block '<S70>/Saturation' : Eliminated Saturate block
//  Block '<S71>/Saturation' : Eliminated Saturate block
//  Block '<S56>/Reshape' : Reshape block reduction
//  Block '<S72>/Saturation' : Eliminated Saturate block
//  Block '<S73>/Saturation' : Eliminated Saturate block
//  Block '<S74>/Saturation' : Eliminated Saturate block
//  Block '<S80>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S80>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S83>/Saturation' : Eliminated Saturate block
//  Block '<S44>/Saturation' : Eliminated Saturate block


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
//  '<Root>' : 'ArduCopter_MinnieLoiterController'
//  '<S1>'   : 'ArduCopter_MinnieLoiterController/Actuator muxer'
//  '<S2>'   : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode'
//  '<S3>'   : 'ArduCopter_MinnieLoiterController/Quaternions to Rotation Matrix'
//  '<S4>'   : 'ArduCopter_MinnieLoiterController/Rotations matrix to Euler angles'
//  '<S5>'   : 'ArduCopter_MinnieLoiterController/log muxer'
//  '<S6>'   : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands'
//  '<S7>'   : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Discrete Derivative'
//  '<S8>'   : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command'
//  '<S9>'   : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control'
//  '<S10>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/command direction'
//  '<S11>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/MATLAB Function1'
//  '<S12>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command'
//  '<S13>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/DCM to quaternions'
//  '<S14>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/MATLAB Function'
//  '<S15>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/MATLAB Function1'
//  '<S16>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/MATLAB Function4'
//  '<S17>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/quaternion to lean angles'
//  '<S18>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/total reduced attitude command (quaternion)'
//  '<S19>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/quaternion to lean angles/MATLAB Function4'
//  '<S20>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Delta attitude to stick commands/conversion to total attitude command/quaternion to lean angles/quaternion to  reduced attitude unit vector'
//  '<S21>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control'
//  '<S22>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/filtered command'
//  '<S23>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/measures'
//  '<S24>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/position controller'
//  '<S25>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control/MATLAB Function1'
//  '<S26>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control/MATLAB Function2'
//  '<S27>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control/MATLAB Function3'
//  '<S28>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control/MATLAB Function4'
//  '<S29>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control/MATLAB Function5'
//  '<S30>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control/MATLAB Function8'
//  '<S31>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/Convert to reduced attitude  pseudo control/MATLAB Function9'
//  '<S32>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/filtered command/MATLAB Function1'
//  '<S33>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/filtered command/PT1 discrete reference model'
//  '<S34>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/filtered command/PT1 discrete reference model/PT1 discrete with saturations'
//  '<S35>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Horizontal NDI position (NE) controller cascade with reduced attitude (angle) command/position controller/PT2 discrete with saturation'
//  '<S36>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Discrete Derivative'
//  '<S37>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Discrete Derivative1'
//  '<S38>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/INDI high level wls control allocation'
//  '<S39>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/MATLAB Function'
//  '<S40>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/MATLAB Function1'
//  '<S41>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller'
//  '<S42>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller'
//  '<S43>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/PT1 discrete reference model'
//  '<S44>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/PT2 discrete with saturation1'
//  '<S45>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/acceleration g to b frame'
//  '<S46>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/control effectiveness'
//  '<S47>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/INDI high level wls control allocation/INDI control allocation'
//  '<S48>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/INDI high level wls control allocation/MATLAB Function'
//  '<S49>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/INDI high level wls control allocation/INDI control allocation/MATLAB Function'
//  '<S50>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/INDI high level wls control allocation/INDI control allocation/MATLAB Function1'
//  '<S51>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/error computation'
//  '<S52>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/measure'
//  '<S53>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/ny control'
//  '<S54>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/ny from reference'
//  '<S55>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/ny measured'
//  '<S56>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model'
//  '<S57>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/error computation/angle error'
//  '<S58>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/error computation/wrap angle'
//  '<S59>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/error computation/wrap angle1'
//  '<S60>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/measure/DCM to quaternions'
//  '<S61>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/measure/MATLAB Function1'
//  '<S62>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/MATLAB Function'
//  '<S63>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/MATLAB Function1'
//  '<S64>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/PT1 discrete reference model2'
//  '<S65>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 discrete reference model'
//  '<S66>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/Subsystem'
//  '<S67>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/Subsystem1'
//  '<S68>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/Subsystem2'
//  '<S69>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/lean angles 2 lean vector'
//  '<S70>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/PT1 discrete reference model2/PT1 discrete with saturations'
//  '<S71>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 discrete reference model/PT2 discrete with saturation'
//  '<S72>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/Subsystem/PT2 discrete with saturation'
//  '<S73>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/Subsystem1/PT2 discrete with saturation'
//  '<S74>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter (Reduced) Attitude INDI Controller/reference model/Subsystem2/PT2 discrete with saturation'
//  '<S75>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/error computation'
//  '<S76>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/measure'
//  '<S77>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/ny control'
//  '<S78>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/ny from reference'
//  '<S79>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/ny measured'
//  '<S80>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/reference model'
//  '<S81>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/reference model/PT1 discrete reference model1'
//  '<S82>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/Multicopter Altitude INDI Controller/reference model/PT1 discrete reference model1/PT1 discrete with saturations'
//  '<S83>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/PT1 discrete reference model/PT1 discrete with saturations'
//  '<S84>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/acceleration g to b frame/dcm2Lean'
//  '<S85>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/acceleration g to b frame/MATLAB Function'
//  '<S86>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/Multicopter Altitude Hold Flight Mode with INDI and reduced attitude control/control effectiveness/MATLAB Function'
//  '<S87>'  : 'ArduCopter_MinnieLoiterController/Multicopter INDI Loiter Flight Mode/command direction/MATLAB Function'

#endif                                 // RTW_HEADER_MatlabController_h_

//
// File trailer for generated code.
//
// [EOF]
//
