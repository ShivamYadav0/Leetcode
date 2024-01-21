class Solution {
 public:
  void print(set<pair<int, int>> s, int k) {
    int sm = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
      if (k > 0) sm += (*it).first;
      k--;
      cout << "{" << (*it).first << " " << (*it).second << "} ,";
    }
    cout << sm << "|" << endl;
  }
  long long minimumCost(vector<int>& nums, int k, int dist) {
    set<pair<int, int>> ms;
    long long s = nums[0];
    k--;
    for (int i = 1; i <= dist + 1; i++) {
      ms.insert({nums[i], i});
    }
    long long mx = 0;
    auto it = ms.begin();
    int kk = k;
    while (k > 1) {
      mx += (*it).first;
      it++, k--;
    }
    mx += (*it).first;
    s += mx;
    int j = 1;

    for (int i = dist + 2; i < nums.size(); i++) {
      if ((*it).second == j) {
        mx -= nums[j];

        ms.insert({nums[i], i});
        // mx+=nums[i];
        if (nums[i] < (*it).first) {
          mx += nums[i];
          it--;
        } else {
          it++;
          mx += (*it).first;
        }
        ms.erase({nums[j], j});

      } else if (nums[j] >= (*it).first) {
        if (nums[j] == (*it).first && j < (*it).second) {
          ms.erase({nums[j], j});
          mx -= nums[j];
          ms.insert({nums[i], i});

          if (nums[i] >= (*it).first) {
            it++;
            mx += (*it).first;
          } else
            mx += nums[i];
          //  it++;
        } else {
          ms.erase({nums[j], j});
          ms.insert({nums[i], i});
          if (nums[i] < (*it).first) {
            mx -= (*it).first;
            mx += nums[i];
            it--;
          }
        }
      } else {
        ms.erase({nums[j], j});
        mx -= nums[j];
        if (nums[i] < (*it).first) {
          ms.insert({nums[i], i});

          mx += nums[i];

        }

        else {
          ms.insert({nums[i], i});

          it++;
          mx += (*it).first;
        }
      }
      j++;

      s = min(s, mx + nums[0] * 1ll);
    }

    return s;
  }
};
