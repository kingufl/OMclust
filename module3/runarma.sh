#!/bin/bash
#SBATCH --qos=boucher-b
##SBATCH --partition=hpg2-compute
##SBATCH --mail-user=kingdgp@ufl.edu
#SBATCH --mail-type=ALL
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=64
#SBATCH --mem=10gb
#SBATCH --time=4-00:00:00

ml armadillo
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HPC_ARMADILLO_LIB
export LD_LIBRARY_PATH

/usr/bin/time -v /blue/boucher/kingdgp/clustering/chinese_human/OMclust/bin/clustering.exe $kmerfile $1