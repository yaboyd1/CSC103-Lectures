//Geek for geeks
// Program for transitive closure using Floyd Warshall Algorithm
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Number of vertices in the graph
#define V 4

#define a 1
#define b 2
#define c 3
#define d 4

vector<vector<int> > A = {
 //~ {1,2},
 //~ {2,1},
 //~ {3,1},
 //~ {3,2},
 //~ {4,2},
 //~ {4,4}
};

void printVertex(vector<vector<int> > R = A, bool alph = false) {
  if (!alph) {
    for (size_t i = 0; i < R.size(); i++) {
        for (size_t j = 0; j < R[0].size(); j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
  } else {
    for (size_t i = 0; i < R.size(); i++) {
        for (size_t j = 0; j < R[0].size(); j++) {
            if (R[i][j] == 1) cout << 'a' << " ";
            else if (R[i][j] == 2) cout << 'b' << " ";
            else if (R[i][j] == 3) cout << 'c' << " ";
            else if (R[i][j] == 4) cout << 'd' << " ";
        }
        cout << endl;
    }
  }
}

bool isEqual(int first[][V], int second[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (first[i][j] != second[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void isReflective(int g[][V]) {
    if (g[0][0] == 1 && g[1][1] == 1 && g[2][2] == 1 && g[3][3] == 1)
        cout << "Reflexive!" << endl;
    else if (g[0][0] == 0 && g[1][1] == 0 && g[2][2] == 0 && g[3][3] == 0)
        cout << "Irreflexive!" << endl;
    else
        cout << "Neither reflexive or irreflexive" << endl;
}

void isSym(int g[][V], bool alph = false) {

  int r[V][V];
  bool sym = true;
  vector<vector<int> > list;
  vector<int> coord = {0,0};

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      r[i][j] = g[i][j];
    }
  }

  for (int i = 0; i < V; i++) {
    for (int j = i; j < V; j++) {
      if (r[i][j] != r[j][i]) {
        sym = false;
        if (r[i][j] == 1) {
          coord[0] = j + 1;
          coord[1] = i + 1;
          list.push_back(coord);
        } else {
          coord[0] = i + 1;
          coord[1] = j + 1;
          list.push_back(coord);
        }
      }
    }
  }

  if (!sym) {
    cout << "Sym Closure: " << endl;
    printVertex(list, alph);
  } else {
    cout << "IDK about Sym" << endl;
  }

}

void userPrompt() {
  string input;
  cin >> input;
  size_t j = 0;
  vector<int> coord = {0,0};
  bool ch = false;
  for (size_t i = 0; i < input.length(); i++) {
    if (input[i] == '1' || input[i] == 'a') {
      coord[j++] = 1;
      ch = true;
    }
    else if (input[i] == '2' || input[i] == 'b') {
      coord[j++] = 2;
      ch = true;
    }
    else if (input[i] == '3' || input[i] == 'c') {
      coord[j++] = 3;
      ch = true;
    }
    else if (input[i] == '4' || input[i] == 'd') {
      coord[j++] = 4;
      ch = true;
    }
    if (ch) {
      if(j%2==0) {
        A.push_back(coord);
        j = j % 2;
      }
      ch = false;
    }

  }
}//1221314244

// A function to print the solution matrix
void printSolution(int reach[][V]);
void printRelation(int reach[][V], bool alph = false);

// Prints transitive closure of graph[][] using Floyd Warshall algorithm
void transitiveClosure(int graph[][V], bool alph = false)
{
    /* reach[][] will be the output matrix that will finally have the
       shortest distances between every pair of vertices */
    int reach[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    for (size_t x = 0; x < A.size(); x++) {
        reach[A[x][0]-1][A[x][1]-1] = 1; //Output
        graph[A[x][0]-1][A[x][1]-1] = 1; //Initial
    }

    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have reachability values for
           all pairs of vertices such that the reachability values
           consider only the vertices in set {0, 1, 2, .. k-1} as
           intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the
            set of intermediate vertices and the set becomes {0, 1, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on a path from i to j,
                // then make sure that the value of reach[i][j] is 1
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the shortest distance matrix
    //printSolution(reach);
    if (!isEqual(reach, graph))
        printRelation(reach, alph);
    else
        cout << "Transitive!" << endl;
}

/* A utility function to print solution */
void printSolution(int reach[][V])
{
    cout << "Output (Graph): " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf ("%d ", reach[i][j]);
        printf("\n");
    }
}

void printRelation(int reach[][V], bool alph) {
  if (!alph) {
    cout << "Transitive Closure: " << endl;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (reach[i][j] == 1) {
          cout << i+1 << " " << j+1 << endl;
        }
      }
    }
  }
  else {
    cout << "Transitive Closure: " << endl;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (reach[i][j] == 1) {
          cout << (char)(i+'a') << " " << (char)(j+'a') << endl;
        }
      }
    }
  }
}

// driver program to test above function
int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    bool alph = false;

    userPrompt();
    cout << "Input: " << endl;

    printVertex(A, alph);

    transitiveClosure(graph, alph);
    //isReflective(graph);
    //isSym(graph);

    return 0;
}