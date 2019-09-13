#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
    if (start > destination) return distanceBetweenBusStops(distance, destination, start);
    int sum = 0;
    for (int i = start; i < destination; ++i) {
      sum += distance[i];
    }
    int sum2 = 0;
    for (int i = destination; sum2 < sum && i < distance.size(); ++i) {
      sum2 += distance[i];
    }
    for (int i = 0; sum2 < sum && i < start; ++i) {
      sum2 += distance[i];
    }
    return min(sum, sum2);
  }
};

void test1() {
  vector<int> v1{1, 2, 3, 4};
  int start = 0;
  int destination = 1;

  cout << "1 ? " << Solution().distanceBetweenBusStops(v1, start, destination) << endl;

  start = 0;
  destination = 2;

  cout << "3 ? " << Solution().distanceBetweenBusStops(v1, start, destination) << endl;

  start = 0;
  destination = 3;

  cout << "4 ? " << Solution().distanceBetweenBusStops(v1, start, destination) << endl;

}

void test2() {

}

void test3() {

}