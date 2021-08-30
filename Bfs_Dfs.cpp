#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    //using BFS
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        bool visited[n];
        for(bool b : visited){
            b=false;
        }

        queue<int> q ;

        visited[start] = true;
        q.push(start);

        while(!q.empty()){

            int n = q.front();
            q.pop();

            if(n==end){
                return true;
            }

            for(auto i : edges){

                if(i[0]==n){

                    if(!visited[i[1]]){
                        q.push(i[1]);
                    }
                }
                else if(i[1]==n){

                    if(!visited[i[0]]){
                        q.push(i[0]);
                    }
                }
            }
        }
        return false;
    }

    void DFS(int n, vector<vector<int>>& edges, int start, int end){
        bool visited[n];
        for(bool b : visited){
            b=false;
        }

        stack<int> s;
        s.push(start);

        while(!s.empty()){

            int n = s.top();
            s.pop();
            
            

            if(!visited[n]){
                cout << n << " ";

                visited[n]=true;
                for(auto i : edges){
                    if(i[0]==n){
                        s.push(i[1]);
                    }
                    else if(i[1]==n){
                        s.push(i[0]);
                    }
                }
            }
        }
        return;
    }
};

int main(){

    Solution sol;

    vector<vector<int>> ed = { {0,1},{1,2},{2,0} };

    
    sol.DFS(3,ed,0,2);

    return 0;
}