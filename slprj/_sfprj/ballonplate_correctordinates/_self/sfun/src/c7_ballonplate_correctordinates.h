#ifndef __c7_ballonplate_correctordinates_h__
#define __c7_ballonplate_correctordinates_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_ballonplate_correctordinatesInstanceStruct
#define typedef_SFc7_ballonplate_correctordinatesInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_ballonplate_correctordinates;
  real_T *c7_u;
  real_T *c7_x;
  real_T *c7_x2;
  real_T *c7_y;
  real_T *c7_alpha_d;
  real_T *c7_beta_d;
  real_T *c7_time;
  real_T *c7_xd;
  real_T *c7_sine_step;
  real_T *c7_A;
  real_T *c7_step_size;
  real_T *c7_frequency;
  real_T *c7_mod_sec;
} SFc7_ballonplate_correctordinatesInstanceStruct;

#endif                                 /*typedef_SFc7_ballonplate_correctordinatesInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_ballonplate_correctordinates_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_ballonplate_correctordinates_get_check_sum(mxArray *plhs[]);
extern void c7_ballonplate_correctordinates_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
