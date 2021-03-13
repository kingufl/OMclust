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

float threshold_rep_nodes=40;
int rangefut=8;
int multiplicity=5;

vector <int> covered;

vector<int> fun_vec_read;

vector< vector<float> > real_values;

vector<int> fun_vec_write;

vector <string> neighs;

vector< set < int > > path_tracker;

vector< vector <int> > final_contigs;

vector< vector < int > > future_of_contigs;

vector < vector< set < int > > > complete_future;


vector< vector <float> > final_contigs_real;

vector< vector <int> > final_contig_omgrams;

vector <int>  lng_contig;
vector <float>  lng_contig_real;

vector< int > long_contig_kmers;


set < int > futures;

set < int > start_nodes;

vector <int> nodes_in_path;

vector< vector<float> > not_sure;


vector<float> this_stitch;
vector<int> this_stitch_nodes;

vector< vector<int> > contig_nodes;
vector<bool> nodes_covered_start;
vector<bool> nodes_covered_ctnd;

//vector < pair<int ,int> > optimized_overlap_alignment(vector< float >& rmap1, vector< float >& rmap2);

int min(int a,int b){

    if(a<=b)
        return a;
    else
        return b;
}

int max(int a,int b){

    if(a>=b)
        return a;
    else
        return b;
}


int main(int argc, char *argv[]){

    if(argc<3){
	cout<<"usage: ./extractkmers <rmap_file> <kmer_size>"<<endl;
	return(1);}

	int buck=2;;

    int kmer_size = atoi(argv[2]);



    string str;


	vector < vector < vector <float> > > bilabel_container;

	vector < vector < int > > bilabel_freq;

	map<string,int> bilabel_pair_map;

	int rmap_no=0;

	int lastpairmapped=0;

	vector<string> bilabelsums;

	ifstream infile(argv[1]);

	int totnumoffrags=0;

    ofstream kmerfile("all_kmers.txt");
    ofstream info("kmerinfo.txt");

    while (getline(infile,str)){

        istringstream ss1(str);

        string rmap_name;
        ss1>>rmap_name;

        getline(infile,str);
        istringstream ss2(str);

        string dummy;
        ss2>>dummy;
        ss2>>dummy;
        float input;

        vector<float> temp;
        vector<int> tem_int;


        rmap_no++;

        while(ss2>>input){
            totnumoffrags++;

            if(input>1000 || input<0)
                cout<<rmap_no<<" "<<input<<endl;

            temp.push_back(input);
            tem_int.push_back((round(input/buck))*buck);
        }

        if(temp.size()<kmer_size+3){
            getline(infile,str);
            continue;
        }


        vector<int> tem_int_rev;
        vector<float> temp_rev;
        for(int i=tem_int.size()-1;i>=0;i--){

            tem_int_rev.push_back(tem_int[i]);
            temp_rev.push_back(temp[i]);
        }

        for(int i=0;i<temp.size()-kmer_size+1;i++){

            for(int j=i;j<i+kmer_size;j++){
                kmerfile<<temp[j]<<" ";
            }
            kmerfile<<endl;
            info<<rmap_name<<endl;

        }


        getline(infile,str);


    }

    cout<<"Total no of frags: "<<totnumoffrags<<endl;


}
