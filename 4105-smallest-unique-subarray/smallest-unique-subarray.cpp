    
using ll = long long;
using i128 = __int128;
const ll MOD = 1000000007;

ll add(ll a, ll b, ll m = MOD) { 
    return (((a % m) + (b % m)) % m + m) % m; 
}

ll sub(ll a, ll b, ll m = MOD) { 
    return (((a % m) - (b % m)) % m + m) % m; 
}

ll mul(ll a, ll b, ll m = MOD) { 
    return ((i128)(a % m) * (b % m)) % m; 
}

ll binpow(ll a, ll e, ll m = MOD) {
    ll ans = 1; 
    a %= m;
    while(e) {
        if(e & 1) ans = mul(ans, a, m);
        a = mul(a, a, m);
        e >>= 1;
    }
    return ans;
}

ll inv(ll a, ll m = MOD) { 
    return binpow(a, m - 2, m); 
} // prime mod

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll rand_p1 = 69;
const ll rand_p2 = uniform_int_distribution<ll>(269, (ll)1e4 - 69)(rng);

struct orz_phash {
    ll p1 = rand_p1, m1 = 6900000469LL, p2 = rand_p2, m2 = 698000002369LL, n;
    vector<ll> pref1, pref2;

    static ll ord(int c) {
        return c;
    }

    orz_phash(vector<int> s) : n((ll)s.size()) {
        ll h1 = 1, h2 = 1;
        pref1.reserve(n); 
        pref2.reserve(n);
        for(ll i = 0; i < n; i++) {
            ll v1 = mul(ord(s[i]), h1, m1);
            ll v2 = mul(ord(s[i]), h2, m2);
            if(i) {
                v1 = add(v1, pref1.back(), m1);
                v2 = add(v2, pref2.back(), m2);
            }
            pref1.push_back(v1);
            pref2.push_back(v2);
            h1 = mul(h1, p1, m1);
            h2 = mul(h2, p2, m2);
        }
    }

    pair<ll, ll> get_substr_val(ll i, ll j) {
        ll ans1 = 0, ans2 = 0;
        if(j < i) return {ans1, ans2};
        
        ans1 = pref1[j];
        ans2 = pref2[j];
        
        if(i > 0) {
            ans1 = sub(ans1, pref1[i-1], m1);
            ans2 = sub(ans2, pref2[i-1], m2);
        }

        ans1 = mul(ans1, binpow(p1, n - 1 - i, m1), m1);
        ans2 = mul(ans2, binpow(p2, n - 1 - i, m2), m2);
        
        return {ans1, ans2};
    }
};


class Solution {

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        orz_phash hashh(nums);
        int l = 1, r = n, ans = n;
        while(l <= r) {
            int m = (l + r) / 2;
            // check
            map<pair<ll, ll>, int> mp;
            for(int st = 0; st <= n - m; st++) {
                // (st, st + m - 1)
                mp[hashh.get_substr_val(st, st+m-1)]++;
            }
            bool found = false;
            for(auto &[x, y] : mp) {
                if(y == 1) { found = true; break; }
            }
            if(found) {
                ans = min(ans, m);
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};