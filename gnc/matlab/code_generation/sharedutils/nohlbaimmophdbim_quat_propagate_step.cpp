//
// File: nohlbaimmophdbim_quat_propagate_step.cpp
//
// Code generated for Simulink model 'est_estimator'.
//
// Model version                  : 1.1142
// Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
// C/C++ source code generated on : Mon Dec  4 08:33:06 2017
//
#include "rtwtypes.h"
#include <math.h>
#include "nohlbaimmophdbim_quat_propagate_step.h"

// Function for MATLAB Function: '<S16>/Compute Residual and H'
void nohlbaimmophdbim_quat_propagate_step(const real32_T quat_in[4], const
  real32_T omega[3], real32_T time_in, real_T quat_out[4])
{
  real32_T omega_mag;
  real32_T c;
  real32_T sine_mag;
  real_T x;
  real_T c_y;
  real32_T c_0[16];
  int32_T i;
  real32_T s_idx_0;
  real32_T s_idx_1;

  //  Copyright (c) 2017, United States Government, as represented by the
  //  Administrator of the National Aeronautics and Space Administration.
  //
  //  All rights reserved.
  //
  //  The Astrobee platform is licensed under the Apache License, Version 2.0
  //  (the "License"); you may not use this file except in compliance with the
  //  License. You may obtain a copy of the License at
  //
  //      http://www.apache.org/licenses/LICENSE-2.0
  //
  //  Unless required by applicable law or agreed to in writing, software
  //  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
  //  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
  //  License for the specific language governing permissions and limitations
  //  under the License.
  //  omega row vector
  //
  //  From: Indirect Kalman Filter for 3D Attitude Estimation: A tutorial for Quaternion Algebra 
  //  Equation below is from Eq. 122, with Omega matrix and
  //  identity matrix multiplied together
  //
  //  Copyright (c) 2017, United States Government, as represented by the
  //  Administrator of the National Aeronautics and Space Administration.
  //
  //  All rights reserved.
  //
  //  The Astrobee platform is licensed under the Apache License, Version 2.0
  //  (the "License"); you may not use this file except in compliance with the
  //  License. You may obtain a copy of the License at
  //
  //      http://www.apache.org/licenses/LICENSE-2.0
  //
  //  Unless required by applicable law or agreed to in writing, software
  //  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
  //  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
  //  License for the specific language governing permissions and limitations
  //  under the License.
  //  Takes the root-sum square of each row of the matrix a
  omega_mag = (real32_T)sqrt((real_T)((omega[0] * omega[0] + omega[1] * omega[1])
    + omega[2] * omega[2]));
  if ((omega_mag == 0.0F) || (time_in <= 0.0F)) {
    quat_out[0] = (real_T)quat_in[0];
    quat_out[1] = (real_T)quat_in[1];
    quat_out[2] = (real_T)quat_in[2];
    quat_out[3] = (real_T)quat_in[3];
  } else {
    c = (real32_T)cos((real_T)(0.5F * omega_mag * time_in));
    sine_mag = (real32_T)sin((real_T)(0.5F * omega_mag * time_in));
    s_idx_0 = sine_mag * omega[0] / omega_mag;
    s_idx_1 = sine_mag * omega[1] / omega_mag;
    omega_mag = sine_mag * omega[2] / omega_mag;

    //  Rollup of trig equations and Omega matrix
    c_0[0] = c;
    c_0[1] = -omega_mag;
    c_0[2] = s_idx_1;
    c_0[3] = -s_idx_0;
    c_0[4] = omega_mag;
    c_0[5] = c;
    c_0[6] = -s_idx_0;
    c_0[7] = -s_idx_1;
    c_0[8] = -s_idx_1;
    c_0[9] = s_idx_0;
    c_0[10] = c;
    c_0[11] = -omega_mag;
    c_0[12] = s_idx_0;
    c_0[13] = s_idx_1;
    c_0[14] = omega_mag;
    c_0[15] = c;
    for (i = 0; i < 4; i++) {
      c = c_0[(int32_T)(i + 12)] * quat_in[3] + (c_0[(int32_T)(i + 8)] *
        quat_in[2] + (c_0[(int32_T)(i + 4)] * quat_in[1] + c_0[i] * quat_in[0]));
      quat_out[i] = (real_T)c;
    }

    if (quat_out[3] < 0.0) {
      x = -1.0;
    } else if (quat_out[3] > 0.0) {
      x = 1.0;
    } else if (quat_out[3] == 0.0) {
      x = 0.0;
    } else {
      x = quat_out[3];
    }

    //  Copyright (c) 2017, United States Government, as represented by the
    //  Administrator of the National Aeronautics and Space Administration.
    //
    //  All rights reserved.
    //
    //  The Astrobee platform is licensed under the Apache License, Version 2.0
    //  (the "License"); you may not use this file except in compliance with the 
    //  License. You may obtain a copy of the License at
    //
    //      http://www.apache.org/licenses/LICENSE-2.0
    //
    //  Unless required by applicable law or agreed to in writing, software
    //  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT 
    //  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the 
    //  License for the specific language governing permissions and limitations
    //  under the License.
    //  Takes the root-sum square of each row of the matrix a
    c_y = sqrt(((quat_out[0] * quat_out[0] + quat_out[1] * quat_out[1]) +
                quat_out[2] * quat_out[2]) + quat_out[3] * quat_out[3]);
    quat_out[0] = x * quat_out[0] / c_y;
    quat_out[1] = x * quat_out[1] / c_y;
    quat_out[2] = x * quat_out[2] / c_y;
    quat_out[3] = x * quat_out[3] / c_y;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
