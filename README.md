# OMclust

------------------------------------------------------------------------------------------------------------

An Optical Map clustering method for finding overlapping Rmaps.

------------------------------------------------------------------------------------------------------------

Requirements:

1. Armadillo C++ library for linear algebra & scientific computing
   http://arma.sourceforge.net/download.html  
  
2. gcc 5.2.0 or later

-------------------------------------------------------------------------------------------------------------

Module 1

Input:

1. Rmap file in Valouev format
2. Number of clusters for training
3. m value :  minimum number of co-clustered kmers required for overlap call

Output:

1. Rmap relations
2. Trained cluster centers

------------------------------------------------------------------------------------------------------------

Module 2

Input:

1. Rmap file in Valouev format
2. Coverage of data

Output:

1. Silhouette scores and BIC statistics report
2. Trained cluster centers for a range of cluster sizes

------------------------------------------------------------------------------------------------------------

Module 3

Input:

1. Rmap file in Valouev format
2. Trained cluster centers
3. m value 

Output:

1. Related Rmap calls

