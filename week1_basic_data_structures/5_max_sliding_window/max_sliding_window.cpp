#include <iostream>
#include <vector>
#include <deque>
using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    std::deque<unsigned int> mx;
    for (size_t j = 0; j <  w; ++j){
        while(!mx.empty() && A.at(j)>A.at(mx.back())){
            mx.pop_back();
        }
        mx.push_back(j);
        }

    cout << A.at(mx.front()) << " ";
    for (size_t i = w; i < A.size(); ++i) {
        if(mx.front()<i-w+1){
            mx.pop_front();
        }
        while(!mx.empty() && A.at(i)>A.at(mx.back())){
            mx.pop_back();
        }
        mx.push_back(i);
       cout << A.at(mx.front()) << " ";
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
