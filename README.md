# __OpenGL-Demo__
## __Description__
* This is a repository for OpenGL demo projects I had done.

## __Contents__
* __OpenGLDemo__ A cmake project for learning opengl.

## __Third Party Libraries__
* __GLAD__
* __GLFW__
* __GLM__
* __STB_IMAGE__
* __ASSIMP__ Open Asset Import Library
> All third party libraries are added as __git submodule__ into this project.

## __Installation Instructions__
```
git clone https://github.com/thezzw/OpenGL-Demo.git
mkdir build
cd build
cmake ..
```
* __OpenGLDemo__

    1. Open `build/OpenGLDemo.sln` with _Visual Studio_.
    2. Right click OpenGLDemo and select as start project.
    ![](assets/readme/vs_config_0.png)
    3. Click run button.
    ![](assets/readme/vs_effect_material.gif)
    * __Current effect__:
    1. [Boxes with various lights.](assets/readme/boxes_with_lights.mp4)
    ![](assets/readme/boxes_with_lights.png)
    2. [Load a model from .obj.](assets/readme/model_load.mp4)
    ![](assets/readme/model_load.png)
    * __Tips__: This project is using _Visual Studio 2022_ default charset _GB2312_, so if you open it with other IDE you may see some unreadable code. Just change your charset to _GB2312_ and you'll see those chinese annotations.

## __Useful Link__
* [__OpenGL/VRML Materials__](http://devernay.free.fr/cours/opengl/materials.html)
* [__Range Constant Linear Quadratic__](http://www.ogre3d.org/tikiwiki/tiki-index.php?page=-Point+Light+Attenuation)
* [__Wavefront .obj file__](http://en.wikipedia.org/wiki/Wavefront_.obj_file)
* [__COLLADA__](http://en.wikipedia.org/wiki/COLLADA) Based on xml.
* [__Assimp Doc__](http://assimp.sourceforge.net/lib_html/postprocess_8h.html)