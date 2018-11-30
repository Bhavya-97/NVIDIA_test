#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unistd.h>

using namespace std;

#define MAX 255

unsigned int FindFunctionDefn( const char* strFunctionName, const char* strSourceCode ) {
    FILE * fptr;                                                        //fptr to point to the file

    fptr = fopen(strSourceCode, "r");                                        //reads the given file

    char buffer[MAX];                                                   //stores a line while reading the file
    int line = 0, length = strlen(strFunctionName);                            //line: retains a count of the line ; length: stores the length of the function name
    vector<char> s;                                                     //utility stack

    while(fgets(buffer, 255, fptr) != NULL) {                           //reads the file line by line
      line++;

      string buff(buffer);
      int found = buff.find(strFunctionName);                                  //stores the first occurence of the function name in the line

  		if(found != string::npos) {                                       //if successfully found
        int index;

        if(buff[found + length] == ' ') {                               //token ends here
  			     index = found + length + 1;
        } else {
  			     index = found + length;
  		  }

        while(buff[index] != '\0') {
          if(buff[index] == '(') {                                    //marks the start of the parameters to be passed, if any
            s.push_back('(');
          } else if(buff[index] == ')' && !s.empty()) {               //marks the end of the parameters' list, if any
            s.pop_back();
          } else if(buff[index] == '{' && s.empty()) {                //marks the start of the function definition
            return line;
          } else if(buff[index] == ';') {                             //marks that function wasn't defined but might have been called
            s.clear();
            break;
          }

          index++;
        }
      }
    }

    return 0;
}

int main() {
    char strSourceCode[20], strFunctionName[20];                         //strSourceCode: stores the code-file ; strFunctionName: stores the function name to be searched

    cout << "Enter an existing filename and function name to be found: ";
    cin >> strSourceCode >> strFunctionName;

    while(1) {                                                          //checks for existing filename
      if(access(strSourceCode, F_OK) == 0)
		    break;
      else {
        cout << "Enter a valid filename and function name: ";
        cin >> strSourceCode >> strFunctionName;
      }
    }

    cout << "Line number storing the function definition: " << FindFunctionDefn(strFunctionName, strSourceCode) << endl;    //prints the line number if the function definition is found else returns 0

    return 0;
}
