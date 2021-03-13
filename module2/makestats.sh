#!/bin/bash

cat sil* |  awk '{print $2, $4, $5}' > allsil.txt

grep 'logp' *.out |  awk '{print $2, $4}' > allbic.txt

grep 'logp' *.out |  awk '{print $2, $7, $8}' > allruntimes.txt

for f in *.out;
do
	sed -n '6p' $f > $f.cluster_assignments
	sed -n '2,5p' $f > $f.cluster_centers
	
done
