#ifndef __c9_pendulumgui_h__
#define __c9_pendulumgui_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_pendulumguiInstanceStruct
#define typedef_SFc9_pendulumguiInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_pendulumgui;
  real_T *c9_n_address;
  int32_T c9__index;
  real_T *c9_theta1;
  real_T *c9_theta2;
  real_T *c9_theta1_d;
  real_T *c9_theta2_d;
  real_T *c9_y;
  real_T *c9_y_d;
  real_T *c9_y_dd;
  real_T *c9_E1;
  real_T *c9_E2;
  real_T *c9_time;
  real_T *c9_n_out;
  real_T *c9_u2;
  real_T *c9_selector;
} SFc9_pendulumguiInstanceStruct;

#endif                                 /*typedef_SFc9_pendulumguiInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_pendulumgui_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_pendulumgui_get_check_sum(mxArray *plhs[]);
extern void c9_pendulumgui_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
