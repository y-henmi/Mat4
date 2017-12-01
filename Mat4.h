#include <immintrin.h>
#include <stdint.h>

/**
 * GLKitを基にCでVR動作に必要な箇所抽出
 **/
union _Matrix4
{
    struct
    {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    };
    float m[16];
} __attribute__((aligned(16)));
typedef union _Matrix4 Matrix4;

/**
 * GLKMatrix4Make 
 **/
Matrix4 Matrix4Make(float m00, float m01, float m02, float m03,
                    float m10, float m11, float m12, float m13,
                    float m20, float m21, float m22, float m23,
                    float m30, float m31, float m32, float m33);

/**
 * GLKMatrix4Multiply 
 **/
Matrix4 Matrix4Multiply(Matrix4 matrixLeft, Matrix4 matrixRight);

/**
 * GLKMatrix4MakeXRotation 
 **/
Matrix4 Matrix4MakeXRotation(float radians);

/**
 * GLKMatrix4MakeYRotation 
 **/
Matrix4 Matrix4MakeYRotation(float radians);

/**
 * GLKMatrix4RotateY 
 **/
Matrix4 Matrix4RotateY(Matrix4 matrix, float radians);