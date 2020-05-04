#include <iostream>
using namespace std;

int main(){
    
    int N,M;
    cin>>N>>M; 
    int package=1000;
    int unit=1000;
    int tmp1, tmp2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&tmp1,&tmp2);
        package=min(package,tmp1);
        unit=min(unit,tmp2);
    }
    
    int ans=0;
    if(N<6){
        ans=min(package,unit*N);
    }else{
        
        if(N%6==0){
            ans=min(package*(N/6),unit*N);
        }else{
            ans=min(package*(N/6)+unit*(N%6),unit*N);
            ans=min(ans,package*(N/6+1));
        }
    }
    cout<<ans<<endl;
    return 0;
}
 
