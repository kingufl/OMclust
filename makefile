all: bin/OMclust

bin/OMclust:
	mkdir bin
	g++ src/extract_kmers.cpp -o bin/exkmers.exe
	g++ -O2 -L$(HPC_ARMADILLO_LIB) -larmadillo -I$(HPC_ARMADILLO_INC) -fopenmp src/clustering.cpp  -o bin/clustering.exe
	g++ -std=c++11 src/silhouette.cpp src/KDTree.cpp -o  bin/findsil.exe
	g++ -std=c++11 src/assign_cluster.cpp src/KDTree.cpp -o  bin/assign_cluster.exe
	g++ -std=c++11 src/find_relations.cpp -o bin/findrels.exe
	
clean: 
	rm -rf bin