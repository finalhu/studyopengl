#pragma once

#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup);
	Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup);
	~Camera();

	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 worldUp;

	float pitch;
	float yaw;

	void ProcessMouseMovement(float deltaX, float deltaY);
	void setMovefront();
	void setMovelast();
	void setMoveleft();
	void setMoveright();

	glm::mat4 getViewMatrix();

private:
	void UpdateCameraVectors();

private:
	float moveSpeed;
	float mouseSpeed;
};

#endif // !CAMERA_H_
