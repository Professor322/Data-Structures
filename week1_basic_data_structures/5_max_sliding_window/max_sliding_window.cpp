#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void max_sliding_window(vector<int> const & A, int w) {
	deque<int> d; //push indecies

	for (int i = 0; i < A.size(); ++i) {
		while (!d.empty() && A[d.back()] <= A[i]) {
			d.pop_back();
		}
		d.push_back(i);
		if (i + 1 >= w) {
			cout << A[d.front()] << ' ';
		}
		if (d.front() == i - w + 1) {
			d.pop_front();
		}
	}

	return ;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
