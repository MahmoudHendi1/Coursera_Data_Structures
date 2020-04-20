#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    map<int,list<string> >mp;
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            list<string>::iterator it;
                for(it = mp[query.ind].begin();it!=mp[query.ind].end();it++){
                    std::cout << *it << " ";
                }
            std::cout << "\n";
        } else {
            bool flag=false;
            int hash = hash_func(query.s);
            list<string>::iterator it;

            if (query.type == "find"){
                for(it = mp[hash].begin();it!=mp[hash].end();it++){
                    if(*it==query.s){
                    flag=true;
                    break;
                    }
                }
                writeSearchResult(flag);
            }
            else if (query.type == "add") {
                for(it = mp[hash].begin();it!=mp[hash].end();it++){
                    if(*it==query.s){
                    flag=true;
                    break;
                    }
                }
                if(!flag)
                    mp[hash].push_front(query.s);

            } else if (query.type == "del") {
                for(it = mp[hash].begin();it!=mp[hash].end();it++){
                    if(*it==query.s){
                    mp[hash].erase(it);
                    break;
                    }
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
