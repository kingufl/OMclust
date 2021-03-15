# OMclust

------------------------------------------------------------------------------------------------------------

An Optical Map clustering method for finding overlapping Rmaps.

------------------------------------------------------------------------------------------------------------

Requirements:

1. Armadillo C++ library for linear algebra & scientific computing
   http://arma.sourceforge.net/download.html  
  
2. gcc 5.2.0 or later

-------------------------------------------------------------------------------------------------------------

Build OMclust using the make command. The executables are created in the bin directory. Note that the armadillo library needs to be loaded before building OMclust. You may need to edit the makefile to point to where the armadillo libraries are installed on your system. 

------------------------------------------------------------------------------------------------------------



Currently we offer three modules of OMclust. Here is a high level description of the modules. Further details about how to run each module including bash scripts are included in the readme files inside the respective folders.

**Module 1**

This module takes as input an Rmap file, number of clusters and m value and outputs related Rmaps and trained cluster centers. This is suitable when the number of clusters are known.

Input:

1. Rmap file in Valouev format
2. Number of clusters for training
3. m value :  minimum number of co-clustered kmers required for overlap call

Output:

1. Rmap relations
2. Trained cluster centers

------------------------------------------------------------------------------------------------------------

**Module 2**

This module takes Rmap file and a range of num_clusters as input and produces trained cluster centers for each along with key statistics and runtimes. This pipeline is suitable when the number of clusters is unknown and needs to be assessed. 

Input:

1. Rmap file in Valouev format
2. Range of cluster sizes

Output:

1. Silhouette scores, BIC statistics and runtimes report
2. Trained cluster centers for a range of cluster sizes

------------------------------------------------------------------------------------------------------------

**Module 3**

This module takes trained cluster centers and the m-value as input and produces Rmap relations as output. 
This pipeline is suitable when training has already been completed on the genome and the pretrained cluster centers are used to cluster new data from the same species. 
In particular, the results of module 2 can be used as input for this module. 

Input:

1. Rmap file in Valouev format
2. Trained cluster centers
3. m value :  minimum number of co-clustered kmers required for overlap call

Output:

1. Rmap relations

------------------------------------------------------------------------------------------------------------

**Format of input Rmap data**

The Rmap data needs to be in the Valoev format. In this format, an Rmap is written in three lines. The first line contains the Rmap id. The second line contains two fields for the restriction enzyme used, followed by tab separed Rmap fragments expressed in kilo base pair(kbp) values. The third line is empty. The following is an example of two Rmaps in this format.

Rmap_0
BspQI   BspQI    21.033 4.21 7.437 2.622 8.77 3.496 19.563 2.286 2.459 3.258 16.703 2.229 4.639 8.348 3.457 3.846 9.631 4.396 8.606 2.147 17.549 18.372 2.631 15.276 20.469 3.966 11.287 7.448 11.822 15.538 10.659 7.814 26.023 3.523 7.566 17.978 3.442 28.818 11.913 21.614 27.873 8.272 5.1 4.569 14.771 9.579 3.234 7.18 3.092 16.002 8.603

Rmap_1
BspQI   BspQI    1.421 18.748 2.062 2.547 2.717 6.756 7.907 1.48 3.646 3.73 11.801 2.769 13.357 5.216 17.814 4.003 3.103 5.167 12.715 7.376 6.883 3.633 8.857 8.662 7.215 2.65 10.669 28.57 1.894

------------------------------------------------------------------------------------------------------------

**Format of output Rmap relations**

The Rmap relations are written in the file Rmap_relations.txt. Each line carries the relations found for one Rmap. The line begins with the Rmap id followed by a colon. This is followed by related Rmap ids delimited by tabs. The following is an example for Rmap relations for Rmap with id Rmap_0

Rmap_0 : Rmap_882	Rmap_3922



