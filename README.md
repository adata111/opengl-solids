# Dodecahedrons
Created 5 dodecahedrons in OpenGL
1. Elongated square dipyramid
2. Pentagonal antiprism
3. Pentagonal cupola
4. Small stellated dodecahedron
5. Great stellated dodecahedron

Different dodecadrons can be viewed by pressing `spacebar`

## My story :)
So once upon a time we were all on campus and I was sitting in my hostel room(Elongated square dipyramid) doing my Graphics assignment when my friend chucked me out of the room and forced me to go to JC (yes, I had to be forced to go to JC). We went to JC and met the rest of the gang. We luckily got our favourite table (pentagonal antiprism) at JC. We were engaging in our favourite activities: discussing random nonsense and creating new records for the fastest time to drink a glass of nimboo paani (obviously I was just spectating xD). One of my friends then showed us a ring she got from her crush. It had a beautiful gem(pentagonal cupola) on it. We were admiring the ring when we noticed a star-like object(small stellated dodecahedron) approaching JC. It looked beautiful but it came closer and we realized how huge it was. Soon we were chased out of JC and the campus by the giant spiky object (great stellated dodecahedron) that we now know as Coronavirus :(

## Movement
### Shapes
- Right, left, up and down using the respective arrow keys
- Outward and inward (movement along z axis) using `O` and `I` keys respectively
- To make the object spin about its x axis: `B`

### Camera
- Right, left, up and down using `D`, `A`, `W` and `S` respectively
- Outward and inward (movement along z axis) using `Z` and `X` keys respectively
- To make the camera rotate about the object: `C`
  Note: The object is positioned at the centre of the screen before the camera starts rotating about it
- To change the position of the camera to (0,5,0): `U`
- To change the position of the camera to (-5,0,0): `L`
- To change the position of the camera to (0,0,5): `N`

## To run
- Run the following commands in the main directory:
```bash
mkdir build
cd build
cmake ..
make
./My-Shapes
```
