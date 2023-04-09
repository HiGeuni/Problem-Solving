#include<bits/stdc++.h>

using namespace std;

const double PI = acos(-1); // PI 값을 지정해 놓음
typedef complex<double> cpx;
 
void FFT(vector<cpx> &f, cpx w){
    int n = f.size();
    if(n == 1) return;

    vector<cpx> even(n/2), odd(n/2);
    for(int i = 0; i < n; ++i)
        (i%2 ? odd : even)[i/2] = f[i];
 
    FFT(even, w*w);
    FFT(odd, w*w);
 
    cpx wp(1, 0);
    for(int i = 0; i < n/2; ++i){
        f[i] = even[i] + wp*odd[i];
        f[i + n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n);

    cpx w(cos(2*PI/n), sin(2*PI/n)); // k == 1일 때는 k번 n번 곱해져야 1이므로
 
    FFT(a, w);
    FFT(b, w);
 
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*b[i];
 
    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<cpx>a(2*n), b(2*n, 0);
    for(int i=0; i<n; ++i){
        cin>>a[i];
        a[i+n] = a[i];
    }
    for(int i=1; i<=n; ++i){
        cin>>b[n-i];
    }
    vector<cpx> ans = multiply(a, b);
    double p =0;
    for(int i=0; i<ans.size(); ++i){
        p = max(ans[i].real(), p);
    }
    cout<<(long long)p<<'\n';
    return 0;
}
