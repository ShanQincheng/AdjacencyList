# include "headFile.h"

void DFSTraversal(ListHead* listHeadArray, int listHeadArraySize, ListHeadHashTable* listHeadHashTable, int maxStepSize, int hashSize)
{
	int i = 0; // iterator variable
	int graphNumber = 0; // 記錄這是搜寻出来的第幾個子圖 
	VisitStack* visitStackHead = NULL; // store graph nodes which were visited
	VisitStack* visitStackNode = NULL; // need a temp node to create new 
	ListHeadHashTable currentStu;   // current stu information in hash table, address in hashTable, address in listHeadArray
	ListHead* currentListHead = NULL; // read the adjacency list head
	ListNode* currentListNode = NULL; // iterator read each node adjacent the list head
	vector<string> graphSidVector; // store every graph node have gone
	StuPairs* graphSidArray = NULL;  // store every graph node have gone in arrary for heap sort
		
	for(i = 0; i < listHeadArraySize; i++) // make sure that each node is traversed once
	{
		currentStu = GetAddressFromHashTable(listHeadHashTable, maxStepSize, hashSize, listHeadArray[i].sid_one); // get current list head node information by sid
		//cout << currentStu.sid <
		if(currentStu.visited == false) // if current list head node is not visited yet
		{
			listHeadHashTable[currentStu.addressInHashTable].visited = true;  // mark current node visited
			visitStackNode = (VisitStack*)calloc(1, sizeof(VisitStack));  // create a new stack layer
			//strcpy(visitStackNode.sid, currentStu.sid);
			visitStackNode->listHead = listHeadArray[currentStu.addressInListHead]; // push current node informations into the stack
			visitStackNode->next = visitStackHead;
			visitStackHead = visitStackNode;  // make stack head point to the newest node
			graphSidVector.push_back(currentStu.sid);  // once a node is pushed into the stack, means that the node has been traversed and the node belongs to current graph
			
			while(visitStackHead != NULL)  // if the stack is not empty, it means that the map traversal is not finished yet
			{
				currentListNode = visitStackHead->listHead.firstNode;  // traverse all the list node adjacency the list head
				while(true)
				{
					if(currentListNode == NULL) // to the end of current list node
					{
						visitStackHead = visitStackHead->next;  // pop() stack
						
						break;
					}else{	
						currentStu = GetAddressFromHashTable(listHeadHashTable, maxStepSize, hashSize, currentListNode->sid_two); // // get current list node information by sid
						if(currentStu.visited == false) // if the node is not visited yet, push it into the stack
						{
							visitStackNode = (VisitStack*)calloc(1, sizeof(VisitStack));
							//strcpy(visitStackNode.sid, currentStu.sid);
							visitStackNode->listHead = listHeadArray[currentStu.addressInListHead];
							visitStackNode->next = visitStackHead;
							visitStackHead = visitStackNode;
							listHeadHashTable[currentStu.addressInHashTable].visited = true;
							graphSidVector.push_back(currentStu.sid);  // once a node is pushed into the stack, means that the node has been traversed and the node belongs to current graph
										
							break;
						}else{
							currentListNode = currentListNode->nextNode; // keep going to find next list node adjacency the list head
						}
					}
				}
				
			}			
		}else{  // if current list head node is visited, keep going to find next unvisited list head, and then iterator its list node
			continue;
		}
		/*
			if the stack is empty, it means that we have travesed a sub map
			we need to printf current sub map and then keep going to find next sub map
		*/
		graphNumber++;
		graphSidArray = (StuPairs*)calloc(graphSidVector.size(), sizeof(StuPairs)); // create a node array for heap sort
		for(i = 0; i < graphSidVector.size(); i++)
		{
			strcpy(graphSidArray[i].sid_one, graphSidVector[i].c_str()); // copy each node from vector to array
			
			//graphSidArray[i].sid_one = graphSidVector[i];
		}
		HeapSort(graphSidArray, graphSidVector.size(), true);  // heap sort by the sid , strcmp
		MissionTwoPrintf(graphSidArray, graphSidVector.size(), graphNumber); // printf the sub map
		//cout << "link size == " << graphSidVector.size() << endl;
		graphSidVector.clear(); // clear the vector to store next sub map
	}
	
	return;
}
