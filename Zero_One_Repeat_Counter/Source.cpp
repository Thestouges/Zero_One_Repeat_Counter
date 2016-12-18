#include <iostream>
#include <string>

using namespace std;

/*Counts any repeating 0s and 1s in a string of 0s and 1s
 *ex: 10101 will output 4
 *and 00110 will output 3
*/
int counting(string s) {
    int count = 0;
    int repeat = 1;
	int index = 0;
    
    for(int i = 0; i < s.length(); i++){
		if(s[i] != s[i+1] && s[i+1] != '\0'){
			count++;
		}
		else{
			for(int j = i+1; j < s.length(); j++){
				if(s[i] == s[j])
					repeat++;
				else{
					index = j;
					break;
				}
			}
			for(int j = index; j < s.length(); j++){
				if(j == '\0' || s[i] == s[j])
					break;
				else
					repeat--;
			}
			if(repeat == 0)
				count++;
		}
		repeat = 1;
	}
    return count;
}

int main() {
    int res;
    string s;
	cout<<"Enter string of 0s and 1s:";
    while(1){
		cin>>s;
		if(s.find_first_not_of("01") == string::npos)
			break;
		std::cout<<"Enter valid string of 0s and 1s:";
	}

    res = counting(s);
    cout << "Number of sequences: "<<res<<endl;
	system("pause");
    return 0;
}
