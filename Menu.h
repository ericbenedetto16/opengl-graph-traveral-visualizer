#pragma once

#include "Graph.h"

extern int window;
extern int graph_menu;
extern int main_menu;
extern std::vector<Graph*> graphs;
extern bool runningAnimation;
extern Graph* currGraph;
extern GraphIterator* it;

void mainMenu(int n) {
	switch (n) {
	case 0:
		glutDestroyWindow(window);
		exit(0);

		break;
	case 1:
		if (currGraph != nullptr) {
			currGraph->refresh();
			it = new GraphDFSIterator(currGraph, 0);
			runningAnimation = true;
		}
		
		break;
	case 2:
		if (currGraph != nullptr) {
			currGraph->refresh();
			it = new GraphBFSIterator(currGraph, 0);
			runningAnimation = true;
		}

		break;
	}
}

void selectGraph(int n) {
	runningAnimation = false;
	it = nullptr;

	if (currGraph != nullptr) {
		Graph* temp = currGraph;
		temp->refresh();
	}

	currGraph = graphs.at(n);
}

void createMenu(void) {
	graph_menu = glutCreateMenu(selectGraph);
	for (int i = 0; i < graphs.size(); i++) {
		std::string label = "Graph ";
		label.append(std::to_string(i + 1));
		glutAddMenuEntry(label.c_str(), i);
	}

	main_menu = glutCreateMenu(mainMenu);
	glutAddSubMenu("Select Graph", graph_menu);

	glutAddMenuEntry("Perform DFS", 1);
	glutAddMenuEntry("Perform BFS", 2);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
