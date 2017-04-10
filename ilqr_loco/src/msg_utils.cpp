#include "traj_client.h"

void TrajClient::FillGoalMsgHeader(ilqr_loco::TrajExecGoal &goal)
{
  goal.traj.header.seq = T_;
  goal.traj.header.stamp = ros::Time::now();
  goal.traj.header.frame_id = "/base_link";
}

void TrajClient::FillTwistMsg(geometry_msgs::Twist &twist, double lin_x, double ang_z)
{
  twist.linear.x = lin_x;
  twist.angular.z = ang_z;
}

void TrajClient::FillOdomMsg(nav_msgs::Odometry &odom, double x, double y,
                             double yaw, double Ux, double Uy, double w)
{
  odom.pose.pose.position.x = x;
  odom.pose.pose.position.y = y;
  odom.pose.pose.position.z = 0.0;

  geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(yaw);
  odom.pose.pose.orientation = odom_quat;

  odom.twist.twist.linear.x = Ux;
  odom.twist.twist.linear.y = Uy;
  odom.twist.twist.angular.z = w;
}