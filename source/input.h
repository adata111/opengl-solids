
#ifndef INPUTS_H
#define INPUTS_H

// camera movement
extern bool a;
extern bool s;
extern bool d;
extern bool w;
// camera zoom in and zoom out
extern bool z;
extern bool x;
// camera rotate about object
extern bool c;

// object movement
extern bool key_up;
extern bool key_down;
extern bool key_left;
extern bool key_right;
// object move out and in
extern bool o;
extern bool i;
// object spin
extern bool b;

// throw camera up to (0,5,0)
extern bool u;
// throw camera left to (-5,0,0)
extern bool l;
// throw camera front to (0,0,5)
extern bool n;

// Object
// Ball ball1;

// //Camera specs
// glm::vec3 line_of_sight (0, 0, -1);
// glm::vec3 eye (0,0,3);
// glm::vec3 up (0, 1, 0);  // always in xy plane
// const float cameraSpeed = 0.05f;

#endif // INPUTS_H
