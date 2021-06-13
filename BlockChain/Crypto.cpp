#include<ctime>
#include<sstream>
#include<iostream>
#include "Blockchain.h"


using namespace std;

int main()
{
	Blockchain AsCoin;

	Transaction data1;
	time_t data1time;
	data1.amount = 2;
	data1.receiverKey = "Pramod";
	data1.senderKey = "Anushka";
	data1.time = time(&data1time);

	AsCoin.addBlock(data1);

	Transaction data2;
	time_t data2time;
	data2.amount = 0.001011;
	data2.receiverKey = "Rashmi";
	data2.senderKey = "Anushka";
	data2.time = time(&data2time);

	AsCoin.addBlock(data2);

	Transaction data3;
	time_t data3time;
	data3.amount = 1.09834;
	data3.receiverKey = "Shashwat";
	data3.senderKey = "Anushka";
	data3.time = time(&data3time);

	AsCoin.addBlock(data3);

	cout << "Is Chain Valid? " << endl << AsCoin.isChainValid() << endl;

	Block* hack = AsCoin.getLatestBlock();
	hack->data.amount = 10000;
	hack->data.receiverKey = "Shukla";

	cout << "Is the chain valid??" << endl << AsCoin.isChainValid() << endl;
}