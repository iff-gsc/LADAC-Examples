//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: MatlabController.cpp
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

// Exported block parameters
struct_MEcmzRVPGSpBEP8QmwPNUF cntrl = {
  {
    0.52359879F,
    0.52359879F,
    2.09439516F,
    13.0,
    5.0,
    6.0F,
    4.0F,

    {
      9.0,
      1.0
    },

    {
      9.0,
      1.0
    },

    {
      0.4
    },

    {
      0.8
    },
    4.0,
    -7.0,
    0.0135,

    {
      100.0,
      1.0
    }
  },

  {
    { 0.0, 0.0, 0.0, 0.0 },

    { 1.0, 1.0, 1.0, 1.0 },

    { 0.0, 0.0, 0.0, 0.0 },

    { 100.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
      0.0, 1.0 },

    { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
      1.0 },
    100000.0,

    { 0.0, 0.0, 0.0, 0.0 },
    100.0
  },
  0.0025,

  { 0.562, 0.562, 0.562, 0.562 },

  { 327.01708, 259.70776, 16.39404, -10.91948, -327.01708, 259.70776, -16.39404,
    -10.91948, -327.01708, -259.70776, 16.39404, -10.91948, 327.01708,
    -259.70776, -16.39404, -10.91948 },

  { -0.0, 0.0, 9.7162, 0.0, 0.0, -0.0, -9.7162, 0.0, -0.0, 0.0, 9.7162, 0.0, 0.0,
    -0.0, -9.7162, 0.0 },

  { 50.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 50.0F, 0.0F, 0.0F, -0.0F, 0.0F, 0.0F,
    50.0F, 0.0F, 0.0F, 0.0F, -0.0F, 0.0F, 50.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F,
    1.5F, 15.16F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 15.16F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 15.16F, 0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 15.16F, 0.0F, 0.0F, 0.0F, -0.0F,
    -0.0F, 2.0221F, 0.2132F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.2132F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.2132F, 0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.2132F, -0.0F,
    0.0F, 0.0F, -0.0F, -0.0F, 0.0297F },

  { 1.4429F, 0.0F, 0.0F, 1.4429F, 2.492F, 0.0F, 0.0F, 2.492F, 0.2717F, 0.0F,
    0.0F, 0.2717F },

  { 2.1434F, 0.0F, 0.0F, 2.1434F, 2.8016F, 0.0F, 0.0F, 2.8016F, 0.3455F, 0.0F,
    0.0F, 0.3455F },

  { 0.4224F, 0.0F, 0.0F, 0.4224F },

  { 15.7164049F, 15.7164049F },
  1.0
} ;                                    // Variable: cntrl
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


extern real32_T rt_hypotf(real32_T u0, real32_T u1);
static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
static void MATLABFunction2(real32_T rtu_phi, real32_T rtu_delta, real32_T
  rty_q_cmd_red[4]);
static void MATLABFunction1(real32_T rtu_z_g_dt2, const real32_T rtu_M_bg[9],
  real32_T *rty_ny_z_b_dt2);
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
//    '<S7>/MATLAB Function2'
//    '<S7>/MATLAB Function8'
//
static void MATLABFunction2(real32_T rtu_phi, real32_T rtu_delta, real32_T
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
//    '<S16>/MATLAB Function1'
//    '<S18>/MATLAB Function'
//
static void MATLABFunction1(real32_T rtu_z_g_dt2, const real32_T rtu_M_bg[9],
  real32_T *rty_ny_z_b_dt2)
{
  real32_T z_1_b;
  z_1_b = rtu_M_bg[8];
  if (std::abs(rtu_M_bg[8]) < 0.1F) {
    if (rtu_M_bg[8] > 0.0F) {
      z_1_b = 0.1F;
    } else {
      z_1_b = -0.1F;
    }
  }

  *rty_ny_z_b_dt2 = rtu_z_g_dt2 / z_1_b;
}

// Function for MATLAB Function: '<S34>/MATLAB Function3'
real32_T MatlabControllerClass::norm(const real32_T x[4])
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

  absxk = std::abs(x[3]);
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

// Function for MATLAB Function: '<S14>/quaternion time derivative'
void MatlabControllerClass::quatmultiply(const real32_T q[4], const real32_T r[4],
  real32_T qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

// Function for MATLAB Function: '<S17>/MATLAB Function2'
void MatlabControllerClass::quatInv(const real32_T q[4], real32_T q_inv[4])
{
  real32_T quat_norm;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = std::abs(q[0]);
  if (absxk > 1.29246971E-26F) {
    quat_norm = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    quat_norm = t * t;
  }

  absxk = std::abs(-q[1]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(-q[2]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(-q[3]);
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

  q_inv[0] = q[0] / quat_norm;
  q_inv[1] = -q[1] / quat_norm;
  q_inv[2] = -q[2] / quat_norm;
  q_inv[3] = -q[3] / quat_norm;
}

// Function for MATLAB Function: '<S16>/MATLAB Function3'
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

// Function for MATLAB Function: '<S31>/MATLAB Function'
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

// Function for MATLAB Function: '<S31>/MATLAB Function'
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

// Function for MATLAB Function: '<S31>/MATLAB Function'
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

// Function for MATLAB Function: '<S31>/MATLAB Function'
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

// Function for MATLAB Function: '<S31>/MATLAB Function'
void MatlabControllerClass::mldivide(const real32_T A_data[], const int32_T
  A_size[2], const real32_T B_0[8], real32_T Y_data[], int32_T *Y_size)
{
  if (A_size[1] == 0) {
    *Y_size = 0;
  } else {
    qrsolve(A_data, A_size, B_0, Y_data, Y_size);
  }
}

// Function for MATLAB Function: '<S31>/MATLAB Function'
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
  int32_T j;
  real32_T quat_norm;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real32_T sin_Phi_2;
  real32_T cos_Phi_2;
  real32_T q3_q3;
  real32_T q0_q1;
  real32_T q0_q2;
  real32_T q0_q3;
  real32_T q1_q2;
  real32_T q1_q3;
  real32_T q2_q3;
  real32_T M_be[9];
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
  real32_T rtb_ch2rpyt[4];
  real32_T rtb_x_dt_ref_ok[2];
  real32_T rtb_q[4];
  real32_T rtb_Gain[5];
  real32_T rtb_Saturation2[4];
  real32_T rtb_DiscreteTimeIntegrator1[3];
  real32_T rtb_TmpSignalConversionAtSFun_l[15];
  real32_T rtb_Add4[3];
  real32_T rtb_q_cmd_n[4];
  real32_T rtb_q_bg_dt2[4];
  real32_T rtb_q_bg_dt[4];
  real32_T rtb_q_e_dt2[4];
  real32_T rtb_G2[16];
  real32_T rtb_M_bg[9];
  real32_T rtb_x_ref_ca[9];
  real32_T Constant9[4];
  real32_T Constant6[16];
  real32_T A_tmp[16];
  int32_T i;
  boolean_T rtb_q_data[4];
  real32_T rtb_Gain_0[4];
  real32_T rtb_q_red_0[4];
  real32_T tmp[4];
  real32_T tmp_0[6];
  real32_T tmp_1[6];
  real32_T tmp_2[6];
  real32_T tmp_3[2];
  real32_T tmp_4[16];
  real32_T rtb_Add4_0[4];
  real32_T A_tmp_0[8];
  boolean_T rtb_q_0[4];
  int32_T A_free_size[2];
  int32_T p_free_size;
  real_T p_0;
  boolean_T x_0;
  real32_T rtb_q_red_idx_3;
  real32_T omega_Kb_idx_2;
  real32_T rtb_TSamp_f_idx_2;
  real32_T rtb_q_red_idx_1;
  real32_T rtb_q_red_idx_2;
  real_T dist_idx_0;
  real32_T rtb_x_ref_b_idx_0;
  real32_T rtb_x_ref_b_idx_1;
  real32_T rtb_TSamp_i_idx_1;
  real32_T rtb_TSamp_l_idx_1;
  real32_T rtb_Sum2_k_idx_0;
  real32_T rtb_Sum2_p_idx_1;
  real32_T rtb_omega2_n_idx_1;
  real32_T rtb_omega2_g_idx_1;
  real32_T rtb_Sum2_k_idx_1;
  real32_T rtb_Sum2_p_idx_2;
  real32_T rtb_omega2_n_idx_2;
  real32_T rtb_omega2_g_idx_2;
  real32_T rtb_Sum2_k_idx_2;
  boolean_T e_idx_0;
  real_T dist_idx_1;
  boolean_T e_idx_1;
  real_T dist_idx_2;
  boolean_T e_idx_2;
  real_T dist_idx_3;
  boolean_T e_idx_3;
  real32_T y;
  real32_T y_0;
  real32_T u_tmp;
  int32_T A_tmp_tmp;
  boolean_T exitg1;
  boolean_T exitg2;

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   Constant: '<S15>/Constant2'
  //   Constant: '<S15>/Constant4'

  for (i = 0; i < 16; i++) {
    rtb_G2[i] = (real32_T)cntrl.ny_du_dt[i] / (real32_T)cntrl.sample_time;
    d[i] = 0.0F;
  }

  // MinMax: '<S15>/Max' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  if (rtDW.x_DSTATE[0] > 0.1F) {
    rtb_TSamp_f_idx_2 = rtDW.x_DSTATE[0];
  } else {
    rtb_TSamp_f_idx_2 = 0.1F;
  }

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   Constant: '<S15>/Constant'

  d[0] = rtb_TSamp_f_idx_2 / (real32_T)cntrl.u_trim[0];

  // MinMax: '<S15>/Max' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  if (rtDW.x_DSTATE[1] > 0.1F) {
    rtb_TSamp_f_idx_2 = rtDW.x_DSTATE[1];
  } else {
    rtb_TSamp_f_idx_2 = 0.1F;
  }

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   Constant: '<S15>/Constant'

  d[5] = rtb_TSamp_f_idx_2 / (real32_T)cntrl.u_trim[1];

  // MinMax: '<S15>/Max' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  if (rtDW.x_DSTATE[2] > 0.1F) {
    rtb_TSamp_f_idx_2 = rtDW.x_DSTATE[2];
  } else {
    rtb_TSamp_f_idx_2 = 0.1F;
  }

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   Constant: '<S15>/Constant'

  d[10] = rtb_TSamp_f_idx_2 / (real32_T)cntrl.u_trim[2];

  // MinMax: '<S15>/Max' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  if (rtDW.x_DSTATE[3] > 0.1F) {
    rtb_TSamp_f_idx_2 = rtDW.x_DSTATE[3];
  } else {
    rtb_TSamp_f_idx_2 = 0.1F;
  }

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   Constant: '<S15>/Constant'

  d[15] = rtb_TSamp_f_idx_2 / (real32_T)cntrl.u_trim[3];

  // Constant: '<S31>/Constant6'
  for (i = 0; i < 16; i++) {
    Constant6[i] = (real32_T)cntrl.ca.W_u[i];
  }

  // End of Constant: '<S31>/Constant6'

  // MATLAB Function: '<S56>/MATLAB Function' incorporates:
  //   DiscreteIntegrator: '<S56>/x'

  scale = 1.29246971E-26F;
  absxk = std::abs(rtDW.x_DSTATE_f[0]);
  if (absxk > 1.29246971E-26F) {
    quat_norm = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    quat_norm = t * t;
  }

  absxk = std::abs(rtDW.x_DSTATE_f[1]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(rtDW.x_DSTATE_f[2]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(rtDW.x_DSTATE_f[3]);
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

  rtb_q[0] = rtDW.x_DSTATE_f[0] / quat_norm;
  rtb_q[1] = rtDW.x_DSTATE_f[1] / quat_norm;
  rtb_q[2] = rtDW.x_DSTATE_f[2] / quat_norm;
  rtb_q[3] = rtDW.x_DSTATE_f[3] / quat_norm;

  // End of MATLAB Function: '<S56>/MATLAB Function'

  // SignalConversion: '<S51>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   MATLAB Function: '<S21>/Euler Angles to Quaternions'

  rtb_DiscreteTimeIntegrator1[0] = 0.0F;
  rtb_DiscreteTimeIntegrator1[1] = 0.0F;

  // DiscreteIntegrator: '<S21>/Discrete-Time Integrator6' incorporates:
  //   MATLAB Function: '<S21>/Euler Angles to Quaternions'

  if (rtDW.DiscreteTimeIntegrator6_IC_LOAD != 0) {
    // MATLAB Function: '<S21>/Euler Angles to Quaternions' incorporates:
    //   Inport: '<Root>/cmd'
    //   SignalConversion: '<S51>/TmpSignal ConversionAt SFunction Inport1'

    rtb_x_ref_b_idx_0 = rtU.cmd.yaw_init / 2.0F;
    rtDW.DiscreteTimeIntegrator6_DSTATE[0] = std::cos(rtb_x_ref_b_idx_0);
    rtDW.DiscreteTimeIntegrator6_DSTATE[1] = 0.0F;

    // MATLAB Function: '<S21>/Euler Angles to Quaternions'
    rtDW.DiscreteTimeIntegrator6_DSTATE[2] = 0.0F;
    rtDW.DiscreteTimeIntegrator6_DSTATE[3] = std::sin(rtb_x_ref_b_idx_0);
  }

  // Gain: '<S5>/ch2rpyt' incorporates:
  //   Inport: '<Root>/cmd'

  rtb_ch2rpyt[0] = 13.0F * rtU.cmd.roll;
  rtb_ch2rpyt[1] = 13.0F * rtU.cmd.pitch;
  rtb_ch2rpyt[2] = rtU.cmd.yaw;
  rtb_ch2rpyt[3] = rtU.cmd.thr;

  // DiscreteIntegrator: '<S29>/x'
  rtb_x_ref_b_idx_0 = rtDW.x_DSTATE_g[0];
  rtb_x_ref_b_idx_1 = rtDW.x_DSTATE_g[1];

  // Gain: '<S29>/1//T' incorporates:
  //   DiscreteIntegrator: '<S29>/x'
  //   Gain: '<S5>/Gain1'
  //   Sum: '<S29>/Sum2'

  quat_norm = (-rtb_ch2rpyt[1] - rtDW.x_DSTATE_g[0]) * 1.25F;

  // Saturate: '<S29>/Saturation'
  if (quat_norm > (real32_T)cntrl.rm.uv_dt_max) {
    y = (real32_T)cntrl.rm.uv_dt_max;
    rtb_x_dt_ref_ok[0] = (real32_T)cntrl.rm.uv_dt_max;
  } else if (quat_norm < -5.0F) {
    y = -5.0F;
    rtb_x_dt_ref_ok[0] = -5.0F;
  } else {
    y = quat_norm;
    rtb_x_dt_ref_ok[0] = quat_norm;
  }

  // Gain: '<S29>/1//T' incorporates:
  //   DiscreteIntegrator: '<S29>/x'
  //   Gain: '<S5>/Gain1'
  //   Sum: '<S29>/Sum2'

  quat_norm = (rtb_ch2rpyt[0] - rtDW.x_DSTATE_g[1]) * 1.25F;

  // Saturate: '<S29>/Saturation'
  if (quat_norm > (real32_T)cntrl.rm.uv_dt_max) {
    y_0 = (real32_T)cntrl.rm.uv_dt_max;
    rtb_x_dt_ref_ok[1] = (real32_T)cntrl.rm.uv_dt_max;
  } else if (quat_norm < -5.0F) {
    y_0 = -5.0F;
    rtb_x_dt_ref_ok[1] = -5.0F;
  } else {
    y_0 = quat_norm;
    rtb_x_dt_ref_ok[1] = quat_norm;
  }

  // DiscreteIntegrator: '<S27>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/cmd'

  if (rtDW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    rtDW.DiscreteTimeIntegrator_DSTATE[0] = rtU.cmd.s_Kg_init[0];
    rtDW.DiscreteTimeIntegrator_DSTATE[1] = rtU.cmd.s_Kg_init[1];
  }

  // DiscreteIntegrator: '<S55>/x'
  sin_Phi_2 = rtDW.x_DSTATE_h;

  // Gain: '<S55>/1//T' incorporates:
  //   DiscreteIntegrator: '<S55>/x'
  //   Inport: '<Root>/cmd'
  //   Lookup_n-D: '<S21>/1-D Lookup Table'
  //   Sum: '<S55>/Sum2'

  cos_Phi_2 = (look1_iflf_binlx(rtU.cmd.thr, rtConstP.uDLookupTable_bp01Data,
    rtConstP.uDLookupTable_tableData, 2U) - rtDW.x_DSTATE_h) * 2.5F;

  // Saturate: '<S55>/Saturation'
  if (cos_Phi_2 > (real32_T)cntrl.rm.w_dt_max) {
    cos_Phi_2 = (real32_T)cntrl.rm.w_dt_max;
  } else {
    if (cos_Phi_2 < (real32_T)cntrl.rm.w_dt_min) {
      cos_Phi_2 = (real32_T)cntrl.rm.w_dt_min;
    }
  }

  // End of Saturate: '<S55>/Saturation'

  // Sum: '<S28>/Add' incorporates:
  //   DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S29>/x'
  //   DiscreteIntegrator: '<S38>/x'
  //   DiscreteIntegrator: '<S39>/x'
  //   DiscreteIntegrator: '<S40>/x'
  //   Saturate: '<S29>/Saturation'

  tmp_0[0] = rtDW.x_DSTATE_c[0];
  tmp_0[2] = rtDW.x_DSTATE_l[0];
  tmp_0[4] = rtDW.x_DSTATE_fe[0];
  tmp_1[0] = rtDW.DiscreteTimeIntegrator_DSTATE[0];
  tmp_1[2] = rtDW.x_DSTATE_g[0];
  tmp_1[4] = y;
  tmp_0[1] = rtDW.x_DSTATE_c[1];
  tmp_0[3] = rtDW.x_DSTATE_l[1];
  tmp_0[5] = rtDW.x_DSTATE_fe[1];
  tmp_1[1] = rtDW.DiscreteTimeIntegrator_DSTATE[1];
  tmp_1[3] = rtDW.x_DSTATE_g[1];
  tmp_1[5] = y_0;

  // Gain: '<S28>/Gain'
  for (b_aoffset = 0; b_aoffset < 6; b_aoffset++) {
    // Saturate: '<S28>/Saturation1' incorporates:
    //   Sum: '<S28>/Add'

    quat_norm = tmp_1[b_aoffset] - tmp_0[b_aoffset];
    if (quat_norm > rtConstP.Saturation1_UpperSat[b_aoffset]) {
      tmp_2[b_aoffset] = rtConstP.Saturation1_UpperSat[b_aoffset];
    } else if (quat_norm < rtConstP.Saturation1_LowerSat[b_aoffset]) {
      tmp_2[b_aoffset] = rtConstP.Saturation1_LowerSat[b_aoffset];
    } else {
      tmp_2[b_aoffset] = quat_norm;
    }

    // End of Saturate: '<S28>/Saturation1'
  }

  for (b_aoffset = 0; b_aoffset < 2; b_aoffset++) {
    tmp_3[b_aoffset] = 0.0F;
    for (aoffset = 0; aoffset < 6; aoffset++) {
      tmp_3[b_aoffset] += cntrl.Kpos[(aoffset << 1) + b_aoffset] * tmp_2[aoffset];
    }

    // Saturate: '<S28>/Saturation' incorporates:
    //   Sum: '<S7>/Add1'

    if (tmp_3[b_aoffset] > (real32_T)cntrl.rm.uv_dt_max) {
      rtb_TSamp_f_idx_2 = (real32_T)cntrl.rm.uv_dt_max;
    } else if (tmp_3[b_aoffset] < -5.0F) {
      rtb_TSamp_f_idx_2 = -5.0F;
    } else {
      rtb_TSamp_f_idx_2 = tmp_3[b_aoffset];
    }

    // End of Saturate: '<S28>/Saturation'

    // SignalConversion: '<S22>/TmpSignal ConversionAt SFunction Inport1' incorporates:
    //   MATLAB Function: '<S7>/MATLAB Function1'
    //   Sum: '<S7>/Add1'

    rtb_DiscreteTimeIntegrator1[b_aoffset] = rtb_x_dt_ref_ok[b_aoffset] +
      rtb_TSamp_f_idx_2;
  }

  // End of Gain: '<S28>/Gain'

  // MATLAB Function: '<S7>/MATLAB Function1' incorporates:
  //   Constant: '<S7>/Constant1'
  //   Sum: '<S7>/Add'

  rtb_TSamp_f_idx_2 = cos_Phi_2 + -9.81F;
  if (std::abs(cos_Phi_2 + -9.81F) < 1.0F) {
    if (cos_Phi_2 + -9.81F > 0.0F) {
      rtb_TSamp_f_idx_2 = 1.0F;
    } else {
      rtb_TSamp_f_idx_2 = -1.0F;
    }
  }

  quat_norm = std::atan2(std::sqrt(rtb_DiscreteTimeIntegrator1[0] *
    rtb_DiscreteTimeIntegrator1[0] + rtb_DiscreteTimeIntegrator1[1] *
    rtb_DiscreteTimeIntegrator1[1]), -rtb_TSamp_f_idx_2);

  // Saturate: '<S7>/Saturation'
  if (quat_norm > cntrl.rm.Phi_max) {
    quat_norm = cntrl.rm.Phi_max;
  } else {
    if (quat_norm < 0.0F) {
      quat_norm = 0.0F;
    }
  }

  // End of Saturate: '<S7>/Saturation'

  // MATLAB Function: '<S7>/MATLAB Function8' incorporates:
  //   MATLAB Function: '<S7>/MATLAB Function1'

  MATLABFunction2(quat_norm, std::atan2(rtb_DiscreteTimeIntegrator1[1],
    rtb_DiscreteTimeIntegrator1[0]), rtb_Saturation2);

  // MATLAB Function: '<S7>/MATLAB Function9' incorporates:
  //   DiscreteIntegrator: '<S40>/x'
  //   Sum: '<S5>/Add4'

  rtb_TSamp_f_idx_2 = rtDW.x_DSTATE_fe[2] + -9.81F;
  if (std::abs(rtDW.x_DSTATE_fe[2] + -9.81F) < 1.0F) {
    if (rtDW.x_DSTATE_fe[2] + -9.81F > 0.0F) {
      rtb_TSamp_f_idx_2 = 1.0F;
    } else {
      rtb_TSamp_f_idx_2 = -1.0F;
    }
  }

  // MATLAB Function: '<S7>/MATLAB Function2' incorporates:
  //   DiscreteIntegrator: '<S40>/x'
  //   MATLAB Function: '<S7>/MATLAB Function9'

  MATLABFunction2(std::atan2(std::sqrt(rtDW.x_DSTATE_fe[0] * rtDW.x_DSTATE_fe[0]
    + rtDW.x_DSTATE_fe[1] * rtDW.x_DSTATE_fe[1]), -rtb_TSamp_f_idx_2), std::
                  atan2(rtDW.x_DSTATE_fe[1], rtDW.x_DSTATE_fe[0]), rtb_ch2rpyt);

  // MATLAB Function: '<S7>/MATLAB Function11'
  quat_norm = ((rtb_ch2rpyt[0] * rtb_ch2rpyt[0] + rtb_ch2rpyt[1] * rtb_ch2rpyt[1])
               + rtb_ch2rpyt[2] * rtb_ch2rpyt[2]) + rtb_ch2rpyt[3] *
    rtb_ch2rpyt[3];
  rtb_TSamp_f_idx_2 = rtb_ch2rpyt[0] / quat_norm;
  rtb_q_red_idx_1 = -rtb_ch2rpyt[1] / quat_norm;
  rtb_q_red_idx_2 = -rtb_ch2rpyt[2] / quat_norm;
  rtb_q_red_idx_3 = -rtb_ch2rpyt[3] / quat_norm;
  rtb_ch2rpyt[0] = ((rtb_TSamp_f_idx_2 * rtb_Saturation2[0] - rtb_q_red_idx_1 *
                     rtb_Saturation2[1]) - rtb_q_red_idx_2 * rtb_Saturation2[2])
    - rtb_q_red_idx_3 * rtb_Saturation2[3];
  rtb_ch2rpyt[1] = (rtb_TSamp_f_idx_2 * rtb_Saturation2[1] + rtb_Saturation2[0] *
                    rtb_q_red_idx_1) + (rtb_q_red_idx_2 * rtb_Saturation2[3] -
    rtb_q_red_idx_3 * rtb_Saturation2[2]);
  rtb_ch2rpyt[2] = (rtb_TSamp_f_idx_2 * rtb_Saturation2[2] + rtb_Saturation2[0] *
                    rtb_q_red_idx_2) + (rtb_q_red_idx_3 * rtb_Saturation2[1] -
    rtb_q_red_idx_1 * rtb_Saturation2[3]);
  rtb_ch2rpyt[3] = (rtb_TSamp_f_idx_2 * rtb_Saturation2[3] + rtb_Saturation2[0] *
                    rtb_q_red_idx_3) + (rtb_q_red_idx_1 * rtb_Saturation2[2] -
    rtb_q_red_idx_2 * rtb_Saturation2[1]);

  // MATLAB Function: '<Root>/Quaternions to Rotation Matrix' incorporates:
  //   Inport: '<Root>/measure'

  scale = 1.29246971E-26F;
  absxk = std::abs(rtU.measure.q_bg[0]);
  if (absxk > 1.29246971E-26F) {
    quat_norm = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    quat_norm = t * t;
  }

  absxk = std::abs(rtU.measure.q_bg[1]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(rtU.measure.q_bg[2]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

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
  if (0.01 >= quat_norm) {
    quat_norm = 0.01F;
  }

  rtb_q_cmd_n[0] = rtU.measure.q_bg[0] / quat_norm;
  rtb_q_cmd_n[1] = rtU.measure.q_bg[1] / quat_norm;
  rtb_q_cmd_n[2] = rtU.measure.q_bg[2] / quat_norm;
  rtb_q_cmd_n[3] = rtU.measure.q_bg[3] / quat_norm;
  scale = rtb_q_cmd_n[0] * rtb_q_cmd_n[0];
  absxk = rtb_q_cmd_n[1] * rtb_q_cmd_n[1];
  t = rtb_q_cmd_n[2] * rtb_q_cmd_n[2];
  q3_q3 = rtb_q_cmd_n[3] * rtb_q_cmd_n[3];
  q0_q1 = rtb_q_cmd_n[0] * rtb_q_cmd_n[1];
  q0_q2 = rtb_q_cmd_n[0] * rtb_q_cmd_n[2];
  q0_q3 = rtb_q_cmd_n[0] * rtb_q_cmd_n[3];
  q1_q2 = rtb_q_cmd_n[1] * rtb_q_cmd_n[2];
  q1_q3 = rtb_q_cmd_n[1] * rtb_q_cmd_n[3];
  q2_q3 = rtb_q_cmd_n[2] * rtb_q_cmd_n[3];
  rtb_M_bg[0] = ((scale + absxk) - t) - q3_q3;
  rtb_M_bg[3] = (q1_q2 + q0_q3) * 2.0F;
  rtb_M_bg[6] = (q1_q3 - q0_q2) * 2.0F;
  rtb_M_bg[1] = (q1_q2 - q0_q3) * 2.0F;
  rtb_TSamp_f_idx_2 = scale - absxk;
  rtb_M_bg[4] = (rtb_TSamp_f_idx_2 + t) - q3_q3;
  rtb_M_bg[7] = (q2_q3 + q0_q1) * 2.0F;
  rtb_M_bg[2] = (q1_q3 + q0_q2) * 2.0F;
  rtb_M_bg[5] = (q2_q3 - q0_q1) * 2.0F;
  rtb_M_bg[8] = (rtb_TSamp_f_idx_2 - t) + q3_q3;

  // End of MATLAB Function: '<Root>/Quaternions to Rotation Matrix'

  // MATLAB Function: '<S20>/MATLAB Function1'
  if (1.0F > rtb_M_bg[8]) {
    quat_norm = rtb_M_bg[8];
  } else {
    quat_norm = 1.0F;
  }

  if (-1.0F >= quat_norm) {
    quat_norm = -1.0F;
  }

  quat_norm = std::acos(quat_norm);
  scale = std::sin(quat_norm);
  scale = scale * scale - rtb_M_bg[2] * rtb_M_bg[2];
  if (rtb_M_bg[5] >= 0.0F) {
    b_aoffset = -1;
  } else {
    b_aoffset = 1;
  }

  if (0.0F >= scale) {
    scale = 0.0F;
  }

  rtb_q_red_idx_2 = std::atan2((real32_T)b_aoffset * std::sqrt(scale),
    -rtb_M_bg[2]);

  // MATLAB Function: '<S20>/MATLAB Function3' incorporates:
  //   MATLAB Function: '<S20>/MATLAB Function1'

  rtb_TSamp_f_idx_2 = std::cos(quat_norm / 2.0F);
  rtb_q_red_idx_3 = std::sin(quat_norm / 2.0F);
  rtb_q_red_idx_1 = rtb_q_red_idx_3 * std::sin(rtb_q_red_idx_2);
  rtb_q_red_idx_2 = rtb_q_red_idx_3 * -std::cos(rtb_q_red_idx_2);

  // MATLAB Function: '<S5>/MATLAB Function5'
  rtb_q_cmd_n[0] = (rtb_TSamp_f_idx_2 * rtb_ch2rpyt[0] - rtb_q_red_idx_1 *
                    rtb_ch2rpyt[1]) - rtb_q_red_idx_2 * rtb_ch2rpyt[2];
  rtb_q_cmd_n[1] = (rtb_TSamp_f_idx_2 * rtb_ch2rpyt[1] + rtb_ch2rpyt[0] *
                    rtb_q_red_idx_1) + rtb_q_red_idx_2 * rtb_ch2rpyt[3];
  rtb_q_cmd_n[2] = (rtb_TSamp_f_idx_2 * rtb_ch2rpyt[2] + rtb_ch2rpyt[0] *
                    rtb_q_red_idx_2) + (0.0F - rtb_q_red_idx_1 * rtb_ch2rpyt[3]);
  rtb_q_cmd_n[3] = (rtb_q_red_idx_1 * rtb_ch2rpyt[2] - rtb_q_red_idx_2 *
                    rtb_ch2rpyt[1]) + rtb_TSamp_f_idx_2 * rtb_ch2rpyt[3];

  // Gain: '<S56>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator6'
  //   DiscreteIntegrator: '<S56>/x_dt'
  //   Gain: '<S56>/2*d//omega'
  //   MATLAB Function: '<S21>/MATLAB Function7'
  //   Sum: '<S56>/Sum2'
  //   Sum: '<S56>/Sum3'

  rtb_TSamp_f_idx_2 = ((((rtb_q_cmd_n[0] * rtDW.DiscreteTimeIntegrator6_DSTATE[0]
    - rtb_q_cmd_n[1] * rtDW.DiscreteTimeIntegrator6_DSTATE[1]) - rtb_q_cmd_n[2] *
    rtDW.DiscreteTimeIntegrator6_DSTATE[2]) - rtb_q_cmd_n[3] *
                        rtDW.DiscreteTimeIntegrator6_DSTATE[3]) - (0.222222224F *
    rtDW.x_dt_DSTATE[0] + rtb_q[0])) * 81.0F;
  rtb_q_red_idx_1 = (((rtb_q_cmd_n[0] * rtDW.DiscreteTimeIntegrator6_DSTATE[1] +
                       rtDW.DiscreteTimeIntegrator6_DSTATE[0] * rtb_q_cmd_n[1])
                      + (rtb_q_cmd_n[2] * rtDW.DiscreteTimeIntegrator6_DSTATE[3]
    - rtb_q_cmd_n[3] * rtDW.DiscreteTimeIntegrator6_DSTATE[2])) - (0.222222224F *
    rtDW.x_dt_DSTATE[1] + rtb_q[1])) * 81.0F;
  rtb_q_red_idx_2 = (((rtb_q_cmd_n[0] * rtDW.DiscreteTimeIntegrator6_DSTATE[2] +
                       rtDW.DiscreteTimeIntegrator6_DSTATE[0] * rtb_q_cmd_n[2])
                      + (rtb_q_cmd_n[3] * rtDW.DiscreteTimeIntegrator6_DSTATE[1]
    - rtb_q_cmd_n[1] * rtDW.DiscreteTimeIntegrator6_DSTATE[3])) - (0.222222224F *
    rtDW.x_dt_DSTATE[2] + rtb_q[2])) * 81.0F;
  rtb_q_red_idx_3 = (((rtb_q_cmd_n[0] * rtDW.DiscreteTimeIntegrator6_DSTATE[3] +
                       rtDW.DiscreteTimeIntegrator6_DSTATE[0] * rtb_q_cmd_n[3])
                      + (rtb_q_cmd_n[1] * rtDW.DiscreteTimeIntegrator6_DSTATE[2]
    - rtb_q_cmd_n[2] * rtDW.DiscreteTimeIntegrator6_DSTATE[1])) - (0.222222224F *
    rtDW.x_dt_DSTATE[3] + rtb_q[3])) * 81.0F;

  // DiscreteIntegrator: '<S36>/x'
  for (i = 0; i < 9; i++) {
    rtb_x_ref_ca[i] = rtDW.x_DSTATE_c5[i];
  }

  // MATLAB Function: '<S34>/MATLAB Function3' incorporates:
  //   DiscreteIntegrator: '<S36>/x'
  //   UnitDelay: '<S34>/Unit Delay'

  scale = ((1.0F + rtDW.x_DSTATE_c5[0]) + rtDW.x_DSTATE_c5[4]) +
    rtDW.x_DSTATE_c5[8];
  if (0.0F >= scale) {
    scale = 0.0F;
  }

  quat_norm = 0.5F * std::sqrt(scale);
  scale = ((1.0F + rtDW.x_DSTATE_c5[0]) - rtDW.x_DSTATE_c5[4]) -
    rtDW.x_DSTATE_c5[8];
  if (0.0F >= scale) {
    scale = 0.0F;
  }

  scale = 0.5F * std::sqrt(scale);
  absxk = ((1.0F - rtDW.x_DSTATE_c5[0]) + rtDW.x_DSTATE_c5[4]) -
    rtDW.x_DSTATE_c5[8];
  if (0.0F >= absxk) {
    absxk = 0.0F;
  }

  absxk = 0.5F * std::sqrt(absxk);
  t = ((1.0F - rtDW.x_DSTATE_c5[0]) - rtDW.x_DSTATE_c5[4]) + rtDW.x_DSTATE_c5[8];
  if (0.0F >= t) {
    t = 0.0F;
  }

  t = 0.5F * std::sqrt(t);
  q3_q3 = quat_norm;
  j = -1;
  if (quat_norm < scale) {
    q3_q3 = scale;
    j = 0;
  }

  if (q3_q3 < absxk) {
    q3_q3 = absxk;
    j = 1;
  }

  if (q3_q3 < t) {
    j = 2;
  }

  switch (j + 1) {
   case 0:
    u_tmp = rtDW.x_DSTATE_c5[7] - rtDW.x_DSTATE_c5[5];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    scale *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[2] - rtDW.x_DSTATE_c5[6];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    absxk *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[3] - rtDW.x_DSTATE_c5[1];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    t *= u_tmp;
    break;

   case 1:
    u_tmp = rtDW.x_DSTATE_c5[7] - rtDW.x_DSTATE_c5[5];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    quat_norm *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[3] + rtDW.x_DSTATE_c5[1];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    absxk *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[2] + rtDW.x_DSTATE_c5[6];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    t *= u_tmp;
    break;

   case 2:
    u_tmp = rtDW.x_DSTATE_c5[2] - rtDW.x_DSTATE_c5[6];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    quat_norm *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[3] + rtDW.x_DSTATE_c5[1];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    scale *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[7] + rtDW.x_DSTATE_c5[5];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    t *= u_tmp;
    break;

   case 3:
    u_tmp = rtDW.x_DSTATE_c5[3] - rtDW.x_DSTATE_c5[1];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    quat_norm *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[2] + rtDW.x_DSTATE_c5[6];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    scale *= u_tmp;
    u_tmp = rtDW.x_DSTATE_c5[7] + rtDW.x_DSTATE_c5[5];
    if (u_tmp < 0.0F) {
      u_tmp = -1.0F;
    } else {
      if (u_tmp > 0.0F) {
        u_tmp = 1.0F;
      }
    }

    absxk *= u_tmp;
    break;
  }

  rtb_ch2rpyt[0] = quat_norm;
  rtb_ch2rpyt[1] = scale;
  rtb_ch2rpyt[2] = absxk;
  rtb_ch2rpyt[3] = t;
  quat_norm = norm(rtb_ch2rpyt);
  if (0.01 >= quat_norm) {
    quat_norm = 0.01F;
  }

  rtb_ch2rpyt[0] /= quat_norm;
  rtb_ch2rpyt[1] = scale / quat_norm;
  rtb_ch2rpyt[2] = absxk / quat_norm;
  u_tmp = t / quat_norm;
  rtb_ch2rpyt[3] = u_tmp;
  if (norm(rtDW.UnitDelay_DSTATE) > 0.5F) {
    scale = ((rtb_ch2rpyt[0] * rtDW.UnitDelay_DSTATE[0] + rtb_ch2rpyt[1] *
              rtDW.UnitDelay_DSTATE[1]) + rtb_ch2rpyt[2] *
             rtDW.UnitDelay_DSTATE[2]) + u_tmp * rtDW.UnitDelay_DSTATE[3];
    if (scale < 0.0F) {
      scale = -1.0F;
    } else {
      if (scale > 0.0F) {
        scale = 1.0F;
      }
    }

    rtb_ch2rpyt[0] *= scale;
    rtb_ch2rpyt[1] *= scale;
    rtb_ch2rpyt[2] *= scale;
    rtb_ch2rpyt[3] = scale * u_tmp;
  }

  // End of MATLAB Function: '<S34>/MATLAB Function3'

  // MATLAB Function: '<S14>/quaternion time derivative'
  p_free_data[0] = 0.0F;

  // SampleTimeMath: '<S35>/TSamp' incorporates:
  //   DiscreteIntegrator: '<S37>/x'
  //
  //  About '<S35>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  u_tmp = rtDW.x_DSTATE_gw[0] * 400.0F;

  // Sum: '<S35>/Diff' incorporates:
  //   UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  rtb_Add4[0] = u_tmp - rtDW.UD_DSTATE[0];

  // MATLAB Function: '<S14>/quaternion time derivative' incorporates:
  //   DiscreteIntegrator: '<S37>/x'

  p_free_data[1] = rtDW.x_DSTATE_gw[0];

  // SampleTimeMath: '<S35>/TSamp' incorporates:
  //   DiscreteIntegrator: '<S37>/x'
  //
  //  About '<S35>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_DiscreteTimeIntegrator1[0] = u_tmp;
  u_tmp = rtDW.x_DSTATE_gw[1] * 400.0F;

  // Sum: '<S35>/Diff' incorporates:
  //   UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  rtb_Add4[1] = u_tmp - rtDW.UD_DSTATE[1];

  // MATLAB Function: '<S14>/quaternion time derivative' incorporates:
  //   DiscreteIntegrator: '<S37>/x'

  p_free_data[2] = rtDW.x_DSTATE_gw[1];

  // SampleTimeMath: '<S35>/TSamp' incorporates:
  //   DiscreteIntegrator: '<S37>/x'
  //
  //  About '<S35>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_DiscreteTimeIntegrator1[1] = u_tmp;
  u_tmp = rtDW.x_DSTATE_gw[2] * 400.0F;

  // Sum: '<S35>/Diff' incorporates:
  //   UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  rtb_Add4[2] = u_tmp - rtDW.UD_DSTATE[2];

  // MATLAB Function: '<S14>/quaternion time derivative' incorporates:
  //   DiscreteIntegrator: '<S37>/x'

  p_free_data[3] = rtDW.x_DSTATE_gw[2];
  quatmultiply(rtb_ch2rpyt, p_free_data, rtb_q_bg_dt);
  rtb_q_bg_dt[0] *= 0.5F;
  rtb_q_bg_dt[1] *= 0.5F;
  rtb_q_bg_dt[2] *= 0.5F;
  rtb_q_bg_dt[3] *= 0.5F;
  p_free_data[0] = 0.0F;
  p_free_data[1] = rtb_Add4[0];
  p_free_data[2] = rtb_Add4[1];
  p_free_data[3] = rtb_Add4[2];
  quatmultiply(rtb_ch2rpyt, p_free_data, rtb_q_bg_dt2);
  p_free_data[0] = 0.0F;
  p_free_data[1] = rtDW.x_DSTATE_gw[0];
  p_free_data[2] = rtDW.x_DSTATE_gw[1];
  p_free_data[3] = rtDW.x_DSTATE_gw[2];
  quatmultiply(rtb_q_bg_dt, p_free_data, tmp);

  // MATLAB Function: '<S17>/MATLAB Function2'
  quatInv(rtb_ch2rpyt, p_free_data);
  quatmultiply(p_free_data, rtb_q, rtb_q_cmd_n);
  quatInv(rtb_ch2rpyt, p_free_data);
  quatmultiply(rtb_q_bg_dt, rtb_q_cmd_n, rtb_Gain_0);

  // MATLAB Function: '<S14>/quaternion time derivative'
  rtb_q_bg_dt2[0] = (rtb_q_bg_dt2[0] + tmp[0]) * 0.5F;

  // MATLAB Function: '<S17>/MATLAB Function2' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtb_q_e_dt2[0] = rtDW.x_dt_DSTATE[0] - rtb_Gain_0[0];

  // MATLAB Function: '<S14>/quaternion time derivative'
  rtb_q_bg_dt2[1] = (rtb_q_bg_dt2[1] + tmp[1]) * 0.5F;

  // MATLAB Function: '<S17>/MATLAB Function2' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtb_q_e_dt2[1] = rtDW.x_dt_DSTATE[1] - rtb_Gain_0[1];

  // MATLAB Function: '<S14>/quaternion time derivative'
  rtb_q_bg_dt2[2] = (rtb_q_bg_dt2[2] + tmp[2]) * 0.5F;

  // MATLAB Function: '<S17>/MATLAB Function2' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtb_q_e_dt2[2] = rtDW.x_dt_DSTATE[2] - rtb_Gain_0[2];

  // MATLAB Function: '<S14>/quaternion time derivative'
  rtb_q_bg_dt2[3] = (rtb_q_bg_dt2[3] + tmp[3]) * 0.5F;

  // MATLAB Function: '<S17>/MATLAB Function2' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtb_q_e_dt2[3] = rtDW.x_dt_DSTATE[3] - rtb_Gain_0[3];
  quatmultiply(p_free_data, rtb_q_e_dt2, rtb_Saturation2);
  quatInv(rtb_ch2rpyt, p_free_data);
  quatmultiply(rtb_q_bg_dt2, rtb_q_cmd_n, tmp);
  quatmultiply(rtb_q_bg_dt, rtb_Saturation2, rtb_Gain_0);
  rtb_q_red_0[0] = (rtb_TSamp_f_idx_2 + -tmp[0]) + -2.0F * rtb_Gain_0[0];
  rtb_q_red_0[1] = (rtb_q_red_idx_1 + -tmp[1]) + -2.0F * rtb_Gain_0[1];
  rtb_q_red_0[2] = (rtb_q_red_idx_2 + -tmp[2]) + -2.0F * rtb_Gain_0[2];
  rtb_q_red_0[3] = (rtb_q_red_idx_3 + -tmp[3]) + -2.0F * rtb_Gain_0[3];
  quatmultiply(p_free_data, rtb_q_red_0, rtb_q_e_dt2);

  // DiscreteIntegrator: '<S21>/Discrete-Time Integrator3' incorporates:
  //   Inport: '<Root>/cmd'

  if (rtDW.DiscreteTimeIntegrator3_IC_LOAD != 0) {
    rtDW.DiscreteTimeIntegrator3_DSTATE = rtU.cmd.s_Kg_init[2];
  }

  // SignalConversion: '<S30>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator3'
  //   DiscreteIntegrator: '<S38>/x'
  //   DiscreteIntegrator: '<S39>/x'
  //   DiscreteIntegrator: '<S40>/x'
  //   DiscreteIntegrator: '<S55>/x'
  //   MATLAB Function: '<S8>/MATLAB Function'
  //   Sum: '<S17>/error1 1'
  //   Sum: '<S17>/error1 2'
  //   Sum: '<S17>/error1 3'

  rtb_TmpSignalConversionAtSFun_l[4] = rtDW.DiscreteTimeIntegrator3_DSTATE -
    rtDW.x_DSTATE_c[2];
  rtb_TmpSignalConversionAtSFun_l[9] = rtDW.x_DSTATE_h - rtDW.x_DSTATE_l[2];
  rtb_TmpSignalConversionAtSFun_l[5] = rtb_Saturation2[0];
  rtb_TmpSignalConversionAtSFun_l[10] = rtb_q_e_dt2[0];
  rtb_TmpSignalConversionAtSFun_l[1] = rtb_q_cmd_n[1];
  rtb_TmpSignalConversionAtSFun_l[6] = rtb_Saturation2[1];
  rtb_TmpSignalConversionAtSFun_l[11] = rtb_q_e_dt2[1];
  rtb_TmpSignalConversionAtSFun_l[2] = rtb_q_cmd_n[2];
  rtb_TmpSignalConversionAtSFun_l[7] = rtb_Saturation2[2];
  rtb_TmpSignalConversionAtSFun_l[12] = rtb_q_e_dt2[2];
  rtb_TmpSignalConversionAtSFun_l[3] = rtb_q_cmd_n[3];
  rtb_TmpSignalConversionAtSFun_l[8] = rtb_Saturation2[3];
  rtb_TmpSignalConversionAtSFun_l[13] = rtb_q_e_dt2[3];
  rtb_TmpSignalConversionAtSFun_l[14] = cos_Phi_2 - rtDW.x_DSTATE_fe[2];

  // MATLAB Function: '<S8>/MATLAB Function' incorporates:
  //   SignalConversion: '<S30>/TmpSignal ConversionAt SFunction Inport1'

  rtb_TmpSignalConversionAtSFun_l[0] = rtb_q_cmd_n[0] - 1.0F;

  // Sum: '<S36>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S36>/x'
  //   DiscreteIntegrator: '<S36>/x_dt'
  //   Gain: '<S36>/2*d//omega'
  //   Sum: '<S36>/Sum3'

  for (b_aoffset = 0; b_aoffset < 9; b_aoffset++) {
    rtb_M_bg[b_aoffset] -= 0.02F * rtDW.x_dt_DSTATE_a[b_aoffset] +
      rtDW.x_DSTATE_c5[b_aoffset];
  }

  // End of Sum: '<S36>/Sum2'

  // Gain: '<S8>/Gain'
  for (b_aoffset = 0; b_aoffset < 5; b_aoffset++) {
    rtb_Gain[b_aoffset] = 0.0F;
    for (aoffset = 0; aoffset < 15; aoffset++) {
      rtb_Gain[b_aoffset] += cntrl.K[5 * aoffset + b_aoffset] *
        rtb_TmpSignalConversionAtSFun_l[aoffset];
    }
  }

  // End of Gain: '<S8>/Gain'

  // MATLAB Function: '<S18>/MATLAB Function'
  MATLABFunction1(cos_Phi_2, rtb_x_ref_ca, &quat_norm);

  // MATLAB Function: '<S16>/MATLAB Function3'
  p_free_data[0] = rtb_q_cmd_n[0];
  p_free_data[1] = -rtb_q_cmd_n[1];
  p_free_data[2] = -rtb_q_cmd_n[2];
  p_free_data[3] = -rtb_q_cmd_n[3];
  quatNormalize(p_free_data, rtb_q_bg_dt);
  quatNormalize(rtb_q_bg_dt, rtb_q_cmd_n);
  scale = rtb_q_cmd_n[0] * rtb_q_cmd_n[0];
  absxk = rtb_q_cmd_n[1] * rtb_q_cmd_n[1];
  t = rtb_q_cmd_n[2] * rtb_q_cmd_n[2];
  q3_q3 = rtb_q_cmd_n[3] * rtb_q_cmd_n[3];
  q0_q1 = rtb_q_cmd_n[0] * rtb_q_cmd_n[1];
  q0_q2 = rtb_q_cmd_n[0] * rtb_q_cmd_n[2];
  q0_q3 = rtb_q_cmd_n[0] * rtb_q_cmd_n[3];
  q1_q2 = rtb_q_cmd_n[1] * rtb_q_cmd_n[2];
  q1_q3 = rtb_q_cmd_n[1] * rtb_q_cmd_n[3];
  q2_q3 = rtb_q_cmd_n[2] * rtb_q_cmd_n[3];
  M_be[0] = ((scale + absxk) - t) - q3_q3;
  M_be[3] = (q1_q2 + q0_q3) * 2.0F;
  M_be[6] = (q1_q3 - q0_q2) * 2.0F;
  M_be[1] = (q1_q2 - q0_q3) * 2.0F;
  q0_q3 = scale - absxk;
  M_be[4] = (q0_q3 + t) - q3_q3;
  M_be[7] = (q2_q3 + q0_q1) * 2.0F;
  M_be[2] = (q1_q3 + q0_q2) * 2.0F;
  M_be[5] = (q2_q3 - q0_q1) * 2.0F;
  M_be[8] = (q0_q3 - t) + q3_q3;

  // MATLAB Function: '<S16>/MATLAB Function1'
  MATLABFunction1(rtb_Gain[4], rtb_x_ref_ca, &scale);

  // MATLAB Function: '<S31>/MATLAB Function1' incorporates:
  //   Constant: '<S31>/Constant3'
  //   Constant: '<S31>/Constant4'
  //   DiscreteIntegrator: '<S11>/x'

  q3_q3 = (real32_T)cntrl.ca.u_min[0] - rtDW.x_DSTATE[0];
  q0_q1 = (real32_T)cntrl.ca.u_max[0] - rtDW.x_DSTATE[0];
  rtb_q_cmd_n[0] = (q3_q3 + q0_q1) * 0.5F;

  // Constant: '<S31>/Constant9'
  Constant9[0] = (real32_T)cntrl.ca.W[0];

  // MATLAB Function: '<S31>/MATLAB Function1' incorporates:
  //   Constant: '<S31>/Constant3'
  //   Constant: '<S31>/Constant4'
  //   DiscreteIntegrator: '<S11>/x'

  rtb_q_bg_dt2[0] = q3_q3;
  rtb_q_e_dt2[0] = q0_q1;
  q3_q3 = (real32_T)cntrl.ca.u_min[1] - rtDW.x_DSTATE[1];
  q0_q1 = (real32_T)cntrl.ca.u_max[1] - rtDW.x_DSTATE[1];
  rtb_q_cmd_n[1] = (q3_q3 + q0_q1) * 0.5F;

  // Constant: '<S31>/Constant9'
  Constant9[1] = (real32_T)cntrl.ca.W[1];

  // MATLAB Function: '<S31>/MATLAB Function1' incorporates:
  //   Constant: '<S31>/Constant3'
  //   Constant: '<S31>/Constant4'
  //   DiscreteIntegrator: '<S11>/x'

  rtb_q_bg_dt2[1] = q3_q3;
  rtb_q_e_dt2[1] = q0_q1;
  q3_q3 = (real32_T)cntrl.ca.u_min[2] - rtDW.x_DSTATE[2];
  q0_q1 = (real32_T)cntrl.ca.u_max[2] - rtDW.x_DSTATE[2];
  rtb_q_cmd_n[2] = (q3_q3 + q0_q1) * 0.5F;

  // Constant: '<S31>/Constant9'
  Constant9[2] = (real32_T)cntrl.ca.W[2];

  // MATLAB Function: '<S31>/MATLAB Function1' incorporates:
  //   Constant: '<S31>/Constant3'
  //   Constant: '<S31>/Constant4'
  //   DiscreteIntegrator: '<S11>/x'

  rtb_q_bg_dt2[2] = q3_q3;
  rtb_q_e_dt2[2] = q0_q1;
  q3_q3 = (real32_T)cntrl.ca.u_min[3] - rtDW.x_DSTATE[3];
  q0_q1 = (real32_T)cntrl.ca.u_max[3] - rtDW.x_DSTATE[3];
  rtb_q_cmd_n[3] = (q3_q3 + q0_q1) * 0.5F;

  // Constant: '<S31>/Constant9'
  Constant9[3] = (real32_T)cntrl.ca.W[3];

  // MATLAB Function: '<S31>/MATLAB Function1'
  rtb_q_bg_dt2[3] = q3_q3;
  rtb_q_e_dt2[3] = q0_q1;

  // MATLAB Function: '<S31>/MATLAB Function' incorporates:
  //   Constant: '<S31>/Constant1'
  //   Constant: '<S31>/Constant5'
  //   Fcn: '<S5>/Fcn'
  //   Inport: '<Root>/cmd'
  //   Lookup_n-D: '<S13>/1-D Lookup Table1'
  //   Sum: '<S31>/Add1'

  absxk = std::sqrt(look1_iflf_binlx(0.5F - 0.5F * rtU.cmd.thr,
    rtConstP.uDLookupTable1_bp01Data, rtConstP.uDLookupTable1_tableData, 3U) +
                    (real32_T)cntrl.ca.gamma);
  for (b_aoffset = 0; b_aoffset < 16; b_aoffset++) {
    A_tmp[b_aoffset] = absxk * (real32_T)cntrl.ca.W_v[b_aoffset];
  }

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   Constant: '<S15>/ny_du_red_trim'

  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    for (aoffset = 0; aoffset < 4; aoffset++) {
      A_tmp_tmp = b_aoffset << 2;
      tmp_4[aoffset + A_tmp_tmp] = (((d[A_tmp_tmp + 1] * (real32_T)
        cntrl.ny_du_red[aoffset + 4] + d[A_tmp_tmp] * (real32_T)
        cntrl.ny_du_red[aoffset]) + d[A_tmp_tmp + 2] * (real32_T)
        cntrl.ny_du_red[aoffset + 8]) + d[A_tmp_tmp + 3] * (real32_T)
        cntrl.ny_du_red[aoffset + 12]) + rtb_G2[A_tmp_tmp + aoffset];
    }
  }

  // MATLAB Function: '<S31>/MATLAB Function'
  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    for (aoffset = 0; aoffset < 4; aoffset++) {
      A_tmp_tmp = b_aoffset << 2;
      i = aoffset + A_tmp_tmp;
      d[i] = 0.0F;
      j = A_tmp_tmp + aoffset;
      d[i] = d[j] + tmp_4[A_tmp_tmp] * A_tmp[aoffset];
      d[i] = tmp_4[A_tmp_tmp + 1] * A_tmp[aoffset + 4] + d[j];
      d[i] = tmp_4[A_tmp_tmp + 2] * A_tmp[aoffset + 8] + d[j];
      d[i] = tmp_4[A_tmp_tmp + 3] * A_tmp[aoffset + 12] + d[j];
    }
  }

  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    A_tmp_tmp = b_aoffset << 2;
    i = b_aoffset << 3;
    A[i] = d[A_tmp_tmp];
    A[4 + i] = Constant6[A_tmp_tmp];
    j = A_tmp_tmp + 1;
    A[1 + i] = d[j];
    A[5 + i] = Constant6[j];
    j = A_tmp_tmp + 2;
    A[2 + i] = d[j];
    A[6 + i] = Constant6[j];
    A_tmp_tmp += 3;
    A[3 + i] = d[A_tmp_tmp];
    A[7 + i] = Constant6[A_tmp_tmp];
  }

  // MATLAB Function: '<S18>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  quatInv(rtb_q, p_free_data);
  quatInv(rtb_q, tmp);
  quatmultiply(tmp, rtDW.x_dt_DSTATE, rtb_Gain_0);
  tmp[0] = 0.0F;
  tmp[1] = 2.0F * rtb_Gain_0[1];
  tmp[2] = 2.0F * rtb_Gain_0[2];
  tmp[3] = 2.0F * rtb_Gain_0[3];
  quatmultiply(rtDW.x_dt_DSTATE, tmp, rtb_Gain_0);
  rtb_q_red_0[0] = rtb_TSamp_f_idx_2 - 0.5F * rtb_Gain_0[0];
  rtb_q_red_0[1] = rtb_q_red_idx_1 - 0.5F * rtb_Gain_0[1];
  rtb_q_red_0[2] = rtb_q_red_idx_2 - 0.5F * rtb_Gain_0[2];
  rtb_q_red_0[3] = rtb_q_red_idx_3 - 0.5F * rtb_Gain_0[3];
  quatmultiply(p_free_data, rtb_q_red_0, tmp);

  // MATLAB Function: '<S16>/MATLAB Function3'
  quatmultiply(rtb_q_bg_dt, rtb_Saturation2, p_free_data);
  rtb_Gain_0[0] = 0.0F;
  for (b_aoffset = 0; b_aoffset < 3; b_aoffset++) {
    rtb_Gain_0[b_aoffset + 1] = M_be[b_aoffset + 6] * (2.0F * p_free_data[3]) +
      (M_be[b_aoffset + 3] * (2.0F * p_free_data[2]) + 2.0F * p_free_data[1] *
       M_be[b_aoffset]);
  }

  quatmultiply(rtb_Saturation2, rtb_Gain_0, p_free_data);
  rtb_Gain_0[0] = rtb_Gain[0] - 0.5F * p_free_data[0];
  rtb_Gain_0[1] = rtb_Gain[1] - 0.5F * p_free_data[1];
  rtb_Gain_0[2] = rtb_Gain[2] - 0.5F * p_free_data[2];
  rtb_Gain_0[3] = rtb_Gain[3] - 0.5F * p_free_data[3];
  quatmultiply(rtb_q_bg_dt, rtb_Gain_0, p_free_data);

  // Sum: '<S5>/Add5' incorporates:
  //   DiscreteIntegrator: '<S40>/x'
  //   MATLAB Function: '<S16>/MATLAB Function3'
  //   MATLAB Function: '<S18>/MATLAB Function1'

  rtb_Gain_0[3] = quat_norm;
  rtb_q_red_0[3] = scale;
  for (b_aoffset = 0; b_aoffset < 3; b_aoffset++) {
    rtb_Gain_0[b_aoffset] = tmp[1 + b_aoffset] * 2.0F;
    rtb_q_red_0[b_aoffset] = M_be[b_aoffset + 6] * (2.0F * p_free_data[3]) +
      (M_be[b_aoffset + 3] * (2.0F * p_free_data[2]) + 2.0F * p_free_data[1] *
       M_be[b_aoffset]);
    rtb_Add4_0[b_aoffset] = rtb_Add4[b_aoffset];
  }

  rtb_Add4_0[3] = rtDW.x_DSTATE_fe[2];
  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    // Sum: '<S13>/Add2' incorporates:
    //   Product: '<S13>/MatrixMultiply2'
    //   Sum: '<S5>/Add5'
    //   UnitDelay: '<S13>/Unit Delay1'

    p_free_data[b_aoffset] = (((rtb_G2[b_aoffset + 4] * rtDW.UnitDelay1_DSTATE[1]
      + rtb_G2[b_aoffset] * rtDW.UnitDelay1_DSTATE[0]) + rtb_G2[b_aoffset + 8] *
      rtDW.UnitDelay1_DSTATE[2]) + rtb_G2[b_aoffset + 12] *
      rtDW.UnitDelay1_DSTATE[3]) + ((rtb_Gain_0[b_aoffset] +
      rtb_q_red_0[b_aoffset]) - rtb_Add4_0[b_aoffset]);

    // MATLAB Function: '<S31>/MATLAB Function1' incorporates:
    //   Constant: '<S31>/Constant7'
    //   DiscreteIntegrator: '<S11>/x'

    tmp[b_aoffset] = (real32_T)cntrl.ca.u_d[b_aoffset] - rtDW.x_DSTATE[b_aoffset];
  }

  // MATLAB Function: '<S31>/MATLAB Function' incorporates:
  //   Constant: '<S31>/Constant9'

  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    quat_norm = A_tmp[b_aoffset + 12] * p_free_data[3] + (A_tmp[b_aoffset + 8] *
      p_free_data[2] + (A_tmp[b_aoffset + 4] * p_free_data[1] + A_tmp[b_aoffset]
                        * p_free_data[0]));
    q0_q2 = Constant6[b_aoffset + 12] * tmp[3] + (Constant6[b_aoffset + 8] *
      tmp[2] + (Constant6[b_aoffset + 4] * tmp[1] + Constant6[b_aoffset] * tmp[0]));
    A_tmp_0[b_aoffset] = quat_norm;
    A_tmp_0[b_aoffset + 4] = q0_q2;
  }

  for (b_aoffset = 0; b_aoffset < 8; b_aoffset++) {
    quat_norm = A[b_aoffset + 24] * rtb_q_cmd_n[3] + (A[b_aoffset + 16] *
      rtb_q_cmd_n[2] + (A[b_aoffset + 8] * rtb_q_cmd_n[1] + A[b_aoffset] *
                        rtb_q_cmd_n[0]));
    d_0[b_aoffset] = A_tmp_0[b_aoffset] - quat_norm;
  }

  i_free[0] = ((real32_T)cntrl.ca.W[0] == 0.0F);
  i_free[1] = ((real32_T)cntrl.ca.W[1] == 0.0F);
  i_free[2] = ((real32_T)cntrl.ca.W[2] == 0.0F);
  i_free[3] = ((real32_T)cntrl.ca.W[3] == 0.0F);
  A_tmp_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (A_tmp_tmp <= (int32_T)(real32_T)cntrl.ca.i_max - 1)) {
    j = 0;
    if (i_free[0]) {
      j = 1;
    }

    if (i_free[1]) {
      j++;
    }

    if (i_free[2]) {
      j++;
    }

    if (i_free[3]) {
      j++;
    }

    i = j;
    j = 0;
    if (i_free[0]) {
      f_data[0] = 1;
      j = 1;
    }

    if (i_free[1]) {
      f_data[j] = 2;
      j++;
    }

    if (i_free[2]) {
      f_data[j] = 3;
      j++;
    }

    if (i_free[3]) {
      f_data[j] = 4;
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
    j = 0;
    p_0 = 0.0;
    if (i_free[0]) {
      p_0 = p_free_data[0];
      j = 1;
    }

    rtb_q[0] = rtb_q_cmd_n[0] + (real32_T)p_0;
    p[0] = p_0;
    p_0 = 0.0;
    if (i_free[1]) {
      p_0 = p_free_data[j];
      j++;
    }

    rtb_q[1] = rtb_q_cmd_n[1] + (real32_T)p_0;
    p[1] = p_0;
    p_0 = 0.0;
    if (i_free[2]) {
      p_0 = p_free_data[j];
      j++;
    }

    rtb_q[2] = rtb_q_cmd_n[2] + (real32_T)p_0;
    p[2] = p_0;
    p_0 = 0.0;
    if (i_free[3]) {
      p_0 = p_free_data[j];
    }

    rtb_q[3] = rtb_q_cmd_n[3] + (real32_T)p_0;
    p[3] = p_0;
    j = 0;
    if (i_free[0]) {
      j = 1;
    }

    if (i_free[1]) {
      j++;
    }

    if (i_free[2]) {
      j++;
    }

    if (i_free[3]) {
      j++;
    }

    aoffset = j;
    j = 0;
    if (i_free[0]) {
      g_data[0] = 1;
      j = 1;
    }

    rtb_q_0[0] = ((rtb_q[0] < rtb_q_bg_dt2[0]) || (rtb_q[0] > rtb_q_e_dt2[0]));
    if (i_free[1]) {
      g_data[j] = 2;
      j++;
    }

    rtb_q_0[1] = ((rtb_q[1] < rtb_q_bg_dt2[1]) || (rtb_q[1] > rtb_q_e_dt2[1]));
    if (i_free[2]) {
      g_data[j] = 3;
      j++;
    }

    rtb_q_0[2] = ((rtb_q[2] < rtb_q_bg_dt2[2]) || (rtb_q[2] > rtb_q_e_dt2[2]));
    if (i_free[3]) {
      g_data[j] = 4;
    }

    rtb_q_0[3] = ((rtb_q[3] < q3_q3) || (rtb_q[3] > q0_q1));
    for (b_aoffset = 0; b_aoffset < aoffset; b_aoffset++) {
      rtb_q_data[b_aoffset] = rtb_q_0[g_data[b_aoffset] - 1];
    }

    if (!any(rtb_q_data, &aoffset)) {
      rtb_q_cmd_n[0] = rtb_q[0];
      rtb_q_cmd_n[1] = rtb_q[1];
      rtb_q_cmd_n[2] = rtb_q[2];
      rtb_q_cmd_n[3] = rtb_q[3];
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
        for (j = 0; j < 8; j++) {
          A_tmp_0[j] = 0.0F;
        }

        for (p_free_size = 0; p_free_size < i; p_free_size++) {
          b_aoffset = p_free_size << 3;
          for (aoffset = 0; aoffset < 8; aoffset++) {
            j = b_aoffset + aoffset;
            A_tmp_0[aoffset] += A[((f_data[j / 8] - 1) << 3) + j % 8] *
              p_free_data[p_free_size];
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

        quat_norm = Constant9[i] * p_free_data[i];
        x[i] = (quat_norm >= -2.22044605E-16F);
        rtb_q[i] = quat_norm;
      }

      x_0 = true;
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j < 4)) {
        if (!x[j]) {
          x_0 = false;
          exitg2 = true;
        } else {
          j++;
        }
      }

      if (x_0) {
        exitg1 = true;
      } else {
        quat_norm = rtb_q[0];
        j = 0;
        if (rtb_q[0] > rtb_q[1]) {
          quat_norm = rtb_q[1];
          j = 1;
        }

        if (quat_norm > rtb_q[2]) {
          quat_norm = rtb_q[2];
          j = 2;
        }

        if (quat_norm > rtb_q[3]) {
          j = 3;
        }

        Constant9[j] = 0.0F;
        i_free[j] = true;
        A_tmp_tmp++;
      }
    } else {
      j = 0;
      dist_idx_0 = 1.0;
      x_0 = (p[0] < 0.0);
      e_idx_0 = (p[0] > 0.0);
      if (i_free[0] && x_0) {
        j = 1;
      }

      x[0] = x_0;
      dist_idx_1 = 1.0;
      x_0 = (p[1] < 0.0);
      e_idx_1 = (p[1] > 0.0);
      if (i_free[1] && x_0) {
        j++;
      }

      x[1] = x_0;
      dist_idx_2 = 1.0;
      x_0 = (p[2] < 0.0);
      e_idx_2 = (p[2] > 0.0);
      if (i_free[2] && x_0) {
        j++;
      }

      x[2] = x_0;
      dist_idx_3 = 1.0;
      x_0 = (p_0 < 0.0);
      e_idx_3 = (p_0 > 0.0);
      if (i_free[3] && x_0) {
        j++;
      }

      aoffset = j;
      j = 0;
      if (i_free[0] && x[0]) {
        h_data[0] = 1;
        j = 1;
      }

      if (i_free[1] && x[1]) {
        h_data[j] = 2;
        j++;
      }

      if (i_free[2] && x[2]) {
        h_data[j] = 3;
        j++;
      }

      if (i_free[3] && x_0) {
        h_data[j] = 4;
      }

      for (b_aoffset = 0; b_aoffset < aoffset; b_aoffset++) {
        j = h_data[b_aoffset] - 1;
        c_data[b_aoffset] = (rtb_q_bg_dt2[j] - rtb_q_cmd_n[j]) / (real32_T)p[j];
      }

      j = 0;
      if (i_free[0] && x[0]) {
        dist_idx_0 = c_data[0];
        j = 1;
      }

      if (i_free[1] && x[1]) {
        dist_idx_1 = c_data[j];
        j++;
      }

      if (i_free[2] && x[2]) {
        dist_idx_2 = c_data[j];
        j++;
      }

      if (i_free[3] && x_0) {
        dist_idx_3 = c_data[j];
      }

      j = 0;
      if (i_free[0] && e_idx_0) {
        j = 1;
      }

      if (i_free[1] && e_idx_1) {
        j++;
      }

      if (i_free[2] && e_idx_2) {
        j++;
      }

      if (i_free[3] && e_idx_3) {
        j++;
      }

      aoffset = j;
      j = 0;
      if (i_free[0] && e_idx_0) {
        i_data[0] = 1;
        j = 1;
      }

      if (i_free[1] && e_idx_1) {
        i_data[j] = 2;
        j++;
      }

      if (i_free[2] && e_idx_2) {
        i_data[j] = 3;
        j++;
      }

      if (i_free[3] && e_idx_3) {
        i_data[j] = 4;
      }

      for (b_aoffset = 0; b_aoffset < aoffset; b_aoffset++) {
        j = i_data[b_aoffset] - 1;
        c_data[b_aoffset] = (rtb_q_e_dt2[j] - rtb_q_cmd_n[j]) / (real32_T)p[j];
      }

      j = 0;
      if (i_free[0] && e_idx_0) {
        dist_idx_0 = c_data[0];
        j = 1;
      }

      if (i_free[1] && e_idx_1) {
        dist_idx_1 = c_data[j];
        j++;
      }

      if (i_free[2] && e_idx_2) {
        dist_idx_2 = c_data[j];
        j++;
      }

      if (i_free[3] && e_idx_3) {
        dist_idx_3 = c_data[j];
      }

      j = 0;
      if (dist_idx_0 > dist_idx_1) {
        dist_idx_0 = dist_idx_1;
        j = 1;
      }

      if (dist_idx_0 > dist_idx_2) {
        dist_idx_0 = dist_idx_2;
        j = 2;
      }

      if (dist_idx_0 > dist_idx_3) {
        dist_idx_0 = dist_idx_3;
        j = 3;
      }

      rtb_q_cmd_n[0] += (real32_T)(dist_idx_0 * p[0]);
      rtb_q_cmd_n[1] += (real32_T)(dist_idx_0 * p[1]);
      rtb_q_cmd_n[2] += (real32_T)(dist_idx_0 * p[2]);
      rtb_q_cmd_n[3] += (real32_T)(dist_idx_0 * p_0);
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

      if (p[j] < 0.0) {
        Constant9[j] = -1.0F;
      } else if (p[j] > 0.0) {
        Constant9[j] = 1.0F;
      } else {
        Constant9[j] = (real32_T)p[j];
      }

      i_free[j] = false;
      A_tmp_tmp++;
    }
  }

  // Sum: '<S5>/Add6' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  quat_norm = rtb_q_cmd_n[0] + rtDW.x_DSTATE[0];

  // Saturate: '<S5>/Saturation3'
  if (quat_norm > 1.0F) {
    quat_norm = 1.0F;
  } else {
    if (quat_norm < 0.0F) {
      quat_norm = 0.0F;
    }
  }

  // DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
  rtb_q[0] = rtDW.DiscreteTimeIntegrator_DSTATE_n[0];

  // Sum: '<S10>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S10>/Discrete-Time Integrator'

  rtb_q_bg_dt[0] = quat_norm - rtDW.DiscreteTimeIntegrator_DSTATE_n[0];

  // Saturate: '<S5>/Saturation2'
  if (quat_norm < 0.1F) {
    quat_norm = 0.1F;
  }

  // Saturate: '<S5>/Saturation3'
  rtb_Saturation2[0] = quat_norm;

  // Sum: '<S5>/Add6' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  quat_norm = rtb_q_cmd_n[1] + rtDW.x_DSTATE[1];

  // Saturate: '<S5>/Saturation3'
  if (quat_norm > 1.0F) {
    quat_norm = 1.0F;
  } else {
    if (quat_norm < 0.0F) {
      quat_norm = 0.0F;
    }
  }

  // DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
  rtb_q[1] = rtDW.DiscreteTimeIntegrator_DSTATE_n[1];

  // Sum: '<S10>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S10>/Discrete-Time Integrator'

  rtb_q_bg_dt[1] = quat_norm - rtDW.DiscreteTimeIntegrator_DSTATE_n[1];

  // Saturate: '<S5>/Saturation2'
  if (quat_norm < 0.1F) {
    quat_norm = 0.1F;
  }

  // Saturate: '<S5>/Saturation3'
  rtb_Saturation2[1] = quat_norm;

  // Sum: '<S5>/Add6' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  quat_norm = rtb_q_cmd_n[2] + rtDW.x_DSTATE[2];

  // Saturate: '<S5>/Saturation3'
  if (quat_norm > 1.0F) {
    quat_norm = 1.0F;
  } else {
    if (quat_norm < 0.0F) {
      quat_norm = 0.0F;
    }
  }

  // DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
  rtb_q[2] = rtDW.DiscreteTimeIntegrator_DSTATE_n[2];

  // Sum: '<S10>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S10>/Discrete-Time Integrator'

  rtb_q_bg_dt[2] = quat_norm - rtDW.DiscreteTimeIntegrator_DSTATE_n[2];

  // Saturate: '<S5>/Saturation2'
  if (quat_norm < 0.1F) {
    quat_norm = 0.1F;
  }

  // Saturate: '<S5>/Saturation3'
  rtb_Saturation2[2] = quat_norm;

  // Sum: '<S5>/Add6' incorporates:
  //   DiscreteIntegrator: '<S11>/x'

  quat_norm = rtb_q_cmd_n[3] + rtDW.x_DSTATE[3];

  // Saturate: '<S5>/Saturation3'
  if (quat_norm > 1.0F) {
    quat_norm = 1.0F;
  } else {
    if (quat_norm < 0.0F) {
      quat_norm = 0.0F;
    }
  }

  // DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
  rtb_q[3] = rtDW.DiscreteTimeIntegrator_DSTATE_n[3];

  // Sum: '<S10>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S10>/Discrete-Time Integrator'

  rtb_q_bg_dt[3] = quat_norm - rtDW.DiscreteTimeIntegrator_DSTATE_n[3];

  // Saturate: '<S5>/Saturation2'
  if (quat_norm < 0.1F) {
    quat_norm = 0.1F;
  }

  // Outport: '<Root>/u'
  rtY.u[0] = rtb_Saturation2[1];
  rtY.u[1] = quat_norm;
  rtY.u[2] = rtb_Saturation2[0];
  rtY.u[3] = rtb_Saturation2[2];

  // SampleTimeMath: '<S2>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q3_q3 = rtU.measure.V_Kg[0] * 400.0F;

  // SampleTimeMath: '<S3>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q0_q1 = rtU.measure.s_Kg[0] * 400.0F;

  // SampleTimeMath: '<S4>/TSamp' incorporates:
  //   Sum: '<S3>/Diff'
  //   UnitDelay: '<S3>/UD'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  //  Block description for '<S3>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  q0_q2 = (q0_q1 - rtDW.UD_DSTATE_n[0]) * 400.0F;

  // Outport: '<Root>/u' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'
  //   Sum: '<S2>/Diff'
  //   Sum: '<S4>/Diff'
  //   UnitDelay: '<S2>/UD'
  //   UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S2>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S4>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  rtY.u[4] = rtU.measure.a_Kg[0];
  rtY.u[7] = q3_q3 - rtDW.UD_DSTATE_o[0];
  rtY.u[10] = q0_q2 - rtDW.UD_DSTATE_m[0];
  rtY.u[13] = rtDW.DiscreteTimeIntegrator2_DSTATE[0];
  rtY.u[16] = rtDW.DiscreteTimeIntegrator1_DSTATE[0];
  rtY.u[19] = rtU.measure.s_Kg[0];

  // SampleTimeMath: '<S2>/TSamp'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q1_q3 = q3_q3;

  // SampleTimeMath: '<S3>/TSamp'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q2_q3 = q0_q1;

  // SampleTimeMath: '<S4>/TSamp'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q0_q3 = q0_q2;

  // SampleTimeMath: '<S2>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q3_q3 = rtU.measure.V_Kg[1] * 400.0F;

  // SampleTimeMath: '<S3>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q0_q1 = rtU.measure.s_Kg[1] * 400.0F;

  // SampleTimeMath: '<S4>/TSamp' incorporates:
  //   Sum: '<S3>/Diff'
  //   UnitDelay: '<S3>/UD'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  //  Block description for '<S3>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  q0_q2 = (q0_q1 - rtDW.UD_DSTATE_n[1]) * 400.0F;

  // Outport: '<Root>/u' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'
  //   Sum: '<S2>/Diff'
  //   Sum: '<S4>/Diff'
  //   UnitDelay: '<S2>/UD'
  //   UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S2>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S4>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  rtY.u[5] = rtU.measure.a_Kg[1];
  rtY.u[8] = q3_q3 - rtDW.UD_DSTATE_o[1];
  rtY.u[11] = q0_q2 - rtDW.UD_DSTATE_m[1];
  rtY.u[14] = rtDW.DiscreteTimeIntegrator2_DSTATE[1];
  rtY.u[17] = rtDW.DiscreteTimeIntegrator1_DSTATE[1];
  rtY.u[20] = rtU.measure.s_Kg[1];

  // SampleTimeMath: '<S2>/TSamp'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q1_q2 = q3_q3;

  // SampleTimeMath: '<S3>/TSamp'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp_i_idx_1 = q0_q1;

  // SampleTimeMath: '<S4>/TSamp'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp_l_idx_1 = q0_q2;

  // SampleTimeMath: '<S2>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q3_q3 = rtU.measure.V_Kg[2] * 400.0F;

  // SampleTimeMath: '<S3>/TSamp' incorporates:
  //   Inport: '<Root>/measure'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q0_q1 = rtU.measure.s_Kg[2] * 400.0F;

  // SampleTimeMath: '<S4>/TSamp' incorporates:
  //   Sum: '<S3>/Diff'
  //   UnitDelay: '<S3>/UD'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  //  Block description for '<S3>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  q0_q2 = (q0_q1 - rtDW.UD_DSTATE_n[2]) * 400.0F;

  // Outport: '<Root>/u' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'
  //   Sum: '<S2>/Diff'
  //   Sum: '<S4>/Diff'
  //   UnitDelay: '<S2>/UD'
  //   UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S2>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S4>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  rtY.u[6] = rtU.measure.a_Kg[2] + 9.82F;
  rtY.u[9] = q3_q3 - rtDW.UD_DSTATE_o[2];
  rtY.u[12] = q0_q2 - rtDW.UD_DSTATE_m[2];
  rtY.u[15] = rtDW.DiscreteTimeIntegrator2_DSTATE[2];
  rtY.u[18] = rtDW.DiscreteTimeIntegrator1_DSTATE[2];
  rtY.u[21] = rtU.measure.s_Kg[2];
  rtY.u[22] = 0.0F;

  // MATLAB Function: '<S21>/MATLAB Function6' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator6'
  //   Gain: '<S21>/r_max'
  //   Inport: '<Root>/cmd'

  omega_Kb_idx_2 = 2.09439516F * rtU.cmd.yaw;
  scale = 1.29246971E-26F;
  absxk = std::abs(rtDW.DiscreteTimeIntegrator6_DSTATE[0]);
  if (absxk > 1.29246971E-26F) {
    quat_norm = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    quat_norm = t * t;
  }

  absxk = std::abs(rtDW.DiscreteTimeIntegrator6_DSTATE[1]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(rtDW.DiscreteTimeIntegrator6_DSTATE[2]);
  if (absxk > scale) {
    t = scale / absxk;
    quat_norm = quat_norm * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    quat_norm += t * t;
  }

  absxk = std::abs(rtDW.DiscreteTimeIntegrator6_DSTATE[3]);
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

  rtb_Saturation2[0] = rtDW.DiscreteTimeIntegrator6_DSTATE[0] / quat_norm;
  rtb_Saturation2[1] = rtDW.DiscreteTimeIntegrator6_DSTATE[1] / quat_norm;
  rtb_Saturation2[2] = rtDW.DiscreteTimeIntegrator6_DSTATE[2] / quat_norm;
  rtb_Saturation2[3] = rtDW.DiscreteTimeIntegrator6_DSTATE[3] / quat_norm;

  // Sum: '<S11>/Sum2' incorporates:
  //   Delay: '<S5>/Delay'
  //   DiscreteIntegrator: '<S11>/x'
  //   DiscreteIntegrator: '<S11>/x_dt'
  //   Gain: '<S11>/2*d//omega'
  //   Sum: '<S11>/Sum3'

  rtb_q_bg_dt2[0] = rtDW.Delay_DSTATE[0] - (0.02F * rtDW.x_dt_DSTATE_i[0] +
    rtDW.x_DSTATE[0]);
  rtb_q_bg_dt2[1] = rtDW.Delay_DSTATE[1] - (0.02F * rtDW.x_dt_DSTATE_i[1] +
    rtDW.x_DSTATE[1]);
  rtb_q_bg_dt2[2] = rtDW.Delay_DSTATE[2] - (0.02F * rtDW.x_dt_DSTATE_i[2] +
    rtDW.x_DSTATE[2]);

  // MATLAB Function: '<S21>/MATLAB Function6' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator6'

  quat_norm = ((rtDW.DiscreteTimeIntegrator6_DSTATE[0] *
                rtDW.DiscreteTimeIntegrator6_DSTATE[0] +
                rtDW.DiscreteTimeIntegrator6_DSTATE[1] *
                rtDW.DiscreteTimeIntegrator6_DSTATE[1]) +
               rtDW.DiscreteTimeIntegrator6_DSTATE[2] *
               rtDW.DiscreteTimeIntegrator6_DSTATE[2]) +
    rtDW.DiscreteTimeIntegrator6_DSTATE[3] *
    rtDW.DiscreteTimeIntegrator6_DSTATE[3];

  // Sum: '<S11>/Sum2' incorporates:
  //   Delay: '<S5>/Delay'
  //   DiscreteIntegrator: '<S11>/x'
  //   DiscreteIntegrator: '<S11>/x_dt'
  //   Gain: '<S11>/2*d//omega'
  //   Sum: '<S11>/Sum3'

  rtb_q_bg_dt2[3] = rtDW.Delay_DSTATE[3] - (0.02F * rtDW.x_dt_DSTATE_i[3] +
    rtDW.x_DSTATE[3]);

  // Sum: '<S40>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S40>/x'
  //   DiscreteIntegrator: '<S40>/x_dt'
  //   Gain: '<S40>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'
  //   Sum: '<S40>/Sum3'

  scale = rtU.measure.a_Kg[0] - (0.02F * rtDW.x_dt_DSTATE_i0[0] +
    rtDW.x_DSTATE_fe[0]);

  // Gain: '<S37>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S37>/x'
  //   DiscreteIntegrator: '<S37>/x_dt'
  //   Gain: '<S37>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S37>/Sum2'
  //   Sum: '<S37>/Sum3'

  absxk = (rtU.measure.omega_Kb[0] - (0.02F * rtDW.x_dt_DSTATE_e[0] +
            rtDW.x_DSTATE_gw[0])) * 10000.0F;

  // Gain: '<S39>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S39>/x'
  //   DiscreteIntegrator: '<S39>/x_dt'
  //   Gain: '<S39>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S39>/Sum2'
  //   Sum: '<S39>/Sum3'

  t = (rtU.measure.V_Kg[0] - (0.02F * rtDW.x_dt_DSTATE_j[0] + rtDW.x_DSTATE_l[0]))
    * 10000.0F;

  // Sum: '<S38>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S38>/x'
  //   DiscreteIntegrator: '<S38>/x_dt'
  //   Gain: '<S38>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S38>/Sum3'

  rtb_Sum2_k_idx_0 = rtU.measure.s_Kg[0] - (0.02F * rtDW.x_dt_DSTATE_f[0] +
    rtDW.x_DSTATE_c[0]);

  // Sum: '<S40>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S40>/x'
  //   DiscreteIntegrator: '<S40>/x_dt'
  //   Gain: '<S40>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'
  //   Sum: '<S40>/Sum3'

  rtb_Sum2_p_idx_1 = rtU.measure.a_Kg[1] - (0.02F * rtDW.x_dt_DSTATE_i0[1] +
    rtDW.x_DSTATE_fe[1]);

  // Gain: '<S37>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S37>/x'
  //   DiscreteIntegrator: '<S37>/x_dt'
  //   Gain: '<S37>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S37>/Sum2'
  //   Sum: '<S37>/Sum3'

  rtb_omega2_n_idx_1 = (rtU.measure.omega_Kb[1] - (0.02F * rtDW.x_dt_DSTATE_e[1]
    + rtDW.x_DSTATE_gw[1])) * 10000.0F;

  // Gain: '<S39>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S39>/x'
  //   DiscreteIntegrator: '<S39>/x_dt'
  //   Gain: '<S39>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S39>/Sum2'
  //   Sum: '<S39>/Sum3'

  rtb_omega2_g_idx_1 = (rtU.measure.V_Kg[1] - (0.02F * rtDW.x_dt_DSTATE_j[1] +
    rtDW.x_DSTATE_l[1])) * 10000.0F;

  // Sum: '<S38>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S38>/x'
  //   DiscreteIntegrator: '<S38>/x_dt'
  //   Gain: '<S38>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S38>/Sum3'

  rtb_Sum2_k_idx_1 = rtU.measure.s_Kg[1] - (0.02F * rtDW.x_dt_DSTATE_f[1] +
    rtDW.x_DSTATE_c[1]);

  // Sum: '<S40>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S40>/x'
  //   DiscreteIntegrator: '<S40>/x_dt'
  //   Gain: '<S40>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'
  //   Sum: '<S40>/Sum3'

  rtb_Sum2_p_idx_2 = (rtU.measure.a_Kg[2] + 9.82F) - (0.02F *
    rtDW.x_dt_DSTATE_i0[2] + rtDW.x_DSTATE_fe[2]);

  // Gain: '<S37>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S37>/x'
  //   DiscreteIntegrator: '<S37>/x_dt'
  //   Gain: '<S37>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S37>/Sum2'
  //   Sum: '<S37>/Sum3'

  rtb_omega2_n_idx_2 = (rtU.measure.omega_Kb[2] - (0.02F * rtDW.x_dt_DSTATE_e[2]
    + rtDW.x_DSTATE_gw[2])) * 10000.0F;

  // Gain: '<S39>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S39>/x'
  //   DiscreteIntegrator: '<S39>/x_dt'
  //   Gain: '<S39>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S39>/Sum2'
  //   Sum: '<S39>/Sum3'

  rtb_omega2_g_idx_2 = (rtU.measure.V_Kg[2] - (0.02F * rtDW.x_dt_DSTATE_j[2] +
    rtDW.x_DSTATE_l[2])) * 10000.0F;

  // Sum: '<S38>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S38>/x'
  //   DiscreteIntegrator: '<S38>/x_dt'
  //   Gain: '<S38>/2*d//omega'
  //   Inport: '<Root>/measure'
  //   Sum: '<S38>/Sum3'

  rtb_Sum2_k_idx_2 = rtU.measure.s_Kg[2] - (0.02F * rtDW.x_dt_DSTATE_f[2] +
    rtDW.x_DSTATE_c[2]);

  // Update for DiscreteIntegrator: '<S11>/x' incorporates:
  //   DiscreteIntegrator: '<S11>/x_dt'

  rtDW.x_DSTATE[0] += 0.0025F * rtDW.x_dt_DSTATE_i[0];

  // Update for DiscreteIntegrator: '<S56>/x' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtDW.x_DSTATE_f[0] += 0.0025F * rtDW.x_dt_DSTATE[0];

  // Update for DiscreteIntegrator: '<S56>/x_dt'
  rtDW.x_dt_DSTATE[0] += 0.0025F * rtb_TSamp_f_idx_2;

  // Update for DiscreteIntegrator: '<S11>/x' incorporates:
  //   DiscreteIntegrator: '<S11>/x_dt'

  rtDW.x_DSTATE[1] += 0.0025F * rtDW.x_dt_DSTATE_i[1];

  // Update for DiscreteIntegrator: '<S56>/x' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtDW.x_DSTATE_f[1] += 0.0025F * rtDW.x_dt_DSTATE[1];

  // Update for DiscreteIntegrator: '<S56>/x_dt'
  rtDW.x_dt_DSTATE[1] += 0.0025F * rtb_q_red_idx_1;

  // Update for DiscreteIntegrator: '<S11>/x' incorporates:
  //   DiscreteIntegrator: '<S11>/x_dt'

  rtDW.x_DSTATE[2] += 0.0025F * rtDW.x_dt_DSTATE_i[2];

  // Update for DiscreteIntegrator: '<S56>/x' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtDW.x_DSTATE_f[2] += 0.0025F * rtDW.x_dt_DSTATE[2];

  // Update for DiscreteIntegrator: '<S56>/x_dt'
  rtDW.x_dt_DSTATE[2] += 0.0025F * rtb_q_red_idx_2;

  // Update for DiscreteIntegrator: '<S11>/x' incorporates:
  //   DiscreteIntegrator: '<S11>/x_dt'

  rtDW.x_DSTATE[3] += 0.0025F * rtDW.x_dt_DSTATE_i[3];

  // Update for DiscreteIntegrator: '<S56>/x' incorporates:
  //   DiscreteIntegrator: '<S56>/x_dt'

  rtDW.x_DSTATE_f[3] += 0.0025F * rtDW.x_dt_DSTATE[3];

  // Update for DiscreteIntegrator: '<S56>/x_dt'
  rtDW.x_dt_DSTATE[3] += 0.0025F * rtb_q_red_idx_3;

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator6'
  rtDW.DiscreteTimeIntegrator6_IC_LOAD = 0U;

  // MATLAB Function: '<S21>/MATLAB Function6'
  tmp_4[0] = 0.0F;
  tmp_4[4] = -0.0F;
  tmp_4[1] = 0.0F;
  tmp_4[8] = -0.0F;
  tmp_4[2] = 0.0F;
  rtb_TSamp_f_idx_2 = 0.5F * -omega_Kb_idx_2;
  tmp_4[12] = rtb_TSamp_f_idx_2;
  tmp_4[3] = 0.5F * omega_Kb_idx_2;
  tmp_4[5] = 0.0F;
  tmp_4[9] = 0.5F * omega_Kb_idx_2;
  tmp_4[13] = 0.0F;
  tmp_4[6] = rtb_TSamp_f_idx_2;
  tmp_4[10] = 0.0F;
  tmp_4[14] = 0.0F;
  tmp_4[7] = 0.0F;
  tmp_4[11] = 0.0F;
  tmp_4[15] = 0.0F;
  for (b_aoffset = 0; b_aoffset < 4; b_aoffset++) {
    // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator6'
    rtDW.DiscreteTimeIntegrator6_DSTATE[b_aoffset] += ((((tmp_4[b_aoffset + 4] *
      rtb_Saturation2[1] + tmp_4[b_aoffset] * rtb_Saturation2[0]) +
      tmp_4[b_aoffset + 8] * rtb_Saturation2[2]) + tmp_4[b_aoffset + 12] *
      rtb_Saturation2[3]) + (1.0F - quat_norm) * rtb_Saturation2[b_aoffset]) *
      0.0025F;
  }

  // Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_IC_LOADI = 0U;

  // Update for DiscreteIntegrator: '<S29>/x' incorporates:
  //   Saturate: '<S29>/Saturation'

  rtDW.x_DSTATE_g[0] += 0.0025F * y;

  // Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.0025F * rtb_x_ref_b_idx_0;

  // Update for DiscreteIntegrator: '<S29>/x' incorporates:
  //   Saturate: '<S29>/Saturation'

  rtDW.x_DSTATE_g[1] += 0.0025F * y_0;

  // Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 0.0025F * rtb_x_ref_b_idx_1;

  // Update for DiscreteIntegrator: '<S38>/x' incorporates:
  //   DiscreteIntegrator: '<S38>/x_dt'

  rtDW.x_DSTATE_c[0] += 0.0025F * rtDW.x_dt_DSTATE_f[0];

  // Update for DiscreteIntegrator: '<S39>/x' incorporates:
  //   DiscreteIntegrator: '<S39>/x_dt'

  rtDW.x_DSTATE_l[0] += 0.0025F * rtDW.x_dt_DSTATE_j[0];

  // Update for DiscreteIntegrator: '<S40>/x' incorporates:
  //   DiscreteIntegrator: '<S40>/x_dt'

  rtDW.x_DSTATE_fe[0] += 0.0025F * rtDW.x_dt_DSTATE_i0[0];

  // Update for DiscreteIntegrator: '<S38>/x' incorporates:
  //   DiscreteIntegrator: '<S38>/x_dt'

  rtDW.x_DSTATE_c[1] += 0.0025F * rtDW.x_dt_DSTATE_f[1];

  // Update for DiscreteIntegrator: '<S39>/x' incorporates:
  //   DiscreteIntegrator: '<S39>/x_dt'

  rtDW.x_DSTATE_l[1] += 0.0025F * rtDW.x_dt_DSTATE_j[1];

  // Update for DiscreteIntegrator: '<S40>/x' incorporates:
  //   DiscreteIntegrator: '<S40>/x_dt'

  rtDW.x_DSTATE_fe[1] += 0.0025F * rtDW.x_dt_DSTATE_i0[1];

  // Update for DiscreteIntegrator: '<S38>/x' incorporates:
  //   DiscreteIntegrator: '<S38>/x_dt'

  rtDW.x_DSTATE_c[2] += 0.0025F * rtDW.x_dt_DSTATE_f[2];

  // Update for DiscreteIntegrator: '<S39>/x' incorporates:
  //   DiscreteIntegrator: '<S39>/x_dt'

  rtDW.x_DSTATE_l[2] += 0.0025F * rtDW.x_dt_DSTATE_j[2];

  // Update for DiscreteIntegrator: '<S40>/x' incorporates:
  //   DiscreteIntegrator: '<S40>/x_dt'

  rtDW.x_DSTATE_fe[2] += 0.0025F * rtDW.x_dt_DSTATE_i0[2];

  // Update for DiscreteIntegrator: '<S55>/x'
  rtDW.x_DSTATE_h += 0.0025F * cos_Phi_2;

  // Update for UnitDelay: '<S34>/Unit Delay'
  rtDW.UnitDelay_DSTATE[0] = rtb_ch2rpyt[0];
  rtDW.UnitDelay_DSTATE[1] = rtb_ch2rpyt[1];
  rtDW.UnitDelay_DSTATE[2] = rtb_ch2rpyt[2];
  rtDW.UnitDelay_DSTATE[3] = rtb_ch2rpyt[3];

  // Update for DiscreteIntegrator: '<S37>/x' incorporates:
  //   DiscreteIntegrator: '<S37>/x_dt'

  rtDW.x_DSTATE_gw[0] += 0.0025F * rtDW.x_dt_DSTATE_e[0];

  // Update for UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[0] = rtb_DiscreteTimeIntegrator1[0];

  // Update for DiscreteIntegrator: '<S37>/x' incorporates:
  //   DiscreteIntegrator: '<S37>/x_dt'

  rtDW.x_DSTATE_gw[1] += 0.0025F * rtDW.x_dt_DSTATE_e[1];

  // Update for UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[1] = rtb_DiscreteTimeIntegrator1[1];

  // Update for DiscreteIntegrator: '<S37>/x' incorporates:
  //   DiscreteIntegrator: '<S37>/x_dt'

  rtDW.x_DSTATE_gw[2] += 0.0025F * rtDW.x_dt_DSTATE_e[2];

  // Update for UnitDelay: '<S35>/UD'
  //
  //  Block description for '<S35>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[2] = u_tmp;

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator3'
  rtDW.DiscreteTimeIntegrator3_IC_LOAD = 0U;
  rtDW.DiscreteTimeIntegrator3_DSTATE += 0.0025F * sin_Phi_2;
  for (b_aoffset = 0; b_aoffset < 9; b_aoffset++) {
    // Update for DiscreteIntegrator: '<S36>/x' incorporates:
    //   DiscreteIntegrator: '<S36>/x_dt'

    rtDW.x_DSTATE_c5[b_aoffset] += 0.0025F * rtDW.x_dt_DSTATE_a[b_aoffset];

    // Update for DiscreteIntegrator: '<S36>/x_dt' incorporates:
    //   Gain: '<S36>/omega^2'

    rtDW.x_dt_DSTATE_a[b_aoffset] += 10000.0F * rtb_M_bg[b_aoffset] * 0.0025F;
  }

  // Update for UnitDelay: '<S13>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[0] = rtb_q_cmd_n[0];

  // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S10>/1//T'

  rtDW.DiscreteTimeIntegrator_DSTATE_n[0] += 74.0740738F * rtb_q_bg_dt[0] *
    0.0025F;

  // Update for UnitDelay: '<S13>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[1] = rtb_q_cmd_n[1];

  // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S10>/1//T'

  rtDW.DiscreteTimeIntegrator_DSTATE_n[1] += 74.0740738F * rtb_q_bg_dt[1] *
    0.0025F;

  // Update for UnitDelay: '<S13>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[2] = rtb_q_cmd_n[2];

  // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S10>/1//T'

  rtDW.DiscreteTimeIntegrator_DSTATE_n[2] += 74.0740738F * rtb_q_bg_dt[2] *
    0.0025F;

  // Update for UnitDelay: '<S13>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE[3] = rtb_q_cmd_n[3];

  // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S10>/1//T'

  rtDW.DiscreteTimeIntegrator_DSTATE_n[3] += 74.0740738F * rtb_q_bg_dt[3] *
    0.0025F;

  // Update for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_o[0] = q1_q3;

  // Update for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_n[0] = q2_q3;

  // Update for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_m[0] = q0_q3;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator2_DSTATE[0] += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_f[0];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Inport: '<Root>/measure'

  rtDW.DiscreteTimeIntegrator1_DSTATE[0] += 0.0025F * rtU.measure.V_Kg[0];

  // Update for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_o[1] = q1_q2;

  // Update for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_n[1] = rtb_TSamp_i_idx_1;

  // Update for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_m[1] = rtb_TSamp_l_idx_1;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator2_DSTATE[1] += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_f[1];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Inport: '<Root>/measure'

  rtDW.DiscreteTimeIntegrator1_DSTATE[1] += 0.0025F * rtU.measure.V_Kg[1];

  // Update for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_o[2] = q3_q3;

  // Update for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_n[2] = q0_q1;

  // Update for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE_m[2] = q0_q2;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator2_DSTATE[2] += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_f[2];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Inport: '<Root>/measure'

  rtDW.DiscreteTimeIntegrator1_DSTATE[2] += 0.0025F * rtU.measure.V_Kg[2];

  // Update for DiscreteIntegrator: '<S11>/x_dt' incorporates:
  //   Gain: '<S11>/omega^2'

  rtDW.x_dt_DSTATE_i[0] += 10000.0F * rtb_q_bg_dt2[0] * 0.0025F;

  // Update for Delay: '<S5>/Delay'
  rtDW.Delay_DSTATE[0] = rtb_q[0];

  // Update for DiscreteIntegrator: '<S11>/x_dt' incorporates:
  //   Gain: '<S11>/omega^2'

  rtDW.x_dt_DSTATE_i[1] += 10000.0F * rtb_q_bg_dt2[1] * 0.0025F;

  // Update for Delay: '<S5>/Delay'
  rtDW.Delay_DSTATE[1] = rtb_q[1];

  // Update for DiscreteIntegrator: '<S11>/x_dt' incorporates:
  //   Gain: '<S11>/omega^2'

  rtDW.x_dt_DSTATE_i[2] += 10000.0F * rtb_q_bg_dt2[2] * 0.0025F;

  // Update for Delay: '<S5>/Delay'
  rtDW.Delay_DSTATE[2] = rtb_q[2];

  // Update for DiscreteIntegrator: '<S11>/x_dt' incorporates:
  //   Gain: '<S11>/omega^2'

  rtDW.x_dt_DSTATE_i[3] += 10000.0F * rtb_q_bg_dt2[3] * 0.0025F;

  // Update for Delay: '<S5>/Delay'
  rtDW.Delay_DSTATE[3] = rtb_q[3];

  // Update for DiscreteIntegrator: '<S40>/x_dt' incorporates:
  //   Gain: '<S40>/omega^2'

  rtDW.x_dt_DSTATE_i0[0] += 10000.0F * scale * 0.0025F;

  // Update for DiscreteIntegrator: '<S37>/x_dt'
  rtDW.x_dt_DSTATE_e[0] += 0.0025F * absxk;

  // Update for DiscreteIntegrator: '<S39>/x_dt'
  rtDW.x_dt_DSTATE_j[0] += 0.0025F * t;

  // Update for DiscreteIntegrator: '<S38>/x_dt' incorporates:
  //   Gain: '<S38>/omega^2'

  rtDW.x_dt_DSTATE_f[0] += 10000.0F * rtb_Sum2_k_idx_0 * 0.0025F;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'

  rtDW.DiscreteTimeIntegrator_DSTATE_f[0] += 0.0025F * rtU.measure.a_Kg[0];

  // Update for DiscreteIntegrator: '<S40>/x_dt' incorporates:
  //   Gain: '<S40>/omega^2'

  rtDW.x_dt_DSTATE_i0[1] += 10000.0F * rtb_Sum2_p_idx_1 * 0.0025F;

  // Update for DiscreteIntegrator: '<S37>/x_dt'
  rtDW.x_dt_DSTATE_e[1] += 0.0025F * rtb_omega2_n_idx_1;

  // Update for DiscreteIntegrator: '<S39>/x_dt'
  rtDW.x_dt_DSTATE_j[1] += 0.0025F * rtb_omega2_g_idx_1;

  // Update for DiscreteIntegrator: '<S38>/x_dt' incorporates:
  //   Gain: '<S38>/omega^2'

  rtDW.x_dt_DSTATE_f[1] += 10000.0F * rtb_Sum2_k_idx_1 * 0.0025F;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'

  rtDW.DiscreteTimeIntegrator_DSTATE_f[1] += 0.0025F * rtU.measure.a_Kg[1];

  // Update for DiscreteIntegrator: '<S40>/x_dt' incorporates:
  //   Gain: '<S40>/omega^2'

  rtDW.x_dt_DSTATE_i0[2] += 10000.0F * rtb_Sum2_p_idx_2 * 0.0025F;

  // Update for DiscreteIntegrator: '<S37>/x_dt'
  rtDW.x_dt_DSTATE_e[2] += 0.0025F * rtb_omega2_n_idx_2;

  // Update for DiscreteIntegrator: '<S39>/x_dt'
  rtDW.x_dt_DSTATE_j[2] += 0.0025F * rtb_omega2_g_idx_2;

  // Update for DiscreteIntegrator: '<S38>/x_dt' incorporates:
  //   Gain: '<S38>/omega^2'

  rtDW.x_dt_DSTATE_f[2] += 10000.0F * rtb_Sum2_k_idx_2 * 0.0025F;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/measure'
  //   Sum: '<Root>/Add'

  rtDW.DiscreteTimeIntegrator_DSTATE_f[2] += (rtU.measure.a_Kg[2] + 9.82F) *
    0.0025F;
}

// Model initialize function
void MatlabControllerClass::initialize()
{
  {
    int32_T i;

    // InitializeConditions for DiscreteIntegrator: '<S56>/x'
    rtDW.x_DSTATE_f[0] = 1.0F;
    rtDW.x_DSTATE_f[1] = 0.0F;
    rtDW.x_DSTATE_f[2] = 0.0F;
    rtDW.x_DSTATE_f[3] = 0.0F;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator6' 
    rtDW.DiscreteTimeIntegrator6_IC_LOAD = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' 
    rtDW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S36>/x'
    for (i = 0; i < 9; i++) {
      rtDW.x_DSTATE_c5[i] = rtConstP.x_IC_o[i];
    }

    // End of InitializeConditions for DiscreteIntegrator: '<S36>/x'

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator3' 
    rtDW.DiscreteTimeIntegrator3_IC_LOAD = 1U;
  }
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
