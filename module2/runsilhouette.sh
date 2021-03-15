#!/bin/bash

clustfile='num_clusters'
kmerfile='all_kmers.txt'

while read line;
do	
	outfile=ecoli$line.out
	sbatch --job-name=sil$i --output=sil$line --export=kmerfile=$kmerfile runsil.sh $outfile 
done < $clustfile