//July 2

//https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1#
//Approach- traverse throught the given adjacency matrix and print the vertices attached to each vertex as traversed

vector<vector<int>>printGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<vector<int>> ans;
	    for(int i=0; i<V ;i++){
	        vector<int> temp;
	        temp.push_back(i);
	        for(int e:adj[i]){
	            temp.push_back(e);
	        }
	        ans.push_back(temp);
	    }
	    return ans;
	}

//https://practice.geeksforgeeks.org/problems/count-the-paths4332/1
//Approach- make a vector of graph which has all the edges stored. Then push the source in a stack and pop it one by one. if source is equal to destination, 
//increase count by 1 as there would be only one path from source to destination. And then push all the vertex attached to source inside the stack and keep
//repeating the process till all the edges are traversed

int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<int>graph[n];
	    for(int i=0;i<edges.size();i++)
	    {
	        int a,b;
	        a = edges[i][0];
	        b = edges[i][1];
	        graph[a].push_back(b);
	    }
	    int count = 0;
	    stack<int>st;
	    st.push(s);
	    while(!st.empty())
	    {
	        int x = st.top();
	        st.pop();
	        if(x==d)
	        count++;
	        for(auto itr = graph[x].begin();itr!=graph[x].end();itr++)
	        {
	            st.push(*itr);
	        }
	    }
	    return count;
	}

//https://www.pepcoding.com/resources/online-java-foundation/graphs/has-path-official/ojquestion
//Approach- if source is equal to destination, return true since they have a path between them. Mark the source as visited and check if the neighbouring vertex of
//source have a path to destination, if they have a path, then source has a path to destination.

bool hasPath(vector<Edge> graph, int src, int dest, vector<bool> visited){
          if(src==dest) 
          return true;
          visited[src]=true;
          for(Edge e: graph[src]){
              if(!visited[e.nbr]){
                  bool nbrHasPath = hasPath(graph, e.nbr, dest, visited);
                  if (nbrHasPath){
                      return true;
                  }
              }
          }
          return false;
      }

//https://www.pepcoding.com/resources/online-java-foundation/graphs/print-all-paths-official/ojquestion
//Approach- maintain as string having path so far and keep adding all the paths from source to destination in it while traversing all the edges from the source to
//the given destination

void printAllPath(vector<Edge> graph, int src, int dest, vector<bool> visited, string psf){
        if(src==dest) {
            cout<<psf;
            return;
        }
        visited[src]=true;
        for(Edge e: graph[src]){
            if(!visited[e.nbr]){
                printAllPath(graph, e.nbr, dest, visited, psf+e.nbr);
            }
        }
        visited[src]=false;
    }

//July 3

//https://www.pepcoding.com/resources/online-java-foundation/graphs/hamiltonian-official/ojquestion
//Approach- Start with the source and keep storing the path in the string names psf(path so far). If there exists a path which covers all the vertices, then it is 
//a hamiltonian path. Print that path with a dot at the end. And if there is an edge between the source and the destination, then it is a hamiltonian cycle, 
//print it with an * at end

void hamiltonian(vector<vector<Edge> graph, int src, unordered_set<int> visited, string psf, int osrc){
        if(visited.size()==graph.size()-1){
            cout<<psf;
            bool cycle=false;
            for(Edge e: graph[src]){
                if(e.nbr==osrc){
                    cycle=true;
                    break;
                }
            }
            if(cycle==true){
                cout<<"*"<<endl;
            }
            else cout<<"."<<endl;
            return;
        }
        visited[src]++;
        for(Edge e: graph[src]){
            if(visited.find(e.nbr)==visited.end()){
		psf+=e.nbr;
                hamiltonian(graph, e.nbr, visited, psf, osrc);
            }
        }
        visited.erase(src);
    }

//https://www.pepcoding.com/resources/online-java-foundation/graphs/is-graph-connected-official/ojquestion
//Approach- Check for all the vertices and mark them as visited as soon as they are checked, then mark their neighbours visited and add them in the component. Only
//those nighbours can be visited and added in a component which haven't been added before. So for each vertex, its neighbours will be checked and added in a
//component of components

void getConnectedComponents (int vtces, vector<vector<int>> comps, vector<vector<Edge>> graph){
	vector<bool> visited (vtces, false);
      	vector<vector<int>> comps;
      	for(int v = 0; v < vtces; v++){
        	if(visited[v] == false){
            	vector<int> comp;
            	gcc(graph, v, visited, comp);
            	comps.push_back(comp);
         	}
      	}
      	return(comps.size() == 1);
   }

   void gcc(vector<vector<Edge>> graph, int src, vector<bool> visited, vector<int> comp) {
      comp.push_back(src);
      visited[src] = true;
      for (Edge e : graph[src]) {
         if (!visited[e.nbr]) {
            gcc(graph, e.nbr, visited, comp);
         }
      }
   }

//July 4

//https://leetcode.com/problems/number-of-islands/
//Approach- Check for all the elements and if they are not visited yet, and check in their 4 directions and mark them visited as well. When one island is traversed,
//then next elements in the matrix are checked and if another island (denoted by 1) is encountered, increase the count and check in all 4 directions. Check till all
//elements are traversed and return the count

void drawTree(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'||vis[i][j]==true)
            return;
        
        vis[i][j]=true;
        drawTree(grid, i-1, j, vis);
        drawTree(grid, i+1, j, vis);
        drawTree(grid, i, j-1, vis);
        drawTree(grid, i, j+1, vis);
    }
int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==false){
                    drawTree(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }

//https://leetcode.com/problems/island-perimeter/
//Approach- Traverse all the elements and increase count when an island piece is encountered (denoted by 1) and check in all 4 directions for counting its immediate
//neighbours. The perimeter is given by (total count) * 4 - (total neighbours) coz when a block is joined with another, 2 edges are removed from the perimeter.

int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0){
            return 0;
        }
        vector<vector<int>> dir={{0,1}, {1,0}, {-1,0}, {0,-1}};
        int n=grid.size();
        int m=grid[0].size();
        int count=0, nbrs=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    count++;
                    for(int d=0; d<dir.size(); d++){
                        int r=i+dir[d][0];
                        int c=j+dir[d][1];
                        
                        if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
                            nbrs++;
                        }
                    }
                }
            }
        }
        return count*4-nbrs;
    }

//https://leetcode.com/problems/max-area-of-island/
//Approach- Traverse through all the matrix elements and check in its 4 directions for its neighbours and calculate the total area of an island piece. Keep storing
//the maximum area and update the maximum area as the elements are traversed and return the maximum area found
 
int drawTree(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==true)
            return 0;
        vis[i][j]=true;
        int area=1;
        area+=drawTree(grid, i-1, j, vis);
        area+=drawTree(grid, i+1, j, vis);
        area+=drawTree(grid, i, j-1, vis);
        area+=drawTree(grid, i, j+1, vis);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int area=0;
                if(grid[i][j]==1 && vis[i][j]==false){
                    area+=drawTree(grid, i, j, vis);
                    maxArea=max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

//https://leetcode.com/problems/surrounded-regions/
//Approach- Traverse all the elements and replace 'O' at the boundaries and its neighbours with '$' sign and the 'O' away from boundary with 'X'

void surroundedRegion(int i, int j, int n, int m, vector<vector<char>>& board, vector<vector<int>>& dir){
        board[i][j]='$';
        for(int d=0; d<dir.size(); d++){
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 && c>=0 && r<n && c<m && board[r][c]=='O')
                surroundedRegion(r,c,n,m,board,dir);
        }
    }
void solve(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0){
            return;
        }
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> dir={{0,-1}, {0,1}, {1,0}, {-1,0}};
        for(int i=0; i<n; i++){
            if(board[i][0]=='O')
                surroundedRegion(i,0,n,m,board,dir);
            if(board[i][m-1]=='O')
                surroundedRegion(i,m-1,n,m,board,dir);
        }
        for(int j=0; j<m; j++){
            if(board[0][j]=='O')
                surroundedRegion(0,j,n,m,board,dir);
            if(board[n-1][j]=='O')
                surroundedRegion(n-1,j,n,m,board,dir);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='$')
                    board[i][j]='O';
            }
        }
    }

//July 5

//https://www.pepcoding.com/resources/online-java-foundation/graphs/is-cyclic-official/ojquestion#!
//Approach- Insert the elements starting from source, the insert its neighbours. After traversing the elements, mark them as visited and if an element which is
//already traversed is up for insertion in queue, it means that there is a cycle in the graph.

bool detectCycle (int vtces, vector<vector<Edge>> graph){
vector<bool> visited(vtces, false);
      for(int v=0; v<vtces; v++){
          if(visited[v]==false){
              bool cycle = isCyclic(graph, v, visited);
              if(cycle){
                return true;
              }
          }
      }
      return false;
   }

   class Pair{
       int v;
       string psf;
       
       Pair(int v, string psf){
           this->v=v;
           this->psf=psf;
       }
   };
   
   bool isCyclic(vector<vector<Edge>> graph, int src, vector<bool> visited){
      queue<Pair> q;
      q.push(Pair(src, to_string(src)+""));
      while(q.size()>0){
          Pair rem=q.front();
	  q.pop();
          
          if(visited[rem.v]==true){
              return true;
          }
          visited[rem.v]=true;
          for(Edge e: graph[rem.v]){
              if(visited[e.nbr]==false){
                  q.push(Pair(e.nbr, to_string(rem.psf)+to_string(e.nbr)));
              }
          }
      }
      return false;
   }

//https://leetcode.com/problems/shortest-path-in-binary-matrix/
//Approach- Traverse through the elements in the matrix only when they are 0. When on an element, check in 8 directions including diagonals and only travel when
//the adjacent elements are 0. When taking the next step, level is increased to count the shortest path. And 2D matrix is converted to 1D matrix for easy traversal

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0){
            return -1;
        }
        int n=grid.size();
        int m=n;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        queue<int> que;
        vector<vector<int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};
        
        grid[0][0]=1;
        que.push(0*m+0);
        
        int level=1;
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int idx= que.front();
                que.pop();
                int r=idx/m;
                int c=idx%m;
                if(r==n-1 && c==m-1){
                    return level;
                }
                for(int d=0; d<dir.size(); d++){
                    int x=r+dir[d][0];
                    int y=c+dir[d][1];
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0){
                        grid[x][y]=1;
                        que.push(x*m+y);
                    }
                }
            }
            level++;
        }
        return -1;
    }

//https://leetcode.com/problems/is-graph-bipartite/
//Approach- Insert the elements in a queue starting from source and start the colour with 0. When inserting its neightbours, change the color to 1. And alternate
//the colors when inserting neighbours. When an elements previously had another color but is inserted with another color, then the graph is not bipartite

bool isBipartite (vector<vector<int>>& graph, vector<int> &vis, int src){
        queue<int> que;
        que.push(src);
        
        int color=0;
        bool isCycle=false;
        
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int rvtx=que.front();
                que.pop();
                if(vis[rvtx]!=-1){
                    isCycle=true;
                    if(vis[rvtx]!=color){
                        return false;
                    }
                    continue;
                }
                vis[rvtx]=color;
                for(int v: graph[rvtx]){
                    if(vis[v]==-1)
                        que.push(v);
                }
            }
            color= (color+1)%2;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        bool res=true;
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                res=res &&  isBipartite(graph, vis, i);
            }
        }
        return res;
    }

//July 9

//https://leetcode.com/problems/rotting-oranges/
//Approach- First traverse the array and count the numbr of fresh oranges and push the rotten oranges in a queue. Then pop them one by one and rot their adjacent
//oranges and increase the time by one and decrease the fresh orange count. Pop the now rotten oranges into the queue again. When the number of fresh oranges is 
//zero, return the total time

int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<int> que;
        int time=1, freshOranges=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)
                    que.push(i*m+j);
                else if(grid[i][j]==1)
                    freshOranges++;
            }
        }
        if(freshOranges==0)
            return 0;
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int idx=que.front();
                que.pop();
                int r=idx/m;
                int c=idx%m;
                for(int d=0; d<dir.size(); d++){
                    int x=r+dir[d][0];
                    int y=c+dir[d][1];
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
                        freshOranges--;
                        grid[x][y]=2;
                        que.push(x*m+y);
                        if(freshOranges==0)
                            return time;
                    }
                }
            }
            time++;
        }
        return -1;
    }

//https://www.lintcode.com/problem/663/description (Walls and Gates)
//Approach- Traverse through the array and if a gate is encountered, it is pushed into the queue and if a room is encountered, increase the count of rooms. Then
//pop the elements in queue one by one and change the elements in the matrix with their distance from the gate, decrease the number of rooms and push the rooms
//with newly assigned distance again in the queue. The code is fully executed when the number of rooms remains zero.

void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        int n=rooms.size();
        int m=rooms[0].size();
        vector<vector<int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<int> que;
        int countRooms=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rooms[i][j]==0)
                que.push(i*m+j);
                else if(rooms[i][j]==2147483647)
                countRooms++;
            }
        } 
        int distance=1;
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int idx=que.front();
                que.pop();
                int r=idx/m;
                int c=idx%m;
                for(int d=0; d<dir.size(); d++){
                    int x=r+dir[d][0];
                    int y=c+dir[d][1];
                    if(x>=0 && y>=0 && x<n && y<m && rooms[x][y]==2147483647){
                        rooms[x][y]=distance;
                        countRooms--;
                        que.push(x*m+y);
                        if(countRooms==0)
                        return;
                    }
                }
            }
            distance++;
        }
    }

//July 19

//https://leetcode.com/problems/course-schedule/
//Approach- Use Kahn's algorithm to check dependency of courses on each other. If the courses can be completed, returnt true else return false

bool kahnsAlgo(int n, vector<vector<int>>& graph){
        vector<int> indegree(n,0);
        
        for(int i=0; i<n; i++){
            for(int e:graph[i]){
                indegree[e]++;
            }
        }
        
        queue<int> que;
        int count=0;
        
        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                que.push(i);
        }
        
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int rvtx=que.front();
                que.pop();
                count++;
                
                for(int e:graph[rvtx]){
                    if(--indegree[e]==0){
                        que.push(e);
                    }
                }
            }
        }
        return count==n;
    }
    
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>>graph(n);
        for(vector<int>ar:arr){
            graph[ar[0]].push_back(ar[1]);
        }
        return kahnsAlgo(n,graph);
    }

//https://leetcode.com/problems/course-schedule-ii/submissions/
//Approach- Use Kahn's algorithm to check course dependency. If the courses can be completed, i.e the course dependencies can be resolved, then return the order of
//course completion in an array else return an empty array

vector<int> kahnsAlgo(int n, vector<vector<int>> & graph){
        vector<int> indegree(n,0);
        vector<int> ans;
        queue<int> que;
        
        for(int i=0; i<n; i++){
            for(int e:graph[i])
                indegree[e]++;
        }
        
        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                que.push(i);
        }
        
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int rvtx=que.front();
                que.pop();
                
                ans.push_back(rvtx);
                
                for(int e:graph[rvtx]){
                    if(--indegree[e]==0)
                        que.push(e);
                }
            }
        }
        return ans;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<vector<int>> graph(n);
        for(vector<int> ar: arr){
            graph[ar[1]].push_back(ar[0]);
        }
        vector<int> ans=kahnsAlgo(n,graph);
        
        if(ans.size()!=n)
            return {};
        else return ans;
    }

//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//Approach- Check the indegree of the matrix elements. Indegree in this case will be the number of elements smaller than the element which are adjacent to the
//matrix cell. Then use Kahn's algorithm and update the number of times the elements are added in the queue i.e. the level. The number of level tells us the 
//length of the longest path in the matrix

int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> indegree(n, vector<int> (m,0));
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int d=0; d<dir.size(); d++){
                    int x=i+dir[d][0];
                    int y=j+dir[d][1];
                    
                    if(x>=0 && y>=0 && x<n && y<m && matrix[x][y]>matrix[i][j])
                        indegree[x][y]++;
                }
            }
        }
        
        queue<int> que;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(indegree[i][j]==0)
                    que.push(i*m+j);
            }
        }
        
        int level=0;
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                int idx=que.front();
                que.pop();
                int r=idx/m;
                int c=idx%m;
                for(int d=0; d<dir.size(); d++){
                    int x=r+dir[d][0];
                    int y=c+dir[d][1];
                    if(x>=0 && y>=0 && x<n && y<m && matrix[x][y]>matrix[r][c] &&--indegree[x][y]==0)
                        que.push(x*m+y);
                        
                }
            }
            level++;
        }
        return level;
    }

//August 1

//https://leetcode.com/problems/redundant-connection/
//Approach- Use union find algo to find the parent of the vertices, if two vertices don't have the same parent vertex, that is they don't belong to the same group, then make the
//assign parent f vertex 2 to vertex 1. And if the parents are already same, then that edge is the redundant connection

vector<int> par;
    int findPar(int u){
        return par[u]==-1?u:par[u]=findPar(par[u]);
    }    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1,-1);
        for(vector<int>& edge:edges){
            int p1=findPar(edge[0]);
            int p2=findPar(edge[1]);
            if(p1!=p2){
                par[p1]=p2;
            }
            else return edge;
        }
        return {};
    }

//https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
//Approach- Find the parent of the alphabet in such way that the smallest alphabet is made the parent, i.e., to create the smallest string lexicographically, make groups of 
//letters and the parent will be the smallest letter of them all. When we fill the answer string, then that smallest letter will represent the group and will be pushed in the
//string when any of the aplhabets in that particular group is encountered, thus making the lexicographically smallest string.

string smallestEquivalentString(string A, string B, string S)
{
    for (int i = 0; i < 26; i++)
        par.push_back(i);

    for (int i = 0; i < A.length(); i++)
    {
        int p1 = findPar(A[i] - 'a');
        int p2 = findPar(B[i] - 'a');

        par[p1] = min(p1, p2);
        par[p2] = min(p1, p2);
    }

    string ans = "";
    for (int i = 0; i < S.length(); i++)
    {
        ans += (char)(findPar(S[i] - 'a') + 'a');
    }

    return ans;
}

//https://leetcode.com/problems/similar-string-groups/
//Approach- We compare the given string groups one by one and if they have more than two letter jumbled up, then they don't belong to the same group, else they belong in the 
//same group. It can be so then one string belongs to the group because it matches with one string and not the other. Group up the strings and reduce the number of individual
//strings, when all the strings are grouped up, return the final counr of groups.

vector<int> par;
    int findPar(int u){
        return par[u]==u?u:par[u]=findPar(par[u]);
    }
    bool isSimilar(string& s1, string& s2){
        int count=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]&& ++count>2)
                return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int count=strs.size();
        int n=strs.size();
        par.resize(n);
        for(int i=0; i<n; i++) par[i]=i;
        for(int i=0; i<n; i++){We 
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i],strs[j])){
                    int p1=findPar(i);
                    int p2=findPar(j);
                    
                    if(p1!=p2){
                        par[p1]=p2;
                        count--;
                    }
                }
            }
        }
        return count;
    }

//https://leetcode.com/problems/number-of-islands-ii/
//Approach- Using union find algo, make the groups of matrix elements that are adjacent to each other and return the count of islands after each iteration

vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
{
    par.resize(m * n, -1);

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> grid(m, vector<int>(n, 0));
    int count = 0;
    vector<int> ans;
    for (vector<int> &pos : positions)
    {
        int i = pos[0];
        int j = pos[1];

        if (grid[i][j] != 1)
        {

            grid[i][j] = 1;
            count++;

            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1)
                {
                    int p1 = findPar(i * n + j);
                    int p2 = findPar(x * n + y);

                    if (p1 != p2)
                    {
                        count--;
                        par[p1] = p2;
                    }
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

//August 5

//https://leetcode.com/problems/optimize-water-distribution-in-a-village/
//Approach-

vector<int> par;
int minCostToSupplyWater_(int N, vector<vector<int>> &Edges)
{

    for (int i = 0; i <= N; i++)
    {
        par.push_back(i);
    }

    int cost = 0;

    for (vector<int> &edge : Edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        int p1 = findPar(u);
        int p2 = findPar(v);

        if (p1 != p2)
        {
            par[p1] = p2;
            cost += w;
        }
    }

    return cost;
}

int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }

    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    return minCostToSupplyWater_(n, pipes);
}

//https://leetcode.com/problems/number-of-islands/submissions/
//Approach

vector<int> par;
    int findPar(int u){
        return par[u] == u ? u : par[u] = findPar(par[u]);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n*m; i++){
            par.push_back(i);
        }
        int count=0;
        vector<vector<int>> dir{{1,0},{0,1}};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    int p1=findPar(i*m+j);
                    for(int d=0; d<2; d++){
                        int x=i+dir[d][0];
                        int y=j+dir[d][1];
                        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]=='1'){
                            int p2=findPar(x*m+y);
                            if(p1!=p2){
                                par[p2]=p1;
                                count--;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }

//https://leetcode.com/problems/max-area-of-island/submissions/
//Approach-

vector<int> par;
    int findPar(int u){
        return par[u]==u?u: par[u]=findPar(par[u]);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n*m; i++){
            par.push_back(i);
        }
        vector<int> componentSize(n*m, 1);
        int maxArea = 0;
        vector<vector<int>> dir{{1, 0}, {0, 1}};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int p1=findPar(i*m+j);
                    for(int d=0; d<2; d++){
                        int x=i+dir[d][0];
                        int y=j+dir[d][1];
                        if(x>=0 && y>=0 && x<n && y<m &&grid[x][y]==1){
                            int p2=findPar(x*m+y);
                            if(p1!=p2){
                                par[p2]=p1;
                                componentSize[p1] += componentSize[p2];
                            }
                        }
                        maxArea = max(maxArea, componentSize[p1]);
                    }
                }
                else
                    componentSize[i * m + j] = 0;
            }
        }
        return maxArea;
    }

