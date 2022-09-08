# __OpenGL-Sample__
## __Description__
* This is a repository for OpenGL demo projects I had done.

## __Contents__
* __OpenGLSample__ A cmake project for learning opengl.

## __Third Party Libraries__
* __GLAD__
* __GLFW__
* __GLM__
* __STB_IMAGE__
* __ASSIMP__
* __DEAR_IMGUI__
> All third party libraries are added as __git submodule__ into this project.

## __Installation Instructions__
```
git clone https://github.com/thezzw/OpenGL-Demo.git --recursive
mkdir build
cd build
cmake ..
```
* __OpenGLSample__

    1. Open `build/OpenGLSample.sln` with _Visual Studio_.
    2. Right click one project with **exe_** as the prefix  and select it as start project.
    ![](assets/readme/vs_config_0.png)
    3. Click run button.
    ![](assets/readme/vs_effect_material.gif)
    * __Current effect__:
    1. [Boxes with various lights.](assets/readme/boxes_with_lights.mp4)
    ![](assets/readme/boxes_with_lights.png)
    2. [Load a model from .obj.](assets/readme/model_load.mp4)
    ![](assets/readme/model_load.png)
    3. [Add animated light effect.](assets/readme/animation_light.mp4)
    ![](assets/readme/animation_light.png)
    4. [Add imgui backends.]()
    ![](assets/readme/imgui_demo.png)
    5. [Linear depth image.]()
    ![](assets/readme/linear_depth.png)
    6. [Stencil test.]()
    ![](assets/readme/two_boxes.png)
    6. [Grass with alpha pass.]()
    ![](assets/readme/grass.png)
    6. [Glasses.]()
    ![](assets/readme/glass.png)
    7. [Test kernel functions.]()
    ![](assets/readme/kernel_sharpen.png)
    ![](assets/readme/kernel_blur.png)
    ![](assets/readme/kernel_edge_detection.png)
    8. [Add skybox.]()
    ![](assets/readme/skybox.png)
    9. [Add mirror and glass.]()
    ![](assets/readme/mirror_glass.png)
    10. [Test geometry shader.]()
    ![](assets/readme/geometry_shader_point_house.png)
    11. [Draw asteroids normally.]()
    ![](assets/readme/normal_belt.png)
    12. [Draw 100000 asteroids with instancing.]()
    ![](assets/readme/instance_100000_belt.png)
    13. [Test Blinn-Phong shader model.]()
    ![](assets/readme/blinn_phong.png)
    14. [Shadows.]
    ![acne](assets/readme/shadow_acne.png)
    ![bias](assets/readme/shadow_bias.png)
    ![pcf](assets/readme/shadow_pcf.png)

## __Useful Link__
* [__OpenGL/VRML Materials__](http://devernay.free.fr/cours/opengl/materials.html)
* [__Range Constant Linear Quadratic__](http://www.ogre3d.org/tikiwiki/tiki-index.php?page=-Point+Light+Attenuation)
* [__Wavefront .obj file__](http://en.wikipedia.org/wiki/Wavefront_.obj_file)
* [__COLLADA__](http://en.wikipedia.org/wiki/COLLADA) Based on xml.
* [__Assimp Doc__](http://assimp.sourceforge.net/lib_html/postprocess_8h.html)