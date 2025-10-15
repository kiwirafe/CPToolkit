#include <bits/stdc++.h>
using namespace std;

string padZero(const string &s, int n) {
    string res = s;
    while ((int)res.size() < n) res = "0" + res;
    return res;
}

// Add two numeric strings
string addStrings(const string &a, const string &b) {
    string res;
    int carry = 0;
    int n = max(a.size(), b.size());
    string x = padZero(a, n), y = padZero(b, n);

    for (int i = n - 1; i >= 0; i--) {
        int sum = (x[i] - '0') + (y[i] - '0') + carry;
        res += char(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) res += char(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

// Subtract numeric strings (assume a >= b)
string subStrings(const string &a, const string &b) {
    string res;
    int n = max(a.size(), b.size());
    string x = padZero(a, n), y = padZero(b, n);
    int borrow = 0;

    for (int i = n - 1; i >= 0; i--) {
        int diff = (x[i] - '0') - (y[i] - '0') - borrow;
        if (diff < 0) { diff += 10; borrow = 1; }
        else borrow = 0;
        res += char(diff + '0');
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

// Remove leading zeros
string stripLeadingZeros(const string &s) {
    int i = 0;
    while (i < (int)s.size() - 1 && s[i] == '0') i++;
    return s.substr(i);
}

// Karatsuba recursive function
string karatsuba(string x, string y) {
    x = stripLeadingZeros(x);
    y = stripLeadingZeros(y);
    int n = max(x.size(), y.size());
    if (n == 1)
        return to_string((x[0] - '0') * (y[0] - '0'));

    n = (n / 2) + (n % 2);
    string x_high = x.substr(0, x.size() - n);
    string x_low  = x.substr(x.size() - n);
    string y_high = y.substr(0, y.size() - n);
    string y_low  = y.substr(y.size() - n);

    if (x_high.empty()) x_high = "0";
    if (y_high.empty()) y_high = "0";

    string z0 = karatsuba(x_low, y_low);
    string z1 = karatsuba(addStrings(x_low, x_high), addStrings(y_low, y_high));
    string z2 = karatsuba(x_high, y_high);

    string mid = subStrings(subStrings(z1, z2), z0);

    // shift z2 by 2n digits, mid by n digits
    z2 += string(2 * n, '0');
    mid += string(n, '0');

    return stripLeadingZeros(addStrings(addStrings(z2, mid), z0));
}

int main() {
    string a = "12345678";
    string b = "87654321";

    cout << "Product = " << karatsuba(a, b) << endl;
    return 0;
}