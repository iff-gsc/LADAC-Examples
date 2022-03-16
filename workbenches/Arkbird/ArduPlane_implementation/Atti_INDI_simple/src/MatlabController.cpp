//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: MatlabController.cpp
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

extern real32_T rt_hypotf(real32_T u0, real32_T u1);
static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
static uint32_T plook_u32f_binckan(real32_T u, const real32_T bp[], uint32_T
  maxIndex);
static uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
static void wrapangle(real32_T rtu_angle, real32_T *rty_angle_0_2pi);
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

static uint32_T plook_u32f_binckan(real32_T u, const real32_T bp[], uint32_T
  maxIndex)
{
  uint32_T bpIndex;

  // Prelookup - Index only
  // Index Search method: 'binary'
  // Interpolation method: 'Use nearest'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

static uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  // Binary Search
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

//
// Output and update for atomic system:
//    '<S13>/wrap angle'
//    '<S14>/wrap angle'
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

// Function for MATLAB Function: '<S11>/MATLAB Function'
void MatlabControllerClass::LSQFromQR(const real32_T A_data[], const int32_T
  A_size[2], const real32_T tau_data[], const int32_T jpvt_data[], real32_T B_3
  [7], int32_T rankA, real32_T Y_data[], int32_T *Y_size)
{
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
      for (loop_ub = b_j + 1; loop_ub + 1 < 8; loop_ub++) {
        wj += A_data[7 * b_j + loop_ub] * B_3[loop_ub];
      }

      wj *= tau_data[b_j];
      if (wj != 0.0F) {
        B_3[b_j] -= wj;
        for (loop_ub = b_j + 1; loop_ub + 1 < 8; loop_ub++) {
          B_3[loop_ub] -= A_data[7 * b_j + loop_ub] * wj;
        }
      }
    }
  }

  for (loop_ub = 0; loop_ub < rankA; loop_ub++) {
    Y_data[jpvt_data[loop_ub] - 1] = B_3[loop_ub];
  }

  for (loop_ub = rankA - 1; loop_ub + 1 > 0; loop_ub--) {
    Y_data[jpvt_data[loop_ub] - 1] /= A_data[7 * loop_ub + loop_ub];
    for (b_j = 0; b_j < loop_ub; b_j++) {
      Y_data[jpvt_data[b_j] - 1] -= A_data[7 * loop_ub + b_j] *
        Y_data[jpvt_data[loop_ub] - 1];
    }
  }
}

// Function for MATLAB Function: '<S11>/MATLAB Function'
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

// Function for MATLAB Function: '<S11>/MATLAB Function'
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
      coltop = lastc * 7 + ic0;
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
      jy = 7 * lastc + ic0;
      for (iac = ic0; iac <= jy; iac += 7) {
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
        coltop += 7;
      }
    }
  }
}

// Function for MATLAB Function: '<S11>/MATLAB Function'
void MatlabControllerClass::qrsolve(const real32_T A_data[], const int32_T
  A_size[2], const real32_T B_1[7], real32_T Y_data[], int32_T *Y_size)
{
  real32_T b_A_data[28];
  real32_T tau_data[4];
  int32_T jpvt_data[4];
  int32_T n;
  real32_T work_data[4];
  real32_T vn1_data[4];
  real32_T vn2_data[4];
  int32_T nmi;
  int32_T b_n;
  int32_T yk;
  int32_T ix;
  real32_T smax;
  real32_T s;
  int32_T b_ix;
  int32_T iy;
  int32_T d_k;
  real32_T absxk;
  real32_T t;
  real32_T B_2[7];
  int32_T b_A_size[2];
  int8_T c_idx_0;
  b_A_size[0] = 7;
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
      for (nmi = b_n; nmi <= b_n + 6; nmi++) {
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
      b_n += 7;
    }

    for (b_n = 0; b_n < n; b_n++) {
      yk = b_n * 7 + b_n;
      nmi = n - b_n;
      if (nmi < 1) {
        iy = 0;
      } else {
        iy = 1;
        if (nmi > 1) {
          ix = b_n;
          smax = std::abs(vn1_data[b_n]);
          for (b_ix = 2; b_ix <= nmi; b_ix++) {
            ix++;
            s = std::abs(vn1_data[ix]);
            if (s > smax) {
              iy = b_ix;
              smax = s;
            }
          }
        }
      }

      ix = (b_n + iy) - 1;
      if (ix + 1 != b_n + 1) {
        b_ix = 7 * ix;
        iy = 7 * b_n;
        for (d_k = 0; d_k < 7; d_k++) {
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
      s = xnrm2(6 - b_n, b_A_data, yk + 2);
      if (s != 0.0F) {
        s = rt_hypotf(b_A_data[yk], s);
        if (b_A_data[yk] >= 0.0F) {
          s = -s;
        }

        if (std::abs(s) < 9.86076132E-32F) {
          ix = -1;
          b_ix = (yk - b_n) + 7;
          do {
            ix++;
            for (iy = yk + 1; iy < b_ix; iy++) {
              b_A_data[iy] *= 1.01412048E+31F;
            }

            s *= 1.01412048E+31F;
            smax *= 1.01412048E+31F;
          } while (std::abs(s) < 9.86076132E-32F);

          s = rt_hypotf(smax, xnrm2(6 - b_n, b_A_data, yk + 2));
          if (smax >= 0.0F) {
            s = -s;
          }

          tau_data[b_n] = (s - smax) / s;
          smax = 1.0F / (smax - s);
          b_ix = (yk - b_n) + 7;
          for (iy = yk + 1; iy < b_ix; iy++) {
            b_A_data[iy] *= smax;
          }

          for (iy = 0; iy <= ix; iy++) {
            s *= 9.86076132E-32F;
          }

          smax = s;
        } else {
          tau_data[b_n] = (s - b_A_data[yk]) / s;
          smax = 1.0F / (b_A_data[yk] - s);
          ix = (yk - b_n) + 7;
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
        xzlarf(7 - b_n, nmi - 1, yk + 1, tau_data[b_n], b_A_data, (b_n + (b_n +
                 1) * 7) + 1, work_data);
        b_A_data[yk] = smax;
      }

      for (yk = b_n + 1; yk < n; yk++) {
        if (vn1_data[yk] != 0.0F) {
          nmi = 7 * yk + b_n;
          smax = std::abs(b_A_data[nmi]) / vn1_data[yk];
          smax = 1.0F - smax * smax;
          if (smax < 0.0F) {
            smax = 0.0F;
          }

          s = vn1_data[yk] / vn2_data[yk];
          s = s * s * smax;
          if (s <= 0.000345266977F) {
            vn1_data[yk] = xnrm2(6 - b_n, b_A_data, nmi + 2);
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
    while ((n < b_A_size[1]) && (std::abs(b_A_data[7 * n + n]) > 8.34465E-6F *
            std::abs(b_A_data[0]))) {
      n++;
    }
  }

  for (b_ix = 0; b_ix < 7; b_ix++) {
    B_2[b_ix] = B_1[b_ix];
  }

  LSQFromQR(b_A_data, b_A_size, tau_data, jpvt_data, B_2, n, Y_data, Y_size);
}

// Function for MATLAB Function: '<S11>/MATLAB Function'
void MatlabControllerClass::mldivide(const real32_T A_data[], const int32_T
  A_size[2], const real32_T B_0[7], real32_T Y_data[], int32_T *Y_size)
{
  if (A_size[1] == 0) {
    *Y_size = 0;
  } else {
    qrsolve(A_data, A_size, B_0, Y_data, Y_size);
  }
}

// Function for MATLAB Function: '<S11>/MATLAB Function'
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
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real32_T q2_q2;
  real32_T q3_q3;
  real32_T q0_q1;
  real32_T q0_q2;
  real32_T q0_q3;
  real32_T q1_q2;
  real32_T q1_q3;
  real32_T q2_q3;
  real32_T quat_norm;
  real32_T sin_Theta;
  real32_T sin_Psi;
  real32_T cos_Psi;
  real32_T unusedU0[4];
  real32_T A[28];
  real32_T d[7];
  boolean_T i_free[4];
  real32_T A_free_data[28];
  real32_T p_free_data[4];
  real_T p[4];
  real32_T u_opt[4];
  real_T c_data[4];
  int8_T f_data[4];
  int8_T g_data[4];
  int8_T h_data[4];
  int8_T i_data[4];
  int32_T trueCount;
  int32_T aoffset;
  int32_T b_k;
  int32_T b_aoffset;
  boolean_T x[4];
  int32_T iU;
  real32_T rtb_r_max;
  real32_T rtb_Fcn;
  boolean_T rtb_Compare;
  real32_T rtb_FCrotation[3];
  real32_T rtb_eulerAngles_dt[3];
  real32_T rtb_umin[4];
  real32_T rtb_umax[4];
  real32_T rtb_u0[4];
  real32_T rtb_B[12];
  real32_T rtb_nDLookupTable_m[12];
  real32_T rtb_M_bg[9];
  real32_T rtb_MatrixMultiply[9];
  int32_T i;
  boolean_T u_opt_data[4];
  real32_T t_0[9];
  real32_T rtb_M_bg_0[12];
  real32_T rtb_omega2_0[3];
  real32_T tmp[5];
  real32_T rtb_eulerAngles_dt_0[5];
  real32_T tmp_0[6];
  real32_T tmp_1[3];
  real32_T rtb_eulerAngles_dt_1[9];
  real32_T rtb_omega2_1[3];
  real32_T rtb_M_bg_1[7];
  boolean_T u_opt_0[4];
  int32_T A_free_size[2];
  real_T p_0;
  boolean_T x_0;
  real_T dist_idx_0;
  boolean_T e_idx_0;
  real_T dist_idx_1;
  boolean_T e_idx_1;
  real_T dist_idx_2;
  boolean_T e_idx_2;
  real_T dist_idx_3;
  boolean_T e_idx_3;
  uint32_T bpIndices_idx_2_tmp;
  real32_T rtb_M_bg_tmp;
  boolean_T exitg1;
  boolean_T exitg2;

  // MATLAB Function: '<S2>/Ground speed' incorporates:
  //   Inport: '<Root>/measure'
  //   SignalConversion: '<Root>/BusConversion_InsertedFor_measure_at_outport_0'

  scale = 1.29246971E-26F;
  absxk = std::abs(rtU.measure.V_Kg[0]);
  if (absxk > 1.29246971E-26F) {
    rtb_r_max = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    rtb_r_max = t * t;
  }

  absxk = std::abs(rtU.measure.V_Kg[1]);
  if (absxk > scale) {
    t = scale / absxk;
    rtb_r_max = rtb_r_max * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    rtb_r_max += t * t;
  }

  rtb_r_max = scale * std::sqrt(rtb_r_max);

  // Lookup_n-D: '<S4>/n-D Lookup Table' incorporates:
  //   Constant: '<S4>/Constant'
  //   Constant: '<S4>/Constant3'
  //   Lookup_n-D: '<S10>/FC rotation'
  //   Lookup_n-D: '<S5>/n-D Lookup Table'
  //   MATLAB Function: '<S2>/Ground speed'

  bpIndices_idx_2_tmp = plook_u32f_binckan(rtb_r_max, rtConstP.pooled7, 1U);
  for (iU = 0; iU < 12; iU++) {
    rtb_B[iU] = rtConstP.nDLookupTable_tableData[(plook_u32f_binckan
      (rtConstP.pooled4[iU], rtConstP.pooled6, 3U) * 3U + plook_u32f_binckan
      (rtConstP.pooled3[iU], rtConstP.pooled5, 2U)) + bpIndices_idx_2_tmp * 12U];
  }

  // End of Lookup_n-D: '<S4>/n-D Lookup Table'

  // Fcn: '<S2>/Fcn' incorporates:
  //   Inport: '<Root>/cmd'

  rtb_Fcn = 1500.0F - 500.0F * rtU.cmd.thr;

  // MATLAB Function: '<S4>/MATLAB Function'
  if (1500.0F < rtb_Fcn) {
    scale = rtb_Fcn;
  } else {
    scale = 1500.0F;
  }

  scale = (scale - 1000.0F) * (scale - 1000.0F);
  for (b_k = 0; b_k < 2; b_k++) {
    rtb_B[3 * b_k] = rtb_B[3 * b_k] * scale / 268324.0F;
    rtb_B[1 + 3 * b_k] = rtb_B[3 * b_k + 1] * scale / 268324.0F;
    rtb_B[2 + 3 * b_k] = rtb_B[3 * b_k + 2] * scale / 268324.0F;
  }

  // End of MATLAB Function: '<S4>/MATLAB Function'

  // Lookup_n-D: '<S5>/n-D Lookup Table' incorporates:
  //   Constant: '<S5>/Constant'
  //   Constant: '<S5>/Constant3'

  for (iU = 0; iU < 12; iU++) {
    rtb_nDLookupTable_m[iU] = rtConstP.nDLookupTable_tableData_e
      [(plook_u32f_binckan(rtConstP.pooled4[iU], rtConstP.pooled6, 3U) * 3U +
        plook_u32f_binckan(rtConstP.pooled3[iU], rtConstP.pooled5, 2U)) +
      bpIndices_idx_2_tmp * 12U];
  }

  // MATLAB Function: '<S10>/Quaternions to Rotation Matrix' incorporates:
  //   Inport: '<Root>/measure'
  //   SignalConversion: '<Root>/BusConversion_InsertedFor_measure_at_outport_0'

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
  rtb_u0[0] = rtU.measure.q_bg[0] / quat_norm;
  rtb_u0[1] = rtU.measure.q_bg[1] / quat_norm;
  rtb_u0[2] = rtU.measure.q_bg[2] / quat_norm;
  rtb_u0[3] = rtU.measure.q_bg[3] / quat_norm;
  t = rtb_u0[0] * rtb_u0[0];
  quat_norm = rtb_u0[1] * rtb_u0[1];
  q2_q2 = rtb_u0[2] * rtb_u0[2];
  q3_q3 = rtb_u0[3] * rtb_u0[3];
  q0_q1 = rtb_u0[0] * rtb_u0[1];
  q0_q2 = rtb_u0[0] * rtb_u0[2];
  q0_q3 = rtb_u0[0] * rtb_u0[3];
  q1_q2 = rtb_u0[1] * rtb_u0[2];
  q1_q3 = rtb_u0[1] * rtb_u0[3];
  q2_q3 = rtb_u0[2] * rtb_u0[3];
  scale = rtConstP.FCrotation_tableData[bpIndices_idx_2_tmp * 3U +
    plook_u32f_binckan(1.0F, rtConstP.pooled5, 2U)];

  // Lookup_n-D: '<S10>/FC rotation'
  rtb_FCrotation[0] = scale;
  absxk = rtConstP.FCrotation_tableData[bpIndices_idx_2_tmp * 3U +
    plook_u32f_binckan(2.0F, rtConstP.pooled5, 2U)];

  // Lookup_n-D: '<S10>/FC rotation'
  rtb_FCrotation[1] = absxk;
  cos_Psi = rtConstP.FCrotation_tableData[bpIndices_idx_2_tmp * 3U +
    plook_u32f_binckan(3.0F, rtConstP.pooled5, 2U)];

  // Lookup_n-D: '<S10>/FC rotation'
  rtb_FCrotation[2] = cos_Psi;

  // MATLAB Function: '<S21>/Euler Angles to Rotation Matrix'
  rtb_r_max = std::sin(scale);
  scale = std::cos(scale);
  sin_Theta = std::sin(absxk);
  absxk = std::cos(absxk);
  sin_Psi = std::sin(cos_Psi);
  cos_Psi = std::cos(cos_Psi);
  rtb_M_bg[0] = cos_Psi * absxk;
  rtb_M_bg[3] = sin_Psi * absxk;
  rtb_M_bg[6] = -sin_Theta;
  rtb_M_bg_tmp = cos_Psi * sin_Theta;
  rtb_M_bg[1] = rtb_M_bg_tmp * rtb_r_max - sin_Psi * scale;
  sin_Theta *= sin_Psi;
  rtb_M_bg[4] = sin_Theta * rtb_r_max + cos_Psi * scale;
  rtb_M_bg[7] = absxk * rtb_r_max;
  rtb_M_bg[2] = rtb_M_bg_tmp * scale + sin_Psi * rtb_r_max;
  rtb_M_bg[5] = sin_Theta * scale - cos_Psi * rtb_r_max;
  rtb_M_bg[8] = absxk * scale;

  // MATLAB Function: '<S10>/Quaternions to Rotation Matrix'
  t_0[0] = ((t + quat_norm) - q2_q2) - q3_q3;
  t_0[3] = (q1_q2 + q0_q3) * 2.0F;
  t_0[6] = (q1_q3 - q0_q2) * 2.0F;
  t_0[1] = (q1_q2 - q0_q3) * 2.0F;
  t -= quat_norm;
  t_0[4] = (t + q2_q2) - q3_q3;
  t_0[7] = (q2_q3 + q0_q1) * 2.0F;
  t_0[2] = (q1_q3 + q0_q2) * 2.0F;
  t_0[5] = (q2_q3 - q0_q1) * 2.0F;
  t_0[8] = (t - q2_q2) + q3_q3;

  // DiscreteIntegrator: '<S30>/x'
  t = rtDW.x_DSTATE_a;
  for (b_k = 0; b_k < 3; b_k++) {
    // Product: '<S10>/Matrix Multiply'
    rtb_FCrotation[b_k] = 0.0F;
    for (aoffset = 0; aoffset < 3; aoffset++) {
      // Product: '<S21>/Matrix Multiply' incorporates:
      //   Product: '<S10>/Matrix Multiply'

      iU = b_k + 3 * aoffset;
      rtb_MatrixMultiply[iU] = 0.0F;
      i = 3 * aoffset + b_k;
      rtb_MatrixMultiply[iU] = rtb_MatrixMultiply[i] + t_0[3 * aoffset] *
        rtb_M_bg[b_k];
      rtb_MatrixMultiply[iU] = t_0[3 * aoffset + 1] * rtb_M_bg[b_k + 3] +
        rtb_MatrixMultiply[i];
      rtb_MatrixMultiply[iU] = t_0[3 * aoffset + 2] * rtb_M_bg[b_k + 6] +
        rtb_MatrixMultiply[i];

      // Product: '<S10>/Matrix Multiply' incorporates:
      //   Inport: '<Root>/measure'
      //   SignalConversion: '<Root>/BusConversion_InsertedFor_measure_at_outport_0'

      rtb_FCrotation[b_k] += rtb_M_bg[i] * rtU.measure.omega_Kb[aoffset];
    }
  }

  // MATLAB Function: '<S21>/Rotations matrix to Euler angles'
  q2_q3 = std::atan2(rtb_MatrixMultiply[7], rtb_MatrixMultiply[8]);
  q0_q3 = std::asin(rtb_MatrixMultiply[6]);
  q2_q2 = std::atan2(rtb_MatrixMultiply[3], rtb_MatrixMultiply[0]);

  // MATLAB Function: '<S10>/Euler angles derivative' incorporates:
  //   MATLAB Function: '<S10>/Euler angles second derivate'
  //   MATLAB Function: '<S21>/Rotations matrix to Euler angles'

  q1_q2 = std::sin(q2_q3);
  rtb_r_max = q1_q2;
  sin_Theta = std::cos(q2_q3);
  scale = sin_Theta;
  absxk = std::cos(-q0_q3);
  q3_q3 = std::tan(-q0_q3);
  t_0[0] = 1.0F;
  t_0[3] = q1_q2 * q3_q3;
  t_0[6] = sin_Theta * q3_q3;
  t_0[1] = 0.0F;
  t_0[4] = sin_Theta;
  t_0[7] = -q1_q2;
  t_0[2] = 0.0F;
  t_0[5] = q1_q2 / absxk;
  t_0[8] = sin_Theta / absxk;
  for (b_k = 0; b_k < 3; b_k++) {
    rtb_eulerAngles_dt[b_k] = t_0[b_k + 6] * rtb_FCrotation[2] + (t_0[b_k + 3] *
      rtb_FCrotation[1] + t_0[b_k] * rtb_FCrotation[0]);
  }

  // End of MATLAB Function: '<S10>/Euler angles derivative'

  // RelationalOperator: '<S29>/Compare' incorporates:
  //   Constant: '<S29>/Constant'
  //   Inport: '<Root>/cmd'

  rtb_Compare = (rtU.cmd.thr > 0.9F);

  // DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
  //   MATLAB Function: '<S21>/Rotations matrix to Euler angles'

  if (rtDW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    rtDW.DiscreteTimeIntegrator_DSTATE = q2_q2;
  }

  if (rtb_Compare || (rtDW.DiscreteTimeIntegrator_PrevRese != 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE = q2_q2;
  }

  // MATLAB Function: '<S14>/wrap angle' incorporates:
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

  wrapangle(rtDW.DiscreteTimeIntegrator_DSTATE, &rtb_r_max);

  // MATLAB Function: '<S13>/wrap angle' incorporates:
  //   MATLAB Function: '<S21>/Rotations matrix to Euler angles'

  wrapangle(q2_q2, &scale);

  // MATLAB Function: '<S13>/angle error'
  q2_q2 = rtb_r_max - scale;
  if (q2_q2 > 3.1415926535897931) {
    q2_q2 -= 6.28318548F;
  } else {
    if (q2_q2 < -3.1415926535897931) {
      q2_q2 += 6.28318548F;
    }
  }

  // End of MATLAB Function: '<S13>/angle error'

  // Gain: '<S31>/omega^2' incorporates:
  //   DiscreteIntegrator: '<S31>/x'
  //   DiscreteIntegrator: '<S31>/x_dt'
  //   Gain: '<S14>/angle_max'
  //   Gain: '<S31>/2*d//omega'
  //   Inport: '<Root>/cmd'
  //   Sum: '<S31>/Sum2'
  //   Sum: '<S31>/Sum3'

  rtb_r_max = (0.785398185F * rtU.cmd.roll - (0.2F * rtDW.x_dt_DSTATE[0] +
    rtDW.x_DSTATE[0])) * 81.0F;
  q1_q3 = (0.785398185F * rtU.cmd.pitch - (0.2F * rtDW.x_dt_DSTATE[1] +
            rtDW.x_DSTATE[1])) * 81.0F;

  // Gain: '<S30>/1//T' incorporates:
  //   DiscreteIntegrator: '<S30>/x'
  //   Gain: '<S14>/r_max'
  //   Inport: '<Root>/cmd'
  //   Sum: '<S30>/Sum2'

  quat_norm = (2.09439516F * rtU.cmd.yaw - rtDW.x_DSTATE_a) * 3.33333325F;

  // MATLAB Function: '<S10>/Euler angles second derivate' incorporates:
  //   MATLAB Function: '<S21>/Rotations matrix to Euler angles'

  if (-1.5550883635269477 < -q0_q3) {
    scale = -q0_q3;
  } else {
    scale = -1.5550884F;
  }

  if (1.5550883635269477 > scale) {
    q3_q3 = scale;
  } else {
    q3_q3 = 1.5550884F;
  }

  absxk = std::cos(q3_q3);
  q3_q3 = std::tan(q3_q3);
  q0_q1 = absxk * absxk;

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_u0[0] = ((1100.0F - rtDW.x_DSTATE_m[0]) + (1900.0F - rtDW.x_DSTATE_m[0])) *
    0.5F;

  // MATLAB Function: '<S11>/MATLAB Function'
  unusedU0[0] = 0.0F;

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_umin[0] = 1100.0F - rtDW.x_DSTATE_m[0];
  rtb_umax[0] = 1900.0F - rtDW.x_DSTATE_m[0];
  rtb_u0[1] = ((1100.0F - rtDW.x_DSTATE_m[1]) + (1900.0F - rtDW.x_DSTATE_m[1])) *
    0.5F;

  // MATLAB Function: '<S11>/MATLAB Function'
  unusedU0[1] = 0.0F;

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_umin[1] = 1100.0F - rtDW.x_DSTATE_m[1];
  rtb_umax[1] = 1900.0F - rtDW.x_DSTATE_m[1];
  rtb_u0[2] = ((1000.0F - rtDW.x_DSTATE_m[2]) + (2000.0F - rtDW.x_DSTATE_m[2])) *
    0.5F;

  // MATLAB Function: '<S11>/MATLAB Function'
  unusedU0[2] = 0.0F;

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_umin[2] = 1000.0F - rtDW.x_DSTATE_m[2];
  rtb_umax[2] = 2000.0F - rtDW.x_DSTATE_m[2];
  rtb_u0[3] = ((1000.0F - rtDW.x_DSTATE_m[3]) + (2000.0F - rtDW.x_DSTATE_m[3])) *
    0.5F;

  // MATLAB Function: '<S11>/MATLAB Function'
  unusedU0[3] = 0.0F;

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_umin[3] = 1000.0F - rtDW.x_DSTATE_m[3];
  rtb_umax[3] = 2000.0F - rtDW.x_DSTATE_m[3];

  // MATLAB Function: '<S11>/MATLAB Function' incorporates:
  //   Constant: '<S11>/Constant5'
  //   Constant: '<S11>/Constant6'
  //   Lookup_n-D: '<S11>/1-D Lookup Table'

  q0_q2 = std::sqrt(look1_iflf_binlx(rtb_Fcn, rtConstP.uDLookupTable_bp01Data,
    rtConstP.uDLookupTable_tableData, 2U));
  for (i = 0; i < 9; i++) {
    rtb_M_bg[i] = q0_q2 * rtConstP.Constant5_Value[i];
  }

  for (b_k = 0; b_k < 4; b_k++) {
    for (aoffset = 0; aoffset < 3; aoffset++) {
      iU = aoffset + 3 * b_k;
      rtb_M_bg_0[iU] = 0.0F;
      i = 3 * b_k + aoffset;
      rtb_M_bg_0[iU] = rtb_M_bg_0[i] + rtb_B[3 * b_k] * rtb_M_bg[aoffset];
      rtb_M_bg_0[iU] = rtb_B[3 * b_k + 1] * rtb_M_bg[aoffset + 3] + rtb_M_bg_0[i];
      rtb_M_bg_0[iU] = rtb_B[3 * b_k + 2] * rtb_M_bg[aoffset + 6] + rtb_M_bg_0[i];
    }
  }

  for (b_k = 0; b_k < 4; b_k++) {
    A[7 * b_k] = rtb_M_bg_0[3 * b_k];
    A[1 + 7 * b_k] = rtb_M_bg_0[3 * b_k + 1];
    A[2 + 7 * b_k] = rtb_M_bg_0[3 * b_k + 2];
    iU = b_k << 2;
    A[3 + 7 * b_k] = rtConstP.Constant6_Value[iU];
    A[4 + 7 * b_k] = rtConstP.Constant6_Value[iU + 1];
    A[5 + 7 * b_k] = rtConstP.Constant6_Value[iU + 2];
    A[6 + 7 * b_k] = rtConstP.Constant6_Value[iU + 3];
  }

  // Sum: '<S2>/Add1'
  rtb_omega2_0[2] = quat_norm;

  // Sum: '<S13>/error1 ' incorporates:
  //   DiscreteIntegrator: '<S30>/x'

  tmp[2] = rtDW.x_DSTATE_a;

  // Sum: '<S2>/Add1'
  rtb_omega2_0[0] = rtb_r_max;

  // Sum: '<S13>/error1 ' incorporates:
  //   DiscreteIntegrator: '<S31>/x'
  //   DiscreteIntegrator: '<S31>/x_dt'

  tmp[0] = rtDW.x_dt_DSTATE[0];
  tmp[3] = rtDW.x_DSTATE[0];

  // Sum: '<S2>/Add1'
  rtb_omega2_0[1] = q1_q3;

  // Sum: '<S13>/error1 ' incorporates:
  //   DiscreteIntegrator: '<S31>/x'
  //   DiscreteIntegrator: '<S31>/x_dt'
  //   MATLAB Function: '<S21>/Rotations matrix to Euler angles'

  tmp[1] = rtDW.x_dt_DSTATE[1];
  tmp[4] = rtDW.x_DSTATE[1];
  rtb_eulerAngles_dt_0[0] = rtb_eulerAngles_dt[0];
  rtb_eulerAngles_dt_0[1] = rtb_eulerAngles_dt[1];
  rtb_eulerAngles_dt_0[2] = rtb_eulerAngles_dt[2];
  rtb_eulerAngles_dt_0[3] = q2_q3;
  rtb_eulerAngles_dt_0[4] = -q0_q3;

  // SignalConversion: '<S7>/TmpSignal ConversionAtGainInport1' incorporates:
  //   Sum: '<S13>/error1 '

  for (b_k = 0; b_k < 5; b_k++) {
    tmp_0[b_k] = tmp[b_k] - rtb_eulerAngles_dt_0[b_k];
  }

  tmp_0[5] = q2_q2;

  // MATLAB Function: '<S10>/Euler angles second derivate' incorporates:
  //   DiscreteIntegrator: '<S19>/x'

  t_0[0] = 1.0F;
  q2_q3 = q1_q2 * q3_q3;
  t_0[3] = q2_q3;
  q0_q3 = sin_Theta * q3_q3;
  t_0[6] = q0_q3;
  t_0[1] = 0.0F;
  t_0[4] = sin_Theta;
  t_0[7] = -q1_q2;
  t_0[2] = 0.0F;
  t_0[5] = q1_q2 / absxk;
  q2_q2 = sin_Theta / absxk;
  t_0[8] = q2_q2;
  rtb_MatrixMultiply[0] = 0.0F;
  rtb_MatrixMultiply[3] = q0_q3 * rtb_eulerAngles_dt[0];
  rtb_MatrixMultiply[6] = -q1_q2 * q3_q3 * rtb_eulerAngles_dt[0];
  rtb_MatrixMultiply[1] = 0.0F;
  rtb_MatrixMultiply[4] = rtb_eulerAngles_dt[0] * -q1_q2;
  rtb_MatrixMultiply[7] = rtb_eulerAngles_dt[0] * -sin_Theta;
  rtb_MatrixMultiply[2] = 0.0F;
  rtb_MatrixMultiply[5] = q2_q2 * rtb_eulerAngles_dt[0];
  rtb_MatrixMultiply[8] = -q1_q2 / absxk * rtb_eulerAngles_dt[0];
  rtb_eulerAngles_dt_1[0] = 0.0F;
  rtb_eulerAngles_dt_1[3] = q1_q2 / q0_q1 * rtb_eulerAngles_dt[1];
  rtb_eulerAngles_dt_1[6] = sin_Theta / q0_q1 * rtb_eulerAngles_dt[1];
  rtb_eulerAngles_dt_1[2] = 0.0F;
  rtb_eulerAngles_dt_1[5] = q2_q3 / absxk * rtb_eulerAngles_dt[1];
  rtb_eulerAngles_dt_1[8] = q0_q3 / absxk * rtb_eulerAngles_dt[1];
  for (b_k = 0; b_k < 3; b_k++) {
    rtb_eulerAngles_dt_1[1 + 3 * b_k] = 0.0F;

    // Sum: '<S2>/Add1' incorporates:
    //   Gain: '<S7>/Gain'
    //   SignalConversion: '<S7>/TmpSignal ConversionAtGainInport1'

    q2_q3 = 0.0F;
    for (aoffset = 0; aoffset < 6; aoffset++) {
      q2_q3 += rtConstP.Gain_Gain[3 * aoffset + b_k] * tmp_0[aoffset];
    }

    rtb_omega2_1[b_k] = rtb_omega2_0[b_k] + q2_q3;
    tmp_1[b_k] = t_0[b_k + 6] * rtDW.x_DSTATE_k[2] + (t_0[b_k + 3] *
      rtDW.x_DSTATE_k[1] + t_0[b_k] * rtDW.x_DSTATE_k[0]);
    rtb_eulerAngles_dt[b_k] = rtb_MatrixMultiply[b_k + 6] * rtb_FCrotation[2] +
      rtb_MatrixMultiply[b_k + 3] * rtb_FCrotation[1];
  }

  for (b_k = 0; b_k < 3; b_k++) {
    // Sum: '<S2>/Add' incorporates:
    //   Gain: '<S2>/Gain'
    //   Product: '<S2>/MatrixMultiply1'
    //   Sum: '<S2>/Add1'
    //   UnitDelay: '<S2>/Unit Delay'

    rtb_omega2_0[b_k] = (rtb_omega2_1[b_k] - ((rtb_eulerAngles_dt_1[b_k + 3] *
      rtb_FCrotation[1] + rtb_eulerAngles_dt_1[b_k + 6] * rtb_FCrotation[2]) +
      (tmp_1[b_k] + rtb_eulerAngles_dt[b_k]))) + (((300.0F *
      rtDW.UnitDelay_DSTATE[0] * rtb_nDLookupTable_m[b_k] +
      rtb_nDLookupTable_m[b_k + 3] * (300.0F * rtDW.UnitDelay_DSTATE[1])) +
      rtb_nDLookupTable_m[b_k + 6] * (300.0F * rtDW.UnitDelay_DSTATE[2])) +
      rtb_nDLookupTable_m[b_k + 9] * (300.0F * rtDW.UnitDelay_DSTATE[3]));
  }

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   Constant: '<S11>/Constant7'
  //   DiscreteIntegrator: '<S9>/x'
  //   Gain: '<S2>/Gain1'
  //   Sum: '<S11>/Add'

  q3_q3 = rtb_Fcn - rtDW.x_DSTATE_m[2];
  rtb_Fcn -= rtDW.x_DSTATE_m[3];

  // MATLAB Function: '<S11>/MATLAB Function' incorporates:
  //   Constant: '<S11>/Constant6'
  //   Constant: '<S11>/Constant7'
  //   DiscreteIntegrator: '<S9>/x'
  //   MATLAB Function: '<S11>/MATLAB Function1'
  //   Sum: '<S11>/Add'

  for (b_k = 0; b_k < 3; b_k++) {
    rtb_eulerAngles_dt[b_k] = rtb_M_bg[b_k + 6] * rtb_omega2_0[2] +
      (rtb_M_bg[b_k + 3] * rtb_omega2_0[1] + rtb_M_bg[b_k] * rtb_omega2_0[0]);
  }

  for (b_k = 0; b_k < 4; b_k++) {
    q2_q3 = rtConstP.Constant6_Value[b_k + 12] * rtb_Fcn +
      (rtConstP.Constant6_Value[b_k + 8] * q3_q3 + (rtConstP.Constant6_Value[b_k
        + 4] * (1500.0F - rtDW.x_DSTATE_m[1]) + (1500.0F - rtDW.x_DSTATE_m[0]) *
        rtConstP.Constant6_Value[b_k]));
    p_free_data[b_k] = q2_q3;
  }

  rtb_M_bg_1[0] = rtb_eulerAngles_dt[0];
  rtb_M_bg_1[1] = rtb_eulerAngles_dt[1];
  rtb_M_bg_1[2] = rtb_eulerAngles_dt[2];
  rtb_M_bg_1[3] = p_free_data[0];
  rtb_M_bg_1[4] = p_free_data[1];
  rtb_M_bg_1[5] = p_free_data[2];
  rtb_M_bg_1[6] = p_free_data[3];
  for (b_k = 0; b_k < 7; b_k++) {
    rtb_Fcn = A[b_k + 21] * rtb_u0[3] + (A[b_k + 14] * rtb_u0[2] + (A[b_k + 7] *
      rtb_u0[1] + A[b_k] * rtb_u0[0]));
    d[b_k] = rtb_M_bg_1[b_k] - rtb_Fcn;
  }

  i_free[0] = true;
  i_free[1] = true;
  i_free[2] = true;
  i_free[3] = true;
  iU = 0;
  exitg1 = false;
  while ((!exitg1) && (iU <= 99)) {
    trueCount = 0;
    if (i_free[0]) {
      trueCount = 1;
    }

    if (i_free[1]) {
      trueCount++;
    }

    if (i_free[2]) {
      trueCount++;
    }

    if (i_free[3]) {
      trueCount++;
    }

    i = trueCount;
    trueCount = 0;
    if (i_free[0]) {
      f_data[0] = 1;
      trueCount = 1;
    }

    if (i_free[1]) {
      f_data[trueCount] = 2;
      trueCount++;
    }

    if (i_free[2]) {
      f_data[trueCount] = 3;
      trueCount++;
    }

    if (i_free[3]) {
      f_data[trueCount] = 4;
    }

    A_free_size[0] = 7;
    A_free_size[1] = i;
    for (b_k = 0; b_k < i; b_k++) {
      for (aoffset = 0; aoffset < 7; aoffset++) {
        A_free_data[aoffset + 7 * b_k] = A[(f_data[b_k] - 1) * 7 + aoffset];
      }
    }

    mldivide(A_free_data, A_free_size, d, p_free_data, &b_aoffset);
    trueCount = 0;
    p_0 = 0.0;
    if (i_free[0]) {
      p_0 = p_free_data[0];
      trueCount = 1;
    }

    u_opt[0] = rtb_u0[0] + (real32_T)p_0;
    p[0] = p_0;
    p_0 = 0.0;
    if (i_free[1]) {
      p_0 = p_free_data[trueCount];
      trueCount++;
    }

    u_opt[1] = rtb_u0[1] + (real32_T)p_0;
    p[1] = p_0;
    p_0 = 0.0;
    if (i_free[2]) {
      p_0 = p_free_data[trueCount];
      trueCount++;
    }

    u_opt[2] = rtb_u0[2] + (real32_T)p_0;
    p[2] = p_0;
    p_0 = 0.0;
    if (i_free[3]) {
      p_0 = p_free_data[trueCount];
    }

    u_opt[3] = rtb_u0[3] + (real32_T)p_0;
    p[3] = p_0;
    trueCount = 0;
    if (i_free[0]) {
      trueCount = 1;
    }

    if (i_free[1]) {
      trueCount++;
    }

    if (i_free[2]) {
      trueCount++;
    }

    if (i_free[3]) {
      trueCount++;
    }

    aoffset = trueCount;
    trueCount = 0;
    if (i_free[0]) {
      g_data[0] = 1;
      trueCount = 1;
    }

    u_opt_0[0] = ((u_opt[0] < rtb_umin[0]) || (u_opt[0] > rtb_umax[0]));
    if (i_free[1]) {
      g_data[trueCount] = 2;
      trueCount++;
    }

    u_opt_0[1] = ((u_opt[1] < rtb_umin[1]) || (u_opt[1] > rtb_umax[1]));
    if (i_free[2]) {
      g_data[trueCount] = 3;
      trueCount++;
    }

    u_opt_0[2] = ((u_opt[2] < rtb_umin[2]) || (u_opt[2] > rtb_umax[2]));
    if (i_free[3]) {
      g_data[trueCount] = 4;
    }

    u_opt_0[3] = ((u_opt[3] < 1000.0F - rtDW.x_DSTATE_m[3]) || (u_opt[3] >
      2000.0F - rtDW.x_DSTATE_m[3]));
    for (b_k = 0; b_k < aoffset; b_k++) {
      u_opt_data[b_k] = u_opt_0[g_data[b_k] - 1];
    }

    if (!any(u_opt_data, &aoffset)) {
      rtb_u0[0] = u_opt[0];
      rtb_u0[1] = u_opt[1];
      rtb_u0[2] = u_opt[2];
      rtb_u0[3] = u_opt[3];
      if (i == 1) {
        for (b_k = 0; b_k < 7; b_k++) {
          rtb_M_bg_1[b_k] = 0.0F;
          for (aoffset = 0; aoffset < i; aoffset++) {
            rtb_M_bg_1[b_k] += A_free_data[7 * aoffset + b_k] *
              p_free_data[aoffset];
          }
        }
      } else if (b_aoffset == 1) {
        for (b_k = 0; b_k < 7; b_k++) {
          rtb_M_bg_1[b_k] = 0.0F;
          for (aoffset = 0; aoffset < i; aoffset++) {
            rtb_M_bg_1[b_k] += A_free_data[7 * aoffset + b_k] *
              p_free_data[aoffset];
          }
        }
      } else {
        for (trueCount = 0; trueCount < 7; trueCount++) {
          rtb_M_bg_1[trueCount] = 0.0F;
        }

        for (trueCount = 0; trueCount < i; trueCount++) {
          b_aoffset = trueCount * 7;
          for (b_k = 0; b_k < 7; b_k++) {
            aoffset = b_aoffset + b_k;
            rtb_M_bg_1[b_k] += A[(f_data[aoffset / 7] - 1) * 7 + aoffset % 7] *
              p_free_data[trueCount];
          }
        }
      }

      for (b_k = 0; b_k < 7; b_k++) {
        d[b_k] -= rtb_M_bg_1[b_k];
      }

      for (i = 0; i < 4; i++) {
        p_free_data[i] = 0.0F;
        for (b_k = 0; b_k < 7; b_k++) {
          p_free_data[i] += A[7 * i + b_k] * d[b_k];
        }

        rtb_Fcn = unusedU0[i] * p_free_data[i];
        x[i] = (rtb_Fcn >= -2.22044605E-16F);
        u_opt[i] = rtb_Fcn;
      }

      x_0 = true;
      trueCount = 0;
      exitg2 = false;
      while ((!exitg2) && (trueCount < 4)) {
        if (!x[trueCount]) {
          x_0 = false;
          exitg2 = true;
        } else {
          trueCount++;
        }
      }

      if (x_0) {
        exitg1 = true;
      } else {
        rtb_Fcn = u_opt[0];
        trueCount = 0;
        if (u_opt[0] > u_opt[1]) {
          rtb_Fcn = u_opt[1];
          trueCount = 1;
        }

        if (rtb_Fcn > u_opt[2]) {
          rtb_Fcn = u_opt[2];
          trueCount = 2;
        }

        if (rtb_Fcn > u_opt[3]) {
          trueCount = 3;
        }

        unusedU0[trueCount] = 0.0F;
        i_free[trueCount] = true;
        iU++;
      }
    } else {
      trueCount = 0;
      dist_idx_0 = 1.0;
      x_0 = (p[0] < 0.0);
      e_idx_0 = (p[0] > 0.0);
      if (i_free[0] && x_0) {
        trueCount = 1;
      }

      x[0] = x_0;
      dist_idx_1 = 1.0;
      x_0 = (p[1] < 0.0);
      e_idx_1 = (p[1] > 0.0);
      if (i_free[1] && x_0) {
        trueCount++;
      }

      x[1] = x_0;
      dist_idx_2 = 1.0;
      x_0 = (p[2] < 0.0);
      e_idx_2 = (p[2] > 0.0);
      if (i_free[2] && x_0) {
        trueCount++;
      }

      x[2] = x_0;
      dist_idx_3 = 1.0;
      x_0 = (p_0 < 0.0);
      e_idx_3 = (p_0 > 0.0);
      if (i_free[3] && x_0) {
        trueCount++;
      }

      aoffset = trueCount;
      trueCount = 0;
      if (i_free[0] && x[0]) {
        h_data[0] = 1;
        trueCount = 1;
      }

      if (i_free[1] && x[1]) {
        h_data[trueCount] = 2;
        trueCount++;
      }

      if (i_free[2] && x[2]) {
        h_data[trueCount] = 3;
        trueCount++;
      }

      if (i_free[3] && x_0) {
        h_data[trueCount] = 4;
      }

      for (b_k = 0; b_k < aoffset; b_k++) {
        trueCount = h_data[b_k] - 1;
        c_data[b_k] = (rtb_umin[trueCount] - rtb_u0[trueCount]) / (real32_T)
          p[trueCount];
      }

      trueCount = 0;
      if (i_free[0] && x[0]) {
        dist_idx_0 = c_data[0];
        trueCount = 1;
      }

      if (i_free[1] && x[1]) {
        dist_idx_1 = c_data[trueCount];
        trueCount++;
      }

      if (i_free[2] && x[2]) {
        dist_idx_2 = c_data[trueCount];
        trueCount++;
      }

      if (i_free[3] && x_0) {
        dist_idx_3 = c_data[trueCount];
      }

      trueCount = 0;
      if (i_free[0] && e_idx_0) {
        trueCount = 1;
      }

      if (i_free[1] && e_idx_1) {
        trueCount++;
      }

      if (i_free[2] && e_idx_2) {
        trueCount++;
      }

      if (i_free[3] && e_idx_3) {
        trueCount++;
      }

      aoffset = trueCount;
      trueCount = 0;
      if (i_free[0] && e_idx_0) {
        i_data[0] = 1;
        trueCount = 1;
      }

      if (i_free[1] && e_idx_1) {
        i_data[trueCount] = 2;
        trueCount++;
      }

      if (i_free[2] && e_idx_2) {
        i_data[trueCount] = 3;
        trueCount++;
      }

      if (i_free[3] && e_idx_3) {
        i_data[trueCount] = 4;
      }

      for (b_k = 0; b_k < aoffset; b_k++) {
        trueCount = i_data[b_k] - 1;
        c_data[b_k] = (rtb_umax[trueCount] - rtb_u0[trueCount]) / (real32_T)
          p[trueCount];
      }

      trueCount = 0;
      if (i_free[0] && e_idx_0) {
        dist_idx_0 = c_data[0];
        trueCount = 1;
      }

      if (i_free[1] && e_idx_1) {
        dist_idx_1 = c_data[trueCount];
        trueCount++;
      }

      if (i_free[2] && e_idx_2) {
        dist_idx_2 = c_data[trueCount];
        trueCount++;
      }

      if (i_free[3] && e_idx_3) {
        dist_idx_3 = c_data[trueCount];
      }

      trueCount = 0;
      if (dist_idx_0 > dist_idx_1) {
        dist_idx_0 = dist_idx_1;
        trueCount = 1;
      }

      if (dist_idx_0 > dist_idx_2) {
        dist_idx_0 = dist_idx_2;
        trueCount = 2;
      }

      if (dist_idx_0 > dist_idx_3) {
        dist_idx_0 = dist_idx_3;
        trueCount = 3;
      }

      rtb_u0[0] += (real32_T)(dist_idx_0 * p[0]);
      rtb_u0[1] += (real32_T)(dist_idx_0 * p[1]);
      rtb_u0[2] += (real32_T)(dist_idx_0 * p[2]);
      rtb_u0[3] += (real32_T)(dist_idx_0 * p_0);
      aoffset = 7 * i - 1;
      for (b_k = 0; b_k <= aoffset; b_k++) {
        A_free_data[b_k] *= (real32_T)dist_idx_0;
      }

      if (i == 1) {
        for (b_k = 0; b_k < 7; b_k++) {
          rtb_M_bg_1[b_k] = 0.0F;
          for (aoffset = 0; aoffset < 1; aoffset++) {
            rtb_M_bg_1[b_k] += A_free_data[b_k] * p_free_data[0];
          }
        }
      } else if (b_aoffset == 1) {
        for (b_k = 0; b_k < 7; b_k++) {
          rtb_M_bg_1[b_k] = 0.0F;
          for (aoffset = 0; aoffset < i; aoffset++) {
            rtb_M_bg_1[b_k] += A_free_data[7 * aoffset + b_k] *
              p_free_data[aoffset];
          }
        }
      } else {
        for (b_aoffset = 0; b_aoffset < 7; b_aoffset++) {
          rtb_M_bg_1[b_aoffset] = 0.0F;
        }

        for (b_k = 0; b_k < i; b_k++) {
          aoffset = b_k * 7;
          for (b_aoffset = 0; b_aoffset < 7; b_aoffset++) {
            rtb_M_bg_1[b_aoffset] += A_free_data[aoffset + b_aoffset] *
              p_free_data[b_k];
          }
        }
      }

      for (b_k = 0; b_k < 7; b_k++) {
        d[b_k] -= rtb_M_bg_1[b_k];
      }

      if (p[trueCount] < 0.0) {
        unusedU0[trueCount] = -1.0F;
      } else if (p[trueCount] > 0.0) {
        unusedU0[trueCount] = 1.0F;
      } else {
        unusedU0[trueCount] = (real32_T)p[trueCount];
      }

      i_free[trueCount] = false;
      iU++;
    }
  }

  // Sum: '<S2>/Add3' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_Fcn = rtb_u0[0] + rtDW.x_DSTATE_m[0];

  // Saturate: '<S2>/Saturation1'
  if (rtb_Fcn > 2000.0F) {
    q3_q3 = 2000.0F;
  } else if (rtb_Fcn < 1000.0F) {
    q3_q3 = 1000.0F;
  } else {
    q3_q3 = rtb_Fcn;
  }

  // Sum: '<S2>/Add3' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_umin[0] = rtb_Fcn;
  rtb_Fcn = rtb_u0[1] + rtDW.x_DSTATE_m[1];

  // Saturate: '<S2>/Saturation1'
  if (rtb_Fcn > 2000.0F) {
    q0_q1 = 2000.0F;
  } else if (rtb_Fcn < 1000.0F) {
    q0_q1 = 1000.0F;
  } else {
    q0_q1 = rtb_Fcn;
  }

  // Sum: '<S2>/Add3' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_umin[1] = rtb_Fcn;
  rtb_Fcn = rtb_u0[2] + rtDW.x_DSTATE_m[2];

  // Saturate: '<S2>/Saturation1'
  if (rtb_Fcn > 2000.0F) {
    q2_q2 = 2000.0F;
  } else if (rtb_Fcn < 1000.0F) {
    q2_q2 = 1000.0F;
  } else {
    q2_q2 = rtb_Fcn;
  }

  // Sum: '<S2>/Add3' incorporates:
  //   DiscreteIntegrator: '<S9>/x'

  rtb_umin[2] = rtb_Fcn;
  rtb_Fcn = rtb_u0[3] + rtDW.x_DSTATE_m[3];

  // Saturate: '<S2>/Saturation1'
  if (rtb_Fcn > 2000.0F) {
    q0_q2 = 2000.0F;
  } else if (rtb_Fcn < 1000.0F) {
    q0_q2 = 1000.0F;
  } else {
    q0_q2 = rtb_Fcn;
  }

  // Outport: '<Root>/u' incorporates:
  //   MATLAB Function: '<S3>/MATLAB Function'

  rtY.u[0] = (q0_q2 - 1500.0F) / 1000.0F + 0.5F;
  rtY.u[1] = (q2_q2 - 1500.0F) / 1000.0F + 0.5F;
  rtY.u[2] = 0.0F;
  rtY.u[3] = 0.0F;
  rtY.u[4] = -((q0_q1 - 1500.0F) / 1000.0F) + 0.5F;
  rtY.u[5] = (q3_q3 - 1500.0F) / 1000.0F + 0.5F;
  rtY.u[6] = 0.0F;
  rtY.u[7] = 0.0F;

  // Sum: '<S9>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S26>/x'
  //   DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S9>/x'
  //   DiscreteIntegrator: '<S9>/x_dt'
  //   Gain: '<S9>/2*d//omega'
  //   Lookup_n-D: '<S12>/1-D Lookup Table1'
  //   Sum: '<S9>/Sum3'

  rtb_umax[0] = look1_iflf_binlx(rtDW.x_DSTATE_c[0], rtConstP.pooled16,
    rtConstP.pooled15, 1U) - (0.02F * rtDW.x_dt_DSTATE_p[0] + rtDW.x_DSTATE_m[0]);
  rtb_umax[2] = rtDW.A[0] - (0.02F * rtDW.x_dt_DSTATE_p[2] + rtDW.x_DSTATE_m[2]);
  rtb_umax[1] = look1_iflf_binlx(rtDW.x_DSTATE_c[1], rtConstP.pooled16,
    rtConstP.pooled15, 1U) - (0.02F * rtDW.x_dt_DSTATE_p[1] + rtDW.x_DSTATE_m[1]);
  rtb_umax[3] = rtDW.A[1] - (0.02F * rtDW.x_dt_DSTATE_p[3] + rtDW.x_DSTATE_m[3]);

  // SampleTimeMath: '<S16>/TSamp'
  //
  //  About '<S16>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  q3_q3 = rtb_FCrotation[0] * 300.0F;

  // Sum: '<S19>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S19>/x'
  //   DiscreteIntegrator: '<S19>/x_dt'
  //   Gain: '<S19>/2*d//omega'
  //   Sum: '<S16>/Diff'
  //   Sum: '<S19>/Sum3'
  //   UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  q0_q1 = (q3_q3 - rtDW.UD_DSTATE[0]) - (0.02F * rtDW.x_dt_DSTATE_k[0] +
    rtDW.x_DSTATE_k[0]);

  // SampleTimeMath: '<S16>/TSamp'
  //
  //  About '<S16>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_FCrotation[0] = q3_q3;
  q3_q3 = rtb_FCrotation[1] * 300.0F;

  // Sum: '<S19>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S19>/x'
  //   DiscreteIntegrator: '<S19>/x_dt'
  //   Gain: '<S19>/2*d//omega'
  //   Sum: '<S16>/Diff'
  //   Sum: '<S19>/Sum3'
  //   UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  q2_q2 = (q3_q3 - rtDW.UD_DSTATE[1]) - (0.02F * rtDW.x_dt_DSTATE_k[1] +
    rtDW.x_DSTATE_k[1]);

  // SampleTimeMath: '<S16>/TSamp'
  //
  //  About '<S16>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_FCrotation[1] = q3_q3;
  q3_q3 = rtb_FCrotation[2] * 300.0F;

  // Sum: '<S19>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S19>/x'
  //   DiscreteIntegrator: '<S19>/x_dt'
  //   Gain: '<S19>/2*d//omega'
  //   Sum: '<S16>/Diff'
  //   Sum: '<S19>/Sum3'
  //   UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  q0_q2 = (q3_q3 - rtDW.UD_DSTATE[2]) - (0.02F * rtDW.x_dt_DSTATE_k[2] +
    rtDW.x_DSTATE_k[2]);

  // Lookup_n-D: '<S12>/1-D Lookup Table'
  scale = look1_iflf_binlx(rtb_umin[0], rtConstP.pooled15, rtConstP.pooled16, 1U);

  // Saturate: '<S12>/Saturation2'
  if (scale > 0.436332315F) {
    scale = 0.436332315F;
  } else {
    if (scale < -0.436332315F) {
      scale = -0.436332315F;
    }
  }

  // Lookup_n-D: '<S12>/1-D Lookup Table' incorporates:
  //   DiscreteIntegrator: '<S26>/x'
  //   DiscreteIntegrator: '<S26>/x_dt'
  //   Gain: '<S26>/2*d//omega'
  //   Sum: '<S26>/Sum2'
  //   Sum: '<S26>/Sum3'

  absxk = scale - (0.025F * rtDW.x_dt_DSTATE_d[0] + rtDW.x_DSTATE_c[0]);

  // Update for DiscreteIntegrator: '<S31>/x' incorporates:
  //   DiscreteIntegrator: '<S31>/x_dt'

  rtDW.x_DSTATE[0] += 0.00333333341F * rtDW.x_dt_DSTATE[0];

  // Update for DiscreteIntegrator: '<S31>/x_dt'
  rtDW.x_dt_DSTATE[0] += 0.00333333341F * rtb_r_max;

  // Lookup_n-D: '<S12>/1-D Lookup Table'
  scale = look1_iflf_binlx(rtb_umin[1], rtConstP.pooled15, rtConstP.pooled16, 1U);

  // Saturate: '<S12>/Saturation2'
  if (scale > 0.436332315F) {
    scale = 0.436332315F;
  } else {
    if (scale < -0.436332315F) {
      scale = -0.436332315F;
    }
  }

  // Sum: '<S26>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S26>/x'
  //   DiscreteIntegrator: '<S26>/x_dt'
  //   Gain: '<S26>/2*d//omega'
  //   Sum: '<S26>/Sum3'

  scale -= 0.025F * rtDW.x_dt_DSTATE_d[1] + rtDW.x_DSTATE_c[1];

  // Update for DiscreteIntegrator: '<S31>/x' incorporates:
  //   DiscreteIntegrator: '<S31>/x_dt'

  rtDW.x_DSTATE[1] += 0.00333333341F * rtDW.x_dt_DSTATE[1];

  // Update for DiscreteIntegrator: '<S31>/x_dt'
  rtDW.x_dt_DSTATE[1] += 0.00333333341F * q1_q3;

  // Update for DiscreteIntegrator: '<S30>/x'
  rtDW.x_DSTATE_a += 0.00333333341F * quat_norm;

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.00333333341F * t;
  rtDW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Compare;

  // Update for DiscreteIntegrator: '<S19>/x' incorporates:
  //   DiscreteIntegrator: '<S19>/x_dt'

  rtDW.x_DSTATE_k[0] += 0.00333333341F * rtDW.x_dt_DSTATE_k[0];
  rtDW.x_DSTATE_k[1] += 0.00333333341F * rtDW.x_dt_DSTATE_k[1];
  rtDW.x_DSTATE_k[2] += 0.00333333341F * rtDW.x_dt_DSTATE_k[2];

  // Update for UnitDelay: '<S2>/Unit Delay'
  rtDW.UnitDelay_DSTATE[0] = rtb_u0[0];

  // Update for DiscreteIntegrator: '<S9>/x' incorporates:
  //   DiscreteIntegrator: '<S9>/x_dt'

  rtDW.x_DSTATE_m[0] += 0.00333333341F * rtDW.x_dt_DSTATE_p[0];

  // Update for DiscreteIntegrator: '<S9>/x_dt' incorporates:
  //   Gain: '<S9>/omega^2'

  rtDW.x_dt_DSTATE_p[0] += 10000.0F * rtb_umax[0] * 0.00333333341F;

  // Update for UnitDelay: '<S2>/Unit Delay'
  rtDW.UnitDelay_DSTATE[1] = rtb_u0[1];

  // Update for DiscreteIntegrator: '<S9>/x' incorporates:
  //   DiscreteIntegrator: '<S9>/x_dt'

  rtDW.x_DSTATE_m[1] += 0.00333333341F * rtDW.x_dt_DSTATE_p[1];

  // Update for DiscreteIntegrator: '<S9>/x_dt' incorporates:
  //   Gain: '<S9>/omega^2'

  rtDW.x_dt_DSTATE_p[1] += 10000.0F * rtb_umax[1] * 0.00333333341F;

  // Update for UnitDelay: '<S2>/Unit Delay'
  rtDW.UnitDelay_DSTATE[2] = rtb_u0[2];

  // Update for DiscreteIntegrator: '<S9>/x' incorporates:
  //   DiscreteIntegrator: '<S9>/x_dt'

  rtDW.x_DSTATE_m[2] += 0.00333333341F * rtDW.x_dt_DSTATE_p[2];

  // Update for DiscreteIntegrator: '<S9>/x_dt' incorporates:
  //   Gain: '<S9>/omega^2'

  rtDW.x_dt_DSTATE_p[2] += 10000.0F * rtb_umax[2] * 0.00333333341F;

  // Update for UnitDelay: '<S2>/Unit Delay'
  rtDW.UnitDelay_DSTATE[3] = rtb_u0[3];

  // Update for DiscreteIntegrator: '<S9>/x' incorporates:
  //   DiscreteIntegrator: '<S9>/x_dt'

  rtDW.x_DSTATE_m[3] += 0.00333333341F * rtDW.x_dt_DSTATE_p[3];

  // Update for DiscreteIntegrator: '<S9>/x_dt' incorporates:
  //   Gain: '<S9>/omega^2'

  rtDW.x_dt_DSTATE_p[3] += 10000.0F * rtb_umax[3] * 0.00333333341F;

  // Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S8>/1//T'
  //   Sum: '<S8>/Sum2'

  rtDW.A[0] += (rtb_umin[2] - rtDW.A[0]) * 16.666666F * 0.00333333341F;

  // Update for DiscreteIntegrator: '<S26>/x' incorporates:
  //   DiscreteIntegrator: '<S26>/x_dt'

  rtDW.x_DSTATE_c[0] += 0.00333333341F * rtDW.x_dt_DSTATE_d[0];
  if (rtDW.x_DSTATE_c[0] >= 0.436332315F) {
    rtDW.x_DSTATE_c[0] = 0.436332315F;
  } else {
    if (rtDW.x_DSTATE_c[0] <= -0.436332315F) {
      rtDW.x_DSTATE_c[0] = -0.436332315F;
    }
  }

  // Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S8>/1//T'
  //   Sum: '<S8>/Sum2'

  rtDW.A[1] += (rtb_Fcn - rtDW.A[1]) * 16.666666F * 0.00333333341F;

  // Update for DiscreteIntegrator: '<S26>/x' incorporates:
  //   DiscreteIntegrator: '<S26>/x_dt'

  rtDW.x_DSTATE_c[1] += 0.00333333341F * rtDW.x_dt_DSTATE_d[1];
  if (rtDW.x_DSTATE_c[1] >= 0.436332315F) {
    rtDW.x_DSTATE_c[1] = 0.436332315F;
  } else {
    if (rtDW.x_DSTATE_c[1] <= -0.436332315F) {
      rtDW.x_DSTATE_c[1] = -0.436332315F;
    }
  }

  // Update for DiscreteIntegrator: '<S19>/x_dt' incorporates:
  //   Gain: '<S19>/omega^2'

  rtDW.x_dt_DSTATE_k[0] += 10000.0F * q0_q1 * 0.00333333341F;

  // Update for UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[0] = rtb_FCrotation[0];

  // Update for DiscreteIntegrator: '<S19>/x_dt' incorporates:
  //   Gain: '<S19>/omega^2'

  rtDW.x_dt_DSTATE_k[1] += 10000.0F * q2_q2 * 0.00333333341F;

  // Update for UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[1] = rtb_FCrotation[1];

  // Update for DiscreteIntegrator: '<S19>/x_dt' incorporates:
  //   Gain: '<S19>/omega^2'

  rtDW.x_dt_DSTATE_k[2] += 10000.0F * q0_q2 * 0.00333333341F;

  // Update for UnitDelay: '<S16>/UD'
  //
  //  Block description for '<S16>/UD':
  //
  //   Store in Global RAM

  rtDW.UD_DSTATE[2] = q3_q3;

  // Update for DiscreteIntegrator: '<S26>/x_dt' incorporates:
  //   Gain: '<S26>/omega^2'

  rtDW.x_dt_DSTATE_d[0] += 6400.0F * absxk * 0.00333333341F;
  if (rtDW.x_dt_DSTATE_d[0] >= 5.81776428F) {
    rtDW.x_dt_DSTATE_d[0] = 5.81776428F;
  } else {
    if (rtDW.x_dt_DSTATE_d[0] <= -5.81776428F) {
      rtDW.x_dt_DSTATE_d[0] = -5.81776428F;
    }
  }

  rtDW.x_dt_DSTATE_d[1] += 6400.0F * scale * 0.00333333341F;
  if (rtDW.x_dt_DSTATE_d[1] >= 5.81776428F) {
    rtDW.x_dt_DSTATE_d[1] = 5.81776428F;
  } else {
    if (rtDW.x_dt_DSTATE_d[1] <= -5.81776428F) {
      rtDW.x_dt_DSTATE_d[1] = -5.81776428F;
    }
  }

  // End of Update for DiscreteIntegrator: '<S26>/x_dt'
}

// Model initialize function
void MatlabControllerClass::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_IC_LOADI = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S9>/x'
  rtDW.x_DSTATE_m[0] = 1500.0F;
  rtDW.x_DSTATE_m[1] = 1500.0F;
  rtDW.x_DSTATE_m[2] = 1000.0F;
  rtDW.x_DSTATE_m[3] = 1000.0F;

  // InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' 
  rtDW.A[0] = 1000.0F;
  rtDW.A[1] = 1000.0F;
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
