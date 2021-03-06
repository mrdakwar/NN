// NN.c

#include "NN.h"

void NN_update(float *nu, float *target_nu, float delta_time){
	
	int i;

	float error_att[3];
	float r_att[3];
	float node_value;
	float r_mag_att;

	for(i = 0; i < 3; i++){
		error_att[i] = target_nu[i] - nu[i];	//calculate error
		
		//calculate r input
		r_att[i] = ( error_att[i] - previous_error_att[i]) / delta_time + lambda * error_att[i];
		//update previous error
		previous_error_att[i] = error_att[i];
		//calculate node value
		node_value = sigma(r_att[i] + nu[i]);
		
		//forward propogate for each output
		for(j = 0; j < NUMHID; j++){
			NN_out[i] += node_value * W[j][i];
			}
	}
	r_mag_att = (r_att[0]+r_att[1]+r_att[2])/3.0;

	NN_update_weights(r_mag_att);
}


void NN_update_weights(float r_mag_att, float delta_time){
	int i, j;

	for(i = 0; i < 3; i ++){
			for(j = 0; j < NUMHID; j++){
				W[j][i] += ( f * output[i] * r_att[i] - kappa * r_mag_att * f * W[j][i] )/delta_time;
			}
		}

}

double sigma(float value){
	return 1.0/(1.0 - exp(value));
}