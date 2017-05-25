# include "headFile.h"

void MissionTwoPrintf(StuPairs* stuPairArray, int stuPairsSize, int graphNumber)
{
	int i = 0; // iterator variable
	
	if(graphNumber == 1)
		printf("~~ Connected Components ~~\n");
		
	printf("(%d) Connected Component: size = %d\n", graphNumber, stuPairsSize);	
	for (i = 0; i < stuPairsSize; i++ ) {
		if((i + 1) % 5 == 0)
	  		printf("(%3d) %s\n", i+1, stuPairArray[i].sid_one);
	  	else
	  		printf("(%3d) %s\t", i+1, stuPairArray[i].sid_one);
	   
	} // for
	printf("\n");
	
	return;
}
