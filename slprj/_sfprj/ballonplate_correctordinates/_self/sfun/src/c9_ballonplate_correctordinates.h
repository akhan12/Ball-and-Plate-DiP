#ifndef __c9_ballonplate_correctordinates_h__
#define __c9_ballonplate_correctordinates_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_ballonplate_correctordinatesInstanceStruct
#define typedef_SFc9_ballonplate_correctordinatesInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_ballonplate_correctordinates;
  real_T *c9_count_mm_address;
  int32_T c9__indexmm;
  real_T *c9__indexgravity_address;
  int32_T c9__indexy;
  real_T (*c9__indexinitial_position_address)[3];
  int32_T c9__indexl_position;
  real_T (*c9__indexinitial_velocity_address)[3];
  int32_T c9__indexl_velocity;
  real_T *c9_t;
  real_T *c9_bp_x;
  real_T (*c9_ball_position_new)[3];
  real_T *c9_bp_y;
  real_T *c9_bp_z;
  real_T *c9_bv_x;
  real_T *c9_bv_y;
  real_T *c9_bv_z;
  real_T *c9_reset;
  real_T (*c9_x_vec)[3];
  real_T (*c9_y_vec)[3];
  real_T *c9_pos_reset;
  real_T *c9_init_reset;
  real_T *c9_m;
  real_T *c9_r;
  real_T *c9_rest;
} SFc9_ballonplate_correctordinatesInstanceStruct;

#endif                                 /*typedef_SFc9_ballonplate_correctordinatesInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_ballonplate_correctordinates_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_ballonplate_correctordinates_get_check_sum(mxArray *plhs[]);
extern void c9_ballonplate_correctordinates_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
