#pragma once

class DFSIterator {
private:
	Graph* graph;
	std::stack<GraphNode*> dfsStack;
	std::set<int> visited;

public:
	DFSIterator(Graph* graph) {
		this->graph = graph;
	}

	bool hasNext() {
		return !dfsStack.empty();
	}

	void next() {
		GraphNode* curr = dfsStack.top();
		dfsStack.pop();

		if (visited.count(curr->getValue()) < 1) {
			std::cout << curr->getValue() << std::endl;
			curr->markVisited();
			this->graph->render();
			visited.insert(curr->getValue());
		}

		std::vector<GraphEdge*> neighbors = curr->getNeighbors();
		for (auto neighbor : neighbors) {
			if (visited.count(neighbor->getTo()->getValue()) < 1) {
				//std::cout << neighbor->getTo()->getValue() << " seen " << visited.count(neighbor->getTo()->getValue()) << " times" << std::endl;
				dfsStack.push(neighbor->getTo());
			}
		}
	}
};