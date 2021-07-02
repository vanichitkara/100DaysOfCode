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
//Approach- if source is equal to destination, return true since they hav a path between them. Mark the source as visited and check if the neighbouring vertex of
//source have a path to destination, if they have a path, then source has a path to destination.

bool hasPath(vector<Edge> graph, int src, int dest, vector<bool> visited){
          if(src==dest) 
          return true;
          visited[src]=true;
          bool res=false;
          for(Edge e: graph[src]){
              if(!visited[e.nbr]){
                  boolean nbrHasPath = hasPath(graph, e.nbr, dest, visited);
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
