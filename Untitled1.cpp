#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m , n;
    vector<int> child[102];
    int parent[102];
    vector<int> bfs;
    cin>>n>>m;
    int i , j , a , b ;
    for ( i = 0; i < n+1 ; i++ )
        parent[i] = 0;
        
    for ( i = 0; i < m ; i ++){
        cin>> a >> b;
        child[b].push_back(a);
        parent[a] = b;
    }
    //find the root
    int root;
    for ( i = 1; i < n + 1; i ++) 
        if ( parent[i] == 0) {
            root = i;
            break;
        }
    //bfs
    int head , tail , k;
    bfs.push_back(root);
    head = 0; 
 
    while( head < bfs.size() ){
        k = bfs[head];
        for ( i = 0;  i < child[k].size(); i ++)
            bfs.push_back(child[k][i]);
        head ++;
    }
    vector<int> number( n + 1 , 1);
    // start to reverse 
    i = bfs.size() - 1 ;
    int result = 0;
    while ( i >= 0 ){
        if ( number[bfs[i]] % 2 == 0){
            result ++;
        }else{
            k = parent[bfs[i]];//parent node
            number[k] += number[bfs[i]];
        }
        i --;
    }
    cout<< result -1 << endl;
    return 0;
    system("pause");
}
