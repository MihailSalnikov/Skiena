// DFS with colors and timer;
// Mikhail Salnikov just for fun

#include <iostream>
#include <vector>


std::vector<std::vector<int>> g;
std::vector<int> colors;
int n;
std::vector<int> timer_in, timer_out;
int dfs_timer = 0;

void dfs(int s) {
    timer_in[s] = dfs_timer;
    colors[s] = 1;

    for (std::vector<int>::iterator l=g[s].begin(); l != g[s].end(); ++l) {
        if (colors[*l] == 0) {
            dfs(*l);
        }
    }
    colors[s] = 2;
    timer_out[s] = dfs_timer;
    dfs_timer++;
}

void print_graph(std::vector<std::vector<int>> g) {
    std::cout << "Graph:\n";
    for (std::vector<std::vector<int>>::iterator i=g.begin(); i != g.end(); ++i) {
        int ridx = std::distance(g.begin(), i); // row index
        std::cout << ridx << " (Color: " << colors[ridx] << "; Timer in: " << timer_in[ridx] << "; Timer out: " << timer_out[ridx] << ") |";
        for (std::vector<int>::iterator r=(*i).begin(); r != (*i).end(); ++r) {
            std::cout << *r << " ";
        }
        std::cout << "\n";
    }
}


int main() {
    std::cout << "Enter N - numbers of nodes;\n";
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        std::vector<int> r;
        g.push_back(r);
        timer_in.push_back(0);
        timer_out.push_back(0);
    }

    for (size_t i = 0; i < n; i++)
    {   
        std::cout << "Enter number of adjusted nodes for " << i << " node\n";
        int adjusted_n;
        std::cin >> adjusted_n;
        for (size_t j = 0; j < adjusted_n; j++)
        {
            int adjusted_node_index;
            std::cin >> adjusted_node_index;
            g[i].push_back(adjusted_node_index);
        }
    }

    for (size_t _i = 0; _i < n; _i++) {
        colors.push_back(0);
    }

    print_graph(g);
    dfs(0);
    print_graph(g);
    
    
    return 0;
}
