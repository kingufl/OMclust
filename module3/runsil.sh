#!/bin/bash
#SBATCH --qos=boucher-b
##SBATCH --partition=hpg2-compute
##SBATCH --mail-user=kingdgp@ufl.edu
#SBATCH --mail-type=ALL
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem=10gb
#SBATCH --time=1-00:00:00

ml gcc

./../bin/findsil.exe $kmerfile $1