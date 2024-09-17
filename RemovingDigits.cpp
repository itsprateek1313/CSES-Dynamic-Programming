#include <bits/stdc++.h>
using namespace std;

int min_steps_to_zero(int n) {
    int steps = 0;
    while (n > 0) {
        string num_str = to_string(n);
        int max_digit = *max_element(num_str.begin(), num_str.end()) - '0';
        n -= max_digit;
        steps++;
    }
    return steps;
}

int main() {
    int n;
    cin >> n;  
    cout << min_steps_to_zero(n) << endl;  
    return 0;
}
