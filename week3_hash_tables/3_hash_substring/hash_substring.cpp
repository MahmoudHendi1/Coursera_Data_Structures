#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;
typedef long long ll;
const int multiplier=31;
const ll prime=101;

struct Data {
    string pattern, text;
    ll pattern_hashed=0;
    ll f_hashed=0;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}
long long power(ull n, ull k){
    if(k==0) return 1;
    ull sq=(power(n,k/2))%prime;
    sq=(sq*sq)%prime;
    if(k%2==1)
        sq=(sq*n)%prime;
    return sq%prime;
}
void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> Karp(Data input){
    std::vector<int> ans;
    ll mx=power(multiplier,input.pattern.size()-1);
    for(int i=0;i<input.pattern.size();++i){
        input.pattern_hashed =(multiplier*input.pattern_hashed + input.pattern[i])%prime;
        input.f_hashed =(multiplier*input.f_hashed + input.text[i])%prime;
    }

    for (size_t i = 0; i <= input.text.size()-input.pattern.size(); ++i){
        if(input.pattern_hashed==input.f_hashed){
            if(input.pattern == input.text.substr(i,input.pattern.size()))
                ans.push_back(i);
        }
        if(i < input.text.size()-input.pattern.size()){
        input.f_hashed= (multiplier*(input.f_hashed- (input.text[i]*mx+prime))+input.text[i+input.pattern.size()])%prime;
            if(input.f_hashed<0)
                input.f_hashed+=prime;
        }
    }
    return ans;
}
std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(Karp(read_input()));
    return 0;
}
