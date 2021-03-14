#include "main.h"
#include "timer.h"
#include "ball.h"
#include "input.h"
#include <glm/gtx/string_cast.hpp>

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;
int id = 0;
int prev_id = 0;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
float fov = 100.0f;
glm::vec3 line_of_sight (0, 0, -1);
glm::vec3 eye (0,0,3);
glm::vec3 up (0, 1, 0);  // always in xy plane

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    
    glm::vec3 target = eye + line_of_sight;
    // cout<<"target "<<glm::to_string(target)<<endl;
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    // glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    
    // Matrices.projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);  
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    ball1.draw(VP);
}

void tick_input(GLFWwindow *window) {
    // int key_left  = glfwGetKey(window, GLFW_KEY_LEFT);
    // int key_right = glfwGetKey(window, GLFW_KEY_RIGHT);
    // int key_up = glfwGetKey(window, GLFW_KEY_UP);
    // int key_down = glfwGetKey(window, GLFW_KEY_DOWN);
    // int o = glfwGetKey(window, GLFW_KEY_O);
    // int i = glfwGetKey(window, GLFW_KEY_I);
    // int b = glfwGetKey(window, GLFW_KEY_B);
    
    // // int a = glfwGetKey(window, GLFW_KEY_A);
    // int d = glfwGetKey(window, GLFW_KEY_D);
    // int s = glfwGetKey(window, GLFW_KEY_S);
    // int w = glfwGetKey(window, GLFW_KEY_W);
    // int z = glfwGetKey(window, GLFW_KEY_Z);
    // int x = glfwGetKey(window, GLFW_KEY_X);
    // int c = glfwGetKey(window, GLFW_KEY_C);
    
    // int u = glfwGetKey(window, GLFW_KEY_U);
    // int l = glfwGetKey(window, GLFW_KEY_L);
    // int n = glfwGetKey(window, GLFW_KEY_N);
    const float cameraSpeed = 0.05f;
    if (key_right== GLFW_PRESS) {
        // Do something
        ball1.right();
        // key_right = false;
        // eye += glm::normalize(glm::cross(line_of_sight, up)) * cameraSpeed;
        // screen_center_x += 1;
    }
    else if (key_left== GLFW_PRESS) {
        ball1.left();
        // key_left = false;
        // eye += glm::normalize(glm::cross(line_of_sight, -up)) * cameraSpeed;
    }
    else if (key_up== GLFW_PRESS) {
        ball1.up();
        // key_up = false;
        // eye += up * cameraSpeed;
    }
    else if (key_down) {
        ball1.down();
        // key_down = false;
        // eye += -up * cameraSpeed;
    }
    else if (o) {
        ball1.out();
        // o = false;
    }
    else if (i) {
        ball1.in();
        // i = false;
    }
    else if (b) {
        ball1.spin();
        // b = false;
    }

    else if (a) {
        eye += glm::normalize(glm::cross(line_of_sight, -up)) * cameraSpeed;
        // a = false;
    }
    else if (d) {
        eye += glm::normalize(glm::cross(line_of_sight, up)) * cameraSpeed;
        // d = false;
    }
    else if (w) {
        eye += up * cameraSpeed;
        // w = false;
    }
    else if (s) {
        eye += -up * cameraSpeed;
        // s = false;
    }
    else if (x) {
        eye += -line_of_sight * cameraSpeed;
        // x = false;
        // cout<<"eye "<<glm::to_string(eye)<<endl;
        // fov -= 0.1;
        // if (fov < 1.0f)
        //     fov = 1.0f;
        // if (fov > 145.0f)
        //     fov = 145.0f;
        // screen_zoom -= 0.9;
    }
    else if (z) {
        eye += line_of_sight * cameraSpeed;
        // z = false;
        //  fov += 0.1;
        // if (fov < 1.0f)
        //     fov = 1.0f;
        // if (fov > 145.0f)
        //     fov = 145.0f;
    }
    else if (c) {
        camera_rotation_angle += 1;
        glm::vec3 temp = eye;
        eye += glm::normalize(glm::cross(line_of_sight, up))*cameraSpeed;
        line_of_sight = glm::normalize(ball1.position-eye);
        // c = false;
    }

    else if (u){
        eye = glm::vec3 (0,5,0);
        line_of_sight = glm::normalize(ball1.position-eye);
        if(line_of_sight.x == 0 && line_of_sight.y == 0 && line_of_sight.z == 0 ){
            line_of_sight = glm::vec3(0,-1,0);
        }
         // on cross multiplying with this vector we'll get a vector in xy plane that is perpendicular to line of sight
        glm::vec3 vect = line_of_sight + glm::vec3(0,0,1);
        up = glm::normalize(glm::cross(line_of_sight, vect));
        // up = glm::vec3(0,0,-1);
        // u = false;
    }
    else if (l) {
        eye = glm::vec3 (-5,0,0);
        line_of_sight = glm::normalize(ball1.position-eye);
        if(line_of_sight.x == 0 && line_of_sight.y == 0 && line_of_sight.z == 0 ){
            line_of_sight = glm::vec3(1,0,0);
        }
         // on cross multiplying with this vector we'll get a vector in xy plane that is perpendicular to line of sight
        glm::vec3 vect = line_of_sight + glm::vec3(0,0,1);
        up = glm::normalize(glm::cross(line_of_sight, vect));
        // up = glm::vec3 (0,1,0);
        // l = false;
    }
    else if (n) {
        eye = glm::vec3 (0,0,5);
        line_of_sight = glm::normalize(ball1.position-eye);
        if(line_of_sight.x == 0 && line_of_sight.y == 0 && line_of_sight.z == 0 ){
            line_of_sight = glm::vec3(0,0,-1);
        }
         // on cross multiplying with this vector we'll get a vector in xy plane that is perpendicular to line of sight
        glm::vec3 vect = line_of_sight + glm::vec3(0,0,1);
        if(line_of_sight.x == 0 && line_of_sight.y==0){
            vect += glm::vec3(1,0,0);
        }
        else if(line_of_sight.z==0){
            vect += glm::vec3(0,0,1);
        }
        
        // up = glm::vec3 (0,1,0);
        up = glm::normalize(glm::cross(line_of_sight, vect));
        if(up.y < 0){
            up = -up;
        }
        // cout<<"up "<<glm::to_string(up)<<endl;
        // cout<<"los "<<glm::to_string(line_of_sight)<<endl;
        
        // up = glm::vec3(0,0,0) - up;
        // n = false;
    }
}

void tick_elements() {
    ball1.tick();
    camera_rotation_angle += 1*0.2;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    ball1       = Ball(0, 0, 0);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("../source/shaders/shader.vert", "../source/shaders/shader.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 800;
    int height = 800;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            // tick_elements();
            tick_input(window);
            prev_id = id;
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
