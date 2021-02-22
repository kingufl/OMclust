# OMclust

------------------------------------------------------------------------------------------------------------

An Optical Map clustering method for finding overlapping Rmaps.

------------------------------------------------------------------------------------------------------------

Requirements:

1. Armadillo C++ library for linear algebra & scientific computing
   http://arma.sourceforge.net/download.html  
  
2. gcc 5.2.0 or later

-------------------------------------------------------------------------------------------------------------

Input:

1. Rmap file in Valouev format
2. Number of clusters for training
3. m value :  minimum number of co-clustered kmers required for overlap call

------------------------------------------------------------------------------------------------------------

Optional parameters:

1. 2. k-mer size. Default value is 4.
2. cluster_type : For training the data, armadillo provides an option between gmm_diag() and gmm_full(). The former uses an efficient gmm_clustering where the co-variance matrix only consists of diagonal elements - making the clusters speherical in shape. Alternatively, the gmm_full() can be used. It uses a full covariance matrix and hence can be used to represent different cluster shapes at the cost of some increase in the running time. 
