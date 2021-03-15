#!/bin/bash

rmapfile='./../ecoli_rmaps.val'
infofile='kmerinfo.txt'
clusterfile='cluster_assignments'
mvalue=6

./../bin/findrels.exe $rmapfile $infofile $clusterfile $mvalue 