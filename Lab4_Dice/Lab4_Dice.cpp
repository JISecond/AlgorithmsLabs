
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;




string pullDice(string& input)
{
	char devider = ',';
	string dice = "";

	for (size_t i = 0; i < input.length()+1; i++)
		{
			if (input[i] == devider) {

				dice = input.substr(0, i);

				input.erase(0, i + 1);

				break;
			}

			if (input.length() == i) {

				dice = input;

				input.clear();

			}
	}
	
	return (dice);
};


const vector<char> MODS = { '+', '-', '*' };

bool isModifier(char c, vector<char> mods = MODS) {

	bool isMod = false;

	for (int i = 0; i < mods.size(); i++) {

		if (mods[i] == c) {
			isMod = true;
		}
	}

	return isMod;
}

void Operator(int& value, string input) {

	int modifierPos, secondElem, result;
	
	for (size_t i = 0; i < input.length(); i++)
	{
			if (isModifier(input[i])) {

			modifierPos = i;
			
			secondElem = stoi(input.substr(modifierPos + 1, input.length()));

		
			switch (input[modifierPos])
			{
			case '+':
				value += secondElem;
				break;

			case '-':
				value -= secondElem;
				break;

			case '*':
				value *= secondElem;
				break;
			}
			
			break;

			}
	}

}



int NumOfThrows(string input)
{
	char devider = 'd';
	int throws;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == devider) {

			throws = stoi(input.substr(0, i));

			break;
		}
	}

return (throws);
};

int NumOfSides(string input)
{
	char devider = 'd';
	int deviderPos, modifierPos=0, sides=0;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == devider) {

			deviderPos = i;
			
		}

		if (isModifier(input[i])) {

			modifierPos = i;
		}
	}


	if (modifierPos != 0) {
		sides = stoi(input.substr(deviderPos + 1, modifierPos));
	}
	else {
		sides = stoi(input.substr(deviderPos + 1, input.length()));
	}

	return (sides);
};


int dice(string input) {

	string dice;
	int sides, throws, result=0, singleResult = 0;
	while (!input.empty())
	{
		dice = pullDice(input);
		sides = NumOfSides(dice);
		throws = NumOfThrows(dice);


		for (int n = 0; n != throws; ++n) {
			int value;

			value = 1 + std::rand() / ((RAND_MAX + 1u) / sides);

			cout << value << ' ';
			singleResult += value;
		}
		Operator(singleResult, dice);
		result += singleResult;
		singleResult = 0;
		cout  << '\n';


	}





	return result;

}



int main() {
	
	srand(time(NULL));


	string input_;
	//string dice_;


	getline(cin, input_);




	cout <<  dice(input_) << '\n';

	std::ofstream f("diceRes.txt");

	vector<string> diceSet = { "1d6","2d6","3d6","1d10","2d10","3d10","6d10" };
	for (int i = 0; i < diceSet.size(); i++) {
		if (f.is_open())
			f << diceSet[i] << '\t';
	}
	f << '\n';
	

		for (size_t j = 0; j < 1000; j++)
		{
			for (size_t i = 0; i < diceSet.size(); i++)
			{
				f << dice(diceSet[i]) << '\t';
			}
			f << '\n';
		}


	system("pause");
	

}