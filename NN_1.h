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
static float delta_time;
static float *nu_previous = 0;
static float *nu;
static float *target_nu;


double sigma(double value);
void NN_update(float *nu, float *target_nu);
void NN_update_weights();

#endif