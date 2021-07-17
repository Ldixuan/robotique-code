# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "mr_control: 0 messages, 1 services")

set(MSG_I_FLAGS "")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(mr_control_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv" NAME_WE)
add_custom_target(_mr_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "mr_control" "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(mr_control
  "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mr_control
)

### Generating Module File
_generate_module_cpp(mr_control
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mr_control
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(mr_control_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(mr_control_generate_messages mr_control_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv" NAME_WE)
add_dependencies(mr_control_generate_messages_cpp _mr_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mr_control_gencpp)
add_dependencies(mr_control_gencpp mr_control_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mr_control_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(mr_control
  "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/mr_control
)

### Generating Module File
_generate_module_eus(mr_control
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/mr_control
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(mr_control_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(mr_control_generate_messages mr_control_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv" NAME_WE)
add_dependencies(mr_control_generate_messages_eus _mr_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mr_control_geneus)
add_dependencies(mr_control_geneus mr_control_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mr_control_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(mr_control
  "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mr_control
)

### Generating Module File
_generate_module_lisp(mr_control
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mr_control
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(mr_control_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(mr_control_generate_messages mr_control_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv" NAME_WE)
add_dependencies(mr_control_generate_messages_lisp _mr_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mr_control_genlisp)
add_dependencies(mr_control_genlisp mr_control_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mr_control_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(mr_control
  "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/mr_control
)

### Generating Module File
_generate_module_nodejs(mr_control
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/mr_control
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(mr_control_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(mr_control_generate_messages mr_control_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv" NAME_WE)
add_dependencies(mr_control_generate_messages_nodejs _mr_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mr_control_gennodejs)
add_dependencies(mr_control_gennodejs mr_control_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mr_control_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(mr_control
  "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mr_control
)

### Generating Module File
_generate_module_py(mr_control
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mr_control
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(mr_control_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(mr_control_generate_messages mr_control_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dixuan/Document/robotique/controle/robotics_courses/src/mr_control/srv/Goal.srv" NAME_WE)
add_dependencies(mr_control_generate_messages_py _mr_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mr_control_genpy)
add_dependencies(mr_control_genpy mr_control_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mr_control_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mr_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mr_control
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/mr_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/mr_control
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mr_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mr_control
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/mr_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/mr_control
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mr_control)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mr_control\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mr_control
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
