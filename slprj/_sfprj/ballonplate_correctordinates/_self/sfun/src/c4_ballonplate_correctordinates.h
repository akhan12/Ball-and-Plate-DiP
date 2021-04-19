#ifndef __c4_ballonplate_correctordinates_h__
#define __c4_ballonplate_correctordinates_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_ballonplate_correctordinatesInstanceStruct
#define typedef_SFc4_ballonplate_correctordinatesInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_ballonplate_correctordinates;
  real_T *c4_gravity_address;
  int32_T c4__indexy;
  real_T *c4_mod_sec;
  real_T *c4_S_p1;
  real_T *c4_S_p2;
  real_T *c4_err_x;
  real_T (*c4_bounce_co)[3];
  real_T (*c4_math_co)[2];
  real_T *c4_err_y;
} SFc4_ballonplate_correctordinatesInstanceStruct;

#endif                                 /*typedef_SFc4_ballonplate_correctordinatesInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_ballonplate_correctordinates_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_ballonplate_correctordinates_get_check_sum(mxArray *plhs[]);
extern void c4_ballonplate_correctordinates_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
