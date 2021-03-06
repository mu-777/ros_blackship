#include <iostream>
#include "ros/ros.h"
#include "bs_controller/CBlackship.h"

int main(int argc, char** argv) {

    ros::init(argc, argv, "blackship_cotrol");
    ros::NodeHandle nh;
    ros::Rate loop_rate(30);

    CBlackship bs(nh);
    if (bs.initialize()) {
        bs.activate();

        while (ros::ok()) {
            ros::spinOnce();
            bs.publish_odom();
            loop_rate.sleep();
        }
    }

    return 0;
}
