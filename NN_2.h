#ifdef _NN2_H_

#define NUMHID 3

//NN data
static float NN_out[3];
static float W[NUMHID][3][2] = 0//, **V = 0; // static float W[][];
static float V[NUMHIT][3] = 0;
static float node[NUMHID][3];

//learning rates
static float rate = 0.01;
static float f = 0.01;
static float kappa = 0.01;
static float lambda = 0.01;

//calculated and given values
static float previous_error_att[3] = 0;


double sigma(float value);
void NN2_update(float *nu, float *target_nu, float delta_time);
void NN2_update_weights(float r_mat_att, float delta_time);

#endif