#include <stdio.h>
#include <math.h>
#include "Mat4.h"

/**
 * GLKitを基にCでVRで必要な箇所書き直し
 **/
int main(void){
    // 動作確認用
    // 4D Matrix
    Matrix4 mat4 = Matrix4Make(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    printf("4D Matrix: %lf\n", mat4.m00);
    
    // X Rotation Matrix
    Matrix4 xRot = Matrix4MakeXRotation(3.14/2);
    printf("X Rotation Matrix: %lf\n", xRot.m00);
    
    // Y Rotaion Matrix
    Matrix4 yRot = Matrix4MakeYRotation(3.14/2);
    printf("Y Rotation Matrix: %lf\n", yRot.m00);
    
    // Multiply
    Matrix4 mul = Matrix4Multiply(xRot, yRot);
    printf("Multiply: %lf\n", mul.m00);
    
    // Y Rotation
    Matrix4 yRot2 = Matrix4RotateY(mul, 3.14/2);
    printf("Y Rotation: %lf\n", yRot2.m00);
    
    return 0;
}
