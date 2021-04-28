#include "bignum.h"
#include <iostream>   
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void process(string s);
void splitStr2Vec(string s, vector<string>& buf);
int main()
{
	string s;
	while (cin >> s) {
		process(s);
	}
}
void process(string s) {
	int current = 0; //�̪�� 0 ����m�}�l��
	int next;
	next = s.find_first_of("(", current);
	if (next != string::npos)
	{
		int t = 1;
		current = next + 1;
		next++;
		while (t > 0 && next < s.size()) {
			if (s[next] == ')')
				t--;
			else if (s[next] == '(')
				t++;
			next++;
		}
		if (t == 0) {
			string tmp = s.substr(current, next - current);
			cout << tmp << endl;
			process(tmp);
		}
	}
}
void splitStr2Vec(string s, vector<string>& buf)
{
	int current = 0; //�̪�� 0 ����m�}�l��
	int next;
	while (1)
	{
		next = s.find_first_of(" ,|", current);
		if (next != current)
		{
			string tmp = s.substr(current, next - current);
			if (tmp.size() != 0) //�����Ŧr��
				buf.push_back(tmp);
		}
		if (next == string::npos) break;
		current = next + 1; //�U���� next + 1 ����m�}�l��_�C
	}
}