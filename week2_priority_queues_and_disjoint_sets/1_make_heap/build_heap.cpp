#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int LeftChild(int i) {
  	return i * 2 + 1;
  }

  int RightChild(int i) {
  	return i * 2 + 2;
  }

  int Parent(int i) {
  	return (i - 1)/ 2;
  }

  void SiftDown(int i) {
  	int MaxIndex = i;
	int l = LeftChild(i);

	if (l < data_.size() && data_[l] < data_[MaxIndex]) {
		MaxIndex = l;
	}

	int r = RightChild(i);

	if (r < data_.size() && data_[r] < data_[MaxIndex]) {
		MaxIndex = r;
	}
	if (MaxIndex != i) {
		swaps_.emplace_back(i, MaxIndex);
		swap(data_[i], data_[MaxIndex]);
		SiftDown(MaxIndex);
	}
  }

  void BuildHeap() {
  	for (int i = (data_.size() - 1) / 2; i >= 0; --i) {
  		SiftDown(i);
  	}
  }

 public:
  void Solve() {
    ReadData();
    BuildHeap();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
