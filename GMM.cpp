#include<iostream>
#include "GaussianMixture.h"
using namespace std;

int main(){
	const int number_data = 6; //The number of data points
	const int number_features = 3; //The number of features in the data array
	int nb_clusters = 3; //The expected number of clusters
	int max_iterations = 1000; //The maximum number of iterations
	string type_covariance = "full"; //The GMM covariance type. The current supported option is "full" only.
	int rndseed = 21; //The seed for the random generator. Fixing this seed prevents a potential convergeance to different clustering results upon different runs
	GaussianMixture *gmm;
	
	//The data matrix
	double **data = new double  * [number_data];
	for(int i=0; i<number_data; i++){
		data[i] = new double [number_features];
	}

	//Randomly initialize the data matrix
	cout<<"The initial matrix is:\n";
	srand(time(0));
	for(int i=0; i<number_data; i++){
		for(int j=0; j<number_features; j++){
			data[i][j] = double(rand())/double(RAND_MAX);
			cout<<"\t"<<data[i][j];
		}
		cout<<endl;
	}

	//Creating a GMM instance
	gmm = new GaussianMixture(nb_clusters,number_data, number_features, type_covariance,max_iterations,0.01,0.001,rndseed);
	//The resulting labels vector
	int *p = new int[number_data];
	//Training the the model
	(*gmm).train(data,p,number_data,number_features);

	//Display the clustering results
	cout<<endl<<"The GMM scored a BIC = "<<(*gmm).bic()<<" and an AIC = "<<(*gmm).aic()<<endl<<endl;
	for(int i=0; i<number_data; i++){
		cout<<"Data point "<<i<<" belongs to cluster "<<p[i]<<endl;
	}

	//Free dynamically allocated memory	
	for(int i=0; i<number_data; i++){
		delete[] data[i];
	}
	delete[] data;

	return 0;
}