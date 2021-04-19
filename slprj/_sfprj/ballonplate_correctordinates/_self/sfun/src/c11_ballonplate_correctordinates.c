/* Include files */

#include "ballonplate_correctordinates_sfun.h"
#include "c11_ballonplate_correctordinates.h"
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
static const char * c11_debug_family_names[9] = { "plate_dim_y", "nates",
  "nargin", "nargout", "mod_sec", "math_co", "bounce_co", "plate_dim_x",
  "mod_sec_edit" };

/* Function Declarations */
static void initialize_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initialize_params_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void enable_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void disable_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void set_sim_state_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_st);
static void finalize_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void sf_gateway_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void mdl_start_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void initSimStructsc11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_b_mod_sec_edit, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_d_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3]);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static real_T c11_abs(SFc11_ballonplate_correctordinatesInstanceStruct
                      *chartInstance, real_T c11_x);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_e_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_f_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_b_is_active_c11_ballonplate_correctordinates, const char_T
   *c11_identifier);
static uint8_T c11_g_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static real_T c11_get_falloff_toggle
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_elementIndex);
static void c11_set_falloff_toggle
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_elementIndex, real_T c11_elementValue);
static real_T *c11_access_falloff_toggle
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_rdOnly);
static real_T c11_get_gravity(SFc11_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c11_elementIndex);
static void c11_set_gravity(SFc11_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c11_elementIndex, real_T c11_elementValue);
static real_T *c11_access_gravity
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_rdOnly);
static void init_dsm_address_info
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc11_ballonplate_correctordinates(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_is_active_c11_ballonplate_correctordinates = 0U;
}

static void initialize_params_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(2, 1), false);
  c11_hoistedGlobal = *chartInstance->c11_mod_sec_edit;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal =
    chartInstance->c11_is_active_c11_ballonplate_correctordinates;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_st)
{
  const mxArray *c11_u;
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  *chartInstance->c11_mod_sec_edit = c11_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("mod_sec_edit", c11_u, 0)), "mod_sec_edit");
  chartInstance->c11_is_active_c11_ballonplate_correctordinates =
    c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c11_ballonplate_correctordinates", c11_u, 1)),
    "is_active_c11_ballonplate_correctordinates");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_ballonplate_correctordinates(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  int32_T c11_i0;
  int32_T c11_i1;
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  real_T c11_b_mod_sec;
  int32_T c11_i2;
  int32_T c11_i3;
  real_T c11_b_math_co[3];
  real_T c11_b_plate_dim_x;
  real_T c11_b_bounce_co[3];
  uint32_T c11_debug_family_var_map[9];
  real_T c11_plate_dim_y;
  real_T c11_nates[3];
  real_T c11_b_nates[3];
  real_T c11_nargin = 4.0;
  real_T c11_nargout = 1.0;
  real_T c11_b_mod_sec_edit;
  real_T c11_A;
  real_T c11_x;
  real_T c11_b_x;
  int32_T c11_i4;
  int32_T c11_i5;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_plate_dim_x, 3U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
  for (c11_i0 = 0; c11_i0 < 3; c11_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c11_bounce_co)[c11_i0], 2U, 1U, 0U,
                          chartInstance->c11_sfEvent, false);
  }

  for (c11_i1 = 0; c11_i1 < 3; c11_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c11_math_co)[c11_i1], 1U, 1U, 0U,
                          chartInstance->c11_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_mod_sec, 0U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
  chartInstance->c11_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *chartInstance->c11_mod_sec;
  c11_b_hoistedGlobal = *chartInstance->c11_plate_dim_x;
  c11_b_mod_sec = c11_hoistedGlobal;
  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    c11_b_math_co[c11_i2] = (*chartInstance->c11_math_co)[c11_i2];
  }

  for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
    c11_b_bounce_co[c11_i3] = (*chartInstance->c11_bounce_co)[c11_i3];
  }

  c11_b_plate_dim_x = c11_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 10U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_plate_dim_y, 0U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_nates, MAX_uint32_T,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_b_nates, MAX_uint32_T,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_mod_sec, 4U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_b_math_co, 5U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_b_bounce_co, 6U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_plate_dim_x, 7U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_mod_sec_edit, 8U,
    c11_sf_marshallOut, c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_A = c11_b_plate_dim_x;
  c11_x = c11_A;
  c11_b_x = c11_x;
  c11_b_plate_dim_x = c11_b_x / 100.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_plate_dim_y = c11_b_plate_dim_x;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 15);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c11_get_falloff_toggle
        (chartInstance, 0), 0.0, -1, 0U, c11_get_falloff_toggle(chartInstance, 0)
        == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 16);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c11_b_mod_sec, 1.0, -1,
          0U, c11_b_mod_sec == 1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 17);
      c11_b_mod_sec_edit = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
      for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
        c11_b_nates[c11_i5] = c11_b_bounce_co[c11_i5];
      }

      _SFD_SYMBOL_SWITCH(1U, 2U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 19);
      guard2 = false;
      guard3 = false;
      if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 2, c11_b_nates[1], 5.0,
            -1, 2U, c11_b_nates[1] < 5.0))) {
        if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 3, c11_abs
              (chartInstance, c11_b_nates[0]), c11_plate_dim_y, -1, 4U, c11_abs
              (chartInstance, c11_b_nates[0]) > c11_plate_dim_y))) {
          guard2 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 4, c11_abs
              (chartInstance, c11_b_nates[2]), c11_plate_dim_y, -1, 4U, c11_abs
              (chartInstance, c11_b_nates[2]) > c11_plate_dim_y))) {
          guard2 = true;
        } else {
          CV_EML_MCDC(0, 1, 0, false);
          CV_EML_IF(0, 1, 2, false);
        }
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 2, true);
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 21);
        c11_b_mod_sec_edit = 3.0;
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 22);
        c11_set_gravity(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 1);
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 23);
        c11_set_falloff_toggle(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 0);
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
      c11_b_mod_sec_edit = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 28);
      for (c11_i4 = 0; c11_i4 < 3; c11_i4++) {
        c11_nates[c11_i4] = c11_b_math_co[c11_i4];
      }

      _SFD_SYMBOL_SWITCH(1U, 1U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 29);
      guard1 = false;
      if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 5, c11_abs
            (chartInstance, c11_nates[0]), c11_b_plate_dim_x, -1, 4U, c11_abs
            (chartInstance, c11_nates[0]) > c11_b_plate_dim_x))) {
        guard1 = true;
      } else if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 6, c11_abs
                   (chartInstance, c11_nates[2]), c11_plate_dim_y, -1, 4U,
                   c11_abs(chartInstance, c11_nates[2]) > c11_plate_dim_y))) {
        guard1 = true;
      } else {
        CV_EML_MCDC(0, 1, 1, false);
        CV_EML_IF(0, 1, 3, false);
      }

      if (guard1 == true) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 3, true);
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 30);
        c11_b_mod_sec_edit = 3.0;
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 31);
        c11_set_gravity(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 1);
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 32);
        c11_set_falloff_toggle(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog_wrapper(chartInstance->S, 0);
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 36);
    c11_b_mod_sec_edit = 3.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c11_mod_sec_edit = c11_b_mod_sec_edit;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ballonplate_correctordinatesMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_mod_sec_edit, 4U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
}

static void mdl_start_c11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc11_ballonplate_correctordinates
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  (void)c11_chartNumber;
  (void)c11_instanceNumber;
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_b_mod_sec_edit, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_mod_sec_edit),
    &c11_thisId);
  sf_mex_destroy(&c11_b_mod_sec_edit);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_mod_sec_edit;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_b_mod_sec_edit = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_mod_sec_edit),
    &c11_thisId);
  sf_mex_destroy(&c11_b_mod_sec_edit);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i6;
  const mxArray *c11_y = NULL;
  real_T c11_u[3];
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i6 = 0; c11_i6 < 3; c11_i6++) {
    c11_u[c11_i6] = (*(real_T (*)[3])c11_inData)[c11_i6];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i7;
  const mxArray *c11_y = NULL;
  real_T c11_u[3];
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    c11_u[c11_i7] = (*(real_T (*)[3])c11_inData)[c11_i7];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3])
{
  real_T c11_dv0[3];
  int32_T c11_i8;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                3);
  for (c11_i8 = 0; c11_i8 < 3; c11_i8++) {
    c11_y[c11_i8] = c11_dv0[c11_i8];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nates;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i9;
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_nates = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nates), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_nates);
  for (c11_i9 = 0; c11_i9 < 3; c11_i9++) {
    (*(real_T (*)[3])c11_outData)[c11_i9] = c11_y[c11_i9];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static void c11_d_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[3])
{
  real_T c11_dv1[3];
  int32_T c11_i10;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c11_i10 = 0; c11_i10 < 3; c11_i10++) {
    c11_y[c11_i10] = c11_dv1[c11_i10];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nates;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i11;
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_nates = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nates), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_nates);
  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    (*(real_T (*)[3])c11_outData)[c11_i11] = c11_y[c11_i11];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray
  *sf_c11_ballonplate_correctordinates_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c11_nameCaptureInfo;
}

static real_T c11_abs(SFc11_ballonplate_correctordinatesInstanceStruct
                      *chartInstance, real_T c11_x)
{
  real_T c11_b_x;
  real_T c11_c_x;
  (void)chartInstance;
  c11_b_x = c11_x;
  c11_c_x = c11_b_x;
  return muDoubleScalarAbs(c11_c_x);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_e_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i12;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i12, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i12;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)
    chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_f_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_b_is_active_c11_ballonplate_correctordinates, const char_T
   *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_ballonplate_correctordinates), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_ballonplate_correctordinates);
  return c11_y;
}

static uint8_T c11_g_emlrt_marshallIn
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, const
   mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static real_T c11_get_falloff_toggle
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c11_elementIndex);
  return *chartInstance->c11_falloff_toggle_address;
}

static void c11_set_falloff_toggle
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_elementIndex, real_T c11_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c11_elementIndex);
  *chartInstance->c11_falloff_toggle_address = c11_elementValue;
}

static real_T *c11_access_falloff_toggle
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_rdOnly)
{
  real_T *c11_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c11_dsmAddr = chartInstance->c11_falloff_toggle_address;
  if (c11_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c11_dsmAddr;
}

static real_T c11_get_gravity(SFc11_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c11_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c11_elementIndex);
  return *chartInstance->c11__indexgravity_address;
}

static void c11_set_gravity(SFc11_ballonplate_correctordinatesInstanceStruct
  *chartInstance, uint32_T c11_elementIndex, real_T c11_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c11_elementIndex);
  *chartInstance->c11__indexgravity_address = c11_elementValue;
}

static real_T *c11_access_gravity
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance, uint32_T
   c11_rdOnly)
{
  real_T *c11_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c11_dsmAddr = chartInstance->c11__indexgravity_address;
  if (c11_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c11_dsmAddr;
}

static void init_dsm_address_info
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "falloff_toggle",
    (void **)&chartInstance->c11_falloff_toggle_address,
    &chartInstance->c11__indexf_toggle);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "gravity", (void **)
    &chartInstance->c11__indexgravity_address, &chartInstance->c11__indexy);
}

static void init_simulink_io_address
  (SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance)
{
  chartInstance->c11_mod_sec = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c11_mod_sec_edit = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_math_co = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_bounce_co = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c11_plate_dim_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c11_ballonplate_correctordinates_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2772985523U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2212913841U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(726459723U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3473790410U);
}

mxArray* sf_c11_ballonplate_correctordinates_get_post_codegen_info(void);
mxArray *sf_c11_ballonplate_correctordinates_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0sa9IUgBfVtgjhjmq6sPhB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c11_ballonplate_correctordinates_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_ballonplate_correctordinates_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_ballonplate_correctordinates_jit_fallback_info(void)
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

mxArray *sf_c11_ballonplate_correctordinates_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c11_ballonplate_correctordinates_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c11_ballonplate_correctordinates
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"mod_sec_edit\",},{M[8],M[0],T\"is_active_c11_ballonplate_correctordinates\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_ballonplate_correctordinates_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc11_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ballonplate_correctordinatesMachineNumber_,
           11,
           1,
           1,
           0,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"mod_sec");
          _SFD_SET_DATA_PROPS(1,1,1,0,"math_co");
          _SFD_SET_DATA_PROPS(2,1,1,0,"bounce_co");
          _SFD_SET_DATA_PROPS(3,1,1,0,"plate_dim_x");
          _SFD_SET_DATA_PROPS(4,2,0,1,"mod_sec_edit");
          _SFD_SET_DATA_PROPS(5,11,0,0,"falloff_toggle");
          _SFD_SET_DATA_PROPS(6,11,0,0,"gravity");
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
        _SFD_CV_INIT_EML(0,1,1,0,4,0,0,0,0,0,5,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1036);
        _SFD_CV_INIT_EML_IF(0,1,0,361,382,978,1018);
        _SFD_CV_INIT_EML_IF(0,1,1,391,406,689,969);
        _SFD_CV_INIT_EML_IF(0,1,2,481,552,-1,680);
        _SFD_CV_INIT_EML_IF(0,1,3,759,824,-1,957);

        {
          static int condStart[] = { 484, 496, 525 };

          static int condEnd[] = { 494, 523, 552 };

          static int pfixExpr[] = { 0, 1, -3, 2, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,484,552,3,0,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 762, 795 };

          static int condEnd[] = { 791, 824 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,762,824,2,3,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,364,382,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,394,406,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,484,494,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,496,523,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,525,552,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,762,791,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,795,824,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
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
    SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance =
      (SFc11_ballonplate_correctordinatesInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c11_mod_sec);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c11_mod_sec_edit);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c11__indexgravity_address);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c11_math_co);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c11_bounce_co);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c11_falloff_toggle_address);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_plate_dim_x);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sv35EN2yzQ1q8UsCjuGl37E";
}

static void sf_opaque_initialize_c11_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_ballonplate_correctordinatesInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
  initialize_c11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  enable_c11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  disable_c11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  sf_gateway_c11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c11_ballonplate_correctordinates
  (SimStruct* S)
{
  return get_sim_state_c11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c11_ballonplate_correctordinates(SimStruct*
  S, const mxArray *st)
{
  set_sim_state_c11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c11_ballonplate_correctordinates(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_ballonplate_correctordinatesInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ballonplate_correctordinates_optimization_info();
    }

    finalize_c11_ballonplate_correctordinates
      ((SFc11_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_ballonplate_correctordinates
    ((SFc11_ballonplate_correctordinatesInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_ballonplate_correctordinates(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_ballonplate_correctordinates
      ((SFc11_ballonplate_correctordinatesInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c11_ballonplate_correctordinates(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ballonplate_correctordinates_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 11);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1653139786U));
  ssSetChecksum1(S,(3689729805U));
  ssSetChecksum2(S,(1496135079U));
  ssSetChecksum3(S,(2794975057U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c11_ballonplate_correctordinates(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_ballonplate_correctordinates(SimStruct *S)
{
  SFc11_ballonplate_correctordinatesInstanceStruct *chartInstance;
  chartInstance = (SFc11_ballonplate_correctordinatesInstanceStruct *)utMalloc
    (sizeof(SFc11_ballonplate_correctordinatesInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc11_ballonplate_correctordinatesInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_ballonplate_correctordinates;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_ballonplate_correctordinates;
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
  mdl_start_c11_ballonplate_correctordinates(chartInstance);
}

void c11_ballonplate_correctordinates_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_ballonplate_correctordinates(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_ballonplate_correctordinates(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_ballonplate_correctordinates_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
