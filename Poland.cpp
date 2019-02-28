#include<vector>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

vector<string> SplitString(string s)
{
	vector<string> v;
	string s1 = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			s1 += s[i];
		else if (s1.size() > 0)
		{
			v.push_back(s1);
			s1 = "";
		}
	}
	if (s1.size() > 0)
	{
		v.push_back(s1);
		s1 = "";
	}
	return v;
}

int StrToInt(string s)
{
	int a = 0;
	for (int i = 0; i < s.size(); i++)
		a = a * 10 + (s[i] - '0');
	return a;
}

string InfToPostf(string s)
{
	auto elems = SplitString(s);
	string output = "";
	stack<string> st;
	for (auto e : elems)
	{
		if (e[0] >= '0' and e[0] <= '9')
		{
			if (output.size() != 0)
				output += " ";
			output += e;
		}
		else if (e == "+" || e == "-")
		{
			while (!st.empty() && st.top() != "(")
			{
				output += " " + st.top();
				st.pop();
			}
			st.push(e);
		}
		else if (e == "*" || e == "/")
		{
			while (!st.empty() &&
				(st.top() == "*" || st.top() == "/"))
			{
				output += " " + st.top();
				st.pop();
			}
			st.push(e);
		}
		else if (e == "(")
			st.push(e);
		else if (e == ")")
		{
			while (st.top() != "(")
			{
				output += " " + st.top();
				st.pop();
			}
			st.pop();
		}
	}
	while (!st.empty())
	{
		output += " " + st.top();
		st.pop();
	}
	return output;
}

int main()
{
	string s;
	getline(cin, s);
	cout << InfToPostf(s);
	system("pause");
}
