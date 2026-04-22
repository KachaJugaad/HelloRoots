#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 5};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {2, 4};
    adj[4] = {3, 5};
    adj[5] = {0, 4};
    vector<bool> visited(n, false);
    queue<int> Q; 
    int start = 0;
    Q.push(start);
    visited[start]=true;
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        cout<< node << " ";
        //cout<<"going to be checked for adjacent "<< node<<"\n";
        for(int neighbor : adj[node])
        {
            //cout << "neighbor " << neighbor << " | \n";
            if(!visited[neighbor]){
                visited[neighbor]=true;
            //cout << "not visited neighbor " << neighbor << " | \n";
                
                Q.push(neighbor);
            }
            //cout << "visited neighbor " << neighbor << " | \n";
            
        }
    }   
#if 0
for(int node = 0;node<n;node++)    {
    if(!visited[node]) 
    {
        visited[node]=true; 
        cout<< node << " ";
    }
    for(int neighbor: adj[node]){
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            cout <<" "<< neighbor;
      }
  }
}
#endif
        cout<<endl;

    return 0;
}
