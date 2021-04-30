#include <iostream>   
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
namespace variable {
	map<string,string> v;
}
using namespace variable;
string calculate(string s) {
	return s;
}
bool isNumOrDot(char c) {
	if (c < '9' && c>'0')
		return 1;
	else if (c == '.')
		return 1;
	else
		return 0;
}
bool check(string s) {
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
			count--;
	}
	if (count != 0)
		return 1;
	return 0;
}
void input() {
	bool error = 0;
	string input_string;
	getline(cin, input_string);
	error = check(input_string);
	if (!error) {
		if (input_string[0] == 'S' && input_string[1] == 'e' && input_string[2] == 't') {
			int current = 4;
			int next = input_string.find_first_of(" ", current);
			string type = input_string.substr(current, next - current);
			if (type == "Integer") {
				current = next + 1;
				next = input_string.find_first_of("=")-1;
				string variable_name = input_string.substr(current, next - current);
				current = next + 2;
				next = input_string.size();
				input_string = input_string.substr(current, next - current);
				string result = calculate(input_string);
				current = 0;
				next = result.find_first_of(".", 0);
				if (next != string::npos) {
					result = result.substr(current, next - current);
				}
				v[variable_name] = result;
				cout <<variable_name<<"="<<v[variable_name]<<endl;
			}
			else if (type == "Decimal") {
				current = next + 1;
				next = input_string.find_first_of("=")-1;
				string variable_name = input_string.substr(current, next - current);
				current = next + 2;
				next = input_string.size();
				input_string = input_string.substr(current, next - current);
				string result = calculate(input_string);
				v[variable_name] = result;
				cout << variable_name << "=" << v[variable_name] << endl;
			}
			else {
				cout << "Set variable error\n";
			}
		}
		else {
			//calculate
			cout << input_string << endl;
		}
	}
	else
	{
		cout << "input error\n";
	}
}

