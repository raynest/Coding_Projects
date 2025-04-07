#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ofstream fout; // output file to write in
	ifstream fin; // reading file advice to user in first step
	// READING PREVIOUS ADVICE TO USER, step 1 of progam
	// first open input file
	fin.open("C:\\Users\\sauce\\OneDrive\\Desktop\\advice.txt"); // not asking
	//user for file name so must be directed -> (" ")
		if (fin.fail())
		{
			cout << "Advice.txt input failed to open";
			exit(1);
		}
	//second read input file
	cout << "Here is your current advice: " << endl;
	char c; // reading loop!
	while (fin.get(c))
	{
		cout << c;
	}
	// close file after using
	fin.close();
	// WRITING ADVICE TO FILE , step 2 of process
	// first open output file
	fout.open("C:\\Users\\sauce\\OneDrive\\Desktop\\advice.txt", ios::app); //
	//open file for writing
		if (fout.fail())
		{
			cout << "Advice.txt failed to open";
			exit(1);
		}
	// second write in output file
	cout << endl << "Please enter your new advice now. Your advice may be as long as you need, but please indicate the end of input by pressing <cr> twice. " << endl;
	string input;
	int newlineCount = 0;
	while (newlineCount < 2)
	{
		getline(cin,input);
		if (input.empty()) {
			newlineCount++;
		}
		else {
			newlineCount = 0;
		}
		fout << input << endl;
	}
	// close file after using
	fout.close();
	cout << endl << "Thank you for your advice";
	//return 0
	return 0;
}