#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Edge{
    int to, int from;
    T cost;
    Edge(int to) : to(to) {}
    Edge(int to, T cost) : to(to), cost(cost) {}
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template<typename T>
using Graph = vector<vector<Edge<T>>>;