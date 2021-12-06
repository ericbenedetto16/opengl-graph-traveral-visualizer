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
		GLfloat mat[4];

		if (this->visited && this->valid) {
			mat[0] = 0; mat[1] = 200.0f / 255.0f; mat[2] = 80.0f / 255.0f; mat[3] = 1.0;
		}
		else if(!this->valid && this->visited) {
			mat[0] = 1; mat[1] = 0; mat[2] = 0; mat[3] = 1.0;

		}
		else {
			mat[0] = 200.0f / 255.0f ; mat[1] = 0; mat[2] = 200.0f / 255.0f; mat[3] = 1.0;
		}
		
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
		glLineWidth(5);
		glBegin(GL_LINES);
		
		glVertex3f(this->from->getX(), this->from->getY(), this->from->getZ());
		glVertex3f(this->to->getX(), this->to->getY(), this->to->getZ());
		
		glEnd();
		glPopMatrix();
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