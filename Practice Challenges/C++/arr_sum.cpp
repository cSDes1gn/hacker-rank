#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <fstream>
#include <string>
#include <cstdlib>

// reduce need for scope resolution operator :: assigning a namespace to every std function
using namespace std;

// function declaration (prototype)
// good practice for larger products where dependancies are harder to manage
// in addition it prevents circular dependancies in function definitions
vector<string> split_string(string);
int arrSum(vector<int> ar);


int main(void){
    
    // request for array length
    int ar_count;
    cin >> ar_count;
    
    // flushes the character buffer in cin for new data read
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string ar_temp_temp;
    // read new line of characters from cin (array values)
    getline(cin,ar_temp_temp);

    // split input string by ' ' delimiters and store as a string vector
    vector<string> ar_temp = split_string(ar_temp_temp);
    // initialize empty integer vector with length ar_count which holds integer values of array
    vector<int> ar(ar_count);

    // fill integer vector with values from string vector
    for (int i = 0; i < ar_count; i++){
        // std::stoi converts string to int
        int ar_item = stoi(ar_temp[i]);
        ar[i] = ar_item;
    }

    // compute and display sum
    int result = arrSum(ar);
    cout << result << endl;
    return 0;
}

// function definitions
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' '){
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos){
        splits.push_back(input_string.substr(i,pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i,min(pos,input_string.length()) - i + 1));
    return splits;
}

int arrSum(vector<int> ar){
    int sum = 0;
    // iterate over vector<int> by size_type which counts indices [0,ar.size()]
    for(vector<int>::size_type i = 0; i != ar.size(); i++) {
        sum += ar[i];
    }
    return sum;
}

