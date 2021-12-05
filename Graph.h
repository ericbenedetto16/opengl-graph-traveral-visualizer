#pragma once

#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include "GraphEdge.h"
#include "GraphNode.h"

class Graph {
private:
	std::unordered_map<int, GraphNode*> nodes;
	std::unordered_set<GraphEdge*, EdgeHash, EdgeKeyEquals> edges;
	std::vector<std::tuple<float, float, float>> coords;
	bool weighted;

public:
	// Weighted
	Graph(std::vector<std::tuple<int, int, int>> edgeList, std::vector<std::tuple<float, float, float>> coords) {
		this->weighted = true;
		this->coords = coords;

		for (std::tuple<int, int, int>& edge : edgeList) {
			int from = std::get<0>(edge);
			int to = std::get<1>(edge);
			int weight = std::get<2>(edge);

			GraphNode* toNode;
			GraphNode* fromNode;
			GraphEdge* graphEdge;

			// Add Nodes to Graph
			if (this->nodes.count(to) > 0) {
				toNode = this->nodes.at(to);
			}
			else {
				toNode = new GraphNode(to);
				this->nodes.insert(std::pair<int, GraphNode*>(to, toNode));
			}

			if(this->nodes.count(from) > 0) {
				fromNode = this->nodes.at(from);
			}
			else {
				fromNode = new GraphNode(from);
				this->nodes.insert(std::pair<int, GraphNode*>(from, fromNode));
			}
			
			// Add Edge to Graph & Neighbor to fromNode
			graphEdge = new GraphEdge(toNode, fromNode, weight);
			if (!this->edges.count(graphEdge) > 0) {
				this->edges.insert(graphEdge);
				fromNode->addNeighbor(graphEdge);
			}
		}
	}

	// Un-Weighted
	Graph(std::vector<std::tuple<int, int>> edgeList, std::vector<std::tuple<float, float, float>> coords) {
		this->weighted = false;
		this->coords = coords;

		for (std::tuple<int, int>& edge : edgeList) {
			int from = std::get<0>(edge);
			int to = std::get<1>(edge);

			GraphNode* toNode;
			GraphNode* fromNode;
			GraphEdge* graphEdge;

			// Add Nodes to Graph
			if (this->nodes.count(to) > 0) {
				toNode = this->nodes.at(to);
			}
			else {
				toNode = new GraphNode(to);
				this->nodes.insert(std::pair<int, GraphNode*>(to, toNode));
			}

			if (this->nodes.count(from) > 0) {
				fromNode = this->nodes.at(from);
			}
			else {
				fromNode = new GraphNode(from);
				this->nodes.insert(std::pair<int, GraphNode*>(from, fromNode));
			}

			// Add Edge to Graph & Neighbor to fromNode
			graphEdge = new GraphEdge(toNode, fromNode);
			if (!this->edges.count(graphEdge) > 0) {
				this->edges.insert(graphEdge);
				fromNode->addNeighbor(graphEdge);
			}
		}
	}

	void render() {
		assert(this->coords.size() == this->nodes.size());

		for (int i = 0; i < this->coords.size(); i++) {
			GraphNode* curr = this->nodes.at(i);

			curr->registerCoords(std::get<0>(this->coords.at(i)), std::get<1>(this->coords.at(i)), std::get<2>(this->coords.at(i)));
			curr->render();
		}

		for (GraphEdge* edge : this->edges) {
			edge->render();
		}
	}

	std::unordered_map<int, GraphNode*> getNodes() {
		return this->nodes;
	}

	void refresh() {
		for (auto node : this->nodes) {
			node.second->reset();
		}

		for (auto edge : this->edges) {
			edge->reset();
		}
	}
};

class GraphIterator {
public:
	GraphIterator() {}
	virtual bool hasNext() = 0;
	virtual void next() = 0;
};

class GraphDFSIterator : public GraphIterator {
private:
	Graph* graph;
	std::stack<GraphEdge*> dfsStack;
	std::set<int> visited;

public:
	GraphDFSIterator(Graph* graph, int src) {
		this->graph = graph;
		this->dfsStack.push(new GraphEdge(this->graph->getNodes().at(src), this->graph->getNodes().at(src)));
	}
	
	bool hasNext() {
		return !this->dfsStack.empty();
	}

	void next() {
		GraphEdge* edge = this->dfsStack.top();
		GraphNode* curr = edge->getTo();
		this->dfsStack.pop();

		edge->markVisited();

		if (visited.count(curr->getValue()) < 1) {
			edge->markValid();
			curr->markVisited();
			this->visited.insert(curr->getValue());
		}
		else {
			edge->markInvalid();
		}

		std::vector<GraphEdge*> neighbors = curr->getNeighbors();
		for (auto neighbor : neighbors) {
			if (this->visited.count(neighbor->getTo()->getValue()) < 1) {
				this->dfsStack.push(neighbor);
			}
			else {
				neighbor->markVisited();
				neighbor->markInvalid();
			}
		}
	}
};

class GraphBFSIterator : public GraphIterator {
private:
	Graph* graph;
	std::queue<GraphEdge*> bfsQueue;
	std::set<int> visited;
public:
	GraphBFSIterator(Graph* graph, int src) {
		this->graph = graph;
		this->bfsQueue.push(new GraphEdge(this->graph->getNodes().at(src), this->graph->getNodes().at(src)));
	}

	bool hasNext() {
		return !this->bfsQueue.empty();
	}

	void next() {
		GraphEdge* edge = this->bfsQueue.front();
		GraphNode* curr = edge->getTo();
		this->bfsQueue.pop();

		edge->markVisited();

		if (this->visited.count(curr->getValue()) < 1) {
			edge->markValid();
			curr->markVisited();
			this->visited.insert(curr->getValue());
		}
		else {
			edge->markInvalid();
		}

		std::vector<GraphEdge*> neighbors = curr->getNeighbors();
		for (GraphEdge* neighbor : neighbors) {
			if (this->visited.count(neighbor->getTo()->getValue()) < 1) {
				this->bfsQueue.push(neighbor);
			}
			else {
				neighbor->markVisited();
				neighbor->markInvalid();
			}
		}
	}
};