class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int hash[2010];
        memset(hash, 0, sizeof(hash));
        vector<int> ans1, ans2;
        vector<vector<int>> ans;
        for(int i = 0; i < nums1.size(); i++) hash[nums1[i] + 1000] |= 8;
        for(int i = 0; i < nums2.size(); i++) hash[nums2[i] + 1000] |= 2;
        for(int i = 0; i < nums1.size(); i++) if(hash[nums1[i] + 1000] == 8) {
            ans1.push_back(nums1[i]);
            hash[nums1[i] + 1000] |= 4;
        }
        for(int i = 0; i < nums2.size(); i++) if(hash[nums2[i] + 1000] == 2) {
            ans2.push_back(nums2[i]);
            hash[nums2[i] + 1000] |= 1;
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};