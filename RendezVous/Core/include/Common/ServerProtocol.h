#pragma once

namespace nn {
namespace nex {
class Credentials;
class EndPoint;
class Message;
class ProtocolCallContext;
class ProtocolRequestBrokerInterface;

class ServerProtocol : public nn::nex::Protocol {
public:
    ServerProtocol(u32);

    virtual ~ServerProtocol();

    virtual char* GetType() const;
    virtual bool IsAKindOf(char const*) const;
    virtual void EnforceDeclareSysComponentMacro();

    virtual nn::nex::Protocol::_Type GetProtocolType() const = 0;

    virtual void DispatchProtocolMessage(nn::nex::Message*, nn::nex::Message*, bool*,
                                         nn::nex::EndPoint*) = 0;
    virtual void DispatchProtocolMessageWithAttemptCount(u64, nn::nex::Message*, nn::nex::Message*,
                                                         bool*, int*, nn::nex::EndPoint*);
    virtual bool UseAttemptCountMethod();
};
}  // namespace nex
}  // namespace nn
