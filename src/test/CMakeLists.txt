cmake_minimum_required(VERSION 2.8.3)
project(test) # Имя проекта (должно соответствовать указанному в package.xml)
# Поиск зависимостей
find_package(catkin REQUIRED COMPONENTS
  rospy     # Для использования Python
  roscpp    # Для использования C++
)
catkin_package(CATKIN_DEPENDS rospy roscpp)
# Перечисление Python-скриптов для установки
catkin_install_python(PROGRAMS
  nodes/listener.py
  nodes/talker.py
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/nodes
)
# C++ часть. Настройка include-директорий для исполняемых файлов
include_directories(${catkin_INCLUDE_DIRS})
# Настройка C++ listener
add_executable(cpp_listener src/listener.cpp) # Исполняемый файл и его исходники
target_link_libraries(cpp_listener ${catkin_LIBRARIES}) # Подключаемые библиотеки
install(TARGETS cpp_listener  # Установка исполняемого файла
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
# Настройка C++ talker
add_executable(cpp_talker src/talker.cpp)
target_link_libraries(cpp_talker ${catkin_LIBRARIES})
install(TARGETS cpp_talker
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
