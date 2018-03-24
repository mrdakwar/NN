// NN.c

#include "NN_2.h"

void NN2_update(float *nu, float *target_nu){
	
	int i;

	float error_att[3];
	float r_att[3];
	float node_value;
	float r_mag_att;

	for(i = 0; i < 3; i++){
		error_att[i] = target_nu[i] - nu[i];	//calculate error
		
		//calculate r input
		r_att[i] = ( error_att[i] - previous_error_att[i]) / delta_time + lambda_att * error_att[i];
		//update previous error
		previous_error_att[i] = error_att[i];
		
		//forward propogate for each output
		for(j = 0; j < NUMHID; j++){
			node[i][j] = sigma( W[i][j][0] * nu[j] + W[i][j][1] * r_att[j]);
			NN_out[i] = V[i][j] * node[i][j];
			}
	}
	r_mag_att = (r_att[0]+r_att[1]+r_att[2])/3.0;

	NN_update_weights(r_mag_att);
}


void NN2_update_weights(){
	int i, j;

	for(j = 0; j < 3; j ++){
			for(i = 0; i < NUMHID; i++){
				V[i][j] += ( f * sigma(node[i][j]) * r_att[i] )/delta_time;	
				W[i][j][0] += g*nu[j]*sigma(W[i][j][0])(1 - sigma(W[i][j][0]))*W[i][j] * r_att[j];
				W[i][j][1] += g*nu[j]*sigma(W[i][j][1])(1 - sigma(W[i][j][1]))*W[i][j] * r_att[j];
				}
		}
}



double sigma(double value){
	return 1.0/(1.0 - exp(value));
}