#pragma once

#ifndef CAMERA_H_
#define CAMERA_H_

#endif // !CAMERA_H_

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Ĭ��ֵ
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp);
	Camera(glm::vec3 position, glm::vec3 worldUp, float pitch, float yaw);
	~Camera();

	//���������4ά����
	inline glm::mat4 getViewMatrix() { return glm::lookAt(position_, position_ + front_, up_); }
	//�ı䷽��
	void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
	//�ƶ�
	inline void moveFront() { position_ += front_ * movementSpeed_; }
	inline void moveLast()  { position_ -= front_ * movementSpeed_; }
	inline void moveRight() { position_ += right_ * movementSpeed_; }
	inline void moveLeft()  { position_ -= right_ * movementSpeed_; }

	inline float getZoom() { return zoom_; }
	inline glm::vec3 getPosition() { return position_; }

private:
	//����ŷ���Ǽ���ǰ��������
	void updateCameraVectors();

private:
	//camera����
	glm::vec3 position_;
	glm::vec3 front_;      
	glm::vec3 up_; 
	glm::vec3 right_;
	glm::vec3 worldUp_;
	//ŷ����
	float pitch_ = 0.0f;
	float yaw_ = -90.0f;
	//������ٶ�ѡ��
	float movementSpeed_ = 0.005;
	float mouseSensitivity_ = 0.01;
	float zoom_ = 45.0f;
};

