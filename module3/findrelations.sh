#!/bin/bash

rmapfile='/blue/boucher/kingdgp/clustering/arma_cluster_ecoli/ecoli_cov300.val'
infofile='kmerinfo.txt'
clusterfile='ecoli2200.out.cluster_assignments'
mvalue=6

./../src/findrels $rmapfile $infofile $clusterfile $mvalue 