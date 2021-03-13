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

std::ifstream datafile(argv[1]);
std::ifstream outputfile(argv[2]);

string str;

while(getline(datafile,str)){

		stringstream sss(str);vector<float> temp;float temfl;
		while(sss>>temfl)
			temp.push_back(asinh(temfl));

		data.push_back(temp);

}

//cout<<"Data read"<<endl;

int countmeans=0;


//ofstream outfile("spam");

while(getline(outputfile,str)){

            if(str.find("means")==0){
                std::vector< std::vector<float> > readmeans;

                cluster_to_kmer.clear();
                //cout<<"foundmins"<<endl;
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

                //cout<<"readmeans"<<endl;


                std::vector<int> assignedclusters;

                cluster_to_kmer.resize(readmeans[0].size());


                getline(outputfile,str);
                std::stringstream ssss(str);
                int clustid;
                int kmer_id=0;

                while(ssss>>clustid){
                    assignedclusters.push_back(clustid);
                    cluster_to_kmer[clustid].push_back(kmer_id++);
                }

                //cout<<"read_assigned_clusters"<<endl;

                pointVec points;

                for(int i=0;i<readmeans[0].size();i++){

                    point_t newpt;
                    for(int ii=0;ii<readmeans.size();ii++){
                        newpt.push_back(readmeans[ii][i]*1000);
                    }
                    points.push_back(newpt);
                }

                KDTree tree(points);
                std::vector<int> secondclusters;

                for(int i=0;i<data.size();i++){

                    point_t newpt;
                    for(int ii=0;ii<data[i].size();ii++){
                        newpt.push_back(data[i][ii]*1000);
                    }
                    secondclusters.push_back(tree.nearest_index(newpt,points[assignedclusters[i]]));

                 }



                double tot=0;
                int numkmers=0;
                int neg=0;
                for(int i=0;i<data.size();i++){

            //        cout<<i<<" "<<assignedclusters[i]<<" "<<secondclusters[i]<<endl;
            //        break;
                    double dista = finddis(i,assignedclusters[i]);
                    double distb = finddis(i,secondclusters[i]);

                    if(dista==0){
                        //cout<<dista<<" "<<dista<<" "<<dista<<" "<<dista<<" "<<tot/(i+1)<<endl;
                        continue;
                    }

                        //cout<<"Issue "<<i<<" "<<secondclusters[i]<<" "<<cluster_to_kmer[secondclusters[i]].size()<<" "<<assignedclusters[i]<<endl;
                    if(dista==0 || distb==0)
                        continue;
                    tot+=(distb-dista)/std::max(dista,distb);
                    //outfile<<countmeans<<" "<<dista<<" "<<distb<<" "<<(distb-dista)/std::max(dista,distb)<<" "<<tot/(i+1)<<endl;
                    numkmers++;

                    if((distb<dista))
                        neg++;

                }

                std::cout<<std::fixed<<"Sil: "<<readmeans[0].size()<<" "<<countmeans<<" "<<tot/numkmers<<" "<<(float)100*neg/numkmers<<" "<<neg<<" "<<numkmers<<endl;

                countmeans++;


            }

}

}

