#ifdef _NN1_H_

#define NUMHID 3

//NN data
static float NN_out[3];
static float W[NUMHID][3] = 0//, **V = 0; // static float W[][];

//learning rates
static float rate = 0.01;
static float f = 0.01;
static float kappa = 0.01;
static float lambda = 0.01;

//calculated and given values
static float previous_error_att[3] = 0;

double sigma(float value);
void NN_update(float *nu, float *target_nu, float delta_time);
void NN_update_weights(float r_mag_att, float delta_time);

#endif