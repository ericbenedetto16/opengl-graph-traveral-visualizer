#pragma once

class GraphEdge;

class GraphNode {
private:
	int val;
	bool visited;
	float x, y, z;
	std::vector<GraphEdge*> neighbors;
public:
	GraphNode(int val) {
		this->val = val;
		this->visited = false;
		this->x = NULL;
		this->y = NULL;
		this->z = NULL;
	}

	void addNeighbor(GraphEdge* neighbor) {
		this->neighbors.push_back(neighbor);
	}

	std::vector<GraphEdge*> getNeighbors() {
		return this->neighbors;
	}

	void markVisited() {
		this->visited = true;
	}

	bool isVisited() {
		return this->visited;
	}

	void reset() {
		this->visited = false;
	}

	void registerCoords(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float getX() {
		return this->x;
	}

	float getY() {
		return this->y;
	}

	float getZ() {
		return this->z;
	}

	void render() {
		if (this->visited) {
			glColor3ub(0, 255, 0);
		}
		else {
			glColor3ub(0, 200, 200);
		}
		
		glPushMatrix();
		glTranslatef(this->x, this->y, this->z);
		glutSolidSphere(2.0f, 40, 40);
		glPopMatrix();
	}

	int getValue() const {
		return this->val;
	}
};

struct NodeKeyEquals {
	inline bool operator() (const GraphNode* a, const GraphNode* b) const {
		return a->getValue() == b->getValue();
	}
};

struct NodeHash {
	int operator() (const GraphNode* a) const {
		return a->getValue();
	}
};