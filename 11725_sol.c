#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v[100005];
int ans[100005]={1};

void dfs(int x){

    for(int i=0;i<v[x].size();i++){
        int k = v[x][i];

        if(ans[k]==0){
            ans[k] = x;
            dfs(k);
        }
    }

    return;
}

int main(){
    int n;
    int x,y;

    scanf("%d",&n);

    for(int i=0;i<n-1;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for(int i=2;i<=n;i++)
        printf("%d\n",ans[i]);

    return 0;
}
