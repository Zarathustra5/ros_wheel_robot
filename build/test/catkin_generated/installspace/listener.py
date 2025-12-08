#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
# Функция обработки сообщений
def callback(data):
    rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.data)
def listener():
    # Инициализация узла listener
    rospy.init_node('listener', anonymous=True)
    # Функция Subscriber() позволяет подписаться на топик, 
    # и указать функцию которая будет вызываться 
    # при получении сообщений
    rospy.Subscriber('chatter', String, callback)
    # Запуск цикла обработки событий
    rospy.spin()
# Точка входа в программу
if __name__ == '__main__':
    listener()
