
// @snippet<sh19910711/contest:headers.cpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

// @snippet<sh19910711/contest:table/keymap.cpp>
namespace table {
    template <class Key, class Data> class KeyMappingTable {
    public:
        std::vector<Data> memory;
        void init( Key& limit ) {
            memory.resize(mapping(limit));
        }
        void fill( Data& value ) {
            std::fill( memory.begin(), memory.end(), value );
        }
        virtual int mapping( Key& key ) = 0;
        Data& operator []( Key& key ) {
            return memory[mapping(key)];
        }
        Data& operator =( Data& right ) {
            memory = right.memory;
        }
    };
}


class Edge {
public:
    int from;
    int to;
    int weight;
    Edge( int from, int to, int weight )
        : from(from), to(to), weight(weight) {}
    friend std::ostream& operator << ( std::ostream& os, Edge& edge ) {
        return os << "{" << edge.from << "-" << edge.to << ": " << edge.weight << "}";
    }
};

const int DEFAULT_WEIGHT = std::numeric_limits<int>().max() >> 1;
class Graph {
public:
    typedef std::vector<int>::iterator Iterator;
    typedef std::vector<int> Edges;
    typedef std::vector<Edges> EdgesSet;
    typedef std::vector<int> Weights;
    typedef std::vector<Weights> WeightsSet;
    int n;
    EdgesSet edges;
    WeightsSet edge_weights;
    Weights node_weights;
    Graph() {
        edges.clear();
    }
    Graph( int n ) {
        init(n);
    }
    void init( int n_ ) {
        n = n_;
        edges = EdgesSet(n);
        edge_weights = WeightsSet( n, Weights( n, DEFAULT_WEIGHT ) );
        node_weights = Weights( n, 0 );
    }
    void addEdge( Edge& e ) {
        edges[e.from].push_back(e.to);
        edges[e.to].push_back(e.from);
        edge_weights[e.from][e.to] = edge_weights[e.to][e.from] = e.weight;
    }
    int getCost( int u ) {
        return node_weights[u];
    }
    void setCost( int u, int weight ) {
        node_weights[u] = weight;
    }
    int getCost( int u, int v ) {
        return edge_weights[u][v];
    }
    Iterator begin( int u ) {
        return edges[u].begin();
    }
    Iterator end( int u ) {
        return edges[u].end();
    }
};

template <class NODE, class DIST_TYPE, class VISITED_TYPE>
class BellmanFord {
public:
    Graph* G;
    DIST_TYPE dist;
    VISITED_TYPE visited;
    VISITED_TYPE next_visited;
    BellmanFord() {
    }
    virtual void init( Graph* G ) {
        this->G = G;
    }
    void build( NODE start_node ) {
        dist[start_node] = 0;
        visited[start_node] = true;
        while ( true ) {
            if ( ! distribute() )
                break;
            visited = next_visited;
        }
    }
    virtual bool distribute() {
        return false;
    }
};

// @snippet<sh19910711/contest:solution/interface.cpp>
namespace solution {
    class ISolution {
    public:
        virtual void init() {};
        virtual bool input() { return false; };
        virtual void output() {};
        virtual int run() = 0;
    };
}

// @snippet<sh19910711/contest:solution/solution.cpp>
namespace solution {
    using namespace std;
    
    typedef vector<int> VI;
    
    class Node {
    public:
        int id;
        int state;
        Node( int id, int state ): id(id), state(state) {
        }
        friend ostream& operator << ( ostream& os, Node& node ) {
            os << "(" << node.id << ", " << node.state;
            return os;
        }
    };
    template <class T>
        class BF_TABLE: public table::KeyMappingTable<Node, T> {
        public:
            int n;
            int m;
            void init( int n_, int m_, T value ) {
                n = n_;
                m = m_;
                Node limit( n, m );
                table::KeyMappingTable<Node, T>::init( limit );
                table::KeyMappingTable<Node, T>::fill( value );
            }
            int mapping( Node& node ) {
                return node.id * m + node.state;
            }
        };
    class BELLMAN_FORD: public BellmanFord< Node, BF_TABLE<int>, BF_TABLE<char> > {
    public:
        int n;
        int m;
        void init( Graph* G_, int n_, int m_ ) {
            G = G_;
            n = n_;
            m = m_;
            dist.init( n, 1 << m, DEFAULT_WEIGHT );
            visited.init( n, 1 << m, false );
        }
        bool distribute() {
            bool updated = false;
            next_visited.init( n, 1 << m, false );
            for ( int i = 0; i < n; ++ i ) {
                for ( int j = 0; j < ( 1 << m ); ++ j ) {
                    Node node( i, j );
                    if ( ! visited[node] )
                        continue;
                    for ( VI::iterator it_i = G->begin(i); it_i != G->end(i); ++ it_i ) {
                        updated = updated | update( node, *it_i );
                    }
                }
            }
            return updated;
        }
        bool update( Node& node, int to ) {
            if ( m <= to ) {
                int new_dist = dist[node] + G->getCost( node.id, to );
                Node new_node( to, node.state );
                if ( new_dist < dist[new_node] ) {
                    dist[new_node] = new_dist;
                    next_visited[new_node] = true;
                    return true;
                }
            } else {
                int bit_to = 1 << to;
                if ( node.state & bit_to )
                    return false;
                int new_dist = dist[node] + G->getCost( node.id, to ) + G->getCost( to );
                int new_state = node.state | bit_to;
                Node new_node( to, new_state );
                if ( new_dist < dist[new_node] ) {
                    dist[new_node] = new_dist;
                    next_visited[new_node] = true;
                    return true;
                }
            }
            return false;
        }
    };
    
    typedef ostringstream OSS;
    template <class T>
        string to_string( T s ) {
            OSS oss;
            oss << s;
            return oss.str();
        }
    
    const int CAKE_SHOPS = 7;
    const int EDGES = 301;
    
    int m, n, k, d;
    int calory[CAKE_SHOPS];
    string A[EDGES];
    string B[EDGES];
    int C[EDGES];
    Graph G;
    BELLMAN_FORD BF;
    map <string, int> T;
    int TC;
    
    class Solution: public ISolution {
    public:
        void init() {
            T.clear();
            TC = 0;
        }
        void add_node( string s ) {
            if ( T.count(s) )
                return;
            T[s] = TC ++;
        }
        int find_node( string s ) {
            return T[s];
        }
        bool input() {
            cin >> m >> n >> k >> d;
            if ( m == 0 && n == 0 && k == 0 && d == 0 )
                return false;
            for ( int i = 0; i < m; ++ i )
                cin >> calory[i];
            for ( int i = 0; i < d; ++ i ) {
                cin >> A[i] >> B[i] >> C[i];
            }
            return true;
        } 
        int solve() {
            for ( int i = 0; i < m; ++ i )
                add_node( "C"+to_string(i+1) );
            for ( int i = 0; i < n; ++ i )
                add_node( "L"+to_string(i+1) );
            add_node("H");
            add_node("D");
            
            G.init(TC);
            for ( int i = 0; i < m; ++ i ) {
                G.setCost( i, -calory[i] );
            }
            for ( int i = 0; i < d; ++ i ) {
                Edge edge( find_node(A[i]), find_node(B[i]), C[i] * k );
                G.addEdge( edge );
            }
            
            int start = find_node("H");
            int goal = find_node("D");
            Node start_node( start, 0 );
            
            BF.init( &G, TC, m );
            BF.build( start_node );
            
            int res = numeric_limits<int>().max();
            for ( int i = 0; i < ( 1 << m ); ++ i ) {
                Node node( goal, i );
                res = min( res, BF.dist[node] );
            }
            return res;
        }
        void output( int result ) {
            cout << result << endl;
        }
        int run() {
            while ( init(), input() ) {
                output(solve());
            }
            return 0;
        }
    };
}

// @snippet<sh19910711/contest:main.cpp>

int main() {
    return solution::Solution().run();
}