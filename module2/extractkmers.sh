#!/bin/bash

rmapfile='/blue/boucher/kingdgp/clustering/arma_cluster_ecoli/ecoli_cov300.val'
kmerval=4

./../src/exkmers $rmapfile $kmerval