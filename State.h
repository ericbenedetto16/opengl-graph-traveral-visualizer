#pragma once

#include<vector>

class Camera;
class Graph;
class GraphIterator;

// General State
std::vector<Graph*> graphs;
Camera* camera = nullptr;

// Event State
Graph* currGraph = nullptr;
GraphIterator* it = nullptr;
int simClock = 1;
bool runningAnimation = false;

// Menu State
static int window;
static int main_menu;
static int graph_menu;
static bool dfs = false;
static bool bfs = false;