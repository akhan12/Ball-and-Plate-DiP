#ifndef __c3_ballonplate_correctordinates_h__
#define __c3_ballonplate_correctordinates_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ballonplate_correctordinatesInstanceStruct
#define typedef_SFc3_ballonplate_correctordinatesInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_ballonplate_correctordinates;
  real_T *c3_gravity_address;
  int32_T c3__indexy;
  real_T *c3_mod_sec;
  real_T (*c3_y)[3];
  real_T (*c3_bounce_co)[3];
  real_T (*c3_math_co)[3];
} SFc3_ballonplate_correctordinatesInstanceStruct;

#endif                                 /*typedef_SFc3_ballonplate_correctordinatesInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_ballonplate_correctordinates_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_ballonplate_correctordinates_get_check_sum(mxArray *plhs[]);
extern void c3_ballonplate_correctordinates_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
