#define vi vector<int>
#define vvi vector<vector<int>>


bool isFantasy(vi nums, int i, int j, int m) {
    return (j < i) && (nums[j] > nums[i]) && ((nums[j] - nums[i]) % m == 0);
}

vi fantasyValue(vi nums, int n, int m){
    vi ans(n, 0);

    int sum;
    for(int i = 1; i < n; i++) {
        sum = 0;

        for(int j = 0; j < i; j++) {
            if(isFantasy(nums, i, j, m))
                sum += nums[j];
        }

        ans[i] = sum % 2;
    } 

    return ans;
}