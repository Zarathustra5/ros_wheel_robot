#include "ros/ros.h"
#include "std_msgs/String.h"
// Функция обработки сообщений
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
int main(int argc, char **argv)
{
    // Инициализация узла listener
    ros::init(argc, argv, "listener");
    // NodeHandle - это основная точка доступа к системе ROS.
    ros::NodeHandle n;
    // Функция subscribe() позволяет подписаться на топик, # и указать функцию которая будет вызываться # при получении сообщений
    ros::Subscriber sub = 
	n.subscribe("chatter", 1000, chatterCallback);
    // Запуск цикла обработки событий
    ros::spin();
    return 0;
}
