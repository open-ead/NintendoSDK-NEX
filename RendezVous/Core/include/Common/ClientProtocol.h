#pragma once

namespace nn {
namespace nex {
class Credentials;
class EndPoint;
class Message;
class ProtocolCallContext;
class ProtocolRequestBrokerInterface;

class ClientProtocol : public nn::nex::Protocol {
public:
    ClientProtocol(u32);

    virtual ~ClientProtocol();

    virtual char* GetType() const;
    virtual bool IsAKindOf(char const*) const;
    virtual void EnforceDeclareSysComponentMacro();

    virtual nn::nex::Protocol::_Type GetProtocolType() const = 0;

    virtual void ExtractCallSpecificResults(nn::nex::Message*, nn::nex::ProtocolCallContext*) = 0;
    virtual nn::nex::ClientProtocol* CreateResponder() const = 0;
    virtual void SetDefaultCredentials(nn::nex::Credentials*);

    bool SendOverLocalLoopback(nn::nex::ProtocolCallContext*, nn::nex::Message*);
    bool SendRMCMessage(nn::nex::ProtocolCallContext*, nn::nex::Message*);
    void ProcessResponse(nn::nex::Message*, nn::nex::EndPoint*);

    nn::nex::Credentials* mCredentials;  // _88
};
}  // namespace nex
}  // namespace nn
