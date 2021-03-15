#!/bin/bash

kmerfile='all_kmers.txt'
clustercenterfile='./../module1/ecoli2200.out.cluster_centers'

./../bin/assign_cluster.exe $kmerfile $clustercenterfile > cluster_assignments