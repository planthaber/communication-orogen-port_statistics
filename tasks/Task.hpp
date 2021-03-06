/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef PORT_STATISTICS_TASK_TASK_HPP
#define PORT_STATISTICS_TASK_TASK_HPP

#include "port_statistics/TaskBase.hpp"
#include <telemetry_provider/RTTMarshalling.hpp>

using RTT::log;
using RTT::endlog;
using RTT::Debug;
using RTT::Info;
using RTT::Warning;
using RTT::Error;

namespace port_statistics{

    /*! \class Task
     * \brief The task context provides and requires services. It uses an ExecutionEngine to perform its functions.
     * Essential interfaces are operations, data flow ports and properties. These interfaces have been defined using the oroGen specification.
     * In order to modify the interfaces you should (re)use oroGen and rely on the associated workflow.
     * Declare a new task context (i.e., a component)

The corresponding C++ class can be edited in tasks/Task.hpp and
tasks/Task.cpp, and will be put in the port_statistics namespace.
     * \details
     * The name of a TaskContext is primarily defined via:
     \verbatim
     deployment 'deployment_name'
         task('custom_task_name','port_statistics::Task')
     end
     \endverbatim
     *  It can be dynamically adapted when the deployment is called with a prefix argument.
     */
    class Task : public TaskBase
    {
	friend class TaskBase;
    protected:

    /* print current statistics to stdout
     */
    virtual ::std::vector< ::port_statistics::PortStats > getStats();

    /* print current statistics to stdout
     */
    virtual bool printStats();

	RTT::types::TypeInfo* getType(::std::string const & type_name);
	RTT::base::InputPortInterface*  createInputPort(::std::string const & port_name, ::std::string const & type_name);

	struct PortData{
		 RTT::base::InputPortInterface* interface;
		 telemetry_provider::RTTPortReader* reader;
		 PortStats stats;
	};

	std::map<std::string, PortData> portData;


	/**
	 * Read the marshalled data (for the set protocol) from the port
	 * \param marshalled_data Read marshalled data into byte vector
	 * \param copyOldData Set to true to read the last sample from the port
	 */
	RTT::FlowStatus read(std::vector<uint8_t>& marshalled_data, bool copyOldData = false);

    public:
        /** TaskContext constructor for Task
         * \param name Name of the task. This name needs to be unique to make it identifiable via nameservices.
         * \param initial_state The initial TaskState of the TaskContext. Default is Stopped state.
         */
        Task(std::string const& name = "port_statistics::Task");

        /** TaskContext constructor for Task
         * \param name Name of the task. This name needs to be unique to make it identifiable for nameservices.
         * \param engine The RTT Execution engine to be used for this task, which serialises the execution of all commands, programs, state machines and incoming events for a task.
         * 
         */
        Task(std::string const& name, RTT::ExecutionEngine* engine);

        /** Default deconstructor of Task
         */
	~Task();

        /** This hook is called by Orocos when the state machine transitions
         * from PreOperational to Stopped. If it returns false, then the
         * component will stay in PreOperational. Otherwise, it goes into
         * Stopped.
         *
         * It is meaningful only if the #needs_configuration has been specified
         * in the task context definition with (for example):
         \verbatim
         task_context "TaskName" do
           needs_configuration
           ...
         end
         \endverbatim
         */
        bool configureHook();

        /** This hook is called by Orocos when the state machine transitions
         * from Stopped to Running. If it returns false, then the component will
         * stay in Stopped. Otherwise, it goes into Running and updateHook()
         * will be called.
         */
        bool startHook();

        /** This hook is called by Orocos when the component is in the Running
         * state, at each activity step. Here, the activity gives the "ticks"
         * when the hook should be called.
         *
         * The error(), exception() and fatal() calls, when called in this hook,
         * allow to get into the associated RunTimeError, Exception and
         * FatalError states.
         *
         * In the first case, updateHook() is still called, and recover() allows
         * you to go back into the Running state.  In the second case, the
         * errorHook() will be called instead of updateHook(). In Exception, the
         * component is stopped and recover() needs to be called before starting
         * it again. Finally, FatalError cannot be recovered.
         */
        void updateHook();

        /** This hook is called by Orocos when the component is in the
         * RunTimeError state, at each activity step. See the discussion in
         * updateHook() about triggering options.
         *
         * Call recover() to go back in the Runtime state.
         */
        void errorHook();

        /** This hook is called by Orocos when the state machine transitions
         * from Running to Stopped after stop() has been called.
         */
        void stopHook();

        /** This hook is called by Orocos when the state machine transitions
         * from Stopped to PreOperational, requiring the call to configureHook()
         * before calling start() again.
         */
        void cleanupHook();
    };
}

#endif

