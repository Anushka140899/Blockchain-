#include<ctime>
#include<sstream>
#include "Blockchain.h"

using namespace std;

Blockchain::Blockchain()
{
	Block genesis = createGenesisBlock();
	chain.push_back(genesis);

}

Block Blockchain::createGenesisBlock()
{
	time_t current;
	Transaction d;
	d.amount = 0;
	d.receiverKey = "None";
	d.senderKey = "None";
	d.time = time(&current);

	hash<int> hash1;

	Block genesis(0, d, hash1(0));
	return genesis;
}

Block* Blockchain::getLatestBlock()
{
	return &chain.back();
}

void Blockchain::addBlock(Transaction d)
{
	int index = (int)chain.size() - 1;
	Block newBlock(index, d, getLatestBlock()->getHash());
}

bool Blockchain::isChainValid()
{
	vector<Block>::iterator it;
	int length = (int)chain.size();

	for (it = chain.begin(); it != chain.end(); it++)
	{
		Block currBlock = *it;
		if (!currBlock.isValidHash())
		{
			return false;
		}

		if (length > 1)
		{
			Block prevBlock = *(it - 1);
			if (currBlock.prevHash() != prevBlock.getHash())
			{
				return false;
			}
		}
	}
	return true;
}