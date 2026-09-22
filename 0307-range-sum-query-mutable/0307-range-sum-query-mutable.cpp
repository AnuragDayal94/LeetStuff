class NumArray {
public:

    vector<int>segtree;
    int n;

    void build(vector<int>&segtree, int i, vector<int>&nums, int l, int r){
        if(l==r){
            segtree[i]=nums[r];
            return ;

        }

        int mid=l+(r-l)/2;
        build(segtree, 2*i+1, nums, l, mid);
        build(segtree, 2*i+2, nums, mid+1, r);

        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
        return ;

    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        segtree.resize(4*n);
        build(segtree, 0, nums, 0, n-1);
    }

    void updates(vector<int>&segtree, int i, int ind, int val, int l, int r){
        if(l==r){
            segtree[i]=val;
            return ;
        }

        int mid=l+(r-l)/2;
        if(ind<=mid){
            updates(segtree, 2*i+1, ind, val, l, mid);
        }else{
            updates(segtree, 2*i+2, ind, val, mid+1, r);
        }
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
        return ;

    }
    
    void update(int index, int val) {
        updates(segtree, 0, index, val, 0, n-1);
        return ;
    }

    int solve(vector<int>&segtree, int i, int start, int end, int l, int r){
        if(l>end || r<start)return 0;
        if(l>=start && r<=end)return segtree[i];

        int mid=l+(r-l)/2;

        return solve(segtree, 2*i+1, start, end, l, mid)+solve(segtree, 2*i+2, start, end, mid+1, r);
    }
    
    int sumRange(int left, int right) {
        return solve(segtree, 0, left, right, 0, n-1);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */