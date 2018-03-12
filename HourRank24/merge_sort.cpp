#include <iostream>
#include <vector>
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
int main() {
	vector<long long int> nums;
	nums.push_back(4);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(8);
	nums.push_back(5);
	nums.push_back(9);
	nums.push_back(4);
	for(int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
	merge_sort(nums,0,nums.size()-1);

	for(int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
/*	for(int i = 0; i < nums.size(); ++i) {
		cout << (i==0) ? "" : " ";
		cout << nums[i] << " ";
	}*/
	cout << endl;

	return 0;
}
