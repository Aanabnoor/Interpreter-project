#include<fstream>   // 1. Unlocks File tools (ifstream) so we can open and read text files.
#include<iostream>  // 2. Unlocks Console tools (cin, cout) so we can talk to the user.
#include<string>    // 3. Unlocks String tools so we can create text boxes to hold words.
#include<sstream>   // 4. Unlocks Stringstream tools (the word blender) to chop sentences into words.
#include<map>       // 5. Unlocks Map tools (the dictionary database) to act as our program's memory.

using namespace std; // 6. Saves us from typing "std::" in front of every single tool name.

int main() // 7. The main entry point. This is the starting engine where our program begins execution.
{
    // 8. Creates a file reader bridge object named "filename" and points it straight to "code.txt".
    ifstream filename("code.txt");
    
    // 9. Safety Check: If C++ cannot find the file (e.g. misspelled or wrong folder), enter this block.
    if(!filename.is_open())
    {
        // 10. Alert the user that the file is missing so they can fix it.
        cout << "file cannot be opened" << endl;
        // 11. Instantly kill the program with an error status code (1) because we have no file to read.
        return 1;
    }
    
    // 12. Creates our artificial memory notebook. It maps a string key (like "x=") to an integer value.
    map<string, int> memory;
    
    // 13. Creates a blank text variable named "text" to hold a single whole line from our file at a time.
    string text;
    
    // 14. The Loop: Keeps reading "code.txt" line-by-line, loading each line into "text" until it hits the end.
    while(getline(filename, text))
    {
        // 15. Prints the raw line currently being read from the text file out onto the screen.
        cout << text << endl;
        
        // 16. Loads the current line into a stringstream object named "ss" (our word-chopping blender).
        stringstream ss(text);
        
        // 17. Creates three separate empty string boxes to catch the incoming split words.
        string command, variable, value;
                          
        // 18. The Pipeline: Chops up the line by spaces, pouring word 1 into command, word 2 into variable, etc.
        ss >> command >> variable >> value;
        
        // 19. Diagnostics: Prints out the extracted first token word to verify our tokenizer worked.
        cout << "command: " << command << endl;
        // 20. Diagnostics: Prints out the extracted second token word (e.g., the variable label).
        cout << "variable: " << variable << endl;
        // 21. Diagnostics: Prints out the third token word (which will be blank for your design syntax).
        cout << "value: " << value << endl;
        
        // 22. Branch 1: If the file command word is exactly "take", trigger our interactive keyboard input rule.
        if(command == "take")
        {
            // 23. Creates a temporary integer variable named "usertype" to catch the typed keyboard number.
            int usertype;
            // 24. Prints a dynamic message on the screen asking the user for a value for that specific variable.
            cout << "enter a number for " << variable << ": ";
            // 25. Pauses the software and waits for the human to type a number and press Enter.
            cin >> usertype;
            // 26. Dynamic Storage: Saves the typed number inside our 'memory' map database under the key name (e.g. "x=").
            memory[variable] = usertype;
        }
        // 27. Branch 2: If the command is "store", trigger our internal variable locking mechanism.
       
    }
    }
