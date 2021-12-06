// CSC 470 Project 2

// Eric Benedetto
#include <GL/glut.h>
#include "State.h"
#include "Util.h"
#include "Menu.h"

int WINDOW_WIDTH = 500;
int WINDOW_HEIGHT = 500;
int RENDER_INTERVAL = 800;

void drawGround() {
	GLfloat mat[4];
	mat[0] = 0.9f; mat[1] = 0.9f; mat[2] = 0.9f; mat[3] = 1.0f;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat);

	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
}

void tick() {
	// Animation Shouldn't Be Running If We Have No Iterator
	if (runningAnimation && it == nullptr) runningAnimation = false;

	// If We Have a Graph, Render It
	if (currGraph != nullptr) currGraph->render();
	
	if (runningAnimation && it->hasNext() && simClock % RENDER_INTERVAL == 0) {
		it->next();
		simClock++;
	}
	else if (runningAnimation && it->hasNext()) {
		simClock++;
	}
	else {
		it = nullptr;
		runningAnimation = false;
		simClock = 0; // Prevent Overflow
	}
}

void renderScene(void)
{
	// Scene Reset
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera->refresh();

	// Draw Ground
	drawGround();

	// Process Events
	tick();

	// Render Frame
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// Init
	camera = new Camera(0.0f, 1.0f, 5.0f, 0.0f, 1.0f, -1.0f);
	initGraphs();

	// OpenGL Stuff
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Graph Traversal Visualizer");
	
	// Register Callbacks
	createMenu();
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutWarpPointer(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	
	glEnable(GL_DEPTH_TEST); // 3D Space

	initLighting();

	// OpenGL Main Event Loop
	glutMainLoop();

	return 1;
}