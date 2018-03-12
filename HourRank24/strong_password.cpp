#include <bits/stdc++.h>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int minimumNumber(int n, string password) {
	bool arr[4] = {false,false,false,false}; //digit/lower/upper/special
	if(password.find_first_of("!@#$%^&*()-+")!=string::npos)
		arr[3] = true;
	for(int i = 0; i < n; ++i) {
		if(isdigit(password[i]))
			arr[0] = true;
		else if(islower(password[i]))
			arr[1] = true;
		else if(isupper(password[i]))
			arr[2] = true;
	}
	int length = password.length();
	int count = 0;
	for(int i = 0; i < 4; ++i) {
		if(arr[i] == true)
			++count;
	}
	if(length>=6)
		return count;
	else
		return max(6-length,count);

}

int main() {
    int n;
    cin >> n;
    string password;
    cin >> password;
    int answer = minimumNumber(n, password);
    cout << answer << endl;
    return 0;
}
