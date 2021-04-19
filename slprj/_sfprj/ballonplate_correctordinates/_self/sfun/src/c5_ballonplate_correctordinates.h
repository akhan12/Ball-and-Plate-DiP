#ifndef __c5_ballonplate_correctordinates_h__
#define __c5_ballonplate_correctordinates_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_ballonplate_correctordinatesInstanceStruct
#define typedef_SFc5_ballonplate_correctordinatesInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_ballonplate_correctordinates;
  real_T *c5_count_address;
  int32_T c5__index;
  real_T *c5__indexgravity_address;
  int32_T c5__indexy;
  real_T (*c5__indexinitial_position_address)[3];
  int32_T c5__indexl_position;
  real_T (*c5__indexinitial_velocity_address)[3];
  int32_T c5__indexl_velocity;
  real_T *c5__indexx1_d_init_address;
  int32_T c5__indexnit;
  real_T *c5__indexx1_init_address;
  int32_T c5__indext;
  real_T *c5__indexx2_d_init_address;
  int32_T c5_b__indexnit;
  real_T *c5__indexx2_init_address;
  int32_T c5_b__indext;
  real_T *c5_init_mod_sec;
  real_T *c5_reset;
  real_T (*c5_bounce_co)[3];
  real_T (*c5_bounce_co_vel)[3];
  real_T *c5_model_sel;
} SFc5_ballonplate_correctordinatesInstanceStruct;

#endif                                 /*typedef_SFc5_ballonplate_correctordinatesInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_ballonplate_correctordinates_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_ballonplate_correctordinates_get_check_sum(mxArray *plhs[]);
extern void c5_ballonplate_correctordinates_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
