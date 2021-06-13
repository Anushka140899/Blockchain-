#include<ctime>
#include<sstream>
#include "Block.h"

using namespace std;

Block::Block(int index, Transaction data, size_t prevHash)
{
	index = index;
	data = data;
	PreviousHash = prevHash;
	BlockHash = generateHash();

}

size_t Block::generateHash()
{
	hash<string> hash1;
	hash<size_t> hash2;
	hash<size_t> finalHash;
	string toHash = to_string(data.amount) + data.senderKey + data.receiverKey + to_string(data.time);

	return finalHash(hash1(toHash) + hash2(PreviousHash));
}

size_t Block::getHash()
{
	return BlockHash;
}

size_t Block::prevHash()
{
	return PreviousHash;
}

bool Block::isValidHash()
{
	return generateHash()== BlockHash;
}