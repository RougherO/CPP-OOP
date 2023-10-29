// ----- Streams --------------
#include <iostream>
#include <fstream>
#include <sstream>
// ----- Data Structures ------
#include <array>
#include <vector>
#include <valarray>
#include <string>
#include <string_view>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <queue>
// #include <span> /* Check availability */
#include <stack>
#include <list>
#include <iterator>
// ----- Algorithm ------------
#include <algorithm>
#include <numeric>
// ----- Helper functions -----
#include <limits>
// #include <format> /* Check availability */
#include <cctype>
#include <functional>
// ----- Math -----------------
#include <cmath>
#include <complex>
#include <numbers>
// ----- Utilities ------------
#include <bitset>
// #include <bit> /* Check availability */
#include <tuple>
#include <regex>
#include <optional>
#include <any>
#include <variant>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int T {};
    cin >> T;
    while (T--) {
        int s, g, n, sick_sub;
        cin >> s >> g >> n;
        if (s % g == 0) {
            s /= g;
            s *= n * 17;
            cout << s << "\n";
        } else if (n % g == 0) {
            n /= g;
            n *= s * 17;
            cout << n << "\n";
        } else {
            int temp = n / g;
            temp *= s * 17;
            cout << temp + (n % g) * (s % g) % g;
        }
    }
}