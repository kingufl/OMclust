all: bin/OMclust

bin/OMclust:
	mkdir bin
	g++ src/extract_kmers.cpp -o bin/exkmers
	g++ -O2 -L$(HPC_ARMADILLO_LIB) -larmadillo -I$(HPC_ARMADILLO_INC) -fopenmp src/clustering.cpp  -o bin/clustering2.exe
	g++ -std=c++11 src/silhouette.cpp src/KDTree.cpp -o  bin/findsil
	g++ -std=c++11 src/find_relations.cpp -o bin/findrels
	
clean: 
	rm -rf bin