#!/bin/bash

num_clusters=2200
kfile='all_kmers.txt'

sbatch --job-name=ecoli$num_clusters --output=ecoli$num_clusters.out --export=kmerfile=$kfile runarma.sh $num_clusters
