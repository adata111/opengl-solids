#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"
#include "input.h"

bool   cannon_keyboard_input = true;
bool   drag_pan = false, old_cki;
double drag_oldx = -1, drag_oldy = -1;

// camera movement
bool a = false;
bool s = false;
bool d = false;
bool w = false;
// camera zoom in and zoom out
bool z = false;
bool x = false;
// camera rotate about object
bool c = false;

// object movement
bool key_up = false;
bool key_down = false;
bool key_left = false;
bool key_right = false;
// object move out and in
bool o = false;
bool i = false;
// object spin
bool b = false;

// throw camera up to (0,5,0)
bool u = false;
// throw camera left to (-5,0,0)
bool l = false;
// throw camera front to (0,0,5)
bool n = false;


using namespace std;

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods) {
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        switch (key) {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        case GLFW_KEY_A:
            a = false;
            break;
        case GLFW_KEY_S:
            s = false;
            break;
        case GLFW_KEY_D:
            d = false;
            break;
        case GLFW_KEY_W:
            w = false;
            break;
        case GLFW_KEY_Z:
            z = false;
            break;
        case GLFW_KEY_X:
            x = false;
            break;
        case GLFW_KEY_C:
            c = false;
            break;
            
        case GLFW_KEY_UP:
            key_up = false;
            break;
        case GLFW_KEY_DOWN:
            key_down = false;
            break;
        case GLFW_KEY_RIGHT:
            key_right = false;
            break;
        case GLFW_KEY_LEFT:
            key_left = false;
            break;
        case GLFW_KEY_O:
            o = false;
            break;
        case GLFW_KEY_I:
            i = false;
            break;
        case GLFW_KEY_B:
            b = false;
            break;
            
        case GLFW_KEY_U:
            u = false;
            break;
        case GLFW_KEY_L:
            l = false;
            break;
        case GLFW_KEY_N:
            n = false;
            break;
        default:
            break;
        }
    } else if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        case GLFW_KEY_A:
            a = true;
            break;
        case GLFW_KEY_S:
            s = true;
            break;
        case GLFW_KEY_D:
            d = true;
            break;
        case GLFW_KEY_W:
            w = true;
            break;
        case GLFW_KEY_Z:
            z = true;
            break;
        case GLFW_KEY_X:
            x = true;
            break;
        case GLFW_KEY_C:
            c = true;
            break;
            
        case GLFW_KEY_UP:
            key_up = true;
            break;
        case GLFW_KEY_DOWN:
            key_down = true;
            break;
        case GLFW_KEY_RIGHT:
            key_right = true;
            break;
        case GLFW_KEY_LEFT:
            key_left = true;
            break;
        case GLFW_KEY_O:
            o = true;
            break;
        case GLFW_KEY_I:
            i = true;
            break;
        case GLFW_KEY_B:
            b = true;
            break;
            
        case GLFW_KEY_U:
            u = true;
            break;
        case GLFW_KEY_L:
            l = true;
            break;
        case GLFW_KEY_N:
            n = true;
            break;

        case GLFW_KEY_SPACE:
            id++;
            id = id%5;
        default:
            break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar(GLFWwindow *window, unsigned int key) {
    switch (key) {
    case 'Q':
    case 'q':
        quit(window);
        break;
    default:
        break;
    }
}

/* Executed when a mouse button is pressed/released */
void mouseButton(GLFWwindow *window, int button, int action, int mods) {
    switch (button) {
    case GLFW_MOUSE_BUTTON_LEFT:
        if (action == GLFW_PRESS) {
            // Do something
            return;
        } else if (action == GLFW_RELEASE) {
            // Do something
        }
        break;
    // case GLFW_MOUSE_BUTTON_RIGHT:
    // if (action == GLFW_RELEASE) {
    // rectangle_rot_dir *= -1;
    // }
    // break;
    default:
        break;
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    // Do something
}
