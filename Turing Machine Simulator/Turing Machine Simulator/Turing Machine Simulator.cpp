// Turing Machine Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"

int main()
{
	int n, i, j=0, final, state=NULL;
	string input_string;
	cout << "Enter the number of transition functions"<<endl;
	cin >> n;
	cout << "Enter the number of last state"<<endl;
	cin >> final;
	
	vector <TransFunction>  array;
	TransFunction temp(0, "0", 0, "0", 0);
	
	cout << "Enter start state, input symbol, next state, replacement symbol and direction\n";
	for (i = 0; i < n; i++) {
		cin >> temp.curr_state >> temp.sym >> temp.next_state >> temp.replace >> temp.direction;
		array.push_back(temp);
	}

	Tape tape=Tape();
	tape.PrintTape();

	i = 0;

	while ((i<tape.symbol.size() && i>=0) && (final != state)) {
		
		if (j>=array.size()) {
			break;
		}

		if ((array[j].curr_state==state) && (array[j].sym==tape.symbol[i])) {
			
			tape.MoveHead(array[j].direction);
			tape.ReplaceSymbol(i, array[j].replace);
			tape.PrintTape();
			state = array[j].next_state;

			i=tape.head;
			j = 0;
		}
		else {
			j++;
		}
		
	}

	if (final == state) {
		cout << "String accepted" << endl;
	}
	else {
		cout << "String rejected" << endl;
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
