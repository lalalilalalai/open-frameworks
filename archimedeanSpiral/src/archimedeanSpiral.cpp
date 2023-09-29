#include "archimedeanSpiral.h"

archimedeanSpiral::archimedeanSpiral(){
}

void archimedeanSpiral::setup(){
}

void archimedeanSpiral::update(float offset_x, float offset_y, float scale, float rotationAngle){
    dsk.clear();
    polyline.clear();
    
    float fi = 0;
    float k = 1 / (M_PI * 2);
    float incAng = M_PI / 32;
    float maxAngle = 32 * M_PI;
    
    
    while (fi <= maxAngle + incAng) {
        float ro = fi * k;
        float x = cos(fi) * ro;
        float y = sin(fi) * ro;
        dsk.push_back(ofVec2f(x * scale + offset_x, y * scale + offset_y));
        //        std::cout << "ro;fi" << std::endl;
        //        std::cout << ro << ";" << fi*180/M_PI << std::endl;
        //        std::cout << "y;x" << std::endl;
        //        std::cout << y << ";" << x << std::endl;
        //        std::cout << x << ";" << y << std::endl;
        fi += incAng;
    }
    
    for (ofVec2f v : dsk) {
        polyline.curveTo(v.x, v.y);
    }
    
    this -> rotationAngle += rotationAngle; // Incrementally increase the rotation angle
    // Translate polyline to the origin
    polyline.translate(-glm::vec3(offset_x, offset_y, 0));
    
    // Rotate around Z axis
    polyline.rotateRad(this -> rotationAngle, glm::vec3(0, 0, 1));
    
    // Translate polyline back
    polyline.translate(glm::vec3(offset_x, offset_y, 0));
    
}

void archimedeanSpiral::draw(){
    polyline.draw();
}
