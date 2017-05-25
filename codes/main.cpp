# include "headFile.h"

int main(int argc, char** argv) {
	vector<StuPairs> stuPairVectorReadFromFile;
	string filename;
	string filenameHead = "pairs";
	string filenameEnd = ".dat";
	int i = 0; // iterator variable
	int continueFlag = 0;  // The variable used to determine whether the program continues execution
	int listHeadArraySize = 0; 
	int originalStuPairVectorSize = 0;
	int maxStepSize = 0;
	int hashSize = 0;
	int sidPosition = 0;
	StuPairs tempStuPair;
	StuPairs* stuPairsArray;
	ListHead* listHeadArray;
	ListHeadHashTable* listHeadHashTable;
	
	clock_t start, finish;  
	double duration = 0.0;
	
	cout << "*******************************************###***" << endl;
	cout << " On-machine Exercise                            *" << endl;
	cout << " Mission 1: Build adjacency lists               *" << endl;
	cout << " Mission 2: Find connected components           *" << endl;
	cout << "*******************************************###***" << endl;
	cout << "##############################################################" << endl;
	cout << "Mission 1: Build adjacency lists" << endl;
	cout << "##############################################################" << endl << endl;
	
	cout << "Input the file name (e.g., 600a, 601, 602a): [0]Quit" << endl;
  	cin >> filename ;
  	
  	start = clock();
  	while ( filename != "0" ) {
	    /*
			Read the student information file, split each single student information 
			and then store each single student information into a stuInfo Structre.
			push_back each stu info structure into the stuInfoVector
		*/	
	   	while( ReadBinaryFile(stuPairVectorReadFromFile, filenameHead + filename + filenameEnd).empty() ) // generate the input .txt file name
		{
			cout << filenameHead + filename + filenameEnd << " does not exist!!!" << endl << endl;
			cout <<"Input the file name (e.g., 600a, 601, 602a): [0]Quit" << endl;
			cin >> filename;
		}
		
		originalStuPairVectorSize = stuPairVectorReadFromFile.size();
		for(i = 0; i < originalStuPairVectorSize; i++)
		{
			strcpy(tempStuPair.sid_two, stuPairVectorReadFromFile[i].sid_one);
			//tempStuPair.sid_two = stuPairVectorReadFromFile[i].sid_one;
			strcpy(tempStuPair.sid_one, stuPairVectorReadFromFile[i].sid_two);
			//tempStuPair.sid_one = stuPairVectorReadFromFile[i].sid_two;
			tempStuPair.weight = stuPairVectorReadFromFile[i].weight;
			
			stuPairVectorReadFromFile.push_back(tempStuPair);
		}
		
		if( (stuPairsArray = (StuPairs*)calloc(stuPairVectorReadFromFile.size(), sizeof(StuPairs)) ) == NULL )
		{
			printf("calloc unsuccessful\n");
			exit(0);
		}
		
		for(i = 0; i < stuPairVectorReadFromFile.size(); i++)
		{
			stuPairsArray[i] = stuPairVectorReadFromFile[i];
		}
		
		/*
			 using sid_one sort the student pairs array
		*/ 
		HeapSort(stuPairsArray, stuPairVectorReadFromFile.size(), true);  
		/*
			create adjacency list
		*/
		listHeadArray = CreateAdjacencyList(stuPairsArray, stuPairVectorReadFromFile.size(), listHeadArray, listHeadArraySize);
		/*
			output adjacency list to file
		*/
		OutputBinaryFile(listHeadArray, listHeadArraySize, filename);		
		
		printf("<<< %d  pairs => %d nodes >>>\n\n", stuPairVectorReadFromFile.size() / 2, stuPairVectorReadFromFile.size());
		printf("Adjacency lists are written into a file...\n\n\n") ;
		
		
		/*
			Using double hashing method to create a hash table, 
			associate each sid with its address in the listHeadArray. 
			Make it more quickly to get its list node by input a sid
		*/
		listHeadHashTable = CreateSidHashTable(listHeadArray, listHeadArraySize, maxStepSize, hashSize, listHeadHashTable);
		
		printf("<<< There are %d nodes in total. >>>\n\n", stuPairVectorReadFromFile.size());
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "Mission 2: Find connected components" << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
		/*
			DFS traverse the adjacency list, and output the result
		*/
		DFSTraversal(listHeadArray, listHeadArraySize, listHeadHashTable, maxStepSize, hashSize);
				
		/**/
		
		cin.clear();
		stuPairVectorReadFromFile.clear();
		stuPairsArray = NULL;
		listHeadArray = NULL;
				
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;  
  	 	printf( "%lf seconds\n", duration );  
  	 	
		cout << "[0]Quit or [Any other key]continue?" << endl;
	    scanf("%d", &continueFlag);
	    
	    if(continueFlag == 0)
	    {
	    	free(stuPairsArray);
			free(listHeadArray);
			return 0;
		}
	    	
	    else{
	    	cout << "Input the file name (e.g., 600a, 601, 602a): [0]Quit" << endl;
	  		cin >> filename ;
	  	}
		
	}
	
	
	
	return 0;
}
