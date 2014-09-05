#ifndef ED_GUI_SERVER_PLUGIN_H_
#define ED_GUI_SERVER_PLUGIN_H_

#include <ed/plugin.h>

#include <ed_gui_server/QueryEntities.h>
#include <ed_gui_server/QueryMeshes.h>

#include <ros/callback_queue.h>
#include <ros/service_server.h>

class GUIServerPlugin : public ed::Plugin
{

public:

    GUIServerPlugin();

    virtual ~GUIServerPlugin();

    void configure(tue::Configuration config);

    void initialize();

    void process(const ed::WorldModel& world, ed::UpdateRequest& req);

private:

    const ed::WorldModel* world_model_;

    ros::CallbackQueue cb_queue_;

    ros::ServiceServer srv_query_meshes_;    

    bool srvQueryMeshes(const ed_gui_server::QueryMeshes::Request& ros_req,
                         ed_gui_server::QueryMeshes::Response& ros_res);

    ros::ServiceServer srv_query_entities_;

    bool srvQueryEntities(const ed_gui_server::QueryEntities::Request& ros_req,
                          ed_gui_server::QueryEntities::Response& ros_res);

};

#endif