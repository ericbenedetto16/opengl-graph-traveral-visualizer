#pragma once

#include <string>
#include "GraphNode.h"

class GraphEdge {
private:
	GraphNode* to;
	GraphNode* from;
	int weight;
	bool visited;
	bool valid;

public:
	GraphEdge(GraphNode* to, GraphNode* from, int weight) {
		this->to = to;
		this->from = from;
		this->weight = weight;
		this->visited = false;
		this->valid = false;
	}

	GraphEdge(GraphNode* to, GraphNode* from) {
		this->to = to;
		this->from = from;
		this->weight = NULL;
		this->visited = false;
		this->valid = false;
	}

	GraphNode* getTo() const {
		return this->to;
	}

	GraphNode* getFrom() const {
		return this->from;
	}

	int getWeight() const {
		return this->weight;
	}

	void markVisited() {
		this->visited = true;
	}

	void markValid() {
		this->valid = true;
	}

	void markInvalid() {
		if(this->valid != true) this->valid = false;
	}

	void reset() {
		this->visited = false;
		this->valid = false;
	}

	void render() {
		if (this->visited && this->valid) {
			glColor3ub(0, 200, 80);
		}
		else if(!this->valid && this->visited) {
			glColor3ub(255, 0, 0);
		}
		else {
			glColor3ub(200, 0, 200);
		}
		
		glLineWidth(5);
		glBegin(GL_LINES);
		
		glVertex3f(this->from->getX(), this->from->getY(), this->from->getZ());
		glVertex3f(this->to->getX(), this->to->getY(), this->to->getZ());
		
		glEnd();
	}
};

struct EdgeKeyEquals {
	bool operator() (const GraphEdge* a, const GraphEdge* b) const {
		return a->getFrom() == b->getFrom() && a->getTo() == b->getTo();
	}
};

struct EdgeHash {
	size_t operator() (const GraphEdge* a) const {
		std::hash<std::string> hasher;
		return hasher(std::to_string(a->getFrom()->getValue()) + "," + std::to_string(a->getTo()->getValue()));
	}
};