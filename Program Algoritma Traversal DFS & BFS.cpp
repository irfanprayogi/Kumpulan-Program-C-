//Created Program By 20220801379_Irfan Prayogi
//Teknik Informatika
//Program Algoritma Traversal DFS & BFS

#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Graph
{
    int vertex;
    list<char> *adj;
} g;

void addEdge(Graph &g, char v, char w)
{
    g.adj[v - 'A'].push_back(w);
}

void DFSUtil(Graph &g, char v, bool visited[])
{
    visited[v - 'A'] = true;
    cout << v << " ";

    list<char>::iterator i;
    for (i = g.adj[v - 'A'].begin(); i != g.adj[v - 'A'].end(); ++i)
        if (!visited[*i - 'A'])
            DFSUtil(g, *i, visited);
}

void DFS(Graph &g, char v)
{
    bool *visited = new bool[g.vertex];
    for (int i = 0; i < g.vertex; i++)
        visited[i] = false;

    DFSUtil(g, v, visited);
}

void BFS(Graph &g, char v)
{
    bool *visited = new bool[g.vertex];
    for (int i = 0; i < g.vertex; i++)
        visited[i] = false;

    queue<char> queue;
    visited[v - 'A'] = true;
    queue.push(v);

    while (!queue.empty())
    {
        v = queue.front();
        cout << v << " ";
        queue.pop();

        list<char>::iterator i;
        for (i = g.adj[v - 'A'].begin(); i != g.adj[v - 'A'].end(); ++i)
        {
            if (!visited[*i - 'A'])
            {
                visited[*i - 'A'] = true;
                queue.push(*i);
            }
        }
    }
}

int main()
{

    char ulang;

    do
    {

        int simpul;

        cout << "\n\n";
        cout << "=====================================" << endl;
        cout << "PROGRAM ALGORITMA TRAVERSAL DFS & BFS" << endl;
        cout << "=====================================" << endl;
        cout << "\nMasukkan jumlah simpul: ";
        cin >> simpul;

        Graph g;
        g.vertex = simpul;
        g.adj = new list<char>[simpul];

        // Hitung jumlah edge
        int E = simpul - 1;
        cout << "*Note: Gunakan huruf besar 'A' - 'Z'" << endl;
        cout << "Masukkan edge (format: simpul1 simpul2):\n";
        for (char i = 'A'; i < 'A' + E; i++)
        {
            char v, w;
            cin >> v >> w;
            addEdge(g, v, w);
        }

        // Inputan simpul awal
        char simpulAwal;
        cout << "Masukkan simpul awal: ";
        cin >> simpulAwal;

        cout << "========================================" << endl;
        cout << "Traversal Depth-First Search (DFS): ";
        DFS(g, simpulAwal);
        cout << endl;
        cout << "Traversal Breadth-First Search (BFS): ";
        BFS(g, simpulAwal);
        cout << "\n========================================" << endl;

        cout << "\nApakah ingin mengulang lagi? (Y/N): ";
        cin >> ulang;

    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}