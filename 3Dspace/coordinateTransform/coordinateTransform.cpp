/*
 * @Author: your name
 * @Date: 2021-07-01 11:56:46
 * @LastEditTime: 2021-07-01 12:00:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /slam/3Dspace/coordinateTransform/coordinateTransform.cpp
 */
#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv){
    Vector3d t1(0.3,0.1,0.1), t2(-0.1,0.5,0.3),pr(0.5,0,0.2);
    Quaterniond q1(0.35,0.2,0.3,0.1),q2(-0.5,0.4,-0.1,0.2);
    q1.normalize();
    q2.normalize();
    
//     Isometry3d T1w(q1), T2w(q2);
     Isometry3d T1w = Isometry3d::Identity();
     Isometry3d T2w = Isometry3d::Identity();
//      T1w.rotate(q1);
//      T2w.rotate(q2);
     T1w.translate(t1);
     T2w.translate(t2); 
     T1w.rotate(q1);
     T2w.rotate(q2);
//     T1w.pretranslate(t1);
//     T2w.pretranslate(t2);
    
    Vector3d p2 = T2w*T1w.inverse()*pr;
    cout << endl << "new" << p2.transpose() << endl;
    return 0;
}
