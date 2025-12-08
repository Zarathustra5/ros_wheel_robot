#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def talker():
    # Publisher позволяет сообщить ROS, что вы хотите 
    #      что то опубликовать в приведенный топик
    pub = rospy.Publisher('chatter', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        # Формирование очередного сообщения
        hello_str = "hello world %s" % rospy.get_time()
        # Вывод информации в консоль
        rospy.loginfo(hello_str)
        # Отправка очередного сообщения
        pub.publish(hello_str)
        # Спать до следующей итерации (10 Hz)
        rate.sleep()

# Точка входа в программу
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

