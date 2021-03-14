#include "ball.h"
#include "main.h"
#include "shapes.h"
#include "input.h"

Ball::Ball(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.05f;
    if(id==0)
    this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_sd, color_sd, GL_FILL);
    else if(id==1)
    this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_pa, color_pc, GL_FILL);
    else if(id==2)
    this->object = create3DObject(GL_TRIANGLES, 26*3, vertex_pc, color_pc, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (-this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(prev_id!=id){
        std::cout<<"switch\n";
        if(id==0)
            this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_sd, color_sd, GL_FILL);
        else if(id==1)
            this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_pa, color_pc, GL_FILL);
        else if(id==2)
            this->object = create3DObject(GL_TRIANGLES, 26*3, vertex_pc, color_pc, GL_FILL);
    }
    draw3DObject(this->object);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

void Ball::right(){
    this->position.x += speed;
}
void Ball::left(){
    this->position.x -= speed;
}
void Ball::up(){
    this->position.y += speed;
}
void Ball::down(){
    this->position.y -= speed;
}
void Ball::out(){
    this->position.z += speed;
}
void Ball::in(){
    this->position.z -= speed;
}

void Ball::spin(){
    this->rotation += 1;
}

