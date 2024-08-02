#include <queue>
bool found_util(  int  curr , vector<vector<int>> & adjList  ,  vector<bool> & visited  , int & target   )  
{
   visited[curr]  = true ;
   for ( int neighbour : adjList[curr] )

   {  
      if( neighbour == target )  return true ; 
      if( !visited[neighbour] )

      {   
          bool ans = found_util( neighbour, adjList, visited, target)   ;  

          if( ans == true)  return ans ;         

      }
   } 
   return false ;

}
int detectCycleInDirectedGraph (int n, vector < pair < int, int >> & edges ) 
{
    vector<vector<int>> adjList(  n + 1  )  ;  
    for ( int i = 0 ; i < edges.size() ; i++ )

    {          

        int u = edges[i].first  , v = edges[i].second  ;

        adjList[u].push_back(v)  ;   
    } 
    vector<bool> visited( n + 1  , false )  ; 

 

    for ( int i = 1 ; i <= n ; i++ )

    {        

        if( visited[i] ) continue ;  

 

        queue<int> Q ;

        Q.push( i ) ;

        visited[i] = true ;
        while ( !Q.empty() )

        {

            int node = Q.front()     ; 

            Q.pop() ;

            for ( int neighbour : adjList[node] )

            {

                if( !visited[neighbour] )

                {

                  Q.push(neighbour)   ; 

                 visited[neighbour] = true ;

                }

           else

                {   

             vector<bool> New_visited(  n+1 , false  )  ;  

            bool found = found_util( neighbour , adjList  ,   New_visited  , node   )  ;

         if( found) return true ; 

 

                }
            }
        }

    }
return false ; 

}