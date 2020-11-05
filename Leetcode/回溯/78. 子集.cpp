class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> path;
            backtrace(0, ret, nums, path, i);
        }
        return ret;
    }

    void backtrace(int first, vector<vector<int>> &ret, vector<int>& nums, vector<int> &path, const int target) {
        if (path.size() == target) {
            ret.emplace_back(path);
        }

        for (int i = first; i< nums.size(); i++) {
                path.push_back(nums[i]);
                backtrace(i + 1, ret, nums, path, target);
                path.pop_back();
        }
    }
};


class Solution {
    int n;
    vector<vector<int>> ans;
public:

    void backtrack(int first,vector<int>& nums, int num, vector<int>& path)
    {//num个是，这一轮要求的子集的规模
        if(path.size()==num)
        {
            ans.push_back(path);
        }
        for(int i=first;i<n;i++)
        {//如果path没满，再从first之后的某个位置，添加一个元素
            path.push_back(nums[i]);
            backtrack(i+1,nums,num,path);//注意，这里放i+1,作用是，保证一个path里面的元素的
                                            //顺序，在原来nums里面的对应顺序是一样的。自动起到
                                            //去重的功能。
            path.pop_back();//准备迎接下一个候选nums[i]。
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        n=nums.size();
        //枚举元素数目i吧
        for(int i=0;i<=n;i++)
        {
            vector<int> path;//空的
            backtrack(0,nums,i,path);
        }

        return ans;
        
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        for (int i = 0; i <= nums.size(); i++) {
            vector<int> path;
            backtrace(ret, nums, path, i, 0);
        }
        return ret;
    }

    void backtrace(vector<vector<int>> &ret, vector<int>& nums, vector<int> &path, const int length, int start_pos) {
        if (path.size() == length)
            ret.emplace_back(path);
        for (int i = start_pos; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrace(ret, nums, path, length, i + 1);
            path.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        for (int i = 0; i <= nums.size(); i++) {
            vector<int> path;
            vector<int> used(nums.size(), 0);
            dfs(ret, nums, path, used, i, 0);
        }
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int>& nums, vector<int> path, vector<int> used, const int length, int start) {
  
        if (path.size() == length) {
            ret.emplace_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = 1;
            path.emplace_back(nums[i]);
            dfs(ret, nums, path, used, length, i + 1);
            used[i] = 0;
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret, nums, path, 0);
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int>& nums, vector<int> path, int start) {
        ret.emplace_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.emplace_back(nums[i]);
            dfs(ret, nums, path, i + 1);
            path.pop_back();
        }
    }
};