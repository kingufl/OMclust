#!/bin/bash

clustfile='num_clusters'
kmerfile='/blue/boucher/kingdgp/clustering/chinese_human/OMclust/data/ecoli/all_4mers.txt'

while read line;
do	
	outfile=ecoli$line.out
	sbatch --job-name=sil$i --output=sil$line --export=kmerfile=$kmerfile runsil.sh $outfile 
done < $clustfile