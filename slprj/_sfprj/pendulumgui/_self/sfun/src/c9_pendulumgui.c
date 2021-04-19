/* Include files */

#include "pendulumgui_sfun.h"
#include "c9_pendulumgui.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "pendulumgui_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[97] = { "m1", "n1", "l1", "Jn1", "I1",
  "c1", "m2", "n2", "l2", "Jn2", "I2", "c2", "g", "L", "I_theta", "M1", "M2",
  "I_phi", "M3", "t_exit", "ua1", "u_theta", "A2", "B2", "ep2", "P", "S2", "x2",
  "sigma_2", "R2", "K2", "u1_1", "u1_2", "u1_3", "u1_4", "u1", "A11", "A22",
  "A12", "A21", "f11", "f12", "f21", "f22", "mu", "ua2", "cond11", "cond12",
  "cond21", "cond22", "cond3", "uz2", "u2_num_1", "u2_num_2", "u2_num", "u2_den",
  "x3", "a21", "a_den", "a22", "a23", "a24", "a41", "a42", "a43", "a44", "b2",
  "b4", "A3", "B3", "ep3", "K3", "R3", "P3", "S3", "sigma_3", "u3_1", "u3_2",
  "u3_3", "u3_4", "u3", "gain", "nargin", "nargout", "theta1", "theta2",
  "theta1_d", "theta2_d", "y", "y_d", "time", "selector", "y_dd", "E1", "E2",
  "n_out", "u2" };

/* Function Declarations */
static void initialize_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance);
static void initialize_params_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance);
static void enable_c9_pendulumgui(SFc9_pendulumguiInstanceStruct *chartInstance);
static void disable_c9_pendulumgui(SFc9_pendulumguiInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_pendulumgui
  (SFc9_pendulumguiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_pendulumgui
  (SFc9_pendulumguiInstanceStruct *chartInstance);
static void set_sim_state_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_st);
static void finalize_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance);
static void sf_gateway_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance);
static void mdl_start_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance);
static void c9_chartstep_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance);
static void initSimStructsc9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_b_u2, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c9_inData_data[], int32_T c9_inData_sizes[2]);
static void c9_c_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y_data[],
  int32_T c9_y_sizes[2]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, real_T c9_outData_data[], int32_T
  c9_outData_sizes[2]);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_b_y[36]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_e_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_b_y[6]);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_f_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_g_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_b_y[4]);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_mpower(SFc9_pendulumguiInstanceStruct *chartInstance, real_T
  c9_a);
static void c9_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance);
static void c9_dimagree(SFc9_pendulumguiInstanceStruct *chartInstance);
static void c9_error(SFc9_pendulumguiInstanceStruct *chartInstance);
static real_T c9_cos(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x);
static real_T c9_sign(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x);
static void c9_b_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance);
static void c9_c_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance);
static real_T c9_sin(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x);
static real_T c9_abs(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x);
static void c9_d_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance);
static real_T c9_inv(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x);
static void c9_warning(SFc9_pendulumguiInstanceStruct *chartInstance);
static void c9_b_warning(SFc9_pendulumguiInstanceStruct *chartInstance, char_T
  c9_varargin_1[14]);
static void c9_h_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_sprintf, const char_T *c9_identifier, char_T c9_b_y[14]);
static void c9_i_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, char_T c9_b_y[14]);
static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_j_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_k_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_pendulumgui, const char_T
  *c9_identifier);
static uint8_T c9_l_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_cos(SFc9_pendulumguiInstanceStruct *chartInstance, real_T *c9_x);
static void c9_b_sign(SFc9_pendulumguiInstanceStruct *chartInstance, real_T
                      *c9_x);
static void c9_b_sin(SFc9_pendulumguiInstanceStruct *chartInstance, real_T *c9_x);
static real_T c9_get_n(SFc9_pendulumguiInstanceStruct *chartInstance, uint32_T
  c9_elementIndex);
static void c9_set_n(SFc9_pendulumguiInstanceStruct *chartInstance, uint32_T
                     c9_elementIndex, real_T c9_elementValue);
static real_T *c9_access_n(SFc9_pendulumguiInstanceStruct *chartInstance,
  uint32_T c9_rdOnly);
static void init_dsm_address_info(SFc9_pendulumguiInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc9_pendulumguiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc9_pendulumgui(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_pendulumgui = 0U;
}

static void initialize_params_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_pendulumgui(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_pendulumgui(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_pendulumgui
  (SFc9_pendulumguiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_pendulumgui
  (SFc9_pendulumguiInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_b_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_e_hoistedGlobal;
  real_T c9_e_u;
  const mxArray *c9_g_y = NULL;
  uint8_T c9_f_hoistedGlobal;
  uint8_T c9_f_u;
  const mxArray *c9_h_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_createcellmatrix(6, 1), false);
  c9_hoistedGlobal = *chartInstance->c9_E1;
  c9_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_b_y, 0, c9_c_y);
  c9_b_hoistedGlobal = *chartInstance->c9_E2;
  c9_b_u = c9_b_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_b_y, 1, c9_d_y);
  c9_c_hoistedGlobal = *chartInstance->c9_n_out;
  c9_c_u = c9_c_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_b_y, 2, c9_e_y);
  c9_d_hoistedGlobal = *chartInstance->c9_u2;
  c9_d_u = c9_d_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_b_y, 3, c9_f_y);
  c9_e_hoistedGlobal = *chartInstance->c9_y_dd;
  c9_e_u = c9_e_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_b_y, 4, c9_g_y);
  c9_f_hoistedGlobal = chartInstance->c9_is_active_c9_pendulumgui;
  c9_f_u = c9_f_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_b_y, 5, c9_h_y);
  sf_mex_assign(&c9_st, c9_b_y, false);
  return c9_st;
}

static void set_sim_state_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  *chartInstance->c9_E1 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("E1", c9_u, 0)), "E1");
  *chartInstance->c9_E2 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("E2", c9_u, 1)), "E2");
  *chartInstance->c9_n_out = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("n_out", c9_u, 2)), "n_out");
  *chartInstance->c9_u2 = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u2", c9_u, 3)), "u2");
  *chartInstance->c9_y_dd = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("y_dd", c9_u, 4)), "y_dd");
  chartInstance->c9_is_active_c9_pendulumgui = c9_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c9_pendulumgui", c9_u,
       5)), "is_active_c9_pendulumgui");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_pendulumgui(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_selector, 7U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_time, 6U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_y_d, 5U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_y, 4U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_theta2_d, 3U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_theta1_d, 2U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_theta2, 1U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_theta1, 0U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_pendulumgui(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_pendulumguiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_y_dd, 8U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_E1, 9U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_E2, 10U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_n_out, 11U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_u2, 12U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
}

static void mdl_start_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c9_chartstep_c9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_e_hoistedGlobal;
  real_T c9_f_hoistedGlobal;
  real_T c9_g_hoistedGlobal;
  real_T c9_h_hoistedGlobal;
  real_T c9_b_theta1;
  real_T c9_b_theta2;
  real_T c9_b_theta1_d;
  real_T c9_b_theta2_d;
  real_T c9_b_y;
  real_T c9_b_y_d;
  real_T c9_b_time;
  real_T c9_b_selector;
  uint32_T c9_debug_family_var_map[97];
  real_T c9_m1;
  real_T c9_n1;
  real_T c9_l1;
  real_T c9_Jn1;
  real_T c9_I1;
  real_T c9_c1;
  real_T c9_m2;
  real_T c9_n2;
  real_T c9_l2;
  real_T c9_Jn2;
  real_T c9_I2;
  real_T c9_c2;
  real_T c9_g;
  real_T c9_L;
  real_T c9_I_theta;
  real_T c9_M1;
  real_T c9_M2;
  real_T c9_I_phi;
  real_T c9_M3;
  real_T c9_t_exit;
  real_T c9_ua1;
  real_T c9_u_theta;
  real_T c9_A2[16];
  real_T c9_B2[4];
  real_T c9_ep2;
  real_T c9_P[16];
  real_T c9_S2[4];
  real_T c9_x2[4];
  real_T c9_sigma_2;
  real_T c9_R2;
  real_T c9_K2;
  real_T c9_u1_1;
  real_T c9_u1_2;
  real_T c9_u1_3;
  real_T c9_u1_4;
  real_T c9_u1;
  real_T c9_A11;
  real_T c9_A22;
  real_T c9_A12;
  real_T c9_A21;
  real_T c9_f11;
  real_T c9_f12;
  real_T c9_f21;
  real_T c9_f22;
  real_T c9_mu;
  real_T c9_ua2;
  boolean_T c9_cond11;
  boolean_T c9_cond12;
  boolean_T c9_cond21;
  boolean_T c9_cond22;
  boolean_T c9_cond3;
  real_T c9_uz2;
  real_T c9_u2_num_1;
  real_T c9_u2_num_2;
  real_T c9_u2_num;
  real_T c9_u2_den;
  real_T c9_x3[6];
  real_T c9_a21;
  real_T c9_a_den;
  real_T c9_a22;
  real_T c9_a23;
  real_T c9_a24;
  real_T c9_a41;
  real_T c9_a42;
  real_T c9_a43;
  real_T c9_a44;
  real_T c9_b2;
  real_T c9_b4;
  real_T c9_A3[36];
  real_T c9_B3[6];
  real_T c9_ep3;
  real_T c9_K3;
  real_T c9_R3;
  real_T c9_P3[36];
  real_T c9_S3[6];
  real_T c9_sigma_3;
  real_T c9_u3_1;
  real_T c9_u3_2;
  real_T c9_u3_3;
  real_T c9_u3_4;
  real_T c9_u3;
  real_T c9_gain[6];
  real_T c9_u1_data[4];
  int32_T c9_u1_sizes[2];
  real_T c9_nargin = 8.0;
  real_T c9_nargout = 5.0;
  real_T c9_b_y_dd;
  real_T c9_b_E1;
  real_T c9_b_E2;
  real_T c9_b_n_out;
  real_T c9_b_u2;
  real_T c9_d0;
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_d3;
  int32_T c9_i0;
  static real_T c9_dv0[16] = { 0.0, 24.099660249150627, 0.0, 0.0, 1.0,
    -0.0566251415628539, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 };

  int32_T c9_i1;
  static real_T c9_b[4] = { 0.0, -2.45914900501537, 0.0, 1.0 };

  int32_T c9_i2;
  static real_T c9_dv1[16] = { 229.7444, 45.7155, 56.6863, 60.8077, 45.7155,
    9.2259, 11.4113, 12.2074, 56.6863, 11.4113, 27.8115, 20.5373, 60.8077,
    12.2074, 20.5373, 20.8653 };

  int32_T c9_i3;
  static real_T c9_a[4] = { -51.613526338780147, -10.4804628053713,
    -7.5247870409318942, -9.1545155638246243 };

  int32_T c9_i4;
  real_T c9_b_b[4];
  int32_T c9_k;
  int32_T c9_b_k;
  static real_T c9_dv2[4] = { -51.613526338780147, -10.4804628053713,
    -7.5247870409318942, -9.1545155638246243 };

  real_T c9_c_y;
  int32_T c9_c_k;
  real_T c9_B;
  int32_T c9_d_k;
  real_T c9_d_y;
  real_T c9_e_y;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_e_k;
  static real_T c9_dv3[6] = { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c9_f_k;
  real_T c9_d4;
  static real_T c9_dv4[4] = { -252.57559286330837, -51.020068648781773, 0.0,
    -7.5247870409318942 };

  int32_T c9_i8;
  int32_T c9_i9;
  static real_T c9_dv5[6] = { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };

  int32_T c9_b_u1;
  int32_T c9_c_u1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  static real_T c9_dv6[4] = { 27.5833, 5.6714, 1.0, 2.1516 };

  int32_T c9_i13;
  static real_T c9_dv7[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c9_i14;
  int32_T c9_a_sizes[2];
  int32_T c9_b_a;
  int32_T c9_c_a;
  int32_T c9_i15;
  int32_T c9_i16;
  static real_T c9_c_b[6] = { 0.0, -2.4251240518187616, 0.0,
    -0.28875272637286287, 0.0, 1.0 };

  int32_T c9_i17;
  real_T c9_a_data[4];
  int32_T c9_i18;
  static real_T c9_dv8[36] = { 0.0, 28.8552, 0.0, -40.3575, 0.0, 0.0, 1.0,
    -0.1581, 0.0, 0.8612, 0.0, 0.0, 0.0, -5.0889, 0.0, 43.1873, 0.0, 0.0, 0.0,
    0.1549, 1.0, -0.8567, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0 };

  int32_T c9_g_k;
  int32_T c9_h_k;
  int32_T c9_i19;
  real_T c9_d5;
  static real_T c9_dv9[36] = { 3316.3999999999996, 75.300000000000011,
    -5107.4000000000005, -735.6, -199.6, -295.09999999999997, 75.300000000000011,
    9.9, -44.3, -5.7, 9.7000000000000011, 9.7000000000000011,
    -5107.4000000000005, -44.3, 8506.1999999999989, 1230.6999999999998, 432.5,
    599.7, -735.6, -5.7, 1230.6999999999998, 178.2, 63.4, 87.7, -199.6,
    9.7000000000000011, 432.5, 63.4, 50.6, 51.8, -295.09999999999997,
    9.7000000000000011, 599.7, 87.7, 51.8, 64.100000000000009 };

  int32_T c9_i20;
  static real_T c9_d_a[6] = { -265.3053355820748, -12.662837572680422,
    351.76501514848894, 50.067471255722779, 9.9693738453185, 15.252682594457944
  };

  int32_T c9_i21;
  real_T c9_d6;
  real_T c9_d_b[6];
  int32_T c9_i_k;
  real_T c9_d7;
  int32_T c9_j_k;
  real_T c9_f_y;
  static real_T c9_dv10[6] = { -265.3053355820748, -12.662837572680422,
    351.76501514848894, 50.067471255722779, 9.9693738453185, 15.252682594457944
  };

  real_T c9_d8;
  int32_T c9_k_k;
  int32_T c9_l_k;
  real_T c9_d9;
  int32_T c9_i22;
  real_T c9_d10;
  int32_T c9_m_k;
  real_T c9_d11;
  int32_T c9_n_k;
  real_T c9_d12;
  static real_T c9_dv11[6] = { -2385.9866819300405, -220.18523471640555,
    2226.71881548589, 306.91073898370308, 0.0, 9.9693738453185 };

  real_T c9_d13;
  int32_T c9_i23;
  static real_T c9_e_a[6] = { 360.2187, 19.735, -431.6744, -65.4821, -3.1623,
    -7.3102 };

  real_T c9_d14;
  int32_T c9_i24;
  real_T c9_d15;
  int32_T c9_o_k;
  real_T c9_d16;
  int32_T c9_p_k;
  static real_T c9_dv12[6] = { 360.2187, 19.735, -431.6744, -65.4821, -3.1623,
    -7.3102 };

  real_T c9_d17;
  real_T c9_d18;
  real_T c9_d19;
  real_T c9_d20;
  real_T c9_d21;
  real_T c9_d22;
  real_T c9_d23;
  real_T c9_d24;
  real_T c9_A;
  real_T c9_b_B;
  real_T c9_x;
  real_T c9_g_y;
  real_T c9_b_x;
  real_T c9_h_y;
  real_T c9_d25;
  real_T c9_d26;
  real_T c9_d27;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *chartInstance->c9_theta1;
  c9_b_hoistedGlobal = *chartInstance->c9_theta2;
  c9_c_hoistedGlobal = *chartInstance->c9_theta1_d;
  c9_d_hoistedGlobal = *chartInstance->c9_theta2_d;
  c9_e_hoistedGlobal = *chartInstance->c9_y;
  c9_f_hoistedGlobal = *chartInstance->c9_y_d;
  c9_g_hoistedGlobal = *chartInstance->c9_time;
  c9_h_hoistedGlobal = *chartInstance->c9_selector;
  c9_b_theta1 = c9_hoistedGlobal;
  c9_b_theta2 = c9_b_hoistedGlobal;
  c9_b_theta1_d = c9_c_hoistedGlobal;
  c9_b_theta2_d = c9_d_hoistedGlobal;
  c9_b_y = c9_e_hoistedGlobal;
  c9_b_y_d = c9_f_hoistedGlobal;
  c9_b_time = c9_g_hoistedGlobal;
  c9_b_selector = c9_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 97U, 98U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_m1, 0U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_n1, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_l1, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_Jn1, 3U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_I1, 4U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_c1, 5U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_m2, 6U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_n2, 7U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_l2, 8U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_Jn2, 9U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_I2, 10U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_c2, 11U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_g, 12U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_L, 13U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_I_theta, 14U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_M1, 15U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_M2, 16U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_I_phi, 17U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_M3, 18U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t_exit, 19U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ua1, 20U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u_theta, 21U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_A2, 22U, c9_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_B2, 23U, c9_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ep2, 24U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_P, 25U, c9_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_S2, 26U, c9_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_x2, 27U, c9_g_sf_marshallOut,
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_sigma_2, 28U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_R2, 29U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_K2, 30U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u1_1, 31U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u1_2, 32U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u1_3, 33U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u1_4, 34U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u1, MAX_uint32_T, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_A11, 36U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_A22, 37U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_A12, 38U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_A21, 39U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f11, 40U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f12, 41U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f21, 42U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f22, 43U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_mu, 44U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ua2, 45U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cond11, 46U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cond12, 47U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cond21, 48U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cond22, 49U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cond3, 50U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_uz2, 51U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u2_num_1, 52U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u2_num_2, 53U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u2_num, 54U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u2_den, 55U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_x3, 56U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_a21, 57U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_a_den, 58U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_a22, 59U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_a23, 60U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_a24, 61U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_a41, 62U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_a42, 63U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_a43, 64U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_a44, 65U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b2, 66U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b4, 67U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_A3, 68U, c9_d_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_B3, 69U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ep3, 70U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_K3, 71U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_R3, 72U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_P3, 73U, c9_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_S3, 74U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_sigma_3, 75U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u3_1, 76U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u3_2, 77U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u3_3, 78U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u3_4, 79U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_u3, 80U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_gain, 81U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_u1_data, (const int32_T *)
    &c9_u1_sizes, NULL, 0, -1, (void *)c9_b_sf_marshallOut, (void *)
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 82U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 83U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_theta1, 84U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_theta2, 85U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_theta1_d, 86U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_theta2_d, 87U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_y, 88U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_y_d, 89U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_time, 90U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_selector, 91U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_y_dd, 92U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_E1, 93U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_E2, 94U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_n_out, 95U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_u2, 96U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_m1 = 0.18;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_n1 = 0.078;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_l1 = 0.19;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_Jn1 = 2.8E-5;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_I1 = 0.0089;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_c1 = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
  c9_m2 = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
  c9_n2 = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
  c9_l2 = 0.115;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 17);
  c9_Jn2 = 2.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
  c9_I2 = 0.0018;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 19);
  c9_c2 = 0.002;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
  c9_g = 9.8;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
  c9_L = 0.38;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 24);
  c9_b_E1 = 0.00445 * c9_mpower(chartInstance, c9_b_theta1_d);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 25);
  c9_d0 = c9_b_theta1;
  c9_b_cos(chartInstance, &c9_d0);
  c9_b_E1 += 0.33516 * (c9_d0 - 1.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
  c9_b_E2 = 0.0009 * c9_mpower(chartInstance, c9_b_theta2_d);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 28);
  c9_d1 = c9_b_theta2;
  c9_b_cos(chartInstance, &c9_d1);
  c9_b_E2 += 0.11270000000000002 * (c9_d1 - 1.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 30);
  c9_I_theta = 0.037086;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 31);
  c9_M1 = 0.0043700000000000006;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 32);
  c9_M2 = 0.091200000000000017;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 33);
  c9_I_phi = 0.0031245;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 34);
  c9_M3 = 0.011500000000000002;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 38);
  c9_t_exit = 15.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 39);
  c9_ua1 = 14.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 44);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c9_get_n(chartInstance, 0),
        1.0, -1, 0U, c9_get_n(chartInstance, 0) == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
    c9_d2 = c9_b_theta1;
    c9_b_cos(chartInstance, &c9_d2);
    c9_d3 = c9_b_E1 * c9_b_theta1_d * c9_d2;
    c9_b_sign(chartInstance, &c9_d3);
    c9_u_theta = 14.0 * c9_d3;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 47);
    c9_b_y_dd = c9_u_theta;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 48);
    c9_b_u2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 51);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c9_b_time, 0.8, -1, 0U,
          c9_b_time == 0.8))) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 52);
      c9_set_n(chartInstance, 0, 2.0);
      ssUpdateDataStoreLog_wrapper(chartInstance->S, 0);
    }

    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 54);
    c9_b_n_out = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 55);
    if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c9_get_n(chartInstance,
           0), 2.0, -1, 0U, c9_get_n(chartInstance, 0) == 2.0))) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 56);
      c9_b_n_out = 2.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 59);
      for (c9_i0 = 0; c9_i0 < 16; c9_i0++) {
        c9_A2[c9_i0] = c9_dv0[c9_i0];
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 63);
      for (c9_i1 = 0; c9_i1 < 4; c9_i1++) {
        c9_B2[c9_i1] = c9_b[c9_i1];
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 64);
      c9_ep2 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 66);
      for (c9_i2 = 0; c9_i2 < 16; c9_i2++) {
        c9_P[c9_i2] = c9_dv1[c9_i2];
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 73);
      for (c9_i3 = 0; c9_i3 < 4; c9_i3++) {
        c9_S2[c9_i3] = c9_a[c9_i3];
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 76);
      c9_x2[0] = c9_b_theta1;
      c9_x2[1] = c9_b_theta1_d;
      c9_x2[2] = c9_b_y;
      c9_x2[3] = c9_b_y_d;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 78);
      for (c9_i4 = 0; c9_i4 < 4; c9_i4++) {
        c9_b_b[c9_i4] = c9_x2[c9_i4];
      }

      c9_sigma_2 = 0.0;
      for (c9_k = 1; c9_k < 5; c9_k++) {
        c9_b_k = c9_k - 1;
        c9_sigma_2 += c9_dv2[c9_b_k] * c9_b_b[c9_b_k];
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 79);
      c9_R2 = 3.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 80);
      c9_K2 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 81);
      c9_c_y = 0.0;
      for (c9_c_k = 1; c9_c_k < 5; c9_c_k++) {
        c9_d_k = c9_c_k - 1;
        c9_c_y += c9_dv2[c9_d_k] * c9_b[c9_d_k];
      }

      c9_B = c9_c_y;
      c9_d_y = c9_B;
      c9_e_y = c9_d_y;
      c9_u1_1 = -1.0 / c9_e_y;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 82);
      for (c9_i5 = 0; c9_i5 < 4; c9_i5++) {
        c9_b_b[c9_i5] = c9_x2[c9_i5];
      }

      c9_u1_2 = 0.0;
      for (c9_e_k = 1; c9_e_k < 5; c9_e_k++) {
        c9_f_k = c9_e_k - 1;
        c9_u1_2 += c9_dv4[c9_f_k] * c9_b_b[c9_f_k];
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 83);
      c9_d4 = c9_sigma_2;
      c9_b_sign(chartInstance, &c9_d4);
      c9_u1_3 = 3.0 * c9_d4;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 84);
      c9_u1_4 = c9_sigma_2;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 85);
      c9_u1 = c9_u1_1 * ((c9_u1_2 + c9_u1_3) + c9_u1_4);
      _SFD_SYMBOL_SWITCH(35U, 35U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 86);
      c9_u1_sizes[0] = 1;
      c9_u1_sizes[1] = 4;
      c9_b_u1 = c9_u1_sizes[0];
      c9_c_u1 = c9_u1_sizes[1];
      for (c9_i11 = 0; c9_i11 < 4; c9_i11++) {
        c9_u1_data[c9_i11] = c9_dv6[c9_i11];
      }

      _SFD_SYMBOL_SWITCH(35U, 82U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 87);
      c9_a_sizes[0] = 1;
      c9_a_sizes[1] = 4;
      c9_b_a = c9_a_sizes[0];
      c9_c_a = c9_a_sizes[1];
      for (c9_i16 = 0; c9_i16 < 4; c9_i16++) {
        c9_a_data[c9_i16] = c9_u1_data[c9_i16];
      }

      for (c9_i17 = 0; c9_i17 < 4; c9_i17++) {
        c9_b_b[c9_i17] = c9_x2[c9_i17];
      }

      c9_u1 = 0.0;
      for (c9_g_k = 1; c9_g_k < 5; c9_g_k++) {
        c9_h_k = c9_g_k - 1;
        c9_u1 += c9_a_data[c9_h_k] * c9_b_b[c9_h_k];
      }

      _SFD_SYMBOL_SWITCH(35U, 35U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 90);
      c9_A11 = 0.037086;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 91);
      c9_A22 = 0.0031245;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 92);
      c9_d5 = c9_b_theta1 - c9_b_theta2;
      c9_b_cos(chartInstance, &c9_d5);
      c9_A12 = 0.0043700000000000006 * c9_d5;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 93);
      c9_A21 = c9_A12;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 96);
      c9_d6 = c9_b_theta1 - c9_b_theta2;
      c9_b_sin(chartInstance, &c9_d6);
      c9_f11 = 0.0043700000000000006 * c9_mpower(chartInstance, c9_b_theta2_d) *
        c9_d6 + 0.0021 * c9_b_theta1_d;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 97);
      c9_d7 = c9_b_theta1;
      c9_b_sin(chartInstance, &c9_d7);
      c9_f11 = (c9_f11 - 0.002 * c9_b_theta2_d) - 0.89376000000000022 * c9_d7;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 98);
      c9_d8 = c9_b_theta1;
      c9_b_cos(chartInstance, &c9_d8);
      c9_f12 = 0.091200000000000017 * c9_d8;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 99);
      c9_d9 = c9_b_theta1 - c9_b_theta2;
      c9_b_sin(chartInstance, &c9_d9);
      c9_f21 = -0.0043700000000000006 * c9_mpower(chartInstance, c9_b_theta1_d) *
        c9_d9;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 100);
      c9_d10 = c9_b_theta2;
      c9_b_sin(chartInstance, &c9_d10);
      c9_f21 = (c9_f21 - 0.002 * (c9_b_theta1_d - c9_b_theta2_d)) -
        0.11270000000000002 * c9_d10;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 101);
      c9_d11 = c9_b_theta2;
      c9_b_cos(chartInstance, &c9_d11);
      c9_f22 = 0.011500000000000002 * c9_d11;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 104);
      c9_b_E2 = 0.0009 * c9_mpower(chartInstance, c9_b_theta2_d);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 105);
      c9_d13 = c9_b_theta2;
      c9_b_cos(chartInstance, &c9_d13);
      c9_b_E2 += 0.11270000000000002 * (c9_d13 - 1.0);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 106);
      c9_mu = 0.26179938779914941;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 107);
      c9_ua2 = 50.0;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 108);
      c9_d14 = c9_b_theta2;
      c9_b_sin(chartInstance, &c9_d14);
      c9_cond11 = (c9_d14 * c9_b_theta2_d < 0.0);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 109);
      c9_d15 = c9_b_theta2;
      c9_b_cos(chartInstance, &c9_d15);
      c9_d16 = 0.26179938779914941;
      c9_b_cos(chartInstance, &c9_d16);
      c9_cond12 = (c9_d15 < c9_d16);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 111);
      c9_d17 = c9_b_theta2;
      c9_b_sin(chartInstance, &c9_d17);
      c9_cond21 = (c9_d17 * c9_b_theta2_d >= 0.0);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 112);
      c9_cond22 = c9_cond12;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 113);
      c9_d18 = c9_b_theta2;
      c9_b_cos(chartInstance, &c9_d18);
      c9_d19 = 0.26179938779914941;
      c9_b_cos(chartInstance, &c9_d19);
      c9_cond3 = (c9_d18 >= c9_d19);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 114);
      guard2 = false;
      if (CV_EML_COND(0, 1, 0, c9_cond11)) {
        if (CV_EML_COND(0, 1, 1, c9_cond12)) {
          CV_EML_MCDC(0, 1, 0, true);
          CV_EML_IF(0, 1, 3, true);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 115);
          c9_d20 = c9_b_theta2;
          c9_b_cos(chartInstance, &c9_d20);
          c9_d21 = c9_b_E2 * c9_b_theta2_d * c9_d20;
          c9_b_sign(chartInstance, &c9_d21);
          c9_uz2 = 50.0 * c9_d21;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 0, false);
        CV_EML_IF(0, 1, 3, false);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 116);
        guard3 = false;
        if (CV_EML_COND(0, 1, 2, c9_cond21)) {
          if (CV_EML_COND(0, 1, 3, c9_cond22)) {
            CV_EML_MCDC(0, 1, 1, true);
            CV_EML_IF(0, 1, 4, true);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 117);
            c9_uz2 = 0.0;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3 == true) {
          CV_EML_MCDC(0, 1, 1, false);
          CV_EML_IF(0, 1, 4, false);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 118);
          if (CV_EML_IF(0, 1, 5, c9_cond3)) {
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 119);
            c9_uz2 = 0.0;
          } else {
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 120);
            c9_uz2 = 0.0;
          }
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 122);
      c9_d22 = c9_b_theta1;
      c9_b_sin(chartInstance, &c9_d22);
      c9_u2_num_1 = c9_uz2 + 0.38 * c9_mpower(chartInstance, c9_b_theta1_d) *
        c9_d22;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 123);
      c9_u2_num_1 *= 0.00011587520700000001 - c9_A12 * c9_A21;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 124);
      c9_d23 = c9_b_theta1;
      c9_b_cos(chartInstance, &c9_d23);
      c9_u2_num_2 = (c9_A12 * c9_f21 - 0.0031245 * c9_f11) * 0.38 * c9_d23;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 125);
      c9_u2_num = c9_u2_num_1 - c9_u2_num_2;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 126);
      c9_d24 = c9_b_theta1;
      c9_b_cos(chartInstance, &c9_d24);
      c9_u2_den = (c9_A12 * c9_f22 - 0.0031245 * c9_f12) * 0.38 * c9_d24;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, MAX_int8_T);
      c9_u2_den = (c9_u2_den + 0.00011587520700000001) - c9_A12 * c9_A21;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 128U);
      c9_A = c9_u2_num;
      c9_b_B = c9_u2_den;
      c9_x = c9_A;
      c9_g_y = c9_b_B;
      c9_b_x = c9_x;
      c9_h_y = c9_g_y;
      c9_b_u2 = c9_b_x / c9_h_y;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 130U);
      if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 3, c9_abs(chartInstance,
             c9_b_u2), 3.0, -1, 4U, c9_abs(chartInstance, c9_b_u2) > 3.0))) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 131U);
        c9_d25 = c9_b_u2;
        c9_b_sign(chartInstance, &c9_d25);
        c9_b_u2 = 3.0 * c9_d25;
      }

      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 134U);
      c9_b_y_dd = 0.85 * c9_u1 + c9_b_u2;
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 135U);
      c9_d26 = c9_b_theta2;
      c9_b_cos(chartInstance, &c9_d26);
      c9_d27 = c9_b_theta2;
      c9_b_cos(chartInstance, &c9_d27);
      guard1 = false;
      if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c9_d26, 0.9, -1, 4U,
            c9_d27 > 0.9))) {
        if (CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c9_abs
              (chartInstance, c9_b_theta2_d), 1.5, -1, 2U, c9_abs(chartInstance,
               c9_b_theta2_d) < 1.5))) {
          CV_EML_MCDC(0, 1, 2, true);
          CV_EML_IF(0, 1, 7, true);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 137U);
          c9_set_n(chartInstance, 0, 3.0);
          ssUpdateDataStoreLog_wrapper(chartInstance->S, 0);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 138U);
          c9_b_y_dd = c9_u1;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(0, 1, 2, false);
        CV_EML_IF(0, 1, 7, false);
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 141U);
      if (CV_EML_IF(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 6, c9_get_n
            (chartInstance, 0), 3.0, -1, 0U, c9_get_n(chartInstance, 0) == 3.0)))
      {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 142U);
        c9_b_n_out = 3.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 143U);
        c9_x3[0] = c9_b_theta1;
        c9_x3[1] = c9_b_theta1_d;
        c9_x3[2] = c9_b_theta2;
        c9_x3[3] = c9_b_theta2_d;
        c9_x3[4] = c9_b_y;
        c9_x3[5] = c9_b_y_d;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 145U);
        c9_a21 = -0.0027925531200000005;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 146U);
        c9_a_den = 9.6778307000000007E-5;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 147U);
        c9_a21 = -28.855155732368829;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 149U);
        c9_a22 = -1.530145E-5;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 150U);
        c9_a22 = -0.15810826283621596;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 152U);
        c9_a23 = 5.0889400245449652;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 154U);
        c9_a24 = 9.0524500000000017E-6;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 155U);
        c9_a24 = 0.093538007437968515;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 157U);
        c9_a41 = 40.35750697726094;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 159U);
        c9_a42 = 8.3349E-5;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 160U);
        c9_a42 = 0.861236392572976;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 163U);
        c9_a43 = -43.187283695715;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 165U);
        c9_a44 = -7.4609E-5;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 166U);
        c9_a44 = -0.77092689790492;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 168U);
        c9_b2 = -0.00023469940000000003;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 169U);
        c9_b2 = -2.4251240518187616;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 171U);
        c9_b4 = -2.7944999999999923E-5;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 172U);
        c9_b4 = -0.28875272637286287;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 174U);
        c9_i6 = 0;
        for (c9_i7 = 0; c9_i7 < 6; c9_i7++) {
          c9_A3[c9_i6] = c9_dv3[c9_i7];
          c9_i6 += 6;
        }

        c9_A3[1] = c9_a21;
        c9_A3[7] = c9_a22;
        c9_A3[13] = c9_a23;
        c9_A3[19] = c9_a24;
        c9_A3[25] = 0.0;
        c9_A3[31] = 0.0;
        c9_i8 = 0;
        for (c9_i9 = 0; c9_i9 < 6; c9_i9++) {
          c9_A3[c9_i8 + 2] = c9_dv5[c9_i9];
          c9_i8 += 6;
        }

        c9_A3[3] = c9_a41;
        c9_A3[9] = c9_a42;
        c9_A3[15] = c9_a43;
        c9_A3[21] = c9_a44;
        c9_A3[27] = 0.0;
        c9_A3[33] = 0.0;
        c9_i10 = 0;
        for (c9_i12 = 0; c9_i12 < 6; c9_i12++) {
          c9_A3[c9_i10 + 4] = c9_dv7[c9_i12];
          c9_i10 += 6;
        }

        c9_i13 = 0;
        for (c9_i14 = 0; c9_i14 < 6; c9_i14++) {
          c9_A3[c9_i13 + 5] = 0.0;
          c9_i13 += 6;
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 180U);
        for (c9_i15 = 0; c9_i15 < 6; c9_i15++) {
          c9_B3[c9_i15] = c9_c_b[c9_i15];
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 181U);
        for (c9_i18 = 0; c9_i18 < 36; c9_i18++) {
          c9_A3[c9_i18] = c9_dv8[c9_i18];
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 188U);
        c9_ep3 = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 189U);
        c9_K3 = 10.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 190U);
        c9_R3 = 3.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 195U);
        for (c9_i19 = 0; c9_i19 < 36; c9_i19++) {
          c9_P3[c9_i19] = c9_dv9[c9_i19];
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 203U);
        for (c9_i20 = 0; c9_i20 < 6; c9_i20++) {
          c9_S3[c9_i20] = c9_d_a[c9_i20];
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 206U);
        for (c9_i21 = 0; c9_i21 < 6; c9_i21++) {
          c9_d_b[c9_i21] = c9_x3[c9_i21];
        }

        c9_sigma_3 = 0.0;
        for (c9_i_k = 1; c9_i_k < 7; c9_i_k++) {
          c9_j_k = c9_i_k - 1;
          c9_sigma_3 += c9_dv10[c9_j_k] * c9_d_b[c9_j_k];
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 208U);
        c9_f_y = 0.0;
        for (c9_k_k = 1; c9_k_k < 7; c9_k_k++) {
          c9_l_k = c9_k_k - 1;
          c9_f_y += c9_dv10[c9_l_k] * c9_c_b[c9_l_k];
        }

        c9_u3_1 = -c9_inv(chartInstance, c9_f_y);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 209U);
        for (c9_i22 = 0; c9_i22 < 6; c9_i22++) {
          c9_d_b[c9_i22] = c9_x3[c9_i22];
        }

        c9_u3_2 = 0.0;
        for (c9_m_k = 1; c9_m_k < 7; c9_m_k++) {
          c9_n_k = c9_m_k - 1;
          c9_u3_2 += c9_dv11[c9_n_k] * c9_d_b[c9_n_k];
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 210U);
        c9_d12 = c9_sigma_3;
        c9_b_sign(chartInstance, &c9_d12);
        c9_u3_3 = 3.0 * c9_d12;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 211U);
        c9_u3_4 = 10.0 * c9_sigma_3;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 212U);
        c9_u3 = c9_u3_1 * ((c9_u3_2 + c9_u3_3) + c9_u3_4);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 214U);
        for (c9_i23 = 0; c9_i23 < 6; c9_i23++) {
          c9_gain[c9_i23] = c9_e_a[c9_i23];
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 218U);
        if (CV_EML_IF(0, 1, 9, CV_RELATIONAL_EVAL(4U, 0U, 7, c9_b_selector, 0.0,
              -1, 0U, c9_b_selector == 0.0))) {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 219U);
          c9_b_y_dd = c9_u3;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 221U);
          for (c9_i24 = 0; c9_i24 < 6; c9_i24++) {
            c9_d_b[c9_i24] = c9_x3[c9_i24];
          }

          c9_b_y_dd = 0.0;
          for (c9_o_k = 1; c9_o_k < 7; c9_o_k++) {
            c9_p_k = c9_o_k - 1;
            c9_b_y_dd += c9_dv12[c9_p_k] * c9_d_b[c9_p_k];
          }
        }

        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 224U);
        c9_b_u2 = 0.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 226U);
        c9_b_y_dd = 50.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 227U);
        c9_b_n_out = 3.0;
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 228U);
        c9_b_u2 = 0.0;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -228);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c9_y_dd = c9_b_y_dd;
  *chartInstance->c9_E1 = c9_b_E1;
  *chartInstance->c9_E2 = c9_b_E2;
  *chartInstance->c9_n_out = c9_b_n_out;
  *chartInstance->c9_u2 = c9_b_u2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_pendulumgui(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_b_u2, const char_T *c9_identifier)
{
  real_T c9_b_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_u2), &c9_thisId);
  sf_mex_destroy(&c9_b_u2);
  return c9_b_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_b_y;
  real_T c9_d28;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d28, 1, 0, 0U, 0, 0U, 0);
  c9_b_y = c9_d28;
  sf_mex_destroy(&c9_u);
  return c9_b_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_u2;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_b_y;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_b_u2 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_u2), &c9_thisId);
  sf_mex_destroy(&c9_b_u2);
  *(real_T *)c9_outData = c9_b_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c9_inData_data[], int32_T c9_inData_sizes[2])
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u_sizes[2];
  int32_T c9_u;
  int32_T c9_b_u;
  int32_T c9_i25;
  const mxArray *c9_b_y = NULL;
  real_T c9_u_data[4];
  SFc9_pendulumguiInstanceStruct *chartInstance;
  (void)c9_inData_sizes;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u_sizes[0] = 1;
  c9_u_sizes[1] = 4;
  c9_u = c9_u_sizes[0];
  c9_b_u = c9_u_sizes[1];
  for (c9_i25 = 0; c9_i25 < 4; c9_i25++) {
    c9_u_data[c9_i25] = c9_inData_data[c9_i25];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u_data, 0, 0U, 1U, 0U, 2,
    c9_u_sizes[0], c9_u_sizes[1]), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y_data[],
  int32_T c9_y_sizes[2])
{
  int32_T c9_i26;
  int32_T c9_i27;
  uint32_T c9_uv0[2];
  real_T c9_tmp_data[4];
  boolean_T c9_bv0[2];
  int32_T c9_tmp_sizes[2];
  int32_T c9_b_y;
  int32_T c9_c_y;
  int32_T c9_i28;
  (void)chartInstance;
  for (c9_i26 = 0; c9_i26 < 2; c9_i26++) {
    c9_uv0[c9_i26] = 1U + 3U * (uint32_T)c9_i26;
  }

  for (c9_i27 = 0; c9_i27 < 2; c9_i27++) {
    c9_bv0[c9_i27] = false;
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 1, 0, 0U, 1, 0U,
                   2, c9_bv0, c9_uv0, c9_tmp_sizes);
  c9_y_sizes[0] = 1;
  c9_y_sizes[1] = 4;
  c9_b_y = c9_y_sizes[0];
  c9_c_y = c9_y_sizes[1];
  for (c9_i28 = 0; c9_i28 < 4; c9_i28++) {
    c9_y_data[c9_i28] = c9_tmp_data[c9_i28];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, real_T c9_outData_data[], int32_T
  c9_outData_sizes[2])
{
  const mxArray *c9_u1;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y_data[4];
  int32_T c9_y_sizes[2];
  int32_T c9_i29;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_u1 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_u1), &c9_thisId, c9_y_data,
                        c9_y_sizes);
  sf_mex_destroy(&c9_u1);
  c9_outData_sizes[0] = 1;
  c9_outData_sizes[1] = 4;
  for (c9_i29 = 0; c9_i29 < 4; c9_i29++) {
    c9_outData_data[c9_outData_sizes[0] * c9_i29] = c9_y_data[c9_y_sizes[0] *
      c9_i29];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i30;
  const mxArray *c9_b_y = NULL;
  real_T c9_u[6];
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i30 = 0; c9_i30 < 6; c9_i30++) {
    c9_u[c9_i30] = (*(real_T (*)[6])c9_inData)[c9_i30];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i31;
  int32_T c9_i32;
  const mxArray *c9_b_y = NULL;
  int32_T c9_i33;
  real_T c9_u[36];
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i31 = 0;
  for (c9_i32 = 0; c9_i32 < 6; c9_i32++) {
    for (c9_i33 = 0; c9_i33 < 6; c9_i33++) {
      c9_u[c9_i33 + c9_i31] = (*(real_T (*)[36])c9_inData)[c9_i33 + c9_i31];
    }

    c9_i31 += 6;
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i34;
  const mxArray *c9_b_y = NULL;
  real_T c9_u[6];
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i34 = 0; c9_i34 < 6; c9_i34++) {
    c9_u[c9_i34] = (*(real_T (*)[6])c9_inData)[c9_i34];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static void c9_d_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_b_y[36])
{
  real_T c9_dv13[36];
  int32_T c9_i35;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv13, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c9_i35 = 0; c9_i35 < 36; c9_i35++) {
    c9_b_y[c9_i35] = c9_dv13[c9_i35];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_A3;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_b_y[36];
  int32_T c9_i36;
  int32_T c9_i37;
  int32_T c9_i38;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_A3 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_A3), &c9_thisId, c9_b_y);
  sf_mex_destroy(&c9_A3);
  c9_i36 = 0;
  for (c9_i37 = 0; c9_i37 < 6; c9_i37++) {
    for (c9_i38 = 0; c9_i38 < 6; c9_i38++) {
      (*(real_T (*)[36])c9_outData)[c9_i38 + c9_i36] = c9_b_y[c9_i38 + c9_i36];
    }

    c9_i36 += 6;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_e_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_b_y[6])
{
  real_T c9_dv14[6];
  int32_T c9_i39;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv14, 1, 0, 0U, 1, 0U, 1, 6);
  for (c9_i39 = 0; c9_i39 < 6; c9_i39++) {
    c9_b_y[c9_i39] = c9_dv14[c9_i39];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_x3;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_b_y[6];
  int32_T c9_i40;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_x3 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_x3), &c9_thisId, c9_b_y);
  sf_mex_destroy(&c9_x3);
  for (c9_i40 = 0; c9_i40 < 6; c9_i40++) {
    (*(real_T (*)[6])c9_outData)[c9_i40] = c9_b_y[c9_i40];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  boolean_T c9_u;
  const mxArray *c9_b_y = NULL;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_f_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_b_y;
  boolean_T c9_b0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b0, 1, 11, 0U, 0, 0U, 0);
  c9_b_y = c9_b0;
  sf_mex_destroy(&c9_u);
  return c9_b_y;
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_cond3;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_b_y;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_cond3 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_cond3), &c9_thisId);
  sf_mex_destroy(&c9_cond3);
  *(boolean_T *)c9_outData = c9_b_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i41;
  const mxArray *c9_b_y = NULL;
  real_T c9_u[4];
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i41 = 0; c9_i41 < 4; c9_i41++) {
    c9_u[c9_i41] = (*(real_T (*)[4])c9_inData)[c9_i41];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static void c9_g_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_b_y[4])
{
  real_T c9_dv15[4];
  int32_T c9_i42;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv15, 1, 0, 0U, 1, 0U, 1, 4);
  for (c9_i42 = 0; c9_i42 < 4; c9_i42++) {
    c9_b_y[c9_i42] = c9_dv15[c9_i42];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_x2;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_b_y[4];
  int32_T c9_i43;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_x2 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_x2), &c9_thisId, c9_b_y);
  sf_mex_destroy(&c9_x2);
  for (c9_i43 = 0; c9_i43 < 4; c9_i43++) {
    (*(real_T (*)[4])c9_outData)[c9_i43] = c9_b_y[c9_i43];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i44;
  const mxArray *c9_b_y = NULL;
  real_T c9_u[4];
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i44 = 0; c9_i44 < 4; c9_i44++) {
    c9_u[c9_i44] = (*(real_T (*)[4])c9_inData)[c9_i44];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i45;
  int32_T c9_i46;
  const mxArray *c9_b_y = NULL;
  int32_T c9_i47;
  real_T c9_u[16];
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i45 = 0;
  for (c9_i46 = 0; c9_i46 < 4; c9_i46++) {
    for (c9_i47 = 0; c9_i47 < 4; c9_i47++) {
      c9_u[c9_i47 + c9_i45] = (*(real_T (*)[16])c9_inData)[c9_i47 + c9_i45];
    }

    c9_i45 += 4;
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_pendulumgui_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c9_nameCaptureInfo;
}

static real_T c9_mpower(SFc9_pendulumguiInstanceStruct *chartInstance, real_T
  c9_a)
{
  real_T c9_c;
  real_T c9_b_a;
  real_T c9_c_a;
  real_T c9_x;
  real_T c9_d_a;
  boolean_T c9_p;
  c9_b_a = c9_a;
  c9_c_a = c9_b_a;
  c9_x = c9_c_a;
  c9_d_a = c9_x;
  c9_c = c9_d_a * c9_d_a;
  c9_p = false;
  if (c9_p) {
    c9_error(chartInstance);
  }

  return c9_c;
}

static void c9_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_dimagree(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_error(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  const mxArray *c9_b_y = NULL;
  static char_T c9_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c9_b_y));
}

static real_T c9_cos(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x)
{
  real_T c9_b_x;
  c9_b_x = c9_x;
  c9_b_cos(chartInstance, &c9_b_x);
  return c9_b_x;
}

static real_T c9_sign(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x)
{
  real_T c9_b_x;
  c9_b_x = c9_x;
  c9_b_sign(chartInstance, &c9_b_x);
  return c9_b_x;
}

static void c9_b_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_c_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c9_sin(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x)
{
  real_T c9_b_x;
  c9_b_x = c9_x;
  c9_b_sin(chartInstance, &c9_b_x);
  return c9_b_x;
}

static real_T c9_abs(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x)
{
  real_T c9_b_x;
  real_T c9_c_x;
  (void)chartInstance;
  c9_b_x = c9_x;
  c9_c_x = c9_b_x;
  return muDoubleScalarAbs(c9_c_x);
}

static void c9_d_scalarEg(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c9_inv(SFc9_pendulumguiInstanceStruct *chartInstance, real_T c9_x)
{
  real_T c9_b_y;
  real_T c9_c_y;
  real_T c9_b_x;
  real_T c9_xinv;
  real_T c9_c_x;
  real_T c9_n1x;
  real_T c9_d_x;
  real_T c9_n1xinv;
  real_T c9_rc;
  real_T c9_e_x;
  boolean_T c9_b;
  real_T c9_f_x;
  const mxArray *c9_d_y = NULL;
  static char_T c9_rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  real_T c9_u;
  const mxArray *c9_e_y = NULL;
  char_T c9_str[14];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c9_c_y = c9_x;
  c9_b_y = 1.0 / c9_c_y;
  c9_b_x = c9_x;
  c9_xinv = c9_b_y;
  c9_c_x = c9_b_x;
  c9_n1x = c9_abs(chartInstance, c9_c_x);
  c9_d_x = c9_xinv;
  c9_n1xinv = c9_abs(chartInstance, c9_d_x);
  c9_rc = 1.0 / (c9_n1x * c9_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c9_n1x == 0.0) {
    guard2 = true;
  } else if (c9_n1xinv == 0.0) {
    guard2 = true;
  } else if (c9_rc == 0.0) {
    guard1 = true;
  } else {
    c9_e_x = c9_rc;
    c9_b = muDoubleScalarIsNaN(c9_e_x);
    guard3 = false;
    if (c9_b) {
      guard3 = true;
    } else {
      if (c9_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c9_f_x = c9_rc;
      c9_d_y = NULL;
      sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_rfmt, 10, 0U, 1U, 0U, 2, 1, 6),
                    false);
      c9_u = c9_f_x;
      c9_e_y = NULL;
      sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
      c9_h_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14,
        c9_d_y, 14, c9_e_y), "sprintf", c9_str);
      c9_b_warning(chartInstance, c9_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c9_warning(chartInstance);
  }

  return c9_b_y;
}

static void c9_warning(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  const mxArray *c9_b_y = NULL;
  static char_T c9_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c9_c_y = NULL;
  static char_T c9_b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c9_d_y = NULL;
  static char_T c9_msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  (void)chartInstance;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c9_b_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c9_c_y, 14, c9_d_y));
}

static void c9_b_warning(SFc9_pendulumguiInstanceStruct *chartInstance, char_T
  c9_varargin_1[14])
{
  const mxArray *c9_b_y = NULL;
  static char_T c9_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c9_c_y = NULL;
  static char_T c9_b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c9_d_y = NULL;
  static char_T c9_msgID[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i', 'o',
    'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *c9_e_y = NULL;
  (void)chartInstance;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_msgID, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    14), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c9_b_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    3U, 14, c9_c_y, 14, c9_d_y, 14, c9_e_y));
}

static void c9_h_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_sprintf, const char_T *c9_identifier, char_T c9_b_y[14])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_sprintf), &c9_thisId,
                        c9_b_y);
  sf_mex_destroy(&c9_sprintf);
}

static void c9_i_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, char_T c9_b_y[14])
{
  char_T c9_cv0[14];
  int32_T c9_i48;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv0, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c9_i48 = 0; c9_i48 < 14; c9_i48++) {
    c9_b_y[c9_i48] = c9_cv0[c9_i48];
  }

  sf_mex_destroy(&c9_u);
}

static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_b_y = NULL;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_b_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_j_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_b_y;
  int32_T c9_i49;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i49, 1, 6, 0U, 0, 0U, 0);
  c9_b_y = c9_i49;
  sf_mex_destroy(&c9_u);
  return c9_b_y;
}

static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_b_y;
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_y = c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_b_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_k_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_pendulumgui, const char_T
  *c9_identifier)
{
  uint8_T c9_b_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_y = c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_pendulumgui), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_pendulumgui);
  return c9_b_y;
}

static uint8_T c9_l_emlrt_marshallIn(SFc9_pendulumguiInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_b_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_b_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_b_y;
}

static void c9_b_cos(SFc9_pendulumguiInstanceStruct *chartInstance, real_T *c9_x)
{
  (void)chartInstance;
  *c9_x = muDoubleScalarCos(*c9_x);
}

static void c9_b_sign(SFc9_pendulumguiInstanceStruct *chartInstance, real_T
                      *c9_x)
{
  (void)chartInstance;
  *c9_x = muDoubleScalarSign(*c9_x);
}

static void c9_b_sin(SFc9_pendulumguiInstanceStruct *chartInstance, real_T *c9_x)
{
  (void)chartInstance;
  *c9_x = muDoubleScalarSin(*c9_x);
}

static real_T c9_get_n(SFc9_pendulumguiInstanceStruct *chartInstance, uint32_T
  c9_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c9_elementIndex);
  return *chartInstance->c9_n_address;
}

static void c9_set_n(SFc9_pendulumguiInstanceStruct *chartInstance, uint32_T
                     c9_elementIndex, real_T c9_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c9_elementIndex);
  *chartInstance->c9_n_address = c9_elementValue;
}

static real_T *c9_access_n(SFc9_pendulumguiInstanceStruct *chartInstance,
  uint32_T c9_rdOnly)
{
  real_T *c9_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c9_dsmAddr = chartInstance->c9_n_address;
  if (c9_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c9_dsmAddr;
}

static void init_dsm_address_info(SFc9_pendulumguiInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "n", (void **)
    &chartInstance->c9_n_address, &chartInstance->c9__index);
}

static void init_simulink_io_address(SFc9_pendulumguiInstanceStruct
  *chartInstance)
{
  chartInstance->c9_theta1 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_theta2 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_theta1_d = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_theta2_d = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_y = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c9_y_d = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c9_y_dd = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_E1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_E2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_time = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c9_n_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c9_u2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c9_selector = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c9_pendulumgui_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4118486559U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2569779022U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1348780554U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2133768405U);
}

mxArray* sf_c9_pendulumgui_get_post_codegen_info(void);
mxArray *sf_c9_pendulumgui_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4AyXGFOGeSMShhPSnfQFEE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c9_pendulumgui_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_pendulumgui_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_pendulumgui_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c9_pendulumgui_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_pendulumgui_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c9_pendulumgui(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[31],T\"E1\",},{M[1],M[30],T\"E2\",},{M[1],M[35],T\"n_out\",},{M[1],M[39],T\"u2\",},{M[1],M[29],T\"y_dd\",},{M[8],M[0],T\"is_active_c9_pendulumgui\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_pendulumgui_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_pendulumguiInstanceStruct *chartInstance =
      (SFc9_pendulumguiInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _pendulumguiMachineNumber_,
           9,
           1,
           1,
           0,
           14,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_pendulumguiMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_pendulumguiMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _pendulumguiMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"theta1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"theta2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"theta1_d");
          _SFD_SET_DATA_PROPS(3,1,1,0,"theta2_d");
          _SFD_SET_DATA_PROPS(4,1,1,0,"y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"y_d");
          _SFD_SET_DATA_PROPS(6,1,1,0,"time");
          _SFD_SET_DATA_PROPS(7,1,1,0,"selector");
          _SFD_SET_DATA_PROPS(8,2,0,1,"y_dd");
          _SFD_SET_DATA_PROPS(9,2,0,1,"E1");
          _SFD_SET_DATA_PROPS(10,2,0,1,"E2");
          _SFD_SET_DATA_PROPS(11,2,0,1,"n_out");
          _SFD_SET_DATA_PROPS(12,2,0,1,"u2");
          _SFD_SET_DATA_PROPS(13,11,0,0,"n");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,10,0,0,0,0,0,6,3);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4400);
        _SFD_CV_INIT_EML_IF(0,1,0,605,612,727,4394);
        _SFD_CV_INIT_EML_IF(0,1,1,694,706,-1,715);
        _SFD_CV_INIT_EML_IF(0,1,2,727,738,2445,4394);
        _SFD_CV_INIT_EML_IF(0,1,3,1880,1897,1943,2021);
        _SFD_CV_INIT_EML_IF(0,1,4,1943,1964,1978,2021);
        _SFD_CV_INIT_EML_IF(0,1,5,1978,1990,2004,2021);
        _SFD_CV_INIT_EML_IF(0,1,6,2278,2290,-1,2314);
        _SFD_CV_INIT_EML_IF(0,1,7,2341,2379,-1,2425);
        _SFD_CV_INIT_EML_IF(0,1,8,2445,2456,4340,4394);
        _SFD_CV_INIT_EML_IF(0,1,9,4271,4285,4301,4330);

        {
          static int condStart[] = { 1883, 1891 };

          static int condEnd[] = { 1889, 1897 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,1883,1897,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1950, 1958 };

          static int condEnd[] = { 1956, 1964 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1950,1964,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2344, 2362 };

          static int condEnd[] = { 2360, 2379 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,2344,2379,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,608,612,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,697,706,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,734,738,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,2281,2290,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,2344,2360,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,2362,2379,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,2452,2456,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,4274,4285,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _pendulumguiMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_pendulumguiInstanceStruct *chartInstance =
      (SFc9_pendulumguiInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_theta1);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c9_theta2);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_theta1_d);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_theta2_d);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_y);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_y_d);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c9_y_dd);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c9_E1);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c9_E2);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_time);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c9_n_address);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c9_n_out);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c9_u2);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c9_selector);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s4dcSyCan3LqybeI32m9ZMB";
}

static void sf_opaque_initialize_c9_pendulumgui(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_pendulumguiInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*)
    chartInstanceVar);
  initialize_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_pendulumgui(void *chartInstanceVar)
{
  enable_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_pendulumgui(void *chartInstanceVar)
{
  disable_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_pendulumgui(void *chartInstanceVar)
{
  sf_gateway_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_pendulumgui(SimStruct* S)
{
  return get_sim_state_c9_pendulumgui((SFc9_pendulumguiInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_pendulumgui(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c9_pendulumgui(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_pendulumguiInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_pendulumgui_optimization_info();
    }

    finalize_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_pendulumgui((SFc9_pendulumguiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_pendulumgui(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_pendulumgui((SFc9_pendulumguiInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c9_pendulumgui(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_pendulumgui_optimization_info(sim_mode_is_rtw_gen
      (S), sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 9);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4214650163U));
  ssSetChecksum1(S,(3715363472U));
  ssSetChecksum2(S,(993280576U));
  ssSetChecksum3(S,(3265496563U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c9_pendulumgui(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_pendulumgui(SimStruct *S)
{
  SFc9_pendulumguiInstanceStruct *chartInstance;
  chartInstance = (SFc9_pendulumguiInstanceStruct *)utMalloc(sizeof
    (SFc9_pendulumguiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc9_pendulumguiInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_pendulumgui;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c9_pendulumgui;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_pendulumgui;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_pendulumgui;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_pendulumgui;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c9_pendulumgui;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c9_pendulumgui;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_pendulumgui;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_pendulumgui;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_pendulumgui;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_pendulumgui;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c9_pendulumgui(chartInstance);
}

void c9_pendulumgui_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_pendulumgui(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_pendulumgui(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_pendulumgui(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_pendulumgui_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
