// GreedyGiftGivers.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

/*
ID: my id here
PROG: gift1
LANG: C++11
*/

#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
	ifstream fin("gift1.in", ios::in);
	ofstream fout("gift1.out", ios::out);

	unsigned short NP;

	struct person
	{
		string name;
		long int gave;
		long int received;
	};

	vector<person> accounts;

	string tmp_name;
	
	fin >> NP;
	accounts.resize(NP);
	for (auto& i : accounts)
	{
		fin >> tmp_name;
		//fout << "Just read this name: " << tmp_name << "\n";
		i.name = tmp_name;
		i.gave = 0;
		i.received = 0;

		//fout << "We have just created this account: " << i.name << ";" << i.gave << ";" << i.received << "\n";
		// OK, this part works
	}

	/*fout << "Freshly created ledger:\n";
	for (auto& l : accounts)
		fout << "Person: " << l.name << "; Gave: " << l.gave << ";Received " << l.received << "\n";*/

	//fout << "\n";
	
	for (register unsigned int j = 1; j <= NP; j++)
	{
		string giver_name;
		fin >> giver_name;
		//fout << "Read a name #" << j << ": " << giver_name << "\n";

		auto vpit = find_if(accounts.begin(), accounts.end(), [&giver_name](const person& pers) -> bool {return pers.name == giver_name; });
		if (vpit == accounts.end())
		{
			fout << "Couldn't find this giver in accounts\n";
		}
		else
		{
			person& found = *vpit;  // the logic is wrong here: keeps saying "mitnik" where it shouldn'
									//OK, with some stackoverflow enlightenment that got fixed
			//fout << "\nDebug info: \n\t Giver#" << j << "; \n\t iterator->name ==" << vpit->name << "; \n\t iterator->gave == " << vpit->gave << "; \n\t iterator->received == " << vpit ->received << "\n";
			//fout << "Found " << found.name << " in accounts; proceeding\n";
			unsigned int sum, people;
			fin >> sum >> people;
			//fout << "Read this:" << sum << " " << people << "\n";
			vpit->gave = sum;
			// << "We now think " << found.name << " has given " << sum << "  thingies\n";
			if (people != 0)
			{

				for (register unsigned int k = 0; k < people; k++)
				{
					string receiver_name;
					fin >> receiver_name;
					//fout << "\tHe gave them to :" << receiver_name << "\n";



					auto it = find_if(accounts.begin(), accounts.end(), [&receiver_name](const person& p) { return p.name == receiver_name; });  //this is a lambda. Cryptic, elegant, effective
					if (it == accounts.end())
					{
						fout << "Couldn't find receiver\n " << receiver_name;
					}
					else
					{
						person& found_ = *it;
						found_.received += sum / people;
						//fout << "\t\t" << found_.name << " just received " << sum / people << " thingies" << endl;
					}


				}

				found.gave -= sum % people;   // if a person meant to give 200, but couldn't divide 3, 
											  // he actually gave 197
		}
	}
	}

	//fout << "And now we have this:\n";
	for (auto l : accounts)
		fout << l.name << " " << l.received - l.gave << "\n";

	fin.close();
	fout.close();

	exit(0);
}

