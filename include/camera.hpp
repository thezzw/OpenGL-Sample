#pragma once

#include<glad/glad.h>

#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

// 枚举相机可以移动的方向
enum Directions
{
	kForward,
	kBackward,
	kLeft,
	kRight,
	kUp,
	kDown
};

class Camera
{
public:
	/**
	 * @brief 构造一个新的Camera对象
	 * 
	 * @param init_pos 初始化相机的位置
	 */
	Camera(glm::vec3 init_pos)
	{
		position_ = init_pos;
	}
	~Camera(){}

	/**
	 * @brief 获取缩放比
	 * 
	 * @return float 缩放比
	 */
	float zoom(){ return zoom_; }

	/**
	 * @brief 获取相机位置
	 * 
	 * @return glm::vec3 相机位置
	 */
	glm::vec3 position() { return position_; }

	/**
	 * @brief 处理键盘输入
	 * 
	 * @param direction 移动方向
	 * @param dlt_time 间隔
	 */
	void ProcessKeyboard(Directions direction, float dlt_time)
	{
		float dlt_dis = dlt_time * velocity_;
		switch (direction)
		{
		case kForward:
			position_ += dlt_dis * front_;
			break;
		case kBackward:
			position_ -= dlt_dis * front_;
			break;
		case kLeft:
			position_ -= glm::normalize(glm::cross(front_, up_)) * dlt_dis;
			break;
		case kRight:
			position_ += glm::normalize(glm::cross(front_, up_)) * dlt_dis;
			break;
		case kUp:
			position_ += dlt_dis * up_;
			break;
		case kDown:
			position_ -= dlt_dis * up_;
			break;
		default:
			break;
		}
	}

	/**
	 * @brief 处理鼠标移动
	 * 
	 * @param x_offset x轴偏移量
	 * @param y_offset y轴偏移量
	 */
	void ProcessMouseMovement(float x_offset, float y_offset)
	{
		x_offset *= sensitivity_;
		y_offset *= sensitivity_;

		yaw_ += x_offset;
		pitch_ += y_offset;
		
		if (pitch_ > 89.0f)
		    pitch_ = 89.0f;
		if (pitch_ < -89.0f)
		    pitch_ = -89.0f;
		
		glm::vec3 front;
		front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		front.y = sin(glm::radians(pitch_));
		front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		front_ = glm::normalize(front);
	}

	/**
	 * @brief 处理鼠标滚轮
	 * 
	 * @param y_offset y轴偏移量
	 */
	void ProcessMouseScroll(float y_offset)
	{
		if (zoom_ >= 1.0f && zoom_ <= 45.0f)
			zoom_ -= y_offset;
		if (zoom_ <= 1.0f)
			zoom_ = 1.0f;
		if (zoom_ >= 45.0f)
			zoom_ = 45.0f;
	}
	
	/**
	 * @brief 获取观察矩阵
	 * 
	 * @return glm::mat4 观察矩阵
	 */
	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(position_, position_ + front_, up_);
	}
private:
	glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 front_ = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up_ = glm::vec3(0.0f, 1.0f, 0.0f);

	float velocity_ = 2.5f;
	float zoom_ = 45.0f;
	float sensitivity_ = 0.05f;
	float yaw_ = -90.0f;
	float pitch_ = 0.0f;

};