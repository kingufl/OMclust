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

#define NDEBUG
#include <cassert>

#define Pi 3.14159265
#define pi 3.14156

// d as genomic distance

using namespace std;


int overlap(int s1,int e1, int s2, int e2){

    if(s1<=s2 && e1>=e2){
        return (e2-s2);
    }
    else if(s2<=s1 && e2>=e1){
        return (e1-s1);
    }
    else if(s1<=s2 && e1<=e2){
        return (e1-s2);
    }
    else if(s2<=s1 && e1>=e2){
        return (e2-s1);
    }
    else{
        cout<<"weird case"<<endl;
        return 0;
    }


}

int main(int argc, char* argv[]){
// usage parameters: <rmap_file_in_valouev_format> <info_file> <clusterfile(assignments)> <m_value>
    vector<int> cluster_assignment;
    vector<string> rmap_belong;


    map<string,int> nameid;
     map<int,string> revid;
    int lastname=0,rmap_cnt=0;

    ifstream valfile(argv[1]);

    string str;

    while(getline(valfile,str)){
        stringstream ss11(str);

        ss11>>str;
        if(nameid.find(str)==nameid.end()){
            revid[lastname]=str;
            nameid[str]=lastname++;
        }

        getline(valfile,str);

        stringstream ss12(str);

        string dummy;
        float f1;

        ss12>>dummy>>dummy;

        ss12>>f1;

        rmap_cnt++;

        getline(valfile,str);
    }

    string sttt;

    ifstream clusterfile(argv[3]);

    int maxcluster=0;
    getline(clusterfile,sttt);
    stringstream stss(sttt);
    int cl;

    while(stss>>cl){

        cluster_assignment.push_back(cl+1);

        if(cl+1>maxcluster)
            maxcluster=cl+1;

    }

    vector < vector <int> > rmap_to_cluster;

    vector < vector <int> > cluster_to_rmap;

    vector<int> temp;

    cluster_to_rmap.resize(maxcluster,temp);

    ifstream rmapfile(argv[2]);

    int lineno=0;

    rmap_to_cluster.resize(rmap_cnt,temp);

    while(getline(rmapfile,sttt)){

        rmap_belong.push_back(sttt);

        rmap_to_cluster[nameid.find(sttt)->second].push_back(cluster_assignment[lineno]);

        lineno++;

    }


    for(int i=0;i<cluster_assignment.size();i++){

        cluster_to_rmap[cluster_assignment[i]-1].push_back(nameid.find(rmap_belong[i])->second);


    }


    int mvalue=atoi(argv[4]);

    for(int dval=mvalue;dval<=mvalue;dval++){

    int numrmaps = rmap_to_cluster.size();

    string relstr="relations";
    stringstream relsss;
    relsss<<relstr<<dval;

    ofstream relsfile(relsss.str().c_str());

	relsfile<<"#skip_line"<<endl;

    ofstream rmaprels("Rmap_relations.txt");

    vector< vector <int> > found_rels(numrmaps,temp);


    for(int i=0;i<rmap_to_cluster.size();i++){

        rmaprels<<revid[i]<<" : ";

        int numfound=0;

        vector<int> relation_vector(numrmaps,0);
        vector<int> collect_relations;

        for(int j=0;j<rmap_to_cluster[i].size();j++){

            int cluster=rmap_to_cluster[i][j]-1;

//            cout<<i<<" "<<j<<" "<<cluster_to_rmap[cluster].size()<<endl;
            for(int k=0;k<cluster_to_rmap[cluster].size();k++){
                int otherrmap = cluster_to_rmap[cluster][k];
                relation_vector[otherrmap]++;

                if(relation_vector[otherrmap]==dval && otherrmap!=i){
                    numfound++;
                    collect_relations.push_back(otherrmap);
                }


            }


        }

        if(true){
            found_rels[i]=collect_relations;
            for(int ii=0;ii<collect_relations.size();ii++){
                    int otherrmap=collect_relations[ii];
                    rmaprels<<revid[otherrmap]<<"\t";
                    relsfile<<i<<" -- "<<otherrmap<<" -- "<<relation_vector[otherrmap]<<endl;


            }

        }
        rmaprels<<endl;


    }


    }

}
