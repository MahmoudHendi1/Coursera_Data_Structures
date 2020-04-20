#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<long long> data_;
  vector< pair<long long, long long> > swaps_;

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

  void SiftDown(int i){
  int mxind=i;

  }
void min_heap(int i,int dsize){
     int l,r;
        l=2*i+1;
        r=2*i+2;
        int smallest=i;
        if(l < dsize && data_[l] < data_[i])
            smallest=l;
        else
            smallest=i;
        if(r < dsize && data_[r] < data_[smallest])
            smallest=r;
        if(smallest != i){
            swap(data_[i],data_[smallest]);
             swaps_.push_back(make_pair(i, smallest));
            min_heap(smallest,dsize);
        }
}
  void GenerateSwaps() {
    swaps_.clear();
    for(int i=data_.size()/2-1; i>=0;i--){
        min_heap(i,data_.size());

    }

  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
