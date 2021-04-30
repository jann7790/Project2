#include "bignum.h"
#include <iostream>   
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


namespace variable {
	map<string, double> v;
}
using namespace variable;
bool isNumOrDot(char c) {
	if (c < '9' && c>'0')
		return 1;
	else if (c == '.')
		return 1;
	else
		return 0;
}
void add_priority(string& input_s) {
	char sign;
	string temp_string;
	int current,next;
	next = input_s.find_first_of("!",0);
	current = 0;
	while (next != string::npos) {
		if (input_s[next - 1] == ')') {
			int count_priority = 1, position = next - 2;
			while (count_priority > 0) {
				if (input_s[position] == ')')
					count_priority++;
				else if (input_s[position] == '(')
					count_priority--;
				position--;
			}
			position++;

			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else{
				input_s.insert(position, "(");
				next++;
			}
		}
		else {
			int position = next - 1;
			while (position>0&&isNumOrDot(input_s[position-1]))
				position--;
			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else {
				input_s.insert(position, "(");
				next++;
			}
		}
		int position = next;
		while (position < input_s.size()-1 && isNumOrDot(input_s[position+1]))
				position++;
		if (input_s[position+1] != ')')
		input_s.insert(position+1 , ")");
		
		current = next + 1;
		next = input_s.find_first_of("!",current);
	}
	next = input_s.find_first_of("^", 0);
	current = 0;
	while (next != string::npos) {
		if (input_s[next - 1] == ')') {
			int count_priority = 1, position = next - 2;
			while (count_priority > 0) {
				if (input_s[position] == ')')
					count_priority++;
				else if (input_s[position] == '(')
					count_priority--;
				position--;
			}
			position++;

			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else {
				input_s.insert(position, "(");
				next++;
			}
		}
		else {
			int position = next - 1;
			while (position > 0 && isNumOrDot(input_s[position - 1]))
				position--;
			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else {
				input_s.insert(position, "(");
				next++;
			}
		}

		if (input_s[next + 1] == '(') {
			int count_priority = 1, position = next + 2;
			while (count_priority > 0) {
				if (input_s[position] == '(')
					count_priority++;
				else if (input_s[position] == ')')
					count_priority--;
				position++;
			}
			position--;
			if (position < input_s.size() - 1) {
				if (input_s[position + 1] != ')') {
					input_s.insert(position + 1, ")");
				}
			}
			else {
				input_s.insert(position + 1, ")");
			}
		}
		else {
			int position = next + 1;
			while (position < input_s.size() - 1 && isNumOrDot(input_s[position + 1]))
				position++;
			if (input_s[position + 1] != ')')
				input_s.insert(position + 1, ")");
		}
		current = next + 1;
		next = input_s.find_first_of("^", current);
	}
	next = input_s.find_first_of("*/", 0);
	current = 0;
	while (next != string::npos) {
		if (input_s[next - 1] == ')') {
			int count_priority = 1, position = next - 2;
			while (count_priority > 0) {
				if (input_s[position] == ')')
					count_priority++;
				else if (input_s[position] == '(')
					count_priority--;
				position--;
			}
			position++;

			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else {
				input_s.insert(position, "(");
				next++;
			}
		}
		else {
			int position = next - 1;
			while (position > 0 && isNumOrDot(input_s[position - 1]))
				position--;
			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else {
				input_s.insert(position, "(");
				next++;
			}
		}

		if (input_s[next + 1] == '(') {
			int count_priority = 1, position = next + 2;
			while (count_priority > 0) {
				if (input_s[position] == '(')
					count_priority++;
				else if (input_s[position] == ')')
					count_priority--;
				position++;
			}
			position--;
			if (position < input_s.size() - 1) {
				if (input_s[position + 1] != ')') {
					input_s.insert(position + 1, ")");
				}
			}
			else {
				input_s.insert(position + 1, ")");
			}
		}
		else {
			int position = next + 1;
			while (position < input_s.size() - 1 && isNumOrDot(input_s[position + 1]))
				position++;
			if (input_s[position + 1] != ')')
				input_s.insert(position + 1, ")");
		}
		current = next + 1;
		next = input_s.find_first_of("*/", current);
	}
	next = input_s.find_first_of("+-", 0);
	current = 0;
	while (next != string::npos) {
		if (input_s[next - 1] == ')') {
			int count_priority = 1, position = next - 2;
			while (count_priority > 0) {
				if (input_s[position] == ')')
					count_priority++;
				else if (input_s[position] == '(')
					count_priority--;
				position--;
			}
			position++;

			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else {
				input_s.insert(position, "(");
				next++;
			}
		}
		else {
			int position = next - 1;
			while (position > 0 && isNumOrDot(input_s[position - 1]))
				position--;
			if (position > 0) {
				if (input_s[position - 1] != '(') {
					input_s.insert(position, "(");
					next++;
				}
			}
			else {
				input_s.insert(position, "(");
				next++;
			}
		}

		if (input_s[next + 1] == '(') {
			int count_priority = 1, position = next + 2;
			while (count_priority > 0) {
				if (input_s[position] == '(')
					count_priority++;
				else if (input_s[position] == ')')
					count_priority--;
				position++;
			}
			position--;
			if (position < input_s.size() - 1) {
				if (input_s[position + 1] != ')') {
					input_s.insert(position + 1, ")");
				}
			}
			else {
				input_s.insert(position + 1, ")");
			}
		}
		else {
			int position = next + 1;
			while (position < input_s.size() - 1 && isNumOrDot(input_s[position + 1]))
				position++;
			if (input_s[position + 1] != ')')
				input_s.insert(position + 1, ")");
		}
		current = next + 1;
		next = input_s.find_first_of("+-", current);
	}
}
double calculate(string input_string) {
	add_priority(input_string);
	return 0.1;
}
void input() {
	bool error = 0;
	string input_string;
	getline(cin, input_string);
	if (input_string[0] == 'S' && input_string[1] == 'e' && input_string[2] == 't') {
		int current = 4;
		int next = input_string.find_first_of(" ", current);
		string type = input_string.substr(current, next - current);
		if (type == "Integer") {
			current = next + 1;
			next = input_string.find_first_of("=");
			string variable_name = input_string.substr(current, next - current);
			current = next + 1;
			next = input_string.size();
			input_string = input_string.substr(current, next - current);
			double result = calculate(input_string);
			string result_string = to_string(result);
			current = 0;
			next = result_string.find_first_of(".", 0);
			if (next != string::npos) {
				result_string = result_string.substr(current, next - current);
				string a = "11";
				result = atof(result_string.c_str());
			}
			v[variable_name] = result;
		}
		else if (type == "Decimal") {
			current = next + 1;
			next = input_string.find_first_of("=");
			string variable_name = input_string.substr(current, next - current);
			current = next + 1;
			next = input_string.size();
			input_string = input_string.substr(current, next - current);
			double result = calculate(input_string);
			v[variable_name] = result;
		}
		else {
			cout << "Set variable error\n";
		}
	}
	else {
		add_priority(input_string);
		cout << input_string<<endl;
		//double result = calculate(input_string);
		//cout << result;
	}
}

