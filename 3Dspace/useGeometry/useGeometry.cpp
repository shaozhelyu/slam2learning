/*
 * @Author: your name
 * @Date: 2021-06-22 17:19:40
 * @LastEditTime: 2021-07-01 11:29:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /3Dspace/useGeometry/useGeometry.cpp
 */
#include <iostream>
#include <cmath>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main(int argc, char **argv){
    Matrix3d rotation_matrix = Matrix3d::Identity();
    // rotate 45 with z axis
    AngleAxisd rotation_vector(M_PI/4,Vector3d(0,0,1));
    
    cout.precision(3);
    cout << "rotation matrix =\n" << rotation_vector.matrix() << endl;
    
    rotation_matrix = rotation_vector.toRotationMatrix();
    
    Vector3d v(1,0,0);
    Vector3d v_rotated = rotation_vector*v;
    
    cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
    
    Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0); // z y x
    
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;
    
    Isometry3d T = Isometry3d::Identity();
    cout << "Transform matrix = \n" << T.matrix() << endl;
    T.rotate(rotation_vector);
    T.pretranslate(Vector3d(1,3,4));
    cout << "Transform matrix = \n" << T.matrix() << endl;
    
    Vector3d v_transformed = T*v;
    cout << "v transformed = " << v_transformed.transpose() << endl;
    
    Quaterniond q = Quaterniond(rotation_vector);
    
    cout << "quaternion from roration vector = " << q.coeffs().transpose() << endl;
    
    q = Quaterniond(rotation_matrix);
    cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl;
    
    v_rotated = q*v;
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
    
    cout << "should be equal to " << (q*Quaterniond(0,1,0,0) * q.inverse()).coeffs().transpose() << endl;
    
    return 0;
}
