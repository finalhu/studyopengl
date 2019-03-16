#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup)
{
	this->position = position;
	worldUp = worldup;
	forward = glm::normalize(target - position);
	right = glm::normalize(glm::cross(forward, worldUp));
	up = glm::normalize(glm::cross(forward, right));
}

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup)
{
	this->pitch = pitch;
	this->yaw = yaw;
	this->position = position;
	worldUp = worldup;
	forward.x = glm::cos(pitch) * glm::sin(yaw);
	forward.y = glm::sin(pitch);
	forward.z = glm::cos(pitch) * glm::cos(yaw);
	right = glm::normalize(glm::cross(forward, worldUp));
	up = glm::normalize(glm::cross(forward, right));
}


Camera::~Camera()
{
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(position, position + forward, worldUp);
}

void Camera::UpdateCameraVectors()
{
	forward.x = glm::cos(pitch) * glm::sin(yaw);
	forward.y = glm::sin(pitch);
	forward.z = glm::cos(pitch) * glm::cos(yaw);
	right = glm::normalize(glm::cross(forward, worldUp));
	up = glm::normalize(glm::cross(forward, right));
}

void Camera::ProcessMouseMovement(float deltaX, float deltaY)
{
	pitch += -deltaY * 0.01f;
	yaw += -deltaX * 0.01f;
	UpdateCameraVectors();
}


void Camera::setMovefront()
{
	position = position + forward * 0.005f;
}
void Camera::setMovelast()
{
	position = position - forward * 0.005f;
}

void Camera::setMoveleft()
{
	glm::vec3 v(forward.z, 0, -forward.x);
	position = position + v * 0.005f;
}

void Camera::setMoveright()
{
	glm::vec3 v(forward.z, 0, -forward.x);
	position = position - v * 0.005f;
}