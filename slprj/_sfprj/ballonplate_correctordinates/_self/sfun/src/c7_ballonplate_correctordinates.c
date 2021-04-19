/* Include files */

#include "ballonplate_correctordinates_sfun.h"
#include "c7_ballonplate_correctordinates.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ballonplate_correctordinates_sfun_debug_macros.h"
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
static const char * c7_debug_family_names[27] = { "c1", "c2", "m", "r", "J", "k",
  "g", "xd_d", "xd_dd", "u_1", "u_2", "u_alpha", "nargin", "nargout", "x", "x2",
  "y", "alpha_d", "beta_d", "time", "sine_step", "A", "step_size", "frequency",
  "mod_sec", "u", "xd" };

/* Function Declarations */
static void initialize_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initialize_params_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void enable_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void disable_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void set_sim_state_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_st);
static void finalize_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void sf_gateway_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void mdl_start_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void c7_chartstep_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initSimStructsc7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_xd, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static real_T c7_sin(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c7_b_x);
static real_T c7_cos(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c7_b_x);
static void c7_scalarEg(SFc7_ballonplate_correctordinatesInstanceStruct
  *chartInstance);
static void c7_dimagree(SFc7_ballonplate_correctordinatesInstanceStruct
  *chartInstance);
static void c7_error(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance);
static void c7_b_error(SFc7_ballonplate_correctordinatesInstanceStruct
  *chartInstance);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_c_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_d_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_is_active_c7_ballonplate_correctordinates, const char_T *c7_identifier);
static uint8_T c7_e_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sin(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T *c7_b_x);
static void c7_b_cos(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T *c7_b_x);
static void init_dsm_address_info
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc7_ballonplate_correctordinates(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_ballonplate_correctordinates = 0U;
}

static void initialize_params_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_b_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  uint8_T c7_c_hoistedGlobal;
  uint8_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_createcellmatrix(3, 1), false);
  c7_hoistedGlobal = *chartInstance->c7_u;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_b_y, 0, c7_c_y);
  c7_b_hoistedGlobal = *chartInstance->c7_xd;
  c7_c_u = c7_b_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_b_y, 1, c7_d_y);
  c7_c_hoistedGlobal =
    chartInstance->c7_is_active_c7_ballonplate_correctordinates;
  c7_d_u = c7_c_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_b_y, 2, c7_e_y);
  sf_mex_assign(&c7_st, c7_b_y, false);
  return c7_st;
}

static void set_sim_state_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_st)
{
  const mxArray *c7_b_u;
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_b_u = sf_mex_dup(c7_st);
  *chartInstance->c7_u = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u", c7_b_u, 0)), "u");
  *chartInstance->c7_xd = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("xd", c7_b_u, 1)), "xd");
  chartInstance->c7_is_active_c7_ballonplate_correctordinates =
    c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c7_ballonplate_correctordinates", c7_b_u, 2)),
    "is_active_c7_ballonplate_correctordinates");
  sf_mex_destroy(&c7_b_u);
  c7_update_debugger_state_c7_ballonplate_correctordinates(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_mod_sec, 10U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_frequency, 9U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_step_size, 8U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_A, 7U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_sine_step, 6U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_time, 5U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_beta_d, 4U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_alpha_d, 3U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_y, 2U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_x2, 1U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_x, 0U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_ballonplate_correctordinates(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ballonplate_correctordinatesMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_u, 11U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_xd, 12U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
}

static void mdl_start_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_chartstep_c7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_hoistedGlobal;
  real_T c7_d_hoistedGlobal;
  real_T c7_e_hoistedGlobal;
  real_T c7_f_hoistedGlobal;
  real_T c7_g_hoistedGlobal;
  real_T c7_h_hoistedGlobal;
  real_T c7_i_hoistedGlobal;
  real_T c7_j_hoistedGlobal;
  real_T c7_k_hoistedGlobal;
  real_T c7_b_x;
  real_T c7_b_x2;
  real_T c7_b_y;
  real_T c7_b_alpha_d;
  real_T c7_b_beta_d;
  real_T c7_b_time;
  real_T c7_b_sine_step;
  real_T c7_b_A;
  real_T c7_b_step_size;
  real_T c7_b_frequency;
  real_T c7_b_mod_sec;
  uint32_T c7_debug_family_var_map[27];
  real_T c7_c1;
  real_T c7_c2;
  real_T c7_m;
  real_T c7_r;
  real_T c7_J;
  real_T c7_k;
  real_T c7_g;
  real_T c7_xd_d;
  real_T c7_xd_dd;
  real_T c7_u_1;
  real_T c7_u_2;
  real_T c7_u_alpha;
  real_T c7_nargin = 11.0;
  real_T c7_nargout = 2.0;
  real_T c7_b_u;
  real_T c7_b_xd;
  real_T c7_d0;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_a;
  real_T c7_b_a;
  real_T c7_c_a;
  real_T c7_c_x;
  real_T c7_d4;
  real_T c7_d_x;
  real_T c7_e_x;
  real_T c7_d_a;
  real_T c7_c;
  boolean_T c7_p;
  real_T c7_c_A;
  real_T c7_f_x;
  real_T c7_g_x;
  real_T c7_d_A;
  real_T c7_h_x;
  real_T c7_i_x;
  real_T c7_j_x;
  real_T c7_k_x;
  boolean_T c7_b0;
  boolean_T c7_b1;
  boolean_T c7_b2;
  boolean_T c7_b_p;
  real_T c7_l_x;
  real_T c7_m_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *chartInstance->c7_x;
  c7_b_hoistedGlobal = *chartInstance->c7_x2;
  c7_c_hoistedGlobal = *chartInstance->c7_y;
  c7_d_hoistedGlobal = *chartInstance->c7_alpha_d;
  c7_e_hoistedGlobal = *chartInstance->c7_beta_d;
  c7_f_hoistedGlobal = *chartInstance->c7_time;
  c7_g_hoistedGlobal = *chartInstance->c7_sine_step;
  c7_h_hoistedGlobal = *chartInstance->c7_A;
  c7_i_hoistedGlobal = *chartInstance->c7_step_size;
  c7_j_hoistedGlobal = *chartInstance->c7_frequency;
  c7_k_hoistedGlobal = *chartInstance->c7_mod_sec;
  c7_b_x = c7_hoistedGlobal;
  c7_b_x2 = c7_b_hoistedGlobal;
  c7_b_y = c7_c_hoistedGlobal;
  c7_b_alpha_d = c7_d_hoistedGlobal;
  c7_b_beta_d = c7_e_hoistedGlobal;
  c7_b_time = c7_f_hoistedGlobal;
  c7_b_sine_step = c7_g_hoistedGlobal;
  c7_b_A = c7_h_hoistedGlobal;
  c7_b_step_size = c7_i_hoistedGlobal;
  c7_b_frequency = c7_j_hoistedGlobal;
  c7_b_mod_sec = c7_k_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 27U, 27U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c1, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c2, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_m, 2U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_r, 3U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_J, 4U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_k, 5U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_g, 6U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_xd_d, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_xd_dd, 8U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_u_1, 9U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_u_2, 10U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_u_alpha, 11U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 12U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 13U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_x, 14U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_x2, 15U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_y, 16U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_alpha_d, 17U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_beta_d, 18U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_time, 19U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_sine_step, 20U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_A, 21U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_step_size, 22U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_frequency, 23U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_mod_sec, 24U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_u, 25U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_xd, 26U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 2);
  c7_c1 = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 3);
  c7_c2 = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c7_b_sine_step, 1.0, -1,
        4U, c7_b_sine_step > 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
    c7_c1 = 3.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
    c7_c2 = 3.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_m = 0.263;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  c7_r = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  c7_J = 4.208E-5;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
  c7_k = 0.7142857142857143;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_g = -9.8;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 13);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c7_b_mod_sec, 0.0, -1, 0U,
        c7_b_mod_sec == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
    if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c7_b_sine_step, 1.0, -1,
          0U, c7_b_sine_step == 1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
      c7_b_xd = c7_b_step_size;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
      c7_xd_d = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
      c7_xd_dd = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
      if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c7_b_sine_step, 2.0,
            -1, 0U, c7_b_sine_step == 2.0))) {
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 19);
        c7_d1 = c7_b_frequency * c7_b_time;
        c7_b_sin(chartInstance, &c7_d1);
        c7_b_xd = c7_b_A * c7_d1;
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
        c7_d3 = c7_b_frequency * c7_b_time;
        c7_b_cos(chartInstance, &c7_d3);
        c7_xd_d = c7_b_A * 0.5 * c7_d3;
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 21);
        c7_d4 = c7_b_frequency * c7_b_time;
        c7_b_sin(chartInstance, &c7_d4);
        c7_xd_dd = -c7_b_A * c7_b_A * 0.5 * 0.5 * c7_d4;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 23);
        c7_d0 = c7_b_frequency * c7_b_time;
        c7_b_cos(chartInstance, &c7_d0);
        c7_b_xd = c7_b_A * c7_d0;
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 24);
        c7_d2 = c7_b_frequency * c7_b_time;
        c7_b_sin(chartInstance, &c7_d2);
        c7_xd_d = -c7_b_A * 0.5 * c7_d2;
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 25);
        c7_c_x = c7_b_frequency * c7_b_time;
        c7_e_x = c7_c_x;
        c7_e_x = muDoubleScalarCos(c7_e_x);
        c7_xd_dd = -c7_b_A * c7_b_A * 0.5 * 0.5 * c7_e_x;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
    c7_a = c7_b_alpha_d;
    c7_b_a = c7_a;
    c7_c_a = c7_b_a;
    c7_d_x = c7_c_a;
    c7_d_a = c7_d_x;
    c7_c = c7_d_a * c7_d_a;
    c7_p = false;
    if (c7_p) {
      c7_error(chartInstance);
    }

    c7_u_1 = c7_b_x * c7_c;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 28);
    c7_u_1 += c7_b_alpha_d * c7_b_beta_d * c7_b_y;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 29);
    c7_u_2 = 1.0 + c7_c1 * c7_c2;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 30);
    c7_u_2 *= c7_b_x - c7_b_xd;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 31);
    c7_u_2 = (c7_u_2 + (c7_c1 + c7_c2) * (c7_b_x2 - c7_xd_d)) - c7_xd_dd;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 32);
    c7_c_A = c7_u_2;
    c7_f_x = c7_c_A;
    c7_g_x = c7_f_x;
    c7_u_2 = c7_g_x / 0.7142857142857143;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 33);
    c7_u_alpha = c7_u_1 + c7_u_2;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 34);
    c7_d_A = c7_u_alpha;
    c7_h_x = c7_d_A;
    c7_i_x = c7_h_x;
    c7_u_alpha = c7_i_x / -9.8;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 53);
    c7_j_x = c7_u_alpha;
    c7_b_u = c7_j_x;
    c7_k_x = c7_b_u;
    c7_b0 = (c7_k_x < -1.0);
    c7_b1 = (c7_k_x > 1.0);
    c7_b2 = (c7_b0 || c7_b1);
    c7_b_p = c7_b2;
    if (c7_b_p) {
      c7_b_error(chartInstance);
    }

    c7_l_x = c7_b_u;
    c7_b_u = c7_l_x;
    c7_m_x = c7_b_u;
    c7_b_u = c7_m_x;
    c7_b_u = muDoubleScalarAsin(c7_b_u);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 60);
    c7_b_u = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 61);
    c7_b_xd = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -61);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c7_u = c7_b_u;
  *chartInstance->c7_xd = c7_b_xd;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_ballonplate_correctordinates
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc7_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_b_u = *(real_T *)c7_inData;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_xd, const char_T *c7_identifier)
{
  real_T c7_b_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_xd), &c7_thisId);
  sf_mex_destroy(&c7_b_xd);
  return c7_b_y;
}

static real_T c7_b_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_b_y;
  real_T c7_d5;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_b_u), &c7_d5, 1, 0, 0U, 0, 0U, 0);
  c7_b_y = c7_d5;
  sf_mex_destroy(&c7_b_u);
  return c7_b_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_xd;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_b_y;
  SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc7_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c7_b_xd = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_xd), &c7_thisId);
  sf_mex_destroy(&c7_b_xd);
  *(real_T *)c7_outData = c7_b_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray
  *sf_c7_ballonplate_correctordinates_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static real_T c7_sin(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c7_b_x)
{
  real_T c7_c_x;
  c7_c_x = c7_b_x;
  c7_b_sin(chartInstance, &c7_c_x);
  return c7_c_x;
}

static real_T c7_cos(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c7_b_x)
{
  real_T c7_c_x;
  c7_c_x = c7_b_x;
  c7_b_cos(chartInstance, &c7_c_x);
  return c7_c_x;
}

static void c7_scalarEg(SFc7_ballonplate_correctordinatesInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_dimagree(SFc7_ballonplate_correctordinatesInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_error(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance)
{
  const mxArray *c7_b_y = NULL;
  static char_T c7_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c7_b_y));
}

static void c7_b_error(SFc7_ballonplate_correctordinatesInstanceStruct
  *chartInstance)
{
  const mxArray *c7_b_y = NULL;
  static char_T c7_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c7_c_y = NULL;
  static char_T c7_c_u[4] = { 'a', 's', 'i', 'n' };

  (void)chartInstance;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c7_b_y, 14, c7_c_y));
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc7_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_b_u = *(int32_T *)c7_inData;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_c_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_b_y;
  int32_T c7_i0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_b_u), &c7_i0, 1, 6, 0U, 0, 0U, 0);
  c7_b_y = c7_i0;
  sf_mex_destroy(&c7_b_u);
  return c7_b_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_b_y;
  SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc7_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_b_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_d_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_is_active_c7_ballonplate_correctordinates, const char_T *c7_identifier)
{
  uint8_T c7_b_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_ballonplate_correctordinates), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_ballonplate_correctordinates);
  return c7_b_y;
}

static uint8_T c7_e_emlrt_marshallIn
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c7_b_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_b_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_b_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_b_y = c7_u0;
  sf_mex_destroy(&c7_b_u);
  return c7_b_y;
}

static void c7_b_sin(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T *c7_b_x)
{
  (void)chartInstance;
  *c7_b_x = muDoubleScalarSin(*c7_b_x);
}

static void c7_b_cos(SFc7_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T *c7_b_x)
{
  (void)chartInstance;
  *c7_b_x = muDoubleScalarCos(*c7_b_x);
}

static void init_dsm_address_info
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  chartInstance->c7_u = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c7_x = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c7_x2 = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c7_y = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c7_alpha_d = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_beta_d = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c7_time = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c7_xd = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_sine_step = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c7_A = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    7);
  chartInstance->c7_step_size = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c7_frequency = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c7_mod_sec = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
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

void sf_c7_ballonplate_correctordinates_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4103797089U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3981925467U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2875170006U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1665118435U);
}

mxArray* sf_c7_ballonplate_correctordinates_get_post_codegen_info(void);
mxArray *sf_c7_ballonplate_correctordinates_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dF81PSunmCkIMDHqdpOMwF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c7_ballonplate_correctordinates_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_ballonplate_correctordinates_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_ballonplate_correctordinates_jit_fallback_info(void)
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

mxArray *sf_c7_ballonplate_correctordinates_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_ballonplate_correctordinates_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c7_ballonplate_correctordinates(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"u\",},{M[1],M[18],T\"xd\",},{M[8],M[0],T\"is_active_c7_ballonplate_correctordinates\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_ballonplate_correctordinates_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc7_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ballonplate_correctordinatesMachineNumber_,
           7,
           1,
           1,
           0,
           13,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_ballonplate_correctordinatesMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ballonplate_correctordinatesMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ballonplate_correctordinatesMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"alpha_d");
          _SFD_SET_DATA_PROPS(4,1,1,0,"beta_d");
          _SFD_SET_DATA_PROPS(5,1,1,0,"time");
          _SFD_SET_DATA_PROPS(6,1,1,0,"sine_step");
          _SFD_SET_DATA_PROPS(7,1,1,0,"A");
          _SFD_SET_DATA_PROPS(8,1,1,0,"step_size");
          _SFD_SET_DATA_PROPS(9,1,1,0,"frequency");
          _SFD_SET_DATA_PROPS(10,1,1,0,"mod_sec");
          _SFD_SET_DATA_PROPS(11,2,0,1,"u");
          _SFD_SET_DATA_PROPS(12,2,0,1,"xd");
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
        _SFD_CV_INIT_EML(0,1,1,0,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1084);
        _SFD_CV_INIT_EML_IF(0,1,0,106,120,-1,144);
        _SFD_CV_INIT_EML_IF(0,1,1,212,225,1052,1079);
        _SFD_CV_INIT_EML_IF(0,1,2,226,242,292,553);
        _SFD_CV_INIT_EML_IF(0,1,3,292,311,428,553);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,109,120,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,215,225,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,229,242,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,299,311,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ballonplate_correctordinatesMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc7_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c7_u);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c7_x);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c7_x2);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c7_y);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c7_alpha_d);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c7_beta_d);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c7_time);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c7_xd);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c7_sine_step);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c7_A);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c7_step_size);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c7_frequency);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c7_mod_sec);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sutus1XhpTjH4KFaOZJ5zNB";
}

static void sf_opaque_initialize_c7_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_ballonplate_correctordinatesInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
  initialize_c7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  enable_c7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  disable_c7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  sf_gateway_c7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_ballonplate_correctordinates
  (SimStruct* S)
{
  return get_sim_state_c7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_ballonplate_correctordinates(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct*)sf_get_chart_instance_ptr
     (S), st);
}

static void sf_opaque_terminate_c7_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_ballonplate_correctordinatesInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ballonplate_correctordinates_optimization_info();
    }

    finalize_c7_ballonplate_correctordinates
      ((SFc7_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_ballonplate_correctordinates
    ((SFc7_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_ballonplate_correctordinates(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_ballonplate_correctordinates
      ((SFc7_ballonplate_correctordinatesInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c7_ballonplate_correctordinates(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ballonplate_correctordinates_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 7);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,11);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 11; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(305461782U));
  ssSetChecksum1(S,(1535927311U));
  ssSetChecksum2(S,(831850660U));
  ssSetChecksum3(S,(2421209097U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_ballonplate_correctordinates(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_ballonplate_correctordinates(SimStruct *S)
{
  SFc7_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc7_ballonplate_correctordinatesInstanceStruct *)utMalloc
    (sizeof(SFc7_ballonplate_correctordinatesInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc7_ballonplate_correctordinatesInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_ballonplate_correctordinates;
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
  mdl_start_c7_ballonplate_correctordinates(chartInstance);
}

void c7_ballonplate_correctordinates_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_ballonplate_correctordinates(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_ballonplate_correctordinates_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
