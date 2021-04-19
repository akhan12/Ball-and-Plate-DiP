/* Include files */

#include "ballonplate_correctordinates_sfun.h"
#include "c5_ballonplate_correctordinates.h"
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
static const char * c5_debug_family_names[7] = { "nargin", "nargout",
  "init_mod_sec", "bounce_co", "bounce_co_vel", "reset", "model_sel" };

/* Function Declarations */
static void initialize_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initialize_params_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void enable_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void disable_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void set_sim_state_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_st);
static void finalize_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void sf_gateway_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void mdl_start_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initSimStructsc5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_b_model_sel, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_d_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_b_is_active_c5_ballonplate_correctordinates, const char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId);
static real_T c5_get_count(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex);
static void c5_set_count(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_count(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly);
static real_T c5_get_gravity(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex);
static void c5_set_gravity(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_gravity(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly);
static real_T c5_get_initial_position
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex);
static void c5_set_initial_position
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_initial_position
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly);
static real_T c5_get_initial_velocity
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex);
static void c5_set_initial_velocity
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_initial_velocity
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly);
static real_T c5_get_x1_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex);
static void c5_set_x1_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_x1_d_init
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly);
static real_T c5_get_x1_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex);
static void c5_set_x1_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_x1_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly);
static real_T c5_get_x2_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex);
static void c5_set_x2_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_x2_d_init
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly);
static real_T c5_get_x2_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex);
static void c5_set_x2_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_x2_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly);
static void init_dsm_address_info
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc5_ballonplate_correctordinates(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_ballonplate_correctordinates = 0U;
}

static void initialize_params_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(3, 1), false);
  c5_hoistedGlobal = *chartInstance->c5_model_sel;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *chartInstance->c5_reset;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal =
    chartInstance->c5_is_active_c5_ballonplate_correctordinates;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_st)
{
  const mxArray *c5_u;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *chartInstance->c5_model_sel = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("model_sel", c5_u, 0)), "model_sel");
  *chartInstance->c5_reset = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("reset", c5_u, 1)), "reset");
  chartInstance->c5_is_active_c5_ballonplate_correctordinates =
    c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c5_ballonplate_correctordinates", c5_u, 2)),
    "is_active_c5_ballonplate_correctordinates");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_ballonplate_correctordinates(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  int32_T c5_i0;
  int32_T c5_i1;
  real_T c5_hoistedGlobal;
  real_T c5_b_init_mod_sec;
  int32_T c5_i2;
  int32_T c5_i3;
  real_T c5_b_bounce_co[3];
  uint32_T c5_debug_family_var_map[7];
  real_T c5_b_bounce_co_vel[3];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 2.0;
  real_T c5_b_reset;
  real_T c5_b_model_sel;
  int32_T c5_i4;
  static real_T c5_dv0[3] = { 0.0, 15.0, 0.0 };

  int32_T c5_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i0 = 0; c5_i0 < 3; c5_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_bounce_co_vel)[c5_i0], 2U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_bounce_co)[c5_i1], 1U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_init_mod_sec, 0U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *chartInstance->c5_init_mod_sec;
  c5_b_init_mod_sec = c5_hoistedGlobal;
  for (c5_i2 = 0; c5_i2 < 3; c5_i2++) {
    c5_b_bounce_co[c5_i2] = (*chartInstance->c5_bounce_co)[c5_i2];
  }

  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    c5_b_bounce_co_vel[c5_i3] = (*chartInstance->c5_bounce_co_vel)[c5_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_init_mod_sec, 2U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_bounce_co, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_bounce_co_vel, 4U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_reset, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_model_sel, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c5_b_init_mod_sec, 0.0,
        -1, 0U, c5_b_init_mod_sec == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
    c5_set_gravity(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog_wrapper(chartInstance->S, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
    c5_b_model_sel = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
    c5_b_reset = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
    for (c5_i4 = 0; c5_i4 < 3; c5_i4++) {
      c5_set_initial_position(chartInstance, c5_i4, c5_dv0[c5_i4]);
    }

    ssUpdateDataStoreLog_wrapper(chartInstance->S, 2);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
    for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
      c5_set_initial_velocity(chartInstance, c5_i5, 0.0);
    }

    ssUpdateDataStoreLog_wrapper(chartInstance->S, 3);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c5_get_gravity
          (chartInstance, 0), 0.0, -1, 0U, c5_get_gravity(chartInstance, 0) ==
          0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c5_get_count
            (chartInstance, 0), 2.0, -1, 2U, c5_get_count(chartInstance, 0) <
            2.0))) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
        c5_b_reset = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
        c5_set_x1_init(chartInstance, 0, c5_b_bounce_co[0]);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 5);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 28);
        c5_set_x2_init(chartInstance, 0, c5_b_bounce_co[1]);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 7);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
        c5_set_x1_d_init(chartInstance, 0, c5_b_bounce_co_vel[0]);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 4);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
        c5_set_x2_d_init(chartInstance, 0, c5_b_bounce_co_vel[1]);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 6);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
        c5_set_count(chartInstance, 0, c5_get_count(chartInstance, 0) + 1.0);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 0);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
        c5_b_reset = 1.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 34);
      c5_b_model_sel = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 36);
      c5_b_reset = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 37);
      c5_b_model_sel = 1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -37);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c5_reset = c5_b_reset;
  *chartInstance->c5_model_sel = c5_b_model_sel;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ballonplate_correctordinatesMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_reset, 3U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_model_sel, 4U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
}

static void mdl_start_c5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc5_ballonplate_correctordinates
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc5_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_b_model_sel, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_model_sel),
    &c5_thisId);
  sf_mex_destroy(&c5_b_model_sel);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_model_sel;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc5_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c5_b_model_sel = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_model_sel),
    &c5_thisId);
  sf_mex_destroy(&c5_b_model_sel);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i6;
  const mxArray *c5_y = NULL;
  real_T c5_u[3];
  SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc5_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    c5_u[c5_i6] = (*(real_T (*)[3])c5_inData)[c5_i6];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

const mxArray
  *sf_c5_ballonplate_correctordinates_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc5_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i7;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i7, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i7;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc5_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_d_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3])
{
  real_T c5_dv1[3];
  int32_T c5_i8;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_y[c5_i8] = c5_dv1[c5_i8];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_initial_velocity;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i9;
  SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc5_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c5_initial_velocity = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_initial_velocity),
                        &c5_thisId, c5_y);
  sf_mex_destroy(&c5_initial_velocity);
  for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
    (*(real_T (*)[3])c5_outData)[c5_i9] = c5_y[c5_i9];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_b_is_active_c5_ballonplate_correctordinates, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_ballonplate_correctordinates), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_ballonplate_correctordinates);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, const mxArray
   *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static real_T c5_get_count(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c5_elementIndex);
  return *chartInstance->c5_count_address;
}

static void c5_set_count(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c5_elementIndex);
  *chartInstance->c5_count_address = c5_elementValue;
}

static real_T *c5_access_count(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c5_dsmAddr = chartInstance->c5_count_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_gravity(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c5_elementIndex);
  return *chartInstance->c5__indexgravity_address;
}

static void c5_set_gravity(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c5_elementIndex);
  *chartInstance->c5__indexgravity_address = c5_elementValue;
}

static real_T *c5_access_gravity(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c5_dsmAddr = chartInstance->c5__indexgravity_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_initial_position
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c5_elementIndex);
  return (*chartInstance->c5__indexinitial_position_address)[c5_elementIndex];
}

static void c5_set_initial_position
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c5_elementIndex);
  (*chartInstance->c5__indexinitial_position_address)[c5_elementIndex] =
    c5_elementValue;
}

static real_T *c5_access_initial_position
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c5_dsmAddr = &(*chartInstance->c5__indexinitial_position_address)[0U];
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_initial_velocity
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 3, NULL, c5_elementIndex);
  return (*chartInstance->c5__indexinitial_velocity_address)[c5_elementIndex];
}

static void c5_set_initial_velocity
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 3, NULL, c5_elementIndex);
  (*chartInstance->c5__indexinitial_velocity_address)[c5_elementIndex] =
    c5_elementValue;
}

static real_T *c5_access_initial_velocity
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 3, NULL);
  c5_dsmAddr = &(*chartInstance->c5__indexinitial_velocity_address)[0U];
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 3, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_x1_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 4, NULL, c5_elementIndex);
  return *chartInstance->c5__indexx1_d_init_address;
}

static void c5_set_x1_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 4, NULL, c5_elementIndex);
  *chartInstance->c5__indexx1_d_init_address = c5_elementValue;
}

static real_T *c5_access_x1_d_init
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 4, NULL);
  c5_dsmAddr = chartInstance->c5__indexx1_d_init_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 4, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_x1_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 5, NULL, c5_elementIndex);
  return *chartInstance->c5__indexx1_init_address;
}

static void c5_set_x1_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 5, NULL, c5_elementIndex);
  *chartInstance->c5__indexx1_init_address = c5_elementValue;
}

static real_T *c5_access_x1_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 5, NULL);
  c5_dsmAddr = chartInstance->c5__indexx1_init_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 5, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_x2_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 6, NULL, c5_elementIndex);
  return *chartInstance->c5__indexx2_d_init_address;
}

static void c5_set_x2_d_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 6, NULL, c5_elementIndex);
  *chartInstance->c5__indexx2_d_init_address = c5_elementValue;
}

static real_T *c5_access_x2_d_init
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 6, NULL);
  c5_dsmAddr = chartInstance->c5__indexx2_d_init_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 6, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_x2_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 7, NULL, c5_elementIndex);
  return *chartInstance->c5__indexx2_init_address;
}

static void c5_set_x2_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 7, NULL, c5_elementIndex);
  *chartInstance->c5__indexx2_init_address = c5_elementValue;
}

static real_T *c5_access_x2_init(SFc5_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 7, NULL);
  c5_dsmAddr = chartInstance->c5__indexx2_init_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 7, NULL);
  }

  return c5_dsmAddr;
}

static void init_dsm_address_info
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "count", (void **)
    &chartInstance->c5_count_address, &chartInstance->c5__index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "gravity", (void **)
    &chartInstance->c5__indexgravity_address, &chartInstance->c5__indexy);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "initial_position",
    (void **)&chartInstance->c5__indexinitial_position_address,
    &chartInstance->c5__indexl_position);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "initial_velocity",
    (void **)&chartInstance->c5__indexinitial_velocity_address,
    &chartInstance->c5__indexl_velocity);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "x1_d_init", (void **)
    &chartInstance->c5__indexx1_d_init_address, &chartInstance->c5__indexnit);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "x1_init", (void **)
    &chartInstance->c5__indexx1_init_address, &chartInstance->c5__indext);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "x2_d_init", (void **)
    &chartInstance->c5__indexx2_d_init_address, &chartInstance->c5_b__indexnit);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "x2_init", (void **)
    &chartInstance->c5__indexx2_init_address, &chartInstance->c5_b__indext);
}

static void init_simulink_io_address
  (SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  chartInstance->c5_init_mod_sec = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_reset = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_bounce_co = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_bounce_co_vel = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_model_sel = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c5_ballonplate_correctordinates_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3317700361U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(791024529U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3593945182U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4046752129U);
}

mxArray* sf_c5_ballonplate_correctordinates_get_post_codegen_info(void);
mxArray *sf_c5_ballonplate_correctordinates_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Xc7WXBgtOpZ106kjyIo4RC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      sf_c5_ballonplate_correctordinates_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_ballonplate_correctordinates_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_ballonplate_correctordinates_jit_fallback_info(void)
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

mxArray *sf_c5_ballonplate_correctordinates_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_ballonplate_correctordinates_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_ballonplate_correctordinates(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"model_sel\",},{M[1],M[5],T\"reset\",},{M[8],M[0],T\"is_active_c5_ballonplate_correctordinates\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_ballonplate_correctordinates_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc5_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ballonplate_correctordinatesMachineNumber_,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"init_mod_sec");
          _SFD_SET_DATA_PROPS(1,1,1,0,"bounce_co");
          _SFD_SET_DATA_PROPS(2,1,1,0,"bounce_co_vel");
          _SFD_SET_DATA_PROPS(3,2,0,1,"reset");
          _SFD_SET_DATA_PROPS(4,2,0,1,"model_sel");
          _SFD_SET_DATA_PROPS(5,11,0,0,"count");
          _SFD_SET_DATA_PROPS(6,11,0,0,"gravity");
          _SFD_SET_DATA_PROPS(7,11,0,0,"initial_position");
          _SFD_SET_DATA_PROPS(8,11,0,0,"initial_velocity");
          _SFD_SET_DATA_PROPS(9,11,0,0,"x1_d_init");
          _SFD_SET_DATA_PROPS(10,11,0,0,"x1_init");
          _SFD_SET_DATA_PROPS(11,11,0,0,"x2_d_init");
          _SFD_SET_DATA_PROPS(12,11,0,0,"x2_init");
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
        _SFD_CV_INIT_EML(0,1,1,0,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1000);
        _SFD_CV_INIT_EML_IF(0,1,0,405,425,566,997);
        _SFD_CV_INIT_EML_IF(0,1,1,580,595,935,989);
        _SFD_CV_INIT_EML_IF(0,1,2,608,619,864,894);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,408,425,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,583,595,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,611,619,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
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
    SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc5_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_init_mod_sec);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c5_reset);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c5__indexgravity_address);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c5_bounce_co);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c5_bounce_co_vel);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c5_model_sel);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c5__indexx1_init_address);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c5__indexx1_d_init_address);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c5__indexx2_init_address);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c5__indexx2_d_init_address);
        _SFD_SET_DATA_VALUE_PTR(8U,
          *chartInstance->c5__indexinitial_velocity_address);
        _SFD_SET_DATA_VALUE_PTR(7U,
          *chartInstance->c5__indexinitial_position_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c5_count_address);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sNYdl5Fhb5yBkFHeDAFpvsB";
}

static void sf_opaque_initialize_c5_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_ballonplate_correctordinatesInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
  initialize_c5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  enable_c5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  disable_c5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  sf_gateway_c5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_ballonplate_correctordinates
  (SimStruct* S)
{
  return get_sim_state_c5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_ballonplate_correctordinates(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct*)sf_get_chart_instance_ptr
     (S), st);
}

static void sf_opaque_terminate_c5_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_ballonplate_correctordinatesInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ballonplate_correctordinates_optimization_info();
    }

    finalize_c5_ballonplate_correctordinates
      ((SFc5_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_ballonplate_correctordinates
    ((SFc5_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_ballonplate_correctordinates(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_ballonplate_correctordinates
      ((SFc5_ballonplate_correctordinatesInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c5_ballonplate_correctordinates(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ballonplate_correctordinates_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 5);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3336107740U));
  ssSetChecksum1(S,(2829171456U));
  ssSetChecksum2(S,(3804493441U));
  ssSetChecksum3(S,(454296335U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c5_ballonplate_correctordinates(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_ballonplate_correctordinates(SimStruct *S)
{
  SFc5_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc5_ballonplate_correctordinatesInstanceStruct *)utMalloc
    (sizeof(SFc5_ballonplate_correctordinatesInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc5_ballonplate_correctordinatesInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_ballonplate_correctordinates;
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
  mdl_start_c5_ballonplate_correctordinates(chartInstance);
}

void c5_ballonplate_correctordinates_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_ballonplate_correctordinates(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_ballonplate_correctordinates_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
