#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    void right();
    void left();
    void up();
    void down();
    void in();
    void out();
    void spin();
    double speed;
private:
    VAO *object;
};

#endif // BALL_H
