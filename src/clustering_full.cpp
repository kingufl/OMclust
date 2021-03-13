#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include <string>

#include <armadillo>
using namespace arma;

int main(int argc, char* argv[])
{

	std::ifstream kmerfile(argv[1]);
	int onebin=atoi(argv[2]);
	std::string str;

    std::vector<int> bins;
    bins.push_back(onebin);
//    while(getline(binsfile,str)){
//        std::stringstream sss(str);
//        int temin;
//        sss>>temin;
//        bins.push_back(temin);
//    }

	std::vector< std::vector <double> > rowvec;

	while(getline(kmerfile,str)){

		std::stringstream sss(str);
		float temp;
		std::vector<double> temvec;
		while(sss>>temp){
			temvec.push_back(temp);
		}

		rowvec.push_back(temvec);

	}



// model the data as a diagonal GMM with #bins clusters

mat originaldata(rowvec[0].size(), rowvec.size()); // holds the original values of the datapoints

for(size_t i=0;i<rowvec.size();i++){ // random sampling for bootstrapping

		std::vector<double> temvecori=rowvec[i]; // choose index corresponding to i
		vec colvecori(temvecori);
		originaldata.col(i)=colvecori;

}

mat dataasinhori=asinh(originaldata); // transformed by asinh


int j=0;

int loops=0;
double avgbic=0;
double databic[3];

while(true){

time_t ostart = clock();

if(loops==3)
	break;

srand(time(NULL));
//std::cout<<"time: "<<time(NULL)<<endl;

gmm_full model;
bool status = model.learn(dataasinhori, bins[j], eucl_dist, random_subset,10, 5, 1e-10, false); // build model with randomly sampled points

time_t training_end = clock();

if(status == false) { cout << "learning failed" << endl; }
model.means.print("means:");

time_t assign_start = clock();


urowvec assignments = model.assign(dataasinhori,eucl_dist);

time_t assign_end = clock();

assignments.print();

double sumlogpori=model.sum_log_p(dataasinhori); // this returns the sum of the logarithmic likelihoods using the original points

//std::cout<<bins<<" "<<bic<<endl;

double bicori = bins[j]*log(rowvec.size()) - 2*sumlogpori; // compute bic with original points - this is the value that is used finally

databic[loops]=bicori;

avgbic+=bicori;

std::cout<<std::fixed<<"logp "<<bins[j]<<" "<<sumlogpori<<" "<<bicori<<" "<<loops<<" "<<avgbic/(loops+1)<<" "<<double(training_end-ostart) / CLOCKS_PER_SEC<<" "<<double( assign_end-assign_start) / CLOCKS_PER_SEC<<endl;

loops++;

if(loops==3)
    break;

}

}

