#include<fstream>//header file for the file handling
#include<iostream>//for input output
#include<string>//for string
#include<map>//for map storage additional storage
#include<sstream>//for to break line into words
#include<vector>//for user to type any variable name
using namespace std;
int main()
{
	ifstream filename("code.txt");//it takes input from the file
	if(!filename.is_open())//the condition so that if the file is in different folder
	{
		cout<<"file cannot be opened"<<endl;
		return 1;//so the it can finish 
	}
	map<string,int> memory;//for artifcial memory
    vector<string> variableNames;//for user variable name independence
		string text;//the destination where file lines be stored
	while(getline(filename,text))//loop for every variable typed
	{
		cout<<text<<endl;//so the line in the file to be displayed on the screen
		stringstream ss(text);//so the line can be break into words
		string command,variable,value;//to store the words like three main things
		ss>>command>>variable>>value;//use ss so the breaking words into three variables
		
		if(command == "take")//to ensure the syntax is accurate
		{
			int usertype;//to store written variables
			cout<<"enter your variable"<<variable;
			cin>>usertype;//for user to type
			memory[variable]= usertype;//to memorize all varables
			variableNames.push_back(variable);//to store a list of variables
			string clean= variable +"=";
		}
		if(command=="display")
		{
			int val1=memory[variableNames[0]]];
			int val2=memory[variableNames[1]]];
		    int val1=memory[variableNames[2]]];
		    if(display=="biggest")
		      if(val1>val2 && val1>val3)
		      cout<<" is biggest"<<val1<<endl;
		      
		}
		
		
	}
}
