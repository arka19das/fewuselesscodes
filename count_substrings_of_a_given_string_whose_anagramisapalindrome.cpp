        #include <iostream>
        using namespace std;

        #include <bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        typedef vector<long long> vl;
        typedef vector<int> vi;
        #define PB push_back 
        #define MP make_pair
        #define ln "\n"
        #define max(a, b) (a < b ? b : a) 
        #define min(a, b) ((a > b) ? b : a) 
        #define mod 1e9 + 7 
        #define forn(i,e) for(ll i=0; i<e; i++)
        #define forsn(i,s,e) for(ll i=s; i<e; i++)
        #define rforn(i,e) for(ll i=e; i>=0; i--)
        #define rforsn(i,s,e) for(ll i=s; i>=e; i--)
        #define vasort(v) sort(v.begin(), v.end())
        #define vdsort(v) sort(v.begin(), v.end(),greater<ll>())
        #define F first 
        #define S second
         
        #define out1(x1) cout << x1 << ln
        #define out2(x1,x2) cout << x1 << " " << x2 << ln
        #define out3(x1,x2,x3) cout << x1 << " " << x2 << " " << x3 << ln
        #define out4(x1,x2,x3,x4) cout << x1 << " " << x2 << " " << x3 << " " << x4 << ln
        #define out5(x1,x2,x3,x4,x5) cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << ln
        #define out6(x1,x2,x3,x4,x5,x6) cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << x6 << ln
         
        #define in1(x1) cin >> x1
        #define in2(x1,x2) cin >> x1 >> x2
        #define in3(x1,x2,x3) cin >> x1 >> x2 >> x3
        #define in4(x1,x2,x3,x4) cin >> x1 >> x2 >> x3 >> x4
        #define in5(x1,x2,x3,x4,x5) cin >> x1 >> x2 >> x3 >> x4 >> x5
        #define in6(x1,x2,x3,x4,x5,x6) cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6
         
        #define arrin(a,n) forn(i,n) cin >> a[i];
        #define arrout(a,n) forn(i,n) {cout << a[i] << " ";} cout << ln;
         
        #define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        int nxt() {int x; cin >> x; return x;}
        const ll INF = ll(1e17) + 99;
        ll gcd(ll a, ll b)  {if (b == 0) return a;  return gcd(b, a % b);  } 
        ll fact(ll n)    {ll t=1;if(n==0 ||n==1) return t; for(int i=2;i<=n;i++) t*=i; return t;} 
        const int N = int(2e5) + 99;
        vi plist;
        void SieveOfEratosthenes(int n) 
        { 
            // Create a boolean array "prime[0..n]" and initialize 
            // all entries it as true. A value in prime[i] will 
            // finally be false if i is Not a prime, else true. 
            bool prime[n+1]; 
            memset(prime, true, sizeof(prime)); 
          
            for (int p=2; p*p<=n; p++) 
            { 
                // If prime[p] is not changed, then it is a prime 
                if (prime[p] == true) 
                { 
                    // Update all multiples of p greater than or  
                    // equal to the square of it 
                    // numbers which are multiple of p and are 
                    // less than p^2 are already been marked.  
                    for (int i=p*p; i<=n; i += p) 
                        prime[i] = false; 
                } 
            } 
          
            // Print all prime numbers 
            for (int p=2; p<=n; p++) 
               if (prime[p]) 
                  plist.PB(p);
        } 
        ll power(ll x,  ll y, ll p)  
        {  
            ll res = 1;     // Initialize result  
          
            x = x % p; // Update x if it is more than or  
                        // equal to p 
           
            if (x == 0) return 0; // In case x is divisible by p; 
          
            while (y > 0)  
            {  
                // If y is odd, multiply x with result  
                if (y & 1)  
                    res = (res*x) % p;  
          
                // y must be even now  
                y = y>>1; // y = y/2  
                x = (x*x) % p;  
            }  
            return res;  
        }  
        int _mergeSort(int arr[], int temp[], int left, int right);
        int merge(int arr[], int temp[], int left, int mid, int right);
          
        /* This function sorts the input array and returns the
        number of inversions in the array */
        int mergeSort(int arr[], int array_size)
        {
            int temp[array_size];
            return _mergeSort(arr, temp, 0, array_size - 1);
        }
          
        /* An auxiliary recursive function that sorts the input array and
        returns the number of inversions in the array. */
        int _mergeSort(int arr[], int temp[], int left, int right)
        {
            int mid, inv_count = 0;
            if (right > left) {
                /* Divide the array into two parts and
                call _mergeSortAndCountInv()
                for each of the parts */
                mid = (right + left) / 2;
          
                /* Inversion count will be sum of
                inversions in left-part, right-part
                and number of inversions in merging */
                inv_count += _mergeSort(arr, temp, left, mid);
                inv_count += _mergeSort(arr, temp, mid + 1, right);
          
                /*Merge the two parts*/
                inv_count += merge(arr, temp, left, mid + 1, right);
            }
            return inv_count;
        }
          
        /* This funt merges two sorted arrays
        and returns inversion count in the arrays.*/
        int merge(int arr[], int temp[], int left,
                  int mid, int right)
        {
            int i, j, k;
            int inv_count = 0;
          
            i = left; /* i is index for left subarray*/
            j = mid; /* j is index for right subarray*/
            k = left; /* k is index for resultant merged subarray*/
            while ((i <= mid - 1) && (j <= right)) {
                if (arr[i] <= arr[j]) {
                    temp[k++] = arr[i++];
                }
                else {
                    temp[k++] = arr[j++];
          
                    /* this is tricky -- see above
                    explanation/diagram for merge()*/
                    inv_count = inv_count + (mid - i);
                }
            }
          
            /* Copy the remaining elements of left subarray
        (if there are any) to temp*/
            while (i <= mid - 1)
                temp[k++] = arr[i++];
          
            /* Copy the remaining elements of right subarray
        (if there are any) to temp*/
            while (j <= right)
                temp[k++] = arr[j++];
          
            /*Copy back the merged elements to original array*/
            for (i = left; i <= right; i++)
                arr[i] = temp[i];
          
            return inv_count;
        }
        ll binomialCoeff(ll n, ll k)
        {
            ll res = 1;
          
            // Since C(n, k) = C(n, n-k)
            if (k > n - k)
                k = n - k;
          
            // Calculate value of
            // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
            for (ll i = 0; i < k; ++i) {
                res *= (n - i);
                res /= (i + 1);
            }
          
            return res;
        }
         
        

        bool sortbysec(const pair<int,int> &a, 
                      const pair<int,int> &b) 
        { 
            return (a.second < b.second); 
        } 
        /*-----------------------------Code begins------------------------*/
         bool sortinrev(const pair<int,int> &a,  
                   const pair<int,int> &b) 
        { 
           return (a.first > b.first); 
        } 

        

    int MAXN=4e5;
    vl t(MAXN);



    void build(ll a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    ll  get_max(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 1e9+100;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return min(get_max(v*2, tl, tm, l, min(r, tm)), 
                       get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
    }


void solve()
 { ll l,r,g,x,y,m,n,ans1=1e18+7,ans13=0,
   ans2=0,ans3=0,value,ans4=0,flag1=0,ans5=0,ans6=-1e18,ans=0,k=0;
   
   string s;
   cin>>s;
   n=s.length();
   vi v(26,0);flag1=0;
   for(int i=0;i<n;i++)
   {

        v[s[i]-'a']++;
        int odd=0;
        forn(j,26)
        {
            if(v[j]%2)
                odd++;
        }
        if(odd>=2)
        {
            for(int j=flag1;j<i;j++)
            {   v[s[j]-'a']--;
                odd=0;
                forn(k,26)
                {
                    if(v[k]%2)
                        odd++;
                }
                if(odd<2)
                {
                    flag1=j+1;
                    break;
                }
            }

        }
        //out3(i,flag1,odd);
            ans+=i-flag1+1;
        
   }
   cout<<ans;



 }

        int main() {
            #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin); 
            freopen("output.txt","w",stdout);
            //freopen("error.txt","w",stderr);
            #endif
            zoom;
            SieveOfEratosthenes(100000);
             ll t=1;
            
            in1(t);
             while(t--) {
                solve();cout<<ln;
                cerr<<t<<" ";
             }
         
            return 0;
        }
            
                
