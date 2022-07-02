class Solution {
public:
    int mod= 1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int maxlen= max(hc[0]-0, h- hc[hc.size()-1]);
        for(int i=1; i<hc.size(); i++){
            maxlen= max(maxlen, hc[i]-hc[i-1]);
        }
        
        int maxwid= max(vc[0]-0, w- vc[vc.size()-1]);
        for(int i=1; i<vc.size(); i++){
            maxwid= max(maxwid, vc[i]-vc[i-1]);
        }
        long long area= ((0LL + maxlen)%mod * (0LL + maxwid)%mod)%mod;
        return (int) area ;
    }
};

//`````````````````````````````````````````````````````````````````````````````````````````````````````````
class Solution {
public:
    int mod= 1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        long long maxlen= max(hc[0], h- hc.back());
        for(int i=1; i<hc.size(); i++){
            maxlen= max(maxlen, (long long) hc[i]-hc[i-1]);
        }
        
        long long maxwid= max(vc[0], w- vc.back());
        for(int i=1; i<vc.size(); i++){
            maxwid= max(maxwid, (long long) vc[i]-vc[i-1]);
        }
        long long area= ( maxlen%mod *  maxwid%mod ) %mod;
        return (int) area ;
    }
};
