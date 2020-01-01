#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<vector>

using namespace std;

class TransFunction {
public:
	int curr_state;
	string sym;		//input symbol
	int next_state;
	string replace;			//symbol to replace with
	bool direction;			//1 is for right 0 is for left
	
	TransFunction(int curr_state, string sym, int next_state, string replace, bool direction) {
		
		this->curr_state = curr_state;
		this->direction = direction;
		this->next_state = next_state;
		this->replace = replace;
		this->sym = sym;
	}


};

class Tape {
public:
	int head;
	vector<string> symbol;

	Tape() {
		head = 0;
		int i, n;
		string temp;
		cout << "Enter the string length"<<endl;
		cin >> n;
		cout << "Enter string to be tested"<<endl;

		for (i = 0; i < n; i++) {
			cin>> temp;
			symbol.push_back(temp);
		}
	}

	void MoveHead(bool direction) {		
		if (direction) {
			head++;
		}
		else if (!direction) {
			head--;
		}
	}

	void ReplaceSymbol(int index, string replace) {

		symbol[index].clear();
		symbol[index] = replace;

	}
	void PrintTape() {
		
		for (int i = 0; i < symbol.size(); i++) {
			
			if (i == head) {
				cout << "[" << symbol[head] << "] ";
			}
			else {
				cout << " " << symbol[i] << " ";
			}
		}

		cout << endl;  
	}
};