gnome-terminal -- bash -c "cd ~/catkin_ws/ && roslaunch myrobot_control control.launch"
sleep 5s
gnome-terminal -- bash -c "cd ~/catkin_ws/ && roslaunch myrobot_simulator gazebo_testwalls.launch"
gnome-terminal -- bash -c "cd ~/catkin_ws/ && roslaunch myrobot_description rviz.launch"
gnome-terminal -- bash -c "rqt --clear-config"