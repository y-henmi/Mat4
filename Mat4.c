#include "Mat4.h"

/**
 * GLKMatrix4Make
 **/
Matrix4 Matrix4Make(float m00, float m01, float m02, float m03,
                    float m10, float m11, float m12, float m13,
                    float m20, float m21, float m22, float m23,
                    float m30, float m31, float m32, float m33)
{
    Matrix4 m = { m00, m01, m02, m03,
                  m10, m11, m12, m13,
                  m20, m21, m22, m23,
                  m30, m31, m32, m33 };
    return m;
}

/**
 * GLKMatrix4MakeWithArray
 **/
Matrix4 Matrix4MakeWithArray(float values[16])
{
    Matrix4 m = { values[0], values[1], values[2], values[3],
                  values[4], values[5], values[6], values[7],
                  values[8], values[9], values[10], values[11],
                  values[12], values[13], values[14], values[15] };
    return m;
}

/**
 * GLKMatrix4Multiply
 **/
Matrix4 Matrix4Multiply(Matrix4 matrixLeft, Matrix4 matrixRight)
{
    Matrix4 m;
    
    m.m[0]  = matrixLeft.m[0] * matrixRight.m[0]  + matrixLeft.m[4] * matrixRight.m[1]  + matrixLeft.m[8] * matrixRight.m[2]   + matrixLeft.m[12] * matrixRight.m[3];
    m.m[4]  = matrixLeft.m[0] * matrixRight.m[4]  + matrixLeft.m[4] * matrixRight.m[5]  + matrixLeft.m[8] * matrixRight.m[6]   + matrixLeft.m[12] * matrixRight.m[7];
    m.m[8]  = matrixLeft.m[0] * matrixRight.m[8]  + matrixLeft.m[4] * matrixRight.m[9]  + matrixLeft.m[8] * matrixRight.m[10]  + matrixLeft.m[12] * matrixRight.m[11];
    m.m[12] = matrixLeft.m[0] * matrixRight.m[12] + matrixLeft.m[4] * matrixRight.m[13] + matrixLeft.m[8] * matrixRight.m[14]  + matrixLeft.m[12] * matrixRight.m[15];
    
    m.m[1]  = matrixLeft.m[1] * matrixRight.m[0]  + matrixLeft.m[5] * matrixRight.m[1]  + matrixLeft.m[9] * matrixRight.m[2]   + matrixLeft.m[13] * matrixRight.m[3];
    m.m[5]  = matrixLeft.m[1] * matrixRight.m[4]  + matrixLeft.m[5] * matrixRight.m[5]  + matrixLeft.m[9] * matrixRight.m[6]   + matrixLeft.m[13] * matrixRight.m[7];
    m.m[9]  = matrixLeft.m[1] * matrixRight.m[8]  + matrixLeft.m[5] * matrixRight.m[9]  + matrixLeft.m[9] * matrixRight.m[10]  + matrixLeft.m[13] * matrixRight.m[11];
    m.m[13] = matrixLeft.m[1] * matrixRight.m[12] + matrixLeft.m[5] * matrixRight.m[13] + matrixLeft.m[9] * matrixRight.m[14]  + matrixLeft.m[13] * matrixRight.m[15];
    
    m.m[2]  = matrixLeft.m[2] * matrixRight.m[0]  + matrixLeft.m[6] * matrixRight.m[1]  + matrixLeft.m[10] * matrixRight.m[2]  + matrixLeft.m[14] * matrixRight.m[3];
    m.m[6]  = matrixLeft.m[2] * matrixRight.m[4]  + matrixLeft.m[6] * matrixRight.m[5]  + matrixLeft.m[10] * matrixRight.m[6]  + matrixLeft.m[14] * matrixRight.m[7];
    m.m[10] = matrixLeft.m[2] * matrixRight.m[8]  + matrixLeft.m[6] * matrixRight.m[9]  + matrixLeft.m[10] * matrixRight.m[10] + matrixLeft.m[14] * matrixRight.m[11];
    m.m[14] = matrixLeft.m[2] * matrixRight.m[12] + matrixLeft.m[6] * matrixRight.m[13] + matrixLeft.m[10] * matrixRight.m[14] + matrixLeft.m[14] * matrixRight.m[15];
    
    m.m[3]  = matrixLeft.m[3] * matrixRight.m[0]  + matrixLeft.m[7] * matrixRight.m[1]  + matrixLeft.m[11] * matrixRight.m[2]  + matrixLeft.m[15] * matrixRight.m[3];
    m.m[7]  = matrixLeft.m[3] * matrixRight.m[4]  + matrixLeft.m[7] * matrixRight.m[5]  + matrixLeft.m[11] * matrixRight.m[6]  + matrixLeft.m[15] * matrixRight.m[7];
    m.m[11] = matrixLeft.m[3] * matrixRight.m[8]  + matrixLeft.m[7] * matrixRight.m[9]  + matrixLeft.m[11] * matrixRight.m[10] + matrixLeft.m[15] * matrixRight.m[11];
    m.m[15] = matrixLeft.m[3] * matrixRight.m[12] + matrixLeft.m[7] * matrixRight.m[13] + matrixLeft.m[11] * matrixRight.m[14] + matrixLeft.m[15] * matrixRight.m[15];
    
    return m;
}

/**
 * GLKMatrix4MakeXRotation
 **/
Matrix4 Matrix4MakeXRotation(float radians)
{
    float c = cosf(radians);
    float s = sinf(radians);
    
    Matrix4 m = { 1.0f, 0.0f, 0.0f, 0.0f,
                  0.0f, c, s, 0.0f,
                  0.0f, -s, c, 0.0f,
                  0.0f, 0.0f, 0.0f, 1.0f };
    
    return m;
}

/**
 * GLKMatrix4MakeYRotation
 **/
Matrix4 Matrix4MakeYRotation(float radians)
{
    float c = cosf(radians);
    float s = sinf(radians);
    
    Matrix4 m = { c, 0.0f, -s, 0.0f,
                  0.0f, 1.0f, 0.0f, 0.0f,
                  s, 0.0f, c, 0.0f,
                  0.0f, 0.0f, 0.0f, 1.0f };
    
    return m;
}

/**
 * GLKMatrix4RotateY
 **/
Matrix4 Matrix4RotateY(Matrix4 matrix, float radians)
{
    Matrix4 rm = Matrix4MakeYRotation(radians);
    return Matrix4Multiply(matrix, rm);
}
