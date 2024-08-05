# Scene Markup Documentation

## Basics

Scene markup is a non graphical means of easily writing scallable and malluable rendered scenes using a custom xml.

### Syntax

The basic syntax is as follows:
```xml
<NAME param="val" ... >
    <CHILD_NAME param="val" ... />
</NAME>
```

### Steps

The first step is to declare your scene:
```xml
<scene name="my scene"> /* you may prefer to use camel snake or other cases. They also work. */
</scene>
```

then fill the scene with your objects:
```xml
<scene name="my scene">
    <plane pos="0,0,50" rotation="0,0,0" size="100,100" color="100,100,100" fill="SOLID" >
        <plane pos="50,50,0" rotation="0,0,45" size="5,5" color="255,255,255" fill="WIREFRAME" />
    </plane>
</scene>
```

A couple of things to note here:
- A nested object will have all its parameters relative to its parent. That is, a plane with an x 
  co-ordinate of 5, inside a plane with an x of 10, *will have an absolute x of 15*.
- values are pixels, degrees, and radians.
- The order is always "x,y,z", or for 2d objects: "x,y". Though, 2d objects will still have 
  3 dimentional rotation
- y is the up direction, and z is the direction into the screen

## Documentation Reference

**Object**: 
- param.1: ...
- param.2: ...
- ...

**scene**:
- name="name": The scene name

**plane**:
- pos="x,y,z": The start position of the top left corner of the plane
- rotation="x,y,z": the rotation in degrees on each axis
- size="x,y": the size in pixels
- color="r,g,b": ... come on
- fill="FILL_TYPE": specifies the kind of fill the object should have:
    - SOLID: filled in
    - DOTTED: dotted line, no fill
    - WIREFRAME: wireframe

**box**:
**bubble**:
**elipse**:
**cylinder**:
    

