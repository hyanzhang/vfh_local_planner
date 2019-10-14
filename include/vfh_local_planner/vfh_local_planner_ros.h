#ifndef VFH_LOCAL_PLANNER_ROS_H_
#define VFH_LOCAL_PLANNER_ROS_H_

#include <ros/ros.h>

// abstract class from which our plugin inherits
#include <nav_core/base_local_planner.h>

// transforms
#include <angles/angles.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>

// costmap & geometry
#include <costmap_2d/costmap_2d_ros.h>

// msgs
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Twist.h>



namespace vfh_local_planner 
{

    class VFHPlannerRos : public nav_core::BaseLocalPlanner
    {
    public:
        VFHPlannerRos();

        VFHPlannerRos(std::string name, tf::TransformListener* tf,
          costmap_2d::Costmap2DROS* costmap_ros);
        
        ~VFHPlannerRos();

        void initialize(std::string name, tf::TransformListener* tf,
          costmap_2d::Costmap2DROS* costmap_ros);

        bool setPlan(const std::vector<geometry_msgs::PoseStamped>& orig_global_plan);
        
        bool computeVelocityCommands(geometry_msgs::Twist& cmd_vel);

        bool isGoalReached();

    private:

        // pointer to external objects (do NOT delete object)
        costmap_2d::Costmap2DROS* costmap_ros_; ///<@brief pointer to costmap
        tf::TransformListener* tf_; ///<@brief pointer to Transform Listener
        

        // flags
        bool initialized_;
    };

}


#endif