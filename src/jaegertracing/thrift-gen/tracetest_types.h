/**
 * MODIFIED from code autogenerated by Thrift Compiler (0.9.2)
 *
 * WARNING WARNING WARNING
 * This file has been hand-patched. See
 * https://github.com/jaegertracing/jaeger-client-cpp/issues/45.
 */
#ifndef tracetest_TYPES_H
#define tracetest_TYPES_H

#include <iosfwd>

#include <thrift/TApplicationException.h>
#include <thrift/Thrift.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>

namespace jaegertracing {
namespace crossdock {
namespace thrift {

struct Transport {
    enum type { HTTP = 0, TCHANNEL = 1, DUMMY = 2 };
};

extern const std::map<int, const char*> _Transport_VALUES_TO_NAMES;

class Downstream;

class StartTraceRequest;

class JoinTraceRequest;

class ObservedSpan;

class TraceResponse;

class Downstream {
  public:
    static const char*
        ascii_fingerprint;  // = "864D68E1D3FB0C71C1E979F437051051";
    static const uint8_t binary_fingerprint
        [16];  // =
               // {0x86,0x4D,0x68,0xE1,0xD3,0xFB,0x0C,0x71,0xC1,0xE9,0x79,0xF4,0x37,0x05,0x10,0x51};

    Downstream(const Downstream&);
    Downstream& operator=(const Downstream&);
    Downstream()
        : serviceName()
        , serverRole()
        , host()
        , port()
        , transport((Transport::type)0)
    {
    }

    virtual ~Downstream() throw();
    std::string serviceName;
    std::string serverRole;
    std::string host;
    std::string port;
    Transport::type transport;
    boost::shared_ptr<Downstream> downstream;

    void __set_serviceName(const std::string& val);

    void __set_serverRole(const std::string& val);

    void __set_host(const std::string& val);

    void __set_port(const std::string& val);

    void __set_transport(const Transport::type val);

    void __set_downstream(const Downstream& val);

    bool operator==(const Downstream& rhs) const
    {
        if (!(serviceName == rhs.serviceName))
            return false;
        if (!(serverRole == rhs.serverRole))
            return false;
        if (!(host == rhs.host))
            return false;
        if (!(port == rhs.port))
            return false;
        if (!(transport == rhs.transport))
            return false;
        if (static_cast<bool>(downstream) != static_cast<bool>(rhs.downstream))
            return false;
        if (downstream && rhs.downstream && !(*downstream == *rhs.downstream))
            return false;
        return true;
    }
    bool operator!=(const Downstream& rhs) const { return !(*this == rhs); }

    bool operator<(const Downstream&) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const Downstream& obj);
};

void swap(Downstream& a, Downstream& b);

class StartTraceRequest {
  public:
    static const char*
        ascii_fingerprint;  // = "EBD7726A3B9A0D49D03E0D6A6F6C72E0";
    static const uint8_t binary_fingerprint
        [16];  // =
               // {0xEB,0xD7,0x72,0x6A,0x3B,0x9A,0x0D,0x49,0xD0,0x3E,0x0D,0x6A,0x6F,0x6C,0x72,0xE0};

    StartTraceRequest(const StartTraceRequest&);
    StartTraceRequest& operator=(const StartTraceRequest&);
    StartTraceRequest()
        : serverRole()
        , sampled(0)
        , baggage()
    {
    }

    virtual ~StartTraceRequest() throw();
    std::string serverRole;
    bool sampled;
    std::string baggage;
    Downstream downstream;

    void __set_serverRole(const std::string& val);

    void __set_sampled(const bool val);

    void __set_baggage(const std::string& val);

    void __set_downstream(const Downstream& val);

    bool operator==(const StartTraceRequest& rhs) const
    {
        if (!(serverRole == rhs.serverRole))
            return false;
        if (!(sampled == rhs.sampled))
            return false;
        if (!(baggage == rhs.baggage))
            return false;
        if (!(downstream == rhs.downstream))
            return false;
        return true;
    }
    bool operator!=(const StartTraceRequest& rhs) const
    {
        return !(*this == rhs);
    }

    bool operator<(const StartTraceRequest&) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out,
                                    const StartTraceRequest& obj);
};

void swap(StartTraceRequest& a, StartTraceRequest& b);

typedef struct _JoinTraceRequest__isset {
    _JoinTraceRequest__isset()
        : downstream(false)
    {
    }
    bool downstream : 1;
} _JoinTraceRequest__isset;

class JoinTraceRequest {
  public:
    static const char*
        ascii_fingerprint;  // = "B8479409112F7458788A09AB6826E542";
    static const uint8_t binary_fingerprint
        [16];  // =
               // {0xB8,0x47,0x94,0x09,0x11,0x2F,0x74,0x58,0x78,0x8A,0x09,0xAB,0x68,0x26,0xE5,0x42};

    JoinTraceRequest(const JoinTraceRequest&);
    JoinTraceRequest& operator=(const JoinTraceRequest&);
    JoinTraceRequest()
        : serverRole()
    {
    }

    virtual ~JoinTraceRequest() throw();
    std::string serverRole;
    Downstream downstream;

    _JoinTraceRequest__isset __isset;

    void __set_serverRole(const std::string& val);

    void __set_downstream(const Downstream& val);

    bool operator==(const JoinTraceRequest& rhs) const
    {
        if (!(serverRole == rhs.serverRole))
            return false;
        if (__isset.downstream != rhs.__isset.downstream)
            return false;
        else if (__isset.downstream && !(downstream == rhs.downstream))
            return false;
        return true;
    }
    bool operator!=(const JoinTraceRequest& rhs) const
    {
        return !(*this == rhs);
    }

    bool operator<(const JoinTraceRequest&) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out,
                                    const JoinTraceRequest& obj);
};

void swap(JoinTraceRequest& a, JoinTraceRequest& b);

class ObservedSpan {
  public:
    static const char*
        ascii_fingerprint;  // = "980A53AA3FC6CDB7DBBD4C3B9EF9B8E0";
    static const uint8_t binary_fingerprint
        [16];  // =
               // {0x98,0x0A,0x53,0xAA,0x3F,0xC6,0xCD,0xB7,0xDB,0xBD,0x4C,0x3B,0x9E,0xF9,0xB8,0xE0};

    ObservedSpan(const ObservedSpan&);
    ObservedSpan& operator=(const ObservedSpan&);
    ObservedSpan()
        : traceId()
        , sampled(0)
        , baggage()
    {
    }

    virtual ~ObservedSpan() throw();
    std::string traceId;
    bool sampled;
    std::string baggage;

    void __set_traceId(const std::string& val);

    void __set_sampled(const bool val);

    void __set_baggage(const std::string& val);

    bool operator==(const ObservedSpan& rhs) const
    {
        if (!(traceId == rhs.traceId))
            return false;
        if (!(sampled == rhs.sampled))
            return false;
        if (!(baggage == rhs.baggage))
            return false;
        return true;
    }
    bool operator!=(const ObservedSpan& rhs) const { return !(*this == rhs); }

    bool operator<(const ObservedSpan&) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const ObservedSpan& obj);
};

void swap(ObservedSpan& a, ObservedSpan& b);

typedef struct _TraceResponse__isset {
    _TraceResponse__isset()
        : span(false)
    {
    }
    bool span : 1;
} _TraceResponse__isset;

class TraceResponse {
  public:
    static const char*
        ascii_fingerprint;  // = "BE76F8F59F14519CE6831037A5CDA9EE";
    static const uint8_t binary_fingerprint
        [16];  // =
               // {0xBE,0x76,0xF8,0xF5,0x9F,0x14,0x51,0x9C,0xE6,0x83,0x10,0x37,0xA5,0xCD,0xA9,0xEE};

    TraceResponse(const TraceResponse&);
    TraceResponse& operator=(const TraceResponse&);
    TraceResponse()
        : notImplementedError()
    {
    }

    virtual ~TraceResponse() throw();
    ObservedSpan span;
    boost::shared_ptr<TraceResponse> downstream;
    std::string notImplementedError;

    _TraceResponse__isset __isset;

    void __set_span(const ObservedSpan& val);

    void __set_downstream(const TraceResponse& val);

    void __set_notImplementedError(const std::string& val);

    bool operator==(const TraceResponse& rhs) const
    {
        if (__isset.span != rhs.__isset.span)
            return false;
        else if (__isset.span && !(span == rhs.span))
            return false;
        if (static_cast<bool>(downstream) != static_cast<bool>(rhs.downstream))
            return false;
        else if (downstream && rhs.downstream &&
                 !(*downstream == *rhs.downstream))
            return false;
        if (!(notImplementedError == rhs.notImplementedError))
            return false;
        return true;
    }
    bool operator!=(const TraceResponse& rhs) const { return !(*this == rhs); }

    bool operator<(const TraceResponse&) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out,
                                    const TraceResponse& obj);
};

void swap(TraceResponse& a, TraceResponse& b);

}  // namespace thrift
}  // namespace crossdock
}  // namespace jaegertracing

#endif
