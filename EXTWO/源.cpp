#include<vector>
#include <unordered_map>
using namespace std;
//��Ŀ����ΪK��������
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // mp��¼ǰ��������֮��ΪK������ͬ�͵Ĵ���ΪV
        unordered_map<int, int> mp;
        //��ʼkeyΪ0,valueΪ1�������������Ϊ���ڵ�������Ϊ1���ҵ���Kֵ����
        mp[0] = 1;
        // ��¼���ʵ������ַ�������
        int count = 0;
        // ��¼ǰ���������֮��
        int pre = 0;
        for (auto& x : nums) {
            pre += x;
            //map.find():��map���д����ݣ������±�ֵ�����򷵻ص���end�����ĵ�������
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

//��Ŀ���Ϳɱ�K������������
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = { {0, 1} };
        int sum = 0, ans = 0;
        for (int elem : A) {
            sum += elem;
            // ע�� C++ ȡģ�������ԣ���������Ϊ����ʱȡģ���Ϊ��������Ҫ����
            int modulus = (sum % K + K) % K;
            //map.count():���ݴ��ڷ���1,,�����ڷ���0
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
    }
};

