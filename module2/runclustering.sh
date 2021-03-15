#!/bin/bash

clustfile='num_clusters'
kfile='all_kmers.txt'

while read line;
do	
	sbatch --job-name=ecoli$line --output=ecoli$line.out --export=kmerfile=$kfile runarma.sh $line
done < $clustfile