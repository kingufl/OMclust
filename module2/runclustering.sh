#!/bin/bash

clustfile='num_clusters'
kfile='/blue/boucher/kingdgp/clustering/chinese_human/OMclust/data/ecoli/all_4mers.txt'

while read line;
do	
	sbatch --job-name=ecoli$line --output=ecoli$line.out --export=kmerfile=$kfile runarma.sh $line
	##outfile=ecoli$line.out
	##sbatch --job-name=sil$i --output=sil$i.out --export=outfile=$outfile runsil.sh
done < $clustfile