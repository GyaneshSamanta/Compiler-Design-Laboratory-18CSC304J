#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
#include<vector>
#include<set>

using namespace std;

set<string> convertToSet(vector<string> v)
{
    set<string> s;
    for (string x : v) {
        s.insert(x);
    }
    return s;
}
  
void printSet(set<string> s)
{
  
    cout << "Set: ";
    for (string x : s) {
        cout << x << " ";
    }
    cout << endl;
}

string arr[] = {"void","using","namespace","int","include","iostream",
"std","main","cin","cout","return","float","double","string", "printf", "scanf" };
bool isKeyword (string a)
{
    for (int i = 0; i < 14; i++)
    {
        if (arr[i] == a)
        {
            return true;
        }
    }
    return false;
    
}

int main() 
{
    fstream file; 
    string s, filename; 
	filename = "test.txt"; 
	file.open(filename.c_str()); 
	vector<string> g1, g2, g3, g4, g5;
	int count1=0,count2=0,count3=0,count4=0,count5=0;
	while (file >> s) 
	{
	    if (s == "+" || s == "-" || s == "" || s == "/" || s == "^" || s == "&&"
        || s == "||" || s == "=" || s == "==" || s == "&" || s == "|" ||
        s == "%" || s == "++" || s == "--" || s == "+=" || s == "-=" ||
        s == "/=" || s == "=" || s == "%=")
        {
            g1.push_back(s);
            count1++;
            s = "";
	    }
	    else if (isKeyword (s) || s=="printf" || s=="stdio.h")
	    {
	        g2.push_back(s);
	        count2++;
	        s = "";
	    }
	    else if (s == "(" || s == "{" || s == "[" || s == ")" || s == "}" || 
	    s == "]" || s == "<" || s == ">" || s == "()" || s == ";" || 
	    s == "<<" || s == ">>" || s == "," || s == "#")
	    {
	        g3.push_back(s);
	        count3++;
	        s = "";
	    }
	    else if (s == "\n" || s == " " || s == "")
	    {
	        s = "";
	    }
	    else if (isdigit (s[0]))
	    {
	        int x = 0;
	        if (!isdigit (s[x++]))
	        {
	            continue;
	        }
	        else
	        {
	            g4.push_back(s);
	            count4++;
	            s = "";
	        }
	    }
	    else
	    {
	        g5.push_back(s);
	        count5++;
	        s = "";
	    }
	} 
	
	set<string> s1 = convertToSet(g1);
	set<string> s2 = convertToSet(g2);
	set<string> s3 = convertToSet(g3);
	set<string> s4 = convertToSet(g4);
	set<string> s5 = convertToSet(g5);
	
	cout<<"Number of operators="<<count1<<"\n";
	printSet(s1);
	cout<<"\n\n";
	cout<<"Number of keywords="<<count2<<"\n";
	printSet(s2);
	cout<<"\n\n";
	cout<<"Number of symbols="<<count3<<"\n";
	printSet(s3);
	cout<<"\n\n";
	cout<<"Number of constants="<<count4<<"\n";
	printSet(s4);
	cout<<"\n\n";
	cout<<"Number of identifiers="<<count5<<"\n";
	printSet(s5);
	cout<<"\n\n";
	return 0; 
}