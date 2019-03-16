#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp) 
	: position_(position) , worldUp_(worldUp)
{
	front_ = glm::normalize(position - target);
	right_ = glm::normalize(glm::cross(front_, worldUp_));
	up_ = glm::normalize(glm::cross(right_, front_));
}

Camera::Camera(glm::vec3 position, glm::vec3 worldUp, float pitch, float yaw)
	: position_(position), worldUp_(worldUp), pitch_(pitch), yaw_(yaw)
{
	updateCameraVectors();
}

Camera::~Camera()
{
}

void Camera::updateCameraVectors()
{
	glm::vec3 front;
	front.x = glm::cos(pitch_) * glm::sin(yaw_);
	front.y = glm::sin(pitch_);
	front.z = glm::cos(pitch_) * glm::cos(yaw_);
	front_ = glm::normalize(front);
	right_ = glm::normalize(glm::cross(front_, worldUp_));
	up_ = glm::normalize(glm::cross(right_, front_));
}


void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
	pitch_ += yoffset * mouseSensitivity_;
	yaw_ += xoffset * mouseSensitivity_;

	if (constrainPitch)
	{
		if (pitch_ > 89.0f)
			pitch_ = 89.0f;
		if (pitch_ < -89.0f)
			pitch_ = -89.0f;
	}

	updateCameraVectors();
}
