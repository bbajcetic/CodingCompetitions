#include <bits/stdc++.h>

using namespace std;

void merge_sort(vector<long long int>& numbers, int start, int end) {
	int middle = (start+end)/2;
	if(end-start == 0)
		return;
	else if(end-start == 1) {
		if(numbers[start] > numbers[end]) {
			int temp = numbers[start];
			numbers[start] = numbers[end];
			numbers[end] = temp;
		}
		return;
	}
	merge_sort(numbers,start,middle);
	merge_sort(numbers,middle+1,end);
	long long int left[middle-start+1],right[end-middle];
	for(int i = 0; i < middle-start+1; ++i)
		left[i] = numbers[start+i];
	for(int i = 0; i < end-middle; ++i)
		right[i] = numbers[middle+i];
	int index_l = 0, index_r = 0, current = start;
	while(index_l < middle-start+1 || index_r < end-middle) {
		if(index_l == middle-start+1) {
			numbers[current] = right[index_r];
			++index_r;
		}
		else if(index_r == end-middle) {
			numbers[current] = left[index_l];
			++index_l;
		}
		else {
			if(left[index_l] < right[index_r]) {
				numbers[current] = left[index_l];
				++index_l;
			}
			else {
				numbers[current] = right[index_r];
				++index_r;
			}
		}
		++current;
	}
}

vector<long long int> generate_list(vector<long long int> A, vector<long long int> B, int x) {

    int n = A.size();
    int m = B.size();
	vector<long long int> L;

    for (int i = 0; i < min(n, m - x); ++i) {
        for (int j = (i + x); j < m; ++j) {
            L.push_back(A[i]*B[j]);
//			printf("A[%d] = %lld, B[%d] = %lld\n", i,A[i],j,B[j]);
		}
	}
    return L;
}

int main() {
    int n;
    int m;
    int x;
    int k;
    cin >> n >> m >> x >> k;
    vector<long long int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<long long int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
	vector<long long int> L;
	L = generate_list(a,b,x);
	sort(L.begin(),L.end());
	merge_sort(L,0,L.size()-1);
	//for(int i = 0; i < L.size(); ++i) {
	//	cout << L[i] << " ";
	//}
	cout << L[k-1] << endl;
//	cout << "Length of L = " << L.size() << endl;
    return 0;
}


