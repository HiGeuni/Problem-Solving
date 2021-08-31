#include<iostream>
#include<math.h>
using namespace std;

int x, y, N, ans =0;

void solve(int sx, int sy, int depth){
	if(sx>=pow(2,N) ||sx<0 || sy>=pow(2,N) || sy<0  || depth>N) return;
	if(x<sx||y<sy) return;
	int inc_idx = pow(2,(N-depth));
	int cnt = pow(2, 2*(N-depth));
	int x1 = sx + inc_idx-1;
	int x2 = sx + 2*inc_idx-1;
	int y1 = sy+inc_idx-1;
	int y2 = sy+2*inc_idx-1;
	if(x<=x1 && y>=sy && y<=y1){ solve(sx, sy, depth+1); }
	else if(x>=x1 && x<=x2 && y>=sy && y<=y1){
		ans+=cnt;
		solve(x1+1, sy, depth+1);
	}
	else if(x>=sx && x<=x1 && y>=y1 && y<=y2){
		ans+=2*cnt;
		solve(sx, y1+1, depth+1);
	}
	else{
		ans+=3*cnt;
		solve(x1+1, y1+1, depth+1);
	}
}

int main(){
	cin>>N>>y>>x;
	solve(0,0,1);
	cout<<ans;
	return 0;
}
