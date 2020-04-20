#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using std::vector;
using std::priority_queue;
using std::cin;
using std::cout;
using std::greater;
using std::pair;

typedef pair< long long ,int> pi;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i){
      cin >> jobs_[i];
    }
  }
  void AssignJobs() {
    priority_queue <pi, vector<pi>, greater<pi> > processes;
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    for(int i=0;i<num_workers_;i++){
        processes.push(std::make_pair(0,i));

    }
    for(int i=0;i<jobs_.size();i++){
        pi p = processes.top();
        assigned_workers_[i]=p.second;
        start_times_[i]=p.first;
        processes.pop();
        processes.push(std::make_pair(p.first+jobs_[i],p.second));
    }

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
