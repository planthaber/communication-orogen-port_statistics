/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include <rtt/plugin/PluginLoader.hpp>

#include "Task.hpp"

using namespace port_statistics;

RTT::types::TypeInfo* Task::getType(::std::string const & type_name){
	/* Check if port type is known */
	RTT::types::TypeInfoRepository::shared_ptr ti =
					RTT::types::TypeInfoRepository::Instance();
	RTT::types::TypeInfo* type = ti->type(type_name);
	if (!type)
	{
			log(Info) << "Cannot find port type " << type_name <<
							" in the type info repository, loading additional typekits." << endlog();


			std::string path (getenv("LD_LIBRARY_PATH"));
			path = path + ";" + path + "/orocos/";
			RTT::plugin::PluginLoader::Instance()->loadTypekits(path.c_str());

			type = ti->type(type_name);

			if (!type){
				log(Info) << "Cannot find port type " << type_name << " in the updated type info repository" << endlog();
				return 0;
			}

	}
	return type;
}

RTT::base::InputPortInterface*  Task::createInputPort(::std::string const & port_name, ::std::string const & type_name){
	RTT::base::PortInterface *pi = getPort(port_name);

	if(pi){
			// Port exists. Returns success.
			log(Info) << "Port " << port_name << " is already registered." << endlog();
			return 0;
	}

	RTT::types::TypeInfo* type = getType(type_name);

	if (!type){
		return NULL;
	}

	/* Create input port */
	RTT::base::InputPortInterface *in_port = type->inputPort(port_name);
	if (!in_port)
	{
			log(Error) << "An error occurred during input port generation." << endlog();
			return NULL;
	}
	ports()->addEventPort(in_port->getName(), *(in_port) );

	return in_port;
}

Task::Task(std::string const& name)
    : TaskBase(name)
{
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine)
    : TaskBase(name, engine)
{
}

Task::~Task()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See Task.hpp for more detailed
// documentation about them.

bool Task::configureHook()
{
    if (! TaskBase::configureHook())
        return false;
    return true;
}
bool Task::startHook()
{
    if (! TaskBase::startHook())
        return false;
    return true;
}
void Task::updateHook()
{
    TaskBase::updateHook();
}
void Task::errorHook()
{
    TaskBase::errorHook();
}
void Task::stopHook()
{
    TaskBase::stopHook();
}
void Task::cleanupHook()
{
    TaskBase::cleanupHook();
}
