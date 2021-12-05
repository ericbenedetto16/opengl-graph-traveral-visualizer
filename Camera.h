#pragma once

#include <tuple>

class Camera {
private:
	float posX, posY, posZ, lookX, lookY, lookZ;
	float upX = 0.0f;
	float upY = 1.0f;
	float upZ = 0.0f;
	float sensitivity;
	float angle = 0.0f;
	float fraction = 0.1f;
public:
	Camera(float posX, float posY, float posZ, float lookX, float lookY, float lookZ) {
		this->posX = posX;
		this->posY = posY;
		this->posZ = posZ;
		this->lookX = lookX;
		this->lookY = lookY;
		this->lookZ = lookZ;
		this->sensitivity = 4.0f;
	}

	std::tuple<float, float, float> leftRightVector() {
		float viewX = this->lookX;
		float viewY = this->lookY;
		float viewZ = this->lookZ;

		float newX = ((viewY * 0) - (viewZ * 1));
		float newY = ((viewZ * 0) - (viewX * 0));
		float newZ = ((viewX * 1) - (viewY * 0));

		float magnitude = sqrt((newX * newX) + (newY * newY) + (newZ * newZ));

		newX /= magnitude;
		newY /= magnitude;
		newZ /= magnitude;

		return std::make_tuple(newX, newY, newZ);
	}

	void moveForward() {
		this->posX += this->lookX * this->fraction * this->sensitivity;
		this->posZ += this->lookZ * this->fraction * this->sensitivity;
	}

	void moveBack() {
		this->posX -= this->lookX * this->fraction * this->sensitivity;
		this->posZ -= this->lookZ * this->fraction * this->sensitivity;
	}

	void moveLeft() {
		std::tuple<float, float, float> dir = this->leftRightVector();
		this->posX -= std::get<0>(dir) * this->fraction * this->sensitivity;
		this->posZ -= std::get<2>(dir) * this->fraction * this->sensitivity;
	}

	void moveRight() {
		std::tuple<float, float, float> dir = this->leftRightVector();
		this->posX += std::get<0>(dir) * this->fraction * this->sensitivity;
		this->posZ += std::get<2>(dir) * this->fraction * this->sensitivity;
	}

	void moveUp() {
		this->posY += fraction * this->sensitivity;
		this->lookY += fraction * this->sensitivity;
	}

	void moveDown() {
		this->posY -= fraction * this->sensitivity;
		this->lookY -= fraction * this->sensitivity;
	}

	void panLeft() {
		this->angle -= 0.01f * this->sensitivity;
		this->lookX = sin(angle);
		this->lookZ = -cos(angle);
	}

	void panRight() {
		this->angle += 0.01f * this->sensitivity;
		this->lookX = sin(angle);
		this->lookZ = -cos(angle);
	}

	void panUp() {
		this->lookY += 0.1f;
	}

	void panDown() {
		this->lookY -= 0.1f;
	}

	void refresh() {
		glLoadIdentity();
		gluLookAt(posX, posY, posZ,
			posX + lookX, lookY, posZ + lookZ,
			upX, upY, upZ);
	}

	float getSensitivity() {
		return this->sensitivity;
	}

	void increaseSensitivity() {
		this->sensitivity++;
	}

	void decreaseSensitivity() {
		this->sensitivity > 1.0f ? this->sensitivity-- : this->sensitivity = 1.0f;
	}

	float getLookX() {
		return this->lookX;
	}

	float getLookY() {
		return this->lookY;
	}

	float getLookZ() {
		return this->lookZ;
	}

	float getPosX() {
		return this->posX;
	}

	float getPosY() {
		return this->posY;
	}

	float getPosZ() {
		return this->posZ;
	}

	float getUpX() {
		return this->upX;
	}

	float getUpY() {
		return this->upY;
	}

	float getUpZ() {
		return this->upZ;
	}

	void setPosX(float posX) {
		this->posX = posX;
	}

	void setPosY(float posY) {
		this->posY = posY;
	}

	void setPosZ(float posZ) {
		this->posZ = posZ;
	}

	void setLookX(float lookX) {
		this->lookX = lookX;
	}

	void setLookY(float lookY) {
		this->lookY = lookY;
	}

	void setLookZ(float lookZ) {
		this->lookZ = lookZ;
	}

	void setUpX(float upX) {
		this->upX = upX;
	}

	void setUpY(float upY) {
		this->upY = upY;
	}

	void setUpZ(float upZ) {
		this->upZ = upZ;
	}

};