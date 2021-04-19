#ifndef __c12_ballonplate_correctordinates_h__
#define __c12_ballonplate_correctordinates_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc12_ballonplate_correctordinatesInstanceStruct
#define typedef_SFc12_ballonplate_correctordinatesInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_ballonplate_correctordinates;
  real_T *c12_u;
  real_T *c12_x;
  real_T *c12_x2;
  real_T *c12_y;
  real_T *c12_alpha_d;
  real_T *c12_beta_d;
  real_T *c12_time;
  real_T *c12_xd;
  real_T *c12_sine_step;
  real_T *c12_A;
  real_T *c12_step_size;
  real_T *c12_frequency;
  real_T *c12_mod_sec;
} SFc12_ballonplate_correctordinatesInstanceStruct;

#endif                                 /*typedef_SFc12_ballonplate_correctordinatesInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c12_ballonplate_correctordinates_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_ballonplate_correctordinates_get_check_sum(mxArray *plhs[]);
extern void c12_ballonplate_correctordinates_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
