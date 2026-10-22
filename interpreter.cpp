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
		size_t eq = text.find('=');//tells the computer to find the actual position of = and store in a cariable eq
		 if(eq != string::npos)//a condition so if there is an equal sign it executes the code in brackets and if not ignore it
		 { text[eq] = ' ';//it replaces = sign with empty space 
		 text += " ="; }//glues an = sign
		cout<<text<<endl;//so the line in the file to be displayed on the screen
		stringstream ss(text);//so the line can be break into words
		string command,variable,value;//to store the words like three main things
		ss>>command>>variable>>value;//use ss so the breaking words into three variables
		
		if(command == "take")//to ensure the syntax is accurate
		{
			stringstream converter(value);
			int actualnumber;//to store written variables
			converter>>actualnumber;//Extract the clean integer out of the blender (No keyboard cin needed!)
			
			memory[variable]=actualnumber;//to memorize all variables
			variableNames.push_back(variable);//to store a list of variables
		}
	
		if(command=="display")
		{
			int val1=memory[variableNames[0]];
			int val2=memory[variableNames[1]];
		    int val3=memory[variableNames[2]];
		    if(variable=="biggest")
		      {
			  if(val1>=val2 && val1>=val3)
		      {
			  cout<<val1<<"is biggest"<<endl;  
		  }
		  if(val2>=val1 && val2>=val3)
		  {
		  	cout<<val2<<"is biggest"<<endl;	 
			   }
		  	if(val3>=val1 && val3>=val2)
		  	{
		  		cout<<val3<<"is biggest"<<endl;
		}
	}
	     else if(variable=="average")
	     {
	     	double avg = (val1 + val2 + val3) / 3.0;
                cout << "The average is " << avg << endl;
		 }
	
		}
		
		
	}
}

