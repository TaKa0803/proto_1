#pragma once
#include <math.h>
#include <limits>

namespace Math
{

	constexpr float Pi = 3.14159265359f;
	constexpr float Two_Pi = 2.0f * Pi;
	constexpr float Pi_Over_2 = Pi / 2.0f;
	constexpr float INF = std::numeric_limits<float>::infinity();
	constexpr float NEG_INF = -std::numeric_limits<float>::infinity();

	/// <summary>
	/// �ʓx�@�ϊ�
	/// </summary>
	/// <param name="degrees">�x���@</param>
	/// <returns>�ʓx�@</returns>
	inline float ToRadians(float degrees) {
		return degrees * Pi / 180.0f;
	}
	/// <summary>
	/// �x���@�ϊ�
	/// </summary>
	/// <param name="radians">�ʓx�@</param>
	/// <returns>�x���@</returns>
	inline float ToDegrees(float radians) {
		return radians * 180.0f / Pi;
	}
	/// <summary>
	/// �قڃ[��
	/// </summary>
	/// <param name="value">�l</param>
	/// <param name="epsilon">�덷</param>
	/// <returns>true : false</returns>
	inline bool NearZero(float value, float epsilon = 0.001f) {
		return fabs(value) <= epsilon;
	}
	/// <summary>
	/// �傫���ق������߂�
	/// </summary>
	/// <typeparam name="TYPE">�^</typeparam>
	/// <param name="v1">�l�P</param>
	/// <param name="v2">�l�Q</param>
	/// <returns>�l�P�@or�@�l�Q</returns>
	template <typename TYPE>
	TYPE Max(const TYPE& v1, const TYPE& v2) {
		return v1 < v2 ? v2 : v1;
	}
	/// <summary>
	/// �������ق������߂�
	/// </summary>
	/// <typeparam name="TYPE">�^</typeparam>
	/// <param name="v1">�l�P</param>
	/// <param name="v2">�l�Q</param>
	/// <returns>�l�P�@or�@�l�Q</returns>
	template <typename TYPE>
	TYPE Min(const TYPE& v1, const TYPE& v2) {
		return v1 < v2 ? v1 : v2;
	}
	/// <summary>
	/// �l�����߂�
	/// </summary>
	/// <typeparam name="TYPE">�^</typeparam>
	/// <param name="value">�l</param>
	/// <param name="lower">����</param>
	/// <param name="upper">���</param>
	/// <returns></returns>
	template <typename TYPE>
	TYPE Clamp(const TYPE& value, const TYPE& lower, const TYPE& upper) {
		return Min(upper, Max(lower, value));
	}
	/// <summary>
	/// ��Βl
	/// </summary>
	/// <param name="value">�l</param>
	/// <returns></returns>
	inline float Abs(float value) {
		return fabsf(value);
	}
	/// <summary>
	///	�T�C��
	/// </summary>
	/// <param name="angle">���W�A��</param>
	/// <returns></returns>
	inline float Sin(float angle) {
		return sinf(angle);
	}
	/// <summary>
	/// �R�T�C��
	/// </summary>
	/// <param name="angle">���W�A��</param>
	/// <returns></returns>
	inline float Cos(float angle) {
		return cosf(angle);
	}
	/// <summary>
	/// �^���W�F���g
	/// </summary>
	/// <param name="angle">���W�A��</param>
	/// <returns></returns>
	inline float Tan(float angle) {
		return tanf(angle);
	}
	/// <summary>
	/// �A�[�N�T�C��
	/// </summary>
	/// <param name="angle">���W�A��</param>
	/// <returns></returns>
	inline float Asin(float angle) {
		return asinf(angle);
	}
	/// <summary>
	/// �A�[�N�R�T�C��
	/// </summary>
	/// <param name="angle">���W�A��</param>
	/// <returns></returns>
	inline float Acos(float angle) {
		return acosf(angle);
	}
	/// <summary>
	/// �A�[�N�^���W�F���g
	/// </summary>
	/// <param name="y">y����</param>
	/// <param name="x">x����</param>
	/// <returns>���W�A��</returns>
	inline float Atan2(float y, float x) {
		return atan2f(y, x);
	}
	/// <summary>
	/// ���`���
	/// </summary>
	/// <param name="t">�ω���</param>
	/// <param name="start">�X�^�[�g</param>
	/// <param name="end">�G���h</param>
	/// <returns></returns>
	inline float Lerp(float t, float start, float end) {
		return start + t * (end - start);
	}
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="value">�l</param>
	/// <returns></returns>
	inline float Sqrt(float value) {
		return sqrtf(value);
	}
	/// <summary>
	/// float��]���Z
	/// </summary>
	/// <param name="number">�����鐔</param>
	/// <param name="denom">���鐔</param>
	/// <returns>�]��</returns>
	inline float Fmod(float number, float denom) {
		return fmodf(number, denom);
	}
	/// <summary>
	/// �p��
	/// </summary>
	/// <param name="base">��</param>
	/// <param name="exponent">�w��</param>
	/// <returns></returns>
	inline float Pow(float base, float exponent) {
		return powf(base, exponent);
	}
}

// 2�����x�N�g��
class Vector2D
{

public:

	float x; // x����
	float y; // y����


public:

	//�R���X�g���N�^

	Vector2D() : x(0.0f), y(0.0f) {}
	Vector2D(float x, float y) : x(x), y(y) {}
	Vector2D(const Vector2D& vector) : Vector2D(vector.x, vector.y) {}
	~Vector2D() {}


	// �Z�b�g�֐�
	/// <summary>
	/// �Z�b�g
	/// </summary>
	inline void Set(float x, float y);
	/// <summary>
	/// �[���x�N�g���ɂ���
	/// </summary>
	inline void SetZero();
	/// <summary>
	/// ���K���x�N�g���ɂ���
	/// </summary>
	inline void SetNormalize();
	/// <summary>
	/// �傫����ς���
	/// </summary>
	/// <param name="length">�傫��</param>
	inline void SetMagnitude(float length);
	/// <summary>
	/// ��]������
	/// </summary>
	/// <param name="theta">��]�p�x</param>
	inline void SetRotate(float theta);

	// const�֐� 
	/// <summary>
	/// ����
	/// </summary>
	/// <returns>float�^</returns>
	inline float Length() const;
	/// <summary>
	/// �����̓��
	/// </summary>
	/// <returns>float�^</returns>
	inline float LengthSquare() const;
	/// <summary>
	/// �x�N�g���Ƃ̋���
	/// </summary>
	/// <param name="other">�x�N�g��</param>
	/// <returns>float�^</returns>
	inline float DistanceFrom(const Vector2D& other) const;
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="other">�x�N�g��</param>
	/// <returns>float�^</returns>
	inline float Dot(const Vector2D& other) const;
	/// <summary>
	/// �O��
	/// </summary>
	/// <param name="other">�x�N�g��</param>
	/// <returns>float�^</returns>
	inline float Cross(const Vector2D& other) const;
	/// <summary>
	/// ���K��
	/// </summary>
	/// <returns>Vector2D�^</returns>
	inline Vector2D Normalized() const;
	/// <summary>
	/// �@���x�N�g��
	/// </summary>
	/// <returns>Vector2D�^</returns>
	inline Vector2D Normal() const;
	/// <summary>
	/// ��]�����x�N�g��
	/// </summary>
	/// <param name="theta">��]�p�x</param>
	/// <returns>Vector2D�^</returns>
	inline Vector2D Rotated(float theta) const;
	/// <summary>
	/// �傫����ς����x�N�g��
	/// </summary>
	/// <param name="length">�傫��</param>
	/// <returns>Vector2D�^</returns>
	inline Vector2D Magnituded(float length) const;
	/// <summary>
	/// ���˃x�N�g��
	/// </summary>
	/// <param name="normal">���K�������ǂ̖@���x�N�g��</param>
	/// <returns>Vector2D�^</returns>
	inline Vector2D Reflected(const Vector2D& normal) const;
	/// <summary>
	/// �ǂ���x�N�g��
	/// </summary>
	/// <param name="normal">���K�������ǂ̖@���x�N�g��</param>
	/// <returns>Vector2D�^</returns>
	inline Vector2D AlongWall(const Vector2D& normal) const;

	// ��r�֐�

	/// <summary>
	/// �[���x�N�g���ł��邩
	/// </summary>
	/// <returns>bool�^</returns>
	inline bool IsZero() const;

	// ���Z�q�̃I�[�o�[���[�h

	inline Vector2D operator+() const;
	inline Vector2D operator-() const;
	inline Vector2D operator+(const Vector2D& other) const;
	inline Vector2D operator-(const Vector2D& other) const;
	inline Vector2D operator*(float s) const;
	inline Vector2D operator/(float s) const;
	inline Vector2D operator*(const Vector2D& other) const;
	inline Vector2D operator/(const Vector2D& other) const;
	inline const Vector2D& operator=(const Vector2D& other);
	inline const Vector2D& operator+=(const Vector2D& other);
	inline const Vector2D& operator-=(const Vector2D& other);
	inline const Vector2D& operator*=(float s);
	inline const Vector2D& operator/=(float s);
	inline bool operator==(const Vector2D& other) const;
	inline bool operator!=(const Vector2D& other) const;

	// ��ɂ����Z
	friend inline Vector2D operator*(float s, const Vector2D& vector) {
		return { s * vector.x,s * vector.y };
	}
};

class Matrix33 {

private:
	float ele[3][3];

public:
	Matrix33(
		float _00 = 1, float _01 = 0, float _02 = 0,
		float _10 = 0, float _11 = 1, float _12 = 0,
		float _20 = 0, float _21 = 0, float _22 = 1) {
		ele[0][0] = _00, ele[0][1] = _01, ele[0][2] = _02;
		ele[1][0] = _10, ele[1][1] = _11, ele[1][2] = _12;
		ele[2][0] = _20, ele[2][1] = _21, ele[2][2] = _22;
	}
	Matrix33(float e[3][3]) {
		memcpy(ele, e, 9 * sizeof(float));
	}


	inline void setIdentity();
	inline Vector2D operator*(const Vector2D& vec) const;
	inline Matrix33 operator*(const Matrix33& mat) const;
	inline Matrix33& operator*=(const Matrix33& mat);

	inline static Matrix33 CreateScaling(float x, float y);
	inline static Matrix33 CreateScaling(const Vector2D& vec);
	inline static Matrix33 CreateScaling(float s);

	inline static Matrix33 CreateRotation(float t);

	inline static Matrix33 CreateTranslation(float x, float y);
	inline static Matrix33 CreateTranslation(const Vector2D& vec);
};

#pragma region Vector2D�֐���`

// �Z�b�g�֐�

inline void Vector2D::Set(float x, float y) {
	x = x;
	y = y;
}

inline void Vector2D::SetZero() {
	x = 0;
	y = 0;
}
inline void Vector2D::SetNormalize() {
	*this = Normalized();
}
inline void Vector2D::SetMagnitude(float length) {
	*this = Magnituded(length);
}
inline void Vector2D::SetRotate(float theta) {
	*this = Rotated(theta);
}

// const�֐� 
inline float Vector2D::Length() const {
	return Math::Sqrt(LengthSquare());
}
inline float Vector2D::LengthSquare() const {
	return Dot(*this);
}
inline float Vector2D::DistanceFrom(const Vector2D& other) const {
	return (other - *this).Length();
}
inline float Vector2D::Dot(const Vector2D& other) const {
	return x * other.x + y * other.y;
}
inline float Vector2D::Cross(const Vector2D& other) const {
	return x * other.y - y * other.x;
}
inline Vector2D Vector2D::Normalized() const {
	return Length() != 0 ? *this / Length() : *this;
}
inline Vector2D Vector2D::Normal() const {
	return { -y,x };
}
inline Vector2D Vector2D::Rotated(float theta) const {
	float c = Math::Cos(theta);
	float s = Math::Sin(theta);
	return{ x * c - y * s ,y * c + x * s };
}
inline Vector2D Vector2D::Magnituded(float length) const {
	return Normalized() * length;
}
inline Vector2D Vector2D::Reflected(const Vector2D& normal) const {
	return normal.Dot(-*this) * 2 * normal + *this;
}
inline Vector2D Vector2D::AlongWall(const Vector2D& normal) const {
	return normal.Dot(-*this) * normal + *this;
}

// ��r�֐�

inline bool Vector2D::IsZero() const {
	return x == 0.0 && y == 0.0;
}

// ���Z�q�̃I�[�o�[���[�h

inline Vector2D Vector2D::operator+() const {
	return *this;
}
inline Vector2D Vector2D::operator-() const {
	return { -x,-y };
}
inline Vector2D Vector2D::operator+(const Vector2D& other) const {
	return { x + other.x, y + other.y };
}
inline Vector2D Vector2D::operator-(const Vector2D& other) const {
	return { x - other.x, y - other.y };
}
inline Vector2D Vector2D::operator*(float s) const {
	return { x * s, y * s };
}
inline Vector2D Vector2D::operator/(float s) const {
	return { x * (1.0f / s), y * (1.0f / s) };
}
inline Vector2D Vector2D::operator*(const Vector2D& other) const {
	return { x * other.x, y * other.y };
}
inline Vector2D Vector2D::operator/(const Vector2D& other) const {
	return { x * (1.0f / other.x), y * (1.0f / other.y) };
}
inline const Vector2D& Vector2D::operator=(const Vector2D& other) {
	x = other.x;
	y = other.y;
	return *this;
}
inline const Vector2D& Vector2D::operator+=(const Vector2D& other) {
	x += other.x;
	y += other.y;
	return *this;
}
inline const Vector2D& Vector2D::operator-=(const Vector2D& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}
inline const Vector2D& Vector2D::operator*=(float s) {
	x *= s;
	y *= s;
	return *this;
}
inline const Vector2D& Vector2D::operator/=(float s) {
	x /= s;
	y /= s;
	return *this;
}
inline bool Vector2D::operator==(const Vector2D& other) const {
	return x == other.x && y == other.y;
}
inline bool Vector2D::operator!=(const Vector2D& other) const {
	return x != other.x && y != other.y;
}

#pragma endregion


#pragma region Matrix33�֐���`
inline void Matrix33::setIdentity() {
	float iden[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	memcpy(ele, iden, 9 * sizeof(float));
}
inline Vector2D Matrix33::operator*(const Vector2D& vec) const{
	return Vector2D(
		ele[0][0] * vec.x + ele[0][1] * vec.y + ele[0][2],
		ele[1][0] * vec.x + ele[1][1] * vec.y + ele[1][2]);
}
inline Matrix33 Matrix33::operator*(const Matrix33& mat) const {
	return Matrix33(
			ele[0][0] * mat.ele[0][0] + ele[0][1] * mat.ele[1][0] + ele[0][2] * mat.ele[2][0],
			ele[0][0] * mat.ele[0][1] + ele[0][1] * mat.ele[1][1] + ele[0][2] * mat.ele[2][1],
			ele[0][0] * mat.ele[0][2] + ele[0][1] * mat.ele[1][2] + ele[0][2] * mat.ele[2][2],

			ele[1][0] * mat.ele[0][0] + ele[1][1] * mat.ele[1][0] + ele[1][2] * mat.ele[2][0],
			ele[1][0] * mat.ele[0][1] + ele[1][1] * mat.ele[1][1] + ele[1][2] * mat.ele[2][1],
			ele[1][0] * mat.ele[0][2] + ele[1][1] * mat.ele[1][2] + ele[1][2] * mat.ele[2][2], 

			ele[2][0] * mat.ele[0][0] + ele[2][1] * mat.ele[1][0] + ele[2][2] * mat.ele[2][0],
			ele[2][0] * mat.ele[0][1] + ele[2][1] * mat.ele[1][1] + ele[2][2] * mat.ele[2][1],
			ele[2][0] * mat.ele[0][2] + ele[2][1] * mat.ele[1][2] + ele[2][2] * mat.ele[2][2]);
}
inline Matrix33& Matrix33::operator*=(const Matrix33& mat) {
	*this = *this * mat;
	return *this;
}
inline Matrix33 Matrix33::CreateScaling(float x, float y) {
	return Matrix33(
		x, 0, 0,
		0, y, 0,
		0, 0, 1
	);
}
inline Matrix33 Matrix33::CreateScaling(const Vector2D& vec) {
	return CreateScaling(vec.x, vec.y);
}
inline Matrix33 Matrix33::CreateScaling(float s){
	return CreateScaling(s, s);
}
inline Matrix33 Matrix33::CreateRotation(float t) {
	float s = Math::Sin(t);
	float c = Math::Cos(t);
	return Matrix33(
		c,  s,  0,
		-s, c,  0,
		0,  0,  1
	);
}
inline Matrix33 Matrix33::CreateTranslation(float x, float y) {
	return Matrix33(
		1, 0, x,
		0, 1, y,
		0, 0, 1
	);
}
inline Matrix33 Matrix33::CreateTranslation(const Vector2D& vec) {
	return CreateTranslation(vec.x, vec.y);
}
#pragma endregion