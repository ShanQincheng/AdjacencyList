# Adjacency List

##### Project description click here
https://github.com/ShanQincheng/AdjacencyList/blob/master/DS2ex06A.pdf


environment：Win 10

language：C & C++

platform：Dev C++

T07

Team member： 04106034 何政霖

// read node pairs from binary file

vector<StuPairs>& ReadBinaryFile(vector<StuPairs> &, string);

// Determine whether the subtree has been adjusted. if yes return 1 else return 0;
int AdjustHeap(StuPairs *array, int i, int size, bool adjustType);

// build a min heap
void BuildHeap(StuPairs *array, int size,  bool adjustType);

// heap sort function, adjustType == true, sort by sid, adjustType == false, sort by weight
void HeapSort(StuPairs *array, int size, bool adjustType);

// create a adjacency list
ListHead* CreateAdjacencyList(StuPairs* array, int arraySize, ListHead* listHeadArray, int& listHeadArraySize);

// create a adjacency list head array
ListHead* CreateAdjacencyListHead(StuPairs*, int, ListHead*, int& listHeadArraySize);

// create a adjacency node list
ListHead* CreateAdjacencyListNode(StuPairs* array, int arraySize, ListHead* listHeadArray);

// output the binary file
void OutputBinaryFile(ListHead* listHeadArray, int arraySize, string fileName);

// to determine whether a number is a prime number
bool JudgeIfPrime(int judgeNumber);

// calculate sid each character ascii multiplication summation
double CalculateSidAscii(char* sid);

// using double hashing method create list head items hash table
ListHeadHashTable* CreateSidHashTable(ListHead* listHeadArray, int listHeadArraySize, int& maxStepSize, int& hashSize, ListHeadHashTable* listHeadHashTable);

// get address of the input sid
ListHeadHashTable GetAddressFromHashTable(ListHeadHashTable* listHeadHashTable, int maxStepSize, int hashSize, char* sid);

// DFS Traversal
void DFSTraversal(ListHead* listHeadArray, int listHeadArraySize, ListHeadHashTable* listHeadHashTable, int maxStepSize, int hashSize);

// printf mission two result to screen
void MissionTwoPrintf(StuPairs* stuPairArray, int stuPairsSize, int graphNumber);

Mission One思路如圖：
![ideas as shown](https://github.com/ShanQincheng/AdjacencyList/blob/master/Ideas.png)


Mission Two：思路

使用 Double Hashing 方法創建一個 HashTable，將 鄰接串列 中存放的 sid 與其在鄰接串列中的 position 以 key-value 的形式存放在一起。

而後在進行 DFS Traverse 操作時， 利用此 HashTable，能夠免去遍曆 鄰接串列的麻煩，能夠更快地找到下一個鄰接的 Node

————————————————————————————————————————————————————

應用：

我覺得可以解決交通堵塞的問題。此圖可以看作一個交通網，weight越高，堵塞越嚴重。我們可以基於實時的 weight值，構建鄰接矩陣，之後構建出出發地到目的地的路徑 map，制定出最短時間的路徑。
