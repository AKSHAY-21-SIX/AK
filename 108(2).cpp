#define mod 1000000007
long long int countDerangements(int n) {
   
    if(n == 0){
        return 0;
    }
    if(n ==2){
        return 1;
    }

    int ans =( ( (n-1)%mod) * ( (countDerangements(n-1) % mod) + (countDerangements(n-2) % mod) ) %mod);

    return ans;
}