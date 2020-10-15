#include<vector>
#include <unordered_map>
using namespace std;
//题目：和为K的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // mp记录前几个数字之和为K出现相同和的次数为V
        unordered_map<int, int> mp;
        //初始key为0,value为1。个人理解是因为存在当子数组为1个且等于K值的数
        mp[0] = 1;
        // 记录合适的连续字符串数量
        int count = 0;
        // 记录前面数字相加之和
        int pre = 0;
        for (auto& x : nums) {
            pre += x;
            //map.find():当map中有此数据，返回下标值。否则返回等于end函数的迭代器。
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

//题目：和可被K整除的子数组
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = { {0, 1} };
        int sum = 0, ans = 0;
        for (int elem : A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            //map.count():数据存在返回1,,不存在返回0
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
    }
};

