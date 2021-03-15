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
#include <bits/stdc++.h>
#include <climits>
#include "KDTree.hpp"
#include <math.h>

using namespace std;

vector< vector<int> > cluster_to_kmer;

inline double dist2(const vector<float> &a, vector<float> &b) {
    double distc = 0;
    for (size_t i = 0; i < a.size(); i++) {
        double di = a.at(i) - b.at(i);
        distc += di * di;
    }
    return sqrt(distc);
}

vector<vector<float> > data;

double finddis(int i,int clusid){
    double total=0;
    int num=0;
    for(int ii=0;ii<cluster_to_kmer[clusid].size();ii++){
        if(cluster_to_kmer[clusid][ii]==i)
            continue;

        total+=dist2(data[i],data[cluster_to_kmer[clusid][ii]]);
        num++;
    }

    if(num==0){
        //cout<<endl<<"Issue "<<i<<" "<<clusid<<endl;

        return 0;
    }

    return total/num;

}

int main(int argc, char *argv[]){

std::ifstream datafile(argv[1]); // kmers file
std::ifstream outputfile(argv[2]); // cluster centers

string str;

while(getline(datafile,str)){

		stringstream sss(str);vector<float> temp;float temfl;
		while(sss>>temfl)
			temp.push_back(asinh(temfl));

		data.push_back(temp);

}

//cout<<"Data read"<<endl;

int countmeans=0;


std::vector< std::vector<float> > readmeans;

cluster_to_kmer.clear();
int cntmeans=0;

while(cntmeans<4){
    getline(outputfile,str);
    std::stringstream sss(str);
    std::vector<float> temp;
    float temfl;

    while(sss>>temfl)
        temp.push_back(temfl);

    readmeans.push_back(temp);
    cntmeans++;
}



std::vector<int> assignedclusters;

pointVec points;

for(int i=0;i<readmeans[0].size();i++){

    point_t newpt;
    for(int ii=0;ii<readmeans.size();ii++){
        newpt.push_back(readmeans[ii][i]*1000);
    }
    points.push_back(newpt);
}

KDTree tree(points);

for(int i=0;i<data.size();i++){

    point_t newpt;
    for(int ii=0;ii<data[i].size();ii++){
        newpt.push_back(data[i][ii]*1000);
    }
    assignedclusters.push_back(tree.nearest_index_nod2(newpt,newpt));

 }

for(int i:assignedclusters){
    cout<<i<<"\t";
}



}

