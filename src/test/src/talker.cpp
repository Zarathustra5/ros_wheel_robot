#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    // Функция advertise() позволяет сообщить ROS, что вы хотите 
    //      что то опубликовать в приведенный топик
    ros::Publisher chatter_pub = 
        n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);
    int count = 0;    // Кол-во сообщений, которые были отправлены
    while (ros::ok()) {
        // Формирование очередного сообщения
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();
        // Вывод информации в консоль
        ROS_INFO("%s", msg.data.c_str());
        // Отправка очередного сообщения
        chatter_pub.publish(msg);
        // Вызов цикла обработки событий
        ros::spinOnce();
        // Спать до следующей итерации (10 Hz)
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
