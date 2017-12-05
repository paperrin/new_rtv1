# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paperrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 23:22:26 by paperrin          #+#    #+#              #
#    Updated: 2017/12/05 19:22:10 by paperrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 2.8)

project(rtv1)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libft)

find_package(OpenGL REQUIRED)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/libft/include
	${CMAKE_CURRENT_SOURCE_DIR}/glfw/include
	${OPENGL_INCLUDE_DIR}
)

SET(SRC_FILES
	src/graphics/window.c
	src/graphics/window_render.c
	src/graphics/window_callback.c
	src/graphics/window_callback_key.c
	src/graphics/window_callback_mouse_motion.c
	src/graphics/window_callback_mouse_button.c
	src/graphics/window_callback_mouse_scroll.c
	src/graphics/image.c
	src/main.c
	src/event.c
	src/camera.c
	src/camera_render.c
	src/render.c
	src/solve_quadratic.c
	src/obj_f.c
	src/obj_sphere.c
	src/obj_cylinder.c
	src/obj_plane.c
)
add_executable(rtv1 ${SRC_FILES})

target_link_libraries(rtv1
	ft
	glfw
	${OPENGL_glu_LIBRARY}
)
