#include<ctime>
#include<sstream>
#include<vector>
#include "Block.h"

using namespace std;

class Blockchain {

private:
	Block createGenesisBlock();     //First Block in the chain

public:

	//Chain
	vector<Block> chain;

	//Constructor
	Blockchain();

	//Functions

	void addBlock(Transaction data);
	bool isChainValid();

	///For test only///
	Block* getLatestBlock();
};