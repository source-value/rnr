#pragma once
#include <Network/ArkNet/ArkPeer.hpp>
#include <Network/ArkNet/ArkServer.hpp>
#include <Network/ArkNet/Packets.hpp>
#include <Network/NetworkPeer.hpp>
#include <Network/NetworkReplicator.hpp>
#include <App/V8/Tree/Instance.hpp>

namespace RNR
{
    class NetworkServer : public NetworkPeer, ArkNet::IArkServerListener
    {
    protected:
        ArkNet::ArkServer* m_server;
        int m_port;
        bool m_running;
    public:
        NetworkServer();
        ~NetworkServer();

        virtual void onPeerAdding(ArkNet::ArkPeer* addingPeer);
        virtual void onPeerRemoving(ArkNet::ArkPeer* removingPeer);
        virtual bool onPeerConnectionRequest(ArkNet::ArkPeer* rqPeer, ArkNet::Packets::OpenConnectionRequestPacket* rq);

        void start(int port, int threadSleepTime = 20);
        void stop(int blockDuration = 1000);
        void frame();

        NetworkReplicator* getReplicatorForPeer(ArkNet::ArkPeer* peer);

        bool getRunning() { return m_running; }
        virtual std::string getClassName() { return "NetworkServer"; }
    };
}