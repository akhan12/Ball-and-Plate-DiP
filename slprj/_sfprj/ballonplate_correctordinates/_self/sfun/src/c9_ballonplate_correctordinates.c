/* Include files */

#include "ballonplate_correctordinates_sfun.h"
#include "c9_ballonplate_correctordinates.h"
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
static const char * c9_debug_family_names[44] = { "local_pos", "ball_position",
  "local_vel", "ball_velocity", "J_sphere", "J_sphere_inv", "ball_momentum",
  "m_ground_inv", "J_ground_inv", "N", "contact_Point", "r_ball", "kA", "kB",
  "uA", "uB", "numer", "denom", "f", "impulse", "initial_velocity_temp",
  "a_para", "b_para", "turning_time", "toler", "turning_point", "nargin",
  "nargout", "t", "bp_x", "bp_y", "bp_z", "bv_x", "bv_y", "bv_z", "x_vec",
  "y_vec", "init_reset", "m", "r", "rest", "ball_position_new", "reset",
  "pos_reset" };

static const char * c9_b_debug_family_names[10] = { "z_vec", "nargin", "nargout",
  "x_vec", "y_vec", "x", "y", "z", "local", "world" };

static const char * c9_c_debug_family_names[9] = { "z_vec", "nargin", "nargout",
  "x_vec", "y_vec", "x", "y", "z", "world" };

/* Function Declarations */
static void initialize_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initialize_params_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void enable_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void disable_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void set_sim_state_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_st);
static void finalize_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void sf_gateway_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void mdl_start_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void c9_chartstep_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initSimStructsc9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void c9_coordinate_transform
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, real_T
   c9_b_x_vec[3], real_T c9_b_y_vec[3], real_T c9_x, real_T c9_y, real_T c9_z,
   real_T c9_local[3], real_T c9_world[3]);
static void c9_coordinate_transform_l_w
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, real_T
   c9_b_x_vec[3], real_T c9_b_y_vec[3], real_T c9_x, real_T c9_y, real_T c9_z,
   real_T c9_world[3]);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_b_pos_reset, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_b_ball_position_new, const char_T *c9_identifier, real_T c9_y[3]);
static void c9_d_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_f_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9]);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_cross(SFc9_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c9_a[3], real_T c9_b[3], real_T
                     c9_c[3]);
static void c9_mldivide(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, real_T c9_A[9], real_T c9_B[3], real_T c9_Y[3]);
static real_T c9_abs(SFc9_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c9_x);
static void c9_warning(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance);
static void c9_scalarEg(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance);
static void c9_b_scalarEg(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance);
static real_T c9_dot(SFc9_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c9_a[3], real_T c9_b[3]);
static void c9_c_scalarEg(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_g_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_h_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_b_is_active_c9_ballonplate_correctordinates, const char_T *c9_identifier);
static uint8_T c9_i_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static real_T c9_get_count_mm(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex);
static void c9_set_count_mm(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex, real_T c9_elementValue);
static real_T *c9_access_count_mm
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_rdOnly);
static real_T c9_get_gravity(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex);
static void c9_set_gravity(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex, real_T c9_elementValue);
static real_T *c9_access_gravity(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_rdOnly);
static real_T c9_get_initial_position
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex);
static void c9_set_initial_position
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex, real_T c9_elementValue);
static real_T *c9_access_initial_position
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_rdOnly);
static real_T c9_get_initial_velocity
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex);
static void c9_set_initial_velocity
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex, real_T c9_elementValue);
static real_T *c9_access_initial_velocity
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_rdOnly);
static void init_dsm_address_info
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc9_ballonplate_correctordinates(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_ballonplate_correctordinates = 0U;
}

static void initialize_params_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  const mxArray *c9_b_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_d_y = NULL;
  uint8_T c9_c_hoistedGlobal;
  uint8_T c9_c_u;
  const mxArray *c9_e_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(4, 1), false);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", *chartInstance->c9_ball_position_new,
    0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = *chartInstance->c9_pos_reset;
  c9_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_b_hoistedGlobal = *chartInstance->c9_reset;
  c9_b_u = c9_b_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_c_hoistedGlobal =
    chartInstance->c9_is_active_c9_ballonplate_correctordinates;
  c9_c_u = c9_c_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[3];
  int32_T c9_i0;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "ball_position_new", c9_u, 0)), "ball_position_new", c9_dv0);
  for (c9_i0 = 0; c9_i0 < 3; c9_i0++) {
    (*chartInstance->c9_ball_position_new)[c9_i0] = c9_dv0[c9_i0];
  }

  *chartInstance->c9_pos_reset = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("pos_reset", c9_u, 1)), "pos_reset");
  *chartInstance->c9_reset = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("reset", c9_u, 2)), "reset");
  chartInstance->c9_is_active_c9_ballonplate_correctordinates =
    c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c9_ballonplate_correctordinates", c9_u, 3)),
    "is_active_c9_ballonplate_correctordinates");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_ballonplate_correctordinates(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_i3;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_rest, 12U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_r, 11U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_m, 10U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_init_reset, 9U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  for (c9_i1 = 0; c9_i1 < 3; c9_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_y_vec)[c9_i1], 8U, 1U, 0U,
                          chartInstance->c9_sfEvent, false);
  }

  for (c9_i2 = 0; c9_i2 < 3; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_x_vec)[c9_i2], 7U, 1U, 0U,
                          chartInstance->c9_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_bv_z, 6U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_bv_y, 5U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_bv_x, 4U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_bp_z, 3U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_bp_y, 2U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_bp_x, 1U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_t, 0U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_ballonplate_correctordinates(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ballonplate_correctordinatesMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_ball_position_new)[c9_i3], 13U, 1U,
                          0U, chartInstance->c9_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_reset, 14U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_pos_reset, 15U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
}

static void mdl_start_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_chartstep_c9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_e_hoistedGlobal;
  real_T c9_f_hoistedGlobal;
  real_T c9_g_hoistedGlobal;
  real_T c9_h_hoistedGlobal;
  real_T c9_i_hoistedGlobal;
  real_T c9_j_hoistedGlobal;
  real_T c9_k_hoistedGlobal;
  real_T c9_b_t;
  real_T c9_b_bp_x;
  real_T c9_b_bp_y;
  real_T c9_b_bp_z;
  real_T c9_b_bv_x;
  real_T c9_b_bv_y;
  real_T c9_b_bv_z;
  int32_T c9_i4;
  int32_T c9_i5;
  real_T c9_b_x_vec[3];
  real_T c9_b_init_reset;
  real_T c9_b_y_vec[3];
  real_T c9_b_m;
  real_T c9_b_r;
  real_T c9_b_rest;
  uint32_T c9_debug_family_var_map[44];
  real_T c9_local_pos[3];
  real_T c9_ball_position[3];
  real_T c9_local_vel[3];
  real_T c9_ball_velocity[3];
  real_T c9_J_sphere[9];
  real_T c9_J_sphere_inv[9];
  real_T c9_ball_momentum[3];
  real_T c9_m_ground_inv;
  real_T c9_J_ground_inv;
  real_T c9_N[3];
  real_T c9_contact_Point[3];
  real_T c9_r_ball[3];
  real_T c9_kA[3];
  real_T c9_kB[3];
  real_T c9_uA[3];
  real_T c9_uB[3];
  real_T c9_numer;
  real_T c9_denom;
  real_T c9_f;
  real_T c9_impulse[3];
  real_T c9_initial_velocity_temp[3];
  real_T c9_a_para;
  real_T c9_b_para;
  real_T c9_turning_time;
  real_T c9_toler;
  real_T c9_turning_point;
  real_T c9_nargin = 13.0;
  real_T c9_nargout = 3.0;
  real_T c9_b_ball_position_new[3];
  real_T c9_b_reset;
  real_T c9_b_pos_reset;
  int32_T c9_i6;
  int32_T c9_i7;
  real_T c9_c_x_vec[3];
  real_T c9_c_y_vec[3];
  real_T c9_b_local_pos[3];
  real_T c9_unusedU0[3];
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  real_T c9_d_x_vec[3];
  real_T c9_d_y_vec[3];
  int32_T c9_i12;
  int32_T c9_i13;
  real_T c9_a;
  int32_T c9_i14;
  static real_T c9_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c9_B;
  real_T c9_y;
  real_T c9_b_y;
  int32_T c9_i15;
  int32_T c9_i16;
  static real_T c9_A[9] = { 2.5, 0.0, 0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 2.5 };

  real_T c9_b_a;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  static real_T c9_b_b[3] = { 0.0, 0.0, 1.0 };

  real_T c9_b_ball_position[3];
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  real_T c9_b_r_ball[3];
  real_T c9_c_b[3];
  real_T c9_dv1[3];
  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  real_T c9_c_a[9];
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  int32_T c9_i33;
  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  int32_T c9_i37;
  real_T c9_d_b[3];
  real_T c9_b_ball_velocity[3];
  real_T c9_b_B;
  real_T c9_c_y;
  real_T c9_d_y;
  real_T c9_e_y;
  int32_T c9_i38;
  int32_T c9_i39;
  real_T c9_b_kA[3];
  real_T c9_b_uA[3];
  real_T c9_b_A;
  real_T c9_c_B;
  real_T c9_x;
  real_T c9_f_y;
  real_T c9_b_x;
  real_T c9_g_y;
  real_T c9_d_a;
  int32_T c9_i40;
  int32_T c9_i41;
  int32_T c9_i42;
  real_T c9_d_B;
  real_T c9_h_y;
  real_T c9_i_y;
  int32_T c9_i43;
  int32_T c9_i44;
  int32_T c9_i45;
  real_T c9_e_x_vec[3];
  real_T c9_e_y_vec[3];
  real_T c9_dv2[3];
  int32_T c9_i46;
  real_T c9_c_A;
  real_T c9_e_B;
  real_T c9_c_x;
  real_T c9_j_y;
  real_T c9_d_x;
  real_T c9_k_y;
  int32_T c9_i47;
  int32_T c9_i48;
  int32_T c9_i49;
  int32_T c9_i50;
  real_T c9_f_x_vec[3];
  real_T c9_f_y_vec[3];
  real_T c9_dv3[3];
  int32_T c9_i51;
  int32_T c9_i52;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *chartInstance->c9_t;
  c9_b_hoistedGlobal = *chartInstance->c9_bp_x;
  c9_c_hoistedGlobal = *chartInstance->c9_bp_y;
  c9_d_hoistedGlobal = *chartInstance->c9_bp_z;
  c9_e_hoistedGlobal = *chartInstance->c9_bv_x;
  c9_f_hoistedGlobal = *chartInstance->c9_bv_y;
  c9_g_hoistedGlobal = *chartInstance->c9_bv_z;
  c9_h_hoistedGlobal = *chartInstance->c9_init_reset;
  c9_i_hoistedGlobal = *chartInstance->c9_m;
  c9_j_hoistedGlobal = *chartInstance->c9_r;
  c9_k_hoistedGlobal = *chartInstance->c9_rest;
  c9_b_t = c9_hoistedGlobal;
  c9_b_bp_x = c9_b_hoistedGlobal;
  c9_b_bp_y = c9_c_hoistedGlobal;
  c9_b_bp_z = c9_d_hoistedGlobal;
  c9_b_bv_x = c9_e_hoistedGlobal;
  c9_b_bv_y = c9_f_hoistedGlobal;
  c9_b_bv_z = c9_g_hoistedGlobal;
  for (c9_i4 = 0; c9_i4 < 3; c9_i4++) {
    c9_b_x_vec[c9_i4] = (*chartInstance->c9_x_vec)[c9_i4];
  }

  for (c9_i5 = 0; c9_i5 < 3; c9_i5++) {
    c9_b_y_vec[c9_i5] = (*chartInstance->c9_y_vec)[c9_i5];
  }

  c9_b_init_reset = c9_h_hoistedGlobal;
  c9_b_m = c9_i_hoistedGlobal;
  c9_b_r = c9_j_hoistedGlobal;
  c9_b_rest = c9_k_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 44U, 44U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_local_pos, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_ball_position, 1U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_local_vel, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_ball_velocity, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_J_sphere, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_J_sphere_inv, 5U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_ball_momentum, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_m_ground_inv, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_J_ground_inv, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_N, 9U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_contact_Point, 10U,
    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_r_ball, 11U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_kA, 12U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_kB, 13U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_uA, 14U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_uB, 15U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_numer, 16U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_denom, 17U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f, 18U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_impulse, 19U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_initial_velocity_temp, 20U,
    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_a_para, 21U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_para, 22U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_turning_time, 23U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_toler, 24U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_turning_point, 25U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 26U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 27U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_t, 28U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_bp_x, 29U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_bp_y, 30U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_bp_z, 31U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_bv_x, 32U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_bv_y, 33U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_bv_z, 34U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_x_vec, 35U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_y_vec, 36U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_init_reset, 37U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_m, 38U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_r, 39U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_rest, 40U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_ball_position_new, 41U,
    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_reset, 42U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_pos_reset, 43U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  for (c9_i6 = 0; c9_i6 < 3; c9_i6++) {
    c9_c_x_vec[c9_i6] = c9_b_x_vec[c9_i6];
  }

  for (c9_i7 = 0; c9_i7 < 3; c9_i7++) {
    c9_c_y_vec[c9_i7] = c9_b_y_vec[c9_i7];
  }

  c9_coordinate_transform(chartInstance, c9_c_x_vec, c9_c_y_vec, c9_b_bp_x,
    c9_b_bp_y, c9_b_bp_z, c9_b_local_pos, c9_unusedU0);
  for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
    c9_local_pos[c9_i8] = c9_b_local_pos[c9_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i9 = 0; c9_i9 < 3; c9_i9++) {
    c9_ball_position[c9_i9] = c9_local_pos[c9_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i10 = 0; c9_i10 < 3; c9_i10++) {
    c9_d_x_vec[c9_i10] = c9_b_x_vec[c9_i10];
  }

  for (c9_i11 = 0; c9_i11 < 3; c9_i11++) {
    c9_d_y_vec[c9_i11] = c9_b_y_vec[c9_i11];
  }

  c9_coordinate_transform(chartInstance, c9_d_x_vec, c9_d_y_vec, c9_b_bv_x,
    c9_b_bv_y, c9_b_bv_z, c9_b_local_pos, c9_unusedU0);
  for (c9_i12 = 0; c9_i12 < 3; c9_i12++) {
    c9_local_vel[c9_i12] = c9_b_local_pos[c9_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i13 = 0; c9_i13 < 3; c9_i13++) {
    c9_ball_velocity[c9_i13] = c9_local_vel[c9_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_b_ball_position_new[0] = c9_b_bp_x;
  c9_b_ball_position_new[1] = c9_b_bp_y;
  c9_b_ball_position_new[2] = c9_b_bp_z;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 13);
  guard2 = false;
  guard3 = false;
  guard4 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c9_ball_position[2],
        3.0, -1, 3U, c9_ball_position[2] <= 3.0))) {
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c9_b_t, 0.0, -1, 4U,
          c9_b_t > 0.0))) {
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c9_get_gravity
            (chartInstance, 0), 0.0, -1, 1U, c9_get_gravity(chartInstance, 0) !=
            0.0))) {
        if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c9_b_init_reset,
              0.0, -1, 1U, c9_b_init_reset != 0.0))) {
          CV_EML_MCDC(0, 1, 0, true);
          CV_EML_IF(0, 1, 0, true);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
          c9_b_reset = 1.0;
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
          c9_b_pos_reset = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
          c9_a = 0.4 * c9_b_m * c9_b_r * c9_b_r;
          for (c9_i14 = 0; c9_i14 < 9; c9_i14++) {
            c9_J_sphere[c9_i14] = c9_a * c9_b[c9_i14];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 19);
          c9_B = c9_b_m * c9_b_r * c9_b_r;
          c9_y = c9_B;
          c9_b_y = c9_y;
          for (c9_i16 = 0; c9_i16 < 9; c9_i16++) {
            c9_J_sphere_inv[c9_i16] = c9_A[c9_i16] / c9_b_y;
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
          c9_b_a = c9_b_m;
          for (c9_i17 = 0; c9_i17 < 3; c9_i17++) {
            c9_b_local_pos[c9_i17] = c9_ball_velocity[c9_i17];
          }

          for (c9_i18 = 0; c9_i18 < 3; c9_i18++) {
            c9_ball_momentum[c9_i18] = c9_b_a * c9_b_local_pos[c9_i18];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 23);
          c9_m_ground_inv = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 24);
          c9_J_ground_inv = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 25);
          for (c9_i19 = 0; c9_i19 < 3; c9_i19++) {
            c9_N[c9_i19] = c9_b_b[c9_i19];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
          c9_b_ball_position[0] = c9_ball_position[0];
          c9_b_ball_position[1] = c9_ball_position[1];
          c9_b_ball_position[2] = c9_ball_position[2] - c9_b_r;
          for (c9_i20 = 0; c9_i20 < 3; c9_i20++) {
            c9_contact_Point[c9_i20] = c9_b_ball_position[c9_i20];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 28);
          for (c9_i21 = 0; c9_i21 < 3; c9_i21++) {
            c9_r_ball[c9_i21] = c9_contact_Point[c9_i21] -
              c9_ball_position[c9_i21];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 31);
          for (c9_i22 = 0; c9_i22 < 3; c9_i22++) {
            c9_b_r_ball[c9_i22] = c9_r_ball[c9_i22];
          }

          for (c9_i23 = 0; c9_i23 < 3; c9_i23++) {
            c9_c_b[c9_i23] = c9_b_b[c9_i23];
          }

          c9_cross(chartInstance, c9_b_r_ball, c9_c_b, c9_dv1);
          for (c9_i24 = 0; c9_i24 < 3; c9_i24++) {
            c9_kA[c9_i24] = c9_dv1[c9_i24];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 33);
          for (c9_i25 = 0; c9_i25 < 3; c9_i25++) {
            c9_kB[c9_i25] = 0.0;
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 34);
          for (c9_i26 = 0; c9_i26 < 9; c9_i26++) {
            c9_c_a[c9_i26] = c9_J_sphere_inv[c9_i26];
          }

          for (c9_i27 = 0; c9_i27 < 3; c9_i27++) {
            c9_b_local_pos[c9_i27] = c9_kA[c9_i27];
          }

          for (c9_i28 = 0; c9_i28 < 3; c9_i28++) {
            c9_uA[c9_i28] = 0.0;
          }

          for (c9_i29 = 0; c9_i29 < 3; c9_i29++) {
            c9_uA[c9_i29] = 0.0;
          }

          for (c9_i30 = 0; c9_i30 < 3; c9_i30++) {
            c9_unusedU0[c9_i30] = c9_uA[c9_i30];
          }

          for (c9_i31 = 0; c9_i31 < 3; c9_i31++) {
            c9_uA[c9_i31] = c9_unusedU0[c9_i31];
          }

          for (c9_i32 = 0; c9_i32 < 3; c9_i32++) {
            c9_uA[c9_i32] = 0.0;
            c9_i34 = 0;
            for (c9_i35 = 0; c9_i35 < 3; c9_i35++) {
              c9_uA[c9_i32] += c9_c_a[c9_i34 + c9_i32] * c9_b_local_pos[c9_i35];
              c9_i34 += 3;
            }
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 35);
          for (c9_i33 = 0; c9_i33 < 3; c9_i33++) {
            c9_uB[c9_i33] = 0.0;
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 37);
          for (c9_i36 = 0; c9_i36 < 3; c9_i36++) {
            c9_d_b[c9_i36] = c9_b_b[c9_i36];
          }

          for (c9_i37 = 0; c9_i37 < 3; c9_i37++) {
            c9_b_ball_velocity[c9_i37] = c9_ball_velocity[c9_i37];
          }

          c9_numer = -(1.0 + c9_b_rest) * c9_dot(chartInstance, c9_d_b,
            c9_b_ball_velocity);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 38);
          c9_b_B = c9_b_m;
          c9_c_y = c9_b_B;
          c9_d_y = c9_c_y;
          c9_e_y = 1.0 / c9_d_y;
          for (c9_i38 = 0; c9_i38 < 3; c9_i38++) {
            c9_b_kA[c9_i38] = c9_kA[c9_i38];
          }

          for (c9_i39 = 0; c9_i39 < 3; c9_i39++) {
            c9_b_uA[c9_i39] = c9_uA[c9_i39];
          }

          c9_denom = (c9_e_y + c9_m_ground_inv) + c9_dot(chartInstance, c9_b_kA,
            c9_b_uA);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 40);
          c9_b_A = c9_numer;
          c9_c_B = c9_denom;
          c9_x = c9_b_A;
          c9_f_y = c9_c_B;
          c9_b_x = c9_x;
          c9_g_y = c9_f_y;
          c9_f = c9_b_x / c9_g_y;
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 41);
          c9_d_a = c9_f;
          for (c9_i40 = 0; c9_i40 < 3; c9_i40++) {
            c9_impulse[c9_i40] = c9_d_a * c9_b_b[c9_i40];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 43);
          for (c9_i41 = 0; c9_i41 < 3; c9_i41++) {
            c9_ball_momentum[c9_i41] += c9_impulse[c9_i41];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 44);
          for (c9_i42 = 0; c9_i42 < 3; c9_i42++) {
            c9_b_local_pos[c9_i42] = c9_ball_momentum[c9_i42];
          }

          c9_d_B = c9_b_m;
          c9_h_y = c9_d_B;
          c9_i_y = c9_h_y;
          for (c9_i43 = 0; c9_i43 < 3; c9_i43++) {
            c9_initial_velocity_temp[c9_i43] = c9_b_local_pos[c9_i43] / c9_i_y;
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
          c9_a_para = 0.5 * c9_get_gravity(chartInstance, 0);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 47);
          c9_b_para = c9_initial_velocity_temp[2];
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 48);
          for (c9_i44 = 0; c9_i44 < 3; c9_i44++) {
            c9_e_x_vec[c9_i44] = c9_b_x_vec[c9_i44];
          }

          for (c9_i45 = 0; c9_i45 < 3; c9_i45++) {
            c9_e_y_vec[c9_i45] = c9_b_y_vec[c9_i45];
          }

          c9_coordinate_transform_l_w(chartInstance, c9_e_x_vec, c9_e_y_vec,
            c9_initial_velocity_temp[0], c9_initial_velocity_temp[1],
            c9_initial_velocity_temp[2], c9_dv2);
          for (c9_i46 = 0; c9_i46 < 3; c9_i46++) {
            c9_initial_velocity_temp[c9_i46] = c9_dv2[c9_i46];
          }

          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 51);
          c9_c_A = -c9_b_para;
          c9_e_B = 2.0 * c9_a_para;
          c9_c_x = c9_c_A;
          c9_j_y = c9_e_B;
          c9_d_x = c9_c_x;
          c9_k_y = c9_j_y;
          c9_turning_time = c9_d_x / c9_k_y;
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 53);
          c9_toler = 0.06;
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 54);
          if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 4, c9_b_t, 0.0, -1,
                1U, c9_b_t != 0.0))) {
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 55);
            if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 5, c9_turning_time,
                  0.0, -1, 5U, c9_turning_time >= 0.0))) {
              _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 56);
              c9_turning_point = c9_a_para * c9_turning_time * c9_turning_time +
                c9_b_para * c9_turning_time;
              _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 57);
              if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 6,
                    c9_turning_point, c9_toler, -1, 2U, c9_turning_point <
                    c9_toler))) {
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 58);
                for (c9_i48 = 0; c9_i48 < 3; c9_i48++) {
                  c9_set_initial_velocity(chartInstance, c9_i48, 0.0);
                }

                ssUpdateDataStoreLog_wrapper(chartInstance->S, 3);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 60);
                c9_ball_position[1] = 3.0;
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 61);
                for (c9_i49 = 0; c9_i49 < 3; c9_i49++) {
                  c9_f_x_vec[c9_i49] = c9_b_x_vec[c9_i49];
                }

                for (c9_i50 = 0; c9_i50 < 3; c9_i50++) {
                  c9_f_y_vec[c9_i50] = c9_b_y_vec[c9_i50];
                }

                c9_coordinate_transform_l_w(chartInstance, c9_f_x_vec,
                  c9_f_y_vec, c9_ball_position[0], 3.0, c9_ball_position[2],
                  c9_dv3);
                for (c9_i51 = 0; c9_i51 < 3; c9_i51++) {
                  c9_ball_position[c9_i51] = c9_dv3[c9_i51];
                }

                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 62);
                for (c9_i52 = 0; c9_i52 < 3; c9_i52++) {
                  c9_set_initial_position(chartInstance, c9_i52,
                    c9_ball_position[c9_i52]);
                }

                ssUpdateDataStoreLog_wrapper(chartInstance->S, 2);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 63);
                c9_set_gravity(chartInstance, 0, 0.0);
                ssUpdateDataStoreLog_wrapper(chartInstance->S, 1);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 65);
                c9_b_pos_reset = 1.0;
              } else {
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 66);
                for (c9_i47 = 0; c9_i47 < 3; c9_i47++) {
                  c9_set_initial_velocity(chartInstance, c9_i47,
                    c9_initial_velocity_temp[c9_i47]);
                }

                ssUpdateDataStoreLog_wrapper(chartInstance->S, 3);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 67);
                c9_b_pos_reset = 0.0;
              }
            } else {
              _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 69);
              c9_b_pos_reset = 0.0;
            }
          }
        } else {
          guard2 = true;
        }
      } else {
        guard3 = true;
      }
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }

  if (guard4 == true) {
    guard3 = true;
  }

  if (guard3 == true) {
    guard2 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 84);
    c9_b_reset = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 85);
    c9_b_pos_reset = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 91);
  guard1 = false;
  if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 7, c9_b_init_reset, 0.0,
        -1, 0U, c9_b_init_reset == 0.0))) {
    if (CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 8, c9_b_t, 0.0, -1, 4U,
          c9_b_t > 0.0))) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 4, true);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 92);
      c9_b_reset = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 4, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -92);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
    (*chartInstance->c9_ball_position_new)[c9_i15] =
      c9_b_ball_position_new[c9_i15];
  }

  *chartInstance->c9_reset = c9_b_reset;
  *chartInstance->c9_pos_reset = c9_b_pos_reset;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_ballonplate_correctordinates
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_coordinate_transform
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, real_T
   c9_b_x_vec[3], real_T c9_b_y_vec[3], real_T c9_x, real_T c9_y, real_T c9_z,
   real_T c9_local[3], real_T c9_world[3])
{
  uint32_T c9_debug_family_var_map[10];
  real_T c9_z_vec[3];
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 2.0;
  int32_T c9_i53;
  int32_T c9_i54;
  real_T c9_a[3];
  real_T c9_c1;
  real_T c9_b[3];
  real_T c9_c2;
  real_T c9_c3;
  int32_T c9_i55;
  int32_T c9_i56;
  real_T c9_c_x_vec[9];
  int32_T c9_i57;
  real_T c9_b_x[3];
  real_T c9_dv4[3];
  int32_T c9_i58;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c9_b_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_z_vec, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_x_vec, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_y_vec, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_x, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_y, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_z, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_local, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_world, 9U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_world[0] = c9_x;
  c9_world[1] = c9_y;
  c9_world[2] = c9_z;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i53 = 0; c9_i53 < 3; c9_i53++) {
    c9_a[c9_i53] = c9_b_x_vec[c9_i53];
  }

  for (c9_i54 = 0; c9_i54 < 3; c9_i54++) {
    c9_b[c9_i54] = c9_b_y_vec[c9_i54];
  }

  c9_c1 = c9_a[1] * c9_b[2] - c9_a[2] * c9_b[1];
  c9_c2 = c9_a[2] * c9_b[0] - c9_a[0] * c9_b[2];
  c9_c3 = c9_a[0] * c9_b[1] - c9_a[1] * c9_b[0];
  c9_z_vec[0] = c9_c1;
  c9_z_vec[1] = c9_c2;
  c9_z_vec[2] = c9_c3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  for (c9_i55 = 0; c9_i55 < 3; c9_i55++) {
    c9_c_x_vec[c9_i55] = c9_b_x_vec[c9_i55];
  }

  for (c9_i56 = 0; c9_i56 < 3; c9_i56++) {
    c9_c_x_vec[c9_i56 + 3] = c9_b_y_vec[c9_i56];
  }

  for (c9_i57 = 0; c9_i57 < 3; c9_i57++) {
    c9_c_x_vec[c9_i57 + 6] = c9_z_vec[c9_i57];
  }

  c9_b_x[0] = c9_x;
  c9_b_x[1] = c9_y;
  c9_b_x[2] = c9_z;
  c9_mldivide(chartInstance, c9_c_x_vec, c9_b_x, c9_dv4);
  for (c9_i58 = 0; c9_i58 < 3; c9_i58++) {
    c9_local[c9_i58] = c9_dv4[c9_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_coordinate_transform_l_w
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, real_T
   c9_b_x_vec[3], real_T c9_b_y_vec[3], real_T c9_x, real_T c9_y, real_T c9_z,
   real_T c9_world[3])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_z_vec[3];
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i59;
  int32_T c9_i60;
  real_T c9_a[3];
  real_T c9_c1;
  real_T c9_b[3];
  real_T c9_c2;
  real_T c9_c3;
  int32_T c9_i61;
  int32_T c9_i62;
  real_T c9_b_a[9];
  int32_T c9_i63;
  int32_T c9_i64;
  int32_T c9_i65;
  int32_T c9_i66;
  int32_T c9_i67;
  int32_T c9_i68;
  int32_T c9_i69;
  int32_T c9_i70;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_c_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_z_vec, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_x_vec, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_y_vec, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_x, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_y, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_z, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_world, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 6);
  for (c9_i59 = 0; c9_i59 < 3; c9_i59++) {
    c9_a[c9_i59] = c9_b_x_vec[c9_i59];
  }

  for (c9_i60 = 0; c9_i60 < 3; c9_i60++) {
    c9_b[c9_i60] = c9_b_y_vec[c9_i60];
  }

  c9_c1 = c9_a[1] * c9_b[2] - c9_a[2] * c9_b[1];
  c9_c2 = c9_a[2] * c9_b[0] - c9_a[0] * c9_b[2];
  c9_c3 = c9_a[0] * c9_b[1] - c9_a[1] * c9_b[0];
  c9_z_vec[0] = c9_c1;
  c9_z_vec[1] = c9_c2;
  c9_z_vec[2] = c9_c3;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 7);
  for (c9_i61 = 0; c9_i61 < 3; c9_i61++) {
    c9_b_a[c9_i61] = c9_b_x_vec[c9_i61];
  }

  for (c9_i62 = 0; c9_i62 < 3; c9_i62++) {
    c9_b_a[c9_i62 + 3] = c9_b_y_vec[c9_i62];
  }

  for (c9_i63 = 0; c9_i63 < 3; c9_i63++) {
    c9_b_a[c9_i63 + 6] = c9_z_vec[c9_i63];
  }

  c9_b[0] = c9_x;
  c9_b[1] = c9_y;
  c9_b[2] = c9_z;
  for (c9_i64 = 0; c9_i64 < 3; c9_i64++) {
    c9_world[c9_i64] = 0.0;
  }

  for (c9_i65 = 0; c9_i65 < 3; c9_i65++) {
    c9_world[c9_i65] = 0.0;
  }

  for (c9_i66 = 0; c9_i66 < 3; c9_i66++) {
    c9_a[c9_i66] = c9_world[c9_i66];
  }

  for (c9_i67 = 0; c9_i67 < 3; c9_i67++) {
    c9_world[c9_i67] = c9_a[c9_i67];
  }

  for (c9_i68 = 0; c9_i68 < 3; c9_i68++) {
    c9_world[c9_i68] = 0.0;
    c9_i69 = 0;
    for (c9_i70 = 0; c9_i70 < 3; c9_i70++) {
      c9_world[c9_i68] += c9_b_a[c9_i69 + c9_i68] * c9_b[c9_i70];
      c9_i69 += 3;
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\akhan\\Documents\\MATLAB\\WRL\\Collision\\world to plate coordinate testing\\ground collision\\Plate Collision\\fall_off\\GUI Ba"
    "ll and Plate\\coordinate_transform.m"));
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\akhan\\Documents\\MATLAB\\WRL\\Collision\\world to plate coordinate testing\\ground collision\\Plate Collision\\fall_off\\GUI Ba"
    "ll and Plate\\coordinate_transform_l_w.m"));
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_b_pos_reset, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_pos_reset),
    &c9_thisId);
  sf_mex_destroy(&c9_b_pos_reset);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_pos_reset;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_b_pos_reset = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_pos_reset),
    &c9_thisId);
  sf_mex_destroy(&c9_b_pos_reset);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i71;
  const mxArray *c9_y = NULL;
  real_T c9_u[3];
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i71 = 0; c9_i71 < 3; c9_i71++) {
    c9_u[c9_i71] = (*(real_T (*)[3])c9_inData)[c9_i71];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_b_ball_position_new, const char_T *c9_identifier, real_T c9_y[3])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_ball_position_new),
                        &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_ball_position_new);
}

static void c9_d_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3])
{
  real_T c9_dv5[3];
  int32_T c9_i72;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c9_i72 = 0; c9_i72 < 3; c9_i72++) {
    c9_y[c9_i72] = c9_dv5[c9_i72];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_ball_position_new;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i73;
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_b_ball_position_new = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_ball_position_new),
                        &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_ball_position_new);
  for (c9_i73 = 0; c9_i73 < 3; c9_i73++) {
    (*(real_T (*)[3])c9_outData)[c9_i73] = c9_y[c9_i73];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i74;
  const mxArray *c9_y = NULL;
  real_T c9_u[3];
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i74 = 0; c9_i74 < 3; c9_i74++) {
    c9_u[c9_i74] = (*(real_T (*)[3])c9_inData)[c9_i74];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3])
{
  real_T c9_dv6[3];
  int32_T c9_i75;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv6, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c9_i75 = 0; c9_i75 < 3; c9_i75++) {
    c9_y[c9_i75] = c9_dv6[c9_i75];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_uB;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i76;
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_uB = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_uB), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_uB);
  for (c9_i76 = 0; c9_i76 < 3; c9_i76++) {
    (*(real_T (*)[3])c9_outData)[c9_i76] = c9_y[c9_i76];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i77;
  int32_T c9_i78;
  const mxArray *c9_y = NULL;
  int32_T c9_i79;
  real_T c9_u[9];
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i77 = 0;
  for (c9_i78 = 0; c9_i78 < 3; c9_i78++) {
    for (c9_i79 = 0; c9_i79 < 3; c9_i79++) {
      c9_u[c9_i79 + c9_i77] = (*(real_T (*)[9])c9_inData)[c9_i79 + c9_i77];
    }

    c9_i77 += 3;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_f_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9])
{
  real_T c9_dv7[9];
  int32_T c9_i80;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv7, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c9_i80 = 0; c9_i80 < 9; c9_i80++) {
    c9_y[c9_i80] = c9_dv7[c9_i80];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_J_sphere_inv;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i81;
  int32_T c9_i82;
  int32_T c9_i83;
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_J_sphere_inv = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_J_sphere_inv), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_J_sphere_inv);
  c9_i81 = 0;
  for (c9_i82 = 0; c9_i82 < 3; c9_i82++) {
    for (c9_i83 = 0; c9_i83 < 3; c9_i83++) {
      (*(real_T (*)[9])c9_outData)[c9_i83 + c9_i81] = c9_y[c9_i83 + c9_i81];
    }

    c9_i81 += 3;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray
  *sf_c9_ballonplate_correctordinates_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  const char * c9_data[4] = {
    "789ced53cb4ac340149d480dba505c547099a5ab8e4b11177df86821059116172221369336388f3233b5baf537dcbbf02bfc09c1a59fe24c9ac7108381a288e0"
    "25c370e69e73e1dc9b0bac5e1fa8d854e7cd06407d604d9d15b088d5045bc99b95bdd7c046821fd419312ad19d5c24a94f1048236024a23e9583fb29021c0986",
    "6f511067c208a3414490cb0cd08d142027462a033ac52722ab0cb00916a17dec81dc47ade0238dd4c796a1eb7ea1d3fc7a41578f7d331e287f127992fb54848c"
    "93b4de7e453dbb50cf8ebb35bbc628994785fea9a0d7f8f2f8aa730087027101fd9b894fe1111bcd08a252c07e6be0b6daf0e2dc851d8671242246e19c711c38",
    "923953ac4c38b91f472221233a8663ce6634509954721633f312a18fb1c7c2109e0e7b4e5b01c757fc9805cbfad3209ffb6397f8b30c7febd9fc5e0eb71f5f5b"
    "cbebf379ffb67ed7d05b257a60dccbf07f6a0f760a3a8dcbe6ec616ffe1d7bf05ea17f2ee835fe0b7ba0fbd32079df97fb9f9acdff7da8e67f009549c728",
    "" };

  c9_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c9_data, 1768U, &c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_cross(SFc9_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c9_a[3], real_T c9_b[3], real_T
                     c9_c[3])
{
  real_T c9_c1;
  real_T c9_c2;
  real_T c9_c3;
  (void)chartInstance;
  c9_c1 = c9_a[1] * c9_b[2] - c9_a[2] * c9_b[1];
  c9_c2 = c9_a[2] * c9_b[0] - c9_a[0] * c9_b[2];
  c9_c3 = c9_a[0] * c9_b[1] - c9_a[1] * c9_b[0];
  c9_c[0] = c9_c1;
  c9_c[1] = c9_c2;
  c9_c[2] = c9_c3;
}

static void c9_mldivide(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, real_T c9_A[9], real_T c9_B[3], real_T c9_Y[3])
{
  int32_T c9_i84;
  int32_T c9_r1;
  real_T c9_b_A[9];
  int32_T c9_r2;
  int32_T c9_r3;
  real_T c9_x;
  real_T c9_maxval;
  real_T c9_b_x;
  real_T c9_a21;
  real_T c9_c_x;
  real_T c9_d;
  real_T c9_d_x;
  real_T c9_y;
  real_T c9_e_x;
  real_T c9_b_y;
  real_T c9_z;
  real_T c9_f_x;
  real_T c9_c_y;
  real_T c9_g_x;
  real_T c9_d_y;
  real_T c9_b_z;
  real_T c9_h_x;
  real_T c9_b_d;
  real_T c9_i_x;
  real_T c9_c_d;
  int32_T c9_rtemp;
  real_T c9_j_x;
  real_T c9_e_y;
  real_T c9_k_x;
  real_T c9_f_y;
  real_T c9_c_z;
  real_T c9_l_x;
  real_T c9_g_y;
  real_T c9_m_x;
  real_T c9_h_y;
  real_T c9_d_z;
  real_T c9_n_x;
  real_T c9_i_y;
  real_T c9_o_x;
  real_T c9_j_y;
  real_T c9_e_z;
  real_T c9_p_x;
  real_T c9_k_y;
  real_T c9_q_x;
  real_T c9_l_y;
  real_T c9_f_z;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  for (c9_i84 = 0; c9_i84 < 9; c9_i84++) {
    c9_b_A[c9_i84] = c9_A[c9_i84];
  }

  c9_r1 = 0;
  c9_r2 = 1;
  c9_r3 = 2;
  c9_x = c9_b_A[0];
  c9_maxval = c9_abs(chartInstance, c9_x) + c9_abs(chartInstance, 0.0);
  c9_b_x = c9_b_A[1];
  c9_a21 = c9_abs(chartInstance, c9_b_x) + c9_abs(chartInstance, 0.0);
  if (c9_a21 > c9_maxval) {
    c9_maxval = c9_a21;
    c9_r1 = 1;
    c9_r2 = 0;
  }

  c9_c_x = c9_b_A[2];
  c9_d = c9_abs(chartInstance, c9_c_x) + c9_abs(chartInstance, 0.0);
  if (c9_d > c9_maxval) {
    c9_r1 = 2;
    c9_r2 = 1;
    c9_r3 = 0;
  }

  c9_d_x = c9_b_A[c9_r2];
  c9_y = c9_b_A[c9_r1];
  c9_e_x = c9_d_x;
  c9_b_y = c9_y;
  c9_z = c9_e_x / c9_b_y;
  c9_b_A[c9_r2] = c9_z;
  c9_f_x = c9_b_A[c9_r3];
  c9_c_y = c9_b_A[c9_r1];
  c9_g_x = c9_f_x;
  c9_d_y = c9_c_y;
  c9_b_z = c9_g_x / c9_d_y;
  c9_b_A[c9_r3] = c9_b_z;
  c9_b_A[3 + c9_r2] -= c9_b_A[c9_r2] * c9_b_A[3 + c9_r1];
  c9_b_A[3 + c9_r3] -= c9_b_A[c9_r3] * c9_b_A[3 + c9_r1];
  c9_b_A[6 + c9_r2] -= c9_b_A[c9_r2] * c9_b_A[6 + c9_r1];
  c9_b_A[6 + c9_r3] -= c9_b_A[c9_r3] * c9_b_A[6 + c9_r1];
  c9_h_x = c9_b_A[3 + c9_r3];
  c9_b_d = c9_abs(chartInstance, c9_h_x) + c9_abs(chartInstance, 0.0);
  c9_i_x = c9_b_A[3 + c9_r2];
  c9_c_d = c9_abs(chartInstance, c9_i_x) + c9_abs(chartInstance, 0.0);
  if (c9_b_d > c9_c_d) {
    c9_rtemp = c9_r2 + 1;
    c9_r2 = c9_r3;
    c9_r3 = c9_rtemp - 1;
  }

  c9_j_x = c9_b_A[3 + c9_r3];
  c9_e_y = c9_b_A[3 + c9_r2];
  c9_k_x = c9_j_x;
  c9_f_y = c9_e_y;
  c9_c_z = c9_k_x / c9_f_y;
  c9_b_A[3 + c9_r3] = c9_c_z;
  c9_b_A[6 + c9_r3] -= c9_b_A[3 + c9_r3] * c9_b_A[6 + c9_r2];
  guard1 = false;
  guard2 = false;
  if (c9_b_A[c9_r1] == 0.0) {
    guard2 = true;
  } else if (c9_b_A[3 + c9_r2] == 0.0) {
    guard2 = true;
  } else {
    if (c9_b_A[6 + c9_r3] == 0.0) {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c9_warning(chartInstance);
  }

  c9_Y[0] = c9_B[c9_r1];
  c9_Y[1] = c9_B[c9_r2] - c9_Y[0] * c9_b_A[c9_r2];
  c9_Y[2] = (c9_B[c9_r3] - c9_Y[0] * c9_b_A[c9_r3]) - c9_Y[1] * c9_b_A[3 + c9_r3];
  c9_l_x = c9_Y[2];
  c9_g_y = c9_b_A[6 + c9_r3];
  c9_m_x = c9_l_x;
  c9_h_y = c9_g_y;
  c9_d_z = c9_m_x / c9_h_y;
  c9_Y[2] = c9_d_z;
  c9_Y[0] -= c9_Y[2] * c9_b_A[6 + c9_r1];
  c9_Y[1] -= c9_Y[2] * c9_b_A[6 + c9_r2];
  c9_n_x = c9_Y[1];
  c9_i_y = c9_b_A[3 + c9_r2];
  c9_o_x = c9_n_x;
  c9_j_y = c9_i_y;
  c9_e_z = c9_o_x / c9_j_y;
  c9_Y[1] = c9_e_z;
  c9_Y[0] -= c9_Y[1] * c9_b_A[3 + c9_r1];
  c9_p_x = c9_Y[0];
  c9_k_y = c9_b_A[c9_r1];
  c9_q_x = c9_p_x;
  c9_l_y = c9_k_y;
  c9_f_z = c9_q_x / c9_l_y;
  c9_Y[0] = c9_f_z;
}

static real_T c9_abs(SFc9_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c9_x)
{
  real_T c9_b_x;
  real_T c9_c_x;
  (void)chartInstance;
  c9_b_x = c9_x;
  c9_c_x = c9_b_x;
  return muDoubleScalarAbs(c9_c_x);
}

static void c9_warning(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance)
{
  const mxArray *c9_y = NULL;
  static char_T c9_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c9_b_y = NULL;
  static char_T c9_b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c9_c_y = NULL;
  static char_T c9_msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  (void)chartInstance;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c9_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c9_b_y, 14, c9_c_y));
}

static void c9_scalarEg(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c9_b_scalarEg(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c9_dot(SFc9_ballonplate_correctordinatesInstanceStruct
                     *chartInstance, real_T c9_a[3], real_T c9_b[3])
{
  real_T c9_c;
  int32_T c9_k;
  int32_T c9_b_k;
  (void)chartInstance;
  c9_c = 0.0;
  for (c9_k = 1; c9_k < 4; c9_k++) {
    c9_b_k = c9_k - 1;
    c9_c += c9_a[c9_b_k] * c9_b[c9_b_k];
  }

  return c9_c;
}

static void c9_c_scalarEg(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_g_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i85;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i85, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i85;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_h_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_b_is_active_c9_ballonplate_correctordinates, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_ballonplate_correctordinates), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_ballonplate_correctordinates);
  return c9_y;
}

static uint8_T c9_i_emlrt_marshallIn
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static real_T c9_get_count_mm(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c9_elementIndex);
  return *chartInstance->c9_count_mm_address;
}

static void c9_set_count_mm(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex, real_T c9_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c9_elementIndex);
  *chartInstance->c9_count_mm_address = c9_elementValue;
}

static real_T *c9_access_count_mm
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_rdOnly)
{
  real_T *c9_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c9_dsmAddr = chartInstance->c9_count_mm_address;
  if (c9_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c9_dsmAddr;
}

static real_T c9_get_gravity(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c9_elementIndex);
  return *chartInstance->c9__indexgravity_address;
}

static void c9_set_gravity(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_elementIndex, real_T c9_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c9_elementIndex);
  *chartInstance->c9__indexgravity_address = c9_elementValue;
}

static real_T *c9_access_gravity(SFc9_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c9_rdOnly)
{
  real_T *c9_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c9_dsmAddr = chartInstance->c9__indexgravity_address;
  if (c9_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c9_dsmAddr;
}

static real_T c9_get_initial_position
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c9_elementIndex);
  return (*chartInstance->c9__indexinitial_position_address)[c9_elementIndex];
}

static void c9_set_initial_position
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex, real_T c9_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c9_elementIndex);
  (*chartInstance->c9__indexinitial_position_address)[c9_elementIndex] =
    c9_elementValue;
}

static real_T *c9_access_initial_position
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_rdOnly)
{
  real_T *c9_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c9_dsmAddr = &(*chartInstance->c9__indexinitial_position_address)[0U];
  if (c9_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c9_dsmAddr;
}

static real_T c9_get_initial_velocity
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 3, NULL, c9_elementIndex);
  return (*chartInstance->c9__indexinitial_velocity_address)[c9_elementIndex];
}

static void c9_set_initial_velocity
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_elementIndex, real_T c9_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 3, NULL, c9_elementIndex);
  (*chartInstance->c9__indexinitial_velocity_address)[c9_elementIndex] =
    c9_elementValue;
}

static real_T *c9_access_initial_velocity
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c9_rdOnly)
{
  real_T *c9_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 3, NULL);
  c9_dsmAddr = &(*chartInstance->c9__indexinitial_velocity_address)[0U];
  if (c9_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 3, NULL);
  }

  return c9_dsmAddr;
}

static void init_dsm_address_info
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "count_mm", (void **)
    &chartInstance->c9_count_mm_address, &chartInstance->c9__indexmm);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "gravity", (void **)
    &chartInstance->c9__indexgravity_address, &chartInstance->c9__indexy);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "initial_position",
    (void **)&chartInstance->c9__indexinitial_position_address,
    &chartInstance->c9__indexl_position);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "initial_velocity",
    (void **)&chartInstance->c9__indexinitial_velocity_address,
    &chartInstance->c9__indexl_velocity);
}

static void init_simulink_io_address
  (SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  chartInstance->c9_t = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c9_bp_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_ball_position_new = (real_T (*)[3])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c9_bp_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_bp_z = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_bv_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c9_bv_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c9_bv_z = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c9_reset = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_x_vec = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c9_y_vec = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c9_pos_reset = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_init_reset = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c9_m = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    10);
  chartInstance->c9_r = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    11);
  chartInstance->c9_rest = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
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

void sf_c9_ballonplate_correctordinates_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(635829339U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3416786491U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2452260760U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(506754719U);
}

mxArray* sf_c9_ballonplate_correctordinates_get_post_codegen_info(void);
mxArray *sf_c9_ballonplate_correctordinates_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("W6R5rDhA5jnjBGTjINaqZG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c9_ballonplate_correctordinates_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_ballonplate_correctordinates_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_ballonplate_correctordinates_jit_fallback_info(void)
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

mxArray *sf_c9_ballonplate_correctordinates_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_ballonplate_correctordinates_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c9_ballonplate_correctordinates(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"ball_position_new\",},{M[1],M[24],T\"pos_reset\",},{M[1],M[16],T\"reset\",},{M[8],M[0],T\"is_active_c9_ballonplate_correctordinates\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_ballonplate_correctordinates_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc9_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ballonplate_correctordinatesMachineNumber_,
           9,
           1,
           1,
           0,
           20,
           0,
           0,
           0,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,1,1,0,"bp_x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"bp_y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"bp_z");
          _SFD_SET_DATA_PROPS(4,1,1,0,"bv_x");
          _SFD_SET_DATA_PROPS(5,1,1,0,"bv_y");
          _SFD_SET_DATA_PROPS(6,1,1,0,"bv_z");
          _SFD_SET_DATA_PROPS(7,1,1,0,"x_vec");
          _SFD_SET_DATA_PROPS(8,1,1,0,"y_vec");
          _SFD_SET_DATA_PROPS(9,1,1,0,"init_reset");
          _SFD_SET_DATA_PROPS(10,1,1,0,"m");
          _SFD_SET_DATA_PROPS(11,1,1,0,"r");
          _SFD_SET_DATA_PROPS(12,1,1,0,"rest");
          _SFD_SET_DATA_PROPS(13,2,0,1,"ball_position_new");
          _SFD_SET_DATA_PROPS(14,2,0,1,"reset");
          _SFD_SET_DATA_PROPS(15,2,0,1,"pos_reset");
          _SFD_SET_DATA_PROPS(16,11,0,0,"count_mm");
          _SFD_SET_DATA_PROPS(17,11,0,0,"gravity");
          _SFD_SET_DATA_PROPS(18,11,0,0,"initial_position");
          _SFD_SET_DATA_PROPS(19,11,0,0,"initial_velocity");
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
        _SFD_CV_INIT_EML(0,1,1,0,5,0,0,0,0,0,6,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2656);
        _SFD_CV_INIT_EML_IF(0,1,0,426,482,2563,2606);
        _SFD_CV_INIT_EML_IF(0,1,1,1607,1614,-1,2169);
        _SFD_CV_INIT_EML_IF(0,1,2,1615,1633,2144,2165);
        _SFD_CV_INIT_EML_IF(0,1,3,1716,1738,2068,2143);
        _SFD_CV_INIT_EML_IF(0,1,4,2609,2633,-1,2654);

        {
          static int condStart[] = { 430, 452, 457, 469 };

          static int condEnd[] = { 449, 455, 467, 482 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,429,482,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2612, 2630 };

          static int condEnd[] = { 2627, 2633 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,2612,2633,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,430,449,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,452,455,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,457,467,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,469,482,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1610,1614,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,1618,1633,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,1719,1738,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,2612,2627,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,2630,2633,-1,4);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"coordinate_transform",0,-1,282);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"coordinate_transform_l_w",0,-1,264);
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

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }
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
    SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc9_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_t);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c9_bp_x);
        _SFD_SET_DATA_VALUE_PTR(13U, *chartInstance->c9_ball_position_new);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_bp_y);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_bp_z);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_bv_x);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_bv_y);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_bv_z);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c9_reset);
        _SFD_SET_DATA_VALUE_PTR(19U,
          *chartInstance->c9__indexinitial_velocity_address);
        _SFD_SET_DATA_VALUE_PTR(18U,
          *chartInstance->c9__indexinitial_position_address);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c9__indexgravity_address);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c9_x_vec);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c9_y_vec);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c9_pos_reset);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c9_count_mm_address);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c9_init_reset);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c9_m);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c9_r);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c9_rest);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sVQrZyQxYdvhXOEHzq5Y5ZB";
}

static void sf_opaque_initialize_c9_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_ballonplate_correctordinatesInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
  initialize_c9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  enable_c9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  disable_c9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  sf_gateway_c9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_ballonplate_correctordinates
  (SimStruct* S)
{
  return get_sim_state_c9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_ballonplate_correctordinates(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct*)sf_get_chart_instance_ptr
     (S), st);
}

static void sf_opaque_terminate_c9_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_ballonplate_correctordinatesInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ballonplate_correctordinates_optimization_info();
    }

    finalize_c9_ballonplate_correctordinates
      ((SFc9_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_ballonplate_correctordinates
    ((SFc9_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_ballonplate_correctordinates(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_ballonplate_correctordinates
      ((SFc9_ballonplate_correctordinatesInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c9_ballonplate_correctordinates(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ballonplate_correctordinates_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
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
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 13; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3755839926U));
  ssSetChecksum1(S,(2102333602U));
  ssSetChecksum2(S,(2950159356U));
  ssSetChecksum3(S,(2411699391U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c9_ballonplate_correctordinates(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_ballonplate_correctordinates(SimStruct *S)
{
  SFc9_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc9_ballonplate_correctordinatesInstanceStruct *)utMalloc
    (sizeof(SFc9_ballonplate_correctordinatesInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc9_ballonplate_correctordinatesInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_ballonplate_correctordinates;
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
  mdl_start_c9_ballonplate_correctordinates(chartInstance);
}

void c9_ballonplate_correctordinates_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_ballonplate_correctordinates(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_ballonplate_correctordinates_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
