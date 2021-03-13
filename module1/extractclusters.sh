#!/bin/bash

training_output_file='ecoli2200.out'

sed -n '6p' $training_output_file > $training_output_file.cluster_assignments
sed -n '2,5p' $training_output_file > $training_output_file.cluster_centers
	
