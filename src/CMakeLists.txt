set(APP_NAME minimal_glfw_bullet)

set(demo_src
	GL_ShapeDrawer.cpp
	GL_ShapeDrawer.h

	importer/tiny_obj_loader.cpp
	importer/tiny_obj_loader.h

	imagedata.h
	imagedata.cpp

	glshader.h
	glshader.cpp
	
	glmeshdata.h
	glmeshdata.cpp

	../src_extern/gltb/gltb.cpp
	../src_extern/glmodel/glm_util.c
	../src_extern/glmodel/glm.c
	../src_extern/glmodel/glmimg.c
	../src_extern/glmodel/glmimg_devil.c
	../src_extern/glmodel/glmimg_jpg.c
	../src_extern/glmodel/glmimg_png.c
	../src_extern/glmodel/glmimg_sdl.c
	../src_extern/glmodel/glmimg_sim.c
	../src_extern/glmodel/glmint.h


)

add_executable(${APP_NAME} main.cpp  ${demo_src})
#add_executable(${APP_NAME} smooth.cpp  ${demo_src})

include_directories(/usr/local/include)
include_directories(/usr/local/include)

include_directories(../src_extern/gltb)
include_directories(../src_extern/glmodel)

target_link_libraries(${APP_NAME} glfw glew OpenGL::GL /usr/local/lib/libpng.a -L/usr/local/opt/zlib/lib/lib z)
target_link_libraries(${APP_NAME} ${Vulkan_LIBRARIES})
target_link_libraries(${APP_NAME} "-framework GLUT")

add_definitions(-DHAVE_LIBPNG)

target_include_directories(${APP_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

source_group("sources" FILES main.cpp)
source_group("sources\\util" FILES ${demo_src})

set(BULLET_ROOT "/Users/nicholasnewdigate/Development/github/bullet3") # where to find Bullet
set(BULLET_DYNAMICS_LIBRARY "/usr/local/lib/libBulletDynamics_xcode4_x64_debug.a") # where to find Bullet
set(BULLET_COLLISION_LIBRARY "/usr/local/lib/libBulletCollision_xcode4_x64_debug.a") # where to find Bullet
set(BULLET_MATH_LIBRARY "/usr/local/lib/libLinearMath_xcode4_x64_debug.a") # where to find Bullet
set(BULLET_SOFTBODY_LIBRARY "/usr/local/lib/libBulletSoftBody_xcode4_x64_debug.a") # where to find Bullet

find_package(Bullet REQUIRED)
target_link_libraries(${APP_NAME}  ${BULLET_LIBRARIES})
target_include_directories(${APP_NAME} PUBLIC ${BULLET_INCLUDE_DIR})
