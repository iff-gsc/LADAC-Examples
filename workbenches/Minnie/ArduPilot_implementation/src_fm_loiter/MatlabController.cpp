//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MatlabController.cpp
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

extern real32_T rt_hypotf(real32_T u0, real32_T u1);
static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
static void DCMtoquaternions(const real32_T rtu_M_bg[9], real32_T rty_q_bg[4]);
static void MATLABFunction4(const real32_T rtu_n_g[3], real32_T *rty_phi,
  real32_T *rty_delta);
static void MATLABFunction3(real32_T rtu_phi, real32_T rtu_delta, real32_T
  rty_q_cmd_red[4]);
static void wrapangle(real32_T rtu_angle, real32_T *rty_angle_0_2pi);
static void MATLABFunction(const real32_T rtu_omega_Kb[3], const real32_T
  rtu_omega_Kb_dt[3], const real32_T rtu_M_bg[9], const real32_T rtu_n_g_d[3],
  const real32_T rtu_n_g_d_dt[3], const real32_T rtu_n_g_d_dt2[3], real32_T
  rty_n_b_d[3], real32_T rty_n_b_d_dt[3], real32_T rty_n_b_d_dt2[3]);

// Forward declaration for local functions
static real32_T norm(const real32_T x[3]);
static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

//
// Output and update for atomic system:
//    '<S12>/DCM to quaternions'
//    '<S52>/DCM to quaternions'
//
static void DCMtoquaternions(const real32_T rtu_M_bg[9], real32_T rty_q_bg[4])
{
  real32_T q_0;
  real32_T q_1;
  real32_T q_2;
  real32_T q_3;
  real32_T ex;
  int32_T idx;
  q_0 = ((1.0F + rtu_M_bg[0]) + rtu_M_bg[4]) + rtu_M_bg[8];
  if (0.0F >= q_0) {
    q_0 = 0.0F;
  }

  q_0 = 0.5F * std::sqrt(q_0);
  q_1 = ((1.0F + rtu_M_bg[0]) - rtu_M_bg[4]) - rtu_M_bg[8];
  if (0.0F >= q_1) {
    q_1 = 0.0F;
  }

  q_1 = 0.5F * std::sqrt(q_1);
  q_2 = ((1.0F - rtu_M_bg[0]) + rtu_M_bg[4]) - rtu_M_bg[8];
  if (0.0F >= q_2) {
    q_2 = 0.0F;
  }

  q_2 = 0.5F * std::sqrt(q_2);
  q_3 = ((1.0F - rtu_M_bg[0]) - rtu_M_bg[4]) + rtu_M_bg[8];
  if (0.0F >= q_3) {
    q_3 = 0.0F;
  }

  q_3 = 0.5F * std::sqrt(q_3);
  ex = q_0;
  idx = -1;
  if (q_0 < q_1) {
    ex = q_1;
    idx = 0;
  }

  if (ex < q_2) {
    ex = q_2;
    idx = 1;
  }

  if (ex < q_3) {
    idx = 2;
  }

  switch (idx + 1) {
   case 0:
    ex = rtu_M_bg[7] - rtu_M_bg[5];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_1 *= ex;
    ex = rtu_M_bg[2] - rtu_M_bg[6];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_2 *= ex;
    ex = rtu_M_bg[3] - rtu_M_bg[1];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_3 *= ex;
    break;

   case 1:
    ex = rtu_M_bg[7] - rtu_M_bg[5];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_0 *= ex;
    ex = rtu_M_bg[3] + rtu_M_bg[1];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_2 *= ex;
    ex = rtu_M_bg[2] + rtu_M_bg[6];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_3 *= ex;
    break;

   case 2:
    ex = rtu_M_bg[2] - rtu_M_bg[6];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_0 *= ex;
    ex = rtu_M_bg[3] + rtu_M_bg[1];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_1 *= ex;
    ex = rtu_M_bg[7] + rtu_M_bg[5];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_3 *= ex;
    break;

   case 3:
    ex = rtu_M_bg[3] - rtu_M_bg[1];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_0 *= ex;
    ex = rtu_M_bg[2] + rtu_M_bg[6];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_1 *= ex;
    ex = rtu_M_bg[7] + rtu_M_bg[5];
    if (ex < 0.0F) {
      ex = -1.0F;
    } else {
      if (ex > 0.0F) {
        ex = 1.0F;
      }
    }

    q_2 *= ex;
    break;
  }

  rty_q_bg[0] = q_0;
  rty_q_bg[1] = q_1;
  rty_q_bg[2] = q_2;
  rty_q_bg[3] = q_3;
  q_1 = 1.29246971E-26F;
  q_2 = std::abs(rty_q_bg[0]);
  if (q_2 > 1.29246971E-26F) {
    q_0 = 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / 1.29246971E-26F;
    q_0 = q_3 * q_3;
  }

  q_2 = std::abs(rty_q_bg[1]);
  if (q_2 > q_1) {
    q_3 = q_1 / q_2;
    q_0 = q_0 * q_3 * q_3 + 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / q_1;
    q_0 += q_3 * q_3;
  }

  q_2 = std::abs(rty_q_bg[2]);
  if (q_2 > q_1) {
    q_3 = q_1 / q_2;
    q_0 = q_0 * q_3 * q_3 + 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / q_1;
    q_0 += q_3 * q_3;
  }

  q_2 = std::abs(rty_q_bg[3]);
  if (q_2 > q_1) {
    q_3 = q_1 / q_2;
    q_0 = q_0 * q_3 * q_3 + 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / q_1;
    q_0 += q_3 * q_3;
  }

  q_0 = q_1 * std::sqrt(q_0);
  if (0.01 >= q_0) {
    q_0 = 0.01F;
  }

  rty_q_bg[0] /= q_0;
  rty_q_bg[1] /= q_0;
  rty_q_bg[2] /= q_0;
  rty_q_bg[3] /= q_0;
}

//
// Output and update for atomic system:
//    '<S12>/MATLAB Function4'
//    '<S17>/MATLAB Function4'
//
static void MATLABFunction4(const real32_T rtu_n_g[3], real32_T *rty_phi,
  real32_T *rty_delta)
{
  real32_T minval;
  if (1.0F > -rtu_n_g[2]) {
    minval = -rtu_n_g[2];
  } else {
    minval = 1.0F;
  }

  *rty_delta = std::atan2(rtu_n_g[1], rtu_n_g[0]);
  if (-1.0F >= minval) {
    minval = -1.0F;
  }

  *rty_phi = std::acos(minval);
}

//
// Output and update for atomic system:
//    '<S21>/MATLAB Function3'
//    '<S21>/MATLAB Function8'
//
static void MATLABFunction3(real32_T rtu_phi, real32_T rtu_delta, real32_T
  rty_q_cmd_red[4])
{
  real32_T x;
  real32_T xy;
  real32_T b_x;
  real32_T b_x_tmp;
  x = std::sin(rtu_delta);
  b_x_tmp = std::cos(rtu_delta);
  xy = std::sqrt(x * x + -b_x_tmp * -b_x_tmp);
  if (xy <= 0.01) {
    x = 1.0F;
    xy = std::sqrt(-b_x_tmp * -b_x_tmp + 1.0F);
  }

  b_x = 1.0F / xy;
  xy = std::sin(rtu_phi / 2.0F);
  rty_q_cmd_red[0] = std::cos(rtu_phi / 2.0F);
  rty_q_cmd_red[1] = b_x * x * xy;
  rty_q_cmd_red[2] = b_x * -b_x_tmp * xy;
  rty_q_cmd_red[3] = 0.0F;
}

//
// Output and update for atomic system:
//    '<S51>/wrap angle'
//    '<S51>/wrap angle1'
//
static void wrapangle(real32_T rtu_angle, real32_T *rty_angle_0_2pi)
{
  real32_T x;
  x = std::abs(rtu_angle);
  x -= std::floor(x / 6.28318548F) * 6.28318548F;
  if (rtu_angle >= 0.0F) {
    *rty_angle_0_2pi = x;
  } else {
    *rty_angle_0_2pi = 6.28318548F - x;
  }
}

// Function for MATLAB Function: '<S56>/MATLAB Function'
static real32_T norm(const real32_T x[3])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = std::abs(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

//
// Output and update for atomic system:
//    '<S56>/MATLAB Function'
//    '<S56>/MATLAB Function1'
//
static void MATLABFunction(const real32_T rtu_omega_Kb[3], const real32_T
  rtu_omega_Kb_dt[3], const real32_T rtu_M_bg[9], const real32_T rtu_n_g_d[3],
  const real32_T rtu_n_g_d_dt[3], const real32_T rtu_n_g_d_dt2[3], real32_T
  rty_n_b_d[3], real32_T rty_n_b_d_dt[3], real32_T rty_n_b_d_dt2[3])
{
  real32_T absxk;
  int32_T exponent;
  real32_T y;
  real32_T scale;
  real32_T b_absxk;
  real32_T t;
  real32_T rtu_omega_Kb_0[3];
  real32_T rtu_omega_Kb_dt_0[3];
  real32_T tmp[9];
  real32_T rtu_M_bg_0[9];
  int32_T i;
  int32_T i_0;
  int32_T rtu_M_bg_tmp;
  int32_T rtu_M_bg_tmp_0;
  for (i = 0; i < 3; i++) {
    rty_n_b_d[i] = 0.0F;
    rty_n_b_d[i] += rtu_M_bg[i] * rtu_n_g_d[0];
    rty_n_b_d[i] += rtu_M_bg[i + 3] * rtu_n_g_d[1];
    rty_n_b_d[i] += rtu_M_bg[i + 6] * rtu_n_g_d[2];
  }

  rtu_omega_Kb_0[0] = -(rtu_omega_Kb[1] * rty_n_b_d[2] - rtu_omega_Kb[2] *
                        rty_n_b_d[1]);
  rtu_omega_Kb_0[1] = -(rtu_omega_Kb[2] * rty_n_b_d[0] - rtu_omega_Kb[0] *
                        rty_n_b_d[2]);
  rtu_omega_Kb_0[2] = -(rtu_omega_Kb[0] * rty_n_b_d[1] - rtu_omega_Kb[1] *
                        rty_n_b_d[0]);
  for (i = 0; i < 3; i++) {
    rty_n_b_d_dt[i] = rtu_omega_Kb_0[i] + (rtu_M_bg[i + 6] * rtu_n_g_d_dt[2] +
      (rtu_M_bg[i + 3] * rtu_n_g_d_dt[1] + rtu_M_bg[i] * rtu_n_g_d_dt[0]));
  }

  rtu_omega_Kb_dt_0[0] = -(rtu_omega_Kb_dt[1] * rty_n_b_d[2] - rtu_omega_Kb_dt[2]
    * rty_n_b_d[1]);
  rtu_omega_Kb_dt_0[1] = -(rtu_omega_Kb_dt[2] * rty_n_b_d[0] - rtu_omega_Kb_dt[0]
    * rty_n_b_d[2]);
  rtu_omega_Kb_dt_0[2] = -(rtu_omega_Kb_dt[0] * rty_n_b_d[1] - rtu_omega_Kb_dt[1]
    * rty_n_b_d[0]);
  rtu_omega_Kb_0[0] = rtu_omega_Kb[1] * rty_n_b_d_dt[2] - rtu_omega_Kb[2] *
    rty_n_b_d_dt[1];
  rtu_omega_Kb_0[1] = rtu_omega_Kb[2] * rty_n_b_d_dt[0] - rtu_omega_Kb[0] *
    rty_n_b_d_dt[2];
  rtu_omega_Kb_0[2] = rtu_omega_Kb[0] * rty_n_b_d_dt[1] - rtu_omega_Kb[1] *
    rty_n_b_d_dt[0];
  tmp[0] = 0.0F;
  tmp[3] = -rtu_omega_Kb[2];
  tmp[6] = rtu_omega_Kb[1];
  tmp[1] = rtu_omega_Kb[2];
  tmp[4] = 0.0F;
  tmp[7] = -rtu_omega_Kb[0];
  tmp[2] = -rtu_omega_Kb[1];
  tmp[5] = rtu_omega_Kb[0];
  tmp[8] = 0.0F;
  for (i = 0; i < 3; i++) {
    absxk = 0.0F;
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_M_bg_tmp = i + 3 * i_0;
      rtu_M_bg_0[rtu_M_bg_tmp] = 0.0F;
      rtu_M_bg_tmp_0 = 3 * i_0 + i;
      rtu_M_bg_0[rtu_M_bg_tmp] = rtu_M_bg_0[rtu_M_bg_tmp_0] + rtu_M_bg[3 * i_0] *
        tmp[3 * i];
      rtu_M_bg_0[rtu_M_bg_tmp] = rtu_M_bg[3 * i_0 + 1] * tmp[3 * i + 1] +
        rtu_M_bg_0[rtu_M_bg_tmp_0];
      rtu_M_bg_0[rtu_M_bg_tmp] = rtu_M_bg[3 * i_0 + 2] * tmp[3 * i + 2] +
        rtu_M_bg_0[rtu_M_bg_tmp_0];
      absxk += rtu_M_bg_0[rtu_M_bg_tmp_0] * rtu_n_g_d_dt[i_0];
    }

    rty_n_b_d_dt2[i] = ((rtu_omega_Kb_dt_0[i] - rtu_omega_Kb_0[i]) + absxk) +
      (rtu_M_bg[i + 6] * rtu_n_g_d_dt2[2] + (rtu_M_bg[i + 3] * rtu_n_g_d_dt2[1]
        + rtu_M_bg[i] * rtu_n_g_d_dt2[0]));
  }

  if (rty_n_b_d[2] > 0.0F) {
    rty_n_b_d[2] = 0.0F;
    t = std::abs(rty_n_b_d[0]);
    if (t <= 1.17549435E-38F) {
      absxk = 1.4013E-45F;
    } else {
      std::frexp(t, &exponent);
      absxk = std::ldexp(1.0F, exponent - 24);
    }

    scale = 1.29246971E-26F;
    if (t > 1.29246971E-26F) {
      y = 1.0F;
      scale = t;
    } else {
      t /= 1.29246971E-26F;
      y = t * t;
    }

    b_absxk = std::abs(rty_n_b_d[1]);
    if (b_absxk > scale) {
      t = scale / b_absxk;
      y = y * t * t + 1.0F;
      scale = b_absxk;
    } else {
      t = b_absxk / scale;
      y += t * t;
    }

    y = scale * std::sqrt(y);
    absxk += y;
    rty_n_b_d[0] += (rty_n_b_d[0] / absxk - rty_n_b_d[0]) * 2.0F;
    rty_n_b_d[1] += (rty_n_b_d[1] / absxk - rty_n_b_d[1]) * 2.0F;
    if (norm(rty_n_b_d) < 0.9) {
      rty_n_b_d[0] = -1.0F;
      absxk = norm(rty_n_b_d);
      rty_n_b_d[0] /= absxk;
      rty_n_b_d[1] /= absxk;
      rty_n_b_d[2] /= absxk;
    }

    rty_n_b_d_dt[0] = -rty_n_b_d_dt[0] * 0.2F;
    rty_n_b_d_dt2[0] = -rty_n_b_d_dt2[0] * 0.2F;
    rty_n_b_d_dt[1] = -rty_n_b_d_dt[1] * 0.2F;
    rty_n_b_d_dt2[1] = -rty_n_b_d_dt2[1] * 0.2F;
    rty_n_b_d_dt[2] = -rty_n_b_d_dt[2] * 0.2F;
    rty_n_b_d_dt2[2] = -rty_n_b_d_dt2[2] * 0.2F;
  }
}

// Function for MATLAB Function: '<S52>/MATLAB Function1'
void MatlabControllerClass::quatNormalize(const real32_T quat[4], real32_T
  quat_normal[4])
{
  real32_T quat_norm;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = std::abs(quat[0]);
  if (absxk > 1.29246971E-26F) {
    quat_norm = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    quat_norm = t * t;
  }

  absxk = std::abs(quat[1]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(quat[2]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(quat[3]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  quat_norm = scale * std::sqrt(quat_norm);
  if (0.01 >= quat_norm) {
    quat_norm = 0.01F;
  }

  quat_normal[0] = quat[0] / quat_norm;
  quat_normal[1] = quat[1] / quat_norm;
  quat_normal[2] = quat[2] / quat_norm;
  quat_normal[3] = quat[3] / quat_norm;
}

// Function for MATLAB Function: '<S47>/MATLAB Function'
void MatlabControllerClass::LSQFromQR(const real32_T A_data[], const int32_T
  A_size[2], const real32_T tau_data[], const int32_T jpvt_data[], real32_T B_3
  [8], int32_T rankA, real32_T Y_data[], int32_T *Y_size)
{
  int32_T b_i;
  real32_T wj;
  int32_T b_j;
  int32_T loop_ub;
  int8_T b_idx_0;
  b_idx_0 = (int8_T)A_size[1];
  *Y_size = b_idx_0;
  if (0 <= b_idx_0 - 1) {
    memset(&Y_data[0], 0, b_idx_0 * sizeof(real32_T));
  }

  for (b_j = 0; b_j < A_size[1]; b_j++) {
    if (tau_data[b_j] != 0.0F) {
      wj = B_3[b_j];
      for (loop_ub = b_j + 1; loop_ub + 1 < 9; loop_ub++) {
        wj += A_data[(b_j << 3) + loop_ub] * B_3[loop_ub];
      }

      wj *= tau_data[b_j];
      if (wj != 0.0F) {
        B_3[b_j] -= wj;
        for (loop_ub = b_j + 1; loop_ub + 1 < 9; loop_ub++) {
          B_3[loop_ub] -= A_data[(b_j << 3) + loop_ub] * wj;
        }
      }
    }
  }

  for (loop_ub = 0; loop_ub < rankA; loop_ub++) {
    Y_data[jpvt_data[loop_ub] - 1] = B_3[loop_ub];
  }

  for (loop_ub = rankA - 1; loop_ub + 1 > 0; loop_ub--) {
    b_j = loop_ub << 3;
    Y_data[jpvt_data[loop_ub] - 1] /= A_data[b_j + loop_ub];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Y_data[jpvt_data[b_i] - 1] -= A_data[b_j + b_i] * Y_data[jpvt_data[loop_ub]
        - 1];
    }
  }
}

// Function for MATLAB Function: '<S47>/MATLAB Function'
real32_T MatlabControllerClass::xnrm2(int32_T n, const real32_T x_data[],
  int32_T ix0)
{
  real32_T y;
  real32_T scale;
  int32_T kend;
  real32_T absxk;
  real32_T t;
  int32_T k;
  y = 0.0F;
  scale = 1.29246971E-26F;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = std::abs(x_data[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0F;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

real32_T rt_hypotf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T a;
  real32_T b;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0F) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0F) * a;
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

// Function for MATLAB Function: '<S47>/MATLAB Function'
void MatlabControllerClass::xzlarf(int32_T m, int32_T n, int32_T iv0, real32_T
  tau, real32_T C_data[], int32_T ic0, real32_T work_data[])
{
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ix;
  real32_T c;
  int32_T iac;
  int32_T d;
  int32_T b_ia;
  int32_T jy;
  int32_T exitg1;
  boolean_T exitg2;
  if (tau != 0.0F) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C_data[lastc - 2] == 0.0F)) {
      lastv--;
      lastc--;
    }

    lastc = n - 1;
    exitg2 = false;
    while ((!exitg2) && (lastc + 1 > 0)) {
      coltop = (lastc << 3) + ic0;
      jy = coltop;
      do {
        exitg1 = 0;
        if (jy <= (coltop + lastv) - 1) {
          if (C_data[jy - 1] != 0.0F) {
            exitg1 = 1;
          } else {
            jy++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = -1;
  }

  if (lastv > 0) {
    if (lastc + 1 != 0) {
      for (coltop = 0; coltop <= lastc; coltop++) {
        work_data[coltop] = 0.0F;
      }

      coltop = 0;
      jy = (lastc << 3) + ic0;
      for (iac = ic0; iac <= jy; iac += 8) {
        ix = iv0;
        c = 0.0F;
        d = (iac + lastv) - 1;
        for (b_ia = iac; b_ia <= d; b_ia++) {
          c += C_data[b_ia - 1] * C_data[ix - 1];
          ix++;
        }

        work_data[coltop] += c;
        coltop++;
      }
    }

    if (-tau != 0.0F) {
      coltop = ic0 - 1;
      jy = 0;
      for (iac = 0; iac <= lastc; iac++) {
        if (work_data[jy] != 0.0F) {
          c = work_data[jy] * -tau;
          ix = iv0;
          d = lastv + coltop;
          for (b_ia = coltop; b_ia < d; b_ia++) {
            C_data[b_ia] += C_data[ix - 1] * c;
            ix++;
          }
        }

        jy++;
        coltop += 8;
      }
    }
  }
}

// Function for MATLAB Function: '<S47>/MATLAB Function'
void MatlabControllerClass::qrsolve(const real32_T A_data[], const int32_T
  A_size[2], const real32_T B_1[8], real32_T Y_data[], int32_T *Y_size)
{
  real32_T b_A_data[32];
  real32_T tau_data[4];
  int32_T jpvt_data[4];
  int32_T n;
  real32_T work_data[4];
  real32_T vn1_data[4];
  real32_T vn2_data[4];
  int32_T nmi;
  int32_T b_n;
  int32_T yk;
  int32_T idxmax;
  int32_T ix;
  real32_T smax;
  real32_T s;
  int32_T b_ix;
  int32_T iy;
  real32_T absxk;
  real32_T t;
  real32_T B_2[8];
  int32_T b_A_size[2];
  int8_T c_idx_0;
  b_A_size[0] = 8;
  b_A_size[1] = A_size[1];
  b_n = A_size[0] * A_size[1] - 1;
  if (0 <= b_n) {
    memcpy(&b_A_data[0], &A_data[0], (b_n + 1) * sizeof(real32_T));
  }

  n = A_size[1];
  if (A_size[1] < 1) {
    b_n = 0;
  } else {
    b_n = A_size[1];
  }

  if (b_n > 0) {
    jpvt_data[0] = 1;
    yk = 1;
    for (nmi = 2; nmi <= b_n; nmi++) {
      yk++;
      jpvt_data[nmi - 1] = yk;
    }
  }

  if (A_size[1] != 0) {
    c_idx_0 = (int8_T)A_size[1];
    if (0 <= c_idx_0 - 1) {
      memset(&work_data[0], 0, c_idx_0 * sizeof(real32_T));
    }

    b_n = 1;
    for (yk = 0; yk < n; yk++) {
      smax = 0.0F;
      s = 1.29246971E-26F;
      for (nmi = b_n; nmi <= b_n + 7; nmi++) {
        absxk = std::abs(A_data[nmi - 1]);
        if (absxk > s) {
          t = s / absxk;
          smax = smax * t * t + 1.0F;
          s = absxk;
        } else {
          t = absxk / s;
          smax += t * t;
        }
      }

      vn1_data[yk] = s * std::sqrt(smax);
      vn2_data[yk] = vn1_data[yk];
      b_n += 8;
    }

    for (b_n = 0; b_n < n; b_n++) {
      iy = b_n << 3;
      yk = iy + b_n;
      nmi = n - b_n;
      if (nmi < 1) {
        idxmax = 0;
      } else {
        idxmax = 1;
        if (nmi > 1) {
          ix = b_n;
          smax = std::abs(vn1_data[b_n]);
          for (b_ix = 2; b_ix <= nmi; b_ix++) {
            ix++;
            s = std::abs(vn1_data[ix]);
            if (s > smax) {
              idxmax = b_ix;
              smax = s;
            }
          }
        }
      }

      ix = (b_n + idxmax) - 1;
      if (ix + 1 != b_n + 1) {
        b_ix = ix << 3;
        for (idxmax = 0; idxmax < 8; idxmax++) {
          smax = b_A_data[b_ix];
          b_A_data[b_ix] = b_A_data[iy];
          b_A_data[iy] = smax;
          b_ix++;
          iy++;
        }

        b_ix = jpvt_data[ix];
        jpvt_data[ix] = jpvt_data[b_n];
        jpvt_data[b_n] = b_ix;
        vn1_data[ix] = vn1_data[b_n];
        vn2_data[ix] = vn2_data[b_n];
      }

      smax = b_A_data[yk];
      tau_data[b_n] = 0.0F;
      s = xnrm2(7 - b_n, b_A_data, yk + 2);
      if (s != 0.0F) {
        s = rt_hypotf(b_A_data[yk], s);
        if (b_A_data[yk] >= 0.0F) {
          s = -s;
        }

        if (std::abs(s) < 9.86076132E-32F) {
          ix = -1;
          b_ix = (yk - b_n) + 8;
          do {
            ix++;
            for (iy = yk + 1; iy < b_ix; iy++) {
              b_A_data[iy] *= 1.01412048E+31F;
            }

            s *= 1.01412048E+31F;
            smax *= 1.01412048E+31F;
          } while (std::abs(s) < 9.86076132E-32F);

          s = rt_hypotf(smax, xnrm2(7 - b_n, b_A_data, yk + 2));
          if (smax >= 0.0F) {
            s = -s;
          }

          tau_data[b_n] = (s - smax) / s;
          smax = 1.0F / (smax - s);
          b_ix = (yk - b_n) + 8;
          for (iy = yk + 1; iy < b_ix; iy++) {
            b_A_data[iy] *= smax;
          }

          for (idxmax = 0; idxmax <= ix; idxmax++) {
            s *= 9.86076132E-32F;
          }

          smax = s;
        } else {
          tau_data[b_n] = (s - b_A_data[yk]) / s;
          smax = 1.0F / (b_A_data[yk] - s);
          ix = (yk - b_n) + 8;
          for (b_ix = yk + 1; b_ix < ix; b_ix++) {
            b_A_data[b_ix] *= smax;
          }

          smax = s;
        }
      }

      b_A_data[yk] = smax;
      if (b_n + 1 < n) {
        smax = b_A_data[yk];
        b_A_data[yk] = 1.0F;
        xzlarf(8 - b_n, nmi - 1, yk + 1, tau_data[b_n], b_A_data, (b_n + ((b_n +
                  1) << 3)) + 1, work_data);
        b_A_data[yk] = smax;
      }

      for (yk = b_n + 1; yk < n; yk++) {
        if (vn1_data[yk] != 0.0F) {
          nmi = (yk << 3) + b_n;
          smax = std::abs(b_A_data[nmi]) / vn1_data[yk];
          smax = 1.0F - smax * smax;
          if (smax < 0.0F) {
            smax = 0.0F;
          }

          s = vn1_data[yk] / vn2_data[yk];
          s = s * s * smax;
          if (s <= 0.000345266977F) {
            vn1_data[yk] = xnrm2(7 - b_n, b_A_data, nmi + 2);
            vn2_data[yk] = vn1_data[yk];
          } else {
            vn1_data[yk] *= std::sqrt(smax);
          }
        }
      }
    }
  }

  n = 0;
  if (b_A_size[1] > 0) {
    while ((n < b_A_size[1]) && (std::abs(b_A_data[(n << 3) + n]) >
            9.53674316E-6F * std::abs(b_A_data[0]))) {
      n++;
    }
  }

  for (b_ix = 0; b_ix < 8; b_ix++) {
    B_2[b_ix] = B_1[b_ix];
  }

  LSQFromQR(b_A_data, b_A_size, tau_data, jpvt_data, B_2, n, Y_data, Y_size);
}

// Function for MATLAB Function: '<S47>/MATLAB Function'
void MatlabControllerClass::mldivide(const real32_T A_data[], const int32_T
  A_size[2], const real32_T B_0[8], real32_T Y_data[], int32_T *Y_size)
{
  if (A_size[1] == 0) {
    *Y_size = 0;
  } else {
    qrsolve(A_data, A_size, B_0, Y_data, Y_size);
  }
}

// Function for MATLAB Function: '<S47>/MATLAB Function'
boolean_T MatlabControllerClass::any(const boolean_T x_data[], const int32_T
  *x_size)
{
  boolean_T y;
  int32_T ix;
  boolean_T exitg1;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= *x_size)) {
    if (!x_data[ix - 1]) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

// Model step function
void MatlabControllerClass::step()
{
  real32_T d[16];
  real32_T q3_q3;
  real32_T q0_q2;
  real32_T q0_q3;
  real32_T q1_q3;
  real32_T q2_q3;
  real32_T quat_norm;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real32_T sin_Psi;
  real32_T cos_Psi;
  real32_T q_yaw[4];
  real32_T unusedU0[4];
  real32_T A[32];
  real32_T d_0[8];
  boolean_T i_free[4];
  real32_T A_free_data[32];
  real32_T p_free_data[4];
  real_T p[4];
  real_T c_data[4];
  int8_T f_data[4];
  int8_T g_data[4];
  int8_T h_data[4];
  int8_T i_data[4];
  int32_T aoffset;
  int32_T b_aoffset;
  boolean_T x[4];
  real32_T rtb_z_Kg;
  real32_T rtb_y_dt_d[2];
  real32_T rtb_phi_a;
  real32_T rtb_n_b_d[3];
  real32_T rtb_n_b_d_dt2[3];
  real32_T rtb_Diff[3];
  real32_T rtb_Diff_a[3];
  real32_T rtb_u[4];
  real32_T rtb_Add[3];
  real32_T rtb_q_red[4];
  real32_T rtb_uDLookupTable2[4];
  real32_T rtb_G2[16];
  real32_T rtb_M_bg[9];
  real32_T rtb_y_gs[3];
  real32_T rtb_y_d[3];
  real32_T rtb_y_dt[3];
  real32_T rtb_y_f[3];
  real32_T rtb_Add_p[6];
  real32_T rtb_Add1[2];
  real32_T rtb_omega2[3];
  real32_T rtb_y_e[3];
  real32_T A_tmp[16];
  int32_T i;
  boolean_T rtb_u_data[4];
  real32_T tmp[6];
  real32_T tmp_0[2];
  real32_T tmp_1[16];
  real32_T rtb_y_k[4];
  real32_T tmp_2[4];
  real32_T A_tmp_0[8];
  boolean_T rtb_u_0[4];
  int32_T A_free_size[2];
  int32_T p_free_size;
  real32_T cmd_V_NED;
  real_T p_0;
  real32_T rtb_q_cmd;
  boolean_T x_0;
  real32_T rtb_y_idx_3;
  real32_T rtb_y_idx_2;
  real32_T rtb_y_idx_1;
  real32_T rtb_y_idx_0;
  real32_T rtb_y_p_idx_1;
  real32_T rtb_y_p_idx_0;
  real_T dist_idx_3;
  real_T dist_idx_2;
  real_T dist_idx_1;
  boolean_T e_idx_3;
  boolean_T e_idx_2;
  boolean_T e_idx_1;
  real_T dist_idx_0;
  boolean_T e_idx_0;
  real32_T cmd_V_NED_idx_1;
  real32_T cmd_V_NED_idx_0;
  real32_T rtb_TSamp_idx_1;
  real32_T rtb_TSamp_idx_0;
  real32_T M_bg_idx_8;
  real32_T y;
  real32_T u0;
  real32_T y_0;
  real32_T u0_0;
  real32_T u0_1;
  real32_T u0_2;
  real32_T rtb_M_bg_tmp;
  int32_T A_tmp_tmp;
  int32_T A_tmp_tmp_0;
  boolean_T exitg1;
  boolean_T exitg2;

  // DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  rtb_y_idx_0 = rtDW.DiscreteTimeIntegrator_DSTATE[0];
  rtb_y_idx_1 = rtDW.DiscreteTimeIntegrator_DSTATE[1];
  rtb_y_idx_2 = rtDW.DiscreteTimeIntegrator_DSTATE[2];
  rtb_y_idx_3 = rtDW.DiscreteTimeIntegrator_DSTATE[3];

  // MATLAB Function: '<S46>/MATLAB Function' incorporates:
  //   Constant: '<S46>/Constant4'
  //   Constant: '<S46>/ny_du_dt'

  for (i = 0; i < 16; i++) {
    rtb_G2[i] = rtConstP.ny_du_dt_Value[i] / 0.0025F;
    d[i] = 0.0F;
  }

  // MATLAB Function: '<Root>/Quaternions to Rotation Matrix'
  scale = 1.29246971E-26F;

  // MinMax: '<S46>/Max' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[0] > 0.1F) {
    q0_q2 = rtDW.DiscreteTimeIntegrator_DSTATE[0];
  } else {
    q0_q2 = 0.1F;
  }

  // MATLAB Function: '<S46>/MATLAB Function'
  d[0] = q0_q2 / 0.283F;

  // MATLAB Function: '<Root>/Quaternions to Rotation Matrix' incorporates:
  //   Inport: '<Root>/measure'

  absxk = std::abs(rtU.measure.q_bg[0]);
  if (absxk > 1.29246971E-26F) {
    quat_norm = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    quat_norm = t * t;
  }

  // MinMax: '<S46>/Max' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[1] > 0.1F) {
    q0_q2 = rtDW.DiscreteTimeIntegrator_DSTATE[1];
  } else {
    q0_q2 = 0.1F;
  }

  // MATLAB Function: '<S46>/MATLAB Function'
  d[5] = q0_q2 / 0.283F;

  // MATLAB Function: '<Root>/Quaternions to Rotation Matrix' incorporates:
  //   Inport: '<Root>/measure'

  absxk = std::abs(rtU.measure.q_bg[1]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  // MinMax: '<S46>/Max' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[2] > 0.1F) {
    q0_q2 = rtDW.DiscreteTimeIntegrator_DSTATE[2];
  } else {
    q0_q2 = 0.1F;
  }

  // MATLAB Function: '<S46>/MATLAB Function'
  d[10] = q0_q2 / 0.283F;

  // MATLAB Function: '<Root>/Quaternions to Rotation Matrix' incorporates:
  //   Inport: '<Root>/measure'

  absxk = std::abs(rtU.measure.q_bg[2]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  // MinMax: '<S46>/Max' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[3] > 0.1F) {
    q0_q2 = rtDW.DiscreteTimeIntegrator_DSTATE[3];
  } else {
    q0_q2 = 0.1F;
  }

  // MATLAB Function: '<S46>/MATLAB Function'
  d[15] = q0_q2 / 0.283F;

  // MATLAB Function: '<Root>/Quaternions to Rotation Matrix' incorporates:
  //   Inport: '<Root>/measure'

  absxk = std::abs(rtU.measure.q_bg[3]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  quat_norm = scale * std::sqrt(quat_norm);
  if (0.01 < quat_norm) {
    scale = quat_norm;
  } else {
    scale = 0.01F;
  }

  rtb_u[0] = rtU.measure.q_bg[0] / scale;
  rtb_u[1] = rtU.measure.q_bg[1] / scale;
  rtb_u[2] = rtU.measure.q_bg[2] / scale;
  rtb_u[3] = rtU.measure.q_bg[3] / scale;
  absxk = rtb_u[0] * rtb_u[0];
  t = rtb_u[1] * rtb_u[1];
  quat_norm = rtb_u[2] * rtb_u[2];
  q3_q3 = rtb_u[3] * rtb_u[3];
  M_bg_idx_8 = rtb_u[0] * rtb_u[1];
  q0_q2 = rtb_u[0] * rtb_u[2];
  q0_q3 = rtb_u[0] * rtb_u[3];
  scale = rtb_u[1] * rtb_u[2];
  q1_q3 = rtb_u[1] * rtb_u[3];
  q2_q3 = rtb_u[2] * rtb_u[3];
  rtb_M_bg[0] = ((absxk + t) - quat_norm) - q3_q3;
  rtb_M_bg[3] = (scale + q0_q3) * 2.0F;
  rtb_M_bg[6] = (q1_q3 - q0_q2) * 2.0F;
  rtb_M_bg[1] = (scale - q0_q3) * 2.0F;
  rtb_M_bg_tmp = absxk - t;
  rtb_M_bg[4] = (rtb_M_bg_tmp + quat_norm) - q3_q3;
  rtb_M_bg[7] = (q2_q3 + M_bg_idx_8) * 2.0F;
  rtb_M_bg[2] = (q1_q3 + q0_q2) * 2.0F;
  rtb_M_bg[5] = (q2_q3 - M_bg_idx_8) * 2.0F;
  rtb_M_bg[8] = (rtb_M_bg_tmp - quat_norm) + q3_q3;

  // SampleTimeMath: '<S36>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S36>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_M_bg_tmp = rtU.measure.omega_Kb[0] * 400.0F;

  // Sum: '<S36>/Diff' incorporates:
  //   UnitDelay: '<S36>/UD'
  //
  //  Block description for '<S36>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S36>/UD':
  //
  //   Store in Global RAM

  rtb_Diff[0] = rtb_M_bg_tmp - rtDW.UD_DSTATE[0];

  // DiscreteIntegrator: '<S71>/Discrete-Time Integrator y'
  rtb_y_gs[0] = rtDW.DiscreteTimeIntegratory_DSTATE[0];

  // SampleTimeMath: '<S36>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S36>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp_idx_0 = rtb_M_bg_tmp;
  rtb_M_bg_tmp = rtU.measure.omega_Kb[1] * 400.0F;

  // Sum: '<S36>/Diff' incorporates:
  //   UnitDelay: '<S36>/UD'
  //
  //  Block description for '<S36>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S36>/UD':
  //
  //   Store in Global RAM

  rtb_Diff[1] = rtb_M_bg_tmp - rtDW.UD_DSTATE[1];

  // DiscreteIntegrator: '<S71>/Discrete-Time Integrator y'
  rtb_y_gs[1] = rtDW.DiscreteTimeIntegratory_DSTATE[1];

  // SampleTimeMath: '<S36>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S36>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp_idx_1 = rtb_M_bg_tmp;
  rtb_M_bg_tmp = rtU.measure.omega_Kb[2] * 400.0F;

  // Sum: '<S36>/Diff' incorporates:
  //   UnitDelay: '<S36>/UD'
  //
  //  Block description for '<S36>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S36>/UD':
  //
  //   Store in Global RAM

  rtb_Diff[2] = rtb_M_bg_tmp - rtDW.UD_DSTATE[2];

  // DiscreteIntegrator: '<S71>/Discrete-Time Integrator y'
  rtb_y_gs[2] = rtDW.DiscreteTimeIntegratory_DSTATE[2];

  // DiscreteIntegrator: '<S72>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y'

  if (rtDW.DiscreteTimeIntegratory_IC_LOAD != 0) {
    rtDW.DiscreteTimeIntegratory_DSTAT_m[0] =
      rtDW.DiscreteTimeIntegratory_DSTATE[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_m[1] =
      rtDW.DiscreteTimeIntegratory_DSTATE[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_m[2] =
      rtDW.DiscreteTimeIntegratory_DSTATE[2];
  }

  rtb_y_d[0] = rtDW.DiscreteTimeIntegratory_DSTAT_m[0];

  // DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
  rtb_y_dt[0] = rtDW.DiscreteTimeIntegratory_dt_DSTA[0];

  // DiscreteIntegrator: '<S72>/Discrete-Time Integrator y'
  rtb_y_d[1] = rtDW.DiscreteTimeIntegratory_DSTAT_m[1];

  // DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
  rtb_y_dt[1] = rtDW.DiscreteTimeIntegratory_dt_DSTA[1];

  // DiscreteIntegrator: '<S72>/Discrete-Time Integrator y'
  rtb_y_d[2] = rtDW.DiscreteTimeIntegratory_DSTAT_m[2];

  // DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
  rtb_y_dt[2] = rtDW.DiscreteTimeIntegratory_dt_DSTA[2];

  // DiscreteIntegrator: '<S73>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'

  if (rtDW.DiscreteTimeIntegratory_IC_LO_e != 0) {
    rtDW.DiscreteTimeIntegratory_DSTAT_h[0] =
      rtDW.DiscreteTimeIntegratory_dt_DSTA[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_h[1] =
      rtDW.DiscreteTimeIntegratory_dt_DSTA[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_h[2] =
      rtDW.DiscreteTimeIntegratory_dt_DSTA[2];
  }

  rtb_y_f[0] = rtDW.DiscreteTimeIntegratory_DSTAT_h[0];
  rtb_y_f[1] = rtDW.DiscreteTimeIntegratory_DSTAT_h[1];
  rtb_y_f[2] = rtDW.DiscreteTimeIntegratory_DSTAT_h[2];

  // Gain: '<S22>/Gain3' incorporates:
  //   Gain: '<Root>/Gain'
  //   Inport: '<Root>/cmd'
  //   MATLAB Function: '<S10>/MATLAB Function'
  //   MATLAB Function: '<S22>/MATLAB Function1'

  rtb_z_Kg = std::sqrt(rtU.cmd.roll * rtU.cmd.roll + -rtU.cmd.pitch *
                       -rtU.cmd.pitch) * 15.0F;

  // DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  rtb_y_p_idx_0 = rtDW.DiscreteTimeIntegrator_DSTATE_k[0];
  rtb_y_p_idx_1 = rtDW.DiscreteTimeIntegrator_DSTATE_k[1];

  // Gain: '<S34>/1//T' incorporates:
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  //   Gain: '<Root>/Gain'
  //   Inport: '<Root>/cmd'
  //   Product: '<S22>/Product'
  //   Sum: '<S34>/Sum2'

  u0 = (-rtU.cmd.pitch * rtb_z_Kg - rtDW.DiscreteTimeIntegrator_DSTATE_k[0]) *
    1.25F;

  // Saturate: '<S34>/Saturation'
  if (u0 > 12.0F) {
    y = 12.0F;
    rtb_y_dt_d[0] = 12.0F;
  } else if (u0 < -12.0F) {
    y = -12.0F;
    rtb_y_dt_d[0] = -12.0F;
  } else {
    y = u0;
    rtb_y_dt_d[0] = u0;
  }

  // Gain: '<S34>/1//T' incorporates:
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  //   Inport: '<Root>/cmd'
  //   MATLAB Function: '<S10>/MATLAB Function'
  //   Product: '<S22>/Product'
  //   Sum: '<S34>/Sum2'

  u0 = (rtU.cmd.roll * rtb_z_Kg - rtDW.DiscreteTimeIntegrator_DSTATE_k[1]) *
    1.25F;

  // Saturate: '<S34>/Saturation'
  if (u0 > 12.0F) {
    y_0 = 12.0F;
    rtb_y_dt_d[1] = 12.0F;
  } else if (u0 < -12.0F) {
    y_0 = -12.0F;
    rtb_y_dt_d[1] = -12.0F;
  } else {
    y_0 = u0;
    rtb_y_dt_d[1] = u0;
  }

  // SampleTimeMath: '<S7>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S7>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  cmd_V_NED = rtU.measure.V_Kg[0] * 400.0F;

  // Sum: '<S7>/Diff' incorporates:
  //   UnitDelay: '<S7>/UD'
  //
  //  Block description for '<S7>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S7>/UD':
  //
  //   Store in Global RAM

  rtb_Diff_a[0] = cmd_V_NED - rtDW.UD_DSTATE_h[0];

  // SampleTimeMath: '<S7>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S7>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  cmd_V_NED_idx_0 = cmd_V_NED;
  cmd_V_NED = rtU.measure.V_Kg[1] * 400.0F;

  // Sum: '<S7>/Diff' incorporates:
  //   UnitDelay: '<S7>/UD'
  //
  //  Block description for '<S7>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S7>/UD':
  //
  //   Store in Global RAM

  rtb_Diff_a[1] = cmd_V_NED - rtDW.UD_DSTATE_h[1];

  // SampleTimeMath: '<S7>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S7>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  cmd_V_NED_idx_1 = cmd_V_NED;
  cmd_V_NED = rtU.measure.V_Kg[2] * 400.0F;

  // Sum: '<S7>/Diff' incorporates:
  //   UnitDelay: '<S7>/UD'
  //
  //  Block description for '<S7>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S7>/UD':
  //
  //   Store in Global RAM

  rtb_Diff_a[2] = cmd_V_NED - rtDW.UD_DSTATE_h[2];

  // Sum: '<S24>/Add' incorporates:
  //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator y'
  //   Inport: '<Root>/measure'

  rtb_Add_p[0] = rtDW.DiscreteTimeIntegratory_DSTA_hs[0] - rtU.measure.s_Kg[0];
  rtb_Add_p[2] = rtDW.DiscreteTimeIntegratory_DSTA_hs[2] - rtU.measure.V_Kg[0];
  rtb_Add_p[4] = rtDW.DiscreteTimeIntegratory_DSTA_hs[4] - rtb_Diff_a[0];
  rtb_Add_p[1] = rtDW.DiscreteTimeIntegratory_DSTA_hs[1] - rtU.measure.s_Kg[1];
  rtb_Add_p[3] = rtDW.DiscreteTimeIntegratory_DSTA_hs[3] - rtU.measure.V_Kg[1];
  rtb_Add_p[5] = rtDW.DiscreteTimeIntegratory_DSTA_hs[5] - rtb_Diff_a[1];

  // Gain: '<S24>/Gain'
  for (b_aoffset = 0; b_aoffset < 6; b_aoffset++) {
    // Saturate: '<S24>/Saturation1'
    if (rtb_Add_p[b_aoffset] > rtConstP.Saturation1_UpperSat[b_aoffset]) {
      tmp[b_aoffset] = rtConstP.Saturation1_UpperSat[b_aoffset];
    } else if (rtb_Add_p[b_aoffset] < rtConstP.Saturation1_LowerSat[b_aoffset])
    {
      tmp[b_aoffset] = rtConstP.Saturation1_LowerSat[b_aoffset];
    } else {
      tmp[b_aoffset] = rtb_Add_p[b_aoffset];
    }

    // End of Saturate: '<S24>/Saturation1'
  }

  // DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  sin_Psi = rtDW.DiscreteTimeIntegrator_DSTATE_i;

  // Gain: '<S82>/1//T' incorporates:
  //   DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  //   Inport: '<Root>/cmd'
  //   Lookup_n-D: '<S80>/1-D Lookup Table'
  //   Sum: '<S82>/Sum2'

  cos_Psi = (look1_iflf_binlx(rtU.cmd.thr, rtConstP.uDLookupTable_bp01Data,
              rtConstP.uDLookupTable_tableData, 2U) -
             rtDW.DiscreteTimeIntegrator_DSTATE_i) * 3.33333325F;

  // Saturate: '<S82>/Saturation'
  if (cos_Psi > 4.0F) {
    cos_Psi = 4.0F;
  } else {
    if (cos_Psi < -25.0F) {
      cos_Psi = -25.0F;
    }
  }

  // End of Saturate: '<S82>/Saturation'
  for (i = 0; i < 2; i++) {
    // Gain: '<S24>/Gain'
    tmp_0[i] = 0.0F;
    for (b_aoffset = 0; b_aoffset < 6; b_aoffset++) {
      tmp_0[i] += rtConstP.Gain_Gain_i[(b_aoffset << 1) + i] * tmp[b_aoffset];
    }

    // Saturate: '<S24>/Saturation' incorporates:
    //   Gain: '<S24>/Gain'
    //   Sum: '<S8>/Add1'

    if (tmp_0[i] > 9.0F) {
      q0_q2 = 9.0F;
    } else if (tmp_0[i] < -9.0F) {
      q0_q2 = -9.0F;
    } else {
      q0_q2 = tmp_0[i];
    }

    // End of Saturate: '<S24>/Saturation'

    // Sum: '<S8>/Add1'
    rtb_z_Kg = rtb_y_dt_d[i] + q0_q2;

    // SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1' incorporates:
    //   MATLAB Function: '<S21>/MATLAB Function1'

    rtb_n_b_d_dt2[i] = rtb_z_Kg;

    // Sum: '<S8>/Add1'
    rtb_Add1[i] = rtb_z_Kg;
  }

  // SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   MATLAB Function: '<S21>/MATLAB Function1'

  rtb_n_b_d_dt2[2] = cos_Psi;

  // MATLAB Function: '<S21>/MATLAB Function1' incorporates:
  //   MATLAB Function: '<S21>/MATLAB Function4'
  //   SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1'

  scale = 1.29246971E-26F;
  absxk = std::abs(rtb_n_b_d_dt2[0]);
  if (absxk > 1.29246971E-26F) {
    rtb_z_Kg = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    rtb_z_Kg = t * t;
  }

  rtb_omega2[0] = rtb_Diff_a[0];
  absxk = std::abs(rtb_n_b_d_dt2[1]);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_z_Kg = rtb_z_Kg * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_z_Kg += t * t;
  }

  rtb_omega2[1] = rtb_Diff_a[1];
  absxk = std::abs(cos_Psi - 9.81F);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_z_Kg = rtb_z_Kg * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_z_Kg += t * t;
  }

  rtb_omega2[2] = rtb_Diff_a[2] - 9.81F;
  rtb_z_Kg = scale * std::sqrt(rtb_z_Kg);

  // MATLAB Function: '<S21>/MATLAB Function4'
  scale = 1.29246971E-26F;
  absxk = std::abs(rtb_Diff_a[0]);
  if (absxk > 1.29246971E-26F) {
    rtb_phi_a = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    rtb_phi_a = t * t;
  }

  absxk = std::abs(rtb_Diff_a[1]);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_phi_a = rtb_phi_a * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_phi_a += t * t;
  }

  absxk = std::abs(rtb_Diff_a[2] - 9.81F);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_phi_a = rtb_phi_a * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_phi_a += t * t;
  }

  rtb_phi_a = scale * std::sqrt(rtb_phi_a);

  // Sum: '<S12>/Add' incorporates:
  //   MATLAB Function: '<S12>/MATLAB Function1'
  //   MATLAB Function: '<S21>/MATLAB Function1'
  //   MATLAB Function: '<S21>/MATLAB Function4'
  //   Sum: '<S21>/Add2'

  for (b_aoffset = 0; b_aoffset < 3; b_aoffset++) {
    rtb_Add[b_aoffset] = ((rtb_n_b_d_dt2[b_aoffset] - rtConstB.Gain2[b_aoffset])
                          / rtb_z_Kg - rtb_omega2[b_aoffset] / rtb_phi_a) +
      -rtb_M_bg[3 * b_aoffset + 2];
  }

  // End of Sum: '<S12>/Add'

  // MATLAB Function: '<S12>/MATLAB Function'
  scale = 1.29246971E-26F;
  absxk = std::abs(rtb_Add[0]);
  if (absxk > 1.29246971E-26F) {
    rtb_z_Kg = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    rtb_z_Kg = t * t;
  }

  absxk = std::abs(rtb_Add[1]);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_z_Kg = rtb_z_Kg * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_z_Kg += t * t;
  }

  absxk = std::abs(rtb_Add[2]);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_z_Kg = rtb_z_Kg * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_z_Kg += t * t;
  }

  rtb_z_Kg = scale * std::sqrt(rtb_z_Kg);
  rtb_Add[0] /= rtb_z_Kg;
  rtb_Add[1] /= rtb_z_Kg;
  rtb_Add[2] /= rtb_z_Kg;

  // End of MATLAB Function: '<S12>/MATLAB Function'

  // MATLAB Function: '<S12>/MATLAB Function4'
  MATLABFunction4(rtb_Add, &rtb_phi_a, &rtb_z_Kg);

  // Saturate: '<S6>/Saturation'
  if (rtb_phi_a > 1.04719758F) {
    rtb_phi_a = 1.04719758F;
  } else {
    if (rtb_phi_a < 0.0F) {
      rtb_phi_a = 0.0F;
    }
  }

  // End of Saturate: '<S6>/Saturation'

  // Gain: '<S6>/Gain'
  scale = 0.95492965F * rtb_phi_a;

  // MATLAB Function: '<S6>/MATLAB Function1'
  rtb_phi_a = scale * std::sin(rtb_z_Kg);
  rtb_z_Kg = -scale * std::cos(rtb_z_Kg);

  // Gain: '<S56>/lean_angle_max' incorporates:
  //   MATLAB Function: '<S9>/MATLAB Function1'

  quat_norm = std::sqrt(rtb_phi_a * rtb_phi_a + rtb_z_Kg * rtb_z_Kg) *
    1.04719758F;
  rtb_phi_a = std::atan2(rtb_phi_a, -rtb_z_Kg);

  // MATLAB Function: '<S56>/lean angles 2 lean vector'
  rtb_z_Kg = std::sin(quat_norm);

  // Gain: '<S71>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
  //   Gain: '<S71>/2*d//omega'
  //   MATLAB Function: '<S56>/lean angles 2 lean vector'
  //   Sum: '<S71>/Sum2'
  //   Sum: '<S71>/Sum3'

  rtb_omega2[0] = (rtb_z_Kg * std::cos(rtb_phi_a) - (0.166666672F *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[0] +
    rtDW.DiscreteTimeIntegratory_DSTATE[0])) * 144.0F;
  rtb_omega2[1] = (rtb_z_Kg * std::sin(rtb_phi_a) - (0.166666672F *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[1] +
    rtDW.DiscreteTimeIntegratory_DSTATE[1])) * 144.0F;
  rtb_omega2[2] = (-std::cos(quat_norm) - (0.166666672F *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[2] +
    rtDW.DiscreteTimeIntegratory_DSTATE[2])) * 144.0F;

  // DiscreteIntegrator: '<S74>/Discrete-Time Integrator y'
  if (rtDW.DiscreteTimeIntegratory_IC_LO_j != 0) {
    rtDW.DiscreteTimeIntegratory_DSTAT_i[0] = rtb_omega2[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_i[1] = rtb_omega2[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_i[2] = rtb_omega2[2];
  }

  rtb_y_e[0] = rtDW.DiscreteTimeIntegratory_DSTAT_i[0];
  rtb_y_e[1] = rtDW.DiscreteTimeIntegratory_DSTAT_i[1];
  rtb_y_e[2] = rtDW.DiscreteTimeIntegratory_DSTAT_i[2];

  // MATLAB Function: '<S56>/MATLAB Function1' incorporates:
  //   Inport: '<Root>/measure'

  MATLABFunction(rtU.measure.omega_Kb, rtb_Diff, rtb_M_bg, rtb_y_d, rtb_y_f,
                 rtb_y_e, rtb_n_b_d, rtb_Add, rtb_n_b_d_dt2);

  // DiscreteIntegrator: '<S56>/Discrete-Time Integrator2'
  if (rtDW.DiscreteTimeIntegrator2_IC_LOAD != 0) {
    // MATLAB Function: '<Root>/Rotations matrix to Euler angles'
    rtDW.DiscreteTimeIntegrator2_DSTATE = std::atan2(rtb_M_bg[3], rtb_M_bg[0]);
  }

  // MATLAB Function: '<S51>/wrap angle' incorporates:
  //   DiscreteIntegrator: '<S56>/Discrete-Time Integrator2'

  wrapangle(rtDW.DiscreteTimeIntegrator2_DSTATE, &scale);

  // MATLAB Function: '<S52>/DCM to quaternions'
  DCMtoquaternions(rtb_M_bg, rtb_u);

  // MATLAB Function: '<S52>/MATLAB Function1'
  quatNormalize(rtb_u, q_yaw);
  quat_norm = q_yaw[2] * q_yaw[2];
  q2_q3 = (q_yaw[1] * q_yaw[3] + q_yaw[0] * q_yaw[2]) * 2.0F;
  M_bg_idx_8 = ((q_yaw[0] * q_yaw[0] - q_yaw[1] * q_yaw[1]) - quat_norm) +
    q_yaw[3] * q_yaw[3];
  if (1.0F <= M_bg_idx_8) {
    M_bg_idx_8 = 1.0F;
  }

  if (-1.0F >= M_bg_idx_8) {
    M_bg_idx_8 = -1.0F;
  }

  rtb_z_Kg = std::acos(M_bg_idx_8);
  rtb_phi_a = std::sin(rtb_z_Kg);
  rtb_phi_a = rtb_phi_a * rtb_phi_a - q2_q3 * q2_q3;
  if ((q_yaw[2] * q_yaw[3] - q_yaw[0] * q_yaw[1]) * 2.0F >= 0.0F) {
    b_aoffset = -1;
  } else {
    b_aoffset = 1;
  }

  if (0.0F >= rtb_phi_a) {
    rtb_phi_a = 0.0F;
  }

  rtb_phi_a = std::atan2((real32_T)b_aoffset * std::sqrt(rtb_phi_a), -q2_q3);
  absxk = std::sin(rtb_z_Kg / 2.0F);
  p_free_data[0] = std::cos(rtb_z_Kg / 2.0F);
  p_free_data[1] = -(std::sin(rtb_phi_a) * absxk);
  p_free_data[2] = -(-std::cos(rtb_phi_a) * absxk);
  p_free_data[3] = -0.0F;
  quatNormalize(p_free_data, q_yaw);
  rtb_q_red[0] = ((q_yaw[0] * rtb_u[0] - q_yaw[1] * rtb_u[1]) - q_yaw[2] *
                  rtb_u[2]) - q_yaw[3] * rtb_u[3];
  rtb_q_red[1] = (q_yaw[0] * rtb_u[1] + rtb_u[0] * q_yaw[1]) + (q_yaw[2] *
    rtb_u[3] - q_yaw[3] * rtb_u[2]);
  rtb_q_red[2] = (q_yaw[0] * rtb_u[2] + rtb_u[0] * q_yaw[2]) + (q_yaw[3] *
    rtb_u[1] - q_yaw[1] * rtb_u[3]);
  rtb_q_red[3] = (q_yaw[0] * rtb_u[3] + rtb_u[0] * q_yaw[3]) + (q_yaw[1] *
    rtb_u[2] - q_yaw[2] * rtb_u[1]);
  quatNormalize(rtb_q_red, q_yaw);
  if (q_yaw[3] < 0.0F) {
    rtb_z_Kg = -1.0F;
  } else if (q_yaw[3] > 0.0F) {
    rtb_z_Kg = 1.0F;
  } else {
    rtb_z_Kg = q_yaw[3];
  }

  rtb_z_Kg *= q_yaw[0];
  if (-1.0F >= rtb_z_Kg) {
    rtb_z_Kg = -1.0F;
  }

  if (1.0F <= rtb_z_Kg) {
    rtb_z_Kg = 1.0F;
  }

  // MATLAB Function: '<S51>/wrap angle1' incorporates:
  //   MATLAB Function: '<S52>/MATLAB Function1'

  wrapangle(2.0F * std::acos(rtb_z_Kg), &quat_norm);

  // MATLAB Function: '<S51>/angle error'
  absxk = scale - quat_norm;
  if (absxk > 3.1415926535897931) {
    absxk -= 6.28318548F;
  } else {
    if (absxk < -3.1415926535897931) {
      absxk += 6.28318548F;
    }
  }

  // End of MATLAB Function: '<S51>/angle error'

  // Gain: '<S70>/1//T' incorporates:
  //   DiscreteIntegrator: '<S70>/Discrete-Time Integrator'
  //   Gain: '<S56>/r_max'
  //   Inport: '<Root>/cmd'
  //   Sum: '<S70>/Sum2'

  rtb_z_Kg = (5.23598766F * rtU.cmd.yaw - rtDW.DiscreteTimeIntegrator_DSTATE_d) *
    10.0F;

  // Sum: '<S51>/error1 9'
  t = rtb_z_Kg - rtb_Diff[2];

  // DiscreteIntegrator: '<S80>/Discrete-Time Integrator3' incorporates:
  //   Inport: '<Root>/measure'

  if (rtDW.DiscreteTimeIntegrator3_IC_LOAD != 0) {
    rtDW.DiscreteTimeIntegrator3_DSTATE = rtU.measure.s_Kg[2];
  }

  // Sum: '<S75>/error1 3' incorporates:
  //   DiscreteIntegrator: '<S80>/Discrete-Time Integrator3'
  //   Inport: '<Root>/measure'

  M_bg_idx_8 = rtDW.DiscreteTimeIntegrator3_DSTATE - rtU.measure.s_Kg[2];

  // Sum: '<S75>/error1 1' incorporates:
  //   DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  //   Inport: '<Root>/measure'

  q0_q2 = rtDW.DiscreteTimeIntegrator_DSTATE_i - rtU.measure.V_Kg[2];

  // SampleTimeMath: '<S37>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S37>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_phi_a = rtU.measure.V_Kg[2] * 400.0F;

  // Sum: '<S37>/Diff' incorporates:
  //   UnitDelay: '<S37>/UD'
  //
  //  Block description for '<S37>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S37>/UD':
  //
  //   Store in Global RAM

  scale = rtb_phi_a - rtDW.UD_DSTATE_a;

  // Sum: '<S75>/error1 2'
  quat_norm = cos_Psi - scale;

  // Outport: '<Root>/logs' incorporates:
  //   Sum: '<S51>/error1 4'

  rtY.logs[0] = rtb_n_b_d[0];
  rtY.logs[1] = rtb_n_b_d[1];
  rtY.logs[2] = t;
  rtY.logs[3] = absxk;
  rtY.logs[4] = M_bg_idx_8;
  rtY.logs[5] = q0_q2;
  rtY.logs[6] = quat_norm;
  for (i = 0; i < 6; i++) {
    rtY.logs[i + 7] = rtb_Add_p[i];
  }

  rtY.logs[13] = 0.0F;
  rtY.logs[14] = 0.0F;

  // End of Outport: '<Root>/logs'

  // DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/measure'

  if (rtDW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    rtDW.DiscreteTimeIntegrator_DSTAT_ki[0] = rtU.measure.s_Kg[0];
    rtDW.DiscreteTimeIntegrator_DSTAT_ki[1] = rtU.measure.s_Kg[1];
  }

  // Sum: '<S35>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator y_dt'
  //   Gain: '<S35>/2*d//omega'
  //   Saturate: '<S34>/Saturation'
  //   Sum: '<S35>/Sum3'

  rtb_Add_p[0] = rtDW.DiscreteTimeIntegrator_DSTAT_ki[0] - (0.198645547F *
    rtDW.DiscreteTimeIntegratory_dt_DS_b[0] +
    rtDW.DiscreteTimeIntegratory_DSTA_hs[0]);
  rtb_Add_p[2] = rtDW.DiscreteTimeIntegrator_DSTATE_k[0] - (0.198645547F *
    rtDW.DiscreteTimeIntegratory_dt_DS_b[2] +
    rtDW.DiscreteTimeIntegratory_DSTA_hs[2]);
  rtb_Add_p[4] = y - (0.198645547F * rtDW.DiscreteTimeIntegratory_dt_DS_b[4] +
                      rtDW.DiscreteTimeIntegratory_DSTA_hs[4]);
  rtb_Add_p[1] = rtDW.DiscreteTimeIntegrator_DSTAT_ki[1] - (0.198645547F *
    rtDW.DiscreteTimeIntegratory_dt_DS_b[1] +
    rtDW.DiscreteTimeIntegratory_DSTA_hs[1]);
  rtb_Add_p[3] = rtDW.DiscreteTimeIntegrator_DSTATE_k[1] - (0.198645547F *
    rtDW.DiscreteTimeIntegratory_dt_DS_b[3] +
    rtDW.DiscreteTimeIntegratory_DSTA_hs[3]);
  rtb_Add_p[5] = y_0 - (0.198645547F * rtDW.DiscreteTimeIntegratory_dt_DS_b[5] +
                        rtDW.DiscreteTimeIntegratory_DSTA_hs[5]);

  // MATLAB Function: '<S12>/DCM to quaternions'
  DCMtoquaternions(rtb_M_bg, q_yaw);

  // MATLAB Function: '<S21>/MATLAB Function2' incorporates:
  //   Constant: '<S21>/Constant1'
  //   Sum: '<S21>/Add'

  rtb_y_f[2] = cos_Psi - -9.81F;
  if (std::abs(cos_Psi - -9.81F) < 1.0F) {
    if (cos_Psi - -9.81F > 0.0F) {
      rtb_y_f[2] = 1.0F;
    } else {
      rtb_y_f[2] = -1.0F;
    }
  }

  // MATLAB Function: '<S21>/MATLAB Function8' incorporates:
  //   MATLAB Function: '<S21>/MATLAB Function2'
  //   SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1'

  MATLABFunction3(std::atan2(std::sqrt(rtb_Add1[0] * rtb_Add1[0] + rtb_Add1[1] *
    rtb_Add1[1]), -rtb_y_f[2]), std::atan2(rtb_Add1[1], rtb_Add1[0]), rtb_u);

  // SignalConversion: '<S31>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   Constant: '<S21>/Constant1'
  //   MATLAB Function: '<S21>/MATLAB Function9'
  //   Sum: '<S21>/Add3'

  rtb_y_d[0] = rtb_Diff_a[0];
  rtb_y_d[1] = rtb_Diff_a[1];
  rtb_y_d[2] = rtb_Diff_a[2] - -9.81F;

  // MATLAB Function: '<S21>/MATLAB Function9' incorporates:
  //   Constant: '<S21>/Constant1'
  //   SignalConversion: '<S31>/TmpSignal ConversionAt SFunction Inport1'
  //   Sum: '<S21>/Add3'

  rtb_y_f[0] = rtb_Diff_a[0];
  rtb_y_f[1] = rtb_Diff_a[1];
  rtb_y_f[2] = rtb_Diff_a[2] - -9.81F;
  if (std::abs(rtb_Diff_a[2] - -9.81F) < 1.0F) {
    if (rtb_Diff_a[2] - -9.81F > 0.0F) {
      rtb_y_f[2] = 1.0F;
    } else {
      rtb_y_f[2] = -1.0F;
    }
  }

  // MATLAB Function: '<S21>/MATLAB Function3' incorporates:
  //   MATLAB Function: '<S21>/MATLAB Function9'
  //   SignalConversion: '<S31>/TmpSignal ConversionAt SFunction Inport1'

  MATLABFunction3(std::atan2(std::sqrt(rtb_Diff_a[0] * rtb_Diff_a[0] +
    rtb_Diff_a[1] * rtb_Diff_a[1]), -rtb_y_f[2]), std::atan2(rtb_Diff_a[1],
    rtb_Diff_a[0]), rtb_q_red);

  // MATLAB Function: '<S21>/MATLAB Function5'
  q3_q3 = ((rtb_q_red[0] * rtb_q_red[0] + rtb_q_red[1] * rtb_q_red[1]) +
           rtb_q_red[2] * rtb_q_red[2]) + rtb_q_red[3] * rtb_q_red[3];
  q0_q3 = rtb_q_red[0] / q3_q3;
  q1_q3 = -rtb_q_red[1] / q3_q3;
  q2_q3 = -rtb_q_red[2] / q3_q3;
  q3_q3 = -rtb_q_red[3] / q3_q3;
  rtb_q_red[0] = ((q0_q3 * rtb_u[0] - q1_q3 * rtb_u[1]) - q2_q3 * rtb_u[2]) -
    q3_q3 * rtb_u[3];
  rtb_q_red[1] = (q0_q3 * rtb_u[1] + rtb_u[0] * q1_q3) + (q2_q3 * rtb_u[3] -
    q3_q3 * rtb_u[2]);
  rtb_q_red[2] = (q0_q3 * rtb_u[2] + rtb_u[0] * q2_q3) + (q3_q3 * rtb_u[1] -
    q1_q3 * rtb_u[3]);
  rtb_q_red[3] = (q0_q3 * rtb_u[3] + rtb_u[0] * q3_q3) + (q1_q3 * rtb_u[2] -
    q2_q3 * rtb_u[1]);

  // MATLAB Function: '<S12>/total reduced attitude command (quaternion)'
  q0_q3 = ((q_yaw[0] * rtb_q_red[0] - q_yaw[1] * rtb_q_red[1]) - q_yaw[2] *
           rtb_q_red[2]) - q_yaw[3] * rtb_q_red[3];
  q1_q3 = (q_yaw[0] * rtb_q_red[1] + rtb_q_red[0] * q_yaw[1]) + (q_yaw[2] *
    rtb_q_red[3] - q_yaw[3] * rtb_q_red[2]);
  q2_q3 = (q_yaw[0] * rtb_q_red[2] + rtb_q_red[0] * q_yaw[2]) + (q_yaw[3] *
    rtb_q_red[1] - q_yaw[1] * rtb_q_red[3]);
  q3_q3 = (q_yaw[0] * rtb_q_red[3] + rtb_q_red[0] * q_yaw[3]) + (q_yaw[1] *
    rtb_q_red[2] - q_yaw[2] * rtb_q_red[1]);

  // MATLAB Function: '<S56>/MATLAB Function' incorporates:
  //   Inport: '<Root>/measure'

  MATLABFunction(rtU.measure.omega_Kb, rtb_Diff, rtb_M_bg, rtb_y_gs, rtb_y_dt,
                 rtb_omega2, rtb_Diff_a, rtb_y_d, rtb_y_f);

  // Gain: '<S77>/Gain' incorporates:
  //   SignalConversion: '<S77>/TmpSignal ConversionAtGainInport1'

  q0_q2 = (50.0F * M_bg_idx_8 + 28.1578F * q0_q2) + 0.6786F * quat_norm;

  // MATLAB Function: '<S45>/dcm2Lean'
  if (1.0F > rtb_M_bg[8]) {
    M_bg_idx_8 = rtb_M_bg[8];
  } else {
    M_bg_idx_8 = 1.0F;
  }

  if (-1.0F >= M_bg_idx_8) {
    M_bg_idx_8 = -1.0F;
  }

  // MATLAB Function: '<S45>/MATLAB Function' incorporates:
  //   Gain: '<S77>/Gain'
  //   MATLAB Function: '<S45>/dcm2Lean'
  //   Sum: '<S42>/Add1'

  M_bg_idx_8 = std::cos(std::acos(M_bg_idx_8));
  if (M_bg_idx_8 > 0.1) {
    scale = ((cos_Psi + q0_q2) - scale) / M_bg_idx_8;
  } else {
    scale = (cos_Psi + q0_q2) - scale;
  }

  // End of MATLAB Function: '<S45>/MATLAB Function'

  // MATLAB Function: '<S47>/MATLAB Function'
  unusedU0[0] = 0.0F;

  // Gain: '<S38>/Gain' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  rtb_q_red[0] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[0];

  // Lookup_n-D: '<S38>/1-D Lookup Table2' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  rtb_uDLookupTable2[0] = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[0]) +
    (1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[0])) * 0.5F;

  // MATLAB Function: '<S47>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  q_yaw[0] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[0];

  // MATLAB Function: '<S47>/MATLAB Function'
  unusedU0[1] = 0.0F;

  // Gain: '<S38>/Gain' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  rtb_q_red[1] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[1];

  // Lookup_n-D: '<S38>/1-D Lookup Table2' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  rtb_uDLookupTable2[1] = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[1]) +
    (1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[1])) * 0.5F;

  // MATLAB Function: '<S47>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  q_yaw[1] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[1];

  // MATLAB Function: '<S47>/MATLAB Function'
  unusedU0[2] = 0.0F;

  // Gain: '<S38>/Gain' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  rtb_q_red[2] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[2];

  // Lookup_n-D: '<S38>/1-D Lookup Table2' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  rtb_uDLookupTable2[2] = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[2]) +
    (1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[2])) * 0.5F;

  // MATLAB Function: '<S47>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  q_yaw[2] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[2];
  M_bg_idx_8 = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[3]) + (1.0F -
    rtDW.DiscreteTimeIntegrator_DSTATE[3])) * 0.5F;

  // MATLAB Function: '<S47>/MATLAB Function'
  unusedU0[3] = 0.0F;

  // Gain: '<S38>/Gain' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  rtb_q_red[3] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[3];

  // Lookup_n-D: '<S38>/1-D Lookup Table2'
  rtb_uDLookupTable2[3] = M_bg_idx_8;

  // MATLAB Function: '<S47>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'

  q_yaw[3] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[3];

  // MATLAB Function: '<S47>/MATLAB Function' incorporates:
  //   Constant: '<S47>/Constant1'
  //   Constant: '<S47>/Constant5'
  //   Inport: '<Root>/cmd'
  //   Lookup_n-D: '<S38>/1-D Lookup Table1'
  //   MATLAB Function: '<S9>/MATLAB Function'
  //   Sum: '<S47>/Add1'

  quat_norm = std::sqrt(look1_iflf_binlx(0.5F * rtU.cmd.thr + 0.5F,
    rtConstP.uDLookupTable1_bp01Data, rtConstP.uDLookupTable1_tableData, 3U) +
                        1000.0F);
  for (b_aoffset = 0; b_aoffset < 16; b_aoffset++) {
    A_tmp[b_aoffset] = quat_norm * rtConstP.Constant5_Value[b_aoffset];
  }

  // MATLAB Function: '<S46>/MATLAB Function' incorporates:
  //   Constant: '<S46>/ny_du_red_trim'

  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    for (aoffset = 0; aoffset < 4; aoffset++) {
      A_tmp_tmp = b_aoffset << 2;
      tmp_1[aoffset + A_tmp_tmp] = (((d[A_tmp_tmp + 1] *
        rtConstP.ny_du_red_trim_Value[aoffset + 4] + d[A_tmp_tmp] *
        rtConstP.ny_du_red_trim_Value[aoffset]) + d[A_tmp_tmp + 2] *
        rtConstP.ny_du_red_trim_Value[aoffset + 8]) + d[A_tmp_tmp + 3] *
        rtConstP.ny_du_red_trim_Value[aoffset + 12]) + rtb_G2[A_tmp_tmp +
        aoffset];
    }
  }

  // MATLAB Function: '<S47>/MATLAB Function' incorporates:
  //   Constant: '<S47>/Constant6'

  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    for (aoffset = 0; aoffset < 4; aoffset++) {
      A_tmp_tmp = b_aoffset << 2;
      i = aoffset + A_tmp_tmp;
      d[i] = 0.0F;
      A_tmp_tmp_0 = A_tmp_tmp + aoffset;
      d[i] = d[A_tmp_tmp_0] + tmp_1[A_tmp_tmp] * A_tmp[aoffset];
      d[i] = tmp_1[A_tmp_tmp + 1] * A_tmp[aoffset + 4] + d[A_tmp_tmp_0];
      d[i] = tmp_1[A_tmp_tmp + 2] * A_tmp[aoffset + 8] + d[A_tmp_tmp_0];
      d[i] = tmp_1[A_tmp_tmp + 3] * A_tmp[aoffset + 12] + d[A_tmp_tmp_0];
    }
  }

  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    A_tmp_tmp = b_aoffset << 2;
    i = b_aoffset << 3;
    A[i] = d[A_tmp_tmp];
    A[4 + i] = rtConstP.Constant6_Value[A_tmp_tmp];
    A_tmp_tmp_0 = A_tmp_tmp + 1;
    A[1 + i] = d[A_tmp_tmp_0];
    A[5 + i] = rtConstP.Constant6_Value[A_tmp_tmp_0];
    A_tmp_tmp_0 = A_tmp_tmp + 2;
    A[2 + i] = d[A_tmp_tmp_0];
    A[6 + i] = rtConstP.Constant6_Value[A_tmp_tmp_0];
    A_tmp_tmp += 3;
    A[3 + i] = d[A_tmp_tmp];
    A[7 + i] = rtConstP.Constant6_Value[A_tmp_tmp];
  }

  // SignalConversion: '<S53>/TmpSignal ConversionAtGainInport1' incorporates:
  //   DiscreteIntegrator: '<S70>/Discrete-Time Integrator'
  //   Inport: '<Root>/measure'
  //   Sum: '<S51>/error1 4'
  //   Sum: '<S51>/error1 5'
  //   Sum: '<S51>/error1 6'
  //   Sum: '<S51>/error1 8'

  rtb_M_bg[2] = absxk;
  rtb_M_bg[5] = rtDW.DiscreteTimeIntegrator_DSTATE_d - rtU.measure.omega_Kb[2];
  rtb_M_bg[8] = t;
  rtb_M_bg[0] = rtb_n_b_d[0];
  rtb_M_bg[3] = rtb_Add[0];
  rtb_M_bg[6] = rtb_n_b_d_dt2[0];
  rtb_M_bg[1] = rtb_n_b_d[1];
  rtb_M_bg[4] = rtb_Add[1];
  rtb_M_bg[7] = rtb_n_b_d_dt2[1];

  // Gain: '<S53>/Gain' incorporates:
  //   SignalConversion: '<S53>/TmpSignal ConversionAtGainInport1'

  for (b_aoffset = 0; b_aoffset < 3; b_aoffset++) {
    rtb_y_gs[b_aoffset] = 0.0F;
    for (aoffset = 0; aoffset < 9; aoffset++) {
      rtb_y_gs[b_aoffset] += rtConstP.Gain_Gain_m[3 * aoffset + b_aoffset] *
        rtb_M_bg[aoffset];
    }
  }

  // End of Gain: '<S53>/Gain'

  // Sum: '<S38>/Add2' incorporates:
  //   Product: '<S38>/MatrixMultiply2'
  //   Sum: '<S41>/Add1'
  //   UnitDelay: '<S38>/Unit Delay1'

  p_free_data[0] = rtb_y_f[0] + rtb_y_gs[0];
  p_free_data[1] = rtb_y_f[1] + rtb_y_gs[1];
  p_free_data[2] = (rtb_z_Kg + rtb_y_gs[2]) - rtb_Diff[2];
  p_free_data[3] = scale;
  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    rtb_y_k[b_aoffset] = (((rtb_G2[b_aoffset + 4] * rtDW.UnitDelay1_DSTATE[1] +
      rtb_G2[b_aoffset] * rtDW.UnitDelay1_DSTATE[0]) + rtb_G2[b_aoffset + 8] *
      rtDW.UnitDelay1_DSTATE[2]) + rtb_G2[b_aoffset + 12] *
                          rtDW.UnitDelay1_DSTATE[3]) + p_free_data[b_aoffset];

    // MATLAB Function: '<S47>/MATLAB Function1' incorporates:
    //   Constant: '<S47>/Constant7'
    //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
    //   Product: '<S38>/MatrixMultiply2'
    //   Sum: '<S47>/Add'
    //   UnitDelay: '<S38>/Unit Delay1'

    tmp_2[b_aoffset] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[b_aoffset];
  }

  // End of Sum: '<S38>/Add2'

  // MATLAB Function: '<S47>/MATLAB Function' incorporates:
  //   Constant: '<S47>/Constant6'
  //   MATLAB Function: '<S47>/MATLAB Function1'

  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    quat_norm = A_tmp[b_aoffset + 12] * rtb_y_k[3] + (A_tmp[b_aoffset + 8] *
      rtb_y_k[2] + (A_tmp[b_aoffset + 4] * rtb_y_k[1] + A_tmp[b_aoffset] *
                    rtb_y_k[0]));
    q0_q2 = rtConstP.Constant6_Value[b_aoffset + 12] * tmp_2[3] +
      (rtConstP.Constant6_Value[b_aoffset + 8] * tmp_2[2] +
       (rtConstP.Constant6_Value[b_aoffset + 4] * tmp_2[1] +
        rtConstP.Constant6_Value[b_aoffset] * tmp_2[0]));
    A_tmp_0[b_aoffset] = quat_norm;
    A_tmp_0[b_aoffset + 4] = q0_q2;
  }

  for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
    quat_norm = A[b_aoffset + 24] * M_bg_idx_8 + (A[b_aoffset + 16] *
      rtb_uDLookupTable2[2] + (A[b_aoffset + 8] * rtb_uDLookupTable2[1] +
      A[b_aoffset] * rtb_uDLookupTable2[0]));
    d_0[b_aoffset] = A_tmp_0[b_aoffset] - quat_norm;
  }

  i_free[0] = true;
  i_free[1] = true;
  i_free[2] = true;
  i_free[3] = true;
  A_tmp_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (A_tmp_tmp <= 99)) {
    A_tmp_tmp_0 = 0;
    if (i_free[0]) {
      A_tmp_tmp_0 = 1;
    }

    if (i_free[1]) {
      A_tmp_tmp_0++;
    }

    if (i_free[2]) {
      A_tmp_tmp_0++;
    }

    if (i_free[3]) {
      A_tmp_tmp_0++;
    }

    i = A_tmp_tmp_0;
    A_tmp_tmp_0 = 0;
    if (i_free[0]) {
      f_data[0] = 1;
      A_tmp_tmp_0 = 1;
    }

    if (i_free[1]) {
      f_data[A_tmp_tmp_0] = 2;
      A_tmp_tmp_0++;
    }

    if (i_free[2]) {
      f_data[A_tmp_tmp_0] = 3;
      A_tmp_tmp_0++;
    }

    if (i_free[3]) {
      f_data[A_tmp_tmp_0] = 4;
    }

    A_free_size[0] = 8;
    A_free_size[1] = i;
    for (b_aoffset = 0; b_aoffset < i; b_aoffset++) {
      for (aoffset = 0; aoffset < 8; aoffset++) {
        A_free_data[aoffset + (b_aoffset << 3)] = A[((f_data[b_aoffset] - 1) <<
          3) + aoffset];
      }
    }

    mldivide(A_free_data, A_free_size, d_0, p_free_data, &p_free_size);
    A_tmp_tmp_0 = 0;
    p_0 = 0.0;
    if (i_free[0]) {
      p_0 = p_free_data[0];
      A_tmp_tmp_0 = 1;
    }

    rtb_u[0] = rtb_uDLookupTable2[0] + (real32_T)p_0;
    p[0] = p_0;
    p_0 = 0.0;
    if (i_free[1]) {
      p_0 = p_free_data[A_tmp_tmp_0];
      A_tmp_tmp_0++;
    }

    rtb_u[1] = rtb_uDLookupTable2[1] + (real32_T)p_0;
    p[1] = p_0;
    p_0 = 0.0;
    if (i_free[2]) {
      p_0 = p_free_data[A_tmp_tmp_0];
      A_tmp_tmp_0++;
    }

    rtb_u[2] = rtb_uDLookupTable2[2] + (real32_T)p_0;
    p[2] = p_0;
    p_0 = 0.0;
    if (i_free[3]) {
      p_0 = p_free_data[A_tmp_tmp_0];
    }

    rtb_u[3] = rtb_uDLookupTable2[3] + (real32_T)p_0;
    p[3] = p_0;
    A_tmp_tmp_0 = 0;
    if (i_free[0]) {
      A_tmp_tmp_0 = 1;
    }

    if (i_free[1]) {
      A_tmp_tmp_0++;
    }

    if (i_free[2]) {
      A_tmp_tmp_0++;
    }

    if (i_free[3]) {
      A_tmp_tmp_0++;
    }

    aoffset = A_tmp_tmp_0;
    A_tmp_tmp_0 = 0;
    if (i_free[0]) {
      g_data[0] = 1;
      A_tmp_tmp_0 = 1;
    }

    rtb_u_0[0] = ((rtb_u[0] < q_yaw[0]) || (rtb_u[0] > rtb_q_red[0]));
    if (i_free[1]) {
      g_data[A_tmp_tmp_0] = 2;
      A_tmp_tmp_0++;
    }

    rtb_u_0[1] = ((rtb_u[1] < q_yaw[1]) || (rtb_u[1] > rtb_q_red[1]));
    if (i_free[2]) {
      g_data[A_tmp_tmp_0] = 3;
      A_tmp_tmp_0++;
    }

    rtb_u_0[2] = ((rtb_u[2] < q_yaw[2]) || (rtb_u[2] > rtb_q_red[2]));
    if (i_free[3]) {
      g_data[A_tmp_tmp_0] = 4;
    }

    rtb_u_0[3] = ((rtb_u[3] < 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[3]) ||
                  (rtb_u[3] > 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[3]));
    for (b_aoffset = 0; b_aoffset < aoffset; b_aoffset++) {
      rtb_u_data[b_aoffset] = rtb_u_0[g_data[b_aoffset] - 1];
    }

    if (!any(rtb_u_data, &aoffset)) {
      rtb_uDLookupTable2[0] = rtb_u[0];
      rtb_uDLookupTable2[1] = rtb_u[1];
      rtb_uDLookupTable2[2] = rtb_u[2];
      rtb_uDLookupTable2[3] = rtb_u[3];
      if (i == 1) {
        for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
          A_tmp_0[b_aoffset] = 0.0F;
          for (aoffset = 0; aoffset < i; aoffset++) {
            A_tmp_0[b_aoffset] += A_free_data[(aoffset << 3) + b_aoffset] *
              p_free_data[aoffset];
          }
        }
      } else if (p_free_size == 1) {
        for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
          A_tmp_0[b_aoffset] = 0.0F;
          for (aoffset = 0; aoffset < i; aoffset++) {
            A_tmp_0[b_aoffset] += A_free_data[(aoffset << 3) + b_aoffset] *
              p_free_data[aoffset];
          }
        }
      } else {
        for (A_tmp_tmp_0 = 0; A_tmp_tmp_0 < 8; A_tmp_tmp_0++) {
          A_tmp_0[A_tmp_tmp_0] = 0.0F;
        }

        for (p_free_size = 0; p_free_size < i; p_free_size++) {
          b_aoffset = p_free_size << 3;
          for (aoffset = 0; aoffset < 8; aoffset++) {
            A_tmp_tmp_0 = b_aoffset + aoffset;
            A_tmp_0[aoffset] += A[((f_data[A_tmp_tmp_0 / 8] - 1) << 3) +
              A_tmp_tmp_0 % 8] * p_free_data[p_free_size];
          }
        }
      }

      for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
        d_0[b_aoffset] -= A_tmp_0[b_aoffset];
      }

      for (i = 0; i < 4; i++) {
        p_free_data[i] = 0.0F;
        for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
          p_free_data[i] += A[(i << 3) + b_aoffset] * d_0[b_aoffset];
        }

        quat_norm = unusedU0[i] * p_free_data[i];
        x[i] = (quat_norm >= -2.22044605E-16F);
        rtb_u[i] = quat_norm;
      }

      x_0 = true;
      A_tmp_tmp_0 = 0;
      exitg2 = false;
      while ((!exitg2) && (A_tmp_tmp_0 < 4)) {
        if (!x[A_tmp_tmp_0]) {
          x_0 = false;
          exitg2 = true;
        } else {
          A_tmp_tmp_0++;
        }
      }

      if (x_0) {
        exitg1 = true;
      } else {
        scale = rtb_u[0];
        A_tmp_tmp_0 = 0;
        if (rtb_u[0] > rtb_u[1]) {
          scale = rtb_u[1];
          A_tmp_tmp_0 = 1;
        }

        if (scale > rtb_u[2]) {
          scale = rtb_u[2];
          A_tmp_tmp_0 = 2;
        }

        if (scale > rtb_u[3]) {
          A_tmp_tmp_0 = 3;
        }

        unusedU0[A_tmp_tmp_0] = 0.0F;
        i_free[A_tmp_tmp_0] = true;
        A_tmp_tmp++;
      }
    } else {
      A_tmp_tmp_0 = 0;
      dist_idx_0 = 1.0;
      x_0 = (p[0] < 0.0);
      e_idx_0 = (p[0] > 0.0);
      if (i_free[0] && x_0) {
        A_tmp_tmp_0 = 1;
      }

      x[0] = x_0;
      dist_idx_1 = 1.0;
      x_0 = (p[1] < 0.0);
      e_idx_1 = (p[1] > 0.0);
      if (i_free[1] && x_0) {
        A_tmp_tmp_0++;
      }

      x[1] = x_0;
      dist_idx_2 = 1.0;
      x_0 = (p[2] < 0.0);
      e_idx_2 = (p[2] > 0.0);
      if (i_free[2] && x_0) {
        A_tmp_tmp_0++;
      }

      x[2] = x_0;
      dist_idx_3 = 1.0;
      x_0 = (p_0 < 0.0);
      e_idx_3 = (p_0 > 0.0);
      if (i_free[3] && x_0) {
        A_tmp_tmp_0++;
      }

      aoffset = A_tmp_tmp_0;
      A_tmp_tmp_0 = 0;
      if (i_free[0] && x[0]) {
        h_data[0] = 1;
        A_tmp_tmp_0 = 1;
      }

      if (i_free[1] && x[1]) {
        h_data[A_tmp_tmp_0] = 2;
        A_tmp_tmp_0++;
      }

      if (i_free[2] && x[2]) {
        h_data[A_tmp_tmp_0] = 3;
        A_tmp_tmp_0++;
      }

      if (i_free[3] && x_0) {
        h_data[A_tmp_tmp_0] = 4;
      }

      for (b_aoffset = 0; b_aoffset < aoffset; b_aoffset++) {
        A_tmp_tmp_0 = h_data[b_aoffset] - 1;
        c_data[b_aoffset] = (q_yaw[A_tmp_tmp_0] - rtb_uDLookupTable2[A_tmp_tmp_0])
          / (real32_T)p[A_tmp_tmp_0];
      }

      A_tmp_tmp_0 = 0;
      if (i_free[0] && x[0]) {
        dist_idx_0 = c_data[0];
        A_tmp_tmp_0 = 1;
      }

      if (i_free[1] && x[1]) {
        dist_idx_1 = c_data[A_tmp_tmp_0];
        A_tmp_tmp_0++;
      }

      if (i_free[2] && x[2]) {
        dist_idx_2 = c_data[A_tmp_tmp_0];
        A_tmp_tmp_0++;
      }

      if (i_free[3] && x_0) {
        dist_idx_3 = c_data[A_tmp_tmp_0];
      }

      A_tmp_tmp_0 = 0;
      if (i_free[0] && e_idx_0) {
        A_tmp_tmp_0 = 1;
      }

      if (i_free[1] && e_idx_1) {
        A_tmp_tmp_0++;
      }

      if (i_free[2] && e_idx_2) {
        A_tmp_tmp_0++;
      }

      if (i_free[3] && e_idx_3) {
        A_tmp_tmp_0++;
      }

      aoffset = A_tmp_tmp_0;
      A_tmp_tmp_0 = 0;
      if (i_free[0] && e_idx_0) {
        i_data[0] = 1;
        A_tmp_tmp_0 = 1;
      }

      if (i_free[1] && e_idx_1) {
        i_data[A_tmp_tmp_0] = 2;
        A_tmp_tmp_0++;
      }

      if (i_free[2] && e_idx_2) {
        i_data[A_tmp_tmp_0] = 3;
        A_tmp_tmp_0++;
      }

      if (i_free[3] && e_idx_3) {
        i_data[A_tmp_tmp_0] = 4;
      }

      for (b_aoffset = 0; b_aoffset < aoffset; b_aoffset++) {
        A_tmp_tmp_0 = i_data[b_aoffset] - 1;
        c_data[b_aoffset] = (rtb_q_red[A_tmp_tmp_0] -
                             rtb_uDLookupTable2[A_tmp_tmp_0]) / (real32_T)
          p[A_tmp_tmp_0];
      }

      A_tmp_tmp_0 = 0;
      if (i_free[0] && e_idx_0) {
        dist_idx_0 = c_data[0];
        A_tmp_tmp_0 = 1;
      }

      if (i_free[1] && e_idx_1) {
        dist_idx_1 = c_data[A_tmp_tmp_0];
        A_tmp_tmp_0++;
      }

      if (i_free[2] && e_idx_2) {
        dist_idx_2 = c_data[A_tmp_tmp_0];
        A_tmp_tmp_0++;
      }

      if (i_free[3] && e_idx_3) {
        dist_idx_3 = c_data[A_tmp_tmp_0];
      }

      A_tmp_tmp_0 = 0;
      if (dist_idx_0 > dist_idx_1) {
        dist_idx_0 = dist_idx_1;
        A_tmp_tmp_0 = 1;
      }

      if (dist_idx_0 > dist_idx_2) {
        dist_idx_0 = dist_idx_2;
        A_tmp_tmp_0 = 2;
      }

      if (dist_idx_0 > dist_idx_3) {
        dist_idx_0 = dist_idx_3;
        A_tmp_tmp_0 = 3;
      }

      rtb_uDLookupTable2[0] += (real32_T)(dist_idx_0 * p[0]);
      rtb_uDLookupTable2[1] += (real32_T)(dist_idx_0 * p[1]);
      rtb_uDLookupTable2[2] += (real32_T)(dist_idx_0 * p[2]);
      rtb_uDLookupTable2[3] += (real32_T)(dist_idx_0 * p_0);
      aoffset = (i << 3) - 1;
      for (b_aoffset = 0; b_aoffset <= aoffset; b_aoffset++) {
        A_free_data[b_aoffset] *= (real32_T)dist_idx_0;
      }

      if (i == 1) {
        for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
          A_tmp_0[b_aoffset] = 0.0F;
          for (aoffset = 0; aoffset < 1; aoffset++) {
            A_tmp_0[b_aoffset] += A_free_data[b_aoffset] * p_free_data[0];
          }
        }
      } else if (p_free_size == 1) {
        for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
          A_tmp_0[b_aoffset] = 0.0F;
          for (aoffset = 0; aoffset < i; aoffset++) {
            A_tmp_0[b_aoffset] += A_free_data[(aoffset << 3) + b_aoffset] *
              p_free_data[aoffset];
          }
        }
      } else {
        for (p_free_size = 0; p_free_size < 8; p_free_size++) {
          A_tmp_0[p_free_size] = 0.0F;
        }

        for (b_aoffset = 0; b_aoffset < i; b_aoffset++) {
          aoffset = b_aoffset << 3;
          for (p_free_size = 0; p_free_size < 8; p_free_size++) {
            A_tmp_0[p_free_size] += A_free_data[aoffset + p_free_size] *
              p_free_data[b_aoffset];
          }
        }
      }

      for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
        d_0[b_aoffset] -= A_tmp_0[b_aoffset];
      }

      if (p[A_tmp_tmp_0] < 0.0) {
        unusedU0[A_tmp_tmp_0] = -1.0F;
      } else if (p[A_tmp_tmp_0] > 0.0) {
        unusedU0[A_tmp_tmp_0] = 1.0F;
      } else {
        unusedU0[A_tmp_tmp_0] = (real32_T)p[A_tmp_tmp_0];
      }

      i_free[A_tmp_tmp_0] = false;
      A_tmp_tmp++;
    }
  }

  // Sum: '<S9>/Add6' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'

  u0 = rtb_uDLookupTable2[0] + rtDW.DiscreteTimeIntegratory_DSTAT_g[0];

  // Saturate: '<S9>/Saturation3'
  if (u0 > 1.0F) {
    u0 = 1.0F;
  } else {
    if (u0 < 0.1F) {
      u0 = 0.1F;
    }
  }

  // Sum: '<S44>/Sum2' incorporates:
  //   Delay: '<S9>/Delay'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'
  //   Gain: '<S44>/2*d//omega'
  //   Sum: '<S44>/Sum3'

  q_yaw[0] = rtDW.Delay_DSTATE[0] - (0.0039788736F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[0] +
    rtDW.DiscreteTimeIntegratory_DSTAT_g[0]);

  // Sum: '<S9>/Add6' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'

  u0_0 = rtb_uDLookupTable2[1] + rtDW.DiscreteTimeIntegratory_DSTAT_g[1];

  // Saturate: '<S9>/Saturation3'
  if (u0_0 > 1.0F) {
    u0_0 = 1.0F;
  } else {
    if (u0_0 < 0.1F) {
      u0_0 = 0.1F;
    }
  }

  // Sum: '<S44>/Sum2' incorporates:
  //   Delay: '<S9>/Delay'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'
  //   Gain: '<S44>/2*d//omega'
  //   Sum: '<S44>/Sum3'

  q_yaw[1] = rtDW.Delay_DSTATE[1] - (0.0039788736F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[1] +
    rtDW.DiscreteTimeIntegratory_DSTAT_g[1]);

  // Sum: '<S9>/Add6' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'

  u0_1 = rtb_uDLookupTable2[2] + rtDW.DiscreteTimeIntegratory_DSTAT_g[2];

  // Saturate: '<S9>/Saturation3'
  if (u0_1 > 1.0F) {
    u0_1 = 1.0F;
  } else {
    if (u0_1 < 0.1F) {
      u0_1 = 0.1F;
    }
  }

  // Sum: '<S44>/Sum2' incorporates:
  //   Delay: '<S9>/Delay'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'
  //   Gain: '<S44>/2*d//omega'
  //   Sum: '<S44>/Sum3'

  q_yaw[2] = rtDW.Delay_DSTATE[2] - (0.0039788736F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[2] +
    rtDW.DiscreteTimeIntegratory_DSTAT_g[2]);

  // Sum: '<S9>/Add6' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'

  u0_2 = rtb_uDLookupTable2[3] + rtDW.DiscreteTimeIntegratory_DSTAT_g[3];

  // Saturate: '<S9>/Saturation3'
  if (u0_2 > 1.0F) {
    u0_2 = 1.0F;
  } else {
    if (u0_2 < 0.1F) {
      u0_2 = 0.1F;
    }
  }

  // Sum: '<S44>/Sum2' incorporates:
  //   Delay: '<S9>/Delay'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'
  //   Gain: '<S44>/2*d//omega'
  //   Sum: '<S44>/Sum3'

  q_yaw[3] = rtDW.Delay_DSTATE[3] - (0.0039788736F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[3] +
    rtDW.DiscreteTimeIntegratory_DSTAT_g[3]);

  // Outport: '<Root>/u' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Gain: '<Root>/Gain2'
  //   Gain: '<Root>/Gain3'
  //   Gain: '<Root>/Gain4'
  //   Saturate: '<S9>/Saturation3'

  rtY.u[0] = u0_0;
  rtY.u[1] = u0_2;
  rtY.u[2] = u0;
  rtY.u[3] = u0_1;
  rtY.u[4] = 0.0F;
  rtY.u[5] = 0.0F;
  rtY.u[6] = 0.0F;
  rtY.u[7] = 0.0F;

  // MATLAB Function: '<S17>/quaternion to  reduced attitude unit vector'
  scale = 1.29246971E-26F;
  absxk = std::abs(q0_q3);
  if (absxk > 1.29246971E-26F) {
    quat_norm = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    quat_norm = t * t;
  }

  absxk = std::abs(q1_q3);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(q2_q3);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(q3_q3);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  quat_norm = scale * std::sqrt(quat_norm);
  if (0.01 < quat_norm) {
    scale = quat_norm;
  } else {
    scale = 0.01F;
  }

  q0_q3 /= scale;
  q1_q3 /= scale;
  q2_q3 /= scale;
  rtb_q_cmd = q3_q3 / scale;
  absxk = q0_q3 * q0_q3;
  t = q1_q3 * q1_q3;
  quat_norm = q2_q3 * q2_q3;
  q3_q3 = rtb_q_cmd * rtb_q_cmd;
  M_bg_idx_8 = q0_q3 * q1_q3;
  q0_q2 = q0_q3 * q2_q3;
  q0_q3 *= rtb_q_cmd;
  scale = q1_q3 * q2_q3;
  q1_q3 *= rtb_q_cmd;
  q2_q3 *= rtb_q_cmd;
  rtb_M_bg[0] = ((absxk + t) - quat_norm) - q3_q3;
  rtb_M_bg[1] = (scale + q0_q3) * 2.0F;
  rtb_M_bg[2] = (q1_q3 - q0_q2) * 2.0F;
  rtb_M_bg[3] = (scale - q0_q3) * 2.0F;
  absxk -= t;
  rtb_M_bg[4] = (absxk + quat_norm) - q3_q3;
  rtb_M_bg[5] = (q2_q3 + M_bg_idx_8) * 2.0F;
  rtb_M_bg[6] = (q1_q3 + q0_q2) * 2.0F;
  rtb_M_bg[7] = (q2_q3 - M_bg_idx_8) * 2.0F;
  rtb_M_bg[8] = (absxk - quat_norm) + q3_q3;
  for (i = 0; i < 3; i++) {
    // Sum: '<S74>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S74>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S74>/Discrete-Time Integrator y_dt'
    //   Gain: '<S74>/2*d//omega'
    //   Sum: '<S74>/Sum3'

    rtb_y_gs[i] = rtb_omega2[i] - (0.0319788754F *
      rtDW.DiscreteTimeIntegratory_dt_DS_g[i] +
      rtDW.DiscreteTimeIntegratory_DSTAT_i[i]);

    // Sum: '<S73>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
    //   DiscreteIntegrator: '<S73>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S73>/Discrete-Time Integrator y_dt'
    //   Gain: '<S73>/2*d//omega'
    //   Sum: '<S73>/Sum3'

    rtb_y_dt[i] = rtDW.DiscreteTimeIntegratory_dt_DSTA[i] - (0.0319788754F *
      rtDW.DiscreteTimeIntegratory_dt_DS_c[i] +
      rtDW.DiscreteTimeIntegratory_DSTAT_h[i]);

    // Sum: '<S72>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S72>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S72>/Discrete-Time Integrator y_dt'
    //   Gain: '<S72>/2*d//omega'
    //   Sum: '<S72>/Sum3'

    rtb_n_b_d_dt2[i] = rtDW.DiscreteTimeIntegratory_DSTATE[i] - (0.0319788754F *
      rtDW.DiscreteTimeIntegratory_dt_DS_p[i] +
      rtDW.DiscreteTimeIntegratory_DSTAT_m[i]);
    rtb_Diff[i] = -rtb_M_bg[i + 6];
  }

  // End of MATLAB Function: '<S17>/quaternion to  reduced attitude unit vector' 

  // MATLAB Function: '<S17>/MATLAB Function4'
  MATLABFunction4(rtb_Diff, &scale, &absxk);

  // Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S83>/1//T'
  //   Saturate: '<S9>/Saturation3'
  //   Sum: '<S83>/Sum2'

  rtDW.DiscreteTimeIntegrator_DSTATE[0] += (u0 -
    rtDW.DiscreteTimeIntegrator_DSTATE[0]) * 35.7142868F * 0.0025F;
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += (u0_0 -
    rtDW.DiscreteTimeIntegrator_DSTATE[1]) * 35.7142868F * 0.0025F;
  rtDW.DiscreteTimeIntegrator_DSTATE[2] += (u0_1 -
    rtDW.DiscreteTimeIntegrator_DSTATE[2]) * 35.7142868F * 0.0025F;
  rtDW.DiscreteTimeIntegrator_DSTATE[3] += (u0_2 -
    rtDW.DiscreteTimeIntegrator_DSTATE[3]) * 35.7142868F * 0.0025F;

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_LOAD = 0U;

  // Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_LO_e = 0U;

  // Update for UnitDelay: '<S36>/UD'
  //
  //  Block description for '<S36>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[0] = rtb_TSamp_idx_0;

  // Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTATE[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[0];

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S72>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_m[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_p[0];

  // Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
  rtDW.DiscreteTimeIntegratory_dt_DSTA[0] += 0.0025F * rtb_omega2[0];

  // Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S73>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_h[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_c[0];

  // Update for UnitDelay: '<S36>/UD'
  //
  //  Block description for '<S36>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[1] = rtb_TSamp_idx_1;

  // Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTATE[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[1];

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S72>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_m[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_p[1];

  // Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
  rtDW.DiscreteTimeIntegratory_dt_DSTA[1] += 0.0025F * rtb_omega2[1];

  // Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S73>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_h[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_c[1];

  // Update for UnitDelay: '<S36>/UD'
  //
  //  Block description for '<S36>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[2] = rtb_M_bg_tmp;

  // Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTATE[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[2];

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S72>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_m[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_p[2];

  // Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator y_dt'
  rtDW.DiscreteTimeIntegratory_dt_DSTA[2] += 0.0025F * rtb_omega2[2];

  // Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S73>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_h[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_c[2];

  // Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
  //   Saturate: '<S34>/Saturation'

  rtDW.DiscreteTimeIntegrator_DSTATE_k[0] += 0.0025F * y;
  rtDW.DiscreteTimeIntegrator_DSTATE_k[1] += 0.0025F * y_0;

  // Update for UnitDelay: '<S7>/UD'
  //
  //  Block description for '<S7>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_h[0] = cmd_V_NED_idx_0;
  rtDW.UD_DSTATE_h[1] = cmd_V_NED_idx_1;
  rtDW.UD_DSTATE_h[2] = cmd_V_NED;

  // Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE_i += 0.0025F * cos_Psi;

  // Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S74>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_IC_LO_j = 0U;
  rtDW.DiscreteTimeIntegratory_DSTAT_i[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_g[0];
  rtDW.DiscreteTimeIntegratory_DSTAT_i[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_g[1];
  rtDW.DiscreteTimeIntegratory_DSTAT_i[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_g[2];

  // Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator2' incorporates:
  //   DiscreteIntegrator: '<S70>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator2_IC_LOAD = 0U;
  rtDW.DiscreteTimeIntegrator2_DSTATE += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_d;

  // Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE_d += 0.0025F * rtb_z_Kg;

  // Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator3'
  rtDW.DiscreteTimeIntegrator3_IC_LOAD = 0U;
  rtDW.DiscreteTimeIntegrator3_DSTATE += 0.0025F * sin_Psi;

  // Update for UnitDelay: '<S37>/UD'
  //
  //  Block description for '<S37>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_a = rtb_phi_a;
  for (b_aoffset = 0; b_aoffset < 6; b_aoffset++) {
    // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator y' incorporates:
    //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator y_dt'

    rtDW.DiscreteTimeIntegratory_DSTA_hs[b_aoffset] += 0.0025F *
      rtDW.DiscreteTimeIntegratory_dt_DS_b[b_aoffset];

    // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator y_dt' incorporates:
    //   Gain: '<S35>/omega^2'

    rtDW.DiscreteTimeIntegratory_dt_DS_b[b_aoffset] += 101.368347F *
      rtb_Add_p[b_aoffset] * 0.0025F;
  }

  // Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  rtDW.DiscreteTimeIntegrator_DSTAT_ki[0] += 0.0025F * rtb_y_p_idx_0;
  rtDW.DiscreteTimeIntegrator_DSTAT_ki[1] += 0.0025F * rtb_y_p_idx_1;

  // Update for UnitDelay: '<S38>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[0] = rtb_uDLookupTable2[0];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_g[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[0];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S44>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[0] += 252661.875F * q_yaw[0] * 0.0025F;

  // Update for Delay: '<S9>/Delay'
  rtDW.Delay_DSTATE[0] = rtb_y_idx_0;

  // Update for UnitDelay: '<S38>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[1] = rtb_uDLookupTable2[1];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_g[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[1];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S44>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[1] += 252661.875F * q_yaw[1] * 0.0025F;

  // Update for Delay: '<S9>/Delay'
  rtDW.Delay_DSTATE[1] = rtb_y_idx_1;

  // Update for UnitDelay: '<S38>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[2] = rtb_uDLookupTable2[2];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_g[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[2];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S44>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[2] += 252661.875F * q_yaw[2] * 0.0025F;

  // Update for Delay: '<S9>/Delay'
  rtDW.Delay_DSTATE[2] = rtb_y_idx_2;

  // Update for UnitDelay: '<S38>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[3] = rtb_uDLookupTable2[3];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_g[3] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[3];

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S44>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[3] += 252661.875F * q_yaw[3] * 0.0025F;

  // Update for Delay: '<S9>/Delay'
  rtDW.Delay_DSTATE[3] = rtb_y_idx_3;

  // Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S74>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_g[0] += 3911.41284F * rtb_y_gs[0] * 0.0025F;

  // Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S73>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_c[0] += 3911.41284F * rtb_y_dt[0] * 0.0025F;

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S72>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_p[0] += 3911.41284F * rtb_n_b_d_dt2[0] *
    0.0025F;

  // Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S74>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_g[1] += 3911.41284F * rtb_y_gs[1] * 0.0025F;

  // Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S73>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_c[1] += 3911.41284F * rtb_y_dt[1] * 0.0025F;

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S72>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_p[1] += 3911.41284F * rtb_n_b_d_dt2[1] *
    0.0025F;

  // Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S74>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_g[2] += 3911.41284F * rtb_y_gs[2] * 0.0025F;

  // Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S73>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_c[2] += 3911.41284F * rtb_y_dt[2] * 0.0025F;

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y_dt' incorporates:
  //   Gain: '<S72>/omega^2'

  rtDW.DiscreteTimeIntegratory_dt_DS_p[2] += 3911.41284F * rtb_n_b_d_dt2[2] *
    0.0025F;
}

// Model initialize function
void MatlabControllerClass::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_DSTATE[0] = 0.0F;
  rtDW.DiscreteTimeIntegratory_DSTATE[1] = 0.0F;
  rtDW.DiscreteTimeIntegratory_DSTATE[2] = -1.0F;

  // InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LOAD = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_e = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_j = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator2' 
  rtDW.DiscreteTimeIntegrator2_IC_LOAD = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator3' 
  rtDW.DiscreteTimeIntegrator3_IC_LOAD = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_IC_LOADI = 1U;
}

// Constructor
MatlabControllerClass::MatlabControllerClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
MatlabControllerClass::~MatlabControllerClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
