#ifndef port_statistics_TYPES_HPP
#define port_statistics_TYPES_HPP

#include <base/Time.hpp>
#include <string>

/* If you need to define types specific to your oroGen components, define them
 * here. Required headers must be included explicitly
 *
 * However, it is common that you will only import types from your library, in
 * which case you do not need this file
 */

namespace port_statistics {

struct PortDescription{
    std::string portName;
    std::string typeName;
    double statsAverageCount;
};

struct PortStats{
    PortDescription description;
    double packetAvgKbps;
    double packetTotal;
    double packetFrequency;
    //time of the last arrival of messages
    base::Time lastUpdate;
};


}

#endif

