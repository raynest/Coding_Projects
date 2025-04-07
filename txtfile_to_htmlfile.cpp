
#include<iostream>
#include<string>
#include<fstream> // For file stream operations
#include<cstdlib> // For exit function
using namespace std;
void instructions();
//Displays instructions on how to run the program and what the input is.
void get_test_files(ifstream& in_s, ofstream& out_s);
// This function asks users to enter the input and output file names from the
//keyboard.It will attempt to connect
//to the files and once successfully connected, it returns the input and output
//streams to the main.If it fails to
//connect to the input or output file, it will terminate the program.
void write_header(ofstream& out_s);
// This function will write the 5 lines of header into the output file.
void write_footer(ofstream& out_s);
// This function will write the last 2 lines, the footer of the html file.
void copy_text(ifstream& in_s, ofstream& out_s);
// This file copies the entire contents of the input file, myfile, into the output
//file, myfile.html, line - by - line, by
//considering the given instruction for the newline
int main()
{
	ifstream in_s;
	ofstream out_s;
	instructions();
	get_test_files(in_s, out_s);
	write_header(out_s);
	copy_text(in_s, out_s);
	write_footer(out_s);
	in_s.close();
	out_s.close();
	return 0;
}
void instructions()
{
	std::cout << " The program will read a text file and will produce a html file that can be viewed using a web browser, like Netscape or Internet Explorer.\nTo do this you will need to create a input file, and write in a txt document what you want to be written within the hmtl file.\n";
}
void get_test_files(ifstream& in_s, ofstream& out_s)
{
	char input_file[100], output_file[100]; // For the input file name
	cout << "Please input the input file name: \n"; // Ask user for the input file name
	cin >> input_file;
	cout << "Please input the output file name: \n";
	cin >> output_file;
	// Open the input file for reading
	in_s.open(input_file);
	if (in_s.fail()) {
		cout << "Input file opening failed. \n";
		exit(1); // Exit if the file cannot be opened
	}
	// Open the output file for writing
	out_s.open(output_file); // This will create or overwrite the output.txt file
	if (out_s.fail()) {
		cout << "Output file opening failed. \n";
		exit(1); // Exit if the output file cannot be cannot be opened
	}
}
void write_header(ofstream& out_s) // step 1
{
	out_s << " <Html>\n";
	out_s << " <Title>\n";
	out_s << " This my C++ html converter ";
	out_s << " </Title>\n";
	out_s << " <Body>\n";
}
void write_footer(ofstream& out_s) // step 3
{
	out_s << "</Body>";
	out_s << "</Html>";
}
void copy_text(ifstream& in_s, ofstream& out_s) // step 3
{
	char c;
	while (!in_s.eof())
	{
		in_s.get(c);

		if (c == '\n')
		{
			out_s << "<br>";
		}
		else
		{
			out_s << c;
		}
		in_s.get(c);
	}
}