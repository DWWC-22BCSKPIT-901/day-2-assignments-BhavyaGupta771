#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
bool canAssign(const vector<int>& jobs, vector<int>& workers, int
maxWorkingTime, int index) {
if (index == jobs.size())
{ return true;
}

for (int i = 0; i < workers.size(); ++i) {
if (workers[i] + jobs[index] <= maxWorkingTime)
{ workers[i] += jobs[index];
if (canAssign(jobs, workers, maxWorkingTime, index + 1))
{ return true;
}
workers[i] -= jobs[index];
}
if (workers[i] == 0)
{ break;
}
}
return false;
}
int minimumTimeRequired(vector<int>& jobs, int k)
{ int left = *max_element(jobs.begin(), jobs.end());
int right = accumulate(jobs.begin(), jobs.end(), 0);

sort(jobs.rbegin(), jobs.rend());
while (left < right) {
int mid = left + (right - left) / 2;
vector<int> workers(k, 0);
if (canAssign(jobs, workers, mid, 0))
{ right = mid;
} else {
left = mid + 1;
}

}
return left;
}
int main() {
vector<int> jobs = {3, 2, 3};
int k = 3;
cout << "Minimum possible maximum working time: " <<
minimumTimeRequired(jobs, k) << endl;
return 0;
}