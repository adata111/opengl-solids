#include "main.h"

#ifndef SHAPES_H
#define SHAPES_H

static const GLfloat vertex_sd[] = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end
        // bottom back,  bottom back right corner
        0.0f,-2.0f, 0.0f,   // bottom point
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        // cube back bottom right triangle
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        // cube left top left triangle
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        // bottom front, bottom front left corner
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        0.0f,-2.0f, 0.0f,
        
        // bottom left
        -1.0f,-1.0f, -1.0f,
        -1.0f,-1.0f, 1.0f,
        0.0f,-2.0f, 0.0f,

        // bottom right
        1.0f,-1.0f, -1.0f,
        1.0f,-1.0f, 1.0f,
        0.0f,-2.0f, 0.0f,

        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,

        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        // top back, top back right triangle
        0.0f, 2.0f, 0.0f,   // top point
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        // top front, top front left triangle
        1.0f, 1.0f, 1.0f,
        0.0f, 2.0f, 0.0f,   // top point
        -1.0f, 1.0f, 1.0f,

        // top right
        0.0f, 2.0f, 0.0f,   // top point
        1.0f, 1.0f,-1.0f,
        1.0f, 1.0f,1.0f,
        //top left
        -1.0f, 1.0f, -1.0f,
        0.0f, 2.0f, 0.0f,   // top point
        -1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    };
static const GLfloat color_sd[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,

    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,

    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,

    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,

    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,

    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,

    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,

    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,

    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,

    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,

    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,

    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,

    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,

    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,

    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,

    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
};

// pentagonal cupola
/*                    0                                 1                               2                                   3
"vertices":[[-0.973114f,0.120196f,-0.57615f],[-0.844191f,-0.563656f,-0.512814f],[-0.711039f,0.75783f,-0.46202f],[-0.594483f,0.244733f,-0.002202f],
    4                               5                                       6                           7
[-0.46556f,-0.439119f,0.061133f],[-0.373515f,-1.032518f,-0.296206f],[-0.15807f,1.105692f,-0.21402f],[-0.041514f,0.592595f,0.245798f],
        8                                   9                               10                          11  
[0.167087f,-0.513901f,0.348277f],[0.259132f,-1.1073f,-0.009062f],[0.429162f,0.123733f,0.462406f],[0.474577f,1.03091f,0.073124f],
        12                                  13                              14
[0.812101f,-0.759438f,0.238938f],[0.945253f,0.562048f,0.289732f],[1.074175f,-0.121804f,0.353067f]],
"faces":[[4,1,5],[8,9,12],[10,14,13],[7,11,6],[3,2,0],[4,3,0,1],[8,4,5,9],[10,8,12,14],[7,10,13,11],[3,7,6,2],[3,4,8,10,7],[2,6,11,13,14,12,9,5,1,0]]}
*/
static const GLfloat vertex_pc[] = {
    //4,1,5
    -0.46556f,-0.439119f,0.061133f,
    -0.844191f,-0.563656f,-0.512814f,
    -0.373515f,-1.032518f,-0.296206f,

    // 8,9,12
    0.167087f,-0.513901f,0.348277f,
    0.259132f,-1.1073f,-0.009062f,
    0.812101f,-0.759438f,0.238938f,
    // 10,13,14
    0.429162f,0.123733f,0.462406f,
    0.945253f,0.562048f,0.289732f,
    1.074175f,-0.121804f,0.353067f,

    //7,11,6
    -0.041514f,0.592595f,0.245798f,
    0.474577f,1.03091f,0.073124f,
    -0.15807f,1.105692f,-0.21402f,
    //0,2,3
    -0.973114f,0.120196f,-0.57615f,
    -0.711039f,0.75783f,-0.46202f,
    -0.594483f,0.244733f,-0.002202f,
    
    //4,3,0,1
    //0,1,3
    -0.973114f,0.120196f,-0.57615f,
    -0.844191f,-0.563656f,-0.512814f,
    -0.594483f,0.244733f,-0.002202f,
    //1,3,4
    -0.844191f,-0.563656f,-0.512814f,
    -0.594483f,0.244733f,-0.002202f,
    -0.46556f,-0.439119f,0.061133f,
    
    //8,4,5,9
    // 8,4,5
    0.167087f,-0.513901f,0.348277f,
    -0.46556f,-0.439119f,0.061133f,
    -0.373515f,-1.032518f,-0.296206f,
    //8,5,9
    0.167087f,-0.513901f,0.348277f,
    -0.373515f,-1.032518f,-0.296206f,
    0.259132f,-1.1073f,-0.009062f,

    //10,8,12,14
    //10,8,12
    0.429162f,0.123733f,0.462406f,
    0.167087f,-0.513901f,0.348277f,
    0.812101f,-0.759438f,0.238938f,
    //10,12,14
    0.429162f,0.123733f,0.462406f,
    0.812101f,-0.759438f,0.238938f,
    1.074175f,-0.121804f,0.353067f,

    //7,10,13,11
    //7,10,13
    -0.041514f,0.592595f,0.245798f,
    0.429162f,0.123733f,0.462406f,
    0.945253f,0.562048f,0.289732f,
    //7,13,11
    -0.041514f,0.592595f,0.245798f,
    0.945253f,0.562048f,0.289732f,
    0.474577f,1.03091f,0.073124f,

    //3,7,6,2
    //3,7,6
    -0.594483f,0.244733f,-0.002202f,
    -0.041514f,0.592595f,0.245798f,
    -0.15807f,1.105692f,-0.21402f,

    //3,6,2
    -0.594483f,0.244733f,-0.002202f,
    -0.15807f,1.105692f,-0.21402f,
    -0.711039f,0.75783f,-0.46202f,
    
    //3,4,8,10,7
    //3,4,8
    -0.594483f,0.244733f,-0.002202f,
    -0.46556f,-0.439119f,0.061133f,
    0.167087f,-0.513901f,0.348277f,

    //3,8,10
    -0.594483f,0.244733f,-0.002202f,
    0.167087f,-0.513901f,0.348277f,
    0.429162f,0.123733f,0.462406f,

    //3,10,7
    -0.594483f,0.244733f,-0.002202f,
    0.429162f,0.123733f,0.462406f,
    -0.041514f,0.592595f,0.245798f,
    
    //2,6,11,13,14,12,9,5,1,0
    //6,2,0
    -0.15807f,1.105692f,-0.21402f,
    -0.711039f,0.75783f,-0.46202f,
    -0.973114f,0.120196f,-0.57615f,

    //6,11,13
    -0.15807f,1.105692f,-0.21402f,
    0.474577f,1.03091f,0.073124f,
    0.945253f,0.562048f,0.289732f,

    //6,13,14
    -0.15807f,1.105692f,-0.21402f,
    0.945253f,0.562048f,0.289732f,
    1.074175f,-0.121804f,0.353067f,

    //6,14,12
    -0.15807f,1.105692f,-0.21402f,
    1.074175f,-0.121804f,0.353067f,
    0.812101f,-0.759438f,0.238938f,

    //6,12,9
    -0.15807f,1.105692f,-0.21402f,
    0.812101f,-0.759438f,0.238938f,
    0.259132f,-1.1073f,-0.009062f,

    //5,9,6
    -0.373515f,-1.032518f,-0.296206f,
    0.259132f,-1.1073f,-0.009062f,
    -0.15807f,1.105692f,-0.21402f,

    //5,6,1
    -0.373515f,-1.032518f,-0.296206f,
    -0.15807f,1.105692f,-0.21402f,
    -0.844191f,-0.563656f,-0.512814f,

    //6,1,0
    -0.15807f,1.105692f,-0.21402f,
    -0.844191f,-0.563656f,-0.512814f,
    -0.973114f,0.120196f,-0.57615f
};

static const GLfloat color_pc[] = {
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,

    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,

    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,

    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,

    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,

    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,

    0.195f,  0.548f,  0.859f,
    0.559f,  0.861f,  0.639f,
    0.483f,  0.596f,  0.789f,

    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,

    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,

    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,

    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,

    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,

    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,

//square 5
    0.597f,  0.770f,  0.761f,
    0.435f,  0.602f,  0.223f,
    0.559f,  0.436f,  0.130f,

    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.130f,
    0.195f,  0.548f,  0.359f,

//pentagon
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,

    0.483f,  0.596f,  0.789f,
    0.195f,  0.548f,  0.859f,
    0.771f,  0.328f,  0.970f,

    0.483f,  0.596f,  0.789f,
    0.771f,  0.328f,  0.970f,
    0.971f,  0.572f,  0.833f,

//base
    0.195f,  0.548f,  0.859f,
    0.195f,  0.548f,  0.859f,
    0.195f,  0.548f,  0.859f,

    0.483f,  0.596f,  0.789f,
    0.483f,  0.596f,  0.789f,
    0.483f,  0.596f,  0.789f,

    0.483f,  0.596f,  0.789f,
    0.483f,  0.596f,  0.789f,
    0.483f,  0.596f,  0.789f,

    0.483f,  0.596f,  0.789f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,

    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.559f,  0.861f,  0.639f,

    0.559f,  0.861f,  0.639f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,

    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.195f,  0.548f,  0.859f,

    0.195f,  0.548f,  0.859f,
    0.195f,  0.548f,  0.859f,
    0.195f,  0.548f,  0.859f,
};



#endif