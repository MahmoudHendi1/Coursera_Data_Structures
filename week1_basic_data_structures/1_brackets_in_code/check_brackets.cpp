#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket temp(next,position+1);
        if (next == '(' || next == '[' || next == '{')
            opening_brackets_stack.push(temp);
        if (next == ')' || next == ']' || next == '}') {
            if(!opening_brackets_stack.empty() &&
               opening_brackets_stack.top().Matchc(temp.type))
                    opening_brackets_stack.pop();
            else{
                std::cout << position+1 <<std::endl;
                return 0;
            }
        }
    }
    if(opening_brackets_stack.empty()){
    std::cout << "Success" <<std::endl;
    }else{
        int s;
        while(!opening_brackets_stack.empty()){
           s = opening_brackets_stack.top().position;
            opening_brackets_stack.pop();
        }
        std::cout << s <<std::endl;
    }


    return 0;
}
