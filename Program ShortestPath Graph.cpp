// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program ShortestPath Graph

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#define INF INT_MAX

using namespace std;

void dijkstra(map<string, vector<pair<string, int>>> &graph, const string &src)
{
    map<string, int> dist;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    for (auto &entry : graph)
    {
        dist[entry.first] = INF;
    }

    dist[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        string u = pq.top().second;
        pq.pop();

        for (auto &neighbor : graph[u])
        {
            string v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "===========================================" << endl;
    cout << "Jarak Terdekat dari " << src << " ke setiap daerah: " << endl;
    cout << "===========================================" << endl;
    for (auto &entry : dist)
    {
        cout << entry.first << ": " << entry.second << " Km" << endl;
    }
    cout << "===========================================" << endl;
}

int main()
{

    map<string, vector<pair<string, int>>> graph;

    graph["Rumah"] = {{"BKT", 2}, {"Bojong", 4}};
    graph["Bojong"] = {{"Rumah", 4}, {"BKT", 6}, {"Harapan Indah", 5}};
    graph["BKT"] = {{"Rumah", 2}, {"Bojong", 6}, {"Esa Unggul Bekasi", 3}};
    graph["Harapan Indah"] = {{"Bojong", 5}, {"Esa Unggul Bekasi", 4}};
    graph["Esa Unggul Bekasi"] = {{"BKT", 3}, {"Harapan Indah", 4}};

    string source = "Rumah";

    dijkstra(graph, source);

    return 0;
}