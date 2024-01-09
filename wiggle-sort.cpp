class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp(n);
        int i;
        int j=n-1;
        if(n%2==0){
            i=(n/2 - 1);
        }
        //
        else{
            i = n/2;
        }

        int k=0;

        while((i>=0 || j>i)&& k < n){
            if(k%2==0){
                temp[k]=nums[i];
                i--;
            }
            else{
                temp[k]=nums[j];
                j--;
            }
            k++;
        }
        for(int i=0;i<n;i++){
            nums[i]=temp[i];
        }
    }
};