#include<ctime>
#include<vector>
#include<sstream>

using namespace std;

struct Transaction {

	double amount;
	string senderKey;
	string receiverKey;
	size_t time;
};

class Block {
private:
	int index;
	size_t BlockHash;
	size_t PreviousHash;
	size_t generateHash();

public:

	//Constructor//
	Block(int index, Transaction t, size_t PrevHash);

	//Original Hash
	size_t getHash();

	//Previous Hash
	size_t prevHash();

	//Transaction data
	Transaction data;

	//Validate Hash
	bool isValidHash();

};