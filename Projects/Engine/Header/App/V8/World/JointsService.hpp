#pragma once
#include <App/V8/Tree/Instance.hpp>
#include <App/V8/DataModel/PartInstance.hpp>
#include <App/V8/World/Weld.hpp>

namespace RNR
{
    class JointsService : public Instance
    {
    public:
        JointsService();
        virtual std::string getClassName() { return "JointsService"; }
        Snap* snap(PartInstance* a, PartInstance* b);
        
        void makeJoints(Instance* w, PartInstance* p);
        void makeJoints(PartInstance* p);

        void fixWelds();

        void breakJoints(PartInstance* b);
        bool isWelded(PartInstance* a, PartInstance* b);
    };
}