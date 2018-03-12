#include <bits/stdc++.h>
#include <set>

using namespace std;

bool isdivisible(int a, int b) {
	if(a<b)
		return !(b%a);
	else
		return !(a%b);
}

void get_team(set<int>& team, int startnum, int endnum, int numplayers) {
	int size = 0;
	bool divisible = false;
	for(int i = endnum; i >= startnum; --i) {
		if(size == numplayers)
			break;
		divisible = false;
		if(team.empty() || i > endnum/2) {
			team.insert(i);
			++size;
		}
		else
			break;
/*		else {
			for(set<int>::iterator it = team.begin(); it != team.end(); ++it) {
				if(isdivisible(*it,i))
					divisible = true;
			}
			if(!divisible) {
				team.insert(i);
				++size;
			}
		}*/
	}
}

int main() {
	set<int> team;
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int a;
        int b;
        int x;
        cin >> a >> b >> x;
		get_team(team,a,b,x);
		if(team.size()!=x) {
			cout << -1 << endl;
		}
		else {
			for(set<int>::iterator it = team.begin(); it != team.end(); ++it)
				if(it != team.begin())
					cout << " " << *it;
				else
					cout << *it;
			cout << endl;
		}
		//print answer
		team.clear();
    }
    return 0;
}
