//
// Created by piotr on 14.03.16.
//

#ifndef CCFRAMEWORK_CCPREFORKSERVER_H
#define CCFRAMEWORK_CCPREFORKSERVER_H

#include <map>
#include <fcgio.h>
#include "ccApp.h"

using namespace std;
using namespace boost;

namespace ccFramework {

    typedef struct _child child_t;

    class PreforkServer {
    public:
        PreforkServer(ccApp *application) {
            minSpare = 1;
            maxSpare = 5;
            maxChildren = 50;
            maxRequests = 0;
            maxExecTime = 60;
            m_pid = -1;
            PreforkServer::application = application;
        }

        ~PreforkServer() {
        }

        bool run(int sock, bool bDaemon = false);

        uint32_t getMinSpare() const {
            return minSpare;
        }

        void setMinSpare(uint32_t minSpare) {
            PreforkServer::minSpare = minSpare;
        }

        uint32_t getMaxSpare() const {
            return maxSpare;
        }

        void setMaxSpare(uint32_t maxSpare) {
            PreforkServer::maxSpare = maxSpare;
        }

        uint32_t getMaxChildren() const {
            return maxChildren;
        }

        void setMaxChildren(uint32_t maxChildren) {
            PreforkServer::maxChildren = maxChildren;
        }

        uint32_t getMaxRequests() const {
            return maxRequests;
        }

        void setMaxRequests(uint32_t maxRequests) {
            PreforkServer::maxRequests = maxRequests;
        }

        uint32_t getMaxExecTime() const {
            return maxExecTime;
        }

        void setMaxExecTime(uint32_t maxExecTime) {
            PreforkServer::maxExecTime = maxExecTime;
        }

        ccApp *getApplication() const {
            return application;
        }

        void setApplication(ccApp *application) {
            PreforkServer::application = application;
        }

    private:
        void _setPid(pid_t id) {
            m_pid = id;
        }

        bool _daemonize();

        void _setBlocking(int sock, bool flag);

        void _setCloseOnExec(int sock);

        bool _handleRequest(FCGX_Request &request, uint32_t timeout);

        void _childLoop(int sock, int parent);

        bool _spawnChild(int sock);

        void _installSignalHandlers();

        void _restoreSignalHandlers();

        void _reapChildren();

        void _cleanupChildren();

        bool _isClientAllowed(struct sockaddr_in *paddr);

        bool _notifyParent(int parent, char msg);

    private:
        uint32_t minSpare;
        uint32_t maxSpare;
        uint32_t maxChildren;
        uint32_t maxRequests;
        uint32_t maxExecTime;

        pid_t m_pid;
        map<pid_t, child_t *> m_children;
        ccApp *application;
    };

}


#endif //CCFRAMEWORK_CCPREFORKSERVER_H
