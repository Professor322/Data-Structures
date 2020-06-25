#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;


class StackWithMax {

  public:

    void Push(int value) {
    	s.push(value);
    	if ((!mx.empty() && mx.top() <= value) || mx.empty()) {
    		mx.push(value);
    	}
    }

    void Pop() {
    	if (mx.top() == s.top()) {
    		mx.pop();
    	}
    	s.pop();
    }

    int Max() const {
		return mx.top();
    }
private:
	stack<int> s;
    stack<int> mx;
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}