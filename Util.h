#pragma once

#include "Camera.h"
#include "Graph.h"

extern std::vector<Graph*> graphs;
extern bool runningAnimation;
extern Camera* camera;
extern Graph* currGraph;

void initGraphs() {
	std::vector<std::tuple<int, int, int>> edgeList;
	std::vector<std::tuple<float, float, float>> coords;

	// Graph 1
	edgeList.push_back(std::make_tuple(0, 1, 8));
	edgeList.push_back(std::make_tuple(0, 2, 4));
	edgeList.push_back(std::make_tuple(1, 2, 12));
	edgeList.push_back(std::make_tuple(2, 3, 9));
	edgeList.push_back(std::make_tuple(2, 4, 4));
	edgeList.push_back(std::make_tuple(2, 5, 3));
	edgeList.push_back(std::make_tuple(3, 5, 5));
	edgeList.push_back(std::make_tuple(4, 3, 14));

	coords.push_back(std::make_tuple(-50.0f, 1.9f, -50.0f)); // 0
	coords.push_back(std::make_tuple(-30.0f, 1.9f, -50.0f)); // 1
	coords.push_back(std::make_tuple(-30.0f, 1.9f, -20.0f)); // 2
	coords.push_back(std::make_tuple(0.0f, 1.9f, -40.0f)); // 3
	coords.push_back(std::make_tuple(0.0f, 1.9f, -10.0f)); // 4
	coords.push_back(std::make_tuple(30.0f, 1.9f, -30.0f)); // 5

	graphs.push_back(new Graph(edgeList, coords));
	edgeList.clear();
	coords.clear();

	// Graph 2
	edgeList.push_back(std::make_tuple(0, 1, 8));
	edgeList.push_back(std::make_tuple(0, 2, 4));
	edgeList.push_back(std::make_tuple(1, 2, 12));
	edgeList.push_back(std::make_tuple(1, 3, 12));
	edgeList.push_back(std::make_tuple(1, 4, 12));
	edgeList.push_back(std::make_tuple(2, 3, 12));
	edgeList.push_back(std::make_tuple(2, 5, 12));
	edgeList.push_back(std::make_tuple(3, 4, 12));
	edgeList.push_back(std::make_tuple(3, 5, 12));
	edgeList.push_back(std::make_tuple(4, 5, 12));

	coords.push_back(std::make_tuple(-20.0f, 1.9f, 0.0f)); // 0
	coords.push_back(std::make_tuple(-10.0f, 1.9f, -20.0f)); // 1
	coords.push_back(std::make_tuple(0.0f, 1.9f, 0.0f)); // 2
	coords.push_back(std::make_tuple(10.0f, 1.9f, -20.0f)); // 3
	coords.push_back(std::make_tuple(0.0f, 1.9f, -40.0f)); // 4
	coords.push_back(std::make_tuple(30.0f, 1.9f, -20.0f)); // 5

	graphs.push_back(new Graph(edgeList, coords));
	edgeList.clear();
	coords.clear();

	// Graph 3
	edgeList.push_back(std::make_tuple(0, 1, 8));
	edgeList.push_back(std::make_tuple(0, 2, 8));
	edgeList.push_back(std::make_tuple(0, 3, 8));
	edgeList.push_back(std::make_tuple(0, 4, 8));
	edgeList.push_back(std::make_tuple(0, 5, 8));
	edgeList.push_back(std::make_tuple(0, 6, 8));
	edgeList.push_back(std::make_tuple(0, 7, 8));
	edgeList.push_back(std::make_tuple(0, 8, 8));
	edgeList.push_back(std::make_tuple(1, 2, 8));
	edgeList.push_back(std::make_tuple(2, 3, 8));
	edgeList.push_back(std::make_tuple(3, 4, 8));
	edgeList.push_back(std::make_tuple(4, 5, 8));
	edgeList.push_back(std::make_tuple(5, 6, 8));
	edgeList.push_back(std::make_tuple(6, 7, 8));
	edgeList.push_back(std::make_tuple(7, 8, 8));
	edgeList.push_back(std::make_tuple(8, 1, 8));

	coords.push_back(std::make_tuple(0.0f, 1.9f, -20.0f)); // 0
	coords.push_back(std::make_tuple(-20.0f, 1.9f, 0.0f)); // 1
	coords.push_back(std::make_tuple(0.0f, 1.9f, 0.0f)); // 2
	coords.push_back(std::make_tuple(20.0f, 1.9f, 0.0f)); // 3
	coords.push_back(std::make_tuple(20.0f, 1.9f, -20.0f)); // 4
	coords.push_back(std::make_tuple(20.0f, 1.9f, -40.0f)); // 5
	coords.push_back(std::make_tuple(0.0f, 1.9f, -40.0f)); // 6
	coords.push_back(std::make_tuple(-20.0f, 1.9f, -40.0f)); // 7
	coords.push_back(std::make_tuple(-20.0f, 1.9f, -20.0f)); // 8

	graphs.push_back(new Graph(edgeList, coords));
	edgeList.clear();
	coords.clear();

	// Graph 4
	edgeList.push_back(std::make_tuple(0, 1, 8));
	edgeList.push_back(std::make_tuple(0, 2, 8));
	edgeList.push_back(std::make_tuple(1, 2, 8));
	edgeList.push_back(std::make_tuple(2, 3, 8));
	edgeList.push_back(std::make_tuple(2, 4, 8));
	edgeList.push_back(std::make_tuple(3, 4, 8));
	edgeList.push_back(std::make_tuple(4, 5, 8));
	edgeList.push_back(std::make_tuple(5, 2, 8));

	coords.push_back(std::make_tuple(-20.0f, 1.9f, -10.0f)); // 0
	coords.push_back(std::make_tuple(40.0f, 1.9f, 0.0f)); // 1
	coords.push_back(std::make_tuple(0.0f, 1.9f, -25.0f)); // 2
	coords.push_back(std::make_tuple(25.0f, 1.9f, -25.0f)); // 3
	coords.push_back(std::make_tuple(38.0f, 1.9f, -8.0f)); // 4
	coords.push_back(std::make_tuple(-18.0f, 1.9f, -25.0f)); // 5

	graphs.push_back(new Graph(edgeList, coords));
	edgeList.clear();
	coords.clear();

	// Graph 5
	edgeList.push_back(std::make_tuple(0, 1, 8));
	edgeList.push_back(std::make_tuple(0, 2, 8));
	edgeList.push_back(std::make_tuple(0, 3, 8));
	edgeList.push_back(std::make_tuple(0, 4, 8));
	edgeList.push_back(std::make_tuple(0, 5, 8));
	edgeList.push_back(std::make_tuple(0, 6, 8));
	edgeList.push_back(std::make_tuple(0, 7, 8));
	edgeList.push_back(std::make_tuple(0, 8, 8));
	edgeList.push_back(std::make_tuple(0, 9, 8));
	edgeList.push_back(std::make_tuple(0, 10, 8));
	edgeList.push_back(std::make_tuple(0, 11, 8));
	edgeList.push_back(std::make_tuple(0, 12, 8));
	edgeList.push_back(std::make_tuple(1, 2, 8));
	edgeList.push_back(std::make_tuple(2, 3, 8));
	edgeList.push_back(std::make_tuple(3, 4, 8));
	edgeList.push_back(std::make_tuple(4, 5, 8));
	edgeList.push_back(std::make_tuple(5, 6, 8));
	edgeList.push_back(std::make_tuple(6, 1, 8));

	coords.push_back(std::make_tuple(-5.0f, 1.9f, -20.0f)); // 0 - C
	coords.push_back(std::make_tuple(-15.0f, 1.9f, -12.5f)); // 1 - BL Corner
	coords.push_back(std::make_tuple(-5.0f, 1.9f, -5.0f)); // 2 - BC
	coords.push_back(std::make_tuple(5.0f, 1.9f, -12.5f)); // 3 - BR Corner
	coords.push_back(std::make_tuple(5.0f, 1.9f, -27.5f)); // 4 - TR Corner
	coords.push_back(std::make_tuple(-5.0f, 1.9f, -35.0f)); // 5 - TC
	coords.push_back(std::make_tuple(-15.0f, 1.9f, -27.5f)); // 6 - TL Corner
	coords.push_back(std::make_tuple(-20.0f, 1.9f, 0.0f)); // 7 - BL Arm
	coords.push_back(std::make_tuple(10.0f, 1.9f, 0.0f)); // 8 - BR Arm
	coords.push_back(std::make_tuple(20.0f, 1.9f, -20.0f)); // 9 - RC Arm
	coords.push_back(std::make_tuple(10.0f, 1.9f, -50.0f)); // 10 - TR Arm
	coords.push_back(std::make_tuple(-20.0f, 1.9f, -50.0f)); // 11 - TL Arm
	coords.push_back(std::make_tuple(-30.0f, 1.9f, -20.0f)); // 12 - LC Arm

	graphs.push_back(new Graph(edgeList, coords));
	edgeList.clear();
	coords.clear();
}

void processNormalKeys(unsigned char key, int xx, int yy)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'w':
		camera->moveForward();

		break;
	case 'a':
		camera->moveLeft();

		break;
	case 's':
		camera->moveBack();

		break;
	case 'd':
		camera->moveRight();

		break;
	case ' ':
		camera->moveUp();

		break;
	case 'z':
		camera->moveDown();

		break;
	case '=':
		camera->increaseSensitivity();

		break;
	case '-':
		camera->decreaseSensitivity();
		
		break;
	case 'r':
		if (!runningAnimation) currGraph->refresh();
		break;
	}
}

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		camera->panLeft();

		break;
	case GLUT_KEY_RIGHT:
		camera->panRight();

		break;
	case GLUT_KEY_UP:
		camera->panUp();

		break;
	case GLUT_KEY_DOWN:
		camera->panDown();

		break;
	}
}

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}